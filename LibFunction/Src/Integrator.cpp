#include "LibFunction/Integrator.h"

#include <format>
#include <numbers>

namespace lf
{

    Integrator::Integrator(Function&& function)
      : m_function { std::move(function) }
    {
      //nothing
    }

    void Integrator::SetFunction(Function&& function)
    {
      m_function = std::move(function);
    }

    IntegrationDetails Integrator::Integrate(const Line line, const size_t n, const Algorithm algorithm)
    {
      IntegrationDetails details { n };
      
      details.delta = (line.end - line.start) / n;
      details.areas.reserve(n);

      switch (algorithm)
      {
        case Algorithm::Square: HandleSquareIntegration(line, details); break;
        case Algorithm::Trapeze: HandleTrapezeIntegration(line, details); break;
        case Algorithm::SemiCircle: HandleSemiCircleIntegration(line, details); break;
        case Algorithm::IsoscelesTriangle: HandleIsoscelesTriangleIntegration(line, details); break;
        case Algorithm::IsoscelesTrapeze: HandleIsoscelesTrapezeIntegration(line, details); break;
        default: throw InvalidAlgorithmException(std::format("Unknown Algorithm {} used.", static_cast<int>(algorithm)));
      }

      return details;
    }

    void Integrator::HandleSquareIntegration(const Line line, IntegrationDetails& details)
    {
      //< deltaX * f(a + deltaX * i)

      for (size_t i{ 0 }; i < details.n; ++i)
      {
        const double base{ details.delta };
        const double height{ m_function.Resolve(line.start + (details.delta * i)) };
        const double area{ base * height };

        details.areaTotal += area;
        details.areas.emplace_back(std::make_pair(i, area));
      }
    }

    void Integrator::HandleTrapezeIntegration(const Line line, IntegrationDetails& details)
    {
      //< deltaX * f(a + deltaX * i) + (deltaX/2) * ( f(a + deltaX * (i+1) - f(a + deltaX *i) )

      for (size_t i{ 0 }; i < details.n; ++i)
      {
        const double base{ details.delta };

        const double heightSquare{ m_function.Resolve(line.start + (details.delta * i)) };
        const double heightTriangle { m_function.Resolve(line.start + (details.delta * (i+1))) - heightSquare };

        const double areaSquare{ base * heightSquare };
        const double areaTriangle { (base * heightTriangle)/2.0 };
        const double area { areaSquare + areaTriangle };
        
        details.areaTotal += area;
        details.areas.emplace_back(std::make_pair(i, area));
      }
    }

    void Integrator::HandleSemiCircleIntegration(const Line line, IntegrationDetails& details)
    {
      //< deltaX * f(a + deltaX * i) + π/2 * R^2
      //< deltaX * f(a + deltaX * i) + π/8 * (deltaX)^2

      for (size_t i{ 0 }; i < details.n; ++i)
      {
        const double base{ details.delta };

        const double heightSquare{ m_function.Resolve(line.start + (details.delta * i)) };

        const double areaSquare{ base * heightSquare };
        const double areaSemiCircle{ std::numbers::pi / 8.0 * std::pow(details.delta, 2) };

        const double area{ areaSquare + areaSemiCircle };

        details.areaTotal += area;
        details.areas.emplace_back(std::make_pair(i, area));
      }
    }

    
    void Integrator::HandleIsoscelesTriangleIntegration(const Line line, IntegrationDetails& details)
    {
      //deltaX * f(a + deltaX * i) + deltaX/2.0 * (f(a + deltaX * i + deltaX / 2.0) - f(a + deltaX * i))

      for (size_t i{ 0 }; i < details.n; ++i)
      {
        const double base{ details.delta };

        const double heightSquare{ m_function.Resolve(line.start + (details.delta * i)) };
        const double heightTriangle { m_function.Resolve(line.start + (details.delta * i) + (details.delta / 2.0))
                                        - heightSquare};
        
        const double areaSquare{ base * heightSquare };
        const double areaTriangle{ base * heightTriangle / 2.0 };

        const double area{ areaSquare + areaTriangle };

        details.areaTotal += area;
        details.areas.emplace_back(std::make_pair(i, area));
      }
    }

    void Integrator::HandleIsoscelesTrapezeIntegration(const Line line, IntegrationDetails& details)
    {
      //deltaX * f(a + deltaX * i) + 3/4 * deltaX * (f(a + deltaX * i + deltaX / 2.0) - f(a + deltaX * i))

      for (size_t i{ 0 }; i < details.n; ++i)
      {
        const double base{ details.delta };

        const double heightSquare{ m_function.Resolve(line.start + (details.delta * i)) };

        const double heightTrapeze{ m_function.Resolve(line.start + (details.delta * i) + (details.delta / 2.0))
                                        - heightSquare };

        const double areaSquare{ base * heightSquare };
        const double areaTrapeze{ 3.0/4.0 * base * heightTrapeze };

        const double area{ areaSquare + areaTrapeze };

        details.areaTotal += area;
        details.areas.emplace_back(std::make_pair(i, area));
      }
    }
}
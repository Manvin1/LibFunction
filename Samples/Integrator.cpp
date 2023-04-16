/*********************************************************************
 * @file Integrator.cpp
 * @brief Exemplificar o uso da Integrator Class.
 * 
 * Este arquivo contém exemplos para uso da Integrator Class.
 * 
 * @date 2023
 *********************************************************************/

#include <LibFunction/Integrator.h>
#include <LibFunction/Function.h>

#include <format>
#include <iostream>

constexpr const char* Message{
  R"---(**********************
*		     *
* INTEGRATOR EXAMPLE *
*		     *
**********************)---"
};

char GetChar();

bool GetBool();

void ChangeFunction(lf::Integrator& integrator);

void Integrate(lf::Integrator& integrator);

lf::Integrator::Algorithm toAlgorithm(const int number);

void Run()
{
  constexpr const char* Options{ R"---(1 - Mudar a função usada
2 - Integrar
3 - Encerrar programa)---" };

  lf::Integrator integrator;

  bool running { true };

  while (running)
  {
    std::cout << Message << "\n\n";

    const auto& expression { integrator.GetFunction().GetExpression() };

    std::cout << "Function: " << (expression.size() ? expression : "Nenhuma função definida") << "\n\n";

    std::cout << Options << "\n\n";

    char ch {GetChar()};

    switch (ch)
    {
      case '1': ChangeFunction(integrator); break;
      case '2': Integrate(integrator); break;
      case '3': running = false; break;
      default: std::cout << "Unknown command" << std::endl;
    }

    std::cout << std::endl;

    std::system("pause");
    std::system("cls");
  }
}

int main()
{
  try
  {
    Run();
  }
  catch (...)
  {
    std::cout << "The program failed with an unknown error" << std::endl;
  }
}

char GetChar()
{
  char ch;

  std::cin >> ch;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.clear();
  std::cout << std::endl;

  return ch;
}

bool GetBool()
{
  bool b;

  std::cin >> std::boolalpha >> b;
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
  std::cin.clear();

  std::cout << std::endl;

  return b;
}

void ChangeFunction(lf::Integrator& integrator)
{
  try
  {
    std::string expression;

    std::cout << "Definir a função para: ";
    std::getline(std::cin, expression);

    integrator.SetFunction(lf::Function{expression});
  }
  catch (const antlr4::RuntimeException& ex)
  {
    std::cout << std::format("A definição da expressão da função inserida falhou com erro \"{}\"", ex.what()) << std::endl;
  }
  catch (const std::exception& ex)
  {
    std::cout << std::format("A definição da expressão da função inserida falhou com erro \"{}\"", ex.what()) << std::endl;
  }
}

void Integrate(lf::Integrator& integrator)
{
  constexpr const char* AlgorithmOptions { R"---(Será definido a região da curva em relação ao eixo x e a quantidade de figuras. 
Os algoritmos disponíveis são:
	1 Square
	2 Trapézio
	3 Semi-círculo
	4 Triângulo Isosceles
	5 Trapézio Isosceles)---"};

  try
  {
    std::cout << AlgorithmOptions << "\n\n";

    std::string startLine, endLine, n, algorithm;

    std::cout << "Número do algoritmo: ";
    std::getline(std::cin, algorithm);

    std::cout << "start X: ";
    std::getline(std::cin, startLine);

    std::cout << "end X: ";
    std::getline(std::cin, endLine);

    std::cout << "Quantidade de Figuras (n): ";
    std::getline(std::cin, n);

    std::cout << std::endl;

    auto details { integrator.Integrate({std::stod(startLine), std::stod(endLine)}, 
                                          std::stoi(n), 
                                          toAlgorithm(std::stoi(algorithm)))};

    std::cout << std::format("n = {}\ndeltaX = {}\narea total = {}", details.n, details.delta, details.areaTotal) << "\n\n";

    std::cout << "Quer ver a área de cada uma das figuras(true/false)? : ";

    if (GetBool())
    {
      std::cout << "Índice\t\tÁrea\n";
      for (auto& pair : details.areas)
      {
        std::cout<< pair.first << "\t\t" << pair.second << std::endl;
      }
    }
  }
  catch (const std::invalid_argument& ex)
  {
    std::cout << std::format("Um valor inválido foi usado \"{}\"", ex.what()) << std::endl;
  }
  catch (const lf::InvalidAlgorithmException& ex)
  {
    std::cout << std::format("Um algoritmo inválido foi digitado \"{}\"", ex.what()) << std::endl;
  }
  catch (const antlr4::RuntimeException& ex)
  {
    std::cout << std::format("A evaluação da integração falhou com erro \"{}\"", ex.what()) << std::endl;
  }
  catch (const std::exception& ex)
  {
    std::cout << std::format("A evaluação da integração falhou com erro \"{}\"", ex.what()) << std::endl;
  }

}

lf::Integrator::Algorithm toAlgorithm(const int number)
{
  using lf::Integrator;

  switch (number)
  {
    case 1: return Integrator::Algorithm::Square;
    case 2: return Integrator::Algorithm::Trapeze;
    case 3: return Integrator::Algorithm::SemiCircle;
    case 4: return Integrator::Algorithm::IsoscelesTriangle;
    case 5: return Integrator::Algorithm::IsoscelesTrapeze;
  }

  return lf::Integrator::Algorithm(number);
}

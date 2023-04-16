#include "LibFunction/Function.h"

#include "LibFunction/AlgebricBaseVisitor.h"

#include <format>
#include <stdexcept>
#include <string>

namespace lf
{
  Function::Function(Function&& src) noexcept
    : m_stream { std::move(src.m_stream) },
      m_lexer { &m_stream },
      m_tokenStream { &m_lexer },
      m_parser { &m_tokenStream },
      m_entryPoint { nullptr }
  {
    src.m_lexer.reset();
    src.m_tokenStream.reset();
    src.m_parser.reset();
    src.m_entryPoint = nullptr;
  }

  Function::Function(const std::string& expression) noexcept
  {
    For(expression);
  }

  Function& Function::operator=(Function&& src) noexcept
  {
    if (this == &src)
    {
      return *this;
    }

    m_entryPoint = nullptr;

    m_stream = std::move(src.m_stream);

    m_lexer.setInputStream(&m_stream);
    m_tokenStream.setTokenSource(&m_lexer);
    m_parser.setTokenStream(&m_tokenStream);

    src.m_lexer.reset();
    src.m_tokenStream.reset();
    src.m_parser.reset();
    src.m_entryPoint = nullptr;

    return *this;
  }

  void Function::For(const std::string& expression) noexcept
  {
    m_entryPoint = nullptr;

    m_stream.reset();
    m_stream.load(expression);

    m_lexer.setInputStream(&m_stream);
    m_tokenStream.setTokenSource(&m_lexer);
    m_parser.setTokenStream(&m_tokenStream);
  }

  double Function::Resolve()
  {
    if (GetExpression() == "")
    {
      throw std::runtime_error{"Empty function expression used."};
    }

    AlgebricBaseVisitor visitor;

    if (m_entryPoint)
    {
      return std::any_cast<double>(visitor.visitEntryPoint(m_entryPoint));
    }

    m_entryPoint = m_parser.entryPoint();

    return std::any_cast<double>(visitor.visitEntryPoint(m_entryPoint));
  }

  double Function::Resolve(const double x)
  {
    if (GetExpression() == "")
    {
      throw std::runtime_error{ "Empty function expression used." };
    }

    AlgebricBaseVisitor visitor { x };

    if (m_entryPoint)
    {
      return std::any_cast<double>(visitor.visitEntryPoint(m_entryPoint));
    }

    m_entryPoint = m_parser.entryPoint();

    return std::any_cast<double>(visitor.visitEntryPoint(m_entryPoint));
  }
}
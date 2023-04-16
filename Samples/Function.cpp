/*********************************************************************
 * @file Integrator.cpp
 * @brief Exemplificar o uso da Function Class.
 *
 * Este arquivo contém exemplos para uso da Function Class.
 *
 * @date 2023
 *********************************************************************/

#include <LibFunction/Function.h>

#include <format>
#include <iostream>

constexpr const char* Message{
  R"---(********************
*		   *
* FUNCTION EXAMPLE *
*		   *
********************)---"
};

char GetChar();

void ChangeFunction(lf::Function& function);

void Evaluate(lf::Function& function);

void Run()
{
  constexpr const char* Options{ R"---(1 - Mudar a função usada
2 - Evaluir
3 - Encerrar programa)---" };

  lf::Function function;

  bool running{ true };

  while (running)
  {
    std::cout << Message << "\n\n";

    const auto& expression{ function.GetExpression() };

    std::cout << "Function: " << (expression.size() ? expression : "Nenhuma função definida") << "\n\n";

    std::cout << Options << "\n\n";

    char ch{ GetChar() };

    switch (ch)
    {
    case '1': ChangeFunction(function); break;
    case '2': Evaluate(function); break;
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

void ChangeFunction(lf::Function& function)
{
  try
  {
    std::string expression;

    std::cout << "Definir a função para: ";
    std::getline(std::cin, expression);

    function.For(expression);
  }
  catch (const antlr4::RuntimeException& ex)
  {
    std::cout << std::format("A definição da expressão da função inserida falhou com error \"{}\"", ex.what()) << std::endl;
  }
  catch (const std::exception& ex)
  {
    std::cout << std::format("A definição da expressão da função inserida falhou com error \"{}\"", ex.what()) << std::endl;
  }
}

void Evaluate(lf::Function& function)
{
  try
  {
    std::cout << "Insira o valor de input(x), se algum, ao qual resultará no output de f(x)" << "\n\n";

    std::string x;

    std::cout << "Valor de x (se algum): ";
    std::getline(std::cin, x);

    std::cout << std::endl;

    const double number { std::stod(x) };
    double y  { function.Resolve(number) };

    std::cout << std::format("x = {}, y = {}", number, y) << "\n\n";
  }
  catch (const std::invalid_argument& ex)
  {
    std::cout << std::format("Um valor inválido foi usado como input \"{}\"", ex.what()) << std::endl;
  }
  catch (const antlr4::RuntimeException& ex)
  {
    std::cout << std::format("A evaluação da função falhou com error \"{}\"", ex.what()) << std::endl;
  }
  catch (const std::runtime_error& ex)
  {
    std::cout << std::format("A evaluação da função falhou com error \"{}\"", ex.what()) << std::endl;
  }
}

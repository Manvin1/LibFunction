/*********************************************************************
 * @file Integrator.h
 * @brief Classes que provêem serviços para cálculos de integrais.
 * 
 * Este arquivo contém classes que provêem serviços para cálculos de integrais a partir de diferentes algoritmos.
 * 
 * @date 2023
 *********************************************************************/

#pragma once

#include "Function.h"

#include <stdexcept>
#include <utility>
#include <vector>

namespace lf
{
  /**
   * @brief Classe que representa os detalhes de uma integração.
   */
  struct IntegrationDetails
  {
    size_t n{};
    double delta{};
    double areaTotal{};
    std::vector<std::pair<double,double>> areas{}; //< pair index:area.
  };

  /**
   * @brief Classe que provê serviços para cálculos de integrais a partir de diferentes algoritmos.
   */
  class Integrator
  {
  public:
    /**
     * @brief Enum que especifica os diferentes algoritmos para cálculos de integrais.
     */
    enum class Algorithm
    {
      Square = 1,
      Trapeze,
      SemiCircle,
      IsoscelesTriangle,
      IsoscelesTrapeze,
    };

    /**
     * @brief Classe que representa uma linha em um mesmo eixo.
     */
    struct Line
    {
      double start;
      double end;
    };

    /**
     * @brief Default constructor.
     */
    explicit Integrator() = default;

    /**
     * @brief Cria um Integrator que usa a função especificada.
     * 
     * @param function
     */
    explicit Integrator (Function&& function);

    /**
     * @brief Obter a função internada usada pelo integrator.
     * 
     * @return a função internada usada pelo integrator.
     */
    const Function& GetFunction() const { return m_function; }

    /**
     * @brief Definir a função internada usada pelo integrator usando move semantics.
     *
     * Erros de sintaxe só são detectados durante a primeira evaluação da função, ao qual ocorrerá durante a invocação de Integrator::Integrate.
     *
     * @param function a função internada que deve ser usada pelo integrator.
     */
    void SetFunction(Function&& function);

    /**
     * @brief Integrar a função atual do integrator.
     * 
     * @param line A posição inicial e final no eixo x.
     * @param n A quantidade de figuras.
     * @param algorithm O algoritmo usado.
     * 
     * @return O resultado da integração em um IntegrationDetails
     * 
     * @throw InvalidAlgorithmException - Exceção lançada caso um algoritmo inválido seja passado.
     * 
     * @throw std::runtime_error Se a function expression estiver vazia ou ocorrer algum erro durante a resolução da expressão.
     *
     * @throw antlr4::RuntimeException Se tiver algum erro durante o Lexer or Parser.
     */
    IntegrationDetails Integrate(const Line line, const size_t n, const Algorithm algorithm);

  private:

    /**
     * @brief Integrar usando o algoritmo do Square.
     * 
     * O resultado da integração é inserido em details.
     * 
     * @param line
     * @param details
     * 
     * @throw std::runtime_error Se a function expression estiver vazia ou ocorrer algum erro durante a resolução da expressão.
     *
     * @throw antlr4::RuntimeException Se tiver algum erro durante o Lexer or Parser.
     */
    void HandleSquareIntegration(const Line line, IntegrationDetails& details);

    /**
     * @brief Integrar usando o algoritmo do Trapeze.
     *
     * O resultado da integração é inserido em details.
     * 
     * @param line
     * @param details
     * 
     * @throw std::runtime_error Se a function expression estiver vazia ou ocorrer algum erro durante a resolução da expressão.
     *
     * @throw antlr4::RuntimeException Se tiver algum erro durante o Lexer or Parser.
     */
    void HandleTrapezeIntegration(const Line line, IntegrationDetails& details);

    /**
     * @brief Integrar usando o algoritmo do SemiCircle.
     *
     * O resultado da integração é inserido em details.
     * 
     * @param line
     * @param details
     * 
     * @throw std::runtime_error Se a function expression estiver vazia ou ocorrer algum erro durante a resolução da expressão.
     *
     * @throw antlr4::RuntimeException Se tiver algum erro durante o Lexer or Parser.
     */
    void HandleSemiCircleIntegration(const Line line, IntegrationDetails& details);

    /**
     * @brief Integrar usando o algoritmo do IsoscelesTriangle.
     * 
     * O resultado da integração é inserido em details.
     * 
     * @param line
     * @param details
     * 
     * @throw std::runtime_error Se a function expression estiver vazia ou ocorrer algum erro durante a resolução da expressão.
     *
     * @throw antlr4::RuntimeException Se tiver algum erro durante o Lexer or Parser.
     */
    void HandleIsoscelesTriangleIntegration(const Line line, IntegrationDetails& details);

    /**
     * @brief Integrar usando o algoritmo do IsoscelesTrapeze.
     * 
     * O resultado da integração é inserido em details.
     *
     * @param line
     * @param details
     * 
     * @throw std::runtime_error Se a function expression estiver vazia ou ocorrer algum erro durante a resolução da expressão.
     *
     * @throw antlr4::RuntimeException Se tiver algum erro durante o Lexer or Parser.
     */
    void HandleIsoscelesTrapezeIntegration(const Line line, IntegrationDetails& details);

    Function m_function;
  };
}

namespace lf
{
  /**
   * @brief Classe que representa o erro de indicar um Algoritmo inválido em uma Integração.
   */
  class InvalidAlgorithmException : public std::runtime_error
  {
  public:
    explicit InvalidAlgorithmException(const std::string& message)
      : std::runtime_error{message}
    {
      //nothing
    }
  };
}

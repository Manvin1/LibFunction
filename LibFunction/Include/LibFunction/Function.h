/*********************************************************************
 * @file Function.h
 * @brief Classes que representam funções matemáticas e suas operações.
 * 
 * Este arquivo contém classes que representam funções matemáticas e oferecem uma interface para a 
 * definição de sua expressão e a sua evaluação.
 * 
 * @date 2023
 *********************************************************************/

#pragma once

#include "AlgebricLexer.h"
#include "AlgebricParser.h"

#include <antlr4-runtime.h>

namespace lf
{
  /**
   * @brief Classe que representa uma função matemática.
   * 
   * Esta classe representa uma função matemática, oferecendo uma interface para a sua definição e 
   * evaluação de seus valores.
   */
  class Function
  {
  public:

    /**
     * @brief Default Constructor.
     * 
     * Constroi uma função com o valor default, sendo equivalente e Function("").
     */
    explicit Function() = default;

    /**
     * @brief Move Constructor.
     * 
     * @param src
     */
    explicit Function(Function&& src) noexcept;

    /**
     * @brief Construir uma função que usa a expressão definida.
     * 
     * Este construtor usa internamente Function::For.
     * 
     * @param expression
     */
    explicit Function(const std::string& expression) noexcept;

    /**
     * @brief Move assignment
     * 
     * @param src
     * 
     * @return *this
     */
    Function& operator=(Function&& src) noexcept;

    /**
     * @brief Obter a expressão usada pela função.
     * 
     * A string possivelmente está vazia.
     * 
     * @return a expressão usada pela função.
     */
    std::string GetExpression() const { return m_stream.toString(); }

    /**
     * @brief Definir a expressão usada pela função.
     *
     * Erros de sintaxe só serão detectados durante a primeira resolução da expressão em um Function::Resolve, pois é usado um lazy system.
     * 
     * @param expression
     */
    void For(const std::string& expression) noexcept;

    /**
     * @brief Evaluir a função a fim de obter o seu valor.
     *
     * Esta função deve ser a usada quando não se tem alguma variável. Contudo, caso alguma seja encontrada durante a resolução, o valor inicial 0.0 será usado.
     * Esta função pode afetar a performance.
     * 
     * @param x O valor da variável x
     *
     * @return O resultado da evaluação da expressão.
     *
     * @throw std::runtime_error Se a function expression estiver vazia ou ocorrer algum erro durante a resolução da expressão.
     *
     * @throw antlr4::RuntimeException Se tiver algum erro durante o Lexer or Parser.
     */
    double Resolve();

    /**
     * @brief Evaluir a função a fim de obter o seu valor.
     * 
     * Esta função deve ser a usada quando se tem alguma variável. Contudo, caso não seja encontrada alguma, a função ainda é resolvida normalmente.
     * Esta função pode afetar a performance.
     * 
     * @param x O valor da variável x
     * 
     * @return O resultado da evaluação da expressão.
     * 
     * @throw std::runtime_error Se a function expression estiver vazia ou ocorrer algum erro durante a resolução da expressão.
     *
     * @throw antlr4::RuntimeException Se tiver algum erro durante o Lexer or Parser.
     */
    double Resolve(const double x);

  private:
    antlr4::ANTLRInputStream m_stream{ "" };
    AlgebricLexer m_lexer{ &m_stream };
    antlr4::CommonTokenStream m_tokenStream{ &m_lexer };
    AlgebricParser m_parser{ &m_tokenStream };
    AlgebricParser::EntryPointContext* m_entryPoint { nullptr };
  };
}
 


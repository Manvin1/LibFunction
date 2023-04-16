/*********************************************************************
 * @file AlgebricBaseVisitor.h
 * @brief Classe que representa um Visitor para expressões algébricas.
 *
 * Este arquivo contém classes que representam visitores para transcorrer AST geradas em um parsing. 
 * Contém-se implementações geradas a partir do Algebric.g4 pelo ANTLR 4.12.0.
 *
 * @date 2023
 *********************************************************************/

#pragma once

#include "AlgebricVisitor.h"

#include <antlr4-runtime.h>

/**
 * @brief Classe que provê uma implementação base de um AlgebricVisitor, evaluindo expressões algébricas e/ou aritméticas.
 */
class  AlgebricBaseVisitor : public AlgebricVisitor {
public:

  /**
   * @brief Default Constructor.
   * 
   * O valor inicial de x é 0.0.
   */
  explicit AlgebricBaseVisitor() = default;

  /**
   * @brief Construir o visitor com o valor de x especificado.
   * 
   * @param x
   */
  explicit AlgebricBaseVisitor(const double x)
    : m_x { x }
  {
    //nothing
  }

  /**
   * @brief Obter o valor de x.
   * 
   * @return o valor de x.
   */
  double getX() { return m_x; }

  /**
   * @brief Definir o valor de x.
   * 
   * @param x 
   */
  void setX(const double x) { m_x = x; }

  /**
   * @brief Visitir a EntryPoint Rule.
   * 
   * Esta função deve ser usada como entry point para evaluir a AST gerada por um Algebric Parser. Caso seja encontrado uma variável durante o transpassamento da AST, o valor atual de x, ao qual possivelmente é o inicial de 0.0.
   * 
   * @param ctx
   * 
   * @return o valor da expressão (double).
   * 
   * @throw std::runtime_error Se alguma expressão for invalida.
   * 
   * @throw antlr4::RuntimeException Se tiver algum erro durante o Lexer or Parser.
   */
  virtual std::any visitEntryPoint(AlgebricParser::EntryPointContext *ctx) override {
    return visitExpression(ctx->expression());
  }


private:

  /**
   * @brief Visitar uma Expression.
   *
   * Esta função determina o tipo dinâmico da expressão e a invocada.
   * 
   * @param ctx
   *
   * @return o valor da expressão (double).
   *
   * @throw std::runtime_error Se alguma expressão for invalida.
   *
   * @throw antlr4::RuntimeException Se tiver algum erro durante o Lexer or Parser.
   */
  std::any visitExpression(AlgebricParser::ExpressionContext* ctx) {

    if (auto type = dynamic_cast<AlgebricParser::BinaryExpressionP1Context*>(ctx)) { return visitBinaryExpressionP1(type); }

    else if (auto type = dynamic_cast<AlgebricParser::BinaryExpressionP2Context*>(ctx)) { return visitBinaryExpressionP2(type); }

    else if (auto type = dynamic_cast<AlgebricParser::UnaryExpressionContext*>(ctx)) { return visitUnaryExpression(type); }

    else if (auto type = dynamic_cast<AlgebricParser::ParenthesizedPrimaryExpressionContext*>(ctx)) { return visitParenthesizedPrimaryExpression(type); }

    else if (auto type = dynamic_cast<AlgebricParser::SqrtPrimaryExpressionContext*>(ctx)) { return visitSqrtPrimaryExpression(type); }

    else if (auto type = dynamic_cast<AlgebricParser::LiteralPrimaryExpressionContext*>(ctx)) { return visitLiteralPrimaryExpression(type); }

    if (ctx && ctx->exception)
    {
      std::rethrow_exception(ctx->exception);
    }

    throw std::runtime_error("Invalid Expression");
  }

  /**
   * @brief Visitar uma Operand P2 Expression.
   *
   * Esta função determina o tipo de operando P2, que consiste de {+,-};
   * 
   * @param ctx
   *
   * @return o valor do operando (std::string).
   *
   * @throw std::runtime_error Se o operando for desconhecido.
   *
   * @throw antlr4::RuntimeException Se tiver algum erro durante o Lexer or Parser.
   */
  std::string visitOperandP2(AlgebricParser::BinaryExpressionP2Context* ctx) {
    if (auto child = ctx->PLUS()) { return child->getText(); }

    else if (auto child = ctx->MINUS()) { return child->getText(); }

    if (ctx && ctx->exception)
    {
      std::rethrow_exception(ctx->exception);
    }

    throw std::runtime_error("Unknown P2 Operand");
  }

  /**
   * @brief Visitar uma Operand P1 Expression.
   *
   * Esta função determina o tipo de operando P1, que consiste de {*, /, ^};
   * 
   * @param ctx
   *
   * @return o valor do operando (std::string).
   *
   * @throw std::runtime_error Se o operando for desconhecido.
   *
   * @throw antlr4::RuntimeException Se tiver algum erro durante o Lexer or Parser.
   */
  std::string visitOperandP1(AlgebricParser::BinaryExpressionP1Context* ctx) {
    if (auto child = ctx->MULT()) { return child->getText(); }

    else if (auto child = ctx->DIV()) { return child->getText(); }

    else if (auto child = ctx->EXP()) { return child->getText(); }

    if (ctx && ctx->exception)
    {
      std::rethrow_exception(ctx->exception);
    }

    throw std::runtime_error("Unknown P1 Operand");
  }

  /**
   * @brief Visitar uma Operand Unary Expression.
   *
   * Esta função determina o tipo de operando Unary, que consiste de {+,-};
   * 
   * @param ctx
   *
   * @return o valor do operando (std::string).
   *
   * @throw std::runtime_error Se o operando for desconhecido.
   *
   * @throw antlr4::RuntimeException Se tiver algum erro durante o Lexer or Parser.
   */
  std::string visitOperandUnary(AlgebricParser::UnaryExpressionContext* ctx) {
    if (auto child = ctx->PLUS()) { return child->getText(); }

    else if (auto child = ctx->MINUS()) { return child->getText(); }

    if (ctx && ctx->exception)
    {
      std::rethrow_exception(ctx->exception);
    }

    throw std::runtime_error("Unknown Unary Operand");
  }

  //****** INHERITED FROM ALGEBRIC VISITOR ******

   /**
    * @brief Visitar uma Literal Primary Expression Rule
    *
    * @param ctx
    *
    * @return o valor da expressão (double).
    *
    * @throw std::runtime_error Se alguma expressão for invalida.
    *
    * @throw antlr4::RuntimeException Se tiver algum erro durante o Lexer or Parser.
    */
  virtual std::any visitLiteralPrimaryExpression(AlgebricParser::LiteralPrimaryExpressionContext* ctx) override {
    if (auto child = ctx->LITERAL())
    {
      std::string txt{ child->getText() };

      if (std::isalpha(txt.front()))
      {
        return m_x;
      }

      return std::stod(txt);
    }

    if (ctx && ctx->exception)
    {
      std::rethrow_exception(ctx->exception);
    }

    throw std::runtime_error("Invalid Literal Expression");
  }

  /**
   * @brief Visitar uma Sqrt Primary Expression Rule
   *
   * @param ctx
   *
   * @return o valor da expressão (double).
   *
   * @throw std::runtime_error Se alguma expressão for invalida.
   *
   * @throw antlr4::RuntimeException Se tiver algum erro durante o Lexer or Parser.
   */
  virtual std::any visitSqrtPrimaryExpression(AlgebricParser::SqrtPrimaryExpressionContext* ctx) override {
    if (auto child = ctx->expression()) { return std::sqrt(std::any_cast<double>(visitExpression(child))); }

    if (ctx && ctx->exception)
    {
      std::rethrow_exception(ctx->exception);
    }

    throw std::runtime_error("Invalid Sqrt Expression");
  }

  /**
   * @brief Visitar uma Parenthesized Primary Expression Rule
   *
   * @param ctx
   *
   * @return o valor da expressão (double).
   *
   * @throw std::runtime_error Se alguma expressão for invalida.
   *
   * @throw antlr4::RuntimeException Se tiver algum erro durante o Lexer or Parser.
   */
  virtual std::any visitParenthesizedPrimaryExpression(AlgebricParser::ParenthesizedPrimaryExpressionContext* ctx) override {
    if (auto child = ctx->expression()) { return visitExpression(child); }

    if (ctx && ctx->exception)
    {
      std::rethrow_exception(ctx->exception);
    }

    throw std::runtime_error("Invalid Parenthesized Expression");
  }

  /**
   * @brief Visitar uma Unary Primary Expression Rule
   *
   * @param ctx
   *
   * @return o valor da expressão (double).
   *
   * @throw std::runtime_error Se alguma expressão for invalida.
   *
   * @throw antlr4::RuntimeException Se tiver algum erro durante o Lexer or Parser.
   */
  virtual std::any visitUnaryExpression(AlgebricParser::UnaryExpressionContext* ctx) override {
    const std::string op{ visitOperandUnary(ctx) };
    const double result{ std::any_cast<double>(visitExpression(ctx->expression())) };

    if (op == "+") { return result; }

    else if (op == "-") { return -result; }

    if (ctx && ctx->exception)
    {
      std::rethrow_exception(ctx->exception);
    }

    throw std::runtime_error("Invalid Unary Expression");
  }

  /**
   * @brief Visitar uma Binary Expression P2 Rule
   *
   * @param ctx
   *
   * @return o valor da expressão (double).
   *
   * @throw std::runtime_error Se alguma expressão for invalida.
   *
   * @throw antlr4::RuntimeException Se tiver algum erro durante o Lexer or Parser.
   */
  virtual std::any visitBinaryExpressionP2(AlgebricParser::BinaryExpressionP2Context* ctx) override {
    const double lhs{ std::any_cast<double>(visitExpression(ctx->expression(0))) };
    const double rhs{ std::any_cast<double>(visitExpression(ctx->expression(1))) };
    std::string op{ visitOperandP2(ctx) };

    if (op == "+") { return lhs + rhs; }

    else if (op == "-") { return lhs - rhs; }

    if (ctx && ctx->exception)
    {
      std::rethrow_exception(ctx->exception);
    }

    throw std::runtime_error("Invalid BinaryExpressionP2");
  }

  /**
   * @brief Visitar uma Binary Expression P1 Rule
   *
   * @param ctx
   *
   * @return o valor da expressão (double).
   *
   * @throw std::runtime_error Se alguma expressão for invalida.
   *
   * @throw antlr4::RuntimeException Se tiver algum erro durante o Lexer or Parser.
   */
  virtual std::any visitBinaryExpressionP1(AlgebricParser::BinaryExpressionP1Context* ctx) override {
    const double lhs{ std::any_cast<double>(visitExpression(ctx->expression(0))) };
    const double rhs{ std::any_cast<double>(visitExpression(ctx->expression(1))) };
    std::string op{ visitOperandP1(ctx) };

    if (op == "*") { return lhs * rhs; }

    else if (op == "/") { if (rhs) { return lhs / rhs; } throw std::runtime_error("Div By 0"); }

    else if (op == "^") { return std::pow(lhs, rhs); }

    if (ctx && ctx->exception)
    {
      std::rethrow_exception(ctx->exception);
    }

    throw std::runtime_error("Invalid BinaryExpressionP1");
  }

  double m_x { 0.0 };
};


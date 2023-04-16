/*********************************************************************
 * @file AlgebricVisitor.h
 * @brief Classe que representam Algebric Visitors, ao qual possibilitam transpassar Algebric AST e evaluir expressões
 * 
 * Este arquivo contém classes que representam Algebric Visitors, de forma que é possível transpassar Algebric AST.
 * Contém-se implementações geradas a partir do Algebric.g4 pelo ANTLR 4.12.0.
 * 
 * @date 2023
 *********************************************************************/

#pragma once

#include "AlgebricParser.h"

#include <antlr4-runtime.h>

/**
 * @brief Classe que representa um AlgebricVisitor, ao qual possibilita transpassar AST geradas por um AlgebricParser, possibilitando a evaluação de expressões algébricas e/ou aritméticas.
 */
class  AlgebricVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

    virtual std::any visitEntryPoint(AlgebricParser::EntryPointContext *context) = 0;

    virtual std::any visitLiteralPrimaryExpression(AlgebricParser::LiteralPrimaryExpressionContext *context) = 0;

    virtual std::any visitSqrtPrimaryExpression(AlgebricParser::SqrtPrimaryExpressionContext *context) = 0;

    virtual std::any visitParenthesizedPrimaryExpression(AlgebricParser::ParenthesizedPrimaryExpressionContext *context) = 0;

    virtual std::any visitUnaryExpression(AlgebricParser::UnaryExpressionContext *context) = 0;

    virtual std::any visitBinaryExpressionP2(AlgebricParser::BinaryExpressionP2Context *context) = 0;

    virtual std::any visitBinaryExpressionP1(AlgebricParser::BinaryExpressionP1Context *context) = 0;
};


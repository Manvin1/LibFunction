/*********************************************************************
 * @file AlgebricParser.h
 * @brief Classes que representam Algebric Parsers para geração de AST.
 * 
 * Este arquivo contém classes que representam parsers, ao qual geram AST que podem ser posteriormente transpassadas. 
 * Contém-se implementações geradas a partir do Algebric.g4 pelo ANTLR 4.12.0.
 * 
 * @date 2023
 *********************************************************************/

#pragma once

#include <antlr4-runtime.h>

/**
 * @brief Classe que representa um AlgebricParser.
 */
class  AlgebricParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, PLUS = 4, MINUS = 5, MULT = 6, DIV = 7, 
    EXP = 8, LITERAL = 9, NUMBER = 10, VAR = 11, WHITESPACE = 12
  };

  enum {
    RuleEntryPoint = 0, RuleExpression = 1
  };

  explicit AlgebricParser(antlr4::TokenStream *input);

  AlgebricParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~AlgebricParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class EntryPointContext;
  class ExpressionContext; 

  class  EntryPointContext : public antlr4::ParserRuleContext {
  public:
    EntryPointContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  EntryPointContext* entryPoint();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExpressionContext() = default;
    void copyFrom(ExpressionContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;
  };

  class  LiteralPrimaryExpressionContext : public ExpressionContext {
  public:
    LiteralPrimaryExpressionContext(ExpressionContext *ctx);

    antlr4::tree::TerminalNode *LITERAL();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SqrtPrimaryExpressionContext : public ExpressionContext {
  public:
    SqrtPrimaryExpressionContext(ExpressionContext *ctx);

    ExpressionContext *expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenthesizedPrimaryExpressionContext : public ExpressionContext {
  public:
    ParenthesizedPrimaryExpressionContext(ExpressionContext *ctx);

    ExpressionContext *expression();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnaryExpressionContext : public ExpressionContext {
  public:
    UnaryExpressionContext(ExpressionContext *ctx);

    ExpressionContext *expression();
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BinaryExpressionP2Context : public ExpressionContext {
  public:
    BinaryExpressionP2Context(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *PLUS();
    antlr4::tree::TerminalNode *MINUS();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  BinaryExpressionP1Context : public ExpressionContext {
  public:
    BinaryExpressionP1Context(ExpressionContext *ctx);

    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *MULT();
    antlr4::tree::TerminalNode *DIV();
    antlr4::tree::TerminalNode *EXP();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExpressionContext* expression();
  ExpressionContext* expression(int precedence);

  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool expressionSempred(ExpressionContext *_localctx, size_t predicateIndex);

  static void initialize();
};


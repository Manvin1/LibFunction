/*********************************************************************
 * @file AlgebricLexer.h
 * @brief Classe que representam Algebric Lexers para geração de Tokens.
 * 
 * Este arquivo contém classes que representam Lexers para geração de tokens a partir de uma stream. para transcorrer AST geradas em um parsing. 
 * Contém-se implementações geradas a partir do Algebric.g4 pelo ANTLR 4.12.0.
 * 
 * @date 2023
 *********************************************************************/

#pragma once

#include <antlr4-runtime.h>

/**
 * @brief Classe que representa um Algebric Lexer.
 * 
 * As Lexer rules estão descritas em Algebric.g4.
 */
class  AlgebricLexer : public antlr4::Lexer {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, PLUS = 4, MINUS = 5, MULT = 6, DIV = 7, 
    EXP = 8, LITERAL = 9, NUMBER = 10, VAR = 11, WHITESPACE = 12
  };

  explicit AlgebricLexer(antlr4::CharStream *input);

  ~AlgebricLexer() override;

  std::string getGrammarFileName() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const std::vector<std::string>& getChannelNames() const override;

  const std::vector<std::string>& getModeNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;

  const antlr4::atn::ATN& getATN() const override;

  static void initialize();
};



// Generated from Algebric.g4 by ANTLR 4.12.0

#include "LibFunction/AlgebricParser.h"

#include "LibFunction/AlgebricVisitor.h"

using namespace antlrcpp;

using namespace antlr4;

namespace {

struct AlgebricParserStaticData final {
  AlgebricParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  AlgebricParserStaticData(const AlgebricParserStaticData&) = delete;
  AlgebricParserStaticData(AlgebricParserStaticData&&) = delete;
  AlgebricParserStaticData& operator=(const AlgebricParserStaticData&) = delete;
  AlgebricParserStaticData& operator=(AlgebricParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag algebricParserOnceFlag;
AlgebricParserStaticData *algebricParserStaticData = nullptr;

void algebricParserInitialize() {
  assert(algebricParserStaticData == nullptr);
  auto staticData = std::make_unique<AlgebricParserStaticData>(
    std::vector<std::string>{
      "entryPoint", "expression"
    },
    std::vector<std::string>{
      "", "'SQRT'", "'('", "')'", "'+'", "'-'", "'*'", "'/'", "'^'"
    },
    std::vector<std::string>{
      "", "", "", "", "PLUS", "MINUS", "MULT", "DIV", "EXP", "LITERAL", 
      "NUMBER", "VAR", "WHITESPACE"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,12,33,2,0,7,0,2,1,7,1,1,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,3,1,20,8,1,1,1,1,1,1,1,1,1,1,1,1,1,5,1,28,8,1,10,1,12,
  	1,31,9,1,1,1,0,1,2,2,0,2,0,2,1,0,4,5,1,0,6,8,35,0,4,1,0,0,0,2,19,1,0,
  	0,0,4,5,3,2,1,0,5,1,1,0,0,0,6,7,6,1,-1,0,7,20,5,9,0,0,8,9,5,1,0,0,9,10,
  	5,2,0,0,10,11,3,2,1,0,11,12,5,3,0,0,12,20,1,0,0,0,13,14,5,2,0,0,14,15,
  	3,2,1,0,15,16,5,3,0,0,16,20,1,0,0,0,17,18,7,0,0,0,18,20,3,2,1,3,19,6,
  	1,0,0,0,19,8,1,0,0,0,19,13,1,0,0,0,19,17,1,0,0,0,20,29,1,0,0,0,21,22,
  	10,2,0,0,22,23,7,1,0,0,23,28,3,2,1,3,24,25,10,1,0,0,25,26,7,0,0,0,26,
  	28,3,2,1,2,27,21,1,0,0,0,27,24,1,0,0,0,28,31,1,0,0,0,29,27,1,0,0,0,29,
  	30,1,0,0,0,30,3,1,0,0,0,31,29,1,0,0,0,3,19,27,29
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  algebricParserStaticData = staticData.release();
}

}

AlgebricParser::AlgebricParser(TokenStream *input) : AlgebricParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

AlgebricParser::AlgebricParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  AlgebricParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *algebricParserStaticData->atn, algebricParserStaticData->decisionToDFA, algebricParserStaticData->sharedContextCache, options);
}

AlgebricParser::~AlgebricParser() {
  delete _interpreter;
}

const atn::ATN& AlgebricParser::getATN() const {
  return *algebricParserStaticData->atn;
}

std::string AlgebricParser::getGrammarFileName() const {
  return "Algebric.g4";
}

const std::vector<std::string>& AlgebricParser::getRuleNames() const {
  return algebricParserStaticData->ruleNames;
}

const dfa::Vocabulary& AlgebricParser::getVocabulary() const {
  return algebricParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView AlgebricParser::getSerializedATN() const {
  return algebricParserStaticData->serializedATN;
}


//----------------- EntryPointContext ------------------------------------------------------------------

AlgebricParser::EntryPointContext::EntryPointContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

AlgebricParser::ExpressionContext* AlgebricParser::EntryPointContext::expression() {
  return getRuleContext<AlgebricParser::ExpressionContext>(0);
}


size_t AlgebricParser::EntryPointContext::getRuleIndex() const {
  return AlgebricParser::RuleEntryPoint;
}

std::any AlgebricParser::EntryPointContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AlgebricVisitor*>(visitor))
    return parserVisitor->visitEntryPoint(this);
  else
    return visitor->visitChildren(this);
}

AlgebricParser::EntryPointContext* AlgebricParser::entryPoint() {
  EntryPointContext *_localctx = _tracker.createInstance<EntryPointContext>(_ctx, getState());
  enterRule(_localctx, 0, AlgebricParser::RuleEntryPoint);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(4);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

AlgebricParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t AlgebricParser::ExpressionContext::getRuleIndex() const {
  return AlgebricParser::RuleExpression;
}

void AlgebricParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LiteralPrimaryExpressionContext ------------------------------------------------------------------

tree::TerminalNode* AlgebricParser::LiteralPrimaryExpressionContext::LITERAL() {
  return getToken(AlgebricParser::LITERAL, 0);
}

AlgebricParser::LiteralPrimaryExpressionContext::LiteralPrimaryExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any AlgebricParser::LiteralPrimaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AlgebricVisitor*>(visitor))
    return parserVisitor->visitLiteralPrimaryExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SqrtPrimaryExpressionContext ------------------------------------------------------------------

AlgebricParser::ExpressionContext* AlgebricParser::SqrtPrimaryExpressionContext::expression() {
  return getRuleContext<AlgebricParser::ExpressionContext>(0);
}

AlgebricParser::SqrtPrimaryExpressionContext::SqrtPrimaryExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any AlgebricParser::SqrtPrimaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AlgebricVisitor*>(visitor))
    return parserVisitor->visitSqrtPrimaryExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesizedPrimaryExpressionContext ------------------------------------------------------------------

AlgebricParser::ExpressionContext* AlgebricParser::ParenthesizedPrimaryExpressionContext::expression() {
  return getRuleContext<AlgebricParser::ExpressionContext>(0);
}

AlgebricParser::ParenthesizedPrimaryExpressionContext::ParenthesizedPrimaryExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any AlgebricParser::ParenthesizedPrimaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AlgebricVisitor*>(visitor))
    return parserVisitor->visitParenthesizedPrimaryExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryExpressionContext ------------------------------------------------------------------

AlgebricParser::ExpressionContext* AlgebricParser::UnaryExpressionContext::expression() {
  return getRuleContext<AlgebricParser::ExpressionContext>(0);
}

tree::TerminalNode* AlgebricParser::UnaryExpressionContext::PLUS() {
  return getToken(AlgebricParser::PLUS, 0);
}

tree::TerminalNode* AlgebricParser::UnaryExpressionContext::MINUS() {
  return getToken(AlgebricParser::MINUS, 0);
}

AlgebricParser::UnaryExpressionContext::UnaryExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

std::any AlgebricParser::UnaryExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AlgebricVisitor*>(visitor))
    return parserVisitor->visitUnaryExpression(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinaryExpressionP2Context ------------------------------------------------------------------

std::vector<AlgebricParser::ExpressionContext *> AlgebricParser::BinaryExpressionP2Context::expression() {
  return getRuleContexts<AlgebricParser::ExpressionContext>();
}

AlgebricParser::ExpressionContext* AlgebricParser::BinaryExpressionP2Context::expression(size_t i) {
  return getRuleContext<AlgebricParser::ExpressionContext>(i);
}

tree::TerminalNode* AlgebricParser::BinaryExpressionP2Context::PLUS() {
  return getToken(AlgebricParser::PLUS, 0);
}

tree::TerminalNode* AlgebricParser::BinaryExpressionP2Context::MINUS() {
  return getToken(AlgebricParser::MINUS, 0);
}

AlgebricParser::BinaryExpressionP2Context::BinaryExpressionP2Context(ExpressionContext *ctx) { copyFrom(ctx); }

std::any AlgebricParser::BinaryExpressionP2Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AlgebricVisitor*>(visitor))
    return parserVisitor->visitBinaryExpressionP2(this);
  else
    return visitor->visitChildren(this);
}
//----------------- BinaryExpressionP1Context ------------------------------------------------------------------

std::vector<AlgebricParser::ExpressionContext *> AlgebricParser::BinaryExpressionP1Context::expression() {
  return getRuleContexts<AlgebricParser::ExpressionContext>();
}

AlgebricParser::ExpressionContext* AlgebricParser::BinaryExpressionP1Context::expression(size_t i) {
  return getRuleContext<AlgebricParser::ExpressionContext>(i);
}

tree::TerminalNode* AlgebricParser::BinaryExpressionP1Context::MULT() {
  return getToken(AlgebricParser::MULT, 0);
}

tree::TerminalNode* AlgebricParser::BinaryExpressionP1Context::DIV() {
  return getToken(AlgebricParser::DIV, 0);
}

tree::TerminalNode* AlgebricParser::BinaryExpressionP1Context::EXP() {
  return getToken(AlgebricParser::EXP, 0);
}

AlgebricParser::BinaryExpressionP1Context::BinaryExpressionP1Context(ExpressionContext *ctx) { copyFrom(ctx); }

std::any AlgebricParser::BinaryExpressionP1Context::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<AlgebricVisitor*>(visitor))
    return parserVisitor->visitBinaryExpressionP1(this);
  else
    return visitor->visitChildren(this);
}

AlgebricParser::ExpressionContext* AlgebricParser::expression() {
   return expression(0);
}

AlgebricParser::ExpressionContext* AlgebricParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  AlgebricParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  AlgebricParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, AlgebricParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(19);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case AlgebricParser::LITERAL: {
        _localctx = _tracker.createInstance<LiteralPrimaryExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(7);
        match(AlgebricParser::LITERAL);
        break;
      }

      case AlgebricParser::T__0: {
        _localctx = _tracker.createInstance<SqrtPrimaryExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(8);
        match(AlgebricParser::T__0);
        setState(9);
        match(AlgebricParser::T__1);
        setState(10);
        expression(0);
        setState(11);
        match(AlgebricParser::T__2);
        break;
      }

      case AlgebricParser::T__1: {
        _localctx = _tracker.createInstance<ParenthesizedPrimaryExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(13);
        match(AlgebricParser::T__1);
        setState(14);
        expression(0);
        setState(15);
        match(AlgebricParser::T__2);
        break;
      }

      case AlgebricParser::PLUS:
      case AlgebricParser::MINUS: {
        _localctx = _tracker.createInstance<UnaryExpressionContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(17);
        _la = _input->LA(1);
        if (!(_la == AlgebricParser::PLUS

        || _la == AlgebricParser::MINUS)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(18);
        expression(3);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(29);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(27);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<BinaryExpressionP1Context>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(21);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(22);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & 448) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(23);
          expression(3);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<BinaryExpressionP2Context>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(24);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(25);
          _la = _input->LA(1);
          if (!(_la == AlgebricParser::PLUS

          || _la == AlgebricParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(26);
          expression(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(31);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool AlgebricParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool AlgebricParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);
    case 1: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

void AlgebricParser::initialize() {
  ::antlr4::internal::call_once(algebricParserOnceFlag, algebricParserInitialize);
}

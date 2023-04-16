
// Generated from Algebric.g4 by ANTLR 4.12.0

#include "LibFunction/AlgebricLexer.h"

using namespace antlr4;

namespace {

struct AlgebricLexerStaticData final {
  AlgebricLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  AlgebricLexerStaticData(const AlgebricLexerStaticData&) = delete;
  AlgebricLexerStaticData(AlgebricLexerStaticData&&) = delete;
  AlgebricLexerStaticData& operator=(const AlgebricLexerStaticData&) = delete;
  AlgebricLexerStaticData& operator=(AlgebricLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag algebriclexerLexerOnceFlag;
AlgebricLexerStaticData *algebriclexerLexerStaticData = nullptr;

void algebriclexerLexerInitialize() {
  assert(algebriclexerLexerStaticData == nullptr);
  auto staticData = std::make_unique<AlgebricLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "PLUS", "MINUS", "MULT", "DIV", "EXP", "LITERAL", 
      "NUMBER", "VAR", "WHITESPACE"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,12,70,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,1,0,1,0,1,0,1,0,1,1,
  	1,1,1,2,1,2,1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,3,8,47,8,
  	8,1,9,4,9,50,8,9,11,9,12,9,51,1,9,1,9,4,9,56,8,9,11,9,12,9,57,3,9,60,
  	8,9,1,10,1,10,1,11,4,11,65,8,11,11,11,12,11,66,1,11,1,11,0,0,12,1,1,3,
  	2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,23,12,1,0,2,1,0,48,57,2,
  	0,65,90,97,122,74,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,
  	1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,
  	0,0,0,21,1,0,0,0,0,23,1,0,0,0,1,25,1,0,0,0,3,30,1,0,0,0,5,32,1,0,0,0,
  	7,34,1,0,0,0,9,36,1,0,0,0,11,38,1,0,0,0,13,40,1,0,0,0,15,42,1,0,0,0,17,
  	46,1,0,0,0,19,49,1,0,0,0,21,61,1,0,0,0,23,64,1,0,0,0,25,26,5,83,0,0,26,
  	27,5,81,0,0,27,28,5,82,0,0,28,29,5,84,0,0,29,2,1,0,0,0,30,31,5,40,0,0,
  	31,4,1,0,0,0,32,33,5,41,0,0,33,6,1,0,0,0,34,35,5,43,0,0,35,8,1,0,0,0,
  	36,37,5,45,0,0,37,10,1,0,0,0,38,39,5,42,0,0,39,12,1,0,0,0,40,41,5,47,
  	0,0,41,14,1,0,0,0,42,43,5,94,0,0,43,16,1,0,0,0,44,47,3,19,9,0,45,47,3,
  	21,10,0,46,44,1,0,0,0,46,45,1,0,0,0,47,18,1,0,0,0,48,50,7,0,0,0,49,48,
  	1,0,0,0,50,51,1,0,0,0,51,49,1,0,0,0,51,52,1,0,0,0,52,59,1,0,0,0,53,55,
  	5,46,0,0,54,56,7,0,0,0,55,54,1,0,0,0,56,57,1,0,0,0,57,55,1,0,0,0,57,58,
  	1,0,0,0,58,60,1,0,0,0,59,53,1,0,0,0,59,60,1,0,0,0,60,20,1,0,0,0,61,62,
  	7,1,0,0,62,22,1,0,0,0,63,65,5,32,0,0,64,63,1,0,0,0,65,66,1,0,0,0,66,64,
  	1,0,0,0,66,67,1,0,0,0,67,68,1,0,0,0,68,69,6,11,0,0,69,24,1,0,0,0,6,0,
  	46,51,57,59,66,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  algebriclexerLexerStaticData = staticData.release();
}

}

AlgebricLexer::AlgebricLexer(CharStream *input) : Lexer(input) {
  AlgebricLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *algebriclexerLexerStaticData->atn, algebriclexerLexerStaticData->decisionToDFA, algebriclexerLexerStaticData->sharedContextCache);
}

AlgebricLexer::~AlgebricLexer() {
  delete _interpreter;
}

std::string AlgebricLexer::getGrammarFileName() const {
  return "Algebric.g4";
}

const std::vector<std::string>& AlgebricLexer::getRuleNames() const {
  return algebriclexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& AlgebricLexer::getChannelNames() const {
  return algebriclexerLexerStaticData->channelNames;
}

const std::vector<std::string>& AlgebricLexer::getModeNames() const {
  return algebriclexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& AlgebricLexer::getVocabulary() const {
  return algebriclexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView AlgebricLexer::getSerializedATN() const {
  return algebriclexerLexerStaticData->serializedATN;
}

const atn::ATN& AlgebricLexer::getATN() const {
  return *algebriclexerLexerStaticData->atn;
}




void AlgebricLexer::initialize() {
  ::antlr4::internal::call_once(algebriclexerLexerOnceFlag, algebriclexerLexerInitialize);
}

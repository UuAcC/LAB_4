
// Generated from poly_gram.g4 by ANTLR 4.13.2


#include "poly_gramLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct Poly_gramLexerStaticData final {
  Poly_gramLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  Poly_gramLexerStaticData(const Poly_gramLexerStaticData&) = delete;
  Poly_gramLexerStaticData(Poly_gramLexerStaticData&&) = delete;
  Poly_gramLexerStaticData& operator=(const Poly_gramLexerStaticData&) = delete;
  Poly_gramLexerStaticData& operator=(Poly_gramLexerStaticData&&) = delete;

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

::antlr4::internal::OnceFlag poly_gramlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<Poly_gramLexerStaticData> poly_gramlexerLexerStaticData = nullptr;

void poly_gramlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (poly_gramlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(poly_gramlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<Poly_gramLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "DOUBLE", "CHAR", 
      "WS", "MUL", "ADD"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'-'", "'('", "')'", "'x^'", "'y^'", "'z^'", "", "", "", "'*'", 
      "'+'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "DOUBLE", "CHAR", "WS", "MUL", "ADD"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,11,70,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,1,0,1,0,1,1,1,1,1,2,1,2,1,3,1,3,1,
  	3,1,4,1,4,1,4,1,5,1,5,1,5,1,6,1,6,1,6,5,6,42,8,6,10,6,12,6,45,9,6,3,6,
  	47,8,6,1,6,1,6,4,6,51,8,6,11,6,12,6,52,1,7,4,7,56,8,7,11,7,12,7,57,1,
  	8,4,8,61,8,8,11,8,12,8,62,1,8,1,8,1,9,1,9,1,10,1,10,0,0,11,1,1,3,2,5,
  	3,7,4,9,5,11,6,13,7,15,8,17,9,19,10,21,11,1,0,3,1,0,49,57,1,0,48,57,3,
  	0,9,10,13,13,32,32,74,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,
  	0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,
  	1,0,0,0,0,21,1,0,0,0,1,23,1,0,0,0,3,25,1,0,0,0,5,27,1,0,0,0,7,29,1,0,
  	0,0,9,32,1,0,0,0,11,35,1,0,0,0,13,46,1,0,0,0,15,55,1,0,0,0,17,60,1,0,
  	0,0,19,66,1,0,0,0,21,68,1,0,0,0,23,24,5,45,0,0,24,2,1,0,0,0,25,26,5,40,
  	0,0,26,4,1,0,0,0,27,28,5,41,0,0,28,6,1,0,0,0,29,30,5,120,0,0,30,31,5,
  	94,0,0,31,8,1,0,0,0,32,33,5,121,0,0,33,34,5,94,0,0,34,10,1,0,0,0,35,36,
  	5,122,0,0,36,37,5,94,0,0,37,12,1,0,0,0,38,47,5,48,0,0,39,43,7,0,0,0,40,
  	42,7,1,0,0,41,40,1,0,0,0,42,45,1,0,0,0,43,41,1,0,0,0,43,44,1,0,0,0,44,
  	47,1,0,0,0,45,43,1,0,0,0,46,38,1,0,0,0,46,39,1,0,0,0,47,48,1,0,0,0,48,
  	50,5,46,0,0,49,51,7,1,0,0,50,49,1,0,0,0,51,52,1,0,0,0,52,50,1,0,0,0,52,
  	53,1,0,0,0,53,14,1,0,0,0,54,56,7,1,0,0,55,54,1,0,0,0,56,57,1,0,0,0,57,
  	55,1,0,0,0,57,58,1,0,0,0,58,16,1,0,0,0,59,61,7,2,0,0,60,59,1,0,0,0,61,
  	62,1,0,0,0,62,60,1,0,0,0,62,63,1,0,0,0,63,64,1,0,0,0,64,65,6,8,0,0,65,
  	18,1,0,0,0,66,67,5,42,0,0,67,20,1,0,0,0,68,69,5,43,0,0,69,22,1,0,0,0,
  	6,0,43,46,52,57,62,1,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  poly_gramlexerLexerStaticData = std::move(staticData);
}

}

poly_gramLexer::poly_gramLexer(CharStream *input) : Lexer(input) {
  poly_gramLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *poly_gramlexerLexerStaticData->atn, poly_gramlexerLexerStaticData->decisionToDFA, poly_gramlexerLexerStaticData->sharedContextCache);
}

poly_gramLexer::~poly_gramLexer() {
  delete _interpreter;
}

std::string poly_gramLexer::getGrammarFileName() const {
  return "poly_gram.g4";
}

const std::vector<std::string>& poly_gramLexer::getRuleNames() const {
  return poly_gramlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& poly_gramLexer::getChannelNames() const {
  return poly_gramlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& poly_gramLexer::getModeNames() const {
  return poly_gramlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& poly_gramLexer::getVocabulary() const {
  return poly_gramlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView poly_gramLexer::getSerializedATN() const {
  return poly_gramlexerLexerStaticData->serializedATN;
}

const atn::ATN& poly_gramLexer::getATN() const {
  return *poly_gramlexerLexerStaticData->atn;
}




void poly_gramLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  poly_gramlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(poly_gramlexerLexerOnceFlag, poly_gramlexerLexerInitialize);
#endif
}

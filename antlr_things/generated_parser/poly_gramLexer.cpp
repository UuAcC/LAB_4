
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
      "T__0", "T__1", "T__2", "T__3", "T__4", "T__5", "T__6", "COEFF", "DEG", 
      "WS", "MUL", "ADD"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "'-'", "'('", "')'", "'x'", "'^'", "'y'", "'z'", "", "", "", "'*'", 
      "'+'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "COEFF", "DEG", "WS", "MUL", "ADD"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,12,77,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,1,0,1,1,1,1,1,2,1,2,
  	1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,7,5,7,43,8,7,10,7,12,7,46,9,
  	7,3,7,48,8,7,1,7,1,7,4,7,52,8,7,11,7,12,7,53,3,7,56,8,7,1,8,4,8,59,8,
  	8,11,8,12,8,60,1,8,1,8,3,8,65,8,8,1,9,4,9,68,8,9,11,9,12,9,69,1,9,1,9,
  	1,10,1,10,1,11,1,11,0,0,12,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,
  	10,21,11,23,12,1,0,4,1,0,49,57,1,0,48,57,2,0,44,44,46,46,3,0,9,10,13,
  	13,32,32,83,0,1,1,0,0,0,0,3,1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,
  	0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,
  	21,1,0,0,0,0,23,1,0,0,0,1,25,1,0,0,0,3,27,1,0,0,0,5,29,1,0,0,0,7,31,1,
  	0,0,0,9,33,1,0,0,0,11,35,1,0,0,0,13,37,1,0,0,0,15,47,1,0,0,0,17,64,1,
  	0,0,0,19,67,1,0,0,0,21,73,1,0,0,0,23,75,1,0,0,0,25,26,5,45,0,0,26,2,1,
  	0,0,0,27,28,5,40,0,0,28,4,1,0,0,0,29,30,5,41,0,0,30,6,1,0,0,0,31,32,5,
  	120,0,0,32,8,1,0,0,0,33,34,5,94,0,0,34,10,1,0,0,0,35,36,5,121,0,0,36,
  	12,1,0,0,0,37,38,5,122,0,0,38,14,1,0,0,0,39,48,5,48,0,0,40,44,7,0,0,0,
  	41,43,7,1,0,0,42,41,1,0,0,0,43,46,1,0,0,0,44,42,1,0,0,0,44,45,1,0,0,0,
  	45,48,1,0,0,0,46,44,1,0,0,0,47,39,1,0,0,0,47,40,1,0,0,0,48,55,1,0,0,0,
  	49,51,7,2,0,0,50,52,7,1,0,0,51,50,1,0,0,0,52,53,1,0,0,0,53,51,1,0,0,0,
  	53,54,1,0,0,0,54,56,1,0,0,0,55,49,1,0,0,0,55,56,1,0,0,0,56,16,1,0,0,0,
  	57,59,7,1,0,0,58,57,1,0,0,0,59,60,1,0,0,0,60,58,1,0,0,0,60,61,1,0,0,0,
  	61,65,1,0,0,0,62,63,5,45,0,0,63,65,3,17,8,0,64,58,1,0,0,0,64,62,1,0,0,
  	0,65,18,1,0,0,0,66,68,7,3,0,0,67,66,1,0,0,0,68,69,1,0,0,0,69,67,1,0,0,
  	0,69,70,1,0,0,0,70,71,1,0,0,0,71,72,6,9,0,0,72,20,1,0,0,0,73,74,5,42,
  	0,0,74,22,1,0,0,0,75,76,5,43,0,0,76,24,1,0,0,0,8,0,44,47,53,55,60,64,
  	69,1,6,0,0
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

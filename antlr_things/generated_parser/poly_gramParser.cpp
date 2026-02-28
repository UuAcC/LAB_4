
// Generated from poly_gram.g4 by ANTLR 4.13.2


#include "poly_gramVisitor.h"

#include "poly_gramParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct Poly_gramParserStaticData final {
  Poly_gramParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  Poly_gramParserStaticData(const Poly_gramParserStaticData&) = delete;
  Poly_gramParserStaticData(Poly_gramParserStaticData&&) = delete;
  Poly_gramParserStaticData& operator=(const Poly_gramParserStaticData&) = delete;
  Poly_gramParserStaticData& operator=(Poly_gramParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag poly_gramParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<Poly_gramParserStaticData> poly_gramParserStaticData = nullptr;

void poly_gramParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (poly_gramParserStaticData != nullptr) {
    return;
  }
#else
  assert(poly_gramParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<Poly_gramParserStaticData>(
    std::vector<std::string>{
      "polynome", "monome", "x_var", "y_var", "z_var"
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
  	4,1,12,50,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,1,0,1,0,1,0,1,0,1,0,
  	1,0,5,0,17,8,0,10,0,12,0,20,9,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,3,1,36,8,1,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,4,1,4,
  	1,4,1,4,1,4,0,1,0,5,0,2,4,6,8,0,0,47,0,10,1,0,0,0,2,35,1,0,0,0,4,37,1,
  	0,0,0,6,41,1,0,0,0,8,45,1,0,0,0,10,11,6,0,-1,0,11,12,3,2,1,0,12,18,1,
  	0,0,0,13,14,10,2,0,0,14,15,5,12,0,0,15,17,3,2,1,0,16,13,1,0,0,0,17,20,
  	1,0,0,0,18,16,1,0,0,0,18,19,1,0,0,0,19,1,1,0,0,0,20,18,1,0,0,0,21,22,
  	5,1,0,0,22,36,3,2,1,0,23,24,5,2,0,0,24,25,3,2,1,0,25,26,5,3,0,0,26,36,
  	1,0,0,0,27,28,5,8,0,0,28,29,5,11,0,0,29,30,3,4,2,0,30,31,5,11,0,0,31,
  	32,3,6,3,0,32,33,5,11,0,0,33,34,3,8,4,0,34,36,1,0,0,0,35,21,1,0,0,0,35,
  	23,1,0,0,0,35,27,1,0,0,0,36,3,1,0,0,0,37,38,5,4,0,0,38,39,5,5,0,0,39,
  	40,5,9,0,0,40,5,1,0,0,0,41,42,5,6,0,0,42,43,5,5,0,0,43,44,5,9,0,0,44,
  	7,1,0,0,0,45,46,5,7,0,0,46,47,5,5,0,0,47,48,5,9,0,0,48,9,1,0,0,0,2,18,
  	35
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  poly_gramParserStaticData = std::move(staticData);
}

}

poly_gramParser::poly_gramParser(TokenStream *input) : poly_gramParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

poly_gramParser::poly_gramParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  poly_gramParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *poly_gramParserStaticData->atn, poly_gramParserStaticData->decisionToDFA, poly_gramParserStaticData->sharedContextCache, options);
}

poly_gramParser::~poly_gramParser() {
  delete _interpreter;
}

const atn::ATN& poly_gramParser::getATN() const {
  return *poly_gramParserStaticData->atn;
}

std::string poly_gramParser::getGrammarFileName() const {
  return "poly_gram.g4";
}

const std::vector<std::string>& poly_gramParser::getRuleNames() const {
  return poly_gramParserStaticData->ruleNames;
}

const dfa::Vocabulary& poly_gramParser::getVocabulary() const {
  return poly_gramParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView poly_gramParser::getSerializedATN() const {
  return poly_gramParserStaticData->serializedATN;
}


//----------------- PolynomeContext ------------------------------------------------------------------

poly_gramParser::PolynomeContext::PolynomeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

poly_gramParser::MonomeContext* poly_gramParser::PolynomeContext::monome() {
  return getRuleContext<poly_gramParser::MonomeContext>(0);
}

poly_gramParser::PolynomeContext* poly_gramParser::PolynomeContext::polynome() {
  return getRuleContext<poly_gramParser::PolynomeContext>(0);
}

tree::TerminalNode* poly_gramParser::PolynomeContext::ADD() {
  return getToken(poly_gramParser::ADD, 0);
}


size_t poly_gramParser::PolynomeContext::getRuleIndex() const {
  return poly_gramParser::RulePolynome;
}


std::any poly_gramParser::PolynomeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<poly_gramVisitor*>(visitor))
    return parserVisitor->visitPolynome(this);
  else
    return visitor->visitChildren(this);
}


poly_gramParser::PolynomeContext* poly_gramParser::polynome() {
   return polynome(0);
}

poly_gramParser::PolynomeContext* poly_gramParser::polynome(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  poly_gramParser::PolynomeContext *_localctx = _tracker.createInstance<PolynomeContext>(_ctx, parentState);
  poly_gramParser::PolynomeContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 0;
  enterRecursionRule(_localctx, 0, poly_gramParser::RulePolynome, precedence);

    

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
    setState(11);
    monome();
    _ctx->stop = _input->LT(-1);
    setState(18);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<PolynomeContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RulePolynome);
        setState(13);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(14);
        match(poly_gramParser::ADD);
        setState(15);
        monome(); 
      }
      setState(20);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 0, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- MonomeContext ------------------------------------------------------------------

poly_gramParser::MonomeContext::MonomeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

poly_gramParser::MonomeContext* poly_gramParser::MonomeContext::monome() {
  return getRuleContext<poly_gramParser::MonomeContext>(0);
}

tree::TerminalNode* poly_gramParser::MonomeContext::COEFF() {
  return getToken(poly_gramParser::COEFF, 0);
}

std::vector<tree::TerminalNode *> poly_gramParser::MonomeContext::MUL() {
  return getTokens(poly_gramParser::MUL);
}

tree::TerminalNode* poly_gramParser::MonomeContext::MUL(size_t i) {
  return getToken(poly_gramParser::MUL, i);
}

poly_gramParser::X_varContext* poly_gramParser::MonomeContext::x_var() {
  return getRuleContext<poly_gramParser::X_varContext>(0);
}

poly_gramParser::Y_varContext* poly_gramParser::MonomeContext::y_var() {
  return getRuleContext<poly_gramParser::Y_varContext>(0);
}

poly_gramParser::Z_varContext* poly_gramParser::MonomeContext::z_var() {
  return getRuleContext<poly_gramParser::Z_varContext>(0);
}


size_t poly_gramParser::MonomeContext::getRuleIndex() const {
  return poly_gramParser::RuleMonome;
}


std::any poly_gramParser::MonomeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<poly_gramVisitor*>(visitor))
    return parserVisitor->visitMonome(this);
  else
    return visitor->visitChildren(this);
}

poly_gramParser::MonomeContext* poly_gramParser::monome() {
  MonomeContext *_localctx = _tracker.createInstance<MonomeContext>(_ctx, getState());
  enterRule(_localctx, 2, poly_gramParser::RuleMonome);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(35);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case poly_gramParser::T__0: {
        enterOuterAlt(_localctx, 1);
        setState(21);
        match(poly_gramParser::T__0);
        setState(22);
        monome();
        break;
      }

      case poly_gramParser::T__1: {
        enterOuterAlt(_localctx, 2);
        setState(23);
        match(poly_gramParser::T__1);
        setState(24);
        monome();
        setState(25);
        match(poly_gramParser::T__2);
        break;
      }

      case poly_gramParser::COEFF: {
        enterOuterAlt(_localctx, 3);
        setState(27);
        match(poly_gramParser::COEFF);
        setState(28);
        match(poly_gramParser::MUL);
        setState(29);
        x_var();
        setState(30);
        match(poly_gramParser::MUL);
        setState(31);
        y_var();
        setState(32);
        match(poly_gramParser::MUL);
        setState(33);
        z_var();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- X_varContext ------------------------------------------------------------------

poly_gramParser::X_varContext::X_varContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* poly_gramParser::X_varContext::DEG() {
  return getToken(poly_gramParser::DEG, 0);
}


size_t poly_gramParser::X_varContext::getRuleIndex() const {
  return poly_gramParser::RuleX_var;
}


std::any poly_gramParser::X_varContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<poly_gramVisitor*>(visitor))
    return parserVisitor->visitX_var(this);
  else
    return visitor->visitChildren(this);
}

poly_gramParser::X_varContext* poly_gramParser::x_var() {
  X_varContext *_localctx = _tracker.createInstance<X_varContext>(_ctx, getState());
  enterRule(_localctx, 4, poly_gramParser::RuleX_var);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(37);
    match(poly_gramParser::T__3);
    setState(38);
    match(poly_gramParser::T__4);
    setState(39);
    match(poly_gramParser::DEG);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Y_varContext ------------------------------------------------------------------

poly_gramParser::Y_varContext::Y_varContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* poly_gramParser::Y_varContext::DEG() {
  return getToken(poly_gramParser::DEG, 0);
}


size_t poly_gramParser::Y_varContext::getRuleIndex() const {
  return poly_gramParser::RuleY_var;
}


std::any poly_gramParser::Y_varContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<poly_gramVisitor*>(visitor))
    return parserVisitor->visitY_var(this);
  else
    return visitor->visitChildren(this);
}

poly_gramParser::Y_varContext* poly_gramParser::y_var() {
  Y_varContext *_localctx = _tracker.createInstance<Y_varContext>(_ctx, getState());
  enterRule(_localctx, 6, poly_gramParser::RuleY_var);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(41);
    match(poly_gramParser::T__5);
    setState(42);
    match(poly_gramParser::T__4);
    setState(43);
    match(poly_gramParser::DEG);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Z_varContext ------------------------------------------------------------------

poly_gramParser::Z_varContext::Z_varContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* poly_gramParser::Z_varContext::DEG() {
  return getToken(poly_gramParser::DEG, 0);
}


size_t poly_gramParser::Z_varContext::getRuleIndex() const {
  return poly_gramParser::RuleZ_var;
}


std::any poly_gramParser::Z_varContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<poly_gramVisitor*>(visitor))
    return parserVisitor->visitZ_var(this);
  else
    return visitor->visitChildren(this);
}

poly_gramParser::Z_varContext* poly_gramParser::z_var() {
  Z_varContext *_localctx = _tracker.createInstance<Z_varContext>(_ctx, getState());
  enterRule(_localctx, 8, poly_gramParser::RuleZ_var);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(45);
    match(poly_gramParser::T__6);
    setState(46);
    match(poly_gramParser::T__4);
    setState(47);
    match(poly_gramParser::DEG);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool poly_gramParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 0: return polynomeSempred(antlrcpp::downCast<PolynomeContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool poly_gramParser::polynomeSempred(PolynomeContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 2);

  default:
    break;
  }
  return true;
}

void poly_gramParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  poly_gramParserInitialize();
#else
  ::antlr4::internal::call_once(poly_gramParserOnceFlag, poly_gramParserInitialize);
#endif
}

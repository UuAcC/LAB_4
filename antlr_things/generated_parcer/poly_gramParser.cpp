
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
      "polynome", "monome", "variable", "degree", "coeff"
    },
    std::vector<std::string>{
      "", "'-'", "'('", "')'", "'x'", "'y'", "'z'", "'^'", "", "", "", "'*'", 
      "'+'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "", "", "DOUBLE", "CHAR", "WS", "MUL", "ADD"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,12,49,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,1,0,1,0,1,0,1,0,1,0,
  	1,0,5,0,17,8,0,10,0,12,0,20,9,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,1,1,3,1,36,8,1,1,2,1,2,1,2,1,2,1,3,1,3,1,3,3,3,45,8,3,1,
  	4,1,4,1,4,0,1,0,5,0,2,4,6,8,0,1,1,0,4,6,47,0,10,1,0,0,0,2,35,1,0,0,0,
  	4,37,1,0,0,0,6,44,1,0,0,0,8,46,1,0,0,0,10,11,6,0,-1,0,11,12,3,2,1,0,12,
  	18,1,0,0,0,13,14,10,2,0,0,14,15,5,12,0,0,15,17,3,2,1,0,16,13,1,0,0,0,
  	17,20,1,0,0,0,18,16,1,0,0,0,18,19,1,0,0,0,19,1,1,0,0,0,20,18,1,0,0,0,
  	21,22,5,1,0,0,22,36,3,2,1,0,23,24,5,2,0,0,24,25,3,2,1,0,25,26,5,3,0,0,
  	26,36,1,0,0,0,27,28,3,8,4,0,28,29,5,11,0,0,29,30,3,4,2,0,30,31,5,11,0,
  	0,31,32,3,4,2,0,32,33,5,11,0,0,33,34,3,4,2,0,34,36,1,0,0,0,35,21,1,0,
  	0,0,35,23,1,0,0,0,35,27,1,0,0,0,36,3,1,0,0,0,37,38,7,0,0,0,38,39,5,7,
  	0,0,39,40,3,6,3,0,40,5,1,0,0,0,41,42,5,1,0,0,42,45,3,6,3,0,43,45,5,9,
  	0,0,44,41,1,0,0,0,44,43,1,0,0,0,45,7,1,0,0,0,46,47,5,8,0,0,47,9,1,0,0,
  	0,3,18,35,44
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


size_t poly_gramParser::PolynomeContext::getRuleIndex() const {
  return poly_gramParser::RulePolynome;
}

void poly_gramParser::PolynomeContext::copyFrom(PolynomeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- SingleMonomePolynomeContext ------------------------------------------------------------------

poly_gramParser::MonomeContext* poly_gramParser::SingleMonomePolynomeContext::monome() {
  return getRuleContext<poly_gramParser::MonomeContext>(0);
}

poly_gramParser::SingleMonomePolynomeContext::SingleMonomePolynomeContext(PolynomeContext *ctx) { copyFrom(ctx); }


std::any poly_gramParser::SingleMonomePolynomeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<poly_gramVisitor*>(visitor))
    return parserVisitor->visitSingleMonomePolynome(this);
  else
    return visitor->visitChildren(this);
}
//----------------- SumOfMonomesPolynomeContext ------------------------------------------------------------------

poly_gramParser::PolynomeContext* poly_gramParser::SumOfMonomesPolynomeContext::polynome() {
  return getRuleContext<poly_gramParser::PolynomeContext>(0);
}

tree::TerminalNode* poly_gramParser::SumOfMonomesPolynomeContext::ADD() {
  return getToken(poly_gramParser::ADD, 0);
}

poly_gramParser::MonomeContext* poly_gramParser::SumOfMonomesPolynomeContext::monome() {
  return getRuleContext<poly_gramParser::MonomeContext>(0);
}

poly_gramParser::SumOfMonomesPolynomeContext::SumOfMonomesPolynomeContext(PolynomeContext *ctx) { copyFrom(ctx); }


std::any poly_gramParser::SumOfMonomesPolynomeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<poly_gramVisitor*>(visitor))
    return parserVisitor->visitSumOfMonomesPolynome(this);
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
    _localctx = _tracker.createInstance<SingleMonomePolynomeContext>(_localctx);
    _ctx = _localctx;
    previousContext = _localctx;

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
        auto newContext = _tracker.createInstance<SumOfMonomesPolynomeContext>(_tracker.createInstance<PolynomeContext>(parentContext, parentState));
        _localctx = newContext;
        pushNewRecursionContext(newContext, startState, RulePolynome);
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


size_t poly_gramParser::MonomeContext::getRuleIndex() const {
  return poly_gramParser::RuleMonome;
}

void poly_gramParser::MonomeContext::copyFrom(MonomeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ParensMonomeContext ------------------------------------------------------------------

poly_gramParser::MonomeContext* poly_gramParser::ParensMonomeContext::monome() {
  return getRuleContext<poly_gramParser::MonomeContext>(0);
}

poly_gramParser::ParensMonomeContext::ParensMonomeContext(MonomeContext *ctx) { copyFrom(ctx); }


std::any poly_gramParser::ParensMonomeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<poly_gramVisitor*>(visitor))
    return parserVisitor->visitParensMonome(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryMinusMonomeContext ------------------------------------------------------------------

poly_gramParser::MonomeContext* poly_gramParser::UnaryMinusMonomeContext::monome() {
  return getRuleContext<poly_gramParser::MonomeContext>(0);
}

poly_gramParser::UnaryMinusMonomeContext::UnaryMinusMonomeContext(MonomeContext *ctx) { copyFrom(ctx); }


std::any poly_gramParser::UnaryMinusMonomeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<poly_gramVisitor*>(visitor))
    return parserVisitor->visitUnaryMinusMonome(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FinalMonomeContext ------------------------------------------------------------------

poly_gramParser::CoeffContext* poly_gramParser::FinalMonomeContext::coeff() {
  return getRuleContext<poly_gramParser::CoeffContext>(0);
}

std::vector<tree::TerminalNode *> poly_gramParser::FinalMonomeContext::MUL() {
  return getTokens(poly_gramParser::MUL);
}

tree::TerminalNode* poly_gramParser::FinalMonomeContext::MUL(size_t i) {
  return getToken(poly_gramParser::MUL, i);
}

std::vector<poly_gramParser::VariableContext *> poly_gramParser::FinalMonomeContext::variable() {
  return getRuleContexts<poly_gramParser::VariableContext>();
}

poly_gramParser::VariableContext* poly_gramParser::FinalMonomeContext::variable(size_t i) {
  return getRuleContext<poly_gramParser::VariableContext>(i);
}

poly_gramParser::FinalMonomeContext::FinalMonomeContext(MonomeContext *ctx) { copyFrom(ctx); }


std::any poly_gramParser::FinalMonomeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<poly_gramVisitor*>(visitor))
    return parserVisitor->visitFinalMonome(this);
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
        _localctx = _tracker.createInstance<poly_gramParser::UnaryMinusMonomeContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(21);
        match(poly_gramParser::T__0);
        setState(22);
        monome();
        break;
      }

      case poly_gramParser::T__1: {
        _localctx = _tracker.createInstance<poly_gramParser::ParensMonomeContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(23);
        match(poly_gramParser::T__1);
        setState(24);
        monome();
        setState(25);
        match(poly_gramParser::T__2);
        break;
      }

      case poly_gramParser::DOUBLE: {
        _localctx = _tracker.createInstance<poly_gramParser::FinalMonomeContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(27);
        coeff();
        setState(28);
        match(poly_gramParser::MUL);
        setState(29);
        variable();
        setState(30);
        match(poly_gramParser::MUL);
        setState(31);
        variable();
        setState(32);
        match(poly_gramParser::MUL);
        setState(33);
        variable();
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

//----------------- VariableContext ------------------------------------------------------------------

poly_gramParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

poly_gramParser::DegreeContext* poly_gramParser::VariableContext::degree() {
  return getRuleContext<poly_gramParser::DegreeContext>(0);
}


size_t poly_gramParser::VariableContext::getRuleIndex() const {
  return poly_gramParser::RuleVariable;
}


std::any poly_gramParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<poly_gramVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

poly_gramParser::VariableContext* poly_gramParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 4, poly_gramParser::RuleVariable);
  size_t _la = 0;

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
    antlrcpp::downCast<VariableContext *>(_localctx)->var = _input->LT(1);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 112) != 0))) {
      antlrcpp::downCast<VariableContext *>(_localctx)->var = _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(38);
    match(poly_gramParser::T__6);
    setState(39);
    degree();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DegreeContext ------------------------------------------------------------------

poly_gramParser::DegreeContext::DegreeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t poly_gramParser::DegreeContext::getRuleIndex() const {
  return poly_gramParser::RuleDegree;
}

void poly_gramParser::DegreeContext::copyFrom(DegreeContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- CharContext ------------------------------------------------------------------

tree::TerminalNode* poly_gramParser::CharContext::CHAR() {
  return getToken(poly_gramParser::CHAR, 0);
}

poly_gramParser::CharContext::CharContext(DegreeContext *ctx) { copyFrom(ctx); }


std::any poly_gramParser::CharContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<poly_gramVisitor*>(visitor))
    return parserVisitor->visitChar(this);
  else
    return visitor->visitChildren(this);
}
//----------------- UnaryMinusDegreeContext ------------------------------------------------------------------

poly_gramParser::DegreeContext* poly_gramParser::UnaryMinusDegreeContext::degree() {
  return getRuleContext<poly_gramParser::DegreeContext>(0);
}

poly_gramParser::UnaryMinusDegreeContext::UnaryMinusDegreeContext(DegreeContext *ctx) { copyFrom(ctx); }


std::any poly_gramParser::UnaryMinusDegreeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<poly_gramVisitor*>(visitor))
    return parserVisitor->visitUnaryMinusDegree(this);
  else
    return visitor->visitChildren(this);
}
poly_gramParser::DegreeContext* poly_gramParser::degree() {
  DegreeContext *_localctx = _tracker.createInstance<DegreeContext>(_ctx, getState());
  enterRule(_localctx, 6, poly_gramParser::RuleDegree);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(44);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case poly_gramParser::T__0: {
        _localctx = _tracker.createInstance<poly_gramParser::UnaryMinusDegreeContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(41);
        match(poly_gramParser::T__0);
        setState(42);
        degree();
        break;
      }

      case poly_gramParser::CHAR: {
        _localctx = _tracker.createInstance<poly_gramParser::CharContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(43);
        match(poly_gramParser::CHAR);
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

//----------------- CoeffContext ------------------------------------------------------------------

poly_gramParser::CoeffContext::CoeffContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t poly_gramParser::CoeffContext::getRuleIndex() const {
  return poly_gramParser::RuleCoeff;
}

void poly_gramParser::CoeffContext::copyFrom(CoeffContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- DoubleContext ------------------------------------------------------------------

tree::TerminalNode* poly_gramParser::DoubleContext::DOUBLE() {
  return getToken(poly_gramParser::DOUBLE, 0);
}

poly_gramParser::DoubleContext::DoubleContext(CoeffContext *ctx) { copyFrom(ctx); }


std::any poly_gramParser::DoubleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<poly_gramVisitor*>(visitor))
    return parserVisitor->visitDouble(this);
  else
    return visitor->visitChildren(this);
}
poly_gramParser::CoeffContext* poly_gramParser::coeff() {
  CoeffContext *_localctx = _tracker.createInstance<CoeffContext>(_ctx, getState());
  enterRule(_localctx, 8, poly_gramParser::RuleCoeff);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    _localctx = _tracker.createInstance<poly_gramParser::DoubleContext>(_localctx);
    enterOuterAlt(_localctx, 1);
    setState(46);
    match(poly_gramParser::DOUBLE);
   
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


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
      "polynome", "monome", "x_var", "y_var", "z_var", "degree", "coeff"
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
  	4,1,11,63,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,1,0,
  	1,0,1,0,1,0,1,0,1,0,5,0,21,8,0,10,0,12,0,24,9,0,1,1,1,1,1,1,1,1,1,1,1,
  	1,1,1,1,1,1,1,3,1,35,8,1,1,1,1,1,3,1,39,8,1,1,1,1,1,3,1,43,8,1,3,1,45,
  	8,1,1,2,1,2,1,2,1,3,1,3,1,3,1,4,1,4,1,4,1,5,1,5,1,5,3,5,59,8,5,1,6,1,
  	6,1,6,0,1,0,7,0,2,4,6,8,10,12,0,0,62,0,14,1,0,0,0,2,44,1,0,0,0,4,46,1,
  	0,0,0,6,49,1,0,0,0,8,52,1,0,0,0,10,58,1,0,0,0,12,60,1,0,0,0,14,15,6,0,
  	-1,0,15,16,3,2,1,0,16,22,1,0,0,0,17,18,10,2,0,0,18,19,5,11,0,0,19,21,
  	3,2,1,0,20,17,1,0,0,0,21,24,1,0,0,0,22,20,1,0,0,0,22,23,1,0,0,0,23,1,
  	1,0,0,0,24,22,1,0,0,0,25,26,5,1,0,0,26,45,3,2,1,0,27,28,5,2,0,0,28,29,
  	3,2,1,0,29,30,5,3,0,0,30,45,1,0,0,0,31,34,3,12,6,0,32,33,5,10,0,0,33,
  	35,3,4,2,0,34,32,1,0,0,0,34,35,1,0,0,0,35,38,1,0,0,0,36,37,5,10,0,0,37,
  	39,3,6,3,0,38,36,1,0,0,0,38,39,1,0,0,0,39,42,1,0,0,0,40,41,5,10,0,0,41,
  	43,3,8,4,0,42,40,1,0,0,0,42,43,1,0,0,0,43,45,1,0,0,0,44,25,1,0,0,0,44,
  	27,1,0,0,0,44,31,1,0,0,0,45,3,1,0,0,0,46,47,5,4,0,0,47,48,3,10,5,0,48,
  	5,1,0,0,0,49,50,5,5,0,0,50,51,3,10,5,0,51,7,1,0,0,0,52,53,5,6,0,0,53,
  	54,3,10,5,0,54,9,1,0,0,0,55,56,5,1,0,0,56,59,3,10,5,0,57,59,5,8,0,0,58,
  	55,1,0,0,0,58,57,1,0,0,0,59,11,1,0,0,0,60,61,5,7,0,0,61,13,1,0,0,0,6,
  	22,34,38,42,44,58
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

    setState(15);
    monome();
    _ctx->stop = _input->LT(-1);
    setState(22);
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
        setState(17);

        if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
        setState(18);
        match(poly_gramParser::ADD);
        setState(19);
        monome(); 
      }
      setState(24);
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

poly_gramParser::X_varContext* poly_gramParser::FinalMonomeContext::x_var() {
  return getRuleContext<poly_gramParser::X_varContext>(0);
}

poly_gramParser::Y_varContext* poly_gramParser::FinalMonomeContext::y_var() {
  return getRuleContext<poly_gramParser::Y_varContext>(0);
}

poly_gramParser::Z_varContext* poly_gramParser::FinalMonomeContext::z_var() {
  return getRuleContext<poly_gramParser::Z_varContext>(0);
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
    setState(44);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case poly_gramParser::T__0: {
        _localctx = _tracker.createInstance<poly_gramParser::UnaryMinusMonomeContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(25);
        match(poly_gramParser::T__0);
        setState(26);
        monome();
        break;
      }

      case poly_gramParser::T__1: {
        _localctx = _tracker.createInstance<poly_gramParser::ParensMonomeContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(27);
        match(poly_gramParser::T__1);
        setState(28);
        monome();
        setState(29);
        match(poly_gramParser::T__2);
        break;
      }

      case poly_gramParser::DOUBLE: {
        _localctx = _tracker.createInstance<poly_gramParser::FinalMonomeContext>(_localctx);
        enterOuterAlt(_localctx, 3);
        setState(31);
        coeff();
        setState(34);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          setState(32);
          match(poly_gramParser::MUL);
          setState(33);
          x_var();
          break;
        }

        default:
          break;
        }
        setState(38);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
        case 1: {
          setState(36);
          match(poly_gramParser::MUL);
          setState(37);
          y_var();
          break;
        }

        default:
          break;
        }
        setState(42);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
        case 1: {
          setState(40);
          match(poly_gramParser::MUL);
          setState(41);
          z_var();
          break;
        }

        default:
          break;
        }
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

poly_gramParser::DegreeContext* poly_gramParser::X_varContext::degree() {
  return getRuleContext<poly_gramParser::DegreeContext>(0);
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
    setState(46);
    match(poly_gramParser::T__3);
    setState(47);
    degree();
   
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

poly_gramParser::DegreeContext* poly_gramParser::Y_varContext::degree() {
  return getRuleContext<poly_gramParser::DegreeContext>(0);
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
    setState(49);
    match(poly_gramParser::T__4);
    setState(50);
    degree();
   
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

poly_gramParser::DegreeContext* poly_gramParser::Z_varContext::degree() {
  return getRuleContext<poly_gramParser::DegreeContext>(0);
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
    setState(52);
    match(poly_gramParser::T__5);
    setState(53);
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
  enterRule(_localctx, 10, poly_gramParser::RuleDegree);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(58);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case poly_gramParser::T__0: {
        _localctx = _tracker.createInstance<poly_gramParser::UnaryMinusDegreeContext>(_localctx);
        enterOuterAlt(_localctx, 1);
        setState(55);
        match(poly_gramParser::T__0);
        setState(56);
        degree();
        break;
      }

      case poly_gramParser::CHAR: {
        _localctx = _tracker.createInstance<poly_gramParser::CharContext>(_localctx);
        enterOuterAlt(_localctx, 2);
        setState(57);
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
  enterRule(_localctx, 12, poly_gramParser::RuleCoeff);

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
    setState(60);
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

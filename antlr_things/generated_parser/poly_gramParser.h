
// Generated from poly_gram.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"




class  poly_gramParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, DOUBLE = 7, 
    CHAR = 8, WS = 9, MUL = 10, ADD = 11
  };

  enum {
    RulePolynome = 0, RuleMonome = 1, RuleX_var = 2, RuleY_var = 3, RuleZ_var = 4, 
    RuleDegree = 5, RuleCoeff = 6
  };

  explicit poly_gramParser(antlr4::TokenStream *input);

  poly_gramParser(antlr4::TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options);

  ~poly_gramParser() override;

  std::string getGrammarFileName() const override;

  const antlr4::atn::ATN& getATN() const override;

  const std::vector<std::string>& getRuleNames() const override;

  const antlr4::dfa::Vocabulary& getVocabulary() const override;

  antlr4::atn::SerializedATNView getSerializedATN() const override;


  class PolynomeContext;
  class MonomeContext;
  class X_varContext;
  class Y_varContext;
  class Z_varContext;
  class DegreeContext;
  class CoeffContext; 

  class  PolynomeContext : public antlr4::ParserRuleContext {
  public:
    PolynomeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    PolynomeContext() = default;
    void copyFrom(PolynomeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  SingleMonomePolynomeContext : public PolynomeContext {
  public:
    SingleMonomePolynomeContext(PolynomeContext *ctx);

    MonomeContext *monome();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  SumOfMonomesPolynomeContext : public PolynomeContext {
  public:
    SumOfMonomesPolynomeContext(PolynomeContext *ctx);

    PolynomeContext *polynome();
    antlr4::tree::TerminalNode *ADD();
    MonomeContext *monome();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  PolynomeContext* polynome();
  PolynomeContext* polynome(int precedence);
  class  MonomeContext : public antlr4::ParserRuleContext {
  public:
    MonomeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    MonomeContext() = default;
    void copyFrom(MonomeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ParensMonomeContext : public MonomeContext {
  public:
    ParensMonomeContext(MonomeContext *ctx);

    MonomeContext *monome();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnaryMinusMonomeContext : public MonomeContext {
  public:
    UnaryMinusMonomeContext(MonomeContext *ctx);

    MonomeContext *monome();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FinalMonomeContext : public MonomeContext {
  public:
    FinalMonomeContext(MonomeContext *ctx);

    CoeffContext *coeff();
    std::vector<antlr4::tree::TerminalNode *> MUL();
    antlr4::tree::TerminalNode* MUL(size_t i);
    X_varContext *x_var();
    Y_varContext *y_var();
    Z_varContext *z_var();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  MonomeContext* monome();

  class  X_varContext : public antlr4::ParserRuleContext {
  public:
    X_varContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DegreeContext *degree();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  X_varContext* x_var();

  class  Y_varContext : public antlr4::ParserRuleContext {
  public:
    Y_varContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DegreeContext *degree();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Y_varContext* y_var();

  class  Z_varContext : public antlr4::ParserRuleContext {
  public:
    Z_varContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DegreeContext *degree();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Z_varContext* z_var();

  class  DegreeContext : public antlr4::ParserRuleContext {
  public:
    DegreeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    DegreeContext() = default;
    void copyFrom(DegreeContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  CharContext : public DegreeContext {
  public:
    CharContext(DegreeContext *ctx);

    antlr4::tree::TerminalNode *CHAR();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  UnaryMinusDegreeContext : public DegreeContext {
  public:
    UnaryMinusDegreeContext(DegreeContext *ctx);

    DegreeContext *degree();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  DegreeContext* degree();

  class  CoeffContext : public antlr4::ParserRuleContext {
  public:
    CoeffContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    CoeffContext() = default;
    void copyFrom(CoeffContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  DoubleContext : public CoeffContext {
  public:
    DoubleContext(CoeffContext *ctx);

    antlr4::tree::TerminalNode *DOUBLE();

    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  CoeffContext* coeff();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool polynomeSempred(PolynomeContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};



// Generated from poly_gram.g4 by ANTLR 4.13.2

#pragma once

#include "antlr4-runtime.h"




class  poly_gramParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    COEFF = 8, DEG = 9, WS = 10, MUL = 11, ADD = 12
  };

  enum {
    RulePolynome = 0, RuleMonome = 1, RuleX_var = 2, RuleY_var = 3, RuleZ_var = 4
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

  class  PolynomeContext : public antlr4::ParserRuleContext {
  public:
    PolynomeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MonomeContext *monome();
    PolynomeContext *polynome();
    antlr4::tree::TerminalNode *ADD();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PolynomeContext* polynome();
  PolynomeContext* polynome(int precedence);
  class  MonomeContext : public antlr4::ParserRuleContext {
  public:
    MonomeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    MonomeContext *monome();
    antlr4::tree::TerminalNode *COEFF();
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
    antlr4::tree::TerminalNode *DEG();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  X_varContext* x_var();

  class  Y_varContext : public antlr4::ParserRuleContext {
  public:
    Y_varContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEG();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Y_varContext* y_var();

  class  Z_varContext : public antlr4::ParserRuleContext {
  public:
    Z_varContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *DEG();


    virtual std::any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Z_varContext* z_var();


  bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;

  bool polynomeSempred(PolynomeContext *_localctx, size_t predicateIndex);

  // By default the static state used to implement the parser is lazily initialized during the first
  // call to the constructor. You can call this function if you wish to initialize the static state
  // ahead of time.
  static void initialize();

private:
};


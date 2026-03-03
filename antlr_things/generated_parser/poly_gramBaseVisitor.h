
// Generated from poly_gram.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "poly_gramVisitor.h"


/**
 * This class provides an empty implementation of poly_gramVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  poly_gramBaseVisitor : public poly_gramVisitor {
public:

  virtual std::any visitSingleMonomePolynome(poly_gramParser::SingleMonomePolynomeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitSumOfMonomesPolynome(poly_gramParser::SumOfMonomesPolynomeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryMinusMonome(poly_gramParser::UnaryMinusMonomeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitParensMonome(poly_gramParser::ParensMonomeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFinalMonome(poly_gramParser::FinalMonomeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitX_var(poly_gramParser::X_varContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitY_var(poly_gramParser::Y_varContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitZ_var(poly_gramParser::Z_varContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitUnaryMinusDegree(poly_gramParser::UnaryMinusDegreeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitChar(poly_gramParser::CharContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitDouble(poly_gramParser::DoubleContext *ctx) override {
    return visitChildren(ctx);
  }


};


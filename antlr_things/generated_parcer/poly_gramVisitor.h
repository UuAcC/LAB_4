
// Generated from poly_gram.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "poly_gramParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by poly_gramParser.
 */
class  poly_gramVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by poly_gramParser.
   */
    virtual std::any visitSingleMonomePolynome(poly_gramParser::SingleMonomePolynomeContext *context) = 0;

    virtual std::any visitSumOfMonomesPolynome(poly_gramParser::SumOfMonomesPolynomeContext *context) = 0;

    virtual std::any visitUnaryMinusMonome(poly_gramParser::UnaryMinusMonomeContext *context) = 0;

    virtual std::any visitParensMonome(poly_gramParser::ParensMonomeContext *context) = 0;

    virtual std::any visitFinalMonome(poly_gramParser::FinalMonomeContext *context) = 0;

    virtual std::any visitVariable(poly_gramParser::VariableContext *context) = 0;

    virtual std::any visitUnaryMinusDegree(poly_gramParser::UnaryMinusDegreeContext *context) = 0;

    virtual std::any visitChar(poly_gramParser::CharContext *context) = 0;

    virtual std::any visitDouble(poly_gramParser::DoubleContext *context) = 0;


};



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
    virtual std::any visitPolynome(poly_gramParser::PolynomeContext *context) = 0;

    virtual std::any visitMonome(poly_gramParser::MonomeContext *context) = 0;

    virtual std::any visitX_var(poly_gramParser::X_varContext *context) = 0;

    virtual std::any visitY_var(poly_gramParser::Y_varContext *context) = 0;

    virtual std::any visitZ_var(poly_gramParser::Z_varContext *context) = 0;


};


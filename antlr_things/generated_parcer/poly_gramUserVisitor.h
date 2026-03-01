#pragma once

#include "Polynome.h"
#include "poly_gramBaseVisitor.h"

class UserVisitor : public poly_gramBaseVisitor {
    Polynome result;
public:
    virtual std::any visitUnaryMinusMonome(poly_gramParser::UnaryMinusMonomeContext* ctx) override {
        Monome res = std::any_cast<Monome>(visit(ctx->monome())); 
        return -res;
    }
    virtual std::any visitFinalMonome(poly_gramParser::FinalMonomeContext* ctx) override {
        Monome res = Monome();
        res.set_coefficient(std::any_cast<double>(visit(ctx->coeff())));
        res.set_degree(X, std::any_cast<char>(visit(ctx->variable(0))));
        res.set_degree(Y, std::any_cast<char>(visit(ctx->variable(1))));
        res.set_degree(Z, std::any_cast<char>(visit(ctx->variable(2))));
        return res;
    }
    virtual std::any visitSumOfMonomesPolynome(poly_gramParser::SumOfMonomesPolynomeContext* ctx) override {
        result = std::any_cast<Polynome>(visit(ctx->polynome()));
        result += std::any_cast<Monome>(visit(ctx->monome()));
        return &result;
    }
    virtual std::any visitSingleMonomePolynome(poly_gramParser::SingleMonomePolynomeContext* ctx) override {
        return Polynome(std::any_cast<Monome>(visit(ctx->monome())));
    }
    virtual std::any visitVariable(poly_gramParser::VariableContext* ctx) override {
        return visit(ctx->degree());
    }
    virtual std::any visitUnaryMinusDegree(poly_gramParser::UnaryMinusDegreeContext* ctx) override {
        char res = std::any_cast<char>(visit(ctx->degree()));
        return -res;
    }
    virtual std::any visitChar(poly_gramParser::CharContext* ctx) override {
        return (char)std::stoi(ctx->CHAR()->getText());
    }
    virtual std::any visitDouble(poly_gramParser::DoubleContext* ctx) override {
        return std::stod(ctx->DOUBLE()->getText());
    }
};
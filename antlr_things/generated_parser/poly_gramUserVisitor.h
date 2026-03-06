#pragma once

#include "Polynome.h"
#include "poly_gramBaseVisitor.h"

class UserVisitor : public poly_gramBaseVisitor {
public:
    Polynome result;
    virtual std::any visitUnaryMinusMonome(poly_gramParser::UnaryMinusMonomeContext* ctx) override {
        Monome res = std::any_cast<Monome>(visit(ctx->monome())); 
        return -res;
    }
    virtual std::any visitFinalMonome(poly_gramParser::FinalMonomeContext* ctx) override {
        Monome res = Monome();
        res.set_coefficient(std::any_cast<double>(visit(ctx->coeff())));
        if (ctx->x_var()) {
            int xd = std::any_cast<int>(visit(ctx->x_var()));
            res.set_degree(X, static_cast<char>(xd));
        }
        if (ctx->y_var()) {
            int yd = std::any_cast<int>(visit(ctx->y_var()));
            res.set_degree(Y, static_cast<char>(yd));
        }
        if (ctx->z_var()) {
            int zd = std::any_cast<int>(visit(ctx->z_var()));
            res.set_degree(Z, static_cast<char>(zd));
        }
        return res;
    }
    virtual std::any visitSumOfMonomesPolynome(poly_gramParser::SumOfMonomesPolynomeContext* ctx) override {
        result = std::any_cast<Polynome>(visit(ctx->polynome()));
        result += std::any_cast<Monome>(visit(ctx->monome()));
        return 0;
    }
    virtual std::any visitSingleMonomePolynome(poly_gramParser::SingleMonomePolynomeContext* ctx) override {
        return Polynome(std::any_cast<Monome>(visit(ctx->monome())));
    }
    virtual std::any visitX_var(poly_gramParser::X_varContext* ctx) override {
        return visit(ctx->degree());
    }
    virtual std::any visitY_var(poly_gramParser::Y_varContext* ctx) override {
        return visit(ctx->degree());
    }
    virtual std::any visitZ_var(poly_gramParser::Z_varContext* ctx) override {
        return visit(ctx->degree());
    }
    virtual std::any visitUnaryMinusDegree(poly_gramParser::UnaryMinusDegreeContext* ctx) override {
        int res = std::any_cast<int>(visit(ctx->degree()));
        return -res;
    }
    virtual std::any visitChar(poly_gramParser::CharContext* ctx) override {
        return std::stoi(ctx->CHAR()->getText());
    }
    virtual std::any visitDouble(poly_gramParser::DoubleContext* ctx) override {
        return std::stod(ctx->DOUBLE()->getText());
    }
};
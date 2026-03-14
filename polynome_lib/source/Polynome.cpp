#include <sstream>
#include "antlr4-runtime.h"
#include "poly_gramUserVisitor.h"
#include "poly_gramLexer.h"
#include "poly_gramParser.h"

bool Polynome::monome_check(const Monome& m) const {
    bool flag = true;
    for (int i = 0; i < 3; ++i) {
        char p = m.get_degr().s[i];
        flag &= (p <= DEGR_MAX && p >= DEGR_MIN);
    }
    return flag;
}

Polynome::Polynome(const Monome& mon) : SkipList<Monome>(Monome::MAX()) { this->insert(mon); }

Polynome::Polynome(std::string str) : SkipList<Monome>(Monome::MAX()) {
    std::stringstream stream(str);
    antlr4::ANTLRInputStream input(stream);
    poly_gramLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);
    poly_gramParser parser(&tokens);
    UserVisitor visitor;
    visitor.visit(parser.polynome());
    this->operator=(visitor.result);
}

Polynome& Polynome::operator=(const Polynome& other) {
    if (this != &other) { this->SkipList<Monome>::operator=(other); }
    return *this;
}

Polynome& Polynome::operator=(Polynome&& other) noexcept {
    if (this != &other) { this->SkipList<Monome>::operator=(std::move(other)); }
    return *this;
}

Polynome Polynome::operator+(const Polynome& other) const {
    Polynome res;
    Iterator<Monome> first = this->itr();
    Iterator<Monome> second = other.itr();
    Monome fcurr, scurr;
    bool move_f = true, move_s = true;
    while (first.hasNext() && second.hasNext()) {
        if (move_f) { fcurr = first.next(); move_f = false; }
        if (move_s) { scurr = second.next(); move_s = false; }
        if (fcurr == scurr) {
            Monome to_add = fcurr + scurr;
            if (monome_check(to_add) && to_add.get_coeff() != 0.0) { res.addLast(to_add); }
            move_f = true; move_s = true;
        }
        else {
            if (fcurr > scurr) { if (monome_check(fcurr)) { res.addLast(fcurr); } move_f = true; }
            else { if (monome_check(scurr)) { res.addLast(scurr); } move_s = true; }
        }
    }
    while (first.hasNext() && !move_s) {
        if (move_f) { fcurr = first.next(); move_f = false; }
        if (fcurr == scurr) {
            Monome to_add = fcurr + scurr;
            if (monome_check(to_add) && to_add.get_coeff() != 0.0) { res.addLast(to_add); }
            move_f = true; move_s = true;
        }
        else {
            if (fcurr > scurr) { if (monome_check(fcurr)) { res.addLast(fcurr); } move_f = true; }
            else { if (monome_check(scurr)) { res.addLast(scurr); } move_s = true; }
        }
    } 
    while (first.hasNext()) {
        fcurr = first.next();
        if (monome_check(fcurr)) { res.addLast(fcurr); }
    }
    if (!move_s) {
        if (monome_check(scurr)) { res.addLast(scurr); } move_s = true;
    }
    while (second.hasNext() && !move_f) {
        if (move_s) { scurr = second.next(); move_s = false; }
        if (fcurr == scurr) {
            Monome to_add = fcurr + scurr;
            if (monome_check(to_add) && to_add.get_coeff() != 0.0) { res.addLast(to_add); }
            move_f = true; move_s = true;
        }
        else {
            if (fcurr > scurr) { if (monome_check(fcurr)) { res.addLast(fcurr); } move_f = true; }
            else { if (monome_check(scurr)) { res.addLast(scurr); } move_s = true; }
        }
    } 
    while (second.hasNext()) {
        scurr = second.next();
        if (monome_check(scurr)) { res.addLast(scurr); }
    }
    if (!move_f) {
        if (monome_check(fcurr)) { res.addLast(fcurr); } move_f = true;
    }
    return res;
}

Polynome Polynome::operator-(const Polynome& other) const {
    Polynome res;
    Iterator<Monome> first = this->itr();
    Iterator<Monome> second = other.itr();
    Monome fcurr, scurr;
    bool move_f = true, move_s = true;
    while (first.hasNext() && second.hasNext()) {
        if (move_f) { fcurr = first.next(); move_f = false; }
        if (move_s) { scurr = second.next(); move_s = false; }
        if (fcurr == scurr) {
            Monome to_add = fcurr - scurr;
            if (monome_check(to_add) && to_add.get_coeff() != 0.0) { res.addLast(to_add); }
            move_f = true; move_s = true;
        }
        else {
            if (fcurr > scurr) { if (monome_check(fcurr)) { res.addLast(fcurr); } move_f = true; }
            else { if (monome_check(scurr)) { res.addLast(-scurr); } move_s = true; }
        }
    }
    while (first.hasNext() && !move_s) {
        if (move_f) { fcurr = first.next(); move_f = false; }
        if (fcurr == scurr) {
            Monome to_add = fcurr - scurr;
            if (monome_check(to_add) && to_add.get_coeff() != 0.0) { res.addLast(to_add); }
            move_f = true; move_s = true;
        }
        else {
            if (fcurr > scurr) { if (monome_check(fcurr)) { res.addLast(fcurr); } move_f = true; }
            else { if (monome_check(scurr)) { res.addLast(-scurr); } move_s = true; }
        }
    } 
    while (first.hasNext()) {
        fcurr = first.next();
        if (monome_check(fcurr)) { res.addLast(fcurr); }
    } 
    if (!move_s) { 
        if (monome_check(scurr)) { res.addLast(-scurr); } move_s = true; 
    }
    while (second.hasNext() && !move_f) {
        if (move_s) { scurr = second.next(); move_s = false; }
        if (fcurr == scurr) {
            Monome to_add = fcurr - scurr;
            if (monome_check(to_add) && to_add.get_coeff() != 0.0) { res.addLast(to_add); }
            move_f = true; move_s = true;
        }
        else {
            if (fcurr > scurr) { if (monome_check(fcurr)) { res.addLast(fcurr); } move_f = true; }
            else { if (monome_check(scurr)) { res.addLast(-scurr); } move_s = true; }
        }
    } 
    while (second.hasNext()) {
        scurr = second.next();
        if (monome_check(scurr)) { res.addLast(-scurr); }
    }
    if (!move_f) {
        if (monome_check(fcurr)) { res.addLast(fcurr); } move_f = true;
    }
    return res;
}

Polynome Polynome::operator*(const Polynome& other) const {
    Polynome res, temp;
    Iterator<Monome> first = this->itr();
    while (first.hasNext()) {
        Monome fcurr = first.next();
        Iterator<Monome> second = other.itr();
        while (second.hasNext()) {
            Monome curr = fcurr * second.next();
            if (monome_check(curr))
                temp.addLast(curr);
        }
        res += temp;
        temp.clear();
    }
    return res;
}

Polynome& Polynome::operator+=(const Polynome& other) {
    this->operator=(*this + other);
    return *this;
}

Polynome& Polynome::operator-=(const Polynome& other) {
    this->operator=(*this - other);
    return *this;
}

Polynome& Polynome::operator*=(const Polynome& other) {
    this->operator=(*this * other);
    return *this;
}

Polynome Polynome::operator+(const Monome& mon) {
    Polynome res;
    res.addLast(mon);
    res += *this;
    return res;
}
Polynome Polynome::operator-(const Monome& mon) {
    Polynome res;
    res.addLast(-mon);
    res += *this;
    return res;
}
Polynome Polynome::operator*(const Monome& mon) {
    Polynome res;
    Iterator<Monome> iter = this->itr();
    while (iter.hasNext()) {
        Monome curr = mon * iter.next();
        if (monome_check(curr))
            res.addLast(curr);
    }
    return res;
}
Polynome Polynome::operator/(const Monome& mon) {
    Polynome res;
    Iterator<Monome> iter = this->itr();
    while (iter.hasNext()) {
        Monome curr = iter.next() / mon;
        if (monome_check(curr))
            res.addLast(curr);
    }
    return res;
}

Polynome& Polynome::operator+=(const Monome& mon) {
    Polynome res;
    res.addLast(mon);
    this->operator+=(res);
    return *this;
}
Polynome& Polynome::operator-=(const Monome& mon) {
    Polynome res;
    res.addLast(mon);
    this->operator-=(res);
    return *this;
}
Polynome& Polynome::Polynome::operator*=(const Monome& mon) {
    Polynome res;
    Iterator<Monome> iter = this->itr();
    while (iter.hasNext()) {
        Monome curr = mon * iter.next();
        if (monome_check(curr))
            res.addLast(curr);
    }
    this->operator=(res);
    return *this;
}
Polynome& Polynome::operator/=(const Monome& mon) {
    Polynome res;
    Iterator<Monome> iter = this->itr();
    while (iter.hasNext()) {
        Monome curr = iter.next() / mon;
        if (monome_check(curr))
            res.addLast(curr);
    }
    this->operator=(res);
    return *this;
}

double Polynome::calculate(double x, double y, double z) const {
    Iterator<Monome> iter = this->itr();
    double res = 0.0; Monome curr;
    while (iter.hasNext()) {
        curr = iter.next();
        res += curr.value_in_point(x, y, z);
    }
    return res;
}

ostream& operator<<(ostream& ostr, const Polynome& to_out) {
    Iterator<Monome> iter = to_out.itr();
    if (iter.hasNext()) { ostr << iter.next(); }
    while (iter.hasNext()) { ostr << " + " << iter.next(); }
    return ostr;
}

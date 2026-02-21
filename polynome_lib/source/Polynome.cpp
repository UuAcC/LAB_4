#include "Polynome.h"

bool Polynome::monome_check(const Monome& m) const {
    bool flag = true;
    for (int i = 0; i < 3; ++i) {
        char p = m.get_degr().s[i];
        flag &= (p <= DEGR_MAX && p >= DEGR_MIN);
    }
    return flag;
}

Polynome Polynome::operator+(const Polynome& other) const {
    Polynome res;
    Iterator<Monome> first = this->itr();
    Iterator<Monome> second = other.itr();
    Monome fcurr, scurr;
    if (first.hasNext()) { fcurr = first.next(); }
    if (second.hasNext()) { scurr = second.next(); }
    while (first.hasNext() && second.hasNext()) {
        double fc = fcurr.get_coeff(), sc = scurr.get_coeff();
        degrees fd = fcurr.get_degr(), sd = scurr.get_degr();
        if (fcurr.is_similar_to(scurr)) {
            res.addLast(Monome(fc + sc, fd)); fcurr = first.next(); scurr = second.next();
        }
        else {
            if (fd.N > sd.N) { res.addLast(fcurr); fcurr = first.next(); }
            else { res.addLast(scurr); scurr = second.next(); }
        }
    }
    while (first.hasNext()) { res.addLast(fcurr); fcurr = first.next(); }
    while (second.hasNext()) { res.addLast(scurr); scurr = second.next(); }
    return res;
}

Polynome Polynome::operator-(const Polynome& other) const {
    Polynome res;
    Iterator<Monome> first = this->itr();
    Iterator<Monome> second = other.itr();
    Monome fcurr, scurr;
    if (first.hasNext()) { fcurr = first.next(); }
    if (second.hasNext()) { scurr = second.next(); }
    while (first.hasNext() && second.hasNext()) {
        double fc = fcurr.get_coeff(), sc = scurr.get_coeff();
        degrees fd = fcurr.get_degr(), sd = scurr.get_degr();
        if (fcurr.is_similar_to(scurr)) {
            res.addLast(Monome(fc - sc, fd)); fcurr = first.next(); scurr = second.next();
        }
        else {
            if (fd.N > sd.N) { res.addLast(fcurr); fcurr = first.next(); }
            else { res.addLast(-scurr); scurr = second.next(); }
        }
    }
    while (first.hasNext()) { res.addLast(fcurr); fcurr = first.next(); }
    while (second.hasNext()) { res.addLast(-scurr); scurr = second.next(); }
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
    Polynome res;
    Iterator<Monome> first = this->itr();
    Iterator<Monome> second = other.itr();
    Monome fcurr, scurr;
    if (first.hasNext()) { fcurr = first.next(); }
    if (second.hasNext()) { scurr = second.next(); }
    while (first.hasNext() && second.hasNext()) {
        double fc = fcurr.get_coeff(), sc = scurr.get_coeff();
        degrees fd = fcurr.get_degr(), sd = scurr.get_degr();
        if (fcurr.is_similar_to(scurr)) {
            res.addLast(Monome(fc + sc, fd)); fcurr = first.next(); scurr = second.next();
        }
        else {
            if (fd.N > sd.N) { res.addLast(fcurr); fcurr = first.next(); }
            else { res.addLast(scurr); scurr = second.next(); }
        }
    }
    while (first.hasNext()) { res.addLast(fcurr); fcurr = first.next(); }
    while (second.hasNext()) { res.addLast(scurr); scurr = second.next(); }
    this->operator=(res);
    return *this;
}

Polynome& Polynome::operator-=(const Polynome& other) {
    Polynome res;
    Iterator<Monome> first = this->itr();
    Iterator<Monome> second = other.itr();
    Monome fcurr, scurr;
    if (first.hasNext()) { fcurr = first.next(); }
    if (second.hasNext()) { scurr = second.next(); }
    while (first.hasNext() && second.hasNext()) {
        double fc = fcurr.get_coeff(), sc = scurr.get_coeff();
        degrees fd = fcurr.get_degr(), sd = scurr.get_degr();
        if (fcurr.is_similar_to(scurr)) {
            res.addLast(Monome(fc - sc, fd)); fcurr = first.next(); scurr = second.next();
        }
        else {
            if (fd.N > sd.N) { res.addLast(fcurr); fcurr = first.next(); }
            else { res.addLast(-scurr); scurr = second.next(); }
        }
    }
    while (first.hasNext()) { res.addLast(fcurr); fcurr = first.next(); }
    while (second.hasNext()) { res.addLast(-scurr); scurr = second.next(); }
    this->operator=(res);
    return *this;
}

Polynome& Polynome::operator*=(const Polynome& other) {
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
    this->operator=(res);
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
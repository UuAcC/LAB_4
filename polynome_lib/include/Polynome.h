#pragma once

#include "HList.h"
#include "Monome.h"

class Polynome : private HList<Monome> {
	using HList<Monome>::head;
	using HList<Monome>::last;
	bool monome_check(const Monome& m) const;
public:
	Polynome operator+(const Polynome& other) const;
	Polynome operator-(const Polynome& other) const;
	Polynome operator*(const Polynome& other) const;

	Polynome& operator+=(const Polynome& other);
	Polynome& operator-=(const Polynome& other);
	Polynome& operator*=(const Polynome& other);

	Polynome operator+(const Monome& mon);
	Polynome operator-(const Monome& mon);
	Polynome operator*(const Monome& mon);
	Polynome operator/(const Monome& mon);

	Polynome& operator+=(const Monome& mon);
	Polynome& operator-=(const Monome& mon);
	Polynome& operator*=(const Monome& mon);
	Polynome& operator/=(const Monome& mon);

	double calculate(double x, double y, double z) const;
};
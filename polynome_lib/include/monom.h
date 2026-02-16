#pragma once
#include <limits>
#include <iostream>
using namespace std;

enum variables { X, Y, Z };

class Monom {
	double coeff;
	int degr_int;
public:
	Monom(double c = 1, int d = 0) : coeff(c), degr_int(d) {}
	Monom operator+(const Monom& other);
	Monom operator-(const Monom& other);
	Monom operator*(const Monom& other);
	Monom operator/(const Monom& other);
	inline void set_coefficient(double c) { this->coeff = c; }
	inline void set_deg(variables var, char d) { char* deg = (char*)&this->degr_int; deg[var] = d; }
	friend ostream& operator<<(ostream& ostr, const Monom& to_out);
};
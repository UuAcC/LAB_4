#pragma once
#include <limits>
#include <iostream>
using namespace std;

enum variables { X, Y, Z };

class Monome {
	double coeff;
	int degr_int;
public:
	Monome(double c = 1, int d = 0) : coeff(c), degr_int(d) {}

	Monome& operator+(const Monome& other);
	Monome& operator-(const Monome& other);
	Monome& operator*(const Monome& other);
	Monome& operator/(const Monome& other);
	

	Monome& operator+=(const Monome& other);
	Monome& operator-=(const Monome& other);
	Monome& operator*=(const Monome& other);
	Monome& operator/=(const Monome& other);



	inline void set_coefficient(double c) { this->coeff = c; }
	inline void set_deg(variables var, char d) { char* deg = (char*)&this->degr_int; deg[var] = d; }

	friend ostream& operator<<(ostream& ostr, const Monome& to_out);
};
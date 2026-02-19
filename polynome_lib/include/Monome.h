#pragma once
#include <limits>
#include <iostream>
using namespace std;

#define DEGR_MAX 10
#define DEGR_MIN -5

enum variables { X, Y, Z };


// одна и та же память интерпретируется по-разному
union degrees { 
	unsigned N; 
	char s[4]; 
public:
	degrees() : N(0) {}
	degrees(int v) : N(v) {}
};

class Monome {
	double coeff;
	degrees degr;
public:
	Monome(double c = 1, int d = 0) : coeff(c), degr(d) {}
	Monome(double c = 1, degrees d) : coeff(c), degr(d) {}

	// class is triviable copyable, do we really need cope and move constructors?
	// класс тривиально копируемый, реально надо конструктор копирования и присваивания?

	Monome operator+(const Monome& other) const;
	Monome operator-(const Monome& other) const;
	Monome operator*(const Monome& other) const;
	Monome operator/(const Monome& other) const;
	Monome operator*(double c) const;
	Monome operator/(double c) const;

	Monome& operator+=(const Monome& other);
	Monome& operator-=(const Monome& other);
	Monome& operator*=(const Monome& other);
	Monome& operator/=(const Monome& other);
	Monome& operator*=(double c);
	Monome& operator/=(double c);

	Monome operator-() const;

	int is_similar_to(const Monome& other) const;
	int operator==(const Monome& other) const;
	int operator!=(const Monome& other) const;

	inline void set_coefficient(double c) { this->coeff = c; }
	inline void set_degree(variables var, char d) { char* deg = (char*)&this->degr; deg[var] = d; }

	double value_in_point(double x, double y, double z) const;

	friend ostream& operator<<(ostream& ostr, const Monome& to_out);
	friend istream& operator>>(istream& istr, Monome& to_in);
};
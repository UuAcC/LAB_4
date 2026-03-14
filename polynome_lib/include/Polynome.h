#pragma once

#include "SkipList.h"
#include "Monome.h"
#include <string>

#define DEGR_MAX 10
#define DEGR_MIN -5

bool SkipList<Monome>::SkipListRandomInitialized = false;

class Polynome : private SkipList<Monome> {
	using SkipList<Monome>::head;
	bool monome_check(const Monome& m) const;
public:
	Polynome() : SkipList<Monome>(Monome::MAX()) {}
	Polynome(const Monome& mon);
	Polynome(std::string str);

	Polynome(const Polynome& other) : SkipList<Monome>(other) {}
	Polynome& operator=(const Polynome& other);

	Polynome(Polynome&& other) noexcept : SkipList<Monome>(std::move(other)) {}
	Polynome& operator=(Polynome&& other) noexcept;

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

	friend ostream& operator<<(ostream& ostr, const Polynome& to_out);
};
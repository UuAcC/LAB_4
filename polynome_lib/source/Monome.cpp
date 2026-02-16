#include "Monome.h"
#include <cmath>

// ----------------< regular operators >-----------------------------------------------------------

Monome Monome::operator+(const Monome& other) const {
	if (this->degr_int != other.degr_int) throw - 1;
	double sum = this->coeff + other.coeff;
	if (sum < 0 && this->coeff > 0 && other.coeff > 0) { sum = std::numeric_limits<double>::max(); }
	if (sum > 0 && this->coeff < 0 && other.coeff < 0) { sum = std::numeric_limits<double>::min(); }
	return Monome(sum, this->degr_int);
}
Monome Monome::operator-(const Monome& other) const {
	if (this->degr_int != other.degr_int) throw - 1;
	double dif = this->coeff - other.coeff;
	if (dif < 0 && this->coeff > 0 && other.coeff < 0) { dif = std::numeric_limits<double>::max(); }
	if (dif > 0 && this->coeff < 0 && other.coeff > 0) { dif = std::numeric_limits<double>::min(); }
	return Monome(dif, this->degr_int);
}
Monome Monome::operator*(const Monome& other) const {
	double mul = this->coeff * other.coeff;
	if (mul < 0 && ((this->coeff > 0 && other.coeff > 0) || (this->coeff < 0 && other.coeff < 0))) {
		mul = std::numeric_limits<double>::max(); 
	}
	if (mul > 0 && ((this->coeff < 0 && other.coeff > 0) || (this->coeff > 0 && other.coeff < 0))) {
		mul = std::numeric_limits<double>::min();
	}
	Monome res(mul, this->degr_int);
	char* r_degrees = (char*)(&res.degr_int);
	char* o_degrees = (char*)(&other.degr_int);
	for (int i = 0; i < 3; ++i) {
		char r_d_i = r_degrees[i], o_d_i = o_degrees[i];
		char sum = r_d_i + o_d_i;
		if (sum < 0 && r_d_i > 0 && o_d_i > 0) { r_degrees[i] = CHAR_MAX; continue; }
		if (sum > 0 && r_d_i < 0 && o_d_i < 0) { r_degrees[i] = CHAR_MIN; continue; }
		r_degrees[i] = sum;
	}
	return res;
}
Monome Monome::operator/(const Monome& other) const {
	double div = this->coeff / other.coeff;
	if (div < 0 && ((this->coeff > 0 && other.coeff > 0) || (this->coeff < 0 && other.coeff < 0))) {
		div = std::numeric_limits<double>::max();
	}
	if (div > 0 && ((this->coeff < 0 && other.coeff > 0) || (this->coeff > 0 && other.coeff < 0))) {
		div = std::numeric_limits<double>::min();
	}
	Monome res(div, this->degr_int);
	char* r_degrees = (char*)(&res.degr_int);
	char* o_degrees = (char*)(&other.degr_int);
	for (int i = 0; i < 3; ++i) {
		char r_d_i = r_degrees[i], o_d_i = o_degrees[i];
		char dif = r_d_i - o_d_i;
		if (dif < 0 && r_d_i > 0 && o_d_i < 0) { r_degrees[i] = CHAR_MAX; continue; }
		if (dif > 0 && r_d_i < 0 && o_d_i > 0) { r_degrees[i] = CHAR_MIN; continue; }
		r_degrees[i] = dif;
	}
	return res;
}
Monome Monome::operator*(double c) const {
	double mul = this->coeff * c;
	if (mul < 0 && ((this->coeff > 0 && c > 0) || (this->coeff < 0 && c < 0))) {
		mul = std::numeric_limits<double>::max();
	}
	if (mul > 0 && ((this->coeff < 0 && c > 0) || (this->coeff > 0 && c < 0))) {
		mul = std::numeric_limits<double>::min();
	}
	return Monome(mul, this->degr_int);
}
Monome Monome::operator/(double c) const {
	double div = this->coeff / c;
	if (div < 0 && ((this->coeff > 0 && c > 0) || (this->coeff < 0 && c < 0))) {
		div = std::numeric_limits<double>::max();
	}
	if (div > 0 && ((this->coeff < 0 && c > 0) || (this->coeff > 0 && c < 0))) {
		div = std::numeric_limits<double>::min();
	}
	return Monome(div, this->degr_int);
}

// ------------------------------------------------------------------------------------------------

// ----------------< smth= operators >-------------------------------------------------------------

Monome& Monome::operator+=(const Monome& other) {
	if (this->degr_int != other.degr_int) throw - 1;
	double sum = this->coeff + other.coeff;
	if (sum < 0 && this->coeff > 0 && other.coeff > 0) { sum = std::numeric_limits<double>::max(); }
	if (sum > 0 && this->coeff < 0 && other.coeff < 0) { sum = std::numeric_limits<double>::min(); }
	this->coeff = sum;
	return *this;
}
Monome& Monome::operator-=(const Monome& other) {
	if (this->degr_int != other.degr_int) throw - 1;
	double dif = this->coeff - other.coeff;
	if (dif < 0 && this->coeff > 0 && other.coeff < 0) { dif = std::numeric_limits<double>::max(); }
	if (dif > 0 && this->coeff < 0 && other.coeff > 0) { dif = std::numeric_limits<double>::min(); }
	this->coeff = dif;
	return *this;
}
Monome& Monome::operator*=(const Monome& other) {
	double mul = this->coeff * other.coeff;
	if (mul < 0 && ((this->coeff > 0 && other.coeff > 0) || (this->coeff < 0 && other.coeff < 0))) {
		mul = std::numeric_limits<double>::max();
	}
	if (mul > 0 && ((this->coeff < 0 && other.coeff > 0) || (this->coeff > 0 && other.coeff < 0))) {
		mul = std::numeric_limits<double>::min();
	}
	this->coeff = mul;
	char* r_degrees = (char*)(&this->degr_int);
	char* o_degrees = (char*)(&other.degr_int);
	for (int i = 0; i < 3; ++i) {
		char r_d_i = r_degrees[i], o_d_i = o_degrees[i];
		char sum = r_d_i + o_d_i;
		if (sum < 0 && r_d_i > 0 && o_d_i > 0) { r_degrees[i] = CHAR_MAX; continue; }
		if (sum > 0 && r_d_i < 0 && o_d_i < 0) { r_degrees[i] = CHAR_MIN; continue; }
		r_degrees[i] = sum;
	}
	return *this;
}
Monome& Monome::operator/=(const Monome& other) {
	double div = this->coeff / other.coeff;
	if (div < 0 && ((this->coeff > 0 && other.coeff > 0) || (this->coeff < 0 && other.coeff < 0))) {
		div = std::numeric_limits<double>::max();
	}
	if (div > 0 && ((this->coeff < 0 && other.coeff > 0) || (this->coeff > 0 && other.coeff < 0))) {
		div = std::numeric_limits<double>::min();
	}
	this->coeff = div;
	char* r_degrees = (char*)(&this->degr_int);
	char* o_degrees = (char*)(&other.degr_int);
	for (int i = 0; i < 3; ++i) {
		char r_d_i = r_degrees[i], o_d_i = o_degrees[i];
		char dif = r_d_i - o_d_i;
		if (dif < 0 && r_d_i > 0 && o_d_i < 0) { r_degrees[i] = CHAR_MAX; continue; }
		if (dif > 0 && r_d_i < 0 && o_d_i > 0) { r_degrees[i] = CHAR_MIN; continue; }
		r_degrees[i] = dif;
	}
	return *this;
}
Monome& Monome::operator*=(double c){
	double mul = this->coeff * c;
	if (mul < 0 && ((this->coeff > 0 && c > 0) || (this->coeff < 0 && c < 0))) {
		mul = std::numeric_limits<double>::max();
	}
	if (mul > 0 && ((this->coeff < 0 && c > 0) || (this->coeff > 0 && c < 0))) {
		mul = std::numeric_limits<double>::min();
	} 
	this->coeff = mul;
	return *this;
}
Monome& Monome::operator/=(double c){
	double div = this->coeff / c;
	if (div < 0 && ((this->coeff > 0 && c > 0) || (this->coeff < 0 && c < 0))) {
		div = std::numeric_limits<double>::max();
	}
	if (div > 0 && ((this->coeff < 0 && c > 0) || (this->coeff > 0 && c < 0))) {
		div = std::numeric_limits<double>::min();
	} 
	this->coeff = div;
	return *this;
}

// ------------------------------------------------------------------------------------------------

// ----------------< Unary operator- >-------------------------------------------------------------

Monome Monome::operator-() const {
	return Monome(-this->coeff, this->degr_int);
}

// ------------------------------------------------------------------------------------------------

// ----------------< Comparators >-----------------------------------------------------------------

int Monome::is_similar_to(const Monome& other) const {
	return this->degr_int == other.degr_int;
}
int Monome::operator==(const Monome& other) const {
	if (this->is_similar_to(other)) {
		return this->coeff == other.coeff;
	} return 0;
}
int Monome::operator!=(const Monome& other) const {
	return !(this->operator==(other));
}

// ------------------------------------------------------------------------------------------------

// --------< Calculating value in point >----------------------------------------------------------

int sign(double x) { return (x > 0) ? 1 : ((x < 0) ? -1 : 0); }

double Monome::value_in_point(double x, double y, double z) const {
	char* degrees = (char*)(&this->degr_int);
	double res = this->coeff * pow(x, degrees[0]) * pow(y, degrees[1]) * pow(z, degrees[2]);
	double _sign = sign(this->coeff) * sign(x) * sign(y) * sign(z);
	if (_sign > 0 && res < 0) { res = numeric_limits<double>::max(); }
	if (_sign < 0 && res > 0) { res = numeric_limits<double>::min(); }
	return res;
}

// ------------------------------------------------------------------------------------------------

// ----------------< I/O Stream >------------------------------------------------------------------

ostream& operator<<(ostream& ostr, const Monome& to_out) {
	ostr << to_out.coeff;
	char* degrees = (char*)(&to_out.degr_int);
	ostr << " * x^" << degrees[0] << " * y^" << degrees[1] << " * z^" << degrees[2];
	return ostr;
}

istream& operator>>(istream& istr, Monome& to_in) {
	istr >> to_in.coeff; int in_deg_int = 0;
	char* degrees = (char*)(&in_deg_int);
	for (int i = 0; i < 3; ++i) { istr >> degrees[i]; }
	to_in.degr_int = in_deg_int;
	return istr;
}

// ------------------------------------------------------------------------------------------------

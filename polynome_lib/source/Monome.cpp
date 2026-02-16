#include "Monome.h"

Monome& Monome::operator+(const Monome& other) {
	if (this->degr_int != other.degr_int) throw - 1;
	double sum = this->coeff + other.coeff;
	if (sum < 0 && this->coeff > 0 && other.coeff > 0) { sum = std::numeric_limits<double>::max(); }
	if (sum > 0 && this->coeff < 0 && other.coeff < 0) { sum = std::numeric_limits<double>::min(); }
	return Monome(sum, this->degr_int);
}
Monome& Monome::operator-(const Monome& other) {
	if (this->degr_int != other.degr_int) throw - 1;
	double dif = this->coeff - other.coeff;
	if (dif < 0 && this->coeff > 0 && other.coeff < 0) { dif = std::numeric_limits<double>::max(); }
	if (dif > 0 && this->coeff < 0 && other.coeff > 0) { dif = std::numeric_limits<double>::min(); }
	return Monome(dif, this->degr_int);
}
Monome& Monome::operator*(const Monome& other) {
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
Monome& Monome::operator/(const Monome& other) {
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
ostream& operator<<(ostream& ostr, const Monome& to_out) {
	ostr << to_out.coeff;
	char* degrees = (char*)(&to_out.degr_int);
	ostr << " * x^" << degrees[0] << " * y^" << degrees[1] << " * z^" << degrees[2];
	return ostr;
}
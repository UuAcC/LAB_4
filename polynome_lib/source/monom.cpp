#include "monom.h"

Monom Monom::operator+(const Monom& other) {
	if (this->degr_int != other.degr_int) throw - 1;
	double sum = this->coeff + other.coeff;
	if (sum < 0 && this->coeff > 0 && other.coeff > 0) { sum = std::numeric_limits<double>::max(); }
	if (sum > 0 && this->coeff < 0 && other.coeff < 0) { sum = std::numeric_limits<double>::min(); }
	return Monom(sum, this->degr_int);
}
Monom Monom::operator-(const Monom& other) {
	if (this->degr_int != other.degr_int) throw - 1;
	double dif = this->coeff - other.coeff;
	if (dif < 0 && this->coeff > 0 && other.coeff < 0) { dif = std::numeric_limits<double>::max(); }
	if (dif > 0 && this->coeff < 0 && other.coeff > 0) { dif = std::numeric_limits<double>::min(); }
	return Monom(dif, this->degr_int);
}
Monom Monom::operator*(const Monom& other) {
	Monom res(this->coeff * other.coeff, this->degr_int);
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
Monom Monom::operator/(const Monom& other) {
	Monom res(this->coeff * other.coeff, this->degr_int);
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
ostream& operator<<(ostream& ostr, const Monom& to_out) {
	ostr << to_out.coeff;
	char* degrees = (char*)(&to_out.degr_int);
	ostr << " * x^" << degrees[0] << " * y^" << degrees[1] << " * z^" << degrees[2];
	return ostr;
}
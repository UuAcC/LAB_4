#include "Monome.h"
#include <cmath>

// ----------------< min & max values >------------------------------------------------------------

const Monome Monome::MIN() {
	Monome res;
	res.coeff = numeric_limits<double>::min();
	res.degr.N = numeric_limits<unsigned>::min();
	return res;
}
const Monome Monome::MAX() {
	Monome res;
	res.coeff = numeric_limits<double>::max();
	res.degr.N = numeric_limits<unsigned>::max();
	return res;
}

// ------------------------------------------------------------------------------------------------

// ----------------< regular operators >-----------------------------------------------------------

Monome Monome::operator+(const Monome& other) const {
	if (*this != other) throw - 1;
	double sum = this->coeff + other.coeff;
	if (sum < 0 && this->coeff > 0 && other.coeff > 0) { sum = std::numeric_limits<double>::max(); }
	if (sum > 0 && this->coeff < 0 && other.coeff < 0) { sum = std::numeric_limits<double>::min(); }
	return Monome(sum, this->degr);
}
Monome Monome::operator-(const Monome& other) const {
	if (*this != other) throw - 1;
	double dif = this->coeff - other.coeff;
	if (dif < 0 && this->coeff > 0 && other.coeff < 0) { dif = std::numeric_limits<double>::max(); }
	if (dif > 0 && this->coeff < 0 && other.coeff > 0) { dif = std::numeric_limits<double>::min(); }
	return Monome(dif, this->degr);
}
Monome Monome::operator*(const Monome& other) const {
	double mul = this->coeff * other.coeff;
	if (mul < 0 && ((this->coeff > 0 && other.coeff > 0) || (this->coeff < 0 && other.coeff < 0))) {
		mul = std::numeric_limits<double>::max(); 
	}
	if (mul > 0 && ((this->coeff < 0 && other.coeff > 0) || (this->coeff > 0 && other.coeff < 0))) {
		mul = std::numeric_limits<double>::min();
	}
	Monome res(mul, this->degr);
	for (int i = 0; i < 3; ++i) {
		char r_d_i = res.degr.s[i], o_d_i = other.degr.s[i];
		char sum = r_d_i + o_d_i;
		//if (sum > DEGR_MAX) { res.degr.s[i] = DEGR_MAX; continue; }
		//if (sum < DEGR_MIN) { res.degr.s[i] = DEGR_MIN; continue; }
		res.degr.s[i] = sum;
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
	Monome res(div, this->degr);
	for (int i = 0; i < 3; ++i) {
		char r_d_i = res.degr.s[i], o_d_i = other.degr.s[i];
		char dif = r_d_i - o_d_i;
		//if (dif > DEGR_MAX) { res.degr.s[i] = DEGR_MAX; continue; }
		//if (dif < DEGR_MIN) { res.degr.s[i] = DEGR_MIN; continue; }
		res.degr.s[i] = dif;
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
	return Monome(mul, this->degr);
}
Monome Monome::operator/(double c) const {
	double div = this->coeff / c;
	if (div < 0 && ((this->coeff > 0 && c > 0) || (this->coeff < 0 && c < 0))) {
		div = std::numeric_limits<double>::max();
	}
	if (div > 0 && ((this->coeff < 0 && c > 0) || (this->coeff > 0 && c < 0))) {
		div = std::numeric_limits<double>::min();
	}
	return Monome(div, this->degr);
}

// ------------------------------------------------------------------------------------------------

// ----------------< smth= operators >-------------------------------------------------------------

Monome& Monome::operator+=(const Monome& other) {
	if (*this != other) throw - 1;
	double sum = this->coeff + other.coeff;
	if (sum < 0 && this->coeff > 0 && other.coeff > 0) { sum = std::numeric_limits<double>::max(); }
	if (sum > 0 && this->coeff < 0 && other.coeff < 0) { sum = std::numeric_limits<double>::min(); }
	this->coeff = sum;
	return *this;
}
Monome& Monome::operator-=(const Monome& other) {
	if (*this != other) throw - 1;
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
	for (int i = 0; i < 3; ++i) {
		char r_d_i = this->degr.s[i], o_d_i = other.degr.s[i];
		char sum = r_d_i + o_d_i;
		//if (sum > DEGR_MAX) { this->degr.s[i] = DEGR_MAX; continue; }
		//if (sum < DEGR_MIN) { this->degr.s[i] = DEGR_MIN; continue; } можно швырнуть исключение
		this->degr.s[i] = sum;
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
	for (int i = 0; i < 3; ++i) {
		char r_d_i = this->degr.s[i], o_d_i = other.degr.s[i];
		char dif = r_d_i - o_d_i;
		//if (dif > DEGR_MAX) { this->degr.s[i] = DEGR_MAX; continue; }
		//if (dif < DEGR_MIN) { this->degr.s[i] = DEGR_MIN; continue; }
		this->degr.s[i] = dif;
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
	return Monome(-this->coeff, this->degr);
}

// ------------------------------------------------------------------------------------------------

// ----------------< Comparators >-----------------------------------------------------------------

bool Monome::fully_equals(const Monome& other) const {
	if (*this == other) {
		return this->coeff == other.coeff;
	} return false;
}
bool Monome::operator==(const Monome& other) const {
	return this->degr.N == other.degr.N;
}
bool Monome::operator!=(const Monome& other) const {
	return !(this->operator==(other));
}
bool Monome::operator<(const Monome& other) const {
	return this->degr.N < other.degr.N;
}
bool Monome::operator<=(const Monome& other) const {
	return this->degr.N <= other.degr.N;
}
bool Monome::operator>(const Monome& other) const {
	return this->degr.N > other.degr.N;
}
bool Monome::operator>=(const Monome& other) const {
	return this->degr.N >= other.degr.N;
}

// ------------------------------------------------------------------------------------------------

// ----------------< Calculating value in point >--------------------------------------------------

static int sign(double x) { return (x > 0) ? 1 : ((x < 0) ? -1 : 0); }

double Monome::value_in_point(double x, double y, double z) const {
	double xr = pow(x, this->degr.s[X]);
	double yr = pow(y, this->degr.s[Y]);
	double zr = pow(z, this->degr.s[Z]);

	double res = this->coeff * xr * yr * zr;
	double _sign = sign(this->coeff) * sign(xr) * sign(yr) * sign(zr);
	if (_sign > 0 && res < 0) { res = numeric_limits<double>::max(); }
	if (_sign < 0 && res > 0) { res = numeric_limits<double>::min(); }
	return res;
}

// ------------------------------------------------------------------------------------------------

// ----------------< I/O Stream >------------------------------------------------------------------

ostream& operator<<(ostream& ostr, const Monome& to_out) {
	ostr << to_out.coeff;
	ostr << " * x^" << static_cast<int>(to_out.degr.s[X])
		<< " * y^" << static_cast<int>(to_out.degr.s[Y])
		<< " * z^" << static_cast<int>(to_out.degr.s[Z]);
	return ostr;
}

istream& operator>>(istream& istr, Monome& to_in) {
	istr >> to_in.coeff; degrees in_deg = 0;

	for (int i = 0; i < 3; ++i) { istr >> in_deg.s[i]; }
	to_in.degr = in_deg;
	return istr;
}

// ------------------------------------------------------------------------------------------------

/// 
/// int main() {
///		unsigned N = 0; 
/// 
///		int i1 = 10;
///		int i2 = 5;
/// 
///		N |= i1;
///		N |= i2 << 4;
/// 
///		int m = 15;
/// 
///		int i1s = N & m;
///		int i2s = N >> 4 & m;
/// }
/// 
/// 
/// под звездочкой: можно попробовать списки с пропуском КОТОРЫЕ ХОДИМ НА ПОЛОВИНКУ, НА ЧЕТВЕРТИНКУ И ТД
/// 
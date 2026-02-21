#include <iostream>
#include "Polynome.h"

int main() {
	degrees deg = 0, odeg = 0;
	deg.s[X] = 5; odeg.s[Y] = 10;
	std::cout << (deg.N > odeg.N);

	return 0;
}

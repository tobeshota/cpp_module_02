#include <iostream>

// Fixed::Fixed(const int value) {
//     std::cout << "Int constructor called" << std::endl;
//     _fixedPointValue = value << _fractionalBits;
// }
int main(void)
{
	int value = 1;
	int _fractionalBits = 1;
	int _fixedPointValue = value << _fractionalBits;
	std::cout << _fixedPointValue << std::endl;
}

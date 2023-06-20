#include "Fixed.hpp"

// int main( void ) {
// Fixed a;
// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// std::cout << a << std::endl;
// std::cout << ++a << std::endl;
// std::cout << a << std::endl;
// std::cout << a++ << std::endl;
// std::cout << a << std::endl;
// std::cout << b << std::endl;
// std::cout << Fixed::max( a, b ) << std::endl;
// return 0;
// }

int main(void)
{
	Fixed a(42);
	Fixed b(55);
	Fixed c;

	std::cout << a << " " << b << " " << c << std::endl;
	std::cout << (c = a + b) << " " << (b + c) << " " << c << std::endl;
	std::cout << a << " " << b << " " << c << std::endl;
	std::cout << (a*Fixed(2.45f)) << " " << (b/Fixed(0)) << " " << c - b << std::endl;
	std::cout << a << " " << b << " " << c << std::endl;
	std::cout << Fixed::max(a,Fixed(100)) << " " << Fixed::max(b,Fixed(100)) << " " << Fixed::max(c,Fixed(100)) << std::endl;
	std::cout << Fixed::min(a,Fixed(100)) << " " << Fixed::min(b,Fixed(100)) << " " << Fixed::min(c,Fixed(100)) << std::endl;
	if ( a > b)
		std::cout << a << ">" << b << std::endl;
	else
		std::cout << a << "!>" << b << std::endl;
}
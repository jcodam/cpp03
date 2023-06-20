#pragma once 
#include <iostream>

class Fixed
{
private:
	int _num;
	static const int _bits;

public:
	Fixed();
	Fixed( int num );
	Fixed( Fixed const & src );
	~Fixed();

	Fixed & operator=( Fixed const & rhs );
	int getRawBits() const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs);

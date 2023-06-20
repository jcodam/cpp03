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
	Fixed( float num );
	Fixed( Fixed const & src );
	~Fixed();

	Fixed & operator=( Fixed const & rhs );
	int getRawBits() const;
	int toInt() const;
	float toFloat() const;
};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs);

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
	Fixed & operator-=( Fixed const & rhs );
	Fixed & operator+=( Fixed const & rhs );
	Fixed & operator*=( Fixed const & rhs );
	Fixed & operator/=( Fixed const & rhs );
	Fixed operator++( int );
	Fixed & operator++();
	Fixed operator--( int );
	Fixed & operator--();
	Fixed operator+( Fixed const & rhs ) const;
	Fixed operator-( Fixed const & rhs ) const;
	Fixed operator*( Fixed const & rhs ) const;
	Fixed operator/( Fixed const & rhs ) const;
	bool operator<( Fixed const & rhs ) const;
	bool operator<=( Fixed const & rhs ) const;
	bool operator>( Fixed const & rhs ) const;
	bool operator>=( Fixed const & rhs ) const;
	bool operator==( Fixed const & rhs ) const;
	bool operator!=( Fixed const & rhs ) const;

	int getRawBits() const;
	int toInt() const;
	float toFloat() const;

	static Fixed & min(Fixed & a, Fixed & b );
	static Fixed const & min(Fixed const & a, Fixed const & b );
	static Fixed & max(Fixed & a, Fixed & b );
	static Fixed const & max(Fixed const & a, Fixed const & b );

};

std::ostream & operator<<( std::ostream & o, Fixed const & rhs);

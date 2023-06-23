#pragma once
#include "Fixed.hpp"

// the attribute's are not const becaus than the mandatory operator won't work.
class point
{
private:
	Fixed  _x;
	Fixed  _y;

public:
	point();
	point( const float x, const float y );
	point( point const & src );
	~point();

	point & operator=( point const & rhs );
	Fixed const	& getX() const;
	Fixed const	& getY() const;
	void	printData() const;
};
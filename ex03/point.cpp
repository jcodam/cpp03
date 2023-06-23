#include "point.hpp"

point::point() : _x(0), _y(0) {
	// std::cout << "default point constructor called" << std::endl;
}
point::point( const float x, const float y ) : _x(x), _y(y) {
	// std::cout << "assignment point constructor called" << std::endl;
}
point::point( point const & src ) {
	// std::cout << "copy point constructor called" << std::endl;
	*this = src;
}
point::~point() {
	// std::cout << "point Destructor called" << std::endl;

}

point & point::operator=( point const & rhs ) {
	this->_x = rhs.getX();
	this->_y = rhs.getY();
	return *this;
}

Fixed const &	point::getX() const {
	return this->_x;
}
Fixed const &	point::getY() const {
	return this->_y;
}

void	point::printData() const {
	std::cout << " x = " << this->_x << " y = " << this->_y << std::endl;
}

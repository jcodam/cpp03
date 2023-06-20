#include "Fixed.hpp"
#include <math.h>

const int Fixed::_bits = 8;

Fixed::Fixed() : _num(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int num ) : _num(num<<8) {
	std::cout << "Int constructor called" << std::endl;
}
Fixed::Fixed( float num ) {
	std::cout << "Float constructor called" << std::endl;
	this->_num = roundf(num * (1<<this->_bits));
}

Fixed::Fixed( Fixed const & src ) : _num(src.getRawBits()) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int	Fixed::toInt() const{
	return this->_num>>this->_bits;
}

float	Fixed::toFloat() const{
	return (float)this->_num/(float)(1<<this->_bits);
}

Fixed & Fixed::operator=( Fixed const & rhs ) {
	std::cout << "Copy assignment operator called" << this->_num << std::endl;
	this->_num = rhs.getRawBits();
	return *this;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_num;
}

std::ostream & operator<<( std::ostream & o, Fixed const & rhs) {
	o << rhs.toFloat();
	return o;
}
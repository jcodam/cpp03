#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed() : _num(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int num ) : _num(num) {
	std::cout << "Assignment constructor called" << std::endl;
}

Fixed::Fixed( Fixed const & src ) : _num(src.getRawBits()) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
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
	o << rhs.getRawBits();
	return o;
}
#include "DiamondTrap.hpp"
#include "../mycolor.hpp"

DiamondTrap::DiamondTrap() : _Name("unknown")  {
	std::cout << FG_LGREEN "A DiamondTrap named " << this->getName() << " is arriving" FG_DEFAULT << std::endl;
}
DiamondTrap::DiamondTrap( std::string name ) : _Name(name) {
	this->_Name = name;
	this->setName(this->_Name + "_DiamondTrap");
	std::cout << FG_LGREEN "A DiamondTrap named " << this->getName() << " is arriving" FG_DEFAULT << std::endl;
}
DiamondTrap::DiamondTrap( DiamondTrap const & src ) {
	this->setName(src.getName());
	std::cout << FG_LGREEN "A DiamondTrap named " << this->getName() << " is arriving" FG_DEFAULT << std::endl;
}
DiamondTrap::~DiamondTrap() {
	std::cout << FG_LGREEN "A DiamondTrap named " << this->_Name << " is destroyed" FG_DEFAULT << std::endl;
}

DiamondTrap & DiamondTrap::operator=( DiamondTrap const & rhs ) {
	this->_Name = rhs.getName();
	return *this;
}
std::ostream & operator<<( std::ostream & o, DiamondTrap const & rhs) {
	o << "diamond name> " << rhs.getName() << " hp> " << rhs.getHP() << " energy> " << rhs.getEnergy() << " damage> " << rhs.getDamage();
	return o;
}
void DiamondTrap::attack( const std::string& target ) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << FG_CYAN "Who am I? am I "<< this->_Name << " or am I " << this->getName() << FG_DEFAULT << std::endl;
}
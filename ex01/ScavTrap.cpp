#include "ScavTrap.hpp"
#include "../mycolor.hpp"

ScavTrap::ScavTrap() {
	this->setHP(100);
	this->setEnergy(50);
	this->setDamage(20);
	std::cout << FG_LGREEN "A ScavTrap named " << this->getName() << " is arriving" FG_DEFAULT << std::endl;
}
ScavTrap::ScavTrap( std::string name ) {
	this->setName(name);
	this->setHP(100);
	this->setEnergy(50);
	this->setDamage(20);
	std::cout << FG_LGREEN "A ScavTrap named " << this->getName() << " is arriving" FG_DEFAULT << std::endl;
}
ScavTrap::ScavTrap( ScavTrap const & src ) {
	this->setName(src.getName());
	this->setHP(100);
	this->setEnergy(50);
	this->setDamage(20);
		std::cout << FG_LGREEN "A ScavTrap named " << this->getName() << " is arriving" FG_DEFAULT << std::endl;
}
ScavTrap::~ScavTrap() {
	std::cout << FG_LGREEN "A ScavTrap named " << this->getName() << " is destroyed" FG_DEFAULT << std::endl;
}

ScavTrap & ScavTrap::operator=( ScavTrap const & rhs ) {
	this->setName(rhs.getName());
	return *this;
}

void	ScavTrap::guardGate() const {
	std::cout << this->getName() << " is in Gate Keeper mode" << std::endl;
}

std::ostream & operator<<( std::ostream & o, ScavTrap const & rhs) {
	o << rhs.getName();
	return o;
}

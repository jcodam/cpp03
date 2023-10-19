#include "../mycolor.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap() {
	this->setHP(100);
	this->setDamage(30);
	std::cout << FG_LGREEN "a FragTrap named " << this->getName() << " has arrived" FG_DEFAULT << std::endl;
}
FragTrap::FragTrap( std::string name ) {
	this->setName(name);
	this->setHP(100);
	this->setEnergy(100);
	this->setDamage(30);
	std::cout << FG_LGREEN "a FragTrap named " << this->getName() << " has arrived" FG_DEFAULT << std::endl;
}
FragTrap::FragTrap( FragTrap const & src ) {
	this->setName(src.getName());
	this->setHP(100);
	this->setEnergy(100);
	this->setDamage(30);
	std::cout << FG_LGREEN "a FragTrap named " << this->getName() << " has arrived" FG_DEFAULT << std::endl;
}
FragTrap::~FragTrap() {
	std::cout << FG_LGREEN "a FragTrap named " << this->getName() << " has left" FG_DEFAULT << std::endl;
}

FragTrap & FragTrap::operator=( FragTrap const & rhs ) {
	this->setName(rhs.getName());
	return *this;
}

void FragTrap::highFivesGuys(){
	std::cout << this->getName() << " wants to give the gang a high five but as usual is left hanging" << std::endl;
}

std::ostream & operator<<( std::ostream & o, FragTrap const & rhs) {
	o << "frag name> " << rhs.getName() << " hp> " << rhs.getHP() << " energy> " << rhs.getEnergy() << " damage> " << rhs.getDamage();
	return o;
}

void FragTrap::attack( const std::string& target ) {
	if (this->getEnergy() && this->_HP)
	{
		this->setEnergy(this->getEnergy() - 1);
		std::cout << FG_CYAN << "a FragTrap named " << this->getName() << " is attacking " << target << " and hits for "<< this->getDamage() << FG_DEFAULT << std::endl;
	}
	else
	{
		if (!this->_HP)
			std::cout << FG_CYAN << this->_Name << " is already dead" << FG_DEFAULT << std::endl;
		else
			std::cout << FG_CYAN << this->_Name << " is out of energy" << FG_DEFAULT << std::endl;
	}
}
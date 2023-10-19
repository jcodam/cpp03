#include "ClapTrap.hpp"
#include "../mycolor.hpp"

ClapTrap::ClapTrap() : _Name("unknown"), _HP(10), _Energy(10), _Damage(0), _maxHP(10) {
	std::cout << FG_LGREEN "A ClapTrap named " << this->_Name  << " is arriving" FG_DEFAULT << std::endl;
}
ClapTrap::ClapTrap( std::string name ) : _Name(name), _HP(10), _Energy(10), _Damage(0), _maxHP(10) {
	std::cout << FG_LGREEN "A ClapTrap named " << this->_Name  << " is arriving" FG_DEFAULT << std::endl;
}
ClapTrap::ClapTrap( ClapTrap const & src ) : _Name(src.getName()), _HP(10), _Energy(10), _Damage(0), _maxHP(10) {
	std::cout << FG_LGREEN "A ClapTrap copy named " << this->_Name  << " is arriving" FG_DEFAULT << std::endl;
}
ClapTrap::~ClapTrap() {
	std::cout << FG_RED "A ClapTrap named " << this->_Name << " is leaving" FG_DEFAULT << std::endl;
	
}

ClapTrap & ClapTrap::operator=( ClapTrap const & rhs ) {
	this->_Name = rhs.getName();
	// this->_HP = rhs._HP;
	// this->_Energy = rhs._Energy;
	// this->_Damage = rhs._Damage;
	return (*this);
}

void ClapTrap::attack( const std::string& target ) {
	if (this->_Energy && this->_HP)
	{
		this->_Energy--;
		std::cout << FG_CYAN << "a claptrap named " << this->_Name << " is attacking " << target << " and hits for "<< this->_Damage << FG_DEFAULT << std::endl;
	}
	else
	{
		if (!this->_HP)
			std::cout << FG_CYAN << this->_Name << " is already dead" << FG_DEFAULT << std::endl;
		else
			std::cout << FG_CYAN << this->_Name << " is out of energy" << FG_DEFAULT << std::endl;
	}
}

void ClapTrap::takeDamage( unsigned int amount ) {
	if (this->_HP)
	{
		std::cout << FG_CYAN << this->_Name << " " << this->_HP << " hp is taking " << amount;
		this->_HP -= amount;
		if (this->_HP < 1)
		{
			this->_HP = 0;
			std::cout << " of damage and is defeated with " << this->_HP << " hp left" << FG_DEFAULT << std::endl;
		}
		else
			std::cout << " of damage and has " << this->_HP << " hp left" << FG_DEFAULT << std::endl;
	}
	else
		std::cout << FG_CYAN << this->_Name << " is already defeated" << FG_DEFAULT << std::endl;
}

void ClapTrap::beRepaired( unsigned int amount ) {
	if (this->_HP)
	{
		if (this->_Energy)
		{
			this->_Energy--;
			std::cout << FG_CYAN << this->_Name << " " << this->_HP << "hp is repaired by " << amount;
			this->_HP += amount;
			if (this->_HP > this->_maxHP)
				this->_HP = this->_maxHP;
			std::cout << " damage and has " << this->_HP << " hp left" << FG_DEFAULT << std::endl;
		}
		else
			std::cout << FG_CYAN << this->_Name << " is out of energy" << FG_DEFAULT << std::endl;
	}
	else
		std::cout << FG_CYAN << this->_Name << " is already defeated" << FG_DEFAULT << std::endl;

}
void ClapTrap::setName( std::string name ){
	this->_Name = name;
}
void ClapTrap::setHP(int hp){
	this->_HP = hp;
	this->_maxHP = hp;
}
void ClapTrap::setEnergy(int energy){
	this->_Energy = energy;
}
void ClapTrap::setDamage(int damage){
	this->_Damage = damage;
}
std::string ClapTrap::getName() const {
	return (this->_Name);
}
int	ClapTrap::getDamage() const {
	return (this->_Damage);
}
int	ClapTrap::getHP() const {
	return (this->_HP);
}
int	ClapTrap::getEnergy() const {
	return (this->_Energy);
}
std::ostream & operator<<( std::ostream & o, ClapTrap const & rhs) {
	o << "clap name> " << rhs.getName() << " hp> " << rhs.getHP() << " energy> " << rhs.getEnergy() << " damage> " << rhs.getDamage();
	return o;
}

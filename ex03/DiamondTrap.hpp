#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

class DiamondTrap : public ScavTrap , public FragTrap
{
private:
	std::string _Name;
protected:
	DiamondTrap();
public:
	DiamondTrap( std::string name );
	DiamondTrap( DiamondTrap const & src );
	~DiamondTrap();

	DiamondTrap & operator=( DiamondTrap const & rhs );
	void attack( const std::string& target );
	void whoAmI();

};

std::ostream & operator<<( std::ostream & o, DiamondTrap const & rhs);

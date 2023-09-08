#pragma once
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:

public:
	ScavTrap();
	ScavTrap( std::string name );
	ScavTrap( ScavTrap const & src );
	~ScavTrap();

	ScavTrap & operator=( ScavTrap const & rhs );
	void guardGate() const;

};

std::ostream & operator<<( std::ostream & o, ScavTrap const & rhs);

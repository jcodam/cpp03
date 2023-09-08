#pragma once
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
private:

public:
	ScavTrap();
	ScavTrap( std::string name );
	ScavTrap( ScavTrap const & src );
	~ScavTrap();

	ScavTrap & operator=( ScavTrap const & rhs );
	void guardGate() const;
	void attack( const std::string& target );

};

std::ostream & operator<<( std::ostream & o, ScavTrap const & rhs);

#pragma once
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public ClapTrap
{
private:
	//variable

public:
	FragTrap();
	FragTrap( std::string name );
	FragTrap( FragTrap const & src );
	~FragTrap();

	FragTrap & operator=( FragTrap const & rhs );
	void highFivesGuys(void);
};

std::ostream & operator<<( std::ostream & o, FragTrap const & rhs);

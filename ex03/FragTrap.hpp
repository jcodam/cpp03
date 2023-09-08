#pragma once
#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : public virtual ClapTrap
{
private:
	//variable
protected:
	FragTrap();

public:
	FragTrap( std::string name );
	FragTrap( FragTrap const & src );
	~FragTrap();

	FragTrap & operator=( FragTrap const & rhs );
	void highFivesGuys(void);
	void attack( const std::string& target );

};

std::ostream & operator<<( std::ostream & o, FragTrap const & rhs);

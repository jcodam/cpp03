#pragma once
#include <iostream>

class ClapTrap
{
private:

protected:
	std::string _Name;
	int _HP;
	int _Energy;
	int _Damage;
	int _maxHP;
	void setName(std::string name);
	void setHP(int hp);
	void setEnergy(int energy);
	void setDamage(int damage);
	ClapTrap();

public:
	ClapTrap( std::string name );
	ClapTrap( ClapTrap const & src );
	virtual ~ClapTrap();

	ClapTrap & operator=( ClapTrap const & rhs );
	void attack( const std::string& target );
	void takeDamage( unsigned int amount );
	void beRepaired( unsigned int amount );

	std::string getName() const;
	int	getHP() const;
	int	getEnergy() const;
	int	getDamage() const;

};

std::ostream & operator<<( std::ostream & o, ClapTrap const & rhs);

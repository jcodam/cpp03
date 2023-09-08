#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "../mycolor.hpp"

int check_cinerr(std::string errtext)
{
	if (std::cin.eof())
	{
		std::cin.clear();
		std::clearerr(stdin);
		std::cout << std::endl << errtext << std::endl;
		return (0);
	}
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max());
		std::cout << errtext << std::endl;
		return (0);
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return (1);
}

int	display_options(){
	std::string temp;

	std::cout << FG_LGREEN"COMMANDS: attack, damage, new, repair, guard, exit" << FG_DEFAULT << std::endl;
	std::cin >> temp;
	if (!check_cinerr("check your input"))
		return (5);
	for (int i = 0; temp[i]; i++)
		temp[i] = tolower(temp[i]);
	if (temp.compare("exit") == 0 || temp.compare("0") == 0)
		return (0);
	if (temp.compare("attack") == 0 || temp.compare("1") == 0)
		return (1);
	if (temp.compare("damage") == 0 || temp.compare("2") == 0)
		return (2);
	if (temp.compare("new") == 0 || temp.compare("3") == 0)
		return (4);
	if (temp.compare("repair") == 0 || temp.compare("4") == 0)
		return (6);
	if (temp.compare("guard") == 0 || temp.compare("5") == 0)
		return (7);
	std::cout << "command not found.";
	return (5);
}

void delBot(ClapTrap **ClapTraps, ScavTrap **scav)
{
	for (int i = 0; ClapTraps[i]; i++)
	{
		delete ClapTraps[i];
	}
	for (int i = 0; scav[i]; i++)
		delete scav[i];
}

void	scav_action(ScavTrap *scav, int token){
	std::string target;
	unsigned int amount = 0;
		if (token == 1)
		{
			std::cout << FG_LGREEN << "Who do we attack: " << FG_DEFAULT;
			std::getline(std::cin, target, '\n');
				scav->attack( target);
		}
		if (token == 2)
		{
			std::cout << FG_LGREEN << "How much should we do?: " << FG_DEFAULT;
			std::cin >> amount;
			if (check_cinerr("check your input"))
			{
				scav->takeDamage( amount);
			}
		}
		if (token == 6)
		{	
			std::cout << FG_LGREEN << "How much should we do?: " << FG_DEFAULT;
			std::cin >> amount;
			if (check_cinerr("check your input"))
			{
				scav->beRepaired( amount);
			}
		}
		if (token == 7)
			scav->guardGate();
}
void	clap_action(ClapTrap *ClapTraps, int token){
	std::string target;
	unsigned int amount = 0;
		if (token == 1)
		{
			std::cout << FG_LGREEN << "Who do we attack: " << FG_DEFAULT;
			std::getline(std::cin, target, '\n');
				ClapTraps->attack( target);
		}
		if (token == 2)
		{
			std::cout << FG_LGREEN << "How much should we do?: " << FG_DEFAULT;
			std::cin >> amount;
			if (check_cinerr("check your input"))
			{
				ClapTraps->takeDamage( amount);
			}
		}
		if (token == 6)
		{	
			std::cout << FG_LGREEN << "How much should we do?: " << FG_DEFAULT;
			std::cin >> amount;
			if (check_cinerr("check your input"))
			{
				ClapTraps->beRepaired( amount);
			}
		}
		if (token == 7)
			std::cout << ClapTraps->getName() <<" can't guard\n";
}

int searchBot(ClapTrap **ClapTraps, std::string name, ScavTrap **scav, int token)
{
	for (int i = 0; ClapTraps[i]; i++)
	{
		if (!name.compare(ClapTraps[i]->getName()))
			clap_action(ClapTraps[i], token);
	}
	for (int i = 0; scav[i]; i++)
	{
		if (!name.compare(scav[i]->getName()))
			scav_action(scav[i], token);
	}
	return (-1);
}

int main(void)
{
	std::string name;
	std::string type;
	int			token;
	ClapTrap	*ClapTraps[10] = {0,0,0,0,0,0,0,0,0,0};
	ScavTrap	*ScavTraps[10] = {0,0,0,0,0,0,0,0,0,0};
	unsigned int index = 0;
	unsigned int index_scav = 0;

	while (1)
	{
		token = display_options();
		if (!token)
		{
			delBot(ClapTraps, ScavTraps);
			return 0;
			exit(0);
		}
		if (token != 5)
		{
			std::cout << FG_LGREEN << "Whats their name: " << FG_DEFAULT;
			std::getline(std::cin, name, '\n');
		}
		if (token == 4 )
		{
			std::cout << FG_LGREEN << "clap or scav?: " << FG_DEFAULT;
			std::getline(std::cin, type, '\n');
			if ( type.compare("clap") == 0 && index < sizeof(ClapTraps)/sizeof(ClapTrap))
			{
				ClapTraps[index] = new ClapTrap(name);
				index++;
			}
			else if ( type.compare("scav") == 0 && index_scav < sizeof(ScavTraps)/sizeof(ScavTrap))
			{
				ScavTraps[index_scav] = new ScavTrap(name);
				index_scav++;
			}
			else
				std::cout << FG_GREEN << "to many!!! WE ARE GONNA DIE!!!!" << FG_DEFAULT << std::endl;
		}
		else
			searchBot(ClapTraps, name, ScavTraps, token);
		std::cout << std::endl;
	}
	return 0;
}
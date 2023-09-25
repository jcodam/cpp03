#include "ClapTrap.hpp"
#include "../mycolor.hpp"
#include <limits>
#include <cstdio>

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

	std::cout << FG_LGREEN"COMMANDS: attack, damage, new, repair, exit" << FG_DEFAULT << std::endl;
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
	std::cout << "command not found.";
	return (5);
}

void delBot(ClapTrap **ClapTraps, int maxindex)
{
	for (int i = 0; i < maxindex; i++)
	{
		delete ClapTraps[i];
	}
}

int searchBot(ClapTrap **ClapTraps, std::string name, int maxindex)
{
	for (int i = 0; i < maxindex; i++)
	{
		if (!name.compare(ClapTraps[i]->getName()))
			return (i);
	}
	return (-1);
}

int main(void)
{
	std::string name;
	std::string target;
	int			token;
	ClapTrap	*ClapTraps[10];
	unsigned int index = 0;
	unsigned int amount = 0;

	while (1)
	{
		token = display_options();
		if (!token)
		{
			delBot(ClapTraps, index);
			return 0;
		}
		if (token != 5)
		{
			std::cout << FG_LGREEN << "Whats their name: " << FG_DEFAULT;
			std::getline(std::cin, name, '\n');
			if (searchBot(ClapTraps, name, index) == -1 && token != 4)
			{
				std::cout << FG_LGREEN << "wrong name\n" << FG_DEFAULT;
				token = 0;
			}
		}
		if (token == 4 && index < sizeof(ClapTraps)/sizeof(ClapTrap *))
		{
			ClapTraps[index] = new ClapTrap(name);
			index++;
		}
		else if (token == 4 && index >= sizeof(ClapTraps)/sizeof(ClapTrap *))
			std::cout << FG_GREEN << "to many ClapTraps!!! WE ARE GONNA DIE!!!!" << FG_DEFAULT << std::endl;
		if (token == 1)
		{
			std::cout << FG_LGREEN << "Who do we attack: " << FG_DEFAULT;
			std::getline(std::cin, target, '\n');
				ClapTraps[searchBot(ClapTraps,name, index)]->attack( target);
		}
		if (token == 2)
		{
			std::cout << FG_LGREEN << "How much should we do?: " << FG_DEFAULT;
			std::cin >> amount;
			if (check_cinerr("check your input"))
			{
				ClapTraps[searchBot(ClapTraps,name, index)]->takeDamage( amount);
			}
		}
		if (token == 6)
		{
			// for (int index = 0; index < amount; index++)
			
			std::cout << FG_LGREEN << "How much should we do?: " << FG_DEFAULT;
			std::cin >> amount;
			if (check_cinerr("check your input"))
			{
				ClapTraps[searchBot(ClapTraps,name, index)]->beRepaired( amount);
			}
		}
		std::cout << std::endl;
	}
	return 0;
}
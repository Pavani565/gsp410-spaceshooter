#pragma once
#include "Warrior.h"

class HumanWarrior :
	public Warrior
{
public:
	HumanWarrior(void);
	HumanWarrior(int);
	~HumanWarrior(void);
	void attack();
	void defend();
	void loot();
	void displayInventory();
	std::string status();
	void havok();
};
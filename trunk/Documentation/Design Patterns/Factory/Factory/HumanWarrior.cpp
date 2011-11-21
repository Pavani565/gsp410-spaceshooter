#include "StdAfx.h"
#include "HumanWarrior.h"
#include <string>
#include <iostream>


HumanWarrior::HumanWarrior(void)
{
	ID = -1;
	Race = "Human";
	Type = "Warrior";
}

HumanWarrior::HumanWarrior(int ident)
{
	ID = ident;
	Race = "Human";
	Type = "Warrior";
}

HumanWarrior::~HumanWarrior(void)
{
}

void HumanWarrior::attack()
{
}
void HumanWarrior::defend()
{
}

void HumanWarrior::displayInventory()
{
}
void HumanWarrior::loot()
{
}
std::string HumanWarrior::status()
{
	return "Ready for combat.";
}
void HumanWarrior::havok()
{
}

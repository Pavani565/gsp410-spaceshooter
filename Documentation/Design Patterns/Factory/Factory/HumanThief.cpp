#include "StdAfx.h"
#include "HumanThief.h"
#include <string>
#include <iostream>

HumanThief::HumanThief(void)
{
	ID = -1;
	Race = "Human";
	Type = "Thief";
}

HumanThief::HumanThief(int ident)
{
	ID = ident;
	Race = "Human";
	Type = "Thief";
}

HumanThief::~HumanThief(void)
{
}

void HumanThief::attack()
{
}
void HumanThief::defend()
{
}

void HumanThief::displayInventory()
{
}
void HumanThief::loot()
{
}
std::string HumanThief::status()
{
	return "All is well.";
}
void HumanThief::steal()
{
}

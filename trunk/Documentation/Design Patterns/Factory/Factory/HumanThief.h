#pragma once
#include "thief.h"

class HumanThief :
	public Thief
{
public:
	HumanThief(void);
	HumanThief(int);
	~HumanThief(void);
	void attack();
	void defend();
	void loot();
	void displayInventory();
	std::string status();
	void steal();
};

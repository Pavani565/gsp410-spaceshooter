#pragma once
#include "Unit.h"

class Warrior :
	public Unit
{
public:
	Warrior(void);
	~Warrior(void);
	virtual void havok() = 0;

protected:
	int strength;
};


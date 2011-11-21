#pragma once
#include "Unit.h"

class Thief abstract:
	public Unit
{
public:
	Thief(void);
	~Thief(void);
	virtual void steal() = 0;


protected:
	int stealth;

};

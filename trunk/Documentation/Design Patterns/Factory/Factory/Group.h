#pragma once
#include <string>
#include <iostream>
#include "Unit.h"
#include "HumanUnitFactory.h"

#define MAX_UNITS 6
class Group
{
public:
	Group(void);
	~Group(void);
	int pushNewUnit(int, int);
	int pushUnit(Unit* );
	Unit* getUnit(int);

private:
	UnitFactory* getFactory(int);
	Unit* Units[MAX_UNITS];
	int NumberOfUnits;
};

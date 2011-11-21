#pragma once
#include "Unit.h"
#include "UnitFactory.h"
#include "HumanThief.h"
#include "HumanWarrior.h"

class HumanUnitFactory :
	public UnitFactory
{
public:
	~HumanUnitFactory(void);
	static HumanUnitFactory* getInstance();   
	void showData();
	Unit* createUnit(int);
	Unit* createThief();
	Unit* createWarrior();
	Unit* createMage();
private:
	HumanUnitFactory(void);
	static HumanUnitFactory* singleton;
	static bool hasInstance;
};



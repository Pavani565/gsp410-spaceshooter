#include "StdAfx.h"
#include "HumanUnitFactory.h"

bool HumanUnitFactory::hasInstance = false;
HumanUnitFactory* HumanUnitFactory::singleton = NULL;

HumanUnitFactory::HumanUnitFactory(void)
{
	IDCount = 0;
}

HumanUnitFactory::~HumanUnitFactory(void)
{
}


HumanUnitFactory* HumanUnitFactory::getInstance()
{
	if(! hasInstance)
	{
		singleton = new HumanUnitFactory();
		hasInstance = true;
		return singleton;
	}
	else
	{
		return singleton;
	}
}

Unit* HumanUnitFactory::createUnit(int type)
{
	switch ( type )
      {
         case 1:
			 return new HumanThief(IDCount++);
            break;
         case 2:
			return new HumanWarrior(IDCount++);
            break;
         case 3:
			return new HumanThief(IDCount++);
            break;
         default:
			 // put error warning here
            return NULL;
      }
}
Unit* HumanUnitFactory::createThief()
{
	return new HumanThief(IDCount++);
}
Unit* HumanUnitFactory::createWarrior()
{
	return new HumanWarrior(IDCount++);
}
Unit* HumanUnitFactory::createMage()
{
	return new HumanThief(IDCount++);
}
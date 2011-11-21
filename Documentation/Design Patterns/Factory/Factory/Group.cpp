#pragma once
#include "StdAfx.h"
#include "Group.h"

Group::Group(void)
{
	NumberOfUnits = 0;
}

Group::~Group(void)
{
}


int Group::pushUnit(Unit* newUnit)
{
	if (NumberOfUnits < MAX_UNITS)
	{
		Units[NumberOfUnits] = newUnit;
		NumberOfUnits++;
	}
	else
	{
		std::cout << "No more room for units!" << std::endl;
	}
	return NumberOfUnits;
}

int Group::pushNewUnit(int Type, int Race)
{
	if (NumberOfUnits < MAX_UNITS)
	{
		UnitFactory* factory = getFactory(Race);
		Units[NumberOfUnits] = factory->createUnit(Type);
		NumberOfUnits++;
	}
	else
	{
		std::cout << "No more room for units!" << std::endl;
	}
	return NumberOfUnits;
}

Unit* Group::getUnit(int index)
{
	return Units[index];
}

UnitFactory* Group::getFactory(int race)
{
	      
	switch ( race )
      {
         case 1:
			 return HumanUnitFactory::getInstance();
            break;
         case 2:
			 return HumanUnitFactory::getInstance();
            break;
         case 3:
			 return HumanUnitFactory::getInstance();
            break;
         default:
			 // put error warning here
            return NULL;
      }

}
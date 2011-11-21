// Factory.cpp : Defines the entry point for the console application.
//

#pragma once
#include "stdafx.h"
#include "Group.h"
#include "Unit.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Group myGroup;
	Unit* myUnit;
	int unitIndex;
	int iRace;
	int iType;
	int userCommand;
	bool stayInLoop = true;
	do
	{
		std::cout << std::endl << "What race do you want created? ";
		std::cin >> iRace;
		std::cout << std::endl << "What type of unit do you want created? ";
		std::cin >> iType;
		unitIndex = myGroup.pushNewUnit(iType, iRace);
		myUnit = myGroup.getUnit(unitIndex-1);
		std::cout << "Unit race is: " << myUnit->getRace() << std::endl;
		std::cout << "Unit type is: " << myUnit->getType() << std::endl;
		std::cout << "Unit reports status as: " << myUnit->status() << std::endl;
		std::cout << "Type -1 to quit" << std::endl;
		std::cin >> userCommand;
		if (userCommand < 0) stayInLoop = false;
	} while (stayInLoop);
	return 0;
}


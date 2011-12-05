//Will Zepeda
//GSP-410
//Sector.cpp
//sectors that make up a quadrant
#include "Sector.h"

Sector::Sector()
{
	occupied		= false;
	occupiedType	= EMPTY;
}

Command Sector::Clicked(POINT mouse)
{
	Command cmd;

	//check to see if mouse click is in sector
	if(mouse.x <= x + width/2 &&
	   mouse.x >= x - width/2)
	{
		if(mouse.y <= y + height/2 &&
		   mouse.y >= y - height/2)
		{
			cmd.commandType = 0;
			return cmd;
		}
	}
	return cmd;
}
//void Sector::setOccupation(int aType)
//{
//	//set occupied bool to true
//	occupied = true;
//	type	 = aType;
//}
//int	Sector::occupiedWith()
//{
//
//}

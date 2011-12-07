//Will Zepeda
//GSP-410
//Sector.cpp
//sectors that make up a quadrant
#include "Sector.h"

Sector::Sector()
{
	mOccupied		= false;
	mQuadPos.row	= 0;
	mQuadPos.col	= 0;
	mOccupiedType	= -1;
	mEnemyIndex		= -1;
	mScale			= 0.0f;
}

void Sector::setContent(int aType)
{
	mOccupiedType = aType;
}
void Sector::setContent(int aType, int aIndex)
{
	mOccupiedType = aType;
	mEnemyIndex	  = aIndex;
}

void Sector::setOriginScale(float aScale) //occupied type that's in sector
{
	mScale = aScale;
}

bool Sector::Clicked(POINT mouse, Command &cmd)
{
	//check to see if mouse click is in sector
	if(mouse.x <= x + width/2 &&
	   mouse.x >= x - width/2)
	{
		if(mouse.y <= y + height/2 &&
		   mouse.y >= y - height/2)
		{
			//fill command with COMMAND_TYPE
			
			//fill x & y positions

			return true;
		}
	}
	//fill commandType with INVALID_COMMAND
	//fill x and y with zeros
	return false;
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

//Will Zepeda
//GSP-410
//Sector.h
//sectors that make up a quadrant
#pragma once
#include "Clickable.h"

//what do they need?
//NEEDS TO BE DERIVED FROM CLICKABLE
//NEEDS TO KNOW IF IT WAS CLICKED
//#include "Structures.h"

class Sector : public Clickable
{
private:
	bool	mOccupied;
	RowCol	mQuadPos;
	int		mOccupiedType;
	int		mEnemyIndex;
	float	mScale;
	int		mSectorNum;

public:
	Sector();

	void setSectorNum(int);
	int	 getSectorNum(){ return mSectorNum; }

	///////////////////////////////////////////////////////
	//name    : setContent
	//param1  : int, OCCUPATION_TYPE
	//job	  : use for OCCUPATION_TYPES that are not enemies
	//		  : let's sector know what it is occupied with
	//return  : void
	void setContent(int);

	///////////////////////////////////////////////////////
	//name    : setContent
	//param1  : int, OCCUPATION_TYPE
	//param2  : int, enemy index
	//job	  : only use if OCCUPATION_TYPE is ENEMY!
	//        : let's sector know that it's occupied with enemy
	//		  : let's sector know which enemy is on it
	//return  : void
	void setContent(int, int);

	///////////////////////////////////////////////////////
	//name    : setOriginScale
	//param1  : float, scale you sector to be
	//job     : sets sector's scale value
	//return  : void
	void setOriginScale(float); //occupied type that's in sector

	///////////////////////////////////////////////////////
	//name    : Clicked
	//param1  : POINT, mouse position
	//param2  : Command, address of Command object 
	//job     : checks if sector was clicked and returns Command struct
	//        : NOTE: changes Command object's values when function
	//		  : returns.
	//return  : bool, when true it fills command object with
	//		  : command's xy values of sector and the specific command.
	//		  : when false it fills command object with INVALID_COMMAND
	//		  : and sets command's xy to -1.
	bool virtual Clicked(POINT, Command &);

	/**
	* sets/gets
	**/
};
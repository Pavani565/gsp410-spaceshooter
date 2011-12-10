//Will Zepeda
//GSP-410
//SPACE SHOOTER
//Clickable.h
#pragma once
//#include <WinDef.h>
#include <Windows.h>
#include "Structures.h"

//all the things that are clickable
class Clickable
{
protected:
	int x, y, width, height;
public:
	virtual bool Clicked(POINT, Command &) = 0;
	Clickable()
	{
		height = 64;
		width = 64;
		x = 0;
		y = 0;
	}
	/**
	* sets/gets
	**/
	//void setX(int);
	//int	 getX(){ return x; }

	//void setY(int);
	//int  getY(){ return y; }

	//void setWidth(int);
	//int  getWidth(){ return width; }

	//void setHeight(int);
	//int  getHeight(){ return height; }
};
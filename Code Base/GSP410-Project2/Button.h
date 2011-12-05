//Will Zepeda
//GSP-410
//SPACE SHOOTER
//Button.h
#pragma once
#include "Clickable.h"

//needs to be derived from clickable
//everything a button needs to do

class Button : public Clickable
{
private:

public:
	Command virtual Clicked(POINT);
	void setAction(int);
};
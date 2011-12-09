//Will Zepeda
//GSP-410
//SPACE SHOOTER
//Button.h
#pragma once
#include "Clickable.h"
#include "Definitions.h"

//needs to be derived from clickable
//everything a button needs to do

class Button : public Clickable
{
private:
	int mButtonType;

public:
	Button();

	void setButtonType(int);

	//void setAction(int);

	bool virtual Clicked(POINT, Command &);
};
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
	Button();


	bool virtual Clicked(POINT, Command &);
	
	
	void setAction(int);
};
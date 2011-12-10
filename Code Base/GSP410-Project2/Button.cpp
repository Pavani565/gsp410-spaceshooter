//Will Zepeda
//GSP-410
//SPACE SHOOTER
//Button.cpp
#include "Button.h"

Button::Button()
{
	mButtonType = -1;
}

void Button::setButtonType(int aButtonType)
{
	mButtonType = aButtonType;
}

bool Button::Clicked(POINT mouse, Command &cmd)
{
	//check to see if mouse click is in sector
	if(mouse.x <= x + width/2 &&
	   mouse.x >= x - width/2)
	{
		if(mouse.y <= y + height/2 &&
		   mouse.y >= y - height/2)
		{
			//fill command with COMMAND_TYPE
			cmd.commandType = mButtonType;
			//fill x & y positions w/ invalid data
			cmd.sectorPos.row = -1;
			cmd.sectorPos.col = -1;
			return true;
		}
	}
	//fill command with INVALID_COMMAND
	cmd.commandType = INVALID_COMMAND;
	//fill x and y with invalid data
	cmd.sectorPos.row = -1;
	cmd.sectorPos.col = -1;
	return false;
}

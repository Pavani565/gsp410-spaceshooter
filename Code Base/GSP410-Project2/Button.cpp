//Will Zepeda
//GSP-410
//SPACE SHOOTER
//Button.cpp
#include "Button.h"

Command Button::Clicked(POINT mouse)
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

//Will Zepeda
//GSP-410
//SPACE SHOOTER
//Button.cpp
#include "Button.h"

Button::Button()
{

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
			
			//fill x & y positions w/ zero

			return true;
		}
	}
	//fill command with INVALID_COMMAND
	//fill x and y with zeros
	return false;
}

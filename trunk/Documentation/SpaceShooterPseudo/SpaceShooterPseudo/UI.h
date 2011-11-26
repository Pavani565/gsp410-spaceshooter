#pragma once

struct UI
{
	bool checkInput(void)
	{
		bool input;
		//check for some type of input right now bool 
		//but eventually could be used for a variety of input
		//mouse, keyboard, whatever
		return input;
	}
};

//*************************
//THINGS UI NEEDS TO DO

// UI1)
//look for input that will change state to RULES or PLAY
//either keyboard or button
//gameControleState = UI.checkInput();

// UI2)
//gameController calls UI to get input that tells us
//what command player wants
//NONE,MOVE,LRS,
//FIREBLAST,FIREMISS,SHEILDS

// UI3)
//if(Sub Light Engines == Failed)
//what player left clicks on 
//getInput() from mouse

// UI4)
//look for input that will change state from RULES to PLAY
//either keyboard or button
//gameControleState = UI.checkInput();

// UI5)
//If the long range scanner has failed due to critical systems damage,
//the long range scan area will be “greyed” out and no data will be displayed. 
//The long range scan will not respond to left-clicking.  Otherwise, 
//left-clicking anywhere in the long range scan area will refresh the data.

// UI6)
//The long range scan will not respond to left-clicking.  
//Otherwise, left-clicking anywhere in the long range scan area will refresh the data.*/
//what player left clicks on 
//for long range scan
//getInput() from mouse

// UI7)
//what player left clicks on 
//to fire, the player left-clicks the blaster fire button. 
//getInput() from mouse

// UI8)
//somehow player changes blasters which will be done by some input

// UI9)
//to fire, the player left-clicks on the targeted enemy ship. The computer calculates the route to 
//the target ship and determines:

// UI10)
//what player left clicks on 
//to fire, the player left-clicks the missle fire button. 
//getInput() from mouse

// UI11)
//what player left clicks on 
// the player left-clicks “+” button on shields display 
//to increase energy to the shields or left-clicks “-“ button on shield display
//to decrease energy to the shields.
//getInput() from mouse
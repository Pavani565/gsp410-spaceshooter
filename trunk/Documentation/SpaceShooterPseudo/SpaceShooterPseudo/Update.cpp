#include "Controller.h"

void Controller::update()
{
	switch(gameControleState)
	{
	case INTRO:
		//set up game
		 initGame();


		break;
	case RULES:

		runRules();

		break;
	case PLAY:

		//check players ship systems
		//as long as players ship has all systesm needed to still play
		//keep playing game
		if(player.systemsGood() == true)
		{
			//orders: movement, long range scan, fire Blaster, fire missile or raise shields
			//gamecontroller calls UI to check for input that will be used to get command
			//which then goes into a switch statement based on playerCommand
			updateCommand();
		}
		//else game over
		else
		{
			gameControleState = ENDGAME;
		}
		

		break;
	case ENDGAME:

		shutdown();

		break;
	}
}

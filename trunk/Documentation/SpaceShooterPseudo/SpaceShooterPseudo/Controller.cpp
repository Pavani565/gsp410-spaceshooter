#include "Controller.h"

void Controller::initGame(void)
{	
	//While the game is in INTRO state it needs to set up or reset any game values, members
	//or visual stuff, while the game shows the intro text telling the player all the stuff they need to know
	//then the player has the option to read the rules or start game, possible end game as well


	//When the game starts, it determines the number of enemy ships,
	//space stations, and stars for each quadrant –just the number, 
	//not the positions within the quadrant.  It also generates the number of turns
	//the player has to destroy all enemy ships and it picks a starting quadrant for the player’s ship.
	//The player’s ship, enemy ships, space station, and stars are then placed into the quadrant—in that order.

	//have controller call quad class and have it build world numbers as suggested
	//quads could make the numbers for ships,stations, and stars
	makeQuads();

	//maybe first call to build renderer?
	//basiclly get hud build map,stars,buttons
	//any other screen stuff we need
	setUpScreen();

	//while controller is in INTRO it will have the intro text for the player
	//giveIntroSpeel() will tell renderer to show this text and then will wait for spesific
	//input which will tell us weather to show RULES or jump into PLAY 
	giveIntroSpeel();


}
void Controller::giveIntroSpeel(void)
{
	//sendMessToRenderer(playIntroMess)

	// UI1)
	//look for input that will change state to RULES or PLAY
	//either keyboard or button
	
	ui.checkInput() == true;

	

}
void Controller::updateSheilds(void)
{
	//probably send some input
	player.updateSheilds();
}
void Controller::fireBlaster(void)
{
	/*If the energy level to the blasters is zero or the blasters have failed,
	the blaster fire button is “greyed” out and the fire button will not work. 
	Otherwise, to fire, the player left-clicks the blaster fire button. 
	The computer then calculates the damage to the enemy ships in the quadrant.*/

	player.fireBlasters();
	calculateEnemyDamage();

}

void Controller::fireMissle(void)
{
	player.missleAttack();
	//The computer calculates the route to the target ship and determines:
	addUpObsticleDamage();


}
void Controller::calculateEnemyDamage(void)
{
	//The computer then calculates the damage to the enemy ships in the quadrant.
	enemies.update();
}
void Controller::runRules(void)
{
	// UI4)

	//tell renderer to draw the rules text 
	//sendMessToRenderer(showrules)

	//look for input that will change state to PLAY
	//either keyboard or button

	
	ui.checkInput() == true;

	
}
void Controller::updateCommand(void)
{
	// UI2)
	//gameController calls UI to get input that tells us
	//what command player wants


	//playerCommand = UI.checkInput();

	ui.checkInput() == true;

	

	//use a switch to update what command was picked
	//each choice has its own algorythm, process or needs  to fullfill command

	switch(playerCommand)
	{
		//left-clicks on hyper drive button
	case MOVE:

		//long process lookup definition
		moveProcess();

		break;
	case LRS://long range scan

		//The long range scan shows how many enemy ships, space stations, and stars 
		//there are in each of the adjacent quadrants.  Failure of the long range scan 
		//results in not getting this information.

		// HUD6)
		/*If the long range scanner has failed due to critical systems damage,
		the long range scan area will be “greyed” out and no data will be displayed. 

		// UI6)
		The long range scan will not respond to left-clicking.  
		Otherwise, left-clicking anywhere in the long range scan area will refresh the data.*/

		//this may be done somewhere else but for know shows how criticalSystemsDamage has
		//effect on outcome
		if(player.criticalSystemsDamage == true)
		{
			player.longRangeScannerState == false;
			//the long range scan area will be “greyed” out and no data will be displayed. 
			//hud should know
			//rendereer should know
		}

		// UI6)
		//need left mouse input for long range scan
		//UI.checkInput() is a temp way of showing some type of input is excpected
		if(player.longRangeScannerState == true && ui.checkInput() == true)
		{
			longRangeScan();
		}


		break;
	case FIREBLAST:
		/*the player may optionally adjust the energy level to the blasters prior to firing.

		// HUD7)
		If the energy level to the blasters is zero or the blasters have failed, 
		the blaster fire button is “greyed” out and the fire button will not work.

		// UI7)
		Otherwise, to fire, the player left-clicks the blaster fire button. 
		The computer then calculates the damage to the enemy ships in the quadrant.*/

		//if blasters are not 0 or failed player can use them
		if(player.blasterEnergyLevel == true && player.blasters == true)
		{

			//player may optionally adjust the energy level to the blasters prior to firing. 
			//have player contain this function or controller?
			if(ui.checkInput() == true)
			{
				// HUD8)
				//somehow player changes blasters which i asume changes something on hud

				// UI8)
				//somehow player changes blasters which will be done by some input
				player.AdjustBlasters();
			}

			//controller calls this function which calls players fireBlasters(), and then calls
			//calculateEnemyDamage()
			fireBlaster();
		}
		break;
	case FIREMISS:

		// HUD9)
		/*	Missiles: If the number of remaining missiles is zero or the missile launcher has failed,
		the missile launcher is “greyed” out and missiles cannot be fired.

		// UI9)
		Otherwise, to fire, the player left-clicks on the targeted enemy ship. The computer calculates the route to 
		the target ship and determines:

		i.	Obstacles: Does the missile run into a star, enemy ship, or space station? If so then:
		1.	Star:  There is a 90% chance the missile is destroyed, otherwise the missile 
		continues toward the target.
		2.	Space Station: There is a 10% chance the missile and space station are destroyed, 
		otherwise the missile continues toward the target. (Note: if a player destroys all his space stations,
		the game is over and the player loses.)
		3.	Enemy Ship: There is a 50% chance the missile and enemy ship are destroyed, otherwise the missile 
		continues toward the target.
		ii.	Hit: If the missile makes it to the target, the computer calculates whether or not 
		the enemy ship is destroyed. (see table in “Algorithms”)*/

		// HUD10)
		//number of remaining missiles
		if(player.remainingMissiles == true && player.missleLauncher== true)
		{
			if(ui.checkInput() == true)
			{


				// UI10)
				//somehow player fires missile which will be done by some input

				//this function fires missile and calls addUpObsticleDamage() function 
				//to take care of obstical costs as mentioned above
				fireMissle();
			}
		}



		break;
	case SHEILDS:

		// HUD11)
		/*Set Energy Level:  If the shields have failed due to critical systems damage,
		the shields “+” and “-“ buttons are “greyed” out and the shields are inoperable. 


		Otherwise, the player left-clicks “+” button on shields display 
		to increase energy to the shields or left-clicks “-“ button on shield display
		to decrease energy to the shields.  The energy display for the ship is offset 
		by the corresponding amount.
		
		//HUD12 
		ships energy level

		If the shield’s energy is increased by 100, 
		the ship’s energy is decreased by 100. */

		if(player.criticalSystemsDamage == true)
		{
			player.sheilds == false;
			// the shields “+” and “-“ buttons are “greyed” out 
			//hud should know
			//rendereer should know
		}

		if(player.sheilds == true)
		{	
			//the player left-clicks “+” button on shields display 
			if(ui.checkInput() == true)
			{
				//increase energy to the shields
				//If the shield’s energy is increased by 100, the ship’s energy is decreased by 100. 
				updateSheilds();
			}
			//the player left-clicks “-” button on shields display 
			if(ui.checkInput() == true)
			{
				//decrease energy to the shields 
				//If the shield’s energy is increased by 100, the ship’s energy is decreased by 100. 
				updateSheilds();
			}
		}

		break;
	}
}
bool Controller::enoughFuel(void)
{
	bool fuel;
	//do we have enough fuel to make it to target
	return fuel;
}
void Controller::makeQuads(void)
{
	enemies.makeEnemys();
	stations.makeStations();
	stars.makeStars();
	
}
void Controller::setUpScreen(void)
{
	// HUD1)
	//build hud
	//buildScreen()
}
bool Controller::checkForObstacles(void)
{
	bool collied;
	//Did the player run into a star, enemy ship, or space station?
	return collied;
}
void Controller::shutdown(void)
{
	//do all things to shutdown
}
void Controller::addUpObsticleCosts(void)
{
	/*ii.	Obstacles:  Did the player run into a star, enemy ship, or space station? If so, then:
	1.	Star: Player’s ship takes minor damage and stops in the sector before the star.
	2.	Enemy Ship: Player’s ship is attacked and damage is assessed.  Player may not actually be
	blocked (random condition). If blocked the player’s ship stops in the sector before the enemy ship, 
	otherwise, the player’s ship continues toward the target sector.
	3.	Space Station: The player docks with the space station (stops in the sector before the 
	space station’s sector) if the player’s ship has less than 10% of its maximum energy capacity or 
	has one or more failed critical systems.  Otherwise, the player’s ship continues toward the target sector.
	*/
}

void Controller::addUpObsticleDamage(void)
{
	/*i.	Obstacles: Does the missile run into a star, enemy ship, or space station? If so then:
	1.	Star:  There is a 90% chance the missile is destroyed, otherwise the missile continues toward the target.
	2.	Space Station: There is a 10% chance the missile and space station are destroyed, otherwise the missile continues
	toward the target. (Note: if a player destroys all his space stations, the game is over and the player loses.)
	3.	Enemy Ship: There is a 50% chance the missile and enemy ship are destroyed, otherwise the missile continues
	toward the target.
	ii.	Hit: If the missile makes it to the target, the computer calculates whether or not the enemy ship is destroyed.
	(see table in “Algorithms”)*/

	//use these to update damage to objects somehow
	enemies.update();
	stations.update();
	stars.update();


}
void Controller::longRangeScan(void)
{
	player.runLRS();
}
void Controller::moveProcess(void)
{
	// HUD2)
	//If the hyper drive has failed, the hyper drive button will be “greyed” out and will not work. 
	//Otherwise, the player left-clicks on hyper drive button and the galaxy map is displayed. 
	//left-clicks on hyper drive button  "from(UI2)"
	if(player.hyperdrive != false) 
	{



		// UI3)
		//The player left-clicks on a quadrant

		//gameControleState = UI.checkInput();
		//WHAT INPUT ????
		//The player left-clicks on a quadrant
		//The target quadrant is created with the
		//appropriate number of units (enemy ships, space station, stars). 
		makeQuads();

		//call renderer to showMAP ??
		renderer.displayGalaxyMap();


		if(player.SubLightEngines == false)
		{
			// HUD3)
			//the sub light engine indicator will indicate “damaged” 
			//no movement within the quadrant is possible

			//what player left clicks on 
			//getInput() from mouse


			switch(playerAltMove)
			{

			case STATION:
				//If a player left-clicks on a sector with a space station
				//the player moves to the sector next to the space station and docks with the space station
				player.dock();
				break;
			case STAR:
				// HUD4)
				//If the player left-clicks on a star
				//the player is given a warning of an illegal action and nothing else happens
				hud.illegalActionWarning();
				break;
			case ENEMY_SHIP:
				//Left-clicking on an enemy ship results in a missile attack on that ship
				//ship results in a missile attack on that ship
				player.missleAttack();
				break;
			case EMPTY_SECTOR:
				//if the player left-clicks on an empty target sector, the ship will move to that sector 
				//, the ship will move to that sector after the computer calculates the route to the target sector and determines

				//Does the player’s ship have enough fuel to make the move? 
				//If yes, check for obstacles.

				if(enoughFuel() == true)
				{
					

					//Did the player run into a star, enemy ship, or space station? 
					if(checkForObstacles()== true)
					{
						addUpObsticleCosts();
					}

					//player has a function that can have a target location??
					//controller calls it??
					player.moveToTargetSector();

				}
				if(enoughFuel() == false)
				{
					// HUD5)
					// warn the player with a “low fuel” alarm and borrow energy from the shields.
					//then see if fuel is still to low
					//if it is we ignore command
					if(enoughFuel() == false)
					{
						//ignore the command.
						//and the game waits for further orders from the player.
					}
				}
				//if SubLightEngines work then plaer warps to destination and 
				//and game wits for player to give new command
				//not 100% ontransition from here
				if(player.SubLightEngines == true)
				{

					//The new quadrant is displayed
					makeQuads();
					//call renderer to showMAP ??
					renderer.displayGalaxyMap();

					//and the game waits for further orders from the player.
					//UI.getInput()??
				}
				break;
			}


		}




	}
}

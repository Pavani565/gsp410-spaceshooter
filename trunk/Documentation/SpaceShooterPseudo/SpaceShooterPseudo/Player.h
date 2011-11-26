#pragma once

struct Player 
{
	//these are bools just for my psuedo code 
	//keep returns and flow simple
	
	bool	hyperdrive;
	bool	SubLightEngines;
	bool	criticalSystemsDamage;
	bool	longRangeScannerState;
	bool	blasterEnergyLevel;
	bool	blasters;
	bool	remainingMissiles;
	bool	missleLauncher;
	bool	sheilds;

	int fuel;

	void moveToTargetSector(void)
	{
		//move ship
	}

	void fireBlasters()
	{
		//fire blasters at target
	}

	void missleAttack(void)
	{
		/*b	Missiles: If the number of remaining missiles is zero or the missile launcher has failed,
		the missile launcher is “greyed” out and missiles cannot be fired.  Otherwise, to fire, 
		the player left-clicks on the targeted enemy ship. The computer calculates the route to 
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
	}

	void dock(void)
	{
		/*Docking: Since only one unit is allowed in each sector, 
		the player’s ship docks with a space station by stopping 
		in one of the eight adjacent squares around the space station.*/
	}


	void runLRS(void)
	{
		//left-clicking anywhere in the long range scan area will refresh the data.
		//long range scan
	}
	void AdjustBlasters(void)
	{
		// UI8)
		// HUD8) 
		//somehow player changes blasters
	}
	void updateSheilds()
	{
		//something to increase or decrease sheilds based on input??
		//If the shield’s energy is increased by 100, the ship’s energy is decreased by 100. 
	}
	bool systemsGood()
	{
		//somhow make sure everything still works or game is over
		bool system;
		return system;
	}
};

//SHEILDS
//Shields:  Energy based armor for the player’s ship.  Shields are also found on the space station.

//missiles
//Missile:  Projectile Weapons found only on the player’s ship.

//blasters  with energy level
//Blasters:  Energy weapons found on both player and enemy ships, although damage from enemy ships
//is calculated slightly differently from damage from the player’s ship.

//fuel
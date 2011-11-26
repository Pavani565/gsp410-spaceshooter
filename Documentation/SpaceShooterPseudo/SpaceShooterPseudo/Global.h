#pragma once

enum controllerState
{
	INTRO,RULES,PLAY,ENDGAME
};

enum commandState
{
	NONE,MOVE,LRS,
	FIREBLAST,FIREMISS,SHEILDS
};

enum altMoveState
{
	STATION,STAR,ENEMY_SHIP,EMPTY_SECTOR
};

////definitions

//Blasters:  Energy weapons found on both player and enemy ships, although damage from enemy ships is calculated 
//slightly differently from damage from the player’s ship.
//Docking: Since only one unit is allowed in each sector, the player’s ship docks with a space station by stopping in one of the eight adjacent squares around the space station.
//Enemy Ship:  This is a computer controlled unit.  Destroying all enemy ships in a specified number of turns is the game’s single victory condition.
//Galaxy:  The entire play area composed of 64 quadrants in an 8x8 grid.
//Missile:  Projectile Weapons found only on the player’s ship.
//Player’s Ship:  This is the only unit the player controls.
//Quadrants:  An area of the galaxy composed of 64 sectors in an 8x8 grid.
//Sectors:  The smallest unit of area in the game. A sector can hold only one of the following: an enemy ship, a space station, a star, or the player’s ship.  A sector can also be empty.
//Shields:  Energy based armor for the player’s ship.  Shields are also found on the space station.
//Space Station:  Refueling and repair base.  Docking at a space station instantly refuels the player’s ship.  Repairs proceed at a faster rate while docked. The player’s ship is fully protected by the space station’s shields while docked.
//Star:  Stars act as obstacles to both movement and missile firing.
//
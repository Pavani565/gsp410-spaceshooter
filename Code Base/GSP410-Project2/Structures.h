//Will Zepeda
//GSP-410
//SPACE SHOOTER
//Structures needed in space shooter
#pragma once

enum OCCUPATION_TYPE
{
	EMPTY, ENEMY, STATION, STAR, ME,
};
enum COMMAND_TYPE
{
	ADD_SHIELD_ENERGY,
	ADD_BLASTER_ENERGY,
	SUB_SHIELD_ENERGY,
	SUB_BLASTER_ENERGY,
	SCAN_LR,
	FIRE_BL,
	GALAXY_MAP,
};

//struct that holds row and column position (for 2D arrays)
struct RowCol
{
	int row;
	int col;
};

//Struct that holds how many ships, stars, and space stations 
//each quad has.
struct QuadInfo
{
	int		enemies;
	int		stars;
	int		spaceStations;
	bool	scanned;
};

//struct that determines commands in game
struct Command
{
	int		commandType;
	RowCol	sectorPos;
};
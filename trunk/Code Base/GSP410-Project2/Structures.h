//Will Zepeda
//GSP-410
//SPACE SHOOTER
//Structures needed in space shooter
#pragma once

//struct that holds row and column position (for 2D arrays)
struct RowCol
{
	int row;
	int col;
};

//Struct that holds how many ships, stars, and space stations 
//each quad has.
struct QuadData
{
	int		enemies;
	int		stars;
	int		spaceStations;
	bool	scanned;
	bool	shipWithin;
};

//struct that determines commands in game
struct Command
{
	int		commandType;
	RowCol	sectorPos;
};
// Various #defines used throughout the program //
#pragma once

#define WINDOW_CLASS	L"SpaceShooter"
#define WINDOW_TITLE	L"SpaceShooter"

#define WINDOWS_MODE	1		// Windowed(1) or Fullscreen(0) //

#define SCREEN_WIDTH	1366	// Screen Width Specification //
#define SCREEN_HEIGHT	768		// Screen Height Specifiation //

#define MAX_ENEMY_ENERGY			200
#define MAX_FRIENDLY_ENERGY			1000
#define MAX_FRIENDLY_SHIELD_ENERGY	1000
#define MAX_BLASTER_ENERGY			1000
#define MAX_NUMBER_MISSILES			10
#define GALAXY_SIZE					8
#define BUTTONS_AMOUNT				7

enum GAMESTATE
{
	MENU,GAMEOVER,DISPLAYGMAP,PLAY,
};
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
	EMPTY_SECTOR,
	ENEMY_SECTOR,
	STAR_SECTOR,
	STATION_SECTOR,
	GALAXY_MOVE,
	INVALID_COMMAND,
};

#define BUTTONS_AMOUNT				7
#define CLICKABLES_SIZE				BUTTONS_AMOUNT+GALAXY_SIZE*GALAXY_SIZE
//#define CLICKABLES_SIZE				72
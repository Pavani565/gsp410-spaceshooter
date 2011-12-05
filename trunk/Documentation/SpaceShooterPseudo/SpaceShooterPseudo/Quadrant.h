//Will Zepeda
//GSP-410
//Quadrant.h
//Class that holds all data a quadrant needs to init, update, and pass
//to renderer
#pragma once
#include "QuadInfo.h"
#include "Sector.h"

class Quadrant
{
public:
	//CEnemyUnit	enemies[3];
	//CFriendlyUnit friendly;
	//Star			star;
	//SpaceStation	spaceStation;
	Sector			galaxy[8][8];

private:
	Quadrant();

	void initQuad();

};

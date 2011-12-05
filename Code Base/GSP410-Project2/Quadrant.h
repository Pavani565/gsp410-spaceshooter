//Will Zepeda
//GSP-410
//Quadrant.h
//Class that holds all data a quadrant needs to init, update, and pass
//to renderer
#pragma once
#include "Structures.h"
#include "Sector.h"
#include "Unit.h"
#include "EnemyUnit.h"
#include "FriendlyUnit.h"

//MAKE INTO SINGLETON DESIGN
//needs to have firing mechanism that:
//	uses mouse x and y to determine who was clicked
//	needs attack function that calcs distances and whatnot
//	

class Quadrant
{
public:
	CEnemyUnit		enemies[3];
	CFriendlyUnit	friendly;
	//Star			star;
	CUnit			stars[3];
	//SpaceStation	spaceStation[3];
	Sector			quad[8][8];

	int				enemyIndex;
	int				starIndex;

private:
	Quadrant();

	//void initQuad();

	////////////////////////////////////////////////////////////////////////////
	//Class    : LoadQuad
	//Parameter: QuadInfo struct that consists of three ints that make up
	//         : the number of enemies, stars, and stations each quandrant should have
	//Return   : void
	//Job      : fills private data of current quadrant based on QuadInfo.
	//         : makes list of renderables and deletes renderable if it gets destroyed
	void LoadQuad(QuadInfo); 


};

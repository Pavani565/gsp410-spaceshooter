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

const int quadSize = 8;

class Quadrant
{
public:
	CEnemyUnit		mEnemies[3];
	CUnit			mStars[7];
	CFriendlyUnit	mFriendly;
	CUnit			mStation;
	Sector			mQuad[quadSize][quadSize];
	QuadData		mQuadData;

private:
	Quadrant();

	////////////////////////////////////////////////////////////////////////////
	//Class    : LoadQuad
	//Param1   : QuadData struct that consists of three ints that make up
	//         : the number of enemies, stars, and stations each quandrant should have
	//Job      : fills private data of current quadrant based on QuadData.
	//         : makes list of renderables and deletes renderable if it gets destroyed
	//Return   : void
	void LoadQuad(QuadData); 

	////////////////////////////////////////////////////////////////////////////
	//Class    : getEmptySector
	//Param1   : void
	//Job      : generates two random ints withing range of quadSize.
	//		   : uses those ints as indeces for a specific sector in mQuad.
	//		   : checks to see if that sector's mOccupiedType is EMPTY.
	//Return   : address of empty sector.
	Sector& getEmptySector();
};

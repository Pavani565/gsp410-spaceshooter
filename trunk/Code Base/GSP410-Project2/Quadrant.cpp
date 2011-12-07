//Will Zepeda
//GSP-410
//Quadrant.cpp
//Class that holds all data a quadrant needs to init, update, and pass
//to renderer
#include "Quadrant.h"

Quadrant::Quadrant()
{
	
}

void Quadrant::LoadQuad(QuadData aQuad)
{
	mQuadData = aQuad;

	//set all stuff


}

Sector& Quadrant::getEmptySector()
{
	//return NULL;
	return mQuad[0][0];
}
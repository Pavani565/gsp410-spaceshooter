//Will Zepeda
//GSP-410
//Quadrant.cpp
//Class that holds all data a quadrant needs to init, update, and pass
//to renderer
#include "Quadrant.h"
#include <time.h>

Quadrant::Quadrant()
{
	//gives each sector it's sector number
	//the purpose is to make it easier for Controller
	//to make a single Clickable array using the
	//sector number.
	int count = 0;
	for(int r = 0; r < quadSize; ++r)
	{
		for(int c = 0; c < quadSize; ++c)
		{
			mQuad[r][c].setSectorNum(count);
			count++;
		}
	}
}

void Quadrant::LoadQuad(QuadData aQuad)
{
	mQuadData = aQuad;

	//set all stuff
	m_NumberOfDrawables = mQuadData.enemies;
	for(int i = 0; i < m_NumberOfDrawables; i++)
	{
		m_Drawables[i] = &mEnemies[i];
	}
	int Count = m_NumberOfDrawables;
	m_NumberOfDrawables += mQuadData.stars;
	for(int i = 0; i < mQuadData.stars; i++, Count++)
	{
		m_Drawables[Count] = &mStars[i];
	}
	Count = m_NumberOfDrawables;
	m_NumberOfDrawables += mQuadData.spaceStations;
	for(int i = 0; i < mQuadData.spaceStations; i++, Count++)
	{
		m_Drawables[Count] = &mStation;
	}
	Count = m_NumberOfDrawables;
	m_NumberOfDrawables += 1; // for friendly ship
	m_Drawables[Count] = &mFriendly;

}

Sector& Quadrant::getSector(int aIndex)
{
	for(int r = 0; r < quadSize; ++r)
	{
		for(int c = 0; c < quadSize; ++c)
		{
			if(mQuad[r][c].getSectorNum() == aIndex)
				return mQuad[r][c];
		}
	}
	//had to return something for all return control paths.
	//i return the address of the first sector which should
	//mess everything up which is what i want to happen.
	//NOTE: IT SHOULD NEVER MESS UP but if it does, oh well.
	return mQuad[0][0];
}

Sector& Quadrant::getEmptySector()
{
	//: generates two random ints withing range of quadSize.
	int randRow, randCol;
	srand(timeGetTime());
	randRow = rand() % quadSize+1;
	srand(timeGetTime());
	randCol = rand() % quadSize+1;

	//: uses those ints as indeces for a specific sector in mQuad.
	//: checks to see if that sector's mOccupiedType is EMPTY.
	
	
	return mQuad[0][0];
}

void Quadrant::addBlasterEnergy1()
{
	mFriendly.IncrementShieldEnergy1();
}
void Quadrant::addBlasterEnergy10()
{
	mFriendly.IncrementShieldEnergy10();
}
void Quadrant::subBlasterEnergy1()
{
	mFriendly.DecrementBlasterEnergy1();
}
void Quadrant::subBlasterEnergy10()
{
	mFriendly.DecrementBlasterEnergy10();
}

void Quadrant::addShieldEnergy1()
{
	mFriendly.IncrementShieldEnergy1();
}
void Quadrant::addShieldEnergy10()
{
	mFriendly.IncrementShieldEnergy10();
}
void Quadrant::subShieldEnergy1()
{
	mFriendly.DecrementShieldEnergy1();
}
void Quadrant::subShieldEnergy10()
{
	mFriendly.DecrementShieldEnergy10();
}

bool Quadrant::fireBlasters()
{
	//check if blaster condition is ok
	//if true
		//get friendly's blaster energy level
		//divide number by how many enemies are active

	//if false
		return false;
	
	


}
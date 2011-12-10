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
			mQuad[r][c].setQuadPos(r,c);
			mQuad[r][c].setSectorNum(count);
			// Giving each sector its X and Y screen coords //
			mQuad[r][c].setSectorCoord(446+(64*r), 96+(64*c));
			mQuad[r][c].setOriginScale(1.0f);
			//	End											//
			count++;
		}
	}
}

void Quadrant::makeDrawableList()
{
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
	m_NumberOfDrawables += mQuadData.spaceStations;
	for(int i = 0; i < mQuadData.spaceStations; i++, Count++)
	{
		m_Drawables[Count] = &mStation;
	}
	m_NumberOfDrawables += 1; // for friendly ship
	m_Drawables[Count++] = &mFriendly;
}

void Quadrant::LoadQuad(QuadData aQuad)
{
	mQuadData = aQuad;

	makeDrawableList();

	//set postions of enemies, star, stations, and friendly
	//call get empty sector
	mFriendly.setSector(getEmptySector().getQuadPos());
	mFriendly.setX(mQuad[mFriendly.getSector().row][mFriendly.getSector().col].getSectorXCoord());
	mFriendly.setY(mQuad[mFriendly.getSector().row][mFriendly.getSector().col].getSectorYCoord());
	mQuad[mFriendly.getSector().row][mFriendly.getSector().col].setContent(ME);
	
	//place enemies in sectors and set those sectors to ENEMY and 
	for(int i = 0; i < mQuadData.enemies; ++i)
	{
		mEnemies[i].setSector(getEmptySector().getQuadPos());
		mEnemies[i].setX(mQuad[mEnemies[i].getSector().row][ mEnemies[i].getSector().col].getSectorXCoord());
		mEnemies[i].setY(mQuad[mEnemies[i].getSector().row][ mEnemies[i].getSector().col].getSectorYCoord());
		mQuad[mEnemies[i].getSector().row][ mEnemies[i].getSector().col].setContent(ENEMY, i);
	}

	for(int i = 0; i < mQuadData.stars; i++)
	{
		mStars[i].setSector(getEmptySector().getQuadPos());
		mStars[i].setX(mQuad[mStars[i].getSector().row][mStars[i].getSector().col].getSectorXCoord());
		mStars[i].setY(mQuad[mStars[i].getSector().row][mStars[i].getSector().col].getSectorYCoord());
		mQuad[mStars[i].getSector().row][mStars[i].getSector().col].setContent(STAR);
	}
	if(mQuadData.spaceStations > 0)
	{
		mStation.setSector(getEmptySector().getQuadPos());
		mStation.setX(mQuad[mStation.getSector().row][mStation.getSector().col].getSectorXCoord());
		mStation.setY(mQuad[mStation.getSector().row][mStation.getSector().col].getSectorYCoord());
		mQuad[mStation.getSector().row][mStation.getSector().col].setContent(STATION);
	}


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
	
	int randRow, randCol;
	randRow = randCol = -1;
	bool finished = false;
	//srand(timeGetTime());
	while(!finished)
	{
		//: generates two random ints withing range of quadSize.
		randRow = rand() % GALAXY_SIZE;
		randCol = rand() % GALAXY_SIZE;

		//: checks to see if that sector's mOccupiedType is EMPTY.
		if(!mQuad[randRow][randCol].isOccupied())
		{
			finished = true;
			//: uses those ints as indeces for a specific sector in mQuad.
			return mQuad[randRow][randCol];
		}

	}	
	return mQuad[randRow][randCol];
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

bool Quadrant::fireMissiles(Command cmd)
{

	return false;
}

bool Quadrant::moveFriendly(Command cmd)
{

	return false;
}

void Quadrant::moveEnemy()
{
	//call get emptySector

	//set enemy[index] to emptySector's position.

}

int Quadrant::destroyedEnemies()
{
	return 0;
}
int Quadrant::destoryedStations()
{
	return 0;
}
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
	mQuad[mFriendly.getSector().row][mFriendly.getSector().col].setOccupied(true);

	//place enemies in sectors and set those sectors to ENEMY and 
	for(int i = 0; i < mQuadData.enemies; ++i)
	{
		mEnemies[i].setSector(getEmptySector().getQuadPos());
		mEnemies[i].setX(mQuad[mEnemies[i].getSector().row][ mEnemies[i].getSector().col].getSectorXCoord());
		mEnemies[i].setY(mQuad[mEnemies[i].getSector().row][ mEnemies[i].getSector().col].getSectorYCoord());
		mQuad[mEnemies[i].getSector().row][mEnemies[i].getSector().col].setContent(ENEMY, i);
		mQuad[mEnemies[i].getSector().row][mEnemies[i].getSector().col].setOccupied(true);
	}

	for(int i = 0; i < mQuadData.stars; i++)
	{
		mStars[i].setSector(getEmptySector().getQuadPos());
		mStars[i].setX(mQuad[mStars[i].getSector().row][mStars[i].getSector().col].getSectorXCoord());
		mStars[i].setY(mQuad[mStars[i].getSector().row][mStars[i].getSector().col].getSectorYCoord());
		mQuad[mStars[i].getSector().row][mStars[i].getSector().col].setContent(STAR);
		mQuad[mStars[i].getSector().row][mStars[i].getSector().col].setOccupied(true);
	}
	if(mQuadData.spaceStations > 0)
	{
		mStation.setSector(getEmptySector().getQuadPos());
		mStation.setX(mQuad[mStation.getSector().row][mStation.getSector().col].getSectorXCoord());
		mStation.setY(mQuad[mStation.getSector().row][mStation.getSector().col].getSectorYCoord());
		mQuad[mStation.getSector().row][mStation.getSector().col].setContent(STATION);
		mQuad[mStation.getSector().row][mStation.getSector().col].setOccupied(true);
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
	mFriendly.IncrementBlasterEnergy1();
}
void Quadrant::addBlasterEnergy10()
{
	mFriendly.IncrementBlasterEnergy10();
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
	/*Energy weapon firing algorithm.
	Divide the power set for the energy weapon by the number of enemy ships in the quadrant. This is the energy (e1) used against each enemy ship. 
	Use the formula-- hit_energy =  e1 / (random(2 to 3) * (square_root(delta_row^2 + delta_column^2))  where delta_row and delta_column are the numbers of sector rows (or columns) between the enemy and friendly ship.
	if hit_energy is less than or equal to .15 * remaining enemy power, no damage is done.
	otherwise, enemy power = enemy power - hit_energy.
	If enemy power is less than or equal to zero, then the enemy is destroyed.
	*/



	//if blasters damage is 0 and  energy is more then 0 check enemies

	if(mFriendly.getBlasterCondition() == 0 && mFriendly.getBlasterEnergy() > 0)
	{
		//not sure if calling mQuadData is right
		for(int i = 0; i < mQuadData.enemies;i++)
		{	
			////e1 / (random(2 to 3) * (square_root(delta_row^2 + delta_column^2))
			

			//get friendly's blaster energy level
			//divide number by how many enemies are active
			float e1 = mFriendly.getBlasterEnergy()/mQuadData.enemies;
			
			//getting random
			int tempRand = (rand() %3) +2;
			
			//getting rows distance
			float dRTemp = mEnemies[i].getRow() - mFriendly.getRow();
			float delta_row = abs(dRTemp);
			//getting col distance
			float dCTemp = mEnemies[i].getCol() - mFriendly.getCol();
			float delta_col = abs(dCTemp);
			
			//delta_row^2
			delta_row = delta_row * delta_row;
			//delta_column^2
			delta_col = delta_col *  delta_col;
			//(delta_row^2 + delta_column^2)
			float deltas = delta_row + delta_col;
			//square_root(delta_row^2 + delta_column^2)
			float deltaSqrt =sqrt(deltas);
			//hit_energy =  e1 / (random(2 to 3) * (square_root(delta_row^2 + delta_column^2))
			float hit_energy = (e1/ tempRand) * deltaSqrt;

			//If the resulting number (hit value) is less than 15% of the remaining enemy power,
			//no damage is done, otherwise reduce the enemy power by the hit value.

			float targetAmount =  mEnemies[i].getShipEnergy()/15;

			if(hit_energy < targetAmount)
			{
				//report no damage
			}
			else
			{
				int shipDamage = (int)mEnemies[i].getShipEnergy() - hit_energy;
				mEnemies[i].setShipEnergry(shipDamage);
			}
			
			

			
			
		}
	}

	

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
void Quadrant::dockFriendly(Command cmd)
{
	//change cmd's sectorPos to one that is empty and next to station's sectorPos.
	
	if(moveFriendly(cmd))
	{
		//move friendly to sector next to station
	}
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
int Quadrant::destroyedStations()
{
	return 0;
}

CFriendlyUnit Quadrant::GetFriendlyUnit(void)
{
	return mFriendly;
}
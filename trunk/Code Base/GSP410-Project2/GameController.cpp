#include "GameController.h"

GameController::GameController()
{
	int randomChance = 0;
	bool isStationCreated = false;


	m_CurrentTurn = 0;

	srand(timeGetTime());
	m_GameTurns = (rand() %11)  + 25;

	for(int col = 0; col < GALAXY_SIZE;col++)
	{
		for(int row = 0; row < GALAXY_SIZE;row++)
		{
			randomChance = (rand() %100) +1;



			//enemies generation
			if(randomChance <= 2)
			{
				m_Galaxy[col][row].enemies = 3;
			}
			else
			{
				if(randomChance <= 5)
				{
					m_Galaxy[col][row].enemies = 2;
				}
				else
				{
					if(randomChance <= 20)
					{
						m_Galaxy[col][row].enemies = 1;
					}
					else
					{
						m_Galaxy[col][row].enemies = 0;
					}
				}
			}

			randomChance = (rand() %100) +1;
			//space stations generation
			if(randomChance <= 4)
			{
				isStationCreated = true;
				m_Galaxy[col][row].spaceStations = 1;
			}
			else
			{

				m_Galaxy[col][row].spaceStations = 0;
			}

			m_Galaxy[col][row].stars = rand() %8;
		}

	}
	if(isStationCreated == false)
	{
		int tempRow = (rand() %GALAXY_SIZE);
		int tempCol= (rand() %GALAXY_SIZE);

		m_Galaxy[tempCol][tempRow].spaceStations = 1;

		if(m_Galaxy[tempCol][tempRow].enemies < 3)
		{
			m_Galaxy[tempCol][tempRow].enemies++;
		}

	}

	//set player pos
	int tempRow = (rand() %GALAXY_SIZE);
	int tempCol= (rand() %GALAXY_SIZE);

	//temp way now
	m_Player.m_QuadCol = tempCol;
	m_Player.m_QuadRow = tempRow;

}



void GameController::UpdateGame(float DeltaTime)
{
	UserInput = CDirectInput::GetInstance();

	if(UserInput->KeyPressed(DIK_W))
	{
		m_Player.setY(m_Player.getY()+1);
	}

	if(UserInput->MouseClick(0))
	{
		m_Player.setX(m_Player.getX() + 1);
	}

}

GameController::~GameController()
{

}
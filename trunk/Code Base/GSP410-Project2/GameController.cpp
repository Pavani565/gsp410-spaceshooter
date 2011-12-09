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
	m_Player.setSector(tempRow, tempCol);

}



void GameController::UpdateGame(float DeltaTime)
{
	switch(m_Control_State)
	{
	case MENU:
		CheckInput();

		break;
	case GAMEOVER:
		CheckInput();
		ShowResults();
		break;
	case DISPLAYGMAP:
		CheckInput();
		break;
	case PLAY:
		CheckInput();
		Ex_Command();
		UpdateEnemies();

		break;
	}
}


GameController::~GameController()
{

}

void GameController::LoadTextures(void)
{

}

void GameController::CheckInput()
{

	//get the state so i know what input matters

	switch(m_Control_State)
	{
	case MENU:
		//posible mouse clicks
		//possible enter keyboard

		break;
	case GAMEOVER:
		//mouse
		//possible enter keyboard
		break;
	case DISPLAYGMAP:
		//possible enter keyboard
		break;
	case PLAY:
		//keyboard
		//mouseclicks
		/*for(int i = 0; i < BUTTONS_AMOUNT; i++)
		{
		m_Quad.mQuad[0][0].Clicked()
		}*/

		Clickable* clickArray[72];
		for(int i = 0; i < 8; ++i)
		{
			if(i < 7)
			{
				if(m_Buttons[i].Clicked(UserInput->getPosition(), &m_Command))
				{
					//check command for some shit

				}
			}

			for(int c = 0; i < quadSize; ++i)
			{
				if(m_Quad.mQuad[i][c].Clicked(UserInput->getPosition(), &m_Command))
				{
					//check command for some shit
				}
			}

		}

		if(UserInput->MouseClick(0))
		{
			for(i = 0; i< #ofclickables;i++)
			{
				if(clickable[i]->clicked(UserInput->getPosition(),&m_Command))
				{
					//check command
					switch(m_Command.commandType)
					{
					case ADD_SHIELD_ENERGY:
						m_Quad.addSheildEnergy1();				
						break;
					case ADD_BLASTER_ENERGY:
						//quad.addblaster
						break;
					case SUB_SHIELD_ENERGY:
						//quad.subEnerg
						break;
					case SUB_BLASTER_ENERGY:
						//quad.subblaster
						break;
					case SCAN_LR:
						//quad.addblaster
						break;
					case FIRE_BL:
						//quad.addblaster
						break;
					case GALAXY_MAP:
						//change game state 
						m_Control_State = DISPLAYGMAP;
						break;
					default:
						//if not any invalid
					}
				}
			}

		}
		if(UserInput->KeyDown(DIK_Q))
		{
			//subtract
			//m_Quad.subSheildEnergy10();
			//m_Quad.
		}
		if(UserInput->KeyDown(DIK_W))
		{
			//subtract
			m_Quad.addSheildEnergy10();
		}
		if(UserInput->KeyDown(DIK_A))
		{
			//subtract
			m_Quad.subBlasterEnergy10();
		}
		if(UserInput->KeyDown(DIK_S))
		{
			//subtract
			m_Quad.subBlasterEnergy10();
		}



	}



	//qwas keyboard
}

void GameController::ShowResults()
{

}

void GameController::UpdateEnemies()
{

}

void GameController::Ex_Command(int commandType)
{
	switch(commandType)
	{
	case EmptySector://Move Friendly (path check, starting sector, ending sector, access to the sectors)
		break;
	case EnemySector: //Shoot Enemy
		break;

	case StarSector: //Nothing (illegal warning)
		break;
	case StationSector: //Move Adjacently
		break;

	case AddShEnButton: //add energy to shield
		break;
	case AddBlEnButton: //add energy to blasters
		break;
	case SubShEnButton: //subtract energy from shield
		break;
	case SubBlEnButton: //subtract energy from blasters
		break;
	case SCAN_LRButton: //initiate long range scan
		break;
	case FIRE_BLButton: //fire the blasters
		break;
	case GlxyMapButton: //display galaxy map
		break;

	}
}

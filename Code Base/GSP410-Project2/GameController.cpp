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

	//fills clickable array with address of buttons and sectors

	for(int i = 0; i< CLICKABLES_SIZE;i++)
	{
		if(i < BUTTONS_AMOUNT)
		{
			mClickable[i] = &m_Buttons[i];
		}
		else
		{
			mClickable[i] = &m_ActiveQuad.getSector(i - BUTTONS_AMOUNT);
		}
	}

	for(int i = 0; i< BUTTONS_AMOUNT;i++)
	{
		m_Buttons[i].setButtonType(i);
	}

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
		//Ex_Command();
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

		

		if(UserInput->MouseClick(0))
		{
			for(int i = 0; i< CLICKABLES_SIZE;i++)
			{
				if(mClickable[i]->Clicked(UserInput->GetMousePosition(),m_Command))
				{
					//check command
					switch(m_Command.commandType)
					{
					case ADD_SHIELD_ENERGY:
						m_ActiveQuad.addShieldEnergy1();			
						break;
					case ADD_BLASTER_ENERGY:
						m_ActiveQuad.addBlasterEnergy1();		
						break;
					case SUB_SHIELD_ENERGY:
						//quad.subEnerg
						m_ActiveQuad.subShieldEnergy1();
						break;
					case SUB_BLASTER_ENERGY:
						m_ActiveQuad.subBlasterEnergy1();
						//quad.subblaster
						break;
					case SCAN_LR:
						//QuadData change scanned to true
						Scan();
						break;
					case FIRE_BL:						
						if(m_ActiveQuad.fireBlasters()==false)
						{
							//return a false 
						}
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
			m_ActiveQuad.subShieldEnergy10();
			//m_Quad.
		}
		if(UserInput->KeyDown(DIK_W))
		{
			//subtract
			m_ActiveQuad.addShieldEnergy10();
		}
		if(UserInput->KeyDown(DIK_A))
		{
			//subtract
			m_ActiveQuad.subBlasterEnergy10();
		}
		if(UserInput->KeyDown(DIK_S))
		{
			//subtract
			m_ActiveQuad.addBlasterEnergy10();
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



void GameController::Scan()
{
	for(int i = 0; i< GALAXY_SIZE;i++)
	{
		for(int j = 0; j < GALAXY_SIZE;j++)
		{
			if(m_Galaxy[i][j].shipWithin == true)
			{
				m_Galaxy[i][j].scanned = true;
				m_Galaxy[i-1][j-1].scanned = true;
				m_Galaxy[i][j-1].scanned = true;
				m_Galaxy[i-1][j].scanned = true;
				m_Galaxy[i+1][j].scanned = true;
				m_Galaxy[i-1][j+1].scanned = true;
				m_Galaxy[i][j+1].scanned = true;
				m_Galaxy[i+1][j+1].scanned = true;
				
			}
		}
	}
}
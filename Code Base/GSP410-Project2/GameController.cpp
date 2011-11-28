#include "GameController.h"
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
#pragma once

#include "Definitions.h"
#include "DirectInput.h"
#include "Unit.h"
#include "Renderable.h"
#include "FriendlyUnit.h"
#include "EnemyUnit.h"
#include "Structures.h"
#include "Button.h"
#include <time.h>

class GameController
{
private:
	CFriendlyUnit	m_Player;	// m_Player 1	//
	CEnemyUnit		m_Enemy[3];
	CUnit			m_Background;
	// an array of objects to draw;
	CRenderable*	m_Drawables;

	QuadData		m_Galaxy[GALAXY_SIZE][GALAXY_SIZE];

	Button			m_Buttons[BUTTONS_AMOUNT];

	CDirectInput*	UserInput;

	int				m_GameTurns;

	int				m_CurrentTurn;

public:

	GameController(void);
	~GameController(void);

	void UpdateGame(float DeltaTime);

	void LoadTextures(void);


};
#pragma once

#include "Definitions.h"
#include "DirectInput.h"
#include "Unit.h"
#include "Renderable.h"
#include "FriendlyUnit.h"
#include "EnemyUnit.h"
#include "Structures.h"
#include "Button.h"
#include "Quadrant.h"
#include <time.h>
#include "Quadrant.h"
#include "Clickable.h"

class GameController
{
private:
	CFriendlyUnit	m_Player;	// m_Player 1	//
	CEnemyUnit		m_Enemy[3];
	CUnit			m_Background;
	// an array of objects to draw;
	CRenderable*	m_Drawables;

	QuadData		m_Galaxy[GALAXY_SIZE][GALAXY_SIZE];

	//clickable
	Button			m_Buttons[BUTTONS_AMOUNT];

	CDirectInput*	UserInput;

	int				m_GameTurns;

	int				m_CurrentTurn;

	GAMESTATE		m_Control_State;

	Quadrant		m_ActiveQuad;

	Command			m_Command;

	Clickable*		mClickable[CLICKABLES_SIZE];



public:

	GameController(void);
	~GameController(void);

	void UpdateGame(float DeltaTime);

	void LoadTextures(void);

	void CheckInput();

	void ShowResults();

	void UpdateEnemies();

	void Scan();
};
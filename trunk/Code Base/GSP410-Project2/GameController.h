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

	int				m_TotalNumOfEnemies;
	int				m_TotalNumOfStations;

	// an array of objects to draw;

	QuadData		m_Galaxy[GALAXY_SIZE][GALAXY_SIZE];
	int				QuadRow, QuadCol; // our current quad

	//clickable
	Button			m_Buttons[BUTTONS_AMOUNT];

	CDirectInput*	UserInput;

	int				m_GameTurns;

	int				m_CurrentTurn;

	GAMESTATE		m_Control_State;

	Quadrant		m_ActiveQuad;

	Command			m_Command;

	Clickable*		mClickable[CLICKABLES_SIZE];

	int				m_QuadRow;
	int				m_QuadCol;



public:

	GameController(void);
	~GameController(void);

	void UpdateGame(float DeltaTime);

	void LoadTextures(void);

	void CheckInput();

	void ShowResults();

	void UpdateEnemies();

	CRenderable** GetRenderList(void);
	int			 GetRenderListNumber(void);

	void Scan();
	void Check_Win_Lose();
};
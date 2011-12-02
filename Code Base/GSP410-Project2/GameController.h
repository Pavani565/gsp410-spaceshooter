#pragma once

#include "Definitions.h"
#include "DirectInput.h"
#include "Unit.h"
#include "Renderable.h"
#include "FriendlyUnit.h"
#include "EnemyUnit.h"

class GameController
{
private:
	CFriendlyUnit	m_Player;	// m_Player 1	//
	CEnemyUnit		m_Enemy[3];
	CUnit			m_Background;

	

	CDirectInput*	UserInput;

public:

	void UpdateGame(float DeltaTime);

	void LoadTextures(void);
};
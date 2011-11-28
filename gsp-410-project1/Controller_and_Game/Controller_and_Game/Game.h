#pragma once
#include "MessObj.h"
#include "Model.h"

enum State 
{
	OCCUPIED,
	VACANT
};
class Game
{
public:

	State gameState;
	Model model;


	Game();
	~Game();

	MessObj update(MessObj);
	MessObj newGame(MessObj);
	MessObj endGame();

};
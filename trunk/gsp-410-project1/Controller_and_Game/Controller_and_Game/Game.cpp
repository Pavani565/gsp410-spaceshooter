#include "Game.h"

Game::Game()
{

}

Game::~Game()
{
	
}

MessObj Game::update(MessObj mess)
{
	MessObj  newMess;
	MessObj  errorMess;

	switch(gameState)
	{
	case OCCUPIED:
		newMess = model.update(mess);
		break;
	case VACANT:
		newMess = errorMess;
		break;
	}


	//send update in a MessObj
	return newMess;
}

MessObj Game::newGame(MessObj mess)
{
	//make new game using MessObj.num

	MessObj  newID;

	gameState = OCCUPIED;

	model.init(mess);

	//make a mess that confirms andsends back ID
	return newID;
}

MessObj Game::endGame()
{
	
	MessObj  newMess;

	//end game
	
	gameState = VACANT;

	//make mess that tells game ended

	return newMess;
}

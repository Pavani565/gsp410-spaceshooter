#pragma once
#include "COMM.h"
#include "Game.h"
#include "MessObj.h"

enum commState 
{
	CONNECTED,
	DISCONNECTED
};

class Controller
{

private:

//controlState (enum){connected, notconnected}

commState COMMSTATE;

COMM comm;
Game games[4];



public:

Controller();
~Controller();

MessObj checkQueForMess(void);
void getMess(MessObj);
MessObj updateGame(MessObj);
void  controlToComm(MessObj);
MessObj	initGame(MessObj);
void shutDown(void);
MessObj checkComStatus(MessObj);
MessObj update(MessObj);
MessObj endGame(MessObj);
MessObj comToControl(MessObj);

bool connected(MessObj);

};

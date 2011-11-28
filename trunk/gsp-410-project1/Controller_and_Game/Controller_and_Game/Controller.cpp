
#include "Controller.h"


Controller::Controller()
{

}

Controller::~Controller()
{

}

MessObj Controller::checkQueForMess(void)
{
	//check que

	//these are  just for psudo code errors
	char que = 0;
	MessObj info;
	MessObj nada;

	//real code

         if(que)
	{

		 getMess(info);

		return info;
	}
	else
	{
		return nada;
	}

	

	return info;
}
void Controller::getMess(MessObj mess)
{
	MessObj newInfo;
	
	//extract message to get Info
	////readMess()???

	switch(mess.info)
	{
	case 1:
	//message is user -> control (will & Jordon)
	newInfo = initGame(mess);
	break;

	case 2:
	//message user -> game (will & Jordon)
     newInfo = updateGame(mess);
	break;
	case 3:
	//message com -> controller
	newInfo = comToControl(mess);
	break;
	case 4:
	//message is user -> control
	newInfo  = endGame(mess);
	break;
	}
	
	

	controlToComm(newInfo);


}



MessObj Controller::updateGame(MessObj mess)
{
	MessObj newInfo;

	switch (mess.info)
	{
	case 1:
		//for game 1
		//send messege to game 1
		newInfo = games[mess.num].update(mess);
			break;
	case 2: 
		//for game 2
		//send messege to game 2
		newInfo = games[mess.num].update(mess);
			break;
	case 3: 
		//for game 3
		//send messege to game 3
		newInfo = games[mess.num].update(mess);
			break;
	case 4:
		//for game 4
		//send messege to game 4
		newInfo = games[mess.num].update(mess);
			break;
	}

	

	//pack newInfo somehow into message
	//to go ->comm->user
	return newInfo;

}

MessObj comToControl(MessObj)  //kevin
{
	//Do somethng that is related to comm
	//or that comm is requesting

	//then send a mess back
	//message com -> controller
	//controlToComm()??
	MessObj newInfo;
	return newInfo;

}


void  Controller::controlToComm(MessObj)	//kevin
{
	//send mess??
	//transaction
}


MessObj	Controller::initGame(MessObj info)
{
	MessObj newInfo;
	MessObj allGamesBusy;
	MessObj error;

	//use num to give to game as an ID
	//send back to com to goto u/I for num request??
	//message com -> controller
	//controlToComm()??

	//check game[] array and see if any are available
	//loop
	//if a game is notPlaying then call it's initgame function	
	for(int i = 0; i < 4;i++)
	{
		if(games[i].gameState == VACANT)
		{
			newInfo = games[i].newGame(info);
			return newInfo;
		}
		else
		{
			//what if all games are full?????
			newInfo = error;
			
		}
	}
	
	return newInfo;
	
}




void Controller::shutDown()
{
	MessObj  newInfo;
	MessObj errors;

	

	//send back to com that game is terminated
	
	//message com -> controller
	
	for(int i = 0; i < 4; i++)
	{
		newInfo = games[i].endGame();

		controlToComm(newInfo);
	}


	
}





MessObj Controller::checkComStatus(MessObj mess)
{
	//check with com 

	MessObj newMess;

	if (connected(mess))
	{
	   COMMSTATE = CONNECTED;

	   //tell em was up
	   return newMess;
	   
	}
	else
	{
	   COMMSTATE = DISCONNECTED;	

	   //tell em was up
	   return newMess;
	}
}




MessObj Controller::update(MessObj mess)
{
	MessObj newMess;

	switch(COMMSTATE)
	{

	case CONNECTED:

		newMess = checkComStatus(mess);

		newMess = checkQueForMess();

		

		break;


	case DISCONNECTED:

		newMess = checkComStatus(mess);


		shutDown();


	

		break;

	}
		return newMess; 
}

MessObj Controller::comToControl(MessObj mess)
{
	return mess;
}
MessObj Controller::endGame(MessObj mess)
{
	MessObj newMess;

	switch(mess.num)
	{
	case 1:	
		newMess = games[mess.num].endGame();
		break;
	case 2 :
		newMess = games[mess.num].endGame();
		break;
	case 3: 
		newMess = games[mess.num].endGame();
		break;
	case 4: 
		newMess = games[mess.num].endGame();
		break;
	}

	return newMess;

}

bool Controller::connected(MessObj mess)
{
	bool status = mess.status;

	return status;
}
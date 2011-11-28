#pragma once
#include "MessObj.h"

class Model
{
public:

	

	MessObj	init(MessObj)
	{
		MessObj newMess;
		return newMess;
	}

	MessObj update(MessObj mess)
	{
		MessObj newMess;

		newMess = calculate(mess);

		return newMess;
	}

	MessObj calculate(MessObj mess)
	{
		MessObj newMess;

		//take mess MessObj and use members to update current members
		//then return update in a messObj

		return newMess;
	}
};
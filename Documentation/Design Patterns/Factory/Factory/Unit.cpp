#include "StdAfx.h"
#include <string>
#include "Unit.h"

Unit::Unit(void)
{
}

Unit::~Unit(void)
{
}

int Unit::getID()
{
	return ID;
}

std::string Unit::getRace()
{
	return Race;
}

std::string Unit::getType()
{
	return Type;
}

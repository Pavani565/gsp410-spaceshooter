#include "Unit.h"

CUnit::CUnit(void)
{
	m_X = 0;
	m_Y = 0;
}

void CUnit::setX(int newX)
{
	this->m_X = newX;
}
void CUnit::setY(int newY)
{
	this->m_Y = newY;
}
int CUnit::getX(void)
{
	return this->m_X;
}
int CUnit::getY(void)
{
	return this->m_Y;
}

CUnit::~CUnit(void)
{
	m_X = 0;
	m_Y = 0;
}
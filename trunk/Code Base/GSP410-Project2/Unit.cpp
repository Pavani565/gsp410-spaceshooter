#include "Unit.h"

CUnit::CUnit(void)
{
	m_X = 0;
	m_Y = 0;
	UnitTexture = 0;
}

void CUnit::setX(int newX)
{
	this->m_X = newX;
}
void CUnit::setY(int newY)
{
	this->m_Y = newY;
}
void CUnit::setTexturePointer(IDirect3DTexture9* TextureAddress)
{
	this->UnitTexture = TextureAddress;
}
int CUnit::getX(void)
{
	return this->m_X;
}
int CUnit::getY(void)
{
	return this->m_Y;
}
IDirect3DTexture9* CUnit::getTexturePointer(void)
{
	return this->UnitTexture;
}

CUnit::~CUnit(void)
{
	m_X = 0;
	m_Y = 0;
	UnitTexture = 0;
}
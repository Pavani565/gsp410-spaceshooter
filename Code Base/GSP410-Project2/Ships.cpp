#include "Ships.h"

void CParentShip::setHealth(int newHealth)
{
	this->m_Health = newHealth;
}
void CParentShip::setX(int newX)
{
	this->m_X = newX;
}
void CParentShip::setY(int newY)
{
	this->m_Y = newY;
}
int CParentShip::getHealth(void)
{
	return this->m_Health;
}
int CParentShip::getX(void)
{
	return this->m_X;
}
int CParentShip::getY(void)
{
	return this->m_Y;
}

void Cm_PlayerShip::setBlasterEnergy(int newBlasterEnergy)
{
	this->m_BlasterEnergy = newBlasterEnergy;
}
void Cm_PlayerShip::setMissilesToFire(int NumberOfMissiles)
{
	this->m_MissilesToFire = NumberOfMissiles;
}
void Cm_PlayerShip::setShieldEnergy(int newShieldEnergy)
{
	this->m_ShieldEnergy = newShieldEnergy;
}
void Cm_PlayerShip::setShipEnergy(int newShipEnergy)
{
	this->m_ShipEnergy = newShipEnergy;
}
int Cm_PlayerShip::getBlasterEnergy(void)
{
	return this->m_BlasterEnergy;
}
int Cm_PlayerShip::getMissilesToFire(void)
{
	return this->m_MissilesToFire;
}
int Cm_PlayerShip::getShieldEnergy(void)
{
	return this->m_ShieldEnergy;
}
int Cm_PlayerShip::getShipEnergy(void)
{
	return this->m_ShipEnergy;
}
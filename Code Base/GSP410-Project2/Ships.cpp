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

void CPlayerShip::setBlasterEnergy(int newBlasterEnergy)
{
	this->m_BlasterEnergy = newBlasterEnergy;
}
void CPlayerShip::setMissilesToFire(int NumberOfMissiles)
{
	this->m_MissilesToFire = NumberOfMissiles;
}
void CPlayerShip::setShieldEnergy(int newShieldEnergy)
{
	this->m_ShieldEnergy = newShieldEnergy;
}
void CPlayerShip::setShipEnergy(int newShipEnergy)
{
	this->m_ShipEnergy = newShipEnergy;
}
int CPlayerShip::getBlasterEnergy(void)
{
	return this->m_BlasterEnergy;
}
int CPlayerShip::getMissilesToFire(void)
{
	return this->m_MissilesToFire;
}
int CPlayerShip::getShieldEnergy(void)
{
	return this->m_ShieldEnergy;
}
int CPlayerShip::getShipEnergy(void)
{
	return this->m_ShipEnergy;
}
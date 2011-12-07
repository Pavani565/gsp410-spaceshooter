#include "FriendlyUnit.h"
#include "Definitions.h"

const int CFriendlyUnit::m_MaxShipEnergy	= MAX_FRIENDLY_ENERGY;
const int CFriendlyUnit::m_MaxShieldEnergy	= MAX_FRIENDLY_SHIELD_ENERGY;
const int CFriendlyUnit::m_MaxBlasterEnergy	= MAX_BLASTER_ENERGY;
const int CFriendlyUnit::m_MaxMissiles		= MAX_NUMBER_MISSILES;	

CFriendlyUnit::CFriendlyUnit(void)
{
	m_ShipEnergy = m_MaxShipEnergy;
	m_ShieldEnergy = 0;
	m_BlasterEnergy = 0;
	m_NumberOfMissiles = 0;

	m_ShieldCondition = 0;
	m_BlasterCondition = 0;
	m_MissileCondition = 0;
	m_SEngineCondition = 0;
	m_HEngineCondition = 0;
}
CFriendlyUnit::~CFriendlyUnit()
{

}
void CFriendlyUnit::setBlasterEnergy(int newBlasterEnergy)
{
	this->m_BlasterEnergy = newBlasterEnergy;
}
void CFriendlyUnit::setMissilesToFire(int NumberOfMissiles)
{
	this->m_MissilesToFire = NumberOfMissiles;
}
void CFriendlyUnit::setShieldEnergy(int newShieldEnergy)
{
	this->m_ShieldEnergy = newShieldEnergy;
}
void CFriendlyUnit::setShipEnergy(int newShipEnergy)
{
	this->m_ShipEnergy = newShipEnergy;
}
void CFriendlyUnit::setShieldCondition(int newShieldCondition)
{
	this->m_ShieldCondition = newShieldCondition;
}
void CFriendlyUnit::setBlasterCondition(int newBlasterCondition)
{
	this->m_BlasterCondition = newBlasterCondition;
}
void CFriendlyUnit::setMissileCondition(int newMissileCondition)
{
	this->m_MissileCondition = newMissileCondition;
}
void CFriendlyUnit::setSubLightCondition(int newSubLightCondition)
{
	this->m_SEngineCondition = newSubLightCondition;
}
void CFriendlyUnit::setHyperDriveCondition(int newHyperDriveCondition)
{
	this->m_HEngineCondition = newHyperDriveCondition;
}

int CFriendlyUnit::getBlasterEnergy(void)
{
	return this->m_BlasterEnergy;
}
int CFriendlyUnit::getMissilesToFire(void)
{
	return this->m_MissilesToFire;
}
int CFriendlyUnit::getShieldEnergy(void)
{
	return this->m_ShieldEnergy;
}
int CFriendlyUnit::getShipEnergy(void)
{
	return this->m_ShipEnergy;
}
int CFriendlyUnit::getShieldCondition(void)
{
	return this->m_ShieldCondition;
}
int CFriendlyUnit::getBlasterCondition(void)
{
	return this->m_BlasterCondition;
}
int CFriendlyUnit::getMissileCondition(void)
{
	return this->m_MissileCondition;
}
int CFriendlyUnit::getSubLightCondition(void)
{
	return this->m_ShieldCondition;
}
int CFriendlyUnit::getHyperDriveCondition(void)
{
	return this->m_HEngineCondition;
}



IDirect3DTexture9* CFriendlyUnit::GetTexture(void)
{
	return NULL;
}
RECT CFriendlyUnit::GetRect(void)
{
	RECT temp;
	return temp;
}
D3DXVECTOR3 CFriendlyUnit::GetCenter(void)
{
	D3DXVECTOR3 temp;
	return temp;
}
D3DCOLOR CFriendlyUnit::GetColor(void)
{
	return NULL;
}
float CFriendlyUnit::GetScale(void)
{
	return NULL;
}
float CFriendlyUnit::GetRotation(void)
{
	return NULL;
}
D3DXVECTOR3 CFriendlyUnit::GetPosition(void)
{
	D3DXVECTOR3 temp;
	return temp;
}
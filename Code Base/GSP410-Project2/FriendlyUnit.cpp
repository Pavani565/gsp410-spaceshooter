#include "FriendlyUnit.h"
#include "Definitions.h"

const int CFriendlyUnit::m_MaxShipEnergy	= MAX_FRIENDLY_ENERGY;
const int CFriendlyUnit::m_MaxShieldEnergy	= MAX_FRIENDLY_SHIELD_ENERGY;
const int CFriendlyUnit::m_MaxBlasterEnergy	= MAX_BLASTER_ENERGY;
const int CFriendlyUnit::m_MaxMissiles		= MAX_NUMBER_MISSILES;	

CFriendlyUnit::CFriendlyUnit(void)
{
	m_ShipEnergy		= m_MaxShipEnergy;
	m_ShieldEnergy		= 0;
	m_BlasterEnergy		= 0;
	m_NumberOfMissiles	= 10;

	m_ShieldCondition	= 0;
	m_BlasterCondition	= 0;
	m_MissileCondition	= 0;
	m_SEngineCondition	= 0;
	m_HEngineCondition	= 0;
}
CFriendlyUnit::~CFriendlyUnit()
{

}
void CFriendlyUnit::setBlasterEnergy(int newBlasterEnergy)
{
	m_BlasterEnergy = newBlasterEnergy;
}
void CFriendlyUnit::setMissiles(int NumberOfMissiles)
{
	m_NumberOfMissiles = NumberOfMissiles;
}
void CFriendlyUnit::IncrementShieldEnergy1(void)
{
	if(m_ShipEnergy > 0)
	{
		m_ShieldEnergy++;
		m_ShipEnergy--;
	}
}
void CFriendlyUnit::IncrementShieldEnergy10(void)
{
	// Do not let the player kill themselves quickly? //
	if(m_ShipEnergy >= 11)
	{
		m_ShieldEnergy+=10;
		m_ShipEnergy-=10;
	}
}
void CFriendlyUnit::DecrementShieldEnergy1(void)
{
	if(m_ShieldEnergy > 0)
	{
		m_ShieldEnergy--;
		m_ShipEnergy++;
	}
}
void CFriendlyUnit::DecrementShieldEnergy10(void)
{
	if(m_ShieldEnergy >= 10)
	{
		m_ShieldEnergy-=10;
		m_ShipEnergy+=10;
	}
}
void CFriendlyUnit::IncrementBlasterEnergy1(void)
{
	if(m_ShipEnergy > 0)
	{
		m_BlasterEnergy++;
		m_ShipEnergy--;
	}
}
void CFriendlyUnit::IncrementBlasterEnergy10(void)
{
	// Do not let the player kill themselves quickly? //
	if(m_ShipEnergy >= 11)
	{
		m_BlasterEnergy+=10;
		m_ShipEnergy-=10;
	}
}
void CFriendlyUnit::DecrementBlasterEnergy1(void)
{
	if(m_BlasterEnergy > 0)
	{
		m_BlasterEnergy--;
		m_ShipEnergy++;
	}
}
void CFriendlyUnit::DecrementBlasterEnergy10(void)
{
	if(m_BlasterEnergy >= 10)
	{
		m_BlasterEnergy-=10;
		m_ShipEnergy+=10;
	}
}
void CFriendlyUnit::DecrementMissileCount(void)
{
	if(m_NumberOfMissiles>0)
	{
		m_NumberOfMissiles--;
	}
}
void CFriendlyUnit::setShieldEnergy(int newShieldEnergy)
{
	m_ShieldEnergy = newShieldEnergy;
}
void CFriendlyUnit::setShipEnergy(int newShipEnergy)
{
	m_ShipEnergy = newShipEnergy;
}
void CFriendlyUnit::setShieldCondition(int newShieldCondition)
{
	m_ShieldCondition = newShieldCondition;
}
void CFriendlyUnit::setBlasterCondition(int newBlasterCondition)
{
	m_BlasterCondition = newBlasterCondition;
}
void CFriendlyUnit::setMissileCondition(int newMissileCondition)
{
	m_MissileCondition = newMissileCondition;
}
void CFriendlyUnit::setSubLightCondition(int newSubLightCondition)
{
	m_SEngineCondition = newSubLightCondition;
}
void CFriendlyUnit::setHyperDriveCondition(int newHyperDriveCondition)
{
	m_HEngineCondition = newHyperDriveCondition;
}

int CFriendlyUnit::getBlasterEnergy(void)
{
	return m_BlasterEnergy;
}
int CFriendlyUnit::getMissiles(void)
{
	return m_NumberOfMissiles;
}
int CFriendlyUnit::getShieldEnergy(void)
{
	return m_ShieldEnergy;
}
int CFriendlyUnit::getShipEnergy(void)
{
	return m_ShipEnergy;
}
int CFriendlyUnit::getShieldCondition(void)
{
	return m_ShieldCondition;
}
int CFriendlyUnit::getBlasterCondition(void)
{
	return m_BlasterCondition;
}
int CFriendlyUnit::getMissileCondition(void)
{
	return m_MissileCondition;
}
int CFriendlyUnit::getSubLightCondition(void)
{
	return m_ShieldCondition;
}
int CFriendlyUnit::getHyperDriveCondition(void)
{
	return m_HEngineCondition;
}
#include "EnemyUnit.h"
#include "Definitions.h"

const int CEnemyUnit::m_MaxEnergy = MAX_ENEMY_ENERGY;

CEnemyUnit::CEnemyUnit(void)
{
	m_ShipEnergy = m_MaxEnergy;
}

void CEnemyUnit::setShipEnergry(int newShipEnergy)
{
	// Built-In Error Checking //
	if(newShipEnergy <= m_MaxEnergy && newShipEnergy >= 0)
	{
		m_ShipEnergy = newShipEnergy;
		return;
	}
	if(newShipEnergy < 0)
	{
		m_ShipEnergy = 0;
		return;
	}
	if(newShipEnergy > m_MaxEnergy)
		m_ShipEnergy = m_MaxEnergy;
}
void CEnemyUnit::setCombatStateOn(void)
{
	m_CombatState = true;
}
void CEnemyUnit::setCombatStateOff(void)
{
	m_CombatState = false;
}


int CEnemyUnit::getShipEnergy(void)
{
	return m_ShipEnergy;
}
bool CEnemyUnit::getCombatState(void)
{
	return m_CombatState;
}

CEnemyUnit::~CEnemyUnit(void)
{
	m_ShipEnergy = 0;
}
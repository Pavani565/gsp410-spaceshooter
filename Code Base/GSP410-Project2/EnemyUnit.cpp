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
		this->m_ShipEnergy = newShipEnergy;
		return;
	}
	if(newShipEnergy < 0)
	{
		this->m_ShipEnergy = 0;
		return;
	}
	if(newShipEnergy > m_MaxEnergy)
		this->m_ShipEnergy = m_MaxEnergy;
}

int CEnemyUnit::getShipEnergy(void)
{
	return this->m_ShipEnergy;
}

CEnemyUnit::~CEnemyUnit(void)
{
	m_ShipEnergy = 0;
}
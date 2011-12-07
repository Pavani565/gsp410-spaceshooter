#pragma once
#include "Unit.h"

class CEnemyUnit : public CUnit
{
private:
	// Enemy Unit Variables									//
	int m_ShipEnergy;	// The Enemy Unit's Shield's Energy	//
	bool m_CombatState; // The Enemy Unit's Combat State	//
public:
	// Enemy Unit Constants													//
	static const int m_MaxEnergy;	// Max Energy An Enemy Unit Can Have	//

	// Set Functions For Enemy Unit //
	void setShipEnergry(int newShipEnergy);
	void setCombatStateOn(void);
	void setCombatStateOff(void);

	// Get Functions For Enemy Unit //
	int getShipEnergy(void);
	bool getCombatState(void);

	// Constructor & Destructor//
	CEnemyUnit(void);
	~CEnemyUnit(void);
};
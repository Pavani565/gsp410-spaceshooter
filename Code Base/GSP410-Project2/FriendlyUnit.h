#pragma once
#include "Unit.h"
#include "Renderable.h"

class CFriendlyUnit : public CUnit
{
private:
	// Player Modifiable Variables											//
	int m_ShipEnergy;		// Amount of Energy the ship has				//
	int m_ShieldEnergy;		// Amount of Energy allotted to the shields		//
	int m_BlasterEnergy;	// Amount of Energy allotted to the blasters	//
	int m_NumberOfMissiles; // Amount of Missiles the ship has				//

	// Game Modifiable Variables									//
	int m_ShieldCondition;	// Condition of the Shield Generator	//
	int m_BlasterCondition;	// Condition of the Blaster	Launcher	//
	int m_MissileCondition;	// Condition of the Missile Launcher	//
	int m_SEngineCondition; // Condition of the Sub-Light Engine	//
	int m_HEngineCondition;	// Condition of the Hyper-Drive Engine	//
	//roll the dice to figure out how many turns it will take in accordance with GDD
	

public:

	// Constructor & Destructor
	CFriendlyUnit(void);
	~CFriendlyUnit(void);

	// Game Constants																					//
	static const int m_MaxShipEnergy;	// Maximum amount of Energy the ship can have					//
	static const int m_MaxShieldEnergy;	// Maximum amount of Energy that can be allotted to the Shield	//
	static const int m_MaxBlasterEnergy;// Maximum amount of Energy that can be allotted to the Blaster	//
	static const int m_MaxMissiles;		// Maximum amount of Missiles that can be on the Ship			//

	// Set Functions For Player Modifiable Variables //
	void setShipEnergy(int newShipEnergy);
	void setShieldEnergy(int newShieldEnergy);
	void setBlasterEnergy(int newBlasterEnergy);
	void setMissiles(int newNumberOfMissiles);

	void IncrementShieldEnergy1(void);	// Shield	//
	void IncrementShieldEnergy10(void);
	void DecrementShieldEnergy1(void);
	void DecrementShieldEnergy10(void);
	void IncrementBlasterEnergy1(void);	// Blaster	//
	void IncrementBlasterEnergy10(void);
	void DecrementBlasterEnergy1(void);
	void DecrementBlasterEnergy10(void);
	void DecrementMissileCount(void);	// Missile	//

	// Set Functions For Game Modifiable Variables //
	void setShieldCondition(int newShieldCondition);
	void setBlasterCondition(int newBlasterCondition);
	void setMissileCondition(int newMissileCondition);
	void setSubLightCondition(int newSubLightCondition);
	void setHyperDriveCondition(int newHyperDriveCondition);

	// Get Function For Player Modifiable Variables //
	int getShipEnergy(void);
	int getShieldEnergy(void);
	int getBlasterEnergy(void);
	int getMissiles(void);

	// Get Functions For Game Modifiable Variables //
	int getShieldCondition(void);
	int getBlasterCondition(void);
	int getMissileCondition(void);
	int getSubLightCondition(void);
	int getHyperDriveCondition(void);
};
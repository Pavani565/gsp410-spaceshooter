#pragma once

class CParentShip
{
private:
	int m_X;		// X position on Screen //
	int m_Y;		// Y position on Screen //
	int m_Health;	// Health of the ship	//
public:
	void setX(int newX);
	void setY(int newY);
	void setHealth(int newHealth);

	int getX(void);
	int getY(void);
	int getHealth(void);
};

class Cm_PlayerShip : public CParentShip
{
private:
	int m_ShipEnergy;		// Amount of Energy the ship has				//
	int m_ShieldEnergy;		// Amount of Energy allotted to the shields		//
	int m_BlasterEnergy;	// Amount of Energy allotted to the blasters	//
	int m_MissilesToFire;	// Number of Missiles to Shoot					//

	static const int m_MaxShipEnergy = 1000;		// Maximum amount of Energy the ship can have					//
	static const int m_MaxShieldEnergy = 1000;		// Maximum amount of Energy that can be allotted to the Shield	//
	static const int m_MaxBlasterEnergy = 1000;	// Maximum amount of Energy that can be allotted to the Blaster	//
	static const int m_MaxMissiles = 10;			// Maximum amount of Missiles that can be on the Ship			//

	int ShieldCondition;	// Condition of the Shield Generator	//
	int BlasterCondition;	// Condition of the Blaster	Launcher	//
	int MissileCondition;	// Condition of the Missile Launcher	//

public:
	void setShipEnergy(int newShipEnergy);
	void setShieldEnergy(int newShieldEnergy);
	void setBlasterEnergy(int newBlasterEnergy);
	void setMissilesToFire(int newNumberOfMissiles);

	int getShipEnergy(void);
	int getShieldEnergy(void);
	int getBlasterEnergy(void);
	int getMissilesToFire(void);
};

class CEnemyShip : public CParentShip
{

};
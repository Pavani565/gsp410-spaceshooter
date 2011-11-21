#pragma once
#include <string>
class Unit
{
public:
	Unit(void);
	~Unit(void);
	virtual void attack() = 0;
	virtual void defend() = 0;
	virtual void loot() = 0;
	virtual void displayInventory() = 0;
	virtual std::string status() = 0;
	int getID();
	std::string getRace();
	std::string getType();

protected:
	std::string Race;
	std::string Type;
	int ID;
};

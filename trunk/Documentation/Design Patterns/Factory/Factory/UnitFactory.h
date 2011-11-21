#pragma once

class UnitFactory
{
public:
	UnitFactory(void);
	~UnitFactory(void);
	virtual Unit* createThief() = 0;
	virtual Unit* createWarrior() = 0;
	virtual Unit* createMage() = 0;
	virtual Unit* createUnit(int) = 0;
protected:
	int IDCount;
};

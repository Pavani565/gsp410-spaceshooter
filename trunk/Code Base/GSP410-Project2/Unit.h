#pragma once 

class CUnit
{
private:
	// General Unit Variables			//
	int m_X;	// X position on Screen //
	int m_Y;	// Y position on Screen //
public:
	// General Unit Set Functions //
	void setX(int newX);
	void setY(int newY);

	// General Unit Get Functions //
	int getX(void);
	int getY(void);

	// Constructor & Destructor //
	CUnit(void);
	~CUnit(void);
};
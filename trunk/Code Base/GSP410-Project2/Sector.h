//Will Zepeda
//GSP-410
//Sector.h
//sectors that make up a quadrant
#include "Clickable.h"

//what do they need?
//NEEDS TO BE DERIVED FROM CLICKABLE
//NEEDS TO KNOW IF IT WAS CLICKED
//#include "Structures.h"

class Sector : public Clickable
{
private:
	bool	occupied;
	//XYZ	screenPosition;
	RowCol	quadPos;
	int		occupiedType;
public:
	Sector();
	void	setContent(int);
	void	setOriginScale(float); //occupied type that's in sector
	Command virtual Clicked(POINT);

	/**
	* sets/gets
	**/

	//void setOccupation(int);
	//int	 occupiedWith(){ return type; }
};
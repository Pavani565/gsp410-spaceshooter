//Will Zepeda
//GSP-410
//Sector.h
//sectors that make up a quadrant

//what do they need?

class Sector
{
private:
	bool	occupied;
	int		x;
	int		y;
	int		z;
public:
	Sector();
	bool isOccupied(){ return occupied; }
};
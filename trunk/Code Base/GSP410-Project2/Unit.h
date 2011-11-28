#pragma once 
#include <d3dx9.h>

class CUnit
{
private:
	// General Unit Variables			//
	int m_X;	// X position on Screen //
	int m_Y;	// Y position on Screen //
	IDirect3DTexture9* UnitTexture;
	
public:
	// General Unit Set Functions //
	void setX(int newX);
	void setY(int newY);
	void setTexturePointer(IDirect3DTexture9* TextureAddress);

	// General Unit Get Functions //
	int getX(void);
	int getY(void);
	IDirect3DTexture9* getTexturePointer(void);

	// Constructor & Destructor //
	CUnit(void);
	~CUnit(void);
};
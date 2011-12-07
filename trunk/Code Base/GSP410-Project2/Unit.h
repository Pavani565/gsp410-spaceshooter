#pragma once 
#include <d3dx9.h>

class CUnit
{
private:
	// General Unit Variables			//
	int m_X;	// X position on Screen //
	int m_Y;	// Y position on Screen //
	float 
	IDirect3DTexture9*	m_UnitTexture;
	D3DXIMAGE_INFO		m_TextureInfo;
	
public:
	// General Unit Set Functions //
	void setX(int newX);
	void setY(int newY);
	void setTexturePointer(IDirect3DTexture9* TextureAddress);
	void setTextureInfo(D3DXIMAGE_INFO TextureInformation);

	// General Unit Get Functions //
	int getX(void);
	int getY(void);
	IDirect3DTexture9*	getTexturePointer(void);
	D3DXIMAGE_INFO		getTextureInfo(void);

	//bool Clicked(int MouseX, int MouseY);

	// Constructor & Destructor //
	CUnit(void);
	~CUnit(void);
};
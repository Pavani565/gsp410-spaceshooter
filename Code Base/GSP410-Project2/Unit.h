#pragma once 
#include <d3dx9.h>
#include "Structures.h"
#include "Renderable.h"
class CUnit : public virtual CRenderable
{
protected:
	// General Unit Variables			//
	RECT m_Rect;
	D3DXVECTOR3 m_Coordinates;
	D3DXVECTOR3 m_Center;
	D3DCOLOR m_Color;
	float m_Scale;
	float m_Angle;
	RowCol m_MySector;
	//IDirect3DTexture9*	m_UnitTexture;
	int m_TextureType;
	D3DXIMAGE_INFO		m_TextureInfo;
	
public:
	// General Unit Set Functions //
	void setX(float newX);
	void setY(float newY);
	void setSector(int row, int col);
	void setSector(RowCol);
	void setScale(float scale);
	void setAngle(float angle);
	//void setTexturePointer(IDirect3DTexture9* TextureAddress);
	void setTextureType(int TextureType);
	void setTextureInfo(D3DXIMAGE_INFO TextureInformation);

	void resetRect(void);

	// General Unit Get Functions //
	float getX(void);
	float getY(void);
	int getRow(void);
	int getCol(void);
	RowCol getSector(void);

	//IDirect3DTexture9*	getTexturePointer(void);
	D3DXIMAGE_INFO		getTextureInfo(void);

	// Derived Virtual Functions Defined //
	int GetTextureType(void);
	RECT GetRect(void);
	D3DXVECTOR3 GetCenter(void);
	D3DCOLOR GetColor(void);
	float GetScale(void);
	float GetRotation(void);
	D3DXVECTOR3 GetPosition(void);

	// Constructor & Destructor //
	CUnit(void);
	~CUnit(void);
};
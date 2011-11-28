#pragma once

#include <d3d9.h>
#include <d3dx9.h>

class CRenderable
{
public:
	// Sprite Information //
	virtual IDirect3DTexture9* GetTexture(void) = 0;
	virtual RECT GetRect(void) = 0;
	virtual D3DXVECTOR3 GetCenter(void) = 0;
	virtual D3DCOLOR GetColor(void) = 0;

	// Transformation Information //
	virtual float GetScale(void) = 0;
	virtual float GetRotation(void) = 0;
	virtual D3DXVECTOR3 GetPosition(void) = 0;
};
#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include "Definitions.h"

// pass a pointer of type Renderable to DXFrame to render our objects
// also pass the number of objects to be rendered
// in render, loop through all the objects drawing them to the screen

// in LoadQuad we need to build the array of renderables and we need
// to set the number of objects too. when one gets destroyed, we 
// change the number and the array.

class CRenderable
{
public:
	// Sprite Information //
	virtual int GetTextureType(void) = 0;
	virtual RECT GetRect(void) = 0;
	virtual D3DXVECTOR3 GetCenter(void) = 0;
	virtual D3DCOLOR GetColor(void) = 0;

	// Transformation Information //
	virtual float GetScale(void) = 0;
	virtual float GetRotation(void) = 0;
	virtual D3DXVECTOR3 GetPosition(void) = 0;
};
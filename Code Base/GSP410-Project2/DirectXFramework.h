#pragma once

#include "Definitions.h"
#include "DirectXIncludes.h"
#include "Ships.h"

class CDirectXFramework
{
private:
	// Application Variables						//
	HWND	m_hWnd;		// Window Handle			//
	RECT	m_Window;	// Window Size				//
	RECT	m_Source;	// Source Window Size		//
	bool	m_bVsync;	// Vertical Sync Boolean	//
	HRESULT	m_HResult;	// Error Checking			//

	// Direct3D Variables												//
	IDirect3D9*			m_pD3DObject;	// Direct3D 9 Object Pointer	//
	IDirect3DDevice9*	m_pD3DDevice;	// Direct3D 9 Device Pointer	//
	D3DCAPS9			m_D3DCaps;		// Device Capabilites			//

	// Matrices												//
	D3DXMATRIX	m_MatTrans;	// Translation Matrix			//
	D3DXMATRIX	m_MatRot;	// Rotation Matrix				//
	D3DXMATRIX	m_MatScale;	// Scale Matrix					//
	D3DXMATRIX	m_MatWorld;	// World Matrix					//
	D3DXMATRIX	m_MatView;	// View Transform Matrix		//
	D3DXMATRIX	m_MatProj;	// Projection Transform Matrix	//

	// Sprite Variables													//
	ID3DXSprite*		m_pD3DSprite;		// Sprite Object Pointer	//
	IDirect3DTexture9*	m_Paneling;			// Pointer To The Texture	//
	D3DXIMAGE_INFO		m_PanelingInfo;		// Info Related To Texture	//

	IDirect3DTexture9*	m_FireButton;		// Pointer To The Texture	//
	D3DXIMAGE_INFO		m_FireButtonInfo;	// Info Related To Texture	//

	// Font Variables												//
	ID3DXFont*			m_pD3DFont;		// Font Object Pointer		//

	// Direct Input Variables													//
	IDirectInput8*			m_pDIObject;		// DirectInput Object			//
	IDirectInputDevice8*	m_pDIKeyboard;		// Keyboard Device				//
	bool					m_bKeyDown[256];	// Used To Limit Keyboard Input	//
	IDirectInputDevice8*	m_pDIMouse;			// Mouse Device					//
	DIMOUSESTATE2			m_MouseState;		// Mouse's State				//
	POINT					m_MousePosition;	// Mouse's Position				//

	// Game Variables						//
	Cm_PlayerShip m_Player; // m_Player 1			//
	TCHAR m_Text[32];	// Text to Display	//

public:
	// Constructor And Destructor //
	CDirectXFramework(void);
	~CDirectXFramework(void);

	// Initialize DirectX //
	void InitDX(HWND& hWnd, HINSTANCE& hInst, bool bWindowed);
	void LoadTextures(void);

	// Update //
	void Update(float DeltaTime);

	// Render //
	void Render(void);

	// Shutdown //
	void Shutdown(void);
};
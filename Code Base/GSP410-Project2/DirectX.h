#pragma once

#include "Definitions.h"
#include "DirectXIncludes.h"
#include "Unit.h"
#include "FriendlyUnit.h"
#include "EnemyUnit.h"

#include<sstream>

class CDirectX
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


	CFriendlyUnit	m_Player;


	// Sprite Variables													//
	ID3DXSprite*		m_pD3DSprite;		// Sprite Object Pointer	//

	IDirect3DTexture9*	m_TempTexture;
	D3DXIMAGE_INFO		m_TempInfo;

	IDirect3DTexture9*	m_Paneling;
	D3DXIMAGE_INFO		m_PanelingInfo;

	IDirect3DTexture9*	m_FireButton;
	D3DXIMAGE_INFO		m_FireButtonInfo;

	// Font Variables												//
	ID3DXFont*			m_pD3DFont;		// Font Object Pointer		//

	// Game Variables						//
	TCHAR m_Text[32];	// Text to Display	//
	TCHAR m_Text2[3];	// Text to Display	//

public:
	// Constructor And Destructor //
	CDirectX(void);
	~CDirectX(void);

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
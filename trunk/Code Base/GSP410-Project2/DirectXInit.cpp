#include <Windows.h>

#include "DirectXFramework.h"

CDirectXFramework::CDirectXFramework(void)
{
	m_hWnd			=	NULL;
	m_bVsync		=	NULL;
	m_HResult		=	NULL;
	m_pD3DObject	=	NULL;
	m_pD3DDevice	=	NULL;
	m_pD3DFont		=	NULL;
	void(::memset(&m_D3DCaps, NULL, sizeof(m_D3DCaps)));
	void(::D3DXMatrixIdentity(&m_MatTrans));
	void(::D3DXMatrixIdentity(&m_MatRot));
	void(::D3DXMatrixIdentity(&m_MatScale));
	void(::D3DXMatrixIdentity(&m_MatWorld));
	void(::D3DXMatrixIdentity(&m_MatView));
	void(::D3DXMatrixIdentity(&m_MatProj));
	m_pD3DSprite	=	NULL;
	m_FireButton		=	NULL;
	void(::memset(&m_FireButtonInfo, NULL, sizeof(m_FireButtonInfo)));
	m_pD3DFont		=	NULL;
	m_pDIObject		=	NULL;
	m_pDIKeyboard	=	NULL;
	void(::memset(&m_bKeyDown, NULL, sizeof(m_bKeyDown)));
	m_pDIMouse		=	NULL;
	void(::memset(&m_MouseState, NULL, sizeof(m_MouseState)));
	void(::memset(&m_MousePosition, NULL, sizeof(m_MousePosition)));

	m_Player.setX(SCREEN_WIDTH/2);
	m_Player.setY(SCREEN_HEIGHT/2 + 100);
	void(::memset(&m_Text, NULL, sizeof(m_Text)));
	void(::memset(&m_Text2, NULL, sizeof(m_Text2)));
}

void CDirectXFramework::InitDX(HWND& hWnd, HINSTANCE& hInst, bool bWindowed)
{
	// Copy Window Handle //
	m_hWnd = hWnd;
	if(m_hWnd == NULL)
	{
		::MessageBoxA(NULL, "Failed to Copy Window Handler", "hWnd Failed", MB_OK | MB_ICONERROR); 
		::PostQuitMessage(0);
		return;
	}	

	// Create Direct3D Object //
	m_pD3DObject = Direct3DCreate9(D3D_SDK_VERSION);
	if(m_pD3DObject == NULL)
	{
		::MessageBoxA(m_hWnd, "Failed to Create the Direct3D Object", "D3D9 Failed", MB_OK | MB_ICONERROR);
		::PostQuitMessage(0);
		return;
	}

	// Set Direct3D Device Presentation Parameters //
	D3DPRESENT_PARAMETERS	D3Dpp;
	ZeroMemory(&D3Dpp, sizeof(D3Dpp));  // NULL the structure's memory //

	D3Dpp.hDeviceWindow					= hWnd;										// Handle to the focus window										//
	D3Dpp.Windowed						= bWindowed;								// Windowed or Full-screen boolean									//
	D3Dpp.AutoDepthStencilFormat		= D3DFMT_D24S8;								// Format of depth/stencil buffer, 24 bit depth, 8 bit stencil		//
	D3Dpp.EnableAutoDepthStencil		= TRUE;										// Enables Z-Buffer (Depth Buffer)									//
	D3Dpp.BackBufferCount				= 1;										// Change if need of more than 1 is required at a later date		//
	D3Dpp.BackBufferFormat				= D3DFMT_X8R8G8B8;							// Back-buffer format, 8 bits for each pixel						//
	D3Dpp.BackBufferHeight				= SCREEN_HEIGHT;							// Make sure resolution is supported, use adapter modes				//
	D3Dpp.BackBufferWidth				= SCREEN_WIDTH;								// (Same as above)													//
	D3Dpp.SwapEffect					= D3DSWAPEFFECT_DISCARD;					// Discard back-buffer, must stay discard to support multi-sample	//
	D3Dpp.PresentationInterval			= m_bVsync ? D3DPRESENT_INTERVAL_DEFAULT : D3DPRESENT_INTERVAL_ONE; 
																					// Present back-buffer immediately (D3DPRESENT_INTERVAL_IMMEDIATE),	//
																					// Present back-buffer on screen refresh (D3DPRESENT_INTERVAL_ONE)	//

	D3Dpp.Flags							= D3DPRESENTFLAG_DISCARD_DEPTHSTENCIL;		//This flag should improve performance, if not set to NULL.			//
	D3Dpp.FullScreen_RefreshRateInHz	= bWindowed ? 0 : D3DPRESENT_RATE_DEFAULT;	//Full-screen refresh rate, use adapter modes or default			//
	D3Dpp.MultiSampleQuality			= 0;										//MSAA currently off												//
	D3Dpp.MultiSampleType				= D3DMULTISAMPLE_NONE;						//MSAA currently off												//

	// Check Device Capabilities //
	m_HResult = m_pD3DObject->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &m_D3DCaps);
	if(m_HResult != S_OK)
	{
		::MessageBoxA(m_hWnd, "Failed to Get Device Capabilites", "GetDeviceCaps() Failed", MB_OK | MB_ICONERROR);
	}

	DWORD deviceBehaviorFlags = 0;
	// Determine vertex processing mode //
	if(m_D3DCaps.DevCaps & D3DCREATE_HARDWARE_VERTEXPROCESSING)
	{
		// if Hardware vertex processing supported use it (video card) //
		deviceBehaviorFlags |= D3DCREATE_HARDWARE_VERTEXPROCESSING;	
	}
	else
	{
		// else, use software to emulate it (CPU) //
		deviceBehaviorFlags |= D3DCREATE_SOFTWARE_VERTEXPROCESSING; 
	}

	// If hardware vertex processing is on, check pure device support //
	if(m_D3DCaps.DevCaps & D3DDEVCAPS_PUREDEVICE && deviceBehaviorFlags & D3DCREATE_HARDWARE_VERTEXPROCESSING)
	{
		deviceBehaviorFlags |= D3DCREATE_PUREDEVICE;	
	}

	// Create the D3D Device with the present parameters and device flags above			//
	m_HResult = m_pD3DObject->CreateDevice(
		D3DADAPTER_DEFAULT,		// which adapter to use, set to primary					//
		D3DDEVTYPE_HAL,			// device type to use, set to hardware rasterization	//
		hWnd,					// handle to the focus window							//
		deviceBehaviorFlags,	// behavior flags										//
		&D3Dpp,					// presentation parameters								//
		&m_pD3DDevice);			// returned device pointer								//
	if(m_HResult != S_OK)
	{
		::MessageBoxA(m_hWnd, "Failed to Create Device", "CreateDevice() Failed", MB_OK | MB_ICONERROR);
		::PostQuitMessage(0);
		return;
	}


	// Create the Direct Input Object //
	m_HResult = DirectInput8Create(hInst, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pDIObject, NULL);
	if(m_HResult != S_OK)
	{
		::MessageBoxA(m_hWnd, "Failed to Create Input Device", "DirectInput8Create() Failed", MB_OK | MB_ICONERROR);
	}
	// Initialize Mouse //
	m_HResult = m_pDIObject->CreateDevice(GUID_SysMouse, &m_pDIMouse, NULL);
	if(m_HResult != S_OK)
	{
		::MessageBoxA(m_hWnd, "Failed to Create Mouse Device", "CreateDevice() Failed", MB_OK | MB_ICONERROR);
	}
	// Set up Mouse //
	m_HResult = m_pDIMouse->SetCooperativeLevel(hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if(m_HResult != S_OK)
	{
		::MessageBoxA(m_hWnd, "Failed to Set Mouse Cooperative Level", "SetCooperativeLevel() Failed", MB_OK | MB_ICONERROR);
	}
	// 2 Button Mouse //
	m_HResult = m_pDIMouse->SetDataFormat(&c_dfDIMouse2);
	if(m_HResult != S_OK)
	{
		::MessageBoxA(m_hWnd, "Failed to Set Mouse Data Format", "SetDataFormat() Failed", MB_OK | MB_ICONERROR);
	}

	// Initialize Keyboard //
	m_HResult = m_pDIObject->CreateDevice(GUID_SysKeyboard, &m_pDIKeyboard, NULL);
	if(m_HResult != S_OK)
	{
		::MessageBoxA(m_hWnd, "Failed to Create Keyboard Device", "CreateDevice() Failed", MB_OK | MB_ICONERROR);
	}
	// Set up Keyboard //
	m_pDIKeyboard->SetCooperativeLevel(m_hWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if(m_HResult != S_OK)
	{
		::MessageBoxA(m_hWnd, "Failed to Set Keyboard Cooperative Level", "SetCooperativeLevel() Failed", MB_OK | MB_ICONERROR);
	}
	m_pDIKeyboard->SetDataFormat(&c_dfDIKeyboard);
	if(m_HResult != S_OK)
	{
		::MessageBoxA(m_hWnd, "Failed to Set Keyboard Data Format", "SetDataFormat() Failed", MB_OK | MB_ICONERROR);
	}

	// Load D3DXFont //
	m_HResult = D3DXCreateFont(m_pD3DDevice, 0, 0, 0, 0, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_DONTCARE, TEXT("arial"), &m_pD3DFont);
	// Check if the Font was Created //
	if(m_HResult != S_OK)
	{
		::MessageBoxA(m_hWnd, "D3DXCreateFont has failed", "Font Failed", MB_OK | MB_ICONERROR);
	}

	//Create a Single Sprite Object//
	m_HResult = D3DXCreateSprite(m_pD3DDevice, &m_pD3DSprite);
	//Check the Sprite Obejct//
	if(m_HResult != S_OK)
	{
		::MessageBoxA(m_hWnd, "Failed to Create the Sprite Object", "D3DXCreateSprite Failed", MB_OK | MB_ICONERROR);
		::PostQuitMessage(0);
		return;
	}
	m_Source.left = 0;
	m_Source.top = 0;
	m_Source.bottom = SCREEN_HEIGHT;
	m_Source.right = SCREEN_WIDTH;
	LoadTextures();
}

void CDirectXFramework::LoadTextures(void)
{
	// D3DX_DEFAULT_NONPOW2 may not work on certain computers //
	// D3DFMT_UNKNOWN may cause changes in the image; D3DFMT_FROM_FILE can fix this, but may not work on some computers //
	m_HResult = D3DXCreateTextureFromFileExW(m_pD3DDevice, L"../../Documentation/PhotoShop Images/User Interface Images/PlayScreen-Blank.jpg", D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, D3DX_FROM_FILE, 0, D3DFMT_FROM_FILE, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, NULL, &m_PanelingInfo, NULL, &m_Paneling);
	if(m_HResult != S_OK)
	{
		::MessageBoxA(m_hWnd, "Failed to Create Texture From File", "D3DXCreateTextureFromFileExW() Failed", MB_OK | MB_ICONERROR);
	}
	
	m_HResult = D3DXCreateTextureFromFileExW(m_pD3DDevice, L"../../Documentation/PhotoShop Images/Object Images/ButtonFire.png", D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, D3DX_FROM_FILE, 0, D3DFMT_UNKNOWN, D3DPOOL_DEFAULT, D3DX_FILTER_NONE, D3DX_FILTER_NONE, NULL, &m_FireButtonInfo, NULL, &m_FireButton);
	if(m_HResult != S_OK)
	{
		::MessageBoxA(m_hWnd, "Failed to Create Texture From File", "D3DXCreateTextureFromFileExW() Failed", MB_OK | MB_ICONERROR);
	}
}
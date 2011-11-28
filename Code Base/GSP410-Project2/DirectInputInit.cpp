#include "DirectInput.h"

CDirectInput* CDirectInput::Singleton = NULL;

CDirectInput::CDirectInput(void)
{
	m_pDIObject		=	NULL;
	m_pDIKeyboard	=	NULL;
	void(::memset(&m_bKeyDown, NULL, sizeof(m_bKeyDown)));
	m_pDIMouse		=	NULL;
	void(::memset(&m_MouseState, NULL, sizeof(m_MouseState)));
	void(::memset(&m_MousePosition, NULL, sizeof(m_MousePosition)));
	m_HResult		=	NULL;
	m_HWnd			=	NULL;
	m_HResult		=	NULL;
	m_ClickOnce		=	false;
}

CDirectInput* CDirectInput::GetInstance(HINSTANCE hInst, HWND hWnd)
{
	if(Singleton == NULL)
	{
		Singleton = new CDirectInput();
		Singleton->m_HInst = hInst;
		Singleton->m_HWnd = hWnd;
		Singleton->Init();
		return Singleton;
	}
	else
		return Singleton;
}

CDirectInput* CDirectInput::GetInstance(void)
{
	return Singleton;
}

void CDirectInput::Init()
{
	// Create the Direct Input Object //
	m_HResult = DirectInput8Create(m_HInst, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&m_pDIObject, NULL);
	if(m_HResult != S_OK)
	{
		::MessageBoxA(m_HWnd, "Failed to Create Input Device", "DirectInput8Create() Failed", MB_OK | MB_ICONERROR);
	}
	// Initialize Mouse //
	m_HResult = m_pDIObject->CreateDevice(GUID_SysMouse, &m_pDIMouse, NULL);
	if(m_HResult != S_OK)
	{
		::MessageBoxA(m_HWnd, "Failed to Create Mouse Device", "CreateDevice() Failed", MB_OK | MB_ICONERROR);
	}
	// Set up Mouse //
	m_HResult = m_pDIMouse->SetCooperativeLevel(m_HWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if(m_HResult != S_OK)
	{
		::MessageBoxA(m_HWnd, "Failed to Set Mouse Cooperative Level", "SetCooperativeLevel() Failed", MB_OK | MB_ICONERROR);
	}
	// 2 Button Mouse //
	m_HResult = m_pDIMouse->SetDataFormat(&c_dfDIMouse2);
	if(m_HResult != S_OK)
	{
		::MessageBoxA(m_HWnd, "Failed to Set Mouse Data Format", "SetDataFormat() Failed", MB_OK | MB_ICONERROR);
	}

	// Initialize Keyboard //
	m_HResult = m_pDIObject->CreateDevice(GUID_SysKeyboard, &m_pDIKeyboard, NULL);
	if(m_HResult != S_OK)
	{
		::MessageBoxA(m_HWnd, "Failed to Create Keyboard Device", "CreateDevice() Failed", MB_OK | MB_ICONERROR);
	}
	// Set up Keyboard //
	m_pDIKeyboard->SetCooperativeLevel(m_HWnd, DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	if(m_HResult != S_OK)
	{
		::MessageBoxA(m_HWnd, "Failed to Set Keyboard Cooperative Level", "SetCooperativeLevel() Failed", MB_OK | MB_ICONERROR);
	}
	m_pDIKeyboard->SetDataFormat(&c_dfDIKeyboard);
	if(m_HResult != S_OK)
	{
		::MessageBoxA(m_HWnd, "Failed to Set Keyboard Data Format", "SetDataFormat() Failed", MB_OK | MB_ICONERROR);
	}
}
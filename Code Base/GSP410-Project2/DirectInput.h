#pragma once

#include <dinput.h>

class CDirectInput
{
private:
	// Direct Input Variables													//
	IDirectInput8*			m_pDIObject;		// DirectInput Object			//
	IDirectInputDevice8*	m_pDIKeyboard;		// Keyboard Device				//
	bool					m_bKeyDown[256];	// Used To Get Keyboard Input	//
	bool					m_KeyOnce[256];
	IDirectInputDevice8*	m_pDIMouse;			// Mouse Device					//
	DIMOUSESTATE2			m_MouseState;		// Mouse's State				//
	POINT					m_MousePosition;	// Mouse's Position				//
	bool					m_ClickOnce;

	HINSTANCE	m_HInst;
	HWND		m_HWnd;
	HRESULT		m_HResult;

	static CDirectInput* Singleton;
	CDirectInput(void);

public:
	~CDirectInput(void);

	static CDirectInput* GetInstance(HINSTANCE hInst, HWND hWnd);
	static CDirectInput* GetInstance(void);
	void Init();

	void Update(void);
	void Shutdown(void);

	bool KeyDown(int Key);
	bool KeyPressed(int Key);

	bool MouseDown(int Button);
	bool MouseClick(int Button);

	POINT GetMousePosition(void);
};
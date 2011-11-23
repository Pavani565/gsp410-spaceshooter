#include "DirectXFramework.h"

void CDirectXFramework::Update(float DeltaTime)
{
	// Get the Mouse Working //
	ZeroMemory(&m_MouseState, sizeof(m_MouseState));
	// Get the input device state //
	m_HResult = m_pDIMouse->GetDeviceState( sizeof(DIMOUSESTATE2), &m_MouseState );
	if(FAILED(m_HResult))
	{
		m_HResult = m_pDIMouse->Acquire();
		// Device has probably been lost if failed, if so keep trying to get it until it is found	//
		while( m_HResult == DIERR_INPUTLOST)
		{
			m_HResult = m_pDIMouse->Acquire();
		}
		// If we failed for some other reason	//
		if(FAILED(m_HResult))
			return;
		// Read the device state again			//
		m_pDIMouse->GetDeviceState(sizeof(DIMOUSESTATE2), &m_MouseState);
	}

	ZeroMemory(m_bKeyDown, sizeof(m_bKeyDown));

	//Get the input device state
	m_HResult = m_pDIKeyboard->GetDeviceState( sizeof(m_bKeyDown), (LPVOID)&m_bKeyDown );

	if(m_HResult < 0)
	{
		m_HResult = m_pDIKeyboard->Acquire();

		//Device has probably been lost if failed, if so keep trying to get it until it’s found.
		while( m_HResult == DIERR_INPUTLOST)
		{
			m_HResult = m_pDIKeyboard->Acquire();
		}

		// If we failed for some other reason
		if(m_HResult < 0)
			return;

		// Read the device state again
		m_pDIKeyboard->GetDeviceState(sizeof(m_bKeyDown), m_bKeyDown);
	}
	
	if(m_bKeyDown[int(DIK_W)])
	{
		m_Player.setY(m_Player.getY()-1);
	}
	if(m_bKeyDown[int(DIK_A)])
	{
		m_Player.setX(m_Player.getX()-1);
	}
	if(m_bKeyDown[int(DIK_S)])
	{
		m_Player.setY(m_Player.getY()+1);
	}
	if(m_bKeyDown[int(DIK_D)])
	{
		m_Player.setX(m_Player.getX()+1);
	}

	for(int i = 0; i < 256; i++)
	{
		if(m_bKeyDown[i])
		{
			wsprintf(m_Text2, L"%i", i);
			break;
		}
	}

	// Putting the Mouse Position into an array of chars to display it //
	wsprintf(m_Text, L"X: %u, Y: %u", UINT(m_MousePosition.x), UINT(m_MousePosition.y));

	// Check For Mouse Left Click //
	if(m_MouseState.rgbButtons[0] & 0x80)
	{
		// Get Mouse Position If Left Mouse Button Is Down //
		::GetCursorPos(&m_MousePosition);
		::ScreenToClient(m_hWnd, &m_MousePosition);
		WINDOWINFO windinfo;
		::GetWindowInfo(m_hWnd, &windinfo);
		windinfo.cxWindowBorders;
		windinfo.cyWindowBorders;
		windinfo.rcWindow;
		// Check If Mouse Is Over The Button //
		if(unsigned(m_MousePosition.x) <= m_Player.getX() + m_FireButtonInfo.Width/2 && unsigned(m_MousePosition.x) >= m_Player.getX() - m_FireButtonInfo.Width/2)
			if(unsigned(m_MousePosition.y) <= m_Player.getY() + m_FireButtonInfo.Height/2 && unsigned(m_MousePosition.y) >= m_Player.getY() - m_FireButtonInfo.Height/2)
				::PostQuitMessage(0);
	}
}
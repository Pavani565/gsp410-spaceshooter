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

	// Putting the Mouse Position into an array of chars to display it //
	wsprintf(m_Text, L"X: %u, Y: %u", UINT(m_MousePosition.x), UINT(m_MousePosition.y));

	// Check For Mouse Left Click //
	if(m_MouseState.rgbButtons[0] & 0x80)
	{
		// Get Mouse Position If Left Mouse Button Is Down //
		::GetCursorPos(&m_MousePosition);
		// Check If Mouse Is Over The Button //
		if(unsigned(m_MousePosition.x) <= Player.getX() + m_TexInfo.Width/2 && unsigned(m_MousePosition.x) >= Player.getX() - m_TexInfo.Width/2)
			if(unsigned(m_MousePosition.y) <= Player.getY() + m_TexInfo.Height/2 && unsigned(m_MousePosition.y) >= Player.getY() - m_TexInfo.Height/2)
				::PostQuitMessage(0);
	}
}
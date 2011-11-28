#include "DirectInput.h"

void CDirectInput::Update(void)
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
}

bool CDirectInput::KeyDown(int Key)
{
	if(m_bKeyDown[Key])
	{
		return true;
	}
	return false;
}

bool CDirectInput::KeyPressed(int Key)
{
	if(m_bKeyDown[Key])
	{
		if(m_KeyOnce[Key] == false)
		{
			m_KeyOnce[Key] = true;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		m_KeyOnce[Key] = false;
	}
	return false;
}

bool CDirectInput::MouseDown(int Button)
{
	// Check For Mouse Left Click //
	if(m_MouseState.rgbButtons[Button] & 0x80)
	{
		// Get Mouse Position If Mouse Button Is Down //
		::GetCursorPos(&m_MousePosition);
		::ScreenToClient(m_HWnd, &m_MousePosition);
		return true;
	}
	return false;
}

bool CDirectInput::MouseClick(int Button)
{
	if(m_MouseState.rgbButtons[Button]  & 0x80)
	{
		// Determine if the Mouse has been Clicked or is Being Held //
		if(m_ClickOnce == false)
		{
			// Get Position of Mouse //
			m_HResult = ::GetCursorPos(&m_MousePosition);
			if(m_HResult == 1)
			{
				m_ClickOnce = true;
				// Translate Mouse Click to the Window //
				::ScreenToClient(m_HWnd, &m_MousePosition);
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	else
	{
		// This Statement will not be ran unless the mouse button is up //
		m_ClickOnce = false;
	}
	return false;
}
#include "DirectInput.h"

void CDirectInput::Shutdown(void)
{
	if(m_pDIObject != NULL)
	{
		void(m_pDIObject->Release());
		m_pDIObject = NULL;
	}
	if(m_pDIKeyboard != NULL)
	{
		void(m_pDIKeyboard->Release());
		m_pDIKeyboard = NULL;
	}
	if(m_pDIMouse != NULL)
	{
		void(m_pDIMouse->Release());
		m_pDIMouse = NULL;
	}
}

CDirectInput::~CDirectInput(void)
{
	// Destructor //
	Shutdown();
}
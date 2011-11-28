#include "DirectX.h"

void CDirectX::Shutdown(void)
{
	if(m_pD3DObject != NULL)
	{
		void(m_pD3DObject->Release());
		m_pD3DObject = NULL;
	}
	if(m_pD3DDevice != NULL)
	{
		void(m_pD3DDevice->Release());
		m_pD3DDevice = NULL;
	}
	if(m_pD3DSprite != NULL)
	{
		void(m_pD3DSprite->Release());
		m_pD3DSprite = NULL;
	}
	if(m_pD3DFont != NULL)
	{
		void(m_pD3DFont->Release());
		m_pD3DFont = NULL;
	}
	if(m_FireButton != NULL)
	{
		void(m_FireButton->Release());
		m_FireButton = NULL;
	}
	if(m_Paneling != NULL)
	{
		void(m_Paneling->Release());
		m_Paneling = NULL;
	}
}

CDirectX::~CDirectX(void)
{
	// Destructor //
	Shutdown();
}
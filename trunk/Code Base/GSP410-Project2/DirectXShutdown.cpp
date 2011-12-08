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
	if(m_FriendlyShip != NULL)
	{
		void(m_FriendlyShip->Release());
		m_FriendlyShip = NULL;
	}
	if(m_EnemyShip != NULL)
	{
		void(m_EnemyShip->Release());
		m_EnemyShip = NULL;
	}
	if(m_Station != NULL)
	{
		void(m_Station->Release());
		m_Station = NULL;
	}
	if(m_Star != NULL)
	{
		void(m_Star->Release());
		m_Star = NULL;
	}
	if(m_Error != NULL)
	{
		void(m_Error->Release());
		m_Error = NULL;
	}
}

CDirectX::~CDirectX(void)
{
	// Destructor //
	Shutdown();
}
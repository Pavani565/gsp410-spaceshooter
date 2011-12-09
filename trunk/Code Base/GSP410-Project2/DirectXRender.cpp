#include "DirectX.h"

void CDirectX::Render(CRenderable* stuffList[], int rNum)
{
	// Test if the Device was Created Successfully //
	if(!m_pD3DDevice)
		// return if Device was not Created Successfully //
		return;

	// Clear Back Buffer //
	if(SUCCEEDED(m_pD3DDevice->Clear(0, 0, D3DCLEAR_TARGET, D3DXCOLOR(0.0f, 0.4f, 0.8f, 1.0f), 1.0f, 0)))
	{
		if(SUCCEEDED(m_pD3DDevice->Clear(0, NULL, D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0)))
		{
			// Begin the Scene //
			if(SUCCEEDED(m_pD3DDevice->BeginScene()))
			{
				// Begin the Sprite //
				if(SUCCEEDED(m_pD3DSprite->Begin(D3DXSPRITE_ALPHABLEND | D3DXSPRITE_SORT_DEPTH_FRONTTOBACK)))
				{

					// Draw 2D Assests Here //
					
					// Non Player Textures //

					// Paneling //
					D3DXMatrixScaling(&m_MatScale, 1.0f, 1.0f, 1.0f); // Scaling //
					D3DXMatrixRotationZ(&m_MatRot, D3DXToRadian(0)); // Rotation //
					D3DXMatrixTranslation(&m_MatTrans, SCREEN_WIDTH/2.0f, SCREEN_HEIGHT/2.0f, 0.0f);
					//D3DXMatrixTranslation(&m_MatTrans, (m_Window.right - m_Window.left)/2.0f, (m_Window.bottom - m_Window.top)/2.0f, 0.0f); // Translation //
					D3DXMatrixMultiply(&m_MatScale, &m_MatScale, &m_MatRot); // Multiply scale and rotation, store in scale //
					D3DXMatrixMultiply(&m_MatWorld, &m_MatScale, &m_MatTrans); // Multiply scale and translation, store in world //
					// Set Transform //
					m_pD3DSprite->SetTransform(&m_MatWorld);
					m_pD3DSprite->Draw(m_Paneling, 0, &D3DXVECTOR3(m_PanelingInfo.Width/2.0f, m_PanelingInfo.Height/2.0f, 0.0f), 0, D3DCOLOR_XRGB(255, 255, 255));

					// Draw Renderables //
					//for(int i=0; i < rNum; i++)
					//{
					//	D3DXMatrixScaling(&m_MatScale, 1.0f, 1.0f, 1.0f); // Scaling //
					//	D3DXMatrixRotationZ(&m_MatRot, D3DXToRadian(stuffList[i]->GetRotation())); // Rotation //
					//	D3DXMatrixTranslation(&m_MatTrans, stuffList[i]->GetPosition().x, stuffList[i]->GetPosition().y, 0.0f); // Translation //
					//	D3DXMatrixMultiply(&m_MatScale, &m_MatScale, &m_MatRot); // Multiply scale and rotation, store in scale //
					//	D3DXMatrixMultiply(&m_MatWorld, &m_MatScale, &m_MatTrans); // Multiply scale and translation, store in world //
					//	// Set Transform //
					//	m_pD3DSprite->SetTransform(&m_MatWorld);

					//	switch(rNum)
					//	{
					//	case 0:
					//		// Draw Friendly Ship Sprite //							
					//		m_pD3DSprite->Draw(m_FriendlyShip, 0, &D3DXVECTOR3(m_FriendlyShipInfo.Width/2.0f, m_FriendlyShipInfo.Height/2.0f, 0.0f), 0, D3DCOLOR_XRGB(255, 255, 255));
					//		break;
					//	case 1:
					//		// Draw Enemy Ship Sprite //							
					//		m_pD3DSprite->Draw(m_EnemyShip, 0, &D3DXVECTOR3(m_EnemyShipInfo.Width/2.0f, m_EnemyShipInfo.Height/2.0f, 0.0f), 0, D3DCOLOR_XRGB(255, 255, 255));
					//		break;
					//	case 2:
					//		// Draw Station Sprite //
					//		m_pD3DSprite->Draw(m_Star, 0, &D3DXVECTOR3(m_StarInfo.Width/2.0f, m_StarInfo.Height/2.0f, 0.0f), 0, D3DCOLOR_XRGB(255, 255, 255));
					//		break;
					//	case 3:
					//		// Draw Star Sprite //
					//		m_pD3DSprite->Draw(m_Station, 0, &D3DXVECTOR3(m_StationInfo.Width/2.0f, m_StationInfo.Height/2.0f, 0.0f), 0, D3DCOLOR_XRGB(255, 255, 255));
					//		break;
					//	default:
					//		// Draw Error Sprite //
					//		m_pD3DSprite->Draw(m_Error, 0, &D3DXVECTOR3(m_ErrorInfo.Width/2.0f, m_ErrorInfo.Height/2.0f, 0.0f), 0, D3DCOLOR_XRGB(255, 255, 255));
					//		break;
					//	}
					//}

					// Close the Sprite //
					m_HResult = m_pD3DSprite->End();
					if(m_HResult != S_OK)
					{
						::MessageBoxA(m_hWnd, "Failed to Flush the Sprite", "End() Failed", MB_OK | MB_ICONERROR);
					}
				}

				// Text //
				if(m_pD3DFont->DrawTextW(0, L"Application Is Running", -1, &m_Source, DT_VCENTER | DT_CENTER | DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255)) == 0)
				{
					::MessageBoxA(m_hWnd, "Failed to Draw Text", "DrawTextW() Failed", MB_OK | MB_ICONERROR);
				}
				/*
				if(m_pD3DFont->DrawText(0, m_Text, -1, &m_Source, DT_TOP| DT_CENTER | DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255)) == 0)
				{
					::MessageBoxA(m_hWnd, "Failed to Draw Text", "DrawTextW() Failed", MB_OK | MB_ICONERROR);
				}
				if(m_pD3DFont->DrawText(0, m_Text2, -1, &m_Source, DT_TOP| DT_VCENTER | DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255)) == 0)
				{
					::MessageBoxA(m_hWnd, "Failed to Draw Text", "DrawTextW() Failed", MB_OK | MB_ICONERROR);
				}
				*/
				m_HResult = m_pD3DDevice->EndScene();
				if(m_HResult != S_OK)
				{
					::MessageBoxA(m_hWnd, "Failed To End the Scene", "EndScene() Failed", MB_OK | MB_ICONERROR);
				}
			}

			m_HResult = m_pD3DDevice->Present(0, 0, m_hWnd, 0);
			if(m_HResult != S_OK)
			{
				::MessageBoxA(m_hWnd, "Failed to Present the Scene", "Present() Failed", MB_OK | MB_ICONERROR);
			}
		}
	}
}
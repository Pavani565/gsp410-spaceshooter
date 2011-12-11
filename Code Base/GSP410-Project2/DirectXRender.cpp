#include "DirectX.h"

void CDirectX::Render(CRenderable* stuffList[], int rNum, CFriendlyUnit Friend)
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
					m_pD3DSprite->Draw(m_Background, 0, &D3DXVECTOR3(m_BackgroundInfo.Width/2.0f, m_BackgroundInfo.Height/2.0f, 0.0f), 0, D3DCOLOR_XRGB(255, 255, 255));

					// Draw Renderables //
					for(int i=0; i < rNum; i++)
					{
						D3DXMatrixScaling(&m_MatScale, 1.0f, 1.0f, 1.0f); // Scaling //
						D3DXMatrixRotationZ(&m_MatRot, /*D3DXToRadian(stuffList[i]->GetRotation())*/0.0f); // Rotation //
						D3DXMatrixTranslation(&m_MatTrans, stuffList[i]->GetPosition().x, stuffList[i]->GetPosition().y, 0.0f); // Translation //
						D3DXMatrixMultiply(&m_MatScale, &m_MatScale, &m_MatRot); // Multiply scale and rotation, store in scale //
						D3DXMatrixMultiply(&m_MatWorld, &m_MatScale, &m_MatTrans); // Multiply scale and translation, store in world //
						// Set Transform //
						m_pD3DSprite->SetTransform(&m_MatWorld);

						D3DXVECTOR3 test = stuffList[i]->GetPosition();

						switch(stuffList[i]->GetTextureType())
						{
						case 0://Friendly
							m_pD3DSprite->Draw(m_Textures[0], NULL, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
							break;
						case 1://Enemy
							m_pD3DSprite->Draw(m_Textures[1], NULL, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
							break;
						case 2://Star
							m_pD3DSprite->Draw(m_Textures[2], NULL, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
							break;
						case 3://Station
							m_pD3DSprite->Draw(m_Textures[3], NULL, NULL, NULL, D3DCOLOR_XRGB(255, 255, 255));
							break;
						default:
							m_pD3DSprite->Draw(m_Error, 0, &D3DXVECTOR3(m_ErrorInfo.Width/2.0f, m_ErrorInfo.Height/2.0f, 0.0f), 0, D3DCOLOR_XRGB(255, 255, 255));
							break;
						}
					}

					// Close the Sprite //
					m_HResult = m_pD3DSprite->End();
					if(m_HResult != S_OK)
					{
						::MessageBoxA(m_hWnd, "Failed to Flush the Sprite", "End() Failed", MB_OK | MB_ICONERROR);
					}
				}

				// Text //
				wsprintf(m_Text, L"Energy: %i", Friend.getShieldEnergy());
				RECT Plaque;
				Plaque.top = 24;
				Plaque.left = 1062;
				Plaque.right = 1328;
				Plaque.bottom = 169;
				if(m_pD3DFont->DrawTextW(0, m_Text, -1, &Plaque, DT_TOP | DT_CENTER | DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255)) == 0)
				{
					::MessageBoxA(m_hWnd, "Failed to Draw Text", "DrawTextW() Failed", MB_OK | MB_ICONERROR);
				}
				wsprintf(m_Text, L"Energy: %i", Friend.getBlasterEnergy());
				Plaque.top = 202;
				Plaque.left = 1062;
				Plaque.right = 1328;
				Plaque.bottom = 380;
				if(m_pD3DFont->DrawTextW(0, m_Text, -1, &Plaque, DT_TOP | DT_CENTER | DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255)) == 0)
				{
					::MessageBoxA(m_hWnd, "Failed to Draw Text", "DrawTextW() Failed", MB_OK | MB_ICONERROR);
				} //111 45, 393 77
				wsprintf(m_Text, L"Total Energy: %i", Friend.getShipEnergy());
				Plaque.top = 45;
				Plaque.left = 111;
				Plaque.right = 393;
				Plaque.bottom = 77;
				if(m_pD3DFont->DrawTextW(0, m_Text, -1, &Plaque, DT_VCENTER | DT_CENTER | DT_NOCLIP, D3DCOLOR_XRGB(255, 255, 255)) == 0)
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
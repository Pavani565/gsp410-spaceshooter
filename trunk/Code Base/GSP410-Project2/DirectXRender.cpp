#include "DirectXFramework.h"

void CDirectXFramework::Render()
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
					D3DXMatrixScaling(&m_MatScale, 1.0f, 1.0f, 1.0f);// Scaling
					D3DXMatrixRotationZ(&m_MatRot, D3DXToRadian(0));
					D3DXMatrixTranslation(&m_MatTrans, float(Player.getX()), float(Player.getY()), 0.0f);	// Translation
					D3DXMatrixMultiply(&m_MatScale, &m_MatScale, &m_MatRot);		// Multiply scale and rotation, store in scale
					D3DXMatrixMultiply(&m_MatWorld, &m_MatScale, &m_MatTrans);	// Multiply scale and translation, store in world
					/*Set Transform*/
					m_pD3DSprite->SetTransform(&m_MatWorld);
					m_pD3DSprite->Draw(m_Texture, 0, &D3DXVECTOR3(m_TexInfo.Width/2.0f, m_TexInfo.Height/2.0f, 0.0f), 0, D3DCOLOR_XRGB(255, 255, 255));

					// Close the Sprite //
					m_HResult = m_pD3DSprite->End();
					if(m_HResult != S_OK)
					{
						::MessageBoxA(m_hWnd, "Failed to Flush the Sprite", "End() Failed", MB_OK | MB_ICONERROR);
					}
				}

				// Get Window Size and Position //
				if(GetWindowRect(m_hWnd, &m_Window) == 0)
				{
					::MessageBoxA(m_hWnd, "Failed to Get Window RECT", "GetWindowRect() Failed", MB_OK | MB_ICONERROR);
				}

				// Text //
				if(m_pD3DFont->DrawTextW(0, L"Application Is Running", -1, &m_Window, DT_VCENTER | DT_CENTER | DT_NOCLIP, D3DCOLOR_ARGB(255, 255, 255, 255)) == 0)
				{
					::MessageBoxA(m_hWnd, "Failed to Draw Text", "DrawTextW() Failed", MB_OK | MB_ICONERROR);
				}
				if(m_pD3DFont->DrawText(0, m_Text, -1, &m_Window, DT_TOP| DT_CENTER | DT_NOCLIP, D3DCOLOR_ARGB(255, 255, 255, 255)) == 0)
				{
					::MessageBoxA(m_hWnd, "Failed to Draw Text", "DrawTextW() Failed", MB_OK | MB_ICONERROR);
				}

				m_HResult = m_pD3DDevice->EndScene();
				if(m_HResult != S_OK)
				{
					::MessageBoxA(m_hWnd, "Failed To End the Scene", "EndScene() Failed", MB_OK | MB_ICONERROR);
				}
			}

			m_HResult = m_pD3DDevice->Present(&m_Window, &m_Window, m_hWnd, 0);
			if(m_HResult != S_OK)
			{
				::MessageBoxA(m_hWnd, "Failed to Present the Scene", "Present() Failed", MB_OK | MB_ICONERROR);
			}
		}
	}
}
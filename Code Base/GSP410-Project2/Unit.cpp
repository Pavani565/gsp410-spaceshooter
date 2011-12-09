#include "Unit.h"

CUnit::CUnit(void)
{
	m_Scale = 1.0f;
	m_Angle = 0.0f;
	memset(&m_TextureInfo, 0, sizeof(m_TextureInfo));
}

void CUnit::setX(float newX)
{
	m_Coordinates.x = newX;
}
void CUnit::setY(float newY)
{
	m_Coordinates.y = newY;
}
void CUnit::setSector(int row, int col)
{
	m_MySector.row = row;
	m_MySector.col = col;
}
void CUnit::setSector(RowCol sector)
{
	m_MySector = sector;
}
//void CUnit::setTexturePointer(IDirect3DTexture9* TextureAddress)
//{
//	m_UnitTexture = TextureAddress;
//}

void CUnit::setTextureType(int TextureType)
{
	m_TextureType = TextureType;
}
void CUnit::setTextureInfo(D3DXIMAGE_INFO TextureInformation)
{
	m_TextureInfo = TextureInformation;
	m_Rect.bottom = long(m_TextureInfo.Height * m_Scale);
	m_Rect.right = long(m_TextureInfo.Width * m_Scale);
	m_Rect.left = 0;
	m_Rect.top = 0;
	m_Center.x = m_Rect.right/2.0f;
	m_Center.y = m_Rect.bottom/2.0f;
	m_Center.z = 0;
}
void CUnit::setScale(float scale)
{
	m_Scale = scale;
}
void CUnit::setAngle(float angle)
{
	m_Angle = angle;
}
void CUnit::resetRect(void)
{
	m_Rect.bottom = long(m_TextureInfo.Height * m_Scale);
	m_Rect.right = long(m_TextureInfo.Width * m_Scale);
	m_Rect.left = 0;
	m_Rect.top = 0;
}
float CUnit::getX(void)
{
	return m_Coordinates.x;
}
float CUnit::getY(void)
{
	return m_Coordinates.y;
}
int CUnit::getCol(void)
{
	return m_MySector.col;
}
int CUnit::getRow(void)
{
	return m_MySector.row;
}
RowCol CUnit::getSector(void)
{
	return m_MySector;
}

//IDirect3DTexture9* CUnit::getTexturePointer(void)
//{
//	return m_UnitTexture;
//}
D3DXIMAGE_INFO CUnit::getTextureInfo(void)
{
	return m_TextureInfo;
}

//bool CUnit::Clicked(int MouseX, int MouseY)
//{
//	if(MouseX > signed((m_X-(m_TextureInfo.Width/2))) && MouseX > signed((m_X+(m_TextureInfo.Width/2))))
//		if(MouseY > signed((m_Y-(m_TextureInfo.Height/2))) && MouseY < signed((m_Y+(m_TextureInfo.Height/2))))
//			return true;
//	return false;
//}

int CUnit::GetTextureType(void)
{
	return m_TextureType;
}
RECT CUnit::GetRect(void)
{
	return m_Rect;
}
D3DXVECTOR3 CUnit::GetCenter(void)
{
	return m_Center;
}
D3DCOLOR CUnit::GetColor(void)
{
	return m_Color;
}
float CUnit::GetScale(void)
{
	return m_Scale;
}
float CUnit::GetRotation(void)
{
	return m_Angle;
}
D3DXVECTOR3 CUnit::GetPosition(void)
{
	return m_Coordinates;
}



CUnit::~CUnit(void)
{
	memset(&m_TextureInfo, 0, sizeof(m_TextureInfo));
}
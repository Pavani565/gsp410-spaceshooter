#include "Unit.h"

CUnit::CUnit(void)
{
	m_X = 0;
	m_Y = 0;
	m_UnitTexture = 0;
	memset(&m_TextureInfo, 0, sizeof(m_TextureInfo));
}

void CUnit::setX(int newX)
{
	this->m_X = newX;
}
void CUnit::setY(int newY)
{
	this->m_Y = newY;
}
void CUnit::setTexturePointer(IDirect3DTexture9* TextureAddress)
{
	this->m_UnitTexture = TextureAddress;
}
void CUnit::setTextureInfo(D3DXIMAGE_INFO TextureInformation)
{
	this->m_TextureInfo = TextureInformation;
}
int CUnit::getX(void)
{
	return this->m_X;
}
int CUnit::getY(void)
{
	return this->m_Y;
}
IDirect3DTexture9* CUnit::getTexturePointer(void)
{
	return this->m_UnitTexture;
}
D3DXIMAGE_INFO CUnit::getTextureInfo(void)
{
	return this->m_TextureInfo;
}

bool CUnit::Clicked(int MouseX, int MouseY)
{
	if(MouseX > signed((this->m_X-(this->m_TextureInfo.Width/2))) && MouseX > signed((this->m_X+(this->m_TextureInfo.Width/2))))
		if(MouseY > signed((this->m_Y-(this->m_TextureInfo.Height/2))) && MouseY < signed((this->m_Y+(this->m_TextureInfo.Height/2))))
			return true;
	return false;
}
CUnit::~CUnit(void)
{
	m_X = 0;
	m_Y = 0;
	m_UnitTexture = 0;
	memset(&m_TextureInfo, 0, sizeof(m_TextureInfo));
}
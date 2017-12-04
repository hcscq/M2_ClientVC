/******************************************************************************************************************
                                                                                                                   
	모듈명:																											
																													
	작성자:																											
	작성일:																											
																													
	[일자][수정자] : 수정 내용																						
                                                                                                                   
*******************************************************************************************************************/



#include "StdAfx.h"



CExchangeWnd::CExchangeWnd()
{
	Init();
}

CExchangeWnd::~CExchangeWnd()
{
	Destroy();
}

void CExchangeWnd::Init()
{
	CGameWnd::Init();

	m_xExchangeBtn.Init();
}

void CExchangeWnd::Destroy()
{
	CGameWnd::Destroy();
}


void CExchangeWnd::CreateExchangeWnd(INT nID, CWHWilImageData* pxWndImage, INT nFrameImgIdx, INT nStartX, INT nStartY, INT nWidth, INT nHeight, BOOL bCanMove)
{
	CreateGameWnd(nID, pxWndImage, nFrameImgIdx, bCanMove, nStartX, nStartY, nWidth, nHeight);
	m_xExchangeBtn.CreateGameBtn(pxWndImage, 280, 281, nStartX+255, nStartY+291);
}

void CExchangeWnd::ShowExchangeWnd()
{
	ShowGameWnd();
	m_xExchangeBtn.ShowGameBtn();
}

void CExchangeWnd::OnMouseMove(POINT ptMouse)
{
	m_xExchangeBtn.ChangeRect(m_rcWnd.left+567, m_rcWnd.top+413);
	m_xExchangeBtn.OnMouseMove(ptMouse);
}

BOOL CExchangeWnd::OnLButtonUp(POINT ptMouse)
{
	if ( m_xExchangeBtn.OnLButtonUp(ptMouse) )		return TRUE;
	return FALSE;
}

BOOL CExchangeWnd::OnLButtonDown(POINT ptMouse)
{
	if ( m_xExchangeBtn.OnLButtonDown(ptMouse) )		return TRUE;
	return FALSE;
}

void CExchangeWnd::SetStatusBtnInit()
{
	m_xExchangeBtn.SetBtnState(_BTN_STATE_NORMAL);
}


/******************************************************************************************************************
                                                                                                                   
	모듈명:																											
																													
	작성자:																											
	작성일:																											
																													
	[일자][수정자] : 수정 내용																						
                                                                                                                   
*******************************************************************************************************************/



#include "StdAfx.h"



CGroupPopWnd::CGroupPopWnd()
{
	Init();
}

CGroupPopWnd::~CGroupPopWnd()
{
	Destroy();
}

void CGroupPopWnd::CreateGroupPopWnd(INT nID, CWHWilImageData* pxWndImage, INT nFrameImgIdx, INT nStartX, INT nStartY, INT nWidth, INT nHeight, BOOL bCanMove)
{
	CreateGameWnd(nID, pxWndImage, nFrameImgIdx, bCanMove, nStartX, nStartY, nWidth, nHeight);
}

void CGroupPopWnd::Init()
{
	CGameWnd::Init();
}

void CGroupPopWnd::Destroy()
{
	CGameWnd::Destroy();
}


void CGroupPopWnd::ShowGroupPopWnd()
{
	ShowGameWnd();
}

BOOL CGroupPopWnd::OnLButtonUp(POINT ptMouse)
{
	return FALSE;
}

BOOL CGroupPopWnd::OnLButtonDown(POINT ptMouse)
{
	return FALSE;
}

void CGroupPopWnd::OnMouseMove(POINT ptMouse)
{
}
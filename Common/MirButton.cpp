// MirButton.cpp: implementation of the CMirButton class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MirButton.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMirButton::CMirButton()
{

}

CMirButton::~CMirButton()
{

}

CMirButton::CMirButton(HWND hWnd, BUTTONINFO *lpButtonInfo)
{
	SetBtn(hWnd, lpButtonInfo);
}

BOOL CMirButton::CheckMouseOn(int nPosX, int nPosY)
{
	if(IsInRect(nPosX, nPosY))
		return TRUE;

	return FALSE;
}

BOOL CMirButton::CheckClick(POINT Pos)
{
	if(IsInRect(Pos.x, Pos.y))
		return TRUE;

	return FALSE;
}

void CMirButton::SetBtn(HWND hWnd, BUTTONINFO* lpButtonInfo)
{
	m_hParentWnd	= hWnd;
	SetBtn(lpButtonInfo);
}

void CMirButton::SetBtn(BUTTONINFO* lpButtonInfo)
{
	m_nButtonID		= lpButtonInfo->nID;
	m_Rect.left		= lpButtonInfo->left;
	m_Rect.top		= lpButtonInfo->top;
	m_Rect.right	= m_Rect.left + lpButtonInfo->right;
	m_Rect.bottom	= m_Rect.top + lpButtonInfo->bottom;
	m_nState		= lpButtonInfo->nState;
}

void CMirButton::OnLButtonDown(POINT	xPoint)
{
	if(IsInRect(xPoint.x, xPoint.y))
		m_nState		= BUTTON_STATE_DOWN;

}

void  CMirButton::OnMouseMove(POINT xPoint)
{
	if(IsInRect(xPoint.x, xPoint.y))
		m_nState = BUTTON_STATE_ON;
}

void  CMirButton::OnLButtonUp(POINT xPoint)
{
	m_nState = BUTTON_STATE_UP;
}

void CMirButton::ChangeBtnRect(RECT rc)
{

}
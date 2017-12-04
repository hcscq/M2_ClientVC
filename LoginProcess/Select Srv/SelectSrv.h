// LoginProcess.h: interface for the CLoginProcess class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _SELECT_SERVER_H
#define _SELECT_SERVER_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "d3d9.h"
class CSelectSrv : public CBMWnd 
{
	/////////////////////////////////////////////////////////////////////////////////////////
	// Functions
public:
	CSelectSrv();
	~CSelectSrv();

	virtual void		Create(CWHWilImageData* pxImage,CPDLList<ServerList>* pxSList);

	virtual HRESULT		OnButtonDown(WPARAM wParam, LPARAM lParam);
	virtual HRESULT		OnButtonDown(POINT ptMouse);
	virtual HRESULT		OnButtonUp(WPARAM wParam, LPARAM lParam);
	virtual HRESULT		OnButtonUp(POINT ptMouse);
	virtual HRESULT		OnKeyDown(WPARAM wParam, LPARAM lParam);
	virtual LRESULT		OnMouseMove(WPARAM wParam, LPARAM lParam);

	virtual	void		Render(INT	nLoopTime);
	void				Draw3DBorder(RECT rcWnd, COLORREF dwColor, INT nAlpha);
private:
protected:
	/////////////////////////////////////////////////////////////////////////////////////////
	// Variable
public:
private:
	BOOL					m_fIsButtonDown;
protected:
	CWHWilImageData			*m_pxImage;
	_PPSERVERBUTTON			m_ppxSrvBtn;
	INT						m_nSrvCount;
	D3DVERTEX				m_avBillBoard[4];
	
	//D3DXVECTOR3 a;
};
#endif //_SELECT_SERVER_H

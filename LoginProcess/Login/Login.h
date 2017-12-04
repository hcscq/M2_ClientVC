// LoginProcess.h: interface for the CLoginProcess class.
//
//////////////////////////////////////////////////////////////////////

#ifndef _LOGIN_H
#define _LOGIN_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLogin : public CBMWnd 
{
	/////////////////////////////////////////////////////////////////////////////////////////
	// Functions
public:
	CLogin();
	~CLogin();

	virtual void		Create(CWHWilImageData* pxImage);

	virtual HRESULT		OnButtonDown(WPARAM wParam, LPARAM lParam);
	virtual HRESULT		OnButtonDown(POINT ptMouse);
	virtual HRESULT		OnButtonUp(WPARAM wParam, LPARAM lParam);
	virtual HRESULT		OnButtonUp(POINT ptMouse);
	virtual HRESULT		OnKeyDown(WPARAM wParam, LPARAM lParam);
	virtual LRESULT		OnMouseMove(WPARAM wParam, LPARAM lParam);
	virtual	void		Render(INT	nLoopTime);
private:
protected:
	void				SetFocusBefore(void);
	void				SetFocusAfter(void);
	/////////////////////////////////////////////////////////////////////////////////////////
	// Variable
public:
private:
	INPUTSTATE			m_xInputState[2];
	CMirButton			m_xButtons[4];
	INT					m_nUserState;
	BOOL				m_fIsButtonDown;
protected:
	CWHWilImageData		*m_pxImage;
	CMirButton			*m_pBtn;
	BOOL				m_fShowIDPASS;
};
#endif //_LOGIN_H

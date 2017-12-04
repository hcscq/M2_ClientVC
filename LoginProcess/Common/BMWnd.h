#ifndef	_BMWND_H
#define _BMWND_H


class CBMWnd
{
	/////////////////////////////////////////////////////////////////////////////////////////
	// Functions
public:
	CBMWnd();
	~CBMWnd();
	
	void	SetFocused(void);
	
	virtual void	OpenWnd(void);
	virtual void	CloseWnd(void);

	void	SetWndRect(RECT rc)		{m_rcWnd = rc;}
	BOOL	IsWndActive(void)		{return m_fIsActive;}
	BOOL	IsWndFocused(void)		{return m_fIsFocused;}
	
	virtual HRESULT	OnButtonDown(WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnButtonDown(POINT ptMouse);
	virtual HRESULT	OnButtonUp(WPARAM wParam, LPARAM lParam);
	virtual HRESULT OnButtonUp(POINT ptMouse);
	virtual HRESULT OnKeyDown(WPARAM wParam, LPARAM lParam);
	virtual LRESULT	OnMouseMove(WPARAM wParam, LPARAM lParam);
	
	virtual	void	Render(INT	nLoopsTime);
private:
protected:
	__inline	BOOL	IsInRect(RECT rc,INT nX,INT nY)
	{
		if((rc.left > nX) || (rc.right < nX) || (rc.top > nY) || (rc.bottom < nY) ) return FALSE;
		return TRUE;
	}
	__inline	BOOL	IsInRect(RECT rc,POINT pt) 
	{
		return IsInRect(rc, pt.x, pt.y);
	}
	
	/////////////////////////////////////////////////////////////////////////////////////////
	// Variable
public:
private:
protected:
	BOOL	m_fIsActive;
	BOOL	m_fIsFocused;
	RECT	m_rcWnd;
};

#endif //_BMWND_H
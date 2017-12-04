#ifndef _COPTIONWND_H
#define _COPTIONWND_H


class COptionWnd : public CGameWnd
{ 
private:
protected:
	CGameBtn				m_xOptionBtn;

public:
	COptionWnd();
	~COptionWnd();

	virtual void Init();
	virtual void Destroy();

	void	CreateOptionWnd(INT nID, CWHWilImageData* pxWndImage, INT nFrameImgIdx, INT nStartX, INT nStartY, INT nWidth, INT nHeight, BOOL bCanMove);
	void	ShowOptionWnd();

	void	SetStatusBtnInit();

public:
//  메시지 함수.
	BOOL	OnLButtonDown(POINT ptMouse);
	BOOL	OnLButtonUp(POINT ptMouse);
	void	OnMouseMove(POINT ptMouse);

	void	OnScrollDown();
	void	OnScrollUp();
};


#endif // _COPTIONWND_H
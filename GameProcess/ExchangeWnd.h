#ifndef _CEXCHANGEWND_H
#define _CEXCHANGEWND_H


class CExchangeWnd : public CGameWnd
{ 
private:
protected:
public:
	virtual void Init();
	virtual void Destroy();

	CGameBtn		m_xExchangeBtn;


	CExchangeWnd();
	~CExchangeWnd();
	void	CreateExchangeWnd(INT nID, CWHWilImageData* pxWndImage, INT nFrameImgIdx, INT nStartX, INT nStartY, INT nWidth, INT nHeight, BOOL bCanMove);
	void	ShowExchangeWnd();
	void	SetStatusBtnInit();
public:
//  메시지 함수.
	BOOL	OnLButtonDown(POINT ptMouse);
	BOOL	OnLButtonUp(POINT ptMouse);
	void	OnMouseMove(POINT ptMouse);
};


#endif // _CEXCHANGEWND_H

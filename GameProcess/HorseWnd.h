#ifndef _CHORSEWND_H
#define _CHORSEWND_H


class CHorseWnd : public CGameWnd
{ 
private:
protected:
	CGameBtn				m_xHorseBtn;

public:
	CHorseWnd();
	~CHorseWnd();

	virtual void Init();
	virtual void Destroy();

	void	CreateHorseWnd(INT nID, CWHWilImageData* pxWndImage, INT nFrameImgIdx, INT nStartX, INT nStartY, INT nWidth, INT nHeight, BOOL bCanMove);
	void	ShowHorseWnd();

	void	SetStatusBtnInit();

public:
//  메시지 함수.
	BOOL	OnLButtonDown(POINT ptMouse);
	BOOL	OnLButtonUp(POINT ptMouse);
	void	OnMouseMove(POINT ptMouse);

	void	OnScrollDown();
	void	OnScrollUp();
};


#endif // _CHORSEWND_H
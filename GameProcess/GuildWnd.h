#ifndef _CGUILDWND_H
#define _CGUILDWND_H


class CGuildWnd : public CGameWnd
{ 
private:
protected:
	CGameBtn				m_xGuildBtn[5];

public:
	CGuildWnd();
	~CGuildWnd();

	virtual void Init();
	virtual void Destroy();

	void	CreateGuildWnd(INT nID, CWHWilImageData* pxWndImage, INT nFrameImgIdx, INT nStartX, INT nStartY, INT nWidth, INT nHeight, BOOL bCanMove);
	void	ShowGuildWnd();
public:
//  메시지 함수.
	BOOL	OnLButtonDown(POINT ptMouse);
	BOOL	OnLButtonUp(POINT ptMouse);
	void	OnMouseMove(POINT ptMouse);

	void	OnScrollDown();
	void	OnScrollUp();
};


#endif // _CGUILDWND_H
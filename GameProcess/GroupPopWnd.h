#ifndef _CGROUPPOPWND_H
#define _CGROUPPOPWND_H


class CGroupPopWnd : public CGameWnd
{ 
private:
protected:
	CGameBtn				m_xGroupPopBtn[5];

public:
	CGroupPopWnd();
	~CGroupPopWnd();
	void	CreateGroupPopWnd(INT nID, CWHWilImageData* pxWndImage, INT nFrameImgIdx, INT nStartX, INT nStartY, INT nWidth, INT nHeight, BOOL bCanMove);
	void	ShowGroupPopWnd();

	virtual void Init();
	virtual void Destroy();

public:
//  메시지 함수.
	BOOL	OnLButtonDown(POINT ptMouse);
	BOOL	OnLButtonUp(POINT ptMouse);
	void	OnMouseMove(POINT ptMouse);

	void	OnScrollDown();
	void	OnScrollUp();
};


#endif // _CGROUPPOPWND_H

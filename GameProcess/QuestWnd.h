#ifndef _CQUESTWND_H
#define _CQUESTWND_H


class CQuestWnd : public CGameWnd
{ 
private:
protected:
	CGameBtn				m_xQuestBtn;

public:
	CQuestWnd();
	~CQuestWnd();

	virtual void Init();
	virtual void Destroy();

	void	CreateQuestWnd(INT nID, CWHWilImageData* pxWndImage, INT nFrameImgIdx, INT nStartX, INT nStartY, INT nWidth, INT nHeight, BOOL bCanMove);
	void	ShowQuestWnd();

	void	SetStatusBtnInit();

public:
//  메시지 함수.
	BOOL	OnLButtonDown(POINT ptMouse);
	BOOL	OnLButtonUp(POINT ptMouse);
	void	OnMouseMove(POINT ptMouse);

	void	OnScrollDown();
	void	OnScrollUp();
};


#endif // _CQUESTWND_H
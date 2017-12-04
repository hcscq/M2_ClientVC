#ifndef _CCHATPOPWND_H
#define _CCHATPOPWND_H

typedef struct tagCHATSTRING
{
	DWORD	dwFontColor;
	DWORD	dwFontBackColor;
	string	strChat;
}CHATSTRING, *LPCHATSTRING;


class CChatPopWnd : public CGameWnd
{ 
private:
protected:
	CDLList<CHATSTRING> m_xstrDividedChat;		// 나누어진 채팅 데이타.
	
	CGameBtn		m_xChatPopBtn;
	RECT			m_rcChatPopFrame;			// 채팅영역.
	INT				m_nCurrStartChatLine;		// 채팅화면라인의 제일 윗줄이 가리키는 채팅리스트의 번호인덱스.
	INT				m_nCanScrlCnt;

public:
	RECT			m_rcEditBoxFrame;			

public:
	CChatPopWnd();
	~CChatPopWnd();

	virtual void Init();
	virtual void Destroy();

	BOOL	MsgAdd(DWORD dwFontColor, DWORD dwFontBackColor, CHAR* szMsg = NULL);

	void	CreateChatPopWnd(INT nID, CWHWilImageData* pxWndImage, INT nFrameImgIdx, INT nStartX, INT nStartY, INT nWidth, INT nHeight, BOOL bCanMove);
	void	ShowChatPopWnd();
	void	SetStatusBtnInit();
public:
//  메시지 함수.
	BOOL	OnLButtonDown(POINT ptMouse);
	BOOL	OnLButtonUp(POINT ptMouse);
	void	OnMouseMove(POINT ptMouse);

	void	OnScrollDown();
	void	OnScrollUp();
};


#endif // _CCHATPOPWND_H

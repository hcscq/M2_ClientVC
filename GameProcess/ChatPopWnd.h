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
	CDLList<CHATSTRING> m_xstrDividedChat;		// �������� ä�� ����Ÿ.
	
	CGameBtn		m_xChatPopBtn;
	RECT			m_rcChatPopFrame;			// ä�ÿ���.
	INT				m_nCurrStartChatLine;		// ä��ȭ������� ���� ������ ����Ű�� ä�ø���Ʈ�� ��ȣ�ε���.
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
//  �޽��� �Լ�.
	BOOL	OnLButtonDown(POINT ptMouse);
	BOOL	OnLButtonUp(POINT ptMouse);
	void	OnMouseMove(POINT ptMouse);

	void	OnScrollDown();
	void	OnScrollUp();
};


#endif // _CCHATPOPWND_H

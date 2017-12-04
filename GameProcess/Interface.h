#ifndef _INTERFACE_H
#define _INTERFACE_H



class CInterface
{ 
public:
	 CInterface();
	~CInterface();
public:
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// ��������� Message ����.
//---------------------------------------------------------------------------------------------------------------//
	ClientSysMsg	m_xClientSysMsg;
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Main Interface ó������.
//---------------------------------------------------------------------------------------------------------------//
	CWHWilImageData*	m_pxInterImg;					// ���ӻ󿡼� ����� �������̽� �̹���.
	CWHWilImageData		m_xInterImgEx;					// �������̽� ���� �̹���.

	COMMONITEMSET		m_stCommonItem;					// ���� ������ ����(���콺 ������).
	RECT				m_rcMain;						// �����������̽� ��ü ����.

	RECT				m_rcChat;						// ä��â ����.
	INT					m_nFstLine;						// ä��ȭ������� ���� ������ ����Ű�� ä�ø���Ʈ�� ��ȣ�ε���.
	CDLList<CHAT>		m_xChat;						// �������� ä�� ����Ÿ.

	CDLList<INT>		m_xWndOrderList;				
	BOOL				m_bMoveFocusedWnd;

	SHORT				m_shBeltHeight;
	BYTE				m_bBeltState;

	CGameBtn			m_xInterBtn[_MAX_INTER_BTN];	// ��ư.

	CScrlBar			m_xScrlBar;

	BOOL				m_bShowKey;

	CMirMsgBox			m_xMsgBox;						// ���.
	INT					m_nIdxMsgBox;					// ���.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Main Interface ���� �����ϴ� Window.
//---------------------------------------------------------------------------------------------------------------//
	CInventoryWnd		m_xInventoryWnd;				//����������.
	CStatusWnd			m_xStatusWnd;					//ĳ���� ���� ����������(3��).
	CStoreWnd			m_xStoreWnd;					//����������.
	CExchangeWnd		m_xExchangeWnd;					//��ȯ������.
	CGuildMasterWnd		m_xGuildMasterWnd;				//����������.
	CGuildWnd			m_xGuildWnd;					//����������.
	CGroupWnd			m_xGroupWnd;					//�׷�������.
	CGroupPopWnd		m_xGroupPopWnd;					//�׷��Է�������.
	CChatPopWnd			m_xChatPopWnd;					//�׷��Է�������.
	CNPCWnd				m_xNPCWnd;						//NPC ��ȭâ.
	CQuestWnd			m_xQuestWnd;					//����Ʈâ.
	COptionWnd			m_xOptionWnd;					//�ɼ�â.
	CHorseWnd			m_xHorseWnd;					//��â.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
public:
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// �ʱ�ȭ, ����, ����.
//---------------------------------------------------------------------------------------------------------------//
	void			Init();
	void			Destroy();
	void			CreateInterface(CImageHandler* pxImgHandler);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// ä�ø޽������� �Լ�.
//---------------------------------------------------------------------------------------------------------------//
	void			MsgAdd(DWORD dwFontColor, DWORD dwFontBackColor, CHAR* pszMsg = NULL);
	BOOL			MsgDelete();					// �޽��� ����.
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// �����������̽����� �Լ�.
//---------------------------------------------------------------------------------------------------------------//
	void			RenderInterface(INT nLoopTime, POINT ptMousePos);	// ȭ�鿡 �������̽� ���úκ��� �����ش�.

	void			ShowWndList();
	void			ShowChatList();
	void			ShowBeltItem();
	void			ShowGameStatus();
	void			ShowMagicKey();
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// ������ ����Ʈ ���� �� ����ġ �����Լ�.
//---------------------------------------------------------------------------------------------------------------//
	INT				GetWindowInMousePos(POINT ptMouse);
	void			AddWindowToList(INT nID);
	void			DeleteWindowToList(INT nID);

	BOOL			WindowActivate(INT nID);
	void			WindowFocusChangedAndSetReadyMove(INT nID, POINT ptMouse);
	void			MoveTopWindow(POINT ptMouse);
	void			AllWindowsFocusOff();
	BOOL			IsTopWindow(INT nID);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Message Funtion.
//---------------------------------------------------------------------------------------------------------------//
	void			OnSysKeyDown();
	BOOL 			OnKeyDown(WPARAM wParam, LPARAM lParam);
	BOOL 			OnKeyUp(WPARAM wParam, LPARAM lParam);
	BOOL			OnLButtonDown(POINT ptMouse);
	BOOL			OnLButtonUp(POINT ptMouse);
	BOOL			OnMouseMove(POINT ptMouse);
	BOOL			OnScrollDown();
	BOOL			OnScrollUp();
	BOOL			OnLButtonDoubleClick(POINT ptMouse);
	LRESULT			OnMsgInputted(WPARAM wParam, LPARAM lParam);
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
};



#endif // _INTERFACE_H



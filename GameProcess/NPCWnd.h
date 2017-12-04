#ifndef _CNPCWnd_H
#define _CNPCWnd_H

/*using namespace std;

*/
class CNPCWnd : public CGameWnd
{ 
public:
	INT						m_nNpcId;

protected:
	CWHWilImageData			m_xNPCImage;
	int						m_nStartLine;
	int						m_nMaxLine;

public:
	CNPCWnd();
	~CNPCWnd();
	void	CreateNPCChatWnd(INT nID, CWHWilImageData* pxWndImage, INT nFrameImgIdx, INT nStartX, INT nStartY, INT nWidth, INT nHeight, BOOL bCanMove);
	void	ShowNPCChatWnd();

	__inline void	SetNPC(int nNPCID) { m_nNpcId = nNPCID; }
	void	ResetDialog();

public:
	void SetNpcEditBoxPos(void);
	void SetWndRectReduce(void);
	void SetWndRectExtend(void);
//  메시지 함수.
	BOOL	OnLButtonDown(POINT ptMouse);
	BOOL	OnLButtonUp(POINT ptMouse);
	void	OnMouseMove(POINT ptMouse);
	BOOL	OnMsgInputted(void);

	void	OnScrollDown();
	void	OnScrollUp();
	void	OnEnterKeyDown(void);

private:
	// Command Click 처리
	BOOL	ClickCommandProcess(CMTxtBtn* ClickedBtn);		// 아래 에 있는 것들 종합
	BOOL	SendCommandToSrv(CHAR* szMsg);
	INT		m_nNpcMsgState;
	CMTxtBtn* m_pClickedTxtBtn;
	CMirMsgBox	m_xMsgBox;
/*	ClickPepairCommand(void);		// 고치다(@REPAIR)
	ClickSellCommand(void);			// 팔다(@SELL)
	ClickBuyCommand(void);			// 사다(@BUY)
	ClickBuildGuildCommand(void);	// 문파설립(@@BUILDGUILDNOW)
	ClickSpecialRepairCommand(void);// 특수수리(@SPECIALREPAIR)
	ClickMakeCommand(void);			// 만들다(@MAKE)
*/
};

#endif // _CNPCWnd_H
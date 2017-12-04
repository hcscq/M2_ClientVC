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
//  �޽��� �Լ�.
	BOOL	OnLButtonDown(POINT ptMouse);
	BOOL	OnLButtonUp(POINT ptMouse);
	void	OnMouseMove(POINT ptMouse);
	BOOL	OnMsgInputted(void);

	void	OnScrollDown();
	void	OnScrollUp();
	void	OnEnterKeyDown(void);

private:
	// Command Click ó��
	BOOL	ClickCommandProcess(CMTxtBtn* ClickedBtn);		// �Ʒ� �� �ִ� �͵� ����
	BOOL	SendCommandToSrv(CHAR* szMsg);
	INT		m_nNpcMsgState;
	CMTxtBtn* m_pClickedTxtBtn;
	CMirMsgBox	m_xMsgBox;
/*	ClickPepairCommand(void);		// ��ġ��(@REPAIR)
	ClickSellCommand(void);			// �ȴ�(@SELL)
	ClickBuyCommand(void);			// ���(@BUY)
	ClickBuildGuildCommand(void);	// ���ļ���(@@BUILDGUILDNOW)
	ClickSpecialRepairCommand(void);// Ư������(@SPECIALREPAIR)
	ClickMakeCommand(void);			// �����(@MAKE)
*/
};

#endif // _CNPCWnd_H
#ifndef _NOTICEBOX_H_
#define _NOTICEBOX_H_
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
// CMirMsgBox.h
//////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//////////////////////////////////////////////////////////////////////////////////////////
class	CNoticeBox
{
public:
	CNoticeBox();	// Constructor
	~CNoticeBox();	// Destructor

	// Function
	BOOL	IsActive(void){return m_bActive;}
	BOOL	IsInited(void){return m_bSet;}

	BOOL	StringDivideLen(INT nDivideLen, INT& nDividedLine, CHAR* szSrc,CDLList<CHAR*>* m_pxpStr);

	virtual BOOL	Load(CWHWilImageData* pxBtnImage);
	virtual BOOL	SetBoxImage(INT nImageIndex);
	virtual BOOL	SetMsg(CHAR* szMsg);
	virtual BOOL	ShowMessage(CHAR* szMsg);
	virtual BOOL	ShowMessageBox(CHAR* szMsg,INT nImgIndex);		// Show	Message box with Initialization	
	virtual BOOL	HideMessageBox(void);							// Hide Message box
	virtual BOOL	DestoryMessageBox(void);						// DestoryMessage box
	
	// Message Process
	virtual HRESULT	OnButtonDown(POINT ptMouse);					// Button Down
	virtual HRESULT	OnButtonUp(POINT ptMouse);						// Button Up
			void	MoveWnd(POINT ptMouse);							// Move Window
		
	// Render Process
	virtual BOOL	RenderMessageBox(INT nLoopTIme);				// Render Function

private:
	RECT	m_rcWnd;
	POINT	m_bGrabbedMousePos;
	BOOL	m_bActive;			// Show or Hide ??
	BOOL	m_bInited;			// Initialized ?
	BOOL	m_bSet;				// Set ?
	CHAR	m_szMsg[8196];
	WORD*	m_wpData;
	SHORT	m_shWidth;
	SHORT	m_shHeight;
	BOOL	m_bIsSelected;

	CDLList<CHAR*>		m_xMsg;		// ��µ� ����
	CGameBtn			m_xMsgBtn;
	CWHWilImageData*	m_pxBtnImage;
protected:
	__inline BOOL	IsInRect(int nPosX, int nPosY, RECT rc)	// ��Ȯ�ϰ� Rect ���� �ִ°��� üũ
	{	if (nPosX >= rc.left && nPosX <= rc.right && nPosY >= rc.top && nPosY <= rc.bottom)
			return TRUE;
		else 
			return FALSE;
	}
};

#endif  _NOTICEBOX_H_
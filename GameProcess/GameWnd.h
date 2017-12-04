#ifndef _CGAMEWND_H
#define _CGAMEWND_H


class CGameWnd
{ 
public:
	INT				m_nID;					// ������ �����ڰ� �������츦 ������ �ĺ���.
	RECT			m_rcImgWnd;				// �������� �̹����ǿ���. 
	RECT			m_rcWnd;				// �������� ȭ�鿵��. 

	INT				 m_nFrameImgIdx;		// �̹��� ���� ������. 
	CWHWilImageData* m_pxWndImage;

	BOOL			m_bActive;				// ������ Ȱ��ȭ ����. 
	BOOL			m_bFocused; 
	BOOL			m_bMoving;				// ������ �����̴����� ����.
	BOOL			m_bCanMove;				// ������ ��������.

	INT				m_nWidth;
	INT				m_nHeight;

	POINT			m_bGrabbedMousePos;
	// 3D�׽�Ʈ
	D3DVERTEX		m_avBoard[4];

public:
	__inline RECT GetGameWndRect()
	{
		return m_rcWnd;
	}
	__inline BOOL GetGameWndActive()
	{
		return m_bActive;
	}

	__inline CGameWnd()	
	{ 
		Init();
	}

	~CGameWnd()
	{
		Destroy();
	}

	virtual void Init();
	virtual void Destroy();
	virtual void ShowGameWnd();


	void ResetWndImg(INT nIdx);
	void CreateGameWnd(INT nID, CWHWilImageData* pxWndImage, INT nFrameImgIdx, BOOL bCanMove, INT nStartX, INT nStartY, INT nWidth = 0, INT nHeight = 0);
	void DestroyGameWnd();
	void SetGameWndActive(BOOL bActive);
	void SetGameWndFocused(BOOL bFocused);
	void SetReadyMove(POINT ptMouse);
	void MoveGameWnd(POINT ptMouse);
};


#endif // _CGAMEWND_H
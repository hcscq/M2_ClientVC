#ifndef _CGROUPWND_H
#define _CGROUPWND_H

class CGroupMember
{
public:
	char		szMemberName[32];
};

class CGroupWnd : public CGameWnd
{ 
public:
	CPDLList<CGroupMember>	m_xGroupList;

public:
	CGroupWnd();
	~CGroupWnd();
	virtual void Init();
	virtual void Destroy();

	void	CreateGroupWnd(INT nID, CWHWilImageData* pxWndImage, INT nFrameImgIdx, INT nStartX, INT nStartY, INT nWidth, INT nHeight, BOOL bCanMove);
	void	ShowGroupWnd();

public:
//  메시지 함수.
	BOOL	OnLButtonDown(POINT ptMouse);
	BOOL	OnLButtonUp(POINT ptMouse);
	void	OnMouseMove(POINT ptMouse);

	void	OnScrollDown();
	void	OnScrollUp();
};

#endif // _CGROUPWND_H
#ifndef _INVENTORYWND_H
#define _INVENTORYWND_H


#pragma pack(1)
typedef struct tagITEMSET
{
	BOOL	bSetted;
	CItem	xItem;
}ITEMSET, *LPITEMSET;
typedef struct tagCOMMONITEMSET
{
	BOOL	bSetted;					// �������� ���õǾ������� ����.
	BOOL	bWaitResponse;				// ���� �������� �԰ų�, ����Ǿ ������ ������ ��ٸ������� ����.
	BOOL	bIsEquipItem;				// ���� �������� ����â���κ��� �Դ����� ����.
	BOOL	bIsBeltItem;				// ���� �������� ��Ʈâ���κ��� �Դ����� ����.
	BOOL	bIsHideItem;				// ���콺������ �������� �����ٰ��ΰ�?.
	CItem	xItem;						// ������.
}COMMONITEMSET, *LPCOMMONITEMSET;
#pragma pack(8)


class CInventoryWnd : public CGameWnd
{ 
protected:
	INT			m_nStartLineNum;					// �κ��丮â�� ó�� ������ ��ȣ. (�� 10���̰� ȭ�鿡�� 4�� ���� ���� �ִ�.)
	RECT		m_rcInvenCell[_INVEN_MAX_CELL];		// �κ��丮â�� �������� ����.
	RECT		m_rcBeltCell[_BELT_MAX_CELL];

	CGameBtn	m_xInventoryBtn[_MAX_INVEN_BTN];

	CScrlBar	m_xInvenScrlBar;

public:
	ITEMSET		m_stInventoryItem[_MAX_INVEN_ITEM];
	ITEMSET		m_stBeltItem[_MAX_BELT_ITEM];

public:
	CInventoryWnd();
	~CInventoryWnd();

	virtual void Init();
	virtual void Destroy();

	void	CreateInventoryWnd(INT nID, CWHWilImageData* pxWndImage, INT nFrameImgIdx, INT nStartX, INT nStartY, INT nWidth, INT nHeight, BOOL bCanMove);
	void	ShowInventoryWnd();
	void	ShowItemStatus(LPCLIENTITEMRCD pstItemInfo);
	void	ShowInvenItemState();
	void	SetInvenBtnInit();

public:
	BOOL	CheckItemPos(CHAR* szName);
	BOOL	SaveItemPos(CHAR* szName);

	void	DeleteBeltItem(INT nBeltInventoryNum);
	void	DeleteInvenItem(INT nInventoryNum);
	void	DeleteInvenItem(INT nMakeIndex, CHAR* szName);
	void	DeleteAllBeltItem();
	void	DeleteAllInvenItem();

	BOOL	AddInvenItem(CItem xItem, INT nInvenNum, BOOL bUseInvenNum = TRUE);
	BOOL	AddBeltItem(CItem xItem, INT nBeltNum, BOOL bUseBeltNum = TRUE);

	INT		GetInvenNum(POINT ptMouse);
	INT		GetBeltNum(POINT ptMouse);

	BOOL	ExtractInvenItem(CItem* pxItem, INT nInventoryNum);
	BOOL	ExtractBeltItem(CItem* pxItem, INT nBeltInventoryNum);

	void	ChangeInvenWithCommon(INT nInventoryNum, LPCOMMONITEMSET pstCommonItemSet);
	void	ChangeBeltWithCommon(INT nBeltInventoryNum, LPCOMMONITEMSET pstCommonItemSet);

	void	SetCommonFromInven(INT nInventoryNum, LPCOMMONITEMSET pstCommonItemSet);
	void	SetCommonFromBelt(INT nBeltInventoryNum, LPCOMMONITEMSET pstCommonItemSet);

	void	SetInvenFromCommon(INT nInventoryNum, LPCOMMONITEMSET pstCommonItemSet);
	void	SetBeltFromCommon(INT nBeltInventoryNum, LPCOMMONITEMSET pstCommonItemSet);

	void	AddNewBeltItem(LPCOMMONITEMSET pstCommonItemSet);


	BOOL	OnKeyUp(LPCOMMONITEMSET pstCommonItemSet, WPARAM wParam, LPARAM lParam);
	BOOL	OnLButtonDoubleClick(LPCOMMONITEMSET pstCommonItemSet, POINT ptMouse);
	BOOL	OnLButtonDown(LPCOMMONITEMSET pstCommonItemSet, POINT ptMouse);
	BOOL	OnLButtonUp(LPCOMMONITEMSET pstCommonItemSet, POINT ptMouse);
	void	OnMouseMove(POINT ptMouse);
	void	OnScrollDown();
	void	OnScrollUp();
};



#endif // _INVENTORYWND_H
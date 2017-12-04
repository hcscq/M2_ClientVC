#ifndef _CSTATUSWND_H
#define _CSTATUSWND_H



#pragma pack(1)
typedef struct tagSTANDARDMAGIC
{
	WORD	wMagicID;
	char	szMagicName[13];
	BYTE	bEffectType;
	BYTE	bEffect;
	WORD	wSpell;
	WORD	wMinPower;
	BYTE	btNeed[4];
	INT		nTrain[4];
	BYTE	btMaxTrainLevel;
	BYTE	btJob;
	INT		nDelayTime;
	BYTE	bDefSpell;
	BYTE	btDefMinPower;
	WORD	wMaxPower;
	BYTE	btDefMaxPower;
	char	szDesc[16];
}STANDARDMAGIC, *LPSTANDARDMAGIC;

typedef struct tagCLIENTMAGICRCD
{
	INT				nCurrTrain;
	CHAR			bUseKey;
	BYTE			bLevel;
	STANDARDMAGIC	stStdMagic;
}CLIENTMAGICRCD, *LPCLIENTMAGICRCD;
#pragma pack(8)



class CStatusWnd : public CGameWnd
{ 
private:
protected:
	BYTE				m_bType;						// 0 : ����â. 1 : ĳ���� ����â.  2 : ĳ���� ���� ����â.
	CGameBtn			m_xStatusBtn[_MAX_STAUTS_BTN];

	RECT				m_rcCell[_EQUIP_MAX_CELL];		// �κ��丮â�� �������� ����.

	RECT				m_rcMagicCell[_MAGIC_MAX_CELL];	// ��������â�� �������� ����.
	INT					m_nStartLineNum;				// ����â�� ó�� ������ ��ȣ. (��������Ʈ�� ����ִ°�����ŭ ��ũ���Ҽ��ִ�..)
	BYTE				m_bMagicIdxTable[_MAX_MAGIC_SKILL];
	CGameBtn			m_xMagicScrlBtn[2];


public:
	CHAR				m_szEquipItemIdx[_EQUIP_MAX_CELL][12];
	ITEMSET				m_stEquipItem[_EQUIP_MAX_CELL];
	ITEMSET				m_stTakeOnItemSet;				// ������ų�������� ���뿩�� �޽����� ���������� �ӽ������� �����Ѵ�.

	BYTE				m_bMyMagicCnt;
	LPCLIENTMAGICRCD	m_pstMyMagic;

public:
	CStatusWnd();
	~CStatusWnd();

	virtual void Init();
	virtual void Destory();

	__inline void SetStatusWndType(BYTE bType)
	{
		m_bType = bType;
		switch ( m_bType )
		{
		case _TYPE_EQUIP:
			ResetWndImg(_WNDIMGIDX_ITEMSET);
			break;
		case _TYPE_STATUS:
			ResetWndImg(_WNDIMGIDX_STATUS);
			m_rcWnd.left -= 250;
			m_rcWnd.right-= 250;
			break;
		case _TYPE_SETMAGIC:
			ResetWndImg(_WNDIMGIDX_SKILLSET);
			break;
		}
	}
	__inline BYTE GetStatusWndType()
	{
		return m_bType;
	}

	void	CreateStatusWnd(INT nID, CWHWilImageData* pxWndImage, INT nFrameImgIdx, INT nStartX, INT nStartY, INT nWidth, INT nHeight, BOOL bCanMove);
	void	ShowStatusWnd();
	void	SetStatusBtnInit();

public:
	void	ShowCharEquipWnd();
	void	ShowEquipItemState();
	BOOL	CheckEquipItem(CItem* pxItem, BYTE bEquipCell, POINT ptMouse);
	INT		GetEquipNum(POINT ptMouse);
	BOOL	CheckIsItemExisted(INT nEquipNum);
	void	DeleteEquipItem(INT nEquipNum);
	void	DeleteEquipItem(INT nMakeIndex, CHAR* szName);
	void	DeleteAllEquipItem();
	BOOL	AddEquipItem(CItem xItem, INT nEquipNum, BOOL bUseEquipNum = TRUE);
	BOOL	ExtractEquipItem(CItem* pxItem, INT nEquipNum);
	void	ChangeEquipWithCommon(INT nEquipNum, LPCOMMONITEMSET pstCommonItemSet);
	void	SetEquipFromCommon(INT nEquipNum, LPCOMMONITEMSET pstCommonItemSet);
	void	SetCommonFromEquip(INT nEquipNum, LPCOMMONITEMSET pstCommonItemSet);
	void	SetTakeOnFromEquip(INT nEquipNum);
	void	SetTakeOnFromCommon(INT nEquipNum, LPCOMMONITEMSET pstCommonItemSet);
	void	SetEquipFromTakeOn();

	void	ShowCharStatus();

	void			 ShowCharSetMagicWnd();
	INT				 SetMagicKey(POINT ptMouse, BYTE bKey);
	LPCLIENTMAGICRCD GetMagicByKey(BYTE bKey);

	BOOL	OnLButtonDown(LPCOMMONITEMSET pstItemSet, POINT ptMouse);
	BOOL	OnLButtonUp(LPCOMMONITEMSET pstItemSet, POINT ptMouse);
	BOOL	OnKeyDown(WPARAM wParam, LPARAM lParam, POINT ptMouse);
	void	OnMouseMove(POINT ptMouse);
	void	OnScrollDown();
	void	OnScrollUp();
};


#endif // _CSTATUSWND_H
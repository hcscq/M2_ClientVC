#ifndef _CLIENTSOCKET_H
#define _CLIENTSOCKET_H

#define ID_SOCKCLIENT_EVENT_MSG		WM_USER + 1000

#include <assert.h>

class CClientSocket
{
protected:
	int					m_nCurRecv;
	CHAR				m_szBuff[8192 * 4];				// For Receive

	char				m_szEncodeDefMsg[32];			// For Send
	char				m_szEncodeBody[8192];			
	char				m_szPacket[8192 * 2];

	int					m_nSync;

	_TDEFAULTMESSAGE	DefMsg;

public:
	CClientSocket();
	virtual ~CClientSocket();

	SOCKET			m_sockClient;
	CWHDefProcess*	m_pxDefProc;

public:
	unsigned long GetINetAddr(CHAR* pszDotAddress);

	BOOL		InitSocket(HWND hWnd);	
	BOOL		ConnectToServer(HWND hWnd, CHAR* szID, INT nPort);
	BOOL		CheckSocketError(LPARAM lParam);
	BOOL		DisconnectToServer();
//	void		SendToServer(CHAR *pszPacket);
	void		SendPacket(_TDEFAULTMESSAGE* lpDefMsg, char *pszData);

	// For Login
	void		OnLogin(char *pszID, char *pszPassword);
	void		OnSelectServer(char *pszServerName);
	void		OnChangePassword(char *pszID, char *pszOldPassword, char *pszNewPassword);
	void		OnNewAccount(char *pszNewAccount);

	// For Character Select
	void		OnQueryChar();
	void		OnNewChar( char *pszId, int nHair, int nJob, int nSex );
	void		OnDelChar( char *pszCharName );
	void		OnSelChar( char *pszCharName );

	// For Game playing
	void		SendNoticeOK();

	void		SendNPCMessage(WORD wIdent,DWORD dwNpcId,INT reg,CHAR* szTxt);			// MOON
	void		SendGetDetailItem(DWORD dwNpcId,INT nIndex,CHAR* szItemName);			// MOON
	void		SendBuyItem(DWORD dwNpcId,CHAR* szItemName,CHAR* szItemIndex);			// MOON

	void		SendOpenDoor(INT nX, INT nY, INT nIdx);
	void		SendQueryMsg(WORD wIdent);
	void		SendActMsg(WORD wIdent, INT nX, INT nY, INT nDir);	
	void		SendHitMsg(WORD wIdent, INT nX, INT nY, INT nDir, WORD wHitStyle);	
	void		SendRideMsg(WORD wIdent, INT nDir, BOOL bRide);
	void		SendSpellMsg(INT nMagicID, INT nTargetX, INT nTargetY, INT nTargetID);
	void		SendSay(CHAR *pszSay);
	void		SendRunLogin(CHAR* szLoginID, CHAR* szCharName, INT nCertification, INT VersionNum);
	void		SendTakeOnOffItem(WORD wIdent, BYTE bEquipNum, CHAR* szItemName, INT nItemIdx);
	void		SendQueryName(INT nRecog, INT nX, INT nY);
	void		SendMagicKeyChange(INT nKeyNum, INT nMagicID);
	void		SendItemIndex(WORD wIdent, INT nItemIndex, CHAR* pszItemName);
	void		SendPickUp(INT nX, INT nY);
	void		SendButchAnimal(INT nX, INT nY, INT nDir, INT nActorID);
	void		SendNPCClick(INT nRecog);

	void		SendCreateGroup(char *pszWho);
	void		SendGroupMode(BOOL fFlag);
	void		SendAddGroupMember(char *pszWho);
	void		SendDelGroupMember(char *pszWho);

	void		SendGuildHome();

	LRESULT		OnSocketMessage(WPARAM wParam, LPARAM lParam);

protected:
};

#endif // _CLIENTSOCKET_H
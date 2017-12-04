#ifndef _CCLIENTMSG_H
#define _CCLIENTMSG_H


#define _MAX_SYSMSG 10
typedef struct tagCONSTSTRING
{
	CHAR szMsg[MAX_PATH];
}CONSTSTRING, *LPCONSTSTRING;

class ClientSysMsg
{ 
private:
public:
	WORD					m_wCurrDelay;
	CPDLList<CONSTSTRING>	m_stSysMsg;

	ClientSysMsg();
	~ClientSysMsg();
	void		Init();
	void		Destroy();
	void		AddSysMsg(CHAR* szStr);
	void		ShowSysMsg(INT nLoopTime, INT nX, INT nY);
};



#endif _CCLIENTMSG_H_
/******************************************************************************************************************

	CWHDXGraphicWindow Class Declaration

*******************************************************************************************************************/


#ifndef _WINDHORN_DEFPROCESS
#define _WINDHORN_DEFPROCESS


class CWHDefProcess
{
public:
	CWHDefProcess();
	~CWHDefProcess();

	void* m_pxDXGWnd;

	HRESULT	Clear(DWORD dwColor);

	virtual void	OnConnectToServer() = 0;
	virtual char*	OnMessageReceive(CHAR* pszPacketMsg) = 0;
	virtual void	ShowStatus(INT nStartX, INT nStartY);

	//Default Message Process
	virtual LRESULT DefMainWndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
};


#endif //_WINDHORN_DEFPROCESS

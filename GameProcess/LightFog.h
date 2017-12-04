/******************************************************************************************************************
                                                                                                                   
	����:																											
																													
	�ۼ���:																											
	�ۼ���:																											
																													
	[����][������] : ���� ����																						
                                                                                                                   
*******************************************************************************************************************/



#ifndef _CLIGHTFOG_H
#define _CLIGHTFOG_H

class CLightFog
{
public:
	CLightFog();
	~CLightFog();
protected://D3DVERTEX
	D3DLVERTEX			m_avLight[(NUM_CNTY_LIGHTTILE+1)][(NUM_CNTX_LIGHTTILE+1)];
	D3DLVERTEX			m_avSaveLight[(NUM_CNTY_LIGHTTILE+1)][(NUM_CNTX_LIGHTTILE+1)];
	WORD				m_pwLightIndices[NUM_LIGHTTILE_INDICES];
	DWORD				m_dwLightColor;	

public:
	void	Init(DWORD dwLightColor);
	void	ShowLightFog(WORD wScrnWidth = 400, WORD wScrnHeight =300);
	// ���� �ٲ� ���� m_avSaveLight�� �����Ų��.
	void	ChangeLightColor(DWORD dwColor);
	void	ClearSavedLightColor();
	BOOL	GetScreenPosToLightTile(INT nX, INT nY, INT* nTileX, INT* nTileY);
	BOOL	SetLightRadiusWithRing(INT XLightPos, INT YLightPos, INT nSmallRadius, 
								   INT nSmallRed, INT nSmallGreen, INT nSmallBlue, 
								   INT nLargeRadius,
								   INT nLargeRed, INT nLargeGreen, INT nLargeBlue);
	BOOL	SetLightRadiusWithCircle(INT XLightPos, INT YLightPos, INT nRadius,
									 INT nRedValue, INT nGreenValue, INT nBlueValue, 
									 FLOAT rDrakRate = 1.0f);
	BOOL	SetLightRadiusWithElipse(INT XLightPos, INT YLightPos, INT nXRadius, INT nYRadius, 
		                             INT nRedValue, INT nGreenValue, INT nBlueValue, 
									 FLOAT rDrakRate = 1.0f);
};


#endif // _CLIGHTFOG_H
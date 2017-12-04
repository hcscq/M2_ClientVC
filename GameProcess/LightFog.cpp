#include "StdAfx.h"


CLightFog::CLightFog()
{
	Init(RGB(220, 220, 220));
}


CLightFog::~CLightFog()
{
}


void CLightFog::Init(DWORD dwLightColor)
{
	m_dwLightColor = dwLightColor;

	for ( int nCntY = 0; nCntY < (NUM_CNTY_LIGHTTILE+1); nCntY++ )
	{
		for ( int nCntX = 0; nCntX < (NUM_CNTX_LIGHTTILE+1); nCntX++ )
		{
			m_avLight[nCntY][nCntX] = D3DLVERTEX(D3DXVECTOR3((FLOAT)(TILE_START_XPOS+(nCntX*TILE_WIDTH)), (FLOAT)(-TILE_START_YPOS-(nCntY*TILE_HEIGHT)), 0),
								  			     m_dwLightColor, RGB(0, 0, 0),  0, 0); 
		}
	}

	memcpy(m_avSaveLight, m_avLight, sizeof(D3DLVERTEX)*(NUM_CNTY_LIGHTTILE+1)*(NUM_CNTX_LIGHTTILE+1));

	// Å¸ÀÏÆú¸®°ïÀÇ ÀÎµ¦½º »ý¼º.
    WORD* pwIndex = m_pwLightIndices;
	for (int nCntY = 0; nCntY < NUM_CNTY_LIGHTTILE; nCntY++ )
	{
		for ( int nCntX = 0; nCntX < NUM_CNTX_LIGHTTILE; nCntX++ )
		{
			*pwIndex++ = (nCntX+1)+((NUM_CNTX_LIGHTTILE+1)*nCntY);  
			*pwIndex++ = nCntX+((NUM_CNTX_LIGHTTILE+1)*(nCntY+1));  
			*pwIndex++ = (nCntX+1)+((NUM_CNTX_LIGHTTILE+1)*(nCntY+1));
			*pwIndex++ = nCntX+((NUM_CNTX_LIGHTTILE+1)*(nCntY+1));  
			*pwIndex++ = (nCntX+1)+((NUM_CNTX_LIGHTTILE+1)*nCntY);  
			*pwIndex++ = (nCntX)+((NUM_CNTX_LIGHTTILE+1)*nCntY);
		}
	}
}


void CLightFog::ChangeLightColor(DWORD dwColor)
{
	if ( m_dwLightColor != dwColor )
	{
		for ( int nCntY = 0; nCntY < NUM_CNTY_LIGHTTILE+1; nCntY++ )
		{
			for ( int nCntX = 0; nCntX < NUM_CNTX_LIGHTTILE+1; nCntX++ )
			{
				m_avLight[nCntY][nCntX].color = dwColor;
			}
		}
		m_dwLightColor = dwColor;
		memcpy(m_avSaveLight, m_avLight, sizeof(D3DLVERTEX)*(NUM_CNTY_LIGHTTILE+1)*(NUM_CNTX_LIGHTTILE+1));
	}
}


void CLightFog::ClearSavedLightColor()
{
	memcpy(m_avLight, m_avSaveLight, sizeof(D3DLVERTEX)*(NUM_CNTY_LIGHTTILE+1)*(NUM_CNTX_LIGHTTILE+1));
}


BOOL CLightFog::GetScreenPosToLightTile(INT nX, INT nY, INT* nTileX, INT* nTileY)
{
	*nTileX = (nX - TILE_START_XPOS) / TILE_WIDTH;
	*nTileY = (nY - TILE_START_YPOS) / TILE_HEIGHT;
	
	return TRUE;
}


BOOL CLightFog::SetLightRadiusWithRing(INT XLightPos, INT YLightPos, 
									   INT nSmallRadius, 
									   INT nSmallRed, INT nSmallGreen, INT nSmallBlue, 
									   INT nLargeRadius,
									   INT nLargeRed, INT nLargeGreen, INT nLargeBlue)
{
	int nX, nY;
	GetScreenPosToLightTile(XLightPos, YLightPos, &nX, &nY);

	int nStartTileX			= nX - nLargeRadius;
	int nStartTileY			= nY - nLargeRadius;
	int nEndTileX			= nX + nLargeRadius + 1;
	int nEndTileY			= nY + nLargeRadius + 1;

	// y¸¦ ÃàÀ¸·Î ÇØ¼­ Á© ¾îµÎ¿î ºÎºÐÀ» ±¸ÇÑ´Ù.(xº¸´Ù y°¡ ´õ ÀûÀ¸¹Ç·Î)
	nLargeRadius = (nLargeRadius*TILE_HEIGHT);
	nSmallRadius = (nSmallRadius*TILE_HEIGHT);

	DOUBLE rLengthCnt		= 0;
	INT nSelectedRedValue	= 0; 
	INT nSelectedGreenValue	= 0;
	INT nSelectedBlueValue	= 0;

	if ( nStartTileX < 0 )					nStartTileX = 0;
	if ( nStartTileY < 0 )					nStartTileY = 0;
	if ( nEndTileX > NUM_CNTX_LIGHTTILE+1 )	nEndTileX = NUM_CNTX_LIGHTTILE+1;
	if ( nEndTileY > NUM_CNTY_LIGHTTILE+1 )	nEndTileY = NUM_CNTY_LIGHTTILE+1;	

	for ( INT nCntY = nStartTileY; nCntY < nEndTileY; nCntY++ )
	{
		for ( INT nCntX = nStartTileX; nCntX < nEndTileX; nCntX++ )
		{			
			rLengthCnt	= sqrt((double)(XLightPos-(nCntX*TILE_WIDTH+TILE_START_XPOS))*(XLightPos-(nCntX*TILE_WIDTH+TILE_START_XPOS)) + 
							   (YLightPos-(nCntY*TILE_HEIGHT+TILE_START_YPOS))*(YLightPos-(nCntY*TILE_HEIGHT+TILE_START_YPOS)));
			if ( nCntX < NUM_CNTX_LIGHTTILE && nCntY < NUM_CNTY_LIGHTTILE )
			{
				// Æ÷ÀÎÆ®Á¡À» Æ÷ÇÔÇÏÁö ¾Ê´Â ÁÂÇÏ. Æ÷ÀÎÆ®Á¡À» Æ÷ÇÔÇÏÁö ¾Ê´Â ¿ì»ó.
				if ( (nCntX > nX && nCntY < nY) || (nCntX < nX && nCntY > nY) )
				{
					WORD* pwIndex = ((WORD*)m_pwLightIndices+(nCntX+nCntY*(NUM_CNTX_LIGHTTILE))*6);
					*pwIndex++ = (nCntX)+((NUM_CNTX_LIGHTTILE+1)*nCntY);
					*pwIndex++ = (nCntX+1)+((NUM_CNTX_LIGHTTILE+1)*nCntY);  
					*pwIndex++ = (nCntX+1)+((NUM_CNTX_LIGHTTILE+1)*(nCntY+1));
					*pwIndex++ = (nCntX)+((NUM_CNTX_LIGHTTILE+1)*nCntY);
					*pwIndex++ = nCntX+((NUM_CNTX_LIGHTTILE+1)*(nCntY+1));  
					*pwIndex++ = (nCntX+1)+((NUM_CNTX_LIGHTTILE+1)*(nCntY+1));
				}
				else
				{
					WORD* pwIndex = ((WORD*)m_pwLightIndices+(nCntX+nCntY*(NUM_CNTX_LIGHTTILE))*6);
					*pwIndex++ = (nCntX+1)+((NUM_CNTX_LIGHTTILE+1)*nCntY);  
					*pwIndex++ = nCntX+((NUM_CNTX_LIGHTTILE+1)*(nCntY+1));  
					*pwIndex++ = (nCntX+1)+((NUM_CNTX_LIGHTTILE+1)*(nCntY+1));
					*pwIndex++ = nCntX+((NUM_CNTX_LIGHTTILE+1)*(nCntY+1));  
					*pwIndex++ = (nCntX+1)+((NUM_CNTX_LIGHTTILE+1)*nCntY);  
					*pwIndex++ = (nCntX)+((NUM_CNTX_LIGHTTILE+1)*nCntY);
				}
			}

			if ( rLengthCnt	< nSmallRadius )
			{
				nSelectedRedValue	= nSmallRed - INT((nSmallRed*rLengthCnt)/(nLargeRadius));
				nSelectedGreenValue	= nSmallGreen - INT((nSmallGreen*rLengthCnt)/(nLargeRadius));
				nSelectedBlueValue	= nSmallBlue - INT((nSmallBlue*rLengthCnt)/(nLargeRadius));
			}
			else if ( rLengthCnt >= nSmallRadius && rLengthCnt <= nLargeRadius )
			{
				nSelectedRedValue	= nLargeRed - INT((nLargeRed*rLengthCnt)/(nLargeRadius));
				nSelectedGreenValue	= nLargeGreen - INT((nLargeGreen*rLengthCnt)/(nLargeRadius));
				nSelectedBlueValue	= nLargeBlue - INT((nLargeBlue*rLengthCnt)/(nLargeRadius));
			}
			else
			{
				nSelectedRedValue = nSelectedGreenValue = nSelectedBlueValue = 0;
			}

			if ( nSelectedRedValue	 < 0 )		nSelectedRedValue	= 0;
			if ( nSelectedGreenValue < 0 )		nSelectedGreenValue = 0;
			if ( nSelectedBlueValue	 < 0 )		nSelectedBlueValue	= 0;

			if ( m_avLight[nCntY][nCntX].color == 0 )
				m_avLight[nCntY][nCntX].color = RGB(nSelectedRedValue, nSelectedGreenValue, nSelectedBlueValue); 
			else
			{
				
				nSelectedRedValue += (INT)GetBValue(m_avLight[nCntY][nCntX].color);//RGB_GETBLUE(m_avLight[nCntY][nCntX].color);
				nSelectedGreenValue += (INT)GetGValue(m_avLight[nCntY][nCntX].color);//RGB_GETGREEN(m_avLight[nCntY][nCntX].color);
				nSelectedBlueValue += (INT)GetRValue(m_avLight[nCntY][nCntX].color);//RGB_GETRED(m_avLight[nCntY][nCntX].color);

				if ( nSelectedRedValue	 > 255 )		nSelectedRedValue	= 255;
				if ( nSelectedGreenValue > 255 )		nSelectedGreenValue = 255;
				if ( nSelectedBlueValue	 > 255 )		nSelectedBlueValue	= 255;

				m_avLight[nCntY][nCntX].color =  RGB(nSelectedRedValue, nSelectedGreenValue, nSelectedBlueValue);
			}
		}
	}

	return TRUE;
}


BOOL CLightFog::SetLightRadiusWithCircle(INT XLightPos, INT YLightPos, INT nRadius, 
										 INT nRedValue, INT nGreenValue, INT nBlueValue, 
										 FLOAT rDrakRate)
{
	INT nX, nY;
	GetScreenPosToLightTile(XLightPos, YLightPos, &nX, &nY);

	INT nStartTileX			= nX - nRadius;
	INT nStartTileY			= nY - nRadius;
	INT nEndTileX			= nX + nRadius + 1;
	INT nEndTileY			= nY + nRadius + 1;

	// y¸¦ ÃàÀ¸·Î ÇØ¼­ Á© ¾îµÎ¿î ºÎºÐÀ» ±¸ÇÑ´Ù.(xº¸´Ù y°¡ ´õ ÀûÀ¸¹Ç·Î)
	nRadius = (nRadius*TILE_HEIGHT);

	DOUBLE rLengthCnt		= 0;
	INT nSelectedRedValue	= 0; 
	INT nSelectedGreenValue	= 0;
	INT nSelectedBlueValue	= 0;

	if ( nStartTileX < 0 )					nStartTileX = 0;
	if ( nStartTileY < 0 )					nStartTileY = 0;
	if ( nEndTileX > NUM_CNTX_LIGHTTILE+1 )	nEndTileX = NUM_CNTX_LIGHTTILE+1;
	if ( nEndTileY > NUM_CNTY_LIGHTTILE+1 )	nEndTileY = NUM_CNTY_LIGHTTILE+1;	

	for ( INT nCntY = nStartTileY; nCntY < nEndTileY; nCntY++ )
	{
		for ( INT nCntX = nStartTileX; nCntX < nEndTileX; nCntX++ )
		{			
			rLengthCnt	= sqrt((double)(XLightPos-(nCntX*TILE_WIDTH+TILE_START_XPOS))*(XLightPos-(nCntX*TILE_WIDTH+TILE_START_XPOS)) + 
							   (YLightPos-(nCntY*TILE_HEIGHT+TILE_START_YPOS))*(YLightPos-(nCntY*TILE_HEIGHT+TILE_START_YPOS)));
			if ( nCntX < NUM_CNTX_LIGHTTILE && nCntY < NUM_CNTY_LIGHTTILE )
			{
				// Æ÷ÀÎÆ®Á¡À» Æ÷ÇÔÇÏÁö ¾Ê´Â ÁÂÇÏ. Æ÷ÀÎÆ®Á¡À» Æ÷ÇÔÇÏÁö ¾Ê´Â ¿ì»ó.
				if ( (nCntX > nX && nCntY < nY) || (nCntX < nX && nCntY > nY) )
				{
					WORD* pwIndex = ((WORD*)m_pwLightIndices+(nCntX+nCntY*(NUM_CNTX_LIGHTTILE))*6);
					*pwIndex++ = (nCntX)+((NUM_CNTX_LIGHTTILE+1)*nCntY);
					*pwIndex++ = (nCntX+1)+((NUM_CNTX_LIGHTTILE+1)*nCntY);  
					*pwIndex++ = (nCntX+1)+((NUM_CNTX_LIGHTTILE+1)*(nCntY+1));
					*pwIndex++ = (nCntX)+((NUM_CNTX_LIGHTTILE+1)*nCntY);
					*pwIndex++ = nCntX+((NUM_CNTX_LIGHTTILE+1)*(nCntY+1));  
					*pwIndex++ = (nCntX+1)+((NUM_CNTX_LIGHTTILE+1)*(nCntY+1));
				}
				else
				{
					WORD* pwIndex = ((WORD*)m_pwLightIndices+(nCntX+nCntY*(NUM_CNTX_LIGHTTILE))*6);
					*pwIndex++ = (nCntX+1)+((NUM_CNTX_LIGHTTILE+1)*nCntY);  
					*pwIndex++ = nCntX+((NUM_CNTX_LIGHTTILE+1)*(nCntY+1));  
					*pwIndex++ = (nCntX+1)+((NUM_CNTX_LIGHTTILE+1)*(nCntY+1));
					*pwIndex++ = nCntX+((NUM_CNTX_LIGHTTILE+1)*(nCntY+1));  
					*pwIndex++ = (nCntX+1)+((NUM_CNTX_LIGHTTILE+1)*nCntY);  
					*pwIndex++ = (nCntX)+((NUM_CNTX_LIGHTTILE+1)*nCntY);
				}
			}

/*			RECT rc;
			SetRect(&rc,
				   (nCntX*TILE_WIDTH+TILE_START_XPOS),
				   (nCntY*TILE_HEIGHT+TILE_START_YPOS),
				   (nCntX*TILE_WIDTH+TILE_START_XPOS+TILE_WIDTH),
				   (nCntY*TILE_HEIGHT+TILE_START_YPOS+TILE_HEIGHT));
			g_xMainWnd.DrawWithGDI(rc, NULL, RGB(0, 255, 255), 1);
*/
			if ( rLengthCnt	<= nRadius )
			{
				nSelectedRedValue	= nRedValue - INT((nRedValue*rLengthCnt*rDrakRate)/(nRadius));
				nSelectedGreenValue	= nGreenValue - INT((nGreenValue*rLengthCnt*rDrakRate)/(nRadius));
				nSelectedBlueValue	= nBlueValue - INT((nBlueValue*rLengthCnt*rDrakRate)/(nRadius));
/*				SetRect(&rc,
					   (nCntX*TILE_WIDTH+TILE_START_XPOS),
					   (nCntY*TILE_HEIGHT+TILE_START_YPOS),
					   (nCntX*TILE_WIDTH+TILE_START_XPOS+2),
					   (nCntY*TILE_HEIGHT+TILE_START_YPOS+2));
				g_xMainWnd.DrawWithGDI(rc, NULL, RGB(255, 0, 0), 1);
*/			}
			else
			{
				nSelectedRedValue = nSelectedGreenValue = nSelectedBlueValue = 0;
			}

			if ( nSelectedRedValue	 < 0 )		nSelectedRedValue	= 0;
			if ( nSelectedGreenValue < 0 )		nSelectedGreenValue = 0;
			if ( nSelectedBlueValue	 < 0 )		nSelectedBlueValue	= 0;

			if ( m_avLight[nCntY][nCntX].color == 0 )
				m_avLight[nCntY][nCntX].color = RGB(nSelectedRedValue, nSelectedGreenValue, nSelectedBlueValue); 
			else
			{
				nSelectedRedValue += (INT)GetBValue(m_avLight[nCntY][nCntX].color);//RGB_GETBLUE(m_avLight[nCntY][nCntX].color);
				nSelectedGreenValue += (INT)GetGValue(m_avLight[nCntY][nCntX].color);//RGB_GETGREEN(m_avLight[nCntY][nCntX].color);
				nSelectedBlueValue += (INT)GetRValue(m_avLight[nCntY][nCntX].color);//RGB_GETRED(m_avLight[nCntY][nCntX].color);

				if ( nSelectedRedValue	 > 255 )		nSelectedRedValue	= 255;
				if ( nSelectedGreenValue > 255 )		nSelectedGreenValue = 255;
				if ( nSelectedBlueValue	 > 255 )		nSelectedBlueValue	= 255;

				m_avLight[nCntY][nCntX].color =  RGB(nSelectedRedValue, nSelectedGreenValue, nSelectedBlueValue);
			}
		}
	}

	return TRUE;
}


BOOL CLightFog::SetLightRadiusWithElipse(INT XLightPos, INT YLightPos, INT nXRadius, INT nYRadius, 
										 INT nRedValue, INT nGreenValue, INT nBlueValue, 
										 FLOAT rDrakRate)
{
	INT nX, nY;
	GetScreenPosToLightTile(XLightPos, YLightPos, &nX, &nY);

	INT nStartTileX			= nX - nXRadius;
	INT nStartTileY			= nY - nYRadius;
	INT nEndTileX			= nX + nXRadius + 1;
	INT nEndTileY			= nY + nYRadius + 1;
	
	FLOAT rXRadius = (FLOAT)(nXRadius*TILE_WIDTH);
	FLOAT rYRadius = (FLOAT)(nYRadius*TILE_HEIGHT);
	INT	  nRadius  = 0;

	if ( rXRadius > rYRadius )
	{
		nRadius = (INT)rXRadius;
	}
	else
	{
		nRadius = (INT)rYRadius;
	}

	DOUBLE rLengthCnt		= 0;
	INT nSelectedRedValue	= 0; 
	INT nSelectedGreenValue	= 0; 
	INT nSelectedBlueValue	= 0; 

	if ( nStartTileX < 0 )					nStartTileX = 0;
	if ( nStartTileY < 0 )					nStartTileY = 0;
	if ( nEndTileX > NUM_CNTX_LIGHTTILE+1 )	nEndTileX = NUM_CNTX_LIGHTTILE+1;
	if ( nEndTileY > NUM_CNTY_LIGHTTILE+1 )	nEndTileY = NUM_CNTY_LIGHTTILE+1;


	for ( INT nCntY = nStartTileY; nCntY < nEndTileY; nCntY++ )
	{
		for ( INT nCntX = nStartTileX; nCntX < nEndTileX; nCntX++ )
		{
			if ( nCntX < NUM_CNTX_LIGHTTILE && nCntY < NUM_CNTY_LIGHTTILE )
			{
				// Æ÷ÀÎÆ®Á¡À» Æ÷ÇÔÇÏÁö ¾Ê´Â ÁÂÇÏ. Æ÷ÀÎÆ®Á¡À» Æ÷ÇÔÇÏÁö ¾Ê´Â ¿ì»ó.
				if ( (nCntX > nX && nCntY < nY) || (nCntX < nX && nCntY > nY) )
				{
					WORD* pwIndex = ((WORD*)m_pwLightIndices+(nCntX+nCntY*(NUM_CNTX_LIGHTTILE))*6);
					*pwIndex++ = (nCntX)+((NUM_CNTX_LIGHTTILE+1)*nCntY);
					*pwIndex++ = (nCntX+1)+((NUM_CNTX_LIGHTTILE+1)*nCntY);  
					*pwIndex++ = (nCntX+1)+((NUM_CNTX_LIGHTTILE+1)*(nCntY+1));
					*pwIndex++ = (nCntX)+((NUM_CNTX_LIGHTTILE+1)*nCntY);
					*pwIndex++ = nCntX+((NUM_CNTX_LIGHTTILE+1)*(nCntY+1));  
					*pwIndex++ = (nCntX+1)+((NUM_CNTX_LIGHTTILE+1)*(nCntY+1));
				}
				else
				{
					WORD* pwIndex = ((WORD*)m_pwLightIndices+(nCntX+nCntY*(NUM_CNTX_LIGHTTILE))*6);
					*pwIndex++ = (nCntX+1)+((NUM_CNTX_LIGHTTILE+1)*nCntY);  
					*pwIndex++ = nCntX+((NUM_CNTX_LIGHTTILE+1)*(nCntY+1));  
					*pwIndex++ = (nCntX+1)+((NUM_CNTX_LIGHTTILE+1)*(nCntY+1));
					*pwIndex++ = nCntX+((NUM_CNTX_LIGHTTILE+1)*(nCntY+1));  
					*pwIndex++ = (nCntX+1)+((NUM_CNTX_LIGHTTILE+1)*nCntY);  
					*pwIndex++ = (nCntX)+((NUM_CNTX_LIGHTTILE+1)*nCntY);
				}
			}

/*			RECT rc;
			SetRect(&rc,
				   (nCntX*TILE_WIDTH+TILE_START_XPOS),
				   (nCntY*TILE_HEIGHT+TILE_START_YPOS),
				   (nCntX*TILE_WIDTH+TILE_START_XPOS+TILE_WIDTH),
				   (nCntY*TILE_HEIGHT+TILE_START_YPOS+TILE_HEIGHT));
			g_xMainWnd.DrawWithGDI(rc, NULL, RGB(0, 255, 255), 1);
*/
	
			INT nCurrCntXRate, nCurrCntYRate;
			if ( rXRadius > rYRadius )		
			{
				nCurrCntXRate = nCntX;
				nCurrCntYRate = nCntY + (INT)((nCntY-nY)*(FLOAT)(rXRadius/rYRadius-1.0f));
			}
			else if ( rXRadius < rYRadius )										
			{
				nCurrCntXRate = nCntX + (INT)((nCntX-nX)*(FLOAT)(rYRadius/rXRadius-1.0f));
				nCurrCntYRate = nCntY;
			}
			else
			{
				nCurrCntXRate = nCntX;
				nCurrCntYRate = nCntY;
			}

			rLengthCnt	= sqrt((double)(XLightPos-(nCurrCntXRate*TILE_WIDTH+TILE_START_XPOS))*(XLightPos-(nCurrCntXRate*TILE_WIDTH+TILE_START_XPOS)) + 
							   (YLightPos-(nCurrCntYRate*TILE_HEIGHT+TILE_START_YPOS))*(YLightPos-(nCurrCntYRate*TILE_HEIGHT+TILE_START_YPOS)));

/*			SetRect(&rc,
				   (XLightPos),
				   (YLightPos),
				   (XLightPos+5),
				   (YLightPos+5));
			g_xMainWnd.DrawWithGDI(rc, NULL, RGB(255, 0, 0), 1);
*/
			if ( rLengthCnt	<= nRadius )
			{
				nSelectedRedValue	= nRedValue - INT((nRedValue*rLengthCnt*rDrakRate)/(nRadius));
				nSelectedGreenValue	= nGreenValue - INT((nGreenValue*rLengthCnt*rDrakRate)/(nRadius));
				nSelectedBlueValue	= nBlueValue - INT((nBlueValue*rLengthCnt*rDrakRate)/(nRadius));
	/*			SetRect(&rc,
					   (nCntX*TILE_WIDTH+TILE_START_XPOS),
					   (nCntY*TILE_HEIGHT+TILE_START_YPOS),
					   (nCntX*TILE_WIDTH+TILE_START_XPOS+2),
					   (nCntY*TILE_HEIGHT+TILE_START_YPOS+2));
				g_xMainWnd.DrawWithGDI(rc, NULL, RGB(255, 0, 0), 1);
	*/			}
			else
			{
				nSelectedRedValue = nSelectedGreenValue = nSelectedBlueValue = 0;
			}

			if ( nSelectedRedValue	 < 0 )		nSelectedRedValue	= 0;
			if ( nSelectedGreenValue < 0 )		nSelectedGreenValue = 0;
			if ( nSelectedBlueValue	 < 0 )		nSelectedBlueValue	= 0;

			if ( m_avLight[nCntY][nCntX].color == 0 )
				m_avLight[nCntY][nCntX].color = RGB(nSelectedRedValue, nSelectedGreenValue, nSelectedBlueValue); 
			else
			{
				if ( nSelectedRedValue < (INT)GetBValue(m_avLight[nCntY][nCntX].color) )//RGB_GETBLUE(m_avLight[nCntY][nCntX].color) )
					nSelectedRedValue = (INT)GetBValue(m_avLight[nCntY][nCntX].color);
				if ( nSelectedGreenValue < (INT)GetGValue (m_avLight[nCntY][nCntX].color) )
					nSelectedGreenValue = (INT)GetGValue (m_avLight[nCntY][nCntX].color);
				if ( nSelectedBlueValue < (INT)GetRValue (m_avLight[nCntY][nCntX].color) )
					nSelectedBlueValue = (INT)GetRValue (m_avLight[nCntY][nCntX].color);

				m_avLight[nCntY][nCntX].color =  RGB(nSelectedRedValue, nSelectedGreenValue, nSelectedBlueValue);
			}
		}
	}

	return TRUE;
}




void CLightFog::ShowLightFog(WORD wHalfScrnWidth, WORD wHalfScrnHeight)
{
	if ( g_xMainWnd.Get3DDevice() )
	{
		if( SUCCEEDED(g_xMainWnd.Get3DDevice()->BeginScene()) )
		{
			D3DXVECTOR3 vTrans;
			D3DMATRIX matTrans;
			D3DMATRIX matWorldOriginal;

			g_xMainWnd.Get3DDevice()->GetTransform(D3DTS_WORLD, &matWorldOriginal);

			g_xMainWnd.Get3DDevice()->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);
			g_xMainWnd.Get3DDevice()->SetRenderState(D3DRS_SRCBLEND,  D3DBLEND_ZERO);
			g_xMainWnd.Get3DDevice()->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_SRCCOLOR);
			
			vTrans.x = -wHalfScrnWidth; vTrans.y = wHalfScrnHeight; vTrans.z = 0;
			D3DUtil_SetTranslateMatrix(matTrans, vTrans);
			g_xMainWnd.Get3DDevice()->SetTransform(D3DTS_WORLD, &matTrans);
			g_xMainWnd.Get3DDevice()->SetTexture(0, NULL);
			g_xMainWnd.Get3DDevice()->SetRenderState(D3DRS_LIGHTING, FALSE);


			IDirect3DIndexBuffer9 *IB=0;
			g_xMainWnd.Get3DDevice()->CreateIndexBuffer(NUM_LIGHTTILE_INDICES*sizeof(WORD),D3DUSAGE_WRITEONLY,D3DFMT_INDEX32,D3DPOOL_MANAGED,&IB,0);
			WORD *indices=0;
			IB->Lock(0,0,(void**)&indices,0);
			for(int i=0;i<NUM_LIGHTTILE_INDICES;i++)
				indices[i]=m_pwLightIndices[i];
			IB->Unlock();

			IDirect3DVertexBuffer9 *VB=0;
			g_xMainWnd.Get3DDevice()->CreateVertexBuffer(NUM_LIGHTTILE_VERTICES*sizeof(D3DLVERTEX),D3DUSAGE_WRITEONLY,D3DFVF_LVERTEX,D3DPOOL_MANAGED,&VB,0);
			D3DLVERTEX *vertex=0;
			VB->Lock(0,0,(void**)&vertex,0);
			for(int i=0;i<NUM_LIGHTTILE_VERTICES;i++)
				vertex[i]=m_avLight[i];
			VB->Unlock();

			g_xMainWnd.Get3DDevice()->SetStreamSource(0,VB,0,sizeof(D3DLVERTEX));
			g_xMainWnd.Get3DDevice()->SetIndices(IB);
			g_xMainWnd.Get3DDevice()->SetFVF(D3DFVF_LVERTEX);

			//Í¼ÔªÊý ÉÐ²»È·¶¨
			g_xMainWnd.Get3DDevice()->DrawIndexedPrimitive(D3DPT_TRIANGLELIST,0,0,NUM_LIGHTTILE_VERTICES,0,NUM_LIGHTTILE_INDICES/3);
														  //D3DFVF_LVERTEX,
														  //m_avLight, NUM_LIGHTTILE_VERTICES, 
														  //m_pwLightIndices, NUM_LIGHTTILE_INDICES, NULL );
			g_xMainWnd.Get3DDevice()->SetRenderState(D3DRS_LIGHTING, TRUE);

			g_xMainWnd.Get3DDevice()->SetRenderState(D3DRS_SRCBLEND,  D3DBLEND_ONE);
			g_xMainWnd.Get3DDevice()->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ZERO);
			g_xMainWnd.Get3DDevice()->SetRenderState(D3DRS_ALPHABLENDENABLE, FALSE);

			g_xMainWnd.Get3DDevice()->SetTransform(D3DTS_WORLD, &matWorldOriginal);

			g_xMainWnd.Get3DDevice()->EndScene();
		}
	}
}

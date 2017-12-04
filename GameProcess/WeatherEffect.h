#ifndef _CWEATHER_H
#define _CWEATHER_H

#define _MIST_STATE_START 0


class CMist
{
public:
	BOOL	m_bActive;
	BYTE	m_bMistState;	

	D3DVERTEX m_avBillboard[4];
	D3DXVECTOR3 m_vTrans;
	D3DXVECTOR3 m_vScale;	

private:

public:
	CMist();
	~CMist();
	BOOL Create();			// 안개 생성.	
	void Init();			// 안개 변수 초기화.
	void Destory();			// 텍스춰등의 메모리해제.
	HRESULT DrawMist();
	void ProgressMist();	// 안개 진행.(안개시작시점, 안개진행, 안개종료시점에서 서로 다르다.)
};

/*
class CRain
{
public:
	BOOL	m_bActive;
	D3DVERTEX m_avBillboard[4];
	CParticle m_xParticles;

private:

public:
	CRain();
	~CRain();
	BOOL Create();			
	void Init();			
	void Destory();			
	HRESULT DrawRain();
	void ProgressRain();	
};


class CSnow
{
public:
	BOOL	m_bActive;
	D3DVERTEX m_avBillboard[4];
	CParticle m_xParticles;

private:

public:
	CSnow();
	~CSnow();
	BOOL Create();			
	void Init();			
	void Destory();			
	HRESULT DrawSnow();
	void ProgressSnow();	
};
*/
 
class CAirWave
{
#define _MAX_X	276
#define _MAX_Y	185
#define _CURR	0
#define _NEW	1
#define _DAMP	4
public:
	BYTE	m_bDispLut[512];

	BYTE	m_bCurr, m_bNew;

public:
	CAirWave();
	~CAirWave();
	void	InitAirWave();
	void	UpdateAirWave();
	void	DropAirWaveMap(INT nX, INT nY, INT nW, INT nMulFactor);
	void	RenderAirWave();
};

#endif // _CWEATHER_H
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
	BOOL Create();			// �Ȱ� ����.	
	void Init();			// �Ȱ� ���� �ʱ�ȭ.
	void Destory();			// �ؽ������ �޸�����.
	HRESULT DrawMist();
	void ProgressMist();	// �Ȱ� ����.(�Ȱ����۽���, �Ȱ�����, �Ȱ������������ ���� �ٸ���.)
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
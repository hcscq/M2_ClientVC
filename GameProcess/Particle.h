/******************************************************************************************************************
                                                                                                                   
	����:																											
																													
	�ۼ���:																											
	�ۼ���:																											
																													
	[����][������] : ���� ����																						
                                                                                                                   
*******************************************************************************************************************/


#ifndef _CPARTICLE_H
#define _CPARTICLE_H


#define _RAND_FLOAT			((FLOAT)(rand()%1000)/1000.0f)



/******************************************************************************************************************

	CParticle Class

*******************************************************************************************************************/
class CParticle
{
public:
//------------------------------------------------------------------------------------------------------------------
// ���ڰ��� ����.
	WORD					m_wLife;					// ����.
	WORD					m_wCurrLife;				// �������.
	D3DXVECTOR3				m_vecPos;					// ��ǥ.
	D3DXVECTOR3				m_vecOldPos;				// ��ǥ ����.
	D3DXVECTOR3				m_vecVel;					// �ӵ�.
	D3DXVECTOR3				m_vecAccel;					// ���ӵ�.
	D3DXVECTOR3				m_vecLocalForce;			// ��ƼŬ�� ���� ������ �ִ� ��.
	FLOAT					m_fMass;					// ����.
	FLOAT					m_fSize;					// ũ��.
	BOOL					m_bIsDead;					// ��ƼŬ�� ���翩��.
	BYTE					m_bRed, m_bGreen, m_bBlue;	// ��.
	BYTE					m_bOpa;

	FLOAT					m_fOriSize;					// ó��ũ��.
	BYTE					m_bFstRed, m_bFstGreen, m_bFstBlue;	// ��ƼŬ ���������ǻ�.
	BYTE					m_bEndRed, m_bEndGreen, m_bEndBlue;	// ��ƼŬ ��������ǻ�.
//------------------------------------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------------------------
// ���� Frame���� ����.
	WORD					m_wDelay;					// Animation Delay.
	WORD					m_wCurrDelay;
	WORD					m_wCurrFrame;				
//------------------------------------------------------------------------------------------------------------------
public:
	__inline CParticle()
	{
		Init();
	}
	__inline void Init()
	{
		m_wLife			= 0;		
		m_vecPos		= D3DXVECTOR3(0, 0, 0);		
		m_vecOldPos		= D3DXVECTOR3(0, 0, 0);		
		m_vecVel		= D3DXVECTOR3(0, 0, 0);		
		m_vecAccel		= D3DXVECTOR3(0, 0, 0);		
		m_vecLocalForce	= D3DXVECTOR3(0, 0, 0);
		m_fMass			= 0.0f;
		m_fSize			= 0.0f;	
		m_fOriSize		= 0.0f;	
		m_bIsDead		= TRUE;		

		m_bRed = m_bGreen =  m_bBlue = 255;
		m_bFstRed = m_bFstGreen = m_bFstBlue = 255;
		m_bEndRed = m_bEndGreen = m_bEndBlue = 255;
		m_wDelay		= 0;		
		m_wCurrDelay	= 0;
		m_wCurrFrame	= 0;	
		m_wCurrLife		= 0;
		m_bOpa			= 255;
	}
};



/******************************************************************************************************************

	CParticleSystem Class
	��ƼŬ ���� Base Class

*******************************************************************************************************************/
class CParticleSystem
{
protected:
//	FLOAT					m_fAirFiction;			// ���⸶������.(�ٶ�.)
//	D3DXVECTOR3				m_vecEnvironment;		// ���ڿ� �ۿ��ϴ� ȯ�溯��(�߷�, �ٶ�).
	D3DXVECTOR3				m_vecBounding[2];		// �浹üũ���� ����.

	WORD					m_wNum;					// ������ ����.
	CParticle*				m_pxParticle;			// ���� ��ü.
    D3DVERTEX				m_avShape[4];			// Vertex.

	FLOAT					m_fDeltaTime;

public:
	D3DXVECTOR3				m_vecEnvironment;		// ���ڿ� �ۿ��ϴ� ȯ�溯��(�߷�, �ٶ�).
	FLOAT					m_fAirFiction;			// ���⸶������.(�ٶ�.)

	CParticleSystem();
	~CParticleSystem();

	void UpdateAirFiction(WORD wNum);				// ���⸶����� ����.
	void UpdateMove(WORD wNum);						// �߷��� ����.
	void UpdateCrash(WORD wNum);					// �浹�ݹ߷� ����.

	__inline void SetEnvFactor(FLOAT fAirFriction = -0.05f, 
							   D3DXVECTOR3 vecEnvironment = D3DXVECTOR3(0, 300, 0), 
							   D3DXVECTOR3 vecMinBound = D3DXVECTOR3(0, 0, 0), 
							   D3DXVECTOR3 vecMaxBound = D3DXVECTOR3(0, 0, 0))
	{
		m_fAirFiction	 = fAirFriction;
		m_vecEnvironment = vecEnvironment;
		m_vecBounding[0] = vecMinBound;
		m_vecBounding[1] = vecMaxBound;
	}

	virtual void	InitSystem();
	virtual void	SetupSystem(WORD wCnt = 200);
	virtual void	DestroySystem();
	virtual void	LoadTextr()								 = 0;
    virtual HRESULT RenderSystem(LPDIRECT3DDEVICE9 lpDevice) = 0;
	virtual void	UpdateSystem(INT nLoopTime, D3DXVECTOR3 vecGenPos) = 0;
	virtual void	SetParticleDefault(WORD wNum, D3DXVECTOR3 vecGenPos) = 0;
};



/******************************************************************************************************************

	CSnow Class	

*******************************************************************************************************************/
#define _MAX_SNOWFRAME	1

class CSnow : public CParticleSystem
{
private:
	CHAR	m_szSnowFile[_MAX_SNOWFRAME][MAX_PATH];	
    FLOAT	m_fWidth, m_fGround;

public:
    CSnow();
    ~CSnow();

	virtual void	LoadTextr();
	virtual void	InitSystem();
	virtual void	DestroySystem();
	virtual void	SetupSystem(WORD wCnt = 500, FLOAT fWidth = 800, FLOAT fGround = 600);
    virtual HRESULT RenderSystem(LPDIRECT3DDEVICE9 lpDevice);

	virtual void	UpdateSystem(INT nLoopTime, D3DXVECTOR3 vecGenPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	virtual void	SetParticleDefault(WORD wNum, D3DXVECTOR3 vecGenPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f));
};



/******************************************************************************************************************

	CRain Class

*******************************************************************************************************************/
#define _MAX_RAINFRAME		1
#define _MAX_RAINDROPFRAME	5

class CRain : public CParticleSystem
{
private:
	CHAR	m_pszRainFile[_MAX_RAINFRAME][MAX_PATH];	
	CHAR	m_pszRainDropFile[_MAX_RAINDROPFRAME][MAX_PATH];

    FLOAT	m_fWidth, m_fGround;

	BYTE	m_bRainIntensity;			// ���ǰ���.

public:
	BYTE	m_bGenCnt;					

    CRain();
    ~CRain();

	virtual void	LoadTextr();
	virtual void	InitSystem();
	virtual void	DestroySystem();
	virtual void	SetupSystem(WORD wCnt = 400, FLOAT fWidth = 800, FLOAT fGround = 600);
    virtual HRESULT RenderSystem(LPDIRECT3DDEVICE9 lpDevice);

	virtual void	UpdateSystem(INT nLoopTime, D3DXVECTOR3 vecGenPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	virtual void	SetParticleDefault(WORD wNum, D3DXVECTOR3 vecGenPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	D3DXVECTOR3 a;
};



/******************************************************************************************************************

	CFly Class
	���ư��� ������ Praticle����.(������ ����)

*******************************************************************************************************************/
#define _MAX_FLYFRAME	10

class CFly : public CParticleSystem
{
private:
	CHAR	m_pszFlyFile[_MAX_FLYFRAME][MAX_PATH];	
	BYTE	m_bGenCnt;					

public:
	CFly();
	~CFly();
		
	virtual void	LoadTextr();
	virtual void	InitSystem();
	virtual void	DestroySystem();
	virtual void	SetupSystem(WORD wCnt = 100);
    virtual HRESULT RenderSystem(LPDIRECT3DDEVICE9 lpDevice);

	virtual void	UpdateSystem(INT nLoopTime, D3DXVECTOR3 vecGenPos);
	virtual void	SetParticleDefault(WORD wNum, D3DXVECTOR3 vecGenPos);
};



/******************************************************************************************************************

	CBoom
	���� ������ Praticle����.

*******************************************************************************************************************/
#define _MAX_BOOMFRAME	10

class CBoom : public CParticleSystem
{
private:
	CHAR	m_pszBoomFile[_MAX_BOOMFRAME][MAX_PATH];
	SHORT	m_shPartNum;

public:
	CBoom();
	~CBoom();
		
	virtual void	LoadTextr();
	virtual void	InitSystem();
	virtual void	DestroySystem();
	virtual void	SetupSystem(WORD wCnt = 1000);
    virtual HRESULT RenderSystem(LPDIRECT3DDEVICE9 lpDevice);

	void	SetBoomParticle(D3DXVECTOR3 vecGenPos);

	virtual void	UpdateSystem(INT nLoopTime, D3DXVECTOR3  vecGenPos = D3DXVECTOR3(0, 0, 0));
	virtual void	SetParticleDefault(WORD wNum, D3DXVECTOR3 vecGenPos);
};



/******************************************************************************************************************

	CFlyingTail
	���ư��� ������ Praticle����.

*******************************************************************************************************************/
#define _MAX_FLYTAILFRAME	10

class CFlyingTail : public CParticleSystem
{
private:
	CHAR	m_pszFlyingTailFile[_MAX_FLYTAILFRAME][MAX_PATH];	
	SHORT	m_shPartNum;

public:
	CFlyingTail();
	~CFlyingTail();
		
	virtual void	LoadTextr();
	virtual void	InitSystem();
	virtual void	DestroySystem();
	virtual void	SetupSystem(WORD wCnt = 500);
    virtual HRESULT RenderSystem(LPDIRECT3DDEVICE9 lpDevice);

	void	SetFlyTailParticle(D3DXVECTOR3 vecGenPos);

	virtual void	UpdateSystem(INT nLoopTime, D3DXVECTOR3 vecGenPos = D3DXVECTOR3(0, 0, 0));
	virtual void	SetParticleDefault(WORD wNum, D3DXVECTOR3 vecGenPos);
};









/******************************************************************************************************************

	CSmoke

*******************************************************************************************************************/
#define _MAX_SMOKEFRAME		1
class CSmoke : public CParticleSystem
{
private:
	CHAR	m_pszSmokeFile[_MAX_SMOKEFRAME][MAX_PATH];	
	SHORT	m_shPartNum;
public:
	CSmoke();
	~CSmoke();
		
	virtual void	LoadTextr();
	virtual void	InitSystem();
	virtual void	DestroySystem();
	virtual void	SetupSystem(WORD wCnt = 100);
    virtual HRESULT RenderSystem(LPDIRECT3DDEVICE9 lpDevice);

	void	SetSmokeParticle(D3DXVECTOR3 vecGenPos);

	virtual void	UpdateSystem(INT nLoopTime, D3DXVECTOR3 vecGenPos = D3DXVECTOR3(0, 0, 0));
	virtual void	SetParticleDefault(WORD wNum, D3DXVECTOR3 vecGenPos);
};



/******************************************************************************************************************

	CElec
	���� ���� Praticle����.

*******************************************************************************************************************/
#define _MAX_ELECFRAME	1
#define _MAX_ELEC_NODEX	2
#define _MAX_ELEC_NODEY	10
#define _ELEC_INDICES	_MAX_ELEC_NODEX*_MAX_ELEC_NODEY*3*2
#define _ELEC_VERTICES	(_MAX_ELEC_NODEX+1)*(_MAX_ELEC_NODEY+1)
class CElec
{
private:
	CHAR		m_szElecFile[_MAX_ELECFRAME][MAX_PATH];	

	SHORT		m_shPosX, m_shPosY;
	SHORT		m_shDstPosX, m_shDstPosY;

	FLOAT		m_fSize;
	FLOAT		m_fRadian;

	D3DVERTEX	m_avElec[_MAX_ELEC_NODEY+1][_MAX_ELEC_NODEX+1];
	D3DVERTEX	m_avSaveElec[_MAX_ELEC_NODEY+1][_MAX_ELEC_NODEX+1];
//	D3DLVERTEX	m_avElec[_MAX_ELEC_NODE+1][2];
	WORD		m_pwElecIndices[_ELEC_INDICES];
public:
	CElec();
	~CElec();

	void		LoadTextr();

	void		InitElec();
	void		DestroyElec();

	void		SetupElec();

	void		UpdateElec(SHORT shPosX, SHORT shPosY, SHORT shDstPosX, SHORT shDstPosY);

	HRESULT		RenderElec(LPDIRECT3DDEVICE9 lpDevice);
};



#endif // _CPARTICLE_H
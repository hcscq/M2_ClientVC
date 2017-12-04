#ifndef _WINDHORN_
#define	_WINDHORN_

//////////////////////////////////////////////////////////////////////////////////////
//#define STRICT
#define D3D_OVERLOADS
//////////////////////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <windowsx.h>
#include <mmsystem.h>
#include <ddraw.h>
#include<d3dx9.h>
#include <d3d9.h>
#include <stdio.h>
#include <tchar.h>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <dsound.h>
#include <dshow.h>
#include <crtdbg.h>
#include <dinput.h>
#include <d3d9types.h>


#define D3DFVF_LVERTEX ( D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_SPECULAR | D3DFVF_TEX1 )

//#define D3DFVF_VERTEX ( D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1 )

#pragma comment(lib, "dinput8.lib")

#pragma comment (lib, "dxguid.lib")
#pragma comment (lib, "ddraw.lib")
#pragma comment (lib, "d3dim.lib")
#pragma comment (lib, "winmm.lib")
#pragma comment (lib, "wininet.lib")
#pragma comment (lib, "dsound.lib")
#pragma comment(lib, "d3d9.lib")
#define _WINDHORN_CLASS				_T("WH GEngine")

#define _SCREEN_WIDTH				800
#define _SCREEN_HEIGHT				600
#define _SCREEN_BPP					16

#define _DXG_SCREENMODE_WINDOW		1
#define _DXG_SCREENMODE_FULLSCREEN	2
#define _DXG_DEVICEMODE_PRIMARY		1
#define _DXG_DEVICEMODE_SECONDARY	2
#define _DXG_DEVICEMODE_D3D			4
#define _DXG_DEVICEMODE_ZBUFFER		8
#define _DXG_FONT_NORMAL			0
#define _DXG_FONT_ITALIC			1
#define _DXG_FONT_UNDERLINE			2
#define _DXG_FONT_BOLD				3

#define _MAX_DEVICES			    10

#define  SAFE_DELETE(p)				{ if ( p ) { delete ( p );     ( p ) = NULL; } }
#define  SAFE_RELEASE(p)			{ if ( p ) { ( p )->Release(); ( p ) = NULL; } }
#define  D3DFVF_VERTEX (D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_TEX1)
struct D3DVERTEX 
{
	float _x,_y,_z;
	float _nx,_ny,_nz;
	float _u,_v;
	D3DVERTEX(float x=0,float y=0,float z=0,float nx=0,float ny=0,float nz=0,float u=0,float v=0){
		_x=x;
		_y=y;
		_z=z;
		_nx=nx;
		_ny=ny;
		_nz=nz;
		_u=u;
		_v=v;
	}
};

typedef struct _D3DLVERTEX {
	union {
		D3DVALUE x; 
		D3DVALUE dvX;
	};
	union {
		D3DVALUE y;
		D3DVALUE dvY;
	};
	union {
		D3DVALUE z;
		D3DVALUE dvZ;
	};
	DWORD  dwReserved;
	union {
		D3DCOLOR color;
		D3DCOLOR dcColor;
	};
	union {
		D3DCOLOR specular;
		D3DCOLOR dcSpecular;
	};
	union {
		D3DVALUE tu;
		D3DVALUE dvTU;
	};
	union {
		D3DVALUE tv;
		D3DVALUE dvTV;
	};
#if(DIRECT3D_VERSION >= 0x0500)
#if (defined __cplusplus) && (defined D3D_OVERLOADS)
	_D3DLVERTEX() { }
	_D3DLVERTEX(const D3DVECTOR& v, D3DCOLOR _color, D3DCOLOR _specular, float _tu, float _tv)
	{ x = v.x; y = v.y; z = v.z; dwReserved = 0;
	color = _color; specular = _specular;
	tu = _tu; tv = _tv;
	}
#endif
#endif /* DIRECT3D_VERSION >= 0x0500 */
} D3DLVERTEX, *LPD3DLVERTEX;

#define D3DENUMRET_OK true

#include "WHImage.h"
#include "WHWindow.h"
#include "WHDefProcess.h"
#include "WHDXGraphic.h"
#include "WHWilImage.h"
#include "WH3DInit.h"
#include "WHSurface.h"
#include "WHWilTexture.h"

#include "RegHandler.h"

#include ".\D3DCommon\D3DUtil.h"
#include ".\D3DCommon\D3DTextr.h"
#include ".\D3DCommon\D3DMath.h"
#include ".\D3DCommon\DDUtil.h"

#endif //_WINDHORN_

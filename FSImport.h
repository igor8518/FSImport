#pragma once

//**************************************************************************/
// Copyright (c) 1998-2007 Autodesk, Inc.
// All rights reserved.
// 
// These coded instructions, statements, and computer programs contain
// unpublished proprietary information written by Autodesk, Inc., and are
// protected by Federal copyright law. They may not be disclosed to third
// parties or copied or duplicated in any form, in whole or in part, without
// the prior written consent of Autodesk, Inc.
//**************************************************************************/
// DESCRIPTION: Includes for Plugins
// AUTHOR: 
//***************************************************************************/

#include "3dsmaxsdk_preinclude.h"
#include "resource.h"
#include <istdplug.h>
#include <iparamb2.h>
#include <iparamm2.h>
#include <maxtypes.h>
#include <triobj.h>
#include <impapi.h>

//SIMPLE TYPE


#include <impexp.h>
#include <direct.h>
#include <commdlg.h>
#include <stdmat.h>

typedef unsigned short ushort;
typedef unsigned char uchar;
typedef unsigned int uint;
typedef struct {
	unsigned char r, g, b;
} Color_24;
typedef struct {
	uchar type; /* MAP_TYPE_UV, MAP_TYPE_SXP */
	ushort texflags;
	void *sxp_data;
	Bitmap *bm;
	float texblur;		/* texture blur  */
	float uscale, vscale;
	float uoffset, voffset;
	float ang_sin, ang_cos;
	Color_24 col1, col2;  /* tinting colors */
	Color_24 rcol, gcol, bcol;  /* RGB tinting colors */
} MapParams;
typedef struct {
	uchar shade;		/* shading level for auto-cubic */
	uchar aalevel;		/* anti-alias level for auto-cubic */
	ushort flags;		/* auto cubic flags */
	int size;			/* bitmap size for auto-cubic */
	int nth;				/* do nth frame for auto-cubic */
} AutoCubicParams;
typedef struct {
	AutoCubicParams acb;  /* auto-cubic params */
	Bitmap *bm;
	Bitmap *blurbm;
} RMapParams;


typedef struct {
	uchar ok;
	uchar kind;		/* Texture(0) or Reflection map (1)*/
	TCHAR name[13];
	union {
		MapParams tex;	  /* kind == 0 */
		RMapParams ref;  /* kind == 1 */
	} p;
} MapData;
typedef struct {
	uchar use;
	union { float f; int pct; } amt;
	MapData map;
	MapData mask;
} Mapping;
struct SMtl {
	TCHAR name[17];		 	/* Material's 16-TCHAR name		*/
	Color_24 amb;		 	/* 0-255 triplets			*/
	Color_24 diff;			 /* 0-255 triplets			*/
	Color_24 spec;		 	/* 0-255 triplets			*/
	short transparency;	/* 0-100	*/
	short shading;		 	/* 0=WIRE 1=FLAT 2=GOURAUD 3=PHONG 4=METAL	*/
	ulong flags;		 	/* Material flags	*/
	ushort use;   			/* Use  flags */

							/* Effect percent sliders */
	short shininess;	 	/* 0-100	   */
	short shin2pct;		/* 0-100    */
	short shin3pct;		/* 0-100    */
	short xpfall;			/* 0-100   	*/
	short refblur;			/* 0-100   	*/
	short selfipct;	  	/* 0-100    */
	float wiresize;   /* size of wire frame */

	Mapping *map[8];
	void *appdata;
};
extern TCHAR *GetString(int id);

extern HINSTANCE hInstance;

/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2010-2012 - Hans-Kristian Arntzen
 *  Copyright (C) 2011-2012 - Daniel De Matteis
 * 
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _XDK360_VIDEO_H
#define _XDK360_VIDEO_H

#include <stdint.h>

#define DFONT_MAX	4096
#define PRIM_FVF	(D3DFVF_XYZRHW | D3DFVF_TEX1)

#define MIN_SCALING_FACTOR (1.0f)
#define MAX_SCALING_FACTOR (2.0f)

typedef struct
{
   float x;
   float y;
   float z;
   float rhw;
   float u;
   float v;
} primitive_t;

typedef struct DrawVerticeFormats
{
   float x, y;
   float u, v;
} DrawVerticeFormats;

#ifdef _XBOX1
/* Direct3D 8 */
#define LPDIRECT3D_PTR LPDIRECT3D8
#define LPDIRECT3DDEVICE_PTR LPDIRECT3DDEVICE8
#define LPDIRECT3DTEXTURE_PTR LPDIRECT3DTEXTURE8
#define LPDIRECT3DSURFACE_PTR LPDIRECT3DSURFACE8

#define D3DVIEWPORT D3DVIEWPORT8
#define D3DVERTEXELEMENT D3DVERTEXELEMENT8

#define direct3d_create_ctx Direct3DCreate8
#define IDirect3DVertexBuffer IDirect3DVertexBuffer8

#define SetSamplerState SetTextureStageState

#define D3DSAMP_ADDRESSU D3DTSS_ADDRESSU
#define D3DSAMP_ADDRESSV D3DTSS_ADDRESSV
#define D3DSAMP_MAGFILTER D3DTSS_MAGFILTER
#define D3DSAMP_MINFILTER D3DTSS_MINFILTER
#else
/* Direct3D 9 */
#define LPDIRECT3D_PTR LPDIRECT3D9
#define LPDIRECT3DDEVICE_PTR LPDIRECT3DDEVICE9
#define LPDIRECT3DTEXTURE_PTR LPDIRECT3DTEXTURE9
#define LPDIRECT3DSURFACE_PTR LPDIRECT3DSURFACE9

#define D3DVIEWPORT D3DVIEWPORT9
#define D3DVERTEXELEMENT D3DVERTEXELEMENT9

#define direct3d_create_ctx Direct3DCreate9
#define IDirect3DVertexBuffer IDirect3DVertexBuffer9
#define IDirect3DVertexDeclaration IDirect3DVertexDeclaration9
#endif

typedef struct xdk360_video
{
   bool block_swap;
   bool fbo_enabled;
   bool should_resize;
   bool quitting;
   bool vsync;
   unsigned frame_count;
   unsigned last_width;
   unsigned last_height;
   LPDIRECT3D_PTR d3d_device;
   LPDIRECT3DDEVICE_PTR d3d_render_device;
   IDirect3DVertexBuffer *vertex_buf;
   LPDIRECT3DTEXTURE_PTR lpTexture;
   D3DTexture lpTexture_ot_as16srgb;
   LPDIRECT3DTEXTURE_PTR lpTexture_ot;
#ifdef _XBOX360
   IDirect3DVertexDeclaration9* v_decl;
#endif
   D3DPRESENT_PARAMETERS d3dpp;
   XVIDEO_MODE video_mode;
   LPDIRECT3DSURFACE_PTR lpSurface;
} xdk360_video_t;

#endif

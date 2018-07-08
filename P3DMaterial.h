#pragma once
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
class RIFFMATE
{
	int    material_flags;			//
	int    material_flags_2;		//
	int    diffuse_texture_index;	//?texDiffuseMap
	int    detail_texture_index;	//texDetailMap
	int    bumpmap_texture_index;	//?texBumpMap
	int    specular_texture_index;	//?texSpecularMap
	int    emissive_texture_index;	//?texEmissiveMap
	int    reflection_texture_index;//?texReflectionMap
	int    fresnel_texture_index;	//texFresnelRamp     
	float  diffuse_color_R;			//?colorDiffuse
	float  diffuse_color_G;			//
	float  diffuse_color_B;			//
	float  diffuse_color_A;			//
	float  specular_color_R;		//?colorSpecular
	float  specular_color_G;		//
	float  specular_color_B;		//
	float  specular_color_A;		//
	float  specular_power;			//
	float  detail_map_scale;		//
	float  bump_map_scale;			//
	float  reflection_scale;		//
	float  precipitation_offset;	//fPrecipOffset = 0.0
	float  specular_map_power_scale;//fSpecMapPowerScale = 64
	float  specular_bloom_floor;	//fSpecularBloomFloor = 0.9
	float  ambient_light_scale;		//fAmbientLightScale = 1.0
	int    source_blend;			//iSrcBlend = 2 (srcColor)
	int    destination_blend;		//iDstBlend = 1 (one)
	int    alpha_test_function;		//
	float  alpha_test_threshold;	//
	float  final_alpha_multiply;	//
};

//material_flags
#define material_is_specular							0x00000001 //
#define material_has_a_diffuse_texture					0x00000002 //
#define material_has_a_bumpmap_texture					0x00000004 //
#define material_has_a_specular_texture					0x00000008 //
#define material_has_a_detail_texture					0x00000010 //
#define material_has_a_reflection_texture				0x00000020 //
#define Use_global_environment_map_as_reflection		0x00000040 //
#define material_has_an_emissive_texture				0x00000080 //
#define material_has_a_FresnelRamp_texture_Reflection	0x00000100 //
#define material_has_a_FresnelRamp_texture_Diffuse		0x00000200 //
#define material_has_a_FresnelRamp_texture_Specular		0x00000400 //
#define Apply_offset_to_start_of_Precipitation			0x00000800 //
#define Take_into_account_Precipitation					0x00001000 //
#define Blend_environment_by_inverse_of_diffuse_alpha	0x00002000 //
#define Blend_environment_by_specular_map_alpha			0x00004000 //
#define Assume_vertical_normal							0x00008000 //
#define Z_Write_alpha									0x00010000 //
#define No_Z_Write										0x00020000 //
#define Bloom_material_by_copying						0x00040000 //
#define Bloom_material_modulating_by_alpha				0x00080000 //
#define Volume_shadow									0x00100000 //
#define No_shadow										0x00200000 //
#define Z_Test_Alpha									0x00400000 //
#define Emissive_Mode_Blend								0x00800000 //
#define Set_final_alpha_value_at_render_time			0x01000000 //

#define Skinned_mesh									0x04000000 //
#define Allow_bloom										0x08000000 //
#define Allow_emissive_bloom							0x10000000 //
#define Blend_diffuse_by_diffuse_alpha					0x20000000 //
#define Blend_diffuse_by_inverse_of_specular_map_alpha	0x40000000 //
#define Prelit_vertices									0x80000000 //

//material_flags_2
#define Blend_constant									0x00000001 //
#define Force_Texture_Address_Wrap						0x00000002 //
#define Force_Texture_Address_Clamp						0x00000004 //
#define Double_sided									0x00000008 //
#define Emissive_Mode_AdditiveNightOnlyUserControlled	0x00000010 //
#define Emissive_Mode_BlendUserControlled				0x00000020 //
#define Emissive_Mode_MultiplyBlend						0x00000040 //
#define Emissive_Mode_MultiplyBlendUserControlled		0x00000080 //
#define Emissive_Mode_Additive							0x00000100 //
#define Emissive_Mode_AdditiveUserControlled			0x00000200 //

enum Blend
{
	zero = 1,
	one,
	srcColor,
	invSrcColor,
	srcAlpha,
	invSrcAlpha,
	destAlpha,
	invDestAlpha,
	destColor,
	invDestColor
};

enum Alpha_test
{
	never = 1,
	less,
	equal,
	lessEqual,
	greater,
	notEqual,
	greaterEqual,
	always
};

class P3DMaterial : public StdMat2
{
public:
	virtual void GetClassName(MSTR& s) { s = MSTR(_M("P3DMaterial")); }
	int ConvertPrepar3DMaterials(RIFFMATE *mate);
};

P3DMaterial *NewP3DMat();


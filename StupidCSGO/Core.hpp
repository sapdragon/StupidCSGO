#pragma once

/* Types describes all sorts of fucked up shit like defines, and different structures that are the base. */

/* Defines types of calls */
#define CDECL __cdecl
#define STDCALL __stdcall
#define FASTCALL __fastcall
#define THISCALL __thiscall
#define VECTORCALL __vectorcall

#define WIN32 STDCALL

#define FORCEINLINE __forceinline

/* Pair of types ( thanks Terry Davis and srd17 ) )*/
typedef char i8; typedef unsigned char u8;
typedef short i16; typedef unsigned short u16;
typedef int i32; typedef unsigned int u32;
typedef long long i64; typedef unsigned long long u64;
typedef float f32; typedef double f64;
typedef wchar_t wc16;


/* Includes */

/* Windows */
#include <Windows.h>

/* STL */
#include <string>
#include <vector>
#include <algorithm>
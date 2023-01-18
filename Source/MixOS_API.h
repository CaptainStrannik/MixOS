#pragma once

#include <windows.h>

#include "resource.h"
#include "Names.h"

#define MIXOS_VER		"Beta 2.2"
#define MP_VER			MIXOS_VER
//#define TERMINAL_VER	"Beta 1.2"
//#define PIANO_VER		"Beta 1.1"
//#define EMULATE_VER		"Beta 2.0"
//#define YOUTUBE_VER		"Beta 1.1"
//#define MENUMAKER_VER	"Beta 1.0"

#define TYPE_MIXOS_HWND		0x00
#define TYPE_MP_HWND		TYPE_MIXOS_HWND
//#define TYPE_TERMINAL_HWND	1
//#define TYPE_PIANO_HWND		2
//#define TYPE_EMULATE_HWND	3
//#define TYPE_YOUTUBE_HWND	4
//#define TYPE_MENUMAKER_HWND	5

#define TYPE_COMP_MIXOS_VER		0x10
#define TYPE_COMP_MP_VER		

LPVOID MixGetInfo(BYTE cType, LPCVOID lpcvData);
BOOL MixSendInfo(BYTE cType, LPCVOID lpcvData);
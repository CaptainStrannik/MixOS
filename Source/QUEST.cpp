#include <windows.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <tchar.h>
#include <wchar.h>
#include "resource.h"
#include"targetver.h"
#include "framework.h"
#include "targetver.h"
#include <conio.h>
#include <shlobj.h>
#include <ks.h>     
#include <string>    
#include<mciapi.h>                 
#include<Mmsystem.h>
#include "Names.h"
#include "bass.h"  
#include "LoveInQuest.h"
#define STRANNI 90     

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "bass")
#pragma comment(linker,"/manifestdependency:\"type='win32' \
                        name='Microsoft.Windows.Common-Controls' \
                        version='6.0.0.0' processorArchitecture='*'\
 publicKeyToken='6595b64144ccf1df' language='*'\"")

using namespace std;
char str1[1024];
HSTREAM QUEST_THEME;
HSTREAM KILL;
HSTREAM LADAV;
HSTREAM SVOBODA;
HSTREAM SCREAM;
HSTREAM REMIX;
HSTREAM KAVINSKY;
HSTREAM ROSB;
HSTREAM MODEL;
HSTREAM PUTIN;
HSTREAM KAVUL;
HSTREAM JACKSON;
HICON progicon;
int skins;
TCHAR StrT[MAX_PATH];
HANDLE bmpwall;
HANDLE bmpwall1;
HWND hwall;
static COLORREF acrCustClr[16];
HBRUSH hBrush = CreateSolidBrush(RGB(255, 128, 0));
static DWORD rgbCurrent = RGB(255, 128, 0);
HWND hTrack;
HDC hdc;
PAINTSTRUCT ps;
const TCHAR progname[] = _T("Ўашнахме квест");
HWND tardis;
//bool key_pressed = false;
HINSTANCE hInst;

static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {

    case WM_CREATE: {
        

        SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);

        NOTIFYICONDATA data;
        ZeroMemory(&data, sizeof(NOTIFYICONDATA));


        data.cbSize = sizeof(data);
        data.hWnd = hWnd;
        data.uID = 1;          // ћожно поставить любой идентификатор, всЄ равно иконка только одна
        data.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
        data.uCallbackMessage = WM_USER_SHELLICON;
        data.hIcon = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\quest.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        data.uVersion = NOTIFYICON_VERSION;

        /*     strcpy(data.szInfoTitle, "«агрузчик видео с Youtube");*/
        strcpy(data.szTip, "Ўашнахме квест");

 
        Shell_NotifyIcon(NIM_ADD, &data);



        HMENU hMenubar = CreateMenu();
        HMENU hAbout = CreateMenu();
        HMENU hOptions = CreateMenu();


        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "—правка");
        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hOptions, "Ќастройки");



        SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
        AppendMenu(hAbout, MF_STRING, STRANNIK, "ќ программе");
        AppendMenu(hAbout, MF_STRING, STRANNI, "Ўашнахме");


        AppendMenu(hOptions, MF_STRING, MYCOLOR, "—менить цвет");
        AppendMenu(hOptions, MF_SEPARATOR, NULL, NULL);
        AppendMenu(hOptions, MF_STRING, polupon, "¬ключить полупрозрачность");
        AppendMenu(hOptions, MF_STRING, polupoff, "¬ыключить полупрозрачность");

        SetMenu(hWnd, hMenubar);
        BASS_Init(-1, 44100, 0, 0, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ќачать игру"), WS_VISIBLE | WS_CHILD, 200, 100, 250, 150, hWnd, (HMENU)ID_BUTTON, NULL, NULL);


        
        
        break;
        

    }
    case WM_COMMAND: {
        
        //ShowWindow(GetDlgItem(hWnd, LENMUSIC), SW_SHOW);



        if (LOWORD(wParam) == polupon)
        {

            SetLayeredWindowAttributes(hWnd, NULL, 230, LWA_ALPHA);
        }
        if (LOWORD(wParam) == polupoff)
        {

            SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);
        }




        if (LOWORD(wParam) == STRANNIK)
        {
            ShellAbout(hWnd, progname, "–азработчик: Captain Strannik, ѕомощник: Z_Kraf1er_Z", progicon);
            MessageBoxA(hWnd, "Ётот квест €вл€етс€ всего лишь больной фантазией автора. Ќе воспринимайте всерьез. ” вас же толста€ кость?", "ќ программе", MB_OK);
        }
        if (LOWORD(wParam) == STRANNI)
        {
            SCREAM = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\skrimer.mp3", 0, 0, 0);
            BASS_ChannelPlay(SCREAM, false);
            REMIX = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\REMIX.mp3", 0, 0, 0);
            BASS_ChannelPlay(REMIX, false);
            MessageBoxA(hWnd, "ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈", "ЎјЎЌј’ћ≈", MB_ICONERROR);
            MessageBoxA(hWnd, "ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈", "ЎјЎЌј’ћ≈", MB_ICONERROR);
            MessageBoxA(hWnd, "ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈", "ЎјЎЌј’ћ≈", MB_ICONERROR);
            MessageBoxA(hWnd, "ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈", "ЎјЎЌј’ћ≈", MB_ICONERROR);
            MessageBoxA(hWnd, "ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈", "ЎјЎЌј’ћ≈", MB_ICONERROR);
            MessageBoxA(hWnd, "ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈", "ЎјЎЌј’ћ≈", MB_ICONERROR);
            MessageBoxA(hWnd, "ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈", "ЎјЎЌј’ћ≈", MB_ICONERROR);
            MessageBoxA(hWnd, "ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈", "ЎјЎЌј’ћ≈", MB_ICONERROR);
            MessageBoxA(hWnd, "ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈", "ЎјЎЌј’ћ≈", MB_ICONERROR);
            MessageBoxA(hWnd, "ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈", "ЎјЎЌј’ћ≈", MB_ICONERROR);
            MessageBoxA(hWnd, "ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈", "ЎјЎЌј’ћ≈", MB_ICONERROR);
            MessageBoxA(hWnd, "ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈", "ЎјЎЌј’ћ≈", MB_ICONERROR);
            MessageBoxA(hWnd, "ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈ЎјЎЌј’ћ≈", "ЎјЎЌј’ћ≈", MB_ICONERROR);
            BASS_Stop();
            BASS_Start();
        }
        if (LOWORD(wParam) == ID_BUTTON)
        {
            
            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
            QUEST_THEME = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\quest.mp3", 0, 0, 0);
            BASS_Stop();
            BASS_Start();
            BASS_ChannelPlay(QUEST_THEME, false);
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT(""), WS_VISIBLE | WS_CHILD, 225, 10, 450, 12, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("¬ы находитесь в темном переулке, впереди от вас светит свет,сзади тьма, справа от вас лестница, ведуща€ наверх.\n уда пойдем?"), WS_VISIBLE | WS_CHILD | SS_CENTER, 100, 10, 450, 50, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("¬перед "), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)FIRST, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Ќазад "), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)SECOND, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("ѕодн€тьс€ по лестнице "), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)THIRD, NULL, NULL);

            CreateWindow(TEXT("STATIC"), TEXT("√ромкость"), WS_VISIBLE | WS_CHILD, 210+60, 180+80+30-10, 200, 20, hWnd, (HMENU)text1, NULL, NULL);
            hTrack = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | WS_VISIBLE, 210, 180+80-20, 200, 20, hWnd, (HMENU)LENMUSIC, NULL, NULL);

            //SetWindowLong(hWnd, GWL_STYLE, WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE);
            //CreateWindow(_T("STATIC"), _T("Ќе дл€ шашнахме"), WS_VISIBLE | WS_CHILD, 650, 60, 150, 20, hWnd, (HMENU)text1, NULL, NULL);
            //tardis = CreateWindow(_T("LISTBOX"), _T("“елепортер 3000"), WS_CHILD | LBS_HASSTRINGS | LBS_WANTKEYBOARDINPUT | WS_VSCROLL|WS_VISIBLE, 650, 100, 120, 150, hWnd, NULL, NULL, NULL);
            //CreateWindow(_T("BUTTON"), _T("“елепортаци€"), WS_CHILD | WS_VISIBLE, 650, 270, 120, 22, hWnd, (HMENU)TELEPORT, NULL, NULL);
        }
        if (LOWORD(wParam) == FIRST)
        {
            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));

            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);

            CreateWindow(TEXT("STATIC"), TEXT(""), WS_VISIBLE | WS_CHILD, 225, 10, 450, 12, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("ѕройд€ 32 шага вы попали в комнату, где сто€т три машины: BMW X5, LADA VESTA, Toyota Camri. » все они открыты, «абирай не хочу!                                                                                     "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);


            CreateWindow(TEXT("BUTTON"), TEXT("—есть в Toyota"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)FIRST2, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("—есть в BMW"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)SECOND2, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("—есть в LADA "), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)THIRD2, NULL, NULL);


        }
        if (LOWORD(wParam) == SECOND)
        {
            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));

            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT(""), WS_VISIBLE | WS_CHILD, 225, 10, 450, 12, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("  сожалению вы упали в пропасть, с жизнью у вас все шашнахме... »гра окончена =( ћораль: Ќикогда не ходите назад. ƒаже по жизни двигайтесь только вперед. » получитс€ все, что захотите =)"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            BASS_ChannelStop(QUEST_THEME);
            BASS_ChannelStop(LADAV);
            KILL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\kill.mp3", 0, 0, 0);
            BASS_ChannelPlay(KILL, false);

        }
        if (LOWORD(wParam) == THIRD)
        {
            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));

            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);

            CreateWindow(TEXT("STATIC"), TEXT("ѕодн€вшись по лестнице вы подн€лись на крышу здани€. Ќа которой стоит вертолет, машина и велосипед.  уда с€дем?                                                                                              "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);


            CreateWindow(TEXT("BUTTON"), TEXT("—есть в велосипед"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)VELOSIPED, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("—есть в машину"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)MASHINA, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("—есть в вертолет "), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)HELICOPTER, NULL, NULL);
        }

        if (LOWORD(wParam) == VELOSIPED)
        {
            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("                —ев на велосипед вы увидели трамплин                                                                                                                                                             "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("ѕоехать на велосипеде"), WS_VISIBLE | WS_CHILD, 220, 75, 185, 35, hWnd, (HMENU)VELOSIPED1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("—лезть с велосипеда"), WS_VISIBLE | WS_CHILD, 220, 115, 185, 35, hWnd, (HMENU)VELOSIPED2, NULL, NULL);
        }

        if (LOWORD(wParam) == VELOSIPED1)
        {
            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("¬ы что? —овсем шашнахме? ѕон€тно почему. ¬ы пересмотрели √олливудские фильмы. ¬ы серьЄзно думали, что проехав на велике и спрыгнув с крыши вы выживете? ћда.... ћораль: <<”чите науку, чтобы в жизни не попадать в подобные ситуации, ведь жизнь это вам не игра!>>"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            BASS_ChannelStop(QUEST_THEME);
            BASS_ChannelStop(LADAV);
            KILL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\kill.mp3", 0, 0, 0);
            BASS_ChannelPlay(KILL, false);

        }
        if (LOWORD(wParam) == VELOSIPED2)
        {

            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_SHOW);
            CreateWindow(TEXT("STATIC"), TEXT("¬ы все же решили слезть с велосипеда и сесть в другой транспорт"), WS_VISIBLE | WS_CHILD, 100, 10, 470, 80, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("—есть в велосипед"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)VELOSIPED3, NULL, NULL);


 

        }

        if (LOWORD(wParam) == VELOSIPED3)
        {
            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED3), SW_HIDE);
            /*CreateWindow(TEXT("STATIC"), TEXT(""), WS_VISIBLE | WS_CHILD, 225, 10, 450, 12, hWnd, (HMENU)text1, NULL, NULL);*/
            CreateWindow(TEXT("STATIC"), TEXT("ƒела€ нелогичные действи€ в игре,вы дали пон€ть разработчику, что вы шашнахме, поэтому он удалил велосипед, чтобы вы не делали тупые действи€"), WS_VISIBLE | WS_CHILD, 100, 10, 480, 80, hWnd, (HMENU)text1, NULL, NULL);

        }
        if (LOWORD(wParam) == MASHINA)
        {
            ShowWindow(GetDlgItem(hWnd, VELOSIPED3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("Ёто оказалась машина времени. ¬ ней куча кнопочек и циферблатов. ј также потоковый накопитель =). ¬ общем, в какое врем€ полетим?"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("¬ далекое будущее"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)FUTURE, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("¬ далекое прошлое"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)BACK, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("ѕонажимать кнопки"), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)SUDBA, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("ѕолетать по ночному небу"), WS_VISIBLE | WS_CHILD, 220, 195, 185, 35, hWnd, (HMENU)FLY, NULL, NULL);
        }

        if (LOWORD(wParam) == FUTURE)
        {
            ShowWindow(GetDlgItem(hWnd, VELOSIPED3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FUTURE), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, BACK), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SUDBA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FLY), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("¬ы попали в далекое будущее, где «емл€ была чиста€, все следили за природой. » все было хорошо.  ћораль:<<—ледите за природой, не будьте шашнахме>> "), WS_VISIBLE | WS_CHILD, 100, 10, 480, 80, hWnd, (HMENU)text1, NULL, NULL);
            BASS_ChannelStop(QUEST_THEME);
            MODEL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\Model.mp3", 0, 0, 0);
            BASS_ChannelPlay(MODEL, false);

        }
        if (LOWORD(wParam) == BACK)
        {
            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FUTURE), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, BACK), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SUDBA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FLY), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("¬ы попали в далекое прошлое и попали в лес. ¬ котором через 10 минут вас убил динозавр. »гра окончена. ћораль:                       <<Ќе ходите дети в лес одни. “ем более в доисторический>>. "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            BASS_ChannelStop(QUEST_THEME);
            BASS_ChannelStop(LADAV);
            KILL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\kill.mp3", 0, 0, 0);
            BASS_ChannelPlay(KILL, false);

        }
        if (LOWORD(wParam) == SUDBA)
        {
            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FUTURE), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, BACK), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SUDBA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FLY), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("ѕотыкав пару кнопок вы случайно нажали на кнопку деактивации машины, котора€ просто активировала взрывчатку. » через 5 секунд вы взорвались. ћораль: <<Ќе играйте дети c незнакомой вам техникой. „итайте документацию>>."), WS_VISIBLE | WS_CHILD, 100, 10, 480, 80, hWnd, (HMENU)text1, NULL, NULL);
            BASS_ChannelStop(QUEST_THEME);
            BASS_ChannelStop(LADAV);
            KILL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\kill.mp3", 0, 0, 0);
            BASS_ChannelPlay(KILL, false);
        }
        if (LOWORD(wParam) == FLY)
        {
            ShowWindow(GetDlgItem(hWnd, VELOSIPED3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FUTURE), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, BACK), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SUDBA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FLY), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("¬ы включили трек Kavinsky - Testarossa Autodrive и умчались вперед =). ћораль..  ј кака€ тут может быть мораль? ¬ы сломали систему!      "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            BASS_ChannelStop(QUEST_THEME);
            KAVUL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\Testarossa Autodrive.mp3", 0, 0, 0);
            BASS_ChannelPlay(KAVUL, false);

        }
        if (LOWORD(wParam) == HELICOPTER)
        {
            ShowWindow(GetDlgItem(hWnd, VELOSIPED3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("«а всю жизнь вы летали на вертолете всего 1 раз, и то, это было в игре GTA VICE CITY. Ќо ничего, со временем вы смогли его завести.  уда полетим?"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("  родител€м на дачу"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)PARENTS, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("¬резатьс€ в  ремль"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)CREMLIN, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("¬ —Ўј"), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)USA, NULL, NULL);

        }
        if (LOWORD(wParam) == PARENTS)
        {
            ShowWindow(GetDlgItem(hWnd, USA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PARENTS), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, CREMLIN), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("                                                                                                                                                                                                                                                                                                                                                   "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 400, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("                                         ”кажите пол"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("ћужской"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)BOY, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("∆енский"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)GIRLOCHKA, NULL, NULL);


        }
        if (LOWORD(wParam) == USA)
        {
            ShowWindow(GetDlgItem(hWnd, USA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PARENTS), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, CREMLIN), SW_HIDE);
            BASS_ChannelStop(QUEST_THEME);
            CreateWindow(TEXT("STATIC"), TEXT("¬ы попытались прилететь в —Ўј. » по какой-то причине вас не остановили на границе, удивительно, хот€ нет, через 5 минут за вами прилетел самолет ‘Ѕ–. » вежливо стрельнул ракетами в ваш вертолет. ¬ы шашнахме. ћораль: <<Ќе пересекайте дети границу, а то будет шашнахме>> "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            JACKSON = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\Stranger in Moscow.mp3", 0, 0, 0);
            BASS_ChannelPlay(JACKSON, false);
        }
        if (LOWORD(wParam) == CREMLIN)
        {
            ShowWindow(GetDlgItem(hWnd, USA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PARENTS), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, CREMLIN), SW_HIDE);
            BASS_ChannelStop(QUEST_THEME);
            CreateWindow(TEXT("STATIC"), TEXT("ѕрилетев к  ремлю, вы встретили широкого ѕутина, который вам сделал такой шашнахме, что вам вашей худой кости не хватило, чтобы его повалить =). ћораль: <<≈сли вы слабее, даже не пытайтесь лезть в драку, а то получите шашнахме в глаз>> "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            PUTIN = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\WIDE.mp3", 0, 0, 0);
            BASS_ChannelPlay(PUTIN, false);
        }

        if (LOWORD(wParam) == GIRLOCHKA)
        {
            ShowWindow(GetDlgItem(hWnd, USA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PARENTS), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, CREMLIN), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, BOY), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, GIRLOCHKA), SW_HIDE);

            CreateWindow(TEXT("STATIC"), TEXT("¬ы приехали на дачу к родител€м. „то будете делать?"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("ѕомогать родител€м"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)HELP1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("ѕойти в душ"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)SHOWER, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("ѕойти к парню"), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)BOYFRIEND1, NULL, NULL);


        }
        if (LOWORD(wParam) == BOY)
        {
            ShowWindow(GetDlgItem(hWnd, USA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PARENTS), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, CREMLIN), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, BOY), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, GIRLOCHKA), SW_HIDE);

            CreateWindow(TEXT("STATIC"), TEXT("¬ы приехали на дачу к родител€м. „то будете делать?"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("ѕомогать родител€м"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)HELP1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("ѕойти в душ"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)SHOWER, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("ѕойти к девушке"), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)DEVA1, NULL, NULL);

        }
        if (LOWORD(wParam) == BOYFRIEND1)
        {
            ShowWindow(GetDlgItem(hWnd, BOYFRIEND1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, BOY), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, GIRLOCHKA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELP1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SHOWER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, DEVA1), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("ƒј ќ“ ¬ј— ∆≈ ѕј—≈“ Ќј ћ»ЋЋ»ќЌ  »Ћќћ≈“–ќ¬! ѕј–≈Ќ№ ”Ѕ≈∆јЋ! »√–ј ќ ќЌ„≈Ќј! ¬џ ЋќЎјЎ » ЎјЎЌј’ћ≈! ћораль: <<—ледите за гигиеной, не будьте вонючками!>>"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
        }
        if (LOWORD(wParam) == DEVA1)

        {
            ShowWindow(GetDlgItem(hWnd, BOY), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, GIRLOCHKA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELP1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SHOWER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, DEVA1), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("ƒј ќ“ ¬ј— ∆≈ ѕј—≈“ Ќј ћ»ЋЋ»ќЌ  »Ћќћ≈“–ќ¬! ƒ≈¬”Ў ј ”Ѕ≈∆јЋј ¬ —Ћ≈«ј’!! »√–ј ќ ќЌ„≈Ќј! ¬џ ЋќЎјЎ » ЎјЎЌј’ћ≈! ћораль: <<—ледите за гигиеной, не будьте вонючками!>>"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
        }
        if (LOWORD(wParam) == HELP1)
        {
            ShowWindow(GetDlgItem(hWnd, SHOWER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, DEVA1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, BOYFRIEND1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELP1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LOVING), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("ѕравильно вы поступаете, помогаете родител€м. ¬ы в жизни надеюсь также поступаете? ≈сли да, то молодцы. ѕоступайте так всегда! ¬ этом и мораль: <<ѕомогайте близким>>"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
        }
        if (LOWORD(wParam) == SHOWER)
        {
            ShowWindow(GetDlgItem(hWnd, SHOWER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, DEVA1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, BOYFRIEND1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELP1), SW_SHOW);
            CreateWindow(TEXT("BUTTON"), TEXT("ѕойти навстречу любви"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)LOVING, NULL, NULL);
            

        }
        if (LOWORD(wParam) == LOVING)
        {
            ShowWindow(GetDlgItem(hWnd, HELP1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LOVING), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("Ќайд€ свою любовь вы стали жить долго и счастливо. ћораль:<<Ќет в жизни ничего важнее здоровь€ и счасть€>>."), WS_VISIBLE | WS_CHILD, 100, 10, 470, 80, hWnd, (HMENU)text1, NULL, NULL);
            MessageBoxA(hWnd, "ѕопробуйте поиграть в исторический квест, и узнаете много нового дл€ себ€ =)","ѕривет из MixOS Beta 2.2", MB_ICONASTERISK);

        }
        //if (LOWORD(wParam) == LOVING1)
        //{
        //    ShowWindow(GetDlgItem(hWnd, LOVING1), SW_HIDE);
        //    ShowWindow(GetDlgItem(hWnd, LOVING2), SW_HIDE);
        //    ShowWindow(GetDlgItem(hWnd, LOVING3), SW_HIDE);
        //    CreateWindow(TEXT("STATIC"), TEXT("ћолодец! ћораль:<<— девушкой надо вести себ€ интеллигенто и вежливо."), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
        //}
        //if (LOWORD(wParam) == LOVING2)
        //{
        //    ShowWindow(GetDlgItem(hWnd, LOVING1), SW_HIDE);
        //    ShowWindow(GetDlgItem(hWnd, LOVING2), SW_HIDE);
        //    ShowWindow(GetDlgItem(hWnd, LOVING3), SW_HIDE);
        //    CreateWindow(TEXT("STATIC"), TEXT("¬ы сделали неверный выбор! ћораль:<<∆изнь не настолько плоха, чтобы убиватьс€ из-за такой фигни>>."), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
        //}       
        //if (LOWORD(wParam) == LOVING3)
        //{
        //    ShowWindow(GetDlgItem(hWnd, LOVING1), SW_HIDE);
        //    ShowWindow(GetDlgItem(hWnd, LOVING2), SW_HIDE);
        //    ShowWindow(GetDlgItem(hWnd, LOVING3), SW_HIDE);
        //    CreateWindow(TEXT("STATIC"), TEXT("¬ы сделали неверный выбор! ћораль:<<Ћюбовь купить невозможно. Ёто высокое чувство, которое невозможно описать или запрограммировать. ќна не измер€етс€ в деньгах или во вли€нии. ј сн€ть куртизанку это так, на раз. » это не любовь, а услуга...>>."), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
        //}

        if (LOWORD(wParam) == FIRST2)
        {
            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
            UpdateWindow(hWnd);
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD2), SW_HIDE);                                                                                                           
            CreateWindow(TEXT("STATIC"), TEXT("—ев в toyota вы разогнались и пробили стенку, потом удачно выехали и ехали бы еще долго, если бы ближайший гаишник не остановил вас с вопросом: <<Ё… ¬џ —ќ¬—≈ћ ЎјЎЌј’ћ≈ „“ќ Ћ»?>>. »гра окончена.ћораль: не садитесь дети в машину без прав, тем более в чужую машину. Ќе подвергайте риску себ€ и окружающих.     "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 480, hWnd, (HMENU)text1, NULL, NULL);
            BASS_ChannelStop(QUEST_THEME);
            BASS_ChannelStop(LADAV);
            BASS_Stop();
            BASS_Start();

            ROSB = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\RASB.mp3", 0, 0, 0);
            BASS_ChannelPlay(ROSB, false);


        }

        if (LOWORD(wParam) == SECOND2)
        {
            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));

            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD2), SW_HIDE);
            BASS_ChannelStop(QUEST_THEME);
            KAVINSKY = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\kav.mp3", 0, 0, 0);
            BASS_ChannelPlay(KAVINSKY, false);
            CreateWindow(TEXT("STATIC"), TEXT("—ев в BMW, вы включили трек Kavinsky-Nightcall и умчались со стилем!!!                                                                                                                                   "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
        }
        if (LOWORD(wParam) == THIRD2)
        {
            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));

            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD2), SW_HIDE);
            BASS_ChannelPause(QUEST_THEME);
            LADAV = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\trombone.mp3", 0, 0, 0);
            
            BASS_ChannelPlay(LADAV, false);
            BASS_ChannelPlay(QUEST_THEME, false);
            CreateWindow(TEXT("STATIC"), TEXT("ѕопытавшись завести машину, спуст€ 50 минут, вы таки смогли выехать за пределы места где вы застр€ли, но спуст€ 100 метров машина застр€ла в ближайшем болоте. ¬ы смогли выбратьс€, и пройд€ 5 метров нашли телефон, на котором 1% зар€дки, так что позвонить можно только 1 раз.  ому позвоним?    "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("ѕозвонить маме"), WS_VISIBLE | WS_CHILD, 220,115, 185, 35, hWnd, (HMENU)FIRST3, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("ѕозвонить –азработчику"), WS_VISIBLE | WS_CHILD, 220, 155, 185, 35, hWnd, (HMENU)SECOND3, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("ѕоиграть в Geometry Dash"), WS_VISIBLE | WS_CHILD, 220, 195, 185, 35, hWnd, (HMENU)THIRD3, NULL, NULL);
        }
        if (LOWORD(wParam) == FIRST3)
        {
            CreateWindow(TEXT("STATIC"), TEXT("ѕривет мой ребенок, как ты там? ѕочему не звонишь? ¬ деревне по тебе тво€ любовь скучает, так и сидит у окна дома каждый день. Ќадо нам помочь, мы с папой уже старенькие, а работы в деревне выше крыши.  ак ты там?                                                                                                                                         "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD3), SW_HIDE);
            CreateWindow(TEXT("BUTTON"), TEXT("ћама, € тут в каком-то переулке..."), WS_VISIBLE | WS_CHILD, 150, 155, 300, 35, hWnd, (HMENU)MOTHER, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("ћама, € щас приеду!!!"), WS_VISIBLE | WS_CHILD, 150, 200, 300, 35, hWnd, (HMENU)EDU, NULL, NULL);
        }
        if (LOWORD(wParam) == EDU)
        {
            CreateWindow(TEXT("STATIC"), TEXT("¬ы успели сказать маме эти слова, потом телефон отключилс€. ¬ы успешно пешком добежали до лестницы, подн€лись по ней и увидели                        велосипед, машину и вертолет.                                                                                  уда с€дем?"), WS_VISIBLE | WS_CHILD, 100, 10, 480, 108, hWnd, (HMENU)text1, NULL, NULL);
            ShowWindow(GetDlgItem(hWnd, MOTHER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, EDU), SW_HIDE);




                ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
                ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
                ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
                ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);

                ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
                ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
                ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
                ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
                ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);

 


                CreateWindow(TEXT("BUTTON"), TEXT("—есть в велосипед"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)VELOSIPED, NULL, NULL);
                CreateWindow(TEXT("BUTTON"), TEXT("—есть в машину"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)MASHINA, NULL, NULL);
                CreateWindow(TEXT("BUTTON"), TEXT("—есть в вертолет "), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)HELICOPTER, NULL, NULL);
            



        }
        if (LOWORD(wParam) == SECOND3)
        {
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD3), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("«вонить разработчику вредно дл€ здоровь€. ¬ы тут же умерли, потому что у вас не толста€ кость. » разработчик поразил вас великим шашнахмемским мечом."), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            BASS_ChannelStop(QUEST_THEME);
            BASS_ChannelStop(LADAV);
            KILL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\kill.mp3", 0, 0, 0);
            BASS_ChannelPlay(KILL, false);

        }
        if (LOWORD(wParam) == MOTHER)
        {
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MOTHER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, EDU), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("<<ќп€ть ты по переулкам шл€ешьс€ и бухаешь! ’от€ € тебе запретила пить! Ёто все друзь€ твои, очень плохо на теб€ вли€ют. Ќу, ничего дома поговорим! Ќебось еще и куришь? ќтец с теб€ всю шкуру снимет!>> - ¬се что успела сказать мама. ѕотом телефон отключилс€. ћораль такова: Ќе пейте и ведите здоровый образ жизни, тогда по переулкам шл€тьс€ не придетс€ =( "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 480, hWnd, (HMENU)text1, NULL, NULL);
            BASS_ChannelStop(QUEST_THEME);
            BASS_ChannelStop(LADAV);
            KILL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\kill.mp3", 0, 0, 0);
            BASS_ChannelPlay(KILL, false);
        }
        if (LOWORD(wParam) == THIRD3)
        {
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MOTHER), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("ѕоиграв каких-то 5 минут и не пройд€ даже один уровень в игре, вы разбили телефон.  онец игры =). ћораль: не тратьте свою жизнь впустую. –азвлечени€ это хорошо, но в меру. –овно также, как и работа."), WS_VISIBLE | WS_CHILD, 100, 10, 450, 480, hWnd, (HMENU)NULL, NULL, NULL);
            BASS_ChannelStop(QUEST_THEME);
            BASS_ChannelStop(LADAV);
            KILL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\kill.mp3", 0, 0, 0);
            BASS_ChannelPlay(KILL, false);
        }



        if (LOWORD(wParam) == MYCOLOR)
        {
            
            CHOOSECOLOR cc;

            ZeroMemory(&cc, sizeof(CHOOSECOLOR));
            cc.lStructSize = sizeof(CHOOSECOLOR);
            cc.hwndOwner = hWnd;
            cc.lpCustColors = (LPDWORD)acrCustClr;
            cc.rgbResult = rgbCurrent;
            cc.Flags = CC_FULLOPEN | CC_RGBINIT;

            if (ChooseColor(&cc) == TRUE) {
                bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);

                hBrush = CreateSolidBrush(cc.rgbResult);
                rgbCurrent = cc.rgbResult;


            }
            else
            {

                /*   bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
                   SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);*/
                hBrush = CreateSolidBrush(RGB(0, 76, 153));
                rgbCurrent = RGB(0, 76, 153);
                return 0;
            };


            InvalidateRect(hWnd, NULL, FALSE);

              // “ќ ј’–»Ќ≈“№ ќ’”≈“№ “ќ„Ќ≈≈. “еперь надо такое же добавить в “ерминал... » в ѕианино... » еще много куда...
        }

    case WM_HSCROLL:
    {
        if (hTrack == (HWND)lParam)
        {

            BASS_ChannelSetAttribute(QUEST_THEME, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 25, 75));
            BASS_ChannelSetAttribute(LADAV, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 25, 75));
            BASS_ChannelSetAttribute(REMIX, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 25, 75));
            BASS_ChannelSetAttribute(SVOBODA, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 25, 75));
            BASS_ChannelSetAttribute(KILL, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 25, 75));
            BASS_ChannelSetAttribute(KAVINSKY, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 25, 75));
            BASS_ChannelSetAttribute(ROSB, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 25, 75));
            BASS_ChannelSetAttribute(MODEL, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 25, 75));
            BASS_ChannelSetAttribute(PUTIN, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 25, 75)); 
            BASS_ChannelSetAttribute(JACKSON, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 25, 75));
            BASS_ChannelSetAttribute(KAVUL, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 25, 75));
        }
    } break;


    case WM_CTLCOLORSTATIC:
    {
        if (GetDlgCtrlID((HWND)lParam) == text1)
        {
            HDC hdcStatic = (HDC)wParam;
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }
        if (GetDlgCtrlID((HWND)lParam) == LENMUSIC)
        {
            HDC hdcStatic = (HDC)wParam;
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color

            SetBkColor(hdcStatic, RGB(255,255,255));


            return (LRESULT)(COLOR_WINDOW + 1);

        }

    }break;

            case WM_PAINT: {
                hdc = BeginPaint(hWnd, &ps);
                //“ј , слушай, , € щас некоторое врем€ не буду говорить, но скоро начну.Ќо € тут подумал, что смену скинов надо добавить и в остальные подпрограммы.’от€ бы в список эмул€торов
                FillRect(hdc, &ps.rcPaint, hBrush);
                /*SetBkMode(hdc, TRANSPARENT);*/

                //BitBlt(hdc, 0, 0, bm., 720, memBit, 0, 0, SRCCOPY);

                EndPaint(hWnd, &ps);
                //return 0;

            } break;

    //case WM_KEYDOWN:
    //    switch (lParam)
    //    {
    //        case VK_NUMPAD5:
    //            if (key_pressed == false)
    //            {
    //                ShowWindow(tardis, SW_SHOW);
    //                key_pressed = true;
    //            }
    //            else if (key_pressed == true)
    //            {
    //                ShowWindow(tardis, SW_HIDE);
    //                key_pressed = false;
    //            };
    //            break;
    //    }
    //    break;

    case WM_DESTROY: {
        PostQuitMessage(0);
        return 0;

        break;

    }
 

    default:
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
                   return 0; 
    }
}

int WINAPI main()
{
 
    SetProcessDPIAware();
    WNDCLASS op;
    ZeroMemory(&op, sizeof(WNDCLASS));
    op.lpfnWndProc = wnd_proc;
    op.hInstance = GetModuleHandle(NULL);
    op.lpszClassName = "test32cls";
    op.hCursor = LoadCursor(NULL, IDC_ARROW);
    progicon = (HICON)LoadImage(op.hInstance, "MusicPlayer\\BMP\\ico\\quest.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
    op.hIcon = progicon;

    //op.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    RegisterClass(&op);


    CreateWindowEx(WS_EX_LAYERED,op.lpszClassName, "Ўашнахме квест", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE, 100, 100, 640, 360, NULL, NULL, op.hInstance, NULL);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }

}
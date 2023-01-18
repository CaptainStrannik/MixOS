#include <windows.h>
#include<winuser.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <tchar.h>
#include <wchar.h>
#include "resource.h"       
#include "resource1.h"
#include "resource2.h"
#include"targetver.h"
#include "framework.h"
#include "targetver.h"
#include <conio.h>
#include <shlobj.h>
#include <ks.h>
#include <string>
#include<mciapi.h>
#include<Mmsystem.h>
#include <mmeapi.h>
#include<mmdeviceapi.h>
#include "Names.h"
#include "bass.h"
#include "wingdi.h"
#include <commdlg.h>
#include <fstream>
#include <iostream>
#include<set>
#include <algorithm>

//#include <shlwapi.h> 
//#include <filesystem>
#include <shlwapi.h> 
#include <commdlg.h>
#pragma comment (lib,"Winmm.lib")





HSTREAM NOTEDO;
HSTREAM NOTERE;
HSTREAM NOTEMI;
HSTREAM NOTEFA;
HSTREAM NOTESOL;
HSTREAM NOTELA;
HSTREAM NOTESI;

HSTREAM NOTEDODI;
HSTREAM NOTEREDI;
HSTREAM NOTEFADI;
HSTREAM NOTESOLDI;
HSTREAM NOTELADI;
HSTREAM NOTEDO2;
HSTREAM LOOPBREAK;

HSTREAM NOTEDO0;
HSTREAM NOTERE0;
HSTREAM NOTEMI0;
HSTREAM NOTEFA0;
HSTREAM NOTESOL0;
HSTREAM NOTELA0;
HSTREAM NOTESI0;


HSTREAM NOTEDO01;
HSTREAM NOTERE01;
HSTREAM NOTEFA01;
HSTREAM NOTESOL01;
HSTREAM NOTELA01;

HSTREAM YOUTUBER;

HSTREAM START;

HWND eMp3;

HWND hwall;

HANDLE bmpwall;
HANDLE bmpwall1;

char str1[MAX_PATH];
HINSTANCE hInst;
HDC hdc;
HICON progicon;
PAINTSTRUCT ps;
HBRUSH hBrush = CreateSolidBrush(RGB(0, 76, 153));
static DWORD rgbCurrent;
static COLORREF acrCustClr[16];
int skins;
TCHAR StrT[MAX_PATH];
const TCHAR progname[] = "Пианино";

#pragma comment(linker,"/manifestdependency:\"type='win32' \
                        name='Microsoft.Windows.Common-Controls' \
                        version='6.0.0.0' processorArchitecture='*'\
 publicKeyToken='6595b64144ccf1df' language='*'\"")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "bass")
using namespace std;

int b = 710;
int c = 390;
int d = 80;


//DWORD playMIDIFile(HWND hWndNotify, LPCWSTR lpszMIDIFileName)
//{
//    UINT wDeviceID;
//    DWORD dwReturn;
//    MCI_OPEN_PARMS mciOpenParms;
//    MCI_PLAY_PARMS mciPlayParms;
//    MCI_STATUS_PARMS mciStatusParms;
//    MCI_SEQ_SET_PARMS mciSeqSetParms;
//
//    // Open the device by specifying the device and filename.
//    // MCI will attempt to choose the MIDI mapper as the output port.
//    mciOpenParms.lpstrDeviceType = "sequencer";
//    mciOpenParms.lpstrElementName = (LPCSTR)lpszMIDIFileName;
//    if (dwReturn = mciSendCommand(NULL, MCI_OPEN,
//        MCI_OPEN_TYPE | MCI_OPEN_ELEMENT,
//        (DWORD)(LPVOID)&mciOpenParms))
//    {
//        // Failed to open device. Don't close it; just return error.
//        return (dwReturn);
//    }
//
//    // The device opened successfully; get the device ID.
//    wDeviceID = mciOpenParms.wDeviceID;
//
//    // Check if the output port is the MIDI mapper.
//    mciStatusParms.dwItem = MCI_SEQ_STATUS_PORT;
//    if (dwReturn = mciSendCommand(wDeviceID, MCI_STATUS,
//        MCI_STATUS_ITEM, (DWORD)(LPVOID)&mciStatusParms))
//    {
//        mciSendCommand(wDeviceID, MCI_CLOSE, 0, NULL);
//        return (dwReturn);
//    }
//
//    // Begin playback. The window procedure function for the parent 
//    // window will be notified with an MM_MCINOTIFY message when 
//    // playback is complete. At this time, the window procedure closes 
//    // the device.
//    mciPlayParms.dwCallback = (DWORD)hWndNotify;
//    if (dwReturn = mciSendCommand(wDeviceID, MCI_PLAY, MCI_NOTIFY,
//        (DWORD)(LPVOID)&mciPlayParms))
//    {
//        mciSendCommand(wDeviceID, MCI_CLOSE, 0, NULL);
//        return (dwReturn);
//    }
//
//    return (0L);
//}








static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
        
    case WM_CREATE: {



        SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);

        NOTIFYICONDATA data;
        ZeroMemory(&data, sizeof(NOTIFYICONDATA));






        data.cbSize = sizeof(data);
        data.hWnd = hWnd;
        data.uID = 1;          // Можно поставить любой идентификатор, всё равно иконка только одна
        data.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
        data.uCallbackMessage = WM_USER_SHELLICON;
        data.hIcon = progicon;
        data.uVersion = NOTIFYICON_VERSION;
        
   /*     strcpy(data.szInfoTitle, "Загрузчик видео с Youtube");*/ 
        strcpy(data.szTip, "Пианино из MixOS");

        Shell_NotifyIcon(NIM_ADD, &data);





        int a = 120;
        

        HMENU hMenubar = CreateMenu();

        HMENU hAbout = CreateMenu();
        HMENU hColor = CreateMenu();


        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "Справка");
        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hColor, "Сменить цвет");




        CreateWindow(TEXT("BUTTON"), TEXT("До"), WS_VISIBLE | WS_CHILD, 10 + 20 + d, 75, 40, 25, hWnd, (HMENU)DO0, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("До#"), WS_VISIBLE | WS_CHILD, 35 + 20 + d, 50, 40, 25, hWnd, (HMENU)DO01, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ре"), WS_VISIBLE | WS_CHILD, 60 + 20 + d, 75, 40, 25, hWnd, (HMENU)RE0, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ре#"), WS_VISIBLE | WS_CHILD, 85 + 20 + d, 50, 40, 25, hWnd, (HMENU)RE01, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ми"), WS_VISIBLE | WS_CHILD, 104 + 20 + d, 75, 40, 25, hWnd, (HMENU)MI0, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Фа"), WS_VISIBLE | WS_CHILD, 139 + 20 + d, 75, 40, 25, hWnd, (HMENU)FA0, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Фа#"), WS_VISIBLE | WS_CHILD, 160 + 20 + d, 50, 40, 25, hWnd, (HMENU)FA01, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Соль"), WS_VISIBLE | WS_CHILD, 185 + 20 + d, 75, 40, 25, hWnd, (HMENU)SOL0, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Соль#"), WS_VISIBLE | WS_CHILD, 210 + 20 + d, 50, 40, 25, hWnd, (HMENU)SOL01, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ля"), WS_VISIBLE | WS_CHILD, 235 + 20 + d, 75, 40, 25, hWnd, (HMENU)LA0, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ля#"), WS_VISIBLE | WS_CHILD, 260 + 20 + d, 50, 40, 25, hWnd, (HMENU)LA01, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Си"), WS_VISIBLE | WS_CHILD, 285 + 20 + d, 75, 40, 25, hWnd, (HMENU)SI0, NULL, NULL);

        


        CreateWindow(TEXT("BUTTON"), TEXT("До"), WS_VISIBLE | WS_CHILD, 10+20+c, 75, 40, 25, hWnd, (HMENU)DO, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("До#"), WS_VISIBLE | WS_CHILD, 35+20+c, 50, 40, 25, hWnd, (HMENU)DO1, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ре"), WS_VISIBLE | WS_CHILD, 60+20+c, 75, 40, 25, hWnd, (HMENU)RE, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ре#"), WS_VISIBLE | WS_CHILD, 85+20+c, 50, 40, 25, hWnd, (HMENU)RE1, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ми"), WS_VISIBLE | WS_CHILD, 104+20+c, 75, 40, 25, hWnd, (HMENU)MI, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Фа"), WS_VISIBLE | WS_CHILD, 139+20+c, 75, 40, 25, hWnd, (HMENU)FA, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Фа#"), WS_VISIBLE | WS_CHILD, 160+20+c, 50, 40, 25, hWnd, (HMENU)FA1, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Соль"), WS_VISIBLE | WS_CHILD, 185+20+c, 75, 40, 25, hWnd, (HMENU)SOL, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Соль#"), WS_VISIBLE | WS_CHILD, 210+20+c, 50, 40, 25, hWnd, (HMENU)SOL1, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ля"), WS_VISIBLE | WS_CHILD, 235+20+c, 75, 40, 25, hWnd, (HMENU)LA, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ля#"), WS_VISIBLE | WS_CHILD, 260+20+c, 50, 40, 25, hWnd, (HMENU)LA1, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Си"), WS_VISIBLE | WS_CHILD, 285+20+c, 75, 40, 25, hWnd, (HMENU)SI, NULL, NULL);


        CreateWindow(TEXT("BUTTON"), TEXT("До"), WS_VISIBLE | WS_CHILD, 325+20+c, 75, 40, 25, hWnd, (HMENU)DO2, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("До#"), WS_VISIBLE | WS_CHILD, 35 + 20+b, 50, 40, 25, hWnd, (HMENU)DO2D, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ре"), WS_VISIBLE | WS_CHILD, 60 + 20+b, 75, 40, 25, hWnd, (HMENU)RE2, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ре#"), WS_VISIBLE | WS_CHILD, 85 + 20+b, 50, 40, 25, hWnd, (HMENU)RE2D, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ми"), WS_VISIBLE | WS_CHILD, 104 + 20+b, 75, 40, 25, hWnd, (HMENU)MI2, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Фа"), WS_VISIBLE | WS_CHILD, 139 + 20+b, 75, 40, 25, hWnd, (HMENU)FA2, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Фа#"), WS_VISIBLE | WS_CHILD, 160 + 20+b, 50, 40, 25, hWnd, (HMENU)FA2D, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Соль"), WS_VISIBLE | WS_CHILD, 185 + 20+b, 75, 40, 25, hWnd, (HMENU)SOL2, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Соль#"), WS_VISIBLE | WS_CHILD, 210 + 20+b, 50, 40, 25, hWnd, (HMENU)SOL2D, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ля"), WS_VISIBLE | WS_CHILD, 235 + 20+b, 75, 40, 25, hWnd, (HMENU)LA2, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ля#"), WS_VISIBLE | WS_CHILD, 260 + 20+b, 50, 40, 25, hWnd, (HMENU)LA2D, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Си"), WS_VISIBLE | WS_CHILD, 285 + 20+b, 75, 40, 25, hWnd, (HMENU)SI2, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("До"), WS_VISIBLE | WS_CHILD, 325 + 20+b, 75, 40, 25, hWnd, (HMENU)DO3, NULL, NULL);




        CreateWindow(TEXT("BUTTON"), TEXT("До"), WS_VISIBLE | WS_CHILD, 10 + 20 + d, 75, 40, 25, hWnd, (HMENU)PCDO0, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("До#"), WS_VISIBLE | WS_CHILD, 35 + 20 + d, 50, 40, 25, hWnd, (HMENU)PCDO01, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ре"), WS_VISIBLE | WS_CHILD, 60 + 20 + d, 75, 40, 25, hWnd, (HMENU)PCRE0, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ре#"), WS_VISIBLE | WS_CHILD, 85 + 20 + d, 50, 40, 25, hWnd, (HMENU)PCRE01, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ми"), WS_VISIBLE | WS_CHILD, 104 + 20 + d, 75, 40, 25, hWnd, (HMENU)PCMI0, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Фа"), WS_VISIBLE | WS_CHILD, 139 + 20 + d, 75, 40, 25, hWnd, (HMENU)PCFA0, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Фа#"), WS_VISIBLE | WS_CHILD, 160 + 20 + d, 50, 40, 25, hWnd, (HMENU)PCFA01, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Соль"), WS_VISIBLE | WS_CHILD, 185 + 20 + d, 75, 40, 25, hWnd, (HMENU)PCSOL0, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Соль#"), WS_VISIBLE | WS_CHILD, 210 + 20 + d, 50, 40, 25, hWnd, (HMENU)PCSOL01, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ля"), WS_VISIBLE | WS_CHILD, 235 + 20 + d, 75, 40, 25, hWnd, (HMENU)PCLA0, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ля#"), WS_VISIBLE | WS_CHILD, 260 + 20 + d, 50, 40, 25, hWnd, (HMENU)PCLA01, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Си"), WS_VISIBLE | WS_CHILD, 285 + 20 + d, 75, 40, 25, hWnd, (HMENU)PCSI0, NULL, NULL);

        CreateWindow(TEXT("BUTTON"), TEXT("До"), WS_VISIBLE | WS_CHILD, 10 + 20+c, 75, 40, 25, hWnd, (HMENU)PCDO, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("До#"), WS_VISIBLE | WS_CHILD, 35 + 20+c, 50, 40, 25, hWnd, (HMENU)PCDO1, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ре"), WS_VISIBLE | WS_CHILD, 60 + 20+c, 75, 40, 25, hWnd, (HMENU)PCRE, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ре#"), WS_VISIBLE | WS_CHILD, 85 + 20+c, 50, 40, 25, hWnd, (HMENU)PCRE1, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ми"), WS_VISIBLE | WS_CHILD, 104 + 20+c, 75, 40, 25, hWnd, (HMENU)PCMI, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Фа"), WS_VISIBLE | WS_CHILD, 139 + 20+c, 75, 40, 25, hWnd, (HMENU)PCFA, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Фа#"), WS_VISIBLE | WS_CHILD, 160 + 20 + c, 50, 40, 25, hWnd, (HMENU)PCFA1, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Соль"), WS_VISIBLE | WS_CHILD, 185 + 20 + c, 75, 40, 25, hWnd, (HMENU)PCSOL, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Соль#"), WS_VISIBLE | WS_CHILD, 210 + 20 + c, 50, 40, 25, hWnd, (HMENU)PCSOL1, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ля"), WS_VISIBLE | WS_CHILD, 235 + 20 + c, 75, 40, 25, hWnd, (HMENU)PCLA, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ля#"), WS_VISIBLE | WS_CHILD, 260 + 20 + c, 50, 40, 25, hWnd, (HMENU)PCLA1, NULL, NULL); 
        CreateWindow(TEXT("BUTTON"), TEXT("Си"), WS_VISIBLE | WS_CHILD, 285 + 20 + c, 75, 40, 25, hWnd, (HMENU)PCSI, NULL, NULL);

        CreateWindow(TEXT("BUTTON"), TEXT("До"), WS_VISIBLE | WS_CHILD, 285 + 20 + c+40, 75, 40, 25, hWnd, (HMENU)PCDO2, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("До#"), WS_VISIBLE | WS_CHILD, 35 + 20 + b, 50, 40, 25, hWnd, (HMENU)PCDO2D, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ре"), WS_VISIBLE | WS_CHILD, 60 + 20 + b, 75, 40, 25, hWnd, (HMENU)PCRE2, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ре#"), WS_VISIBLE | WS_CHILD, 85 + 20 + b, 50, 40, 25, hWnd, (HMENU)PCRE2D, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ми"), WS_VISIBLE | WS_CHILD, 104 + 20 + b, 75, 40, 25, hWnd, (HMENU)PCMI2, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Фа"), WS_VISIBLE | WS_CHILD, 139 + 20 + b, 75, 40, 25, hWnd, (HMENU)PCFA2, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Фа#"), WS_VISIBLE | WS_CHILD, 160 + 20 + b, 50, 40, 25, hWnd, (HMENU)PCFA2D, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Соль"), WS_VISIBLE | WS_CHILD, 185 + 20 + b, 75, 40, 25, hWnd, (HMENU)PCSOL2, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Соль#"), WS_VISIBLE | WS_CHILD, 210 + 20 + b, 50, 40, 25, hWnd, (HMENU)PCSOL2D, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ля"), WS_VISIBLE | WS_CHILD, 235 + 20 + b, 75, 40, 25, hWnd, (HMENU)PCLA2, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Ля#"), WS_VISIBLE | WS_CHILD, 260 + 20 + b, 50, 40, 25, hWnd, (HMENU)PCLA2D, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Си"), WS_VISIBLE | WS_CHILD, 285 + 20 + b, 75, 40, 25, hWnd, (HMENU)PCSI2, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("До"), WS_VISIBLE | WS_CHILD, 325 + 20 + b, 75, 40, 25, hWnd, (HMENU)PCDO3, NULL, NULL);

        eMp3 = CreateWindow(TEXT("Edit"), NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE, 120+220, 240, 400, 20, hWnd, (HMENU)MIDIC, NULL, 0);
        CreateWindow("BUTTON", "...", WS_VISIBLE | WS_CHILD, 760, 240, 20, 20, hWnd, (HMENU)SEARCH, NULL, NULL);

        CreateWindow(TEXT("BUTTON"), TEXT("Играть"), WS_VISIBLE | WS_CHILD, 760+30+10, 240, 70, 20, hWnd, (HMENU)PLAY, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Выкл"), WS_VISIBLE | WS_CHILD, 760 + 30 + 10, 240, 70, 20, hWnd, (HMENU)STOPS, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Вернуться в MixOS"), WS_VISIBLE | WS_CHILD, 760 + 30 + 10+40+40, 240-100, 200, 150, hWnd, (HMENU)PIANOVID, NULL, NULL);

        //return (LRESULT)CreateSolidBrush(RGB(0, 0, 0));



        ShowWindow(GetDlgItem(hWnd, STOPS), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PLAY), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCDO0), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCDO01), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCRE0), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCRE01), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCMI0), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCLA01), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCFA0), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCFA01), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCSOL0), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCSOL01), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCLA0), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCSI0), SW_HIDE);

        ShowWindow(GetDlgItem(hWnd, PCDO), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCDO1), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCRE), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCRE1), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCMI), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCLA1), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCFA), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCFA1), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCSOL), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCSOL1), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCLA), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCSI), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCDO2), SW_HIDE);


        ShowWindow(GetDlgItem(hWnd, PCDO2D), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCRE2), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCRE2D), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCMI2), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCFA2), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCFA2D), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCSOL2), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCSOL2D), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCLA2), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCLA2D), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCSI2), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, PCDO3), SW_HIDE);












        CreateWindow(_T("BUTTON"), _T("Включить 8 bit звук"), WS_VISIBLE | WS_CHILD ,
            120+150+70,100+30+50, 100+50+50-20, 16, hWnd, (HMENU)PC_SPEAKER, NULL, NULL);
        CreateWindow(_T("BUTTON"), _T("Включить обычный звук"), WS_VISIBLE | WS_CHILD,
            120 + 150 + 70, 100 + 30 + 50, 100 + 50 + 50 - 20, 16, hWnd, (HMENU)NORMALAUDIO, NULL, NULL);
        CreateWindow(_T("BUTTON"), _T("Включить BreakLoop 130 BPM"), WS_VISIBLE | WS_CHILD,
            120 + 150-140-100, 100 + 30 + 50, 100 + 50 + 60, 20, hWnd, (HMENU)LOOP1, NULL, NULL);
        CreateWindow(_T("BUTTON"), _T("Выключить LOOP BREAK"), WS_VISIBLE | WS_CHILD,
            120 + 150 - 140 - 100, 100 + 30 + 50, 100 + 50 + 60, 20, hWnd, (HMENU)LOOPSTOP, NULL, NULL);
        CreateWindow(_T("BUTTON"), _T("Включить NinetyLoop 130 BPM"), WS_VISIBLE | WS_CHILD,
            120 + 150 - 140 - 100, 100 + 30 + 50+30, 100 + 50 + 60, 20, hWnd, (HMENU)LOOP2, NULL, NULL);
        CreateWindow(_T("BUTTON"), _T("Выключить LOOP Ninety"), WS_VISIBLE | WS_CHILD,
            120 + 150 - 140 - 100, 100 + 30 + 50+30, 100 + 50 + 60, 20, hWnd, (HMENU)LOOPSTOP2, NULL, NULL);
        CreateWindow(_T("BUTTON"), _T("Включить PendalLOOP 80 BPM"), WS_VISIBLE | WS_CHILD,
            120 + 150 - 140 - 100, 100 + 30 + 50 + 30+30, 100 + 50 + 60, 20, hWnd, (HMENU)LOOP3, NULL, NULL);
        CreateWindow(_T("BUTTON"), _T("Выключить PendalLOOP"), WS_VISIBLE | WS_CHILD,
            120 + 150 - 140 - 100, 100 + 30 + 50 + 30 + 30, 100 + 50 + 60, 20, hWnd, (HMENU)LOOPSTOP3, NULL, NULL);

        ShowWindow(GetDlgItem(hWnd, LOOPSTOP), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, LOOPSTOP2), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, LOOPSTOP3), SW_HIDE);

        ShowWindow(GetDlgItem(hWnd, NORMALAUDIO), SW_HIDE);
        BASS_Init(-1, 44100, 0, 0, NULL);

        SendMessageW(eMp3, EM_SETCUEBANNER, FALSE, (LPARAM)L"Путь до музыки, например MusicPlayer\\Your\\");


        SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));


        AppendMenu(hAbout, MF_STRING, STRANNIK, "О программе");
        AppendMenu(hColor, MF_STRING, MYCOLOR, "Мой цвет");
        AppendMenu(hColor, MF_STRING, SKINEMU, "Мой фон");
        AppendMenu(hColor, MF_SEPARATOR, NULL, NULL);
        AppendMenu(hColor, MF_STRING, polupon, "Включить полупрозрачность");
        AppendMenu(hColor, MF_STRING, polupoff, "Выключить полупрозрачность");


        SetMenu(hWnd, hMenubar);




    
        break;
    }
    case WM_COMMAND: 
    {



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
            ShellAbout(hWnd, progname, "Разработчик: Captain Strannik.", progicon);
            MessageBoxA(hWnd, "Ну, это обычное пианино, для обычных пользователей.", "О программе", MB_OK);
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

                DestroyWindow(hwall);
                hBrush = CreateSolidBrush(cc.rgbResult);
                rgbCurrent = cc.rgbResult;

            }
            InvalidateRect(hWnd, NULL, FALSE);

            // ТО АХРИНЕТЬ ОХУЕТЬ ТОЧНЕЕ. Теперь надо такое же добавить в Терминал... И в Пианино... И еще много куда...
        }




        if (LOWORD(wParam) == DO0)
        {

            
           
                BASS_StreamFree(NOTEDO0);

                NOTEDO0 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\do0.mp3", 0, 0, 0);
                BASS_ChannelPlay(NOTEDO0, false); // проигрывание файла
          

        }
        if (LOWORD(wParam) == DO01)
        {
            BASS_StreamFree(NOTEDO01);

            NOTEDO01 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\do0#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO01, false); // проигрывание файла

        }
        if (LOWORD(wParam) == RE0)
        {
            BASS_StreamFree(NOTERE0);

            NOTERE0 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\re0.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTERE0, false); // проигрывание файла

        }
        if (LOWORD(wParam) == RE01)
        {
            BASS_StreamFree(NOTERE01);

            NOTERE01 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\re0#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTERE01, false); // проигрывание файла

        }
        if (LOWORD(wParam) == MI0)
        {
            BASS_StreamFree(NOTEMI0);

            NOTEMI0 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\mi0.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEMI0, false); // проигрывание файла

        }
        if (LOWORD(wParam) == FA0)
        {
            BASS_StreamFree(NOTEFA0);

            NOTEFA0 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\fa0.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEFA0, false); // проигрывание файла

        }
        if (LOWORD(wParam) == FA01)
        {
            BASS_StreamFree(NOTEFA01);

            NOTEFA01 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\fa0#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEFA01, false); // проигрывание файла

        }
        if (LOWORD(wParam) == SOL0)
        {
            BASS_StreamFree(NOTESOL0);

            NOTESOL0 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\sol0.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTESOL0, false); // проигрывание файла

        }
        if (LOWORD(wParam) == SOL01)
        {
            BASS_StreamFree(NOTESOL01);

            NOTESOL01 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\sol0#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTESOL01, false); // проигрывание файла

        }
        if (LOWORD(wParam) == LA0)
        {
            BASS_StreamFree(NOTELA0);

            NOTELA0 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\la0.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTELA0, false); // проигрывание файла

        }
        if (LOWORD(wParam) == LA01)
        {
            BASS_StreamFree(NOTELA01);

            NOTELA01 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\la0#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTELA01, false); // проигрывание файла

        }
        if (LOWORD(wParam) == SI0)
        {
            BASS_StreamFree(NOTESI0);

            NOTESI0 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\si0.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTESI0, false); // проигрывание файла

        }
        if (LOWORD(wParam) == DO)
        {
            BASS_StreamFree(NOTEDO);

            NOTEDO = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\do.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO, false); // проигрывание файла

        }
        if (LOWORD(wParam) == DO1)
        {
            BASS_StreamFree(NOTEDODI);
  
            NOTEDODI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\do#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDODI, false); // проигрывание файла

        }
        if (LOWORD(wParam) == RE)
        {
            BASS_StreamFree(NOTERE);

            NOTERE = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\re.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTERE, false); // проигрывание файла

        }
        if (LOWORD(wParam) == RE1)
        {
            BASS_StreamFree(NOTEREDI);
 
            NOTEREDI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\re#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEREDI, false); // проигрывание файла

        }
        if (LOWORD(wParam) == MI)
        {
            BASS_StreamFree(NOTEMI);
 
            NOTEMI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\mi.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEMI, false); // проигрывание файла

        }
        if (LOWORD(wParam) == FA)
        {
            BASS_StreamFree(NOTEFA);

            NOTEFA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\fa.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEFA, false); // проигрывание файла

        }
        if (LOWORD(wParam) == FA1)
        {
            BASS_StreamFree(NOTEFADI);

            NOTEFADI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\fa#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEFADI, false); // проигрывание файла

        }
        if (LOWORD(wParam) == SOL)

        {
            BASS_StreamFree(NOTESOL);
  
            NOTESOL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\sol.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTESOL, false); // проигрывание файла

        }
        if (LOWORD(wParam) == SOL1)
        {
            BASS_StreamFree(NOTESOLDI);
      
            NOTESOLDI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\sol#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTESOLDI, false); // проигрывание файла

        }
        if (LOWORD(wParam) == LA)
        {
            BASS_StreamFree(NOTELA);
  
            NOTELA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\la.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTELA, false); // проигрывание файла

        }

        if (LOWORD(wParam) == LA1)
        {
            BASS_StreamFree(NOTELADI);
    
            NOTELADI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\la#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTELADI, false); // проигрывание файла

        }
        if (LOWORD(wParam) == SI)
        {
            BASS_StreamFree(NOTESI);
   
            NOTESI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\si.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTESI, false); // проигрывание файла

        }
        if (LOWORD(wParam) == DO2)
        {
            BASS_StreamFree(NOTEDO2);
     
            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\do2.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == DO2D)
        {
            BASS_StreamFree(NOTEDO2);
     
            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\do2#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == RE2)
        {
            BASS_StreamFree(NOTEDO2);
   
            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\re2.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == RE2D)
        {
            BASS_StreamFree(NOTEDO2);

            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\re2#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == MI2)
        {
            BASS_StreamFree(NOTEDO2);

            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\mi2.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == FA2)
        {
            BASS_StreamFree(NOTEDO2);
      
            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\fa2.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == FA2D)
        {
            BASS_StreamFree(NOTEDO2);

            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\fa2#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == SOL2)
        {
            BASS_StreamFree(NOTEDO2);
  
            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\sol2.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == SOL2D)
        {
            BASS_StreamFree(NOTEDO2);

            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\sol2#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == LA2)
        {
            BASS_StreamFree(NOTEDO2);

            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\la2.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == LA2D)
        {
            BASS_StreamFree(NOTEDO2);

            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\la2#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == SI2)
        {
            BASS_StreamFree(NOTEDO2);

            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\si2.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }

        if (LOWORD(wParam) == DO3)
        {
            BASS_StreamFree(NOTEDO2);

            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\do3.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        /*==========================================Наверху не 8 бит, а визу для 8 бит=========================================*/  








        if (LOWORD(wParam) == PCDO0)
        {
            BASS_StreamFree(NOTEDO0);

            NOTEDO0 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\do08.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO0, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCDO01)
        {
            BASS_StreamFree(NOTEDO01);

            NOTEDO01 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\do08#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO01, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCRE0)
        {
            BASS_StreamFree(NOTERE0);

            NOTERE0 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\re08.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTERE0, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCRE01)
        {
            BASS_StreamFree(NOTERE01);

            NOTERE01 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\re08#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTERE01, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCMI0)
        {
            BASS_StreamFree(NOTEMI0);

            NOTEMI0 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\mi08.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEMI0, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCFA0)
        {
            BASS_StreamFree(NOTEFA0);

            NOTEFA0 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\fa08.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEFA0, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCFA01)
        {
            BASS_StreamFree(NOTEFA01);

            NOTEFA01 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\fa08#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEFA01, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCSOL0)
        {
            BASS_StreamFree(NOTESOL0);

            NOTESOL0 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\sol08.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTESOL0, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCSOL01)
        {
            BASS_StreamFree(NOTESOL01);

            NOTESOL01 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\sol08#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTESOL01, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCLA0)
        {
            BASS_StreamFree(NOTELA0);

            NOTELA0 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\la08.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTELA0, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCLA01)
        {
            BASS_StreamFree(NOTELA01);

            NOTELA01 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\la08#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTELA01, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCSI0)
        {
            BASS_StreamFree(NOTESI0);

            NOTESI0 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\si08.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTESI0, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCDO)
        {
            BASS_StreamFree(NOTEDO);

            NOTEDO = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\do18.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCDO1)
        {
            BASS_StreamFree(NOTEDODI);

            NOTEDODI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\do18#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDODI, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCRE)
        {
            BASS_StreamFree(NOTERE);

            NOTERE = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\re18.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTERE, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCRE1)
        {
            BASS_StreamFree(NOTEREDI);

            NOTEREDI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\re18#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEREDI, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCMI)
        {
            BASS_StreamFree(NOTEMI);

            NOTEMI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\mi18.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEMI, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCFA)
        {
            BASS_StreamFree(NOTEFA);

            NOTEFA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\fa18.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEFA, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCFA1)
        {
            BASS_StreamFree(NOTEFADI);

            NOTEFADI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\fa18#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEFADI, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCSOL)

        {
            BASS_StreamFree(NOTESOL);

            NOTESOL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\sol18.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTESOL, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCSOL1)
        {
            BASS_StreamFree(NOTESOLDI);

            NOTESOLDI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\sol18#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTESOLDI, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCLA)
        {
            BASS_StreamFree(NOTELA);

            NOTELA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\la18.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTELA, false); // проигрывание файла

        }

        if (LOWORD(wParam) == PCLA1)
        {
            BASS_StreamFree(NOTELADI);

            NOTELADI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\la18#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTELADI, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCSI)
        {
            BASS_StreamFree(NOTESI);

            NOTESI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\si18.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTESI, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCDO2)
        {
            BASS_StreamFree(NOTEDO2);

            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\do28.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCDO2D)
        {
            BASS_StreamFree(NOTEDO2);

            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\do28#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCRE2)
        {
            BASS_StreamFree(NOTEDO2);

            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\re28.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCRE2D)
        {
            BASS_StreamFree(NOTEDO2);

            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\re28#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCMI2)
        {
            BASS_StreamFree(NOTEDO2);

            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\mi28.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCFA2)
        {
            BASS_StreamFree(NOTEDO2);

            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\fa28.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCFA2D)
        {
            BASS_StreamFree(NOTEDO2);

            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\fa28#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCSOL2)
        {
            BASS_StreamFree(NOTEDO2);

            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\sol28.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCSOL2D)
        {
            BASS_StreamFree(NOTEDO2);

            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\sol28#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCLA2)
        {
            BASS_StreamFree(NOTEDO2);

            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\la28.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCLA2D)
        {
            BASS_StreamFree(NOTEDO2);

            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\la28#.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PCSI2)
        {
            BASS_StreamFree(NOTEDO2);

            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\si28.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }

        if (LOWORD(wParam) == PCDO3)
        {
            BASS_StreamFree(NOTEDO2);

            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\do38.mp3", 0, 0, 0);
            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла

        }





















        if (LOWORD(wParam) == LOOP1)
        {
            BASS_StreamFree(LOOPBREAK);
            ShowWindow(GetDlgItem(hWnd, LOOP1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LOOPSTOP), SW_SHOW);

                LOOPBREAK = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\BreakLoop.mp3", 0, 0, 0);
                BASS_ChannelPlay(LOOPBREAK, false); // проигрывание файла
                
     
        }
        if (LOWORD(wParam) == LOOP2)
        {
            BASS_StreamFree(LOOPBREAK);
            BASS_Stop();
            BASS_Start();
            ShowWindow(GetDlgItem(hWnd, LOOP2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LOOPSTOP2), SW_SHOW);

            LOOPBREAK = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\NinetyLOOP.mp3", 0, 0, 0);
            BASS_ChannelPlay(LOOPBREAK, false); // проигрывание файла


        }
        if (LOWORD(wParam) == LOOP3)
        {
            BASS_StreamFree(LOOPBREAK);
            BASS_Stop();
            BASS_Start();
            ShowWindow(GetDlgItem(hWnd, LOOP3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LOOPSTOP3), SW_SHOW);

            LOOPBREAK = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\PendalLOOP.mp3", 0, 0, 0);
            BASS_ChannelPlay(LOOPBREAK, false); // проигрывание файла


        }
        if (LOWORD(wParam) == LOOPSTOP2)
        {
            BASS_StreamFree(LOOPBREAK);
            BASS_Stop();
            BASS_Start();
            ShowWindow(GetDlgItem(hWnd, LOOPSTOP2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LOOP2), SW_SHOW);




        }
        if (LOWORD(wParam) == LOOPSTOP)
        {
            BASS_StreamFree(LOOPBREAK);
            BASS_Stop();
            BASS_Start();
            ShowWindow(GetDlgItem(hWnd, LOOPSTOP), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LOOP1), SW_SHOW);

        }
        if (LOWORD(wParam) == LOOPSTOP3)
        {
            BASS_StreamFree(LOOPBREAK);
            BASS_Stop();
            BASS_Start();
            ShowWindow(GetDlgItem(hWnd, LOOPSTOP3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LOOP3), SW_SHOW);




        }
        if (LOWORD(wParam) == PC_SPEAKER)
        {








            ShowWindow(GetDlgItem(hWnd, DO0), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, DO01), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, RE0), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, RE01), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MI0), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LA0), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FA0), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FA01), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SOL0), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SOL01), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LA0), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LA01), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SI0), SW_HIDE);


            ShowWindow(GetDlgItem(hWnd, DO), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, DO1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, RE), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, RE1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MI), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LA1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FA1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SOL), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SOL1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SI), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, DO2), SW_HIDE);


            ShowWindow(GetDlgItem(hWnd, DO2D), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, RE2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, RE2D), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MI2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FA2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FA2D), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SOL2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SOL2D), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LA2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LA2D), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SI2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, DO3), SW_HIDE);



  

            ShowWindow(GetDlgItem(hWnd, PCDO0), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCDO01), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCRE0), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCRE01), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCMI0), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCLA01), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCFA0), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCFA01), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCSOL0), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCSOL01), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCLA0), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCSI0), SW_SHOW);

            ShowWindow(GetDlgItem(hWnd, PCDO), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCDO1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCRE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCRE1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCMI), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCLA1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCFA), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCFA1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCSOL), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCSOL1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCLA), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCSI), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCDO2), SW_SHOW);


            ShowWindow(GetDlgItem(hWnd, PCDO2D), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCRE2), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCRE2D), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCMI2), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCFA2), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCFA2D), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCSOL2), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCSOL2D), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCLA2), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCLA2D), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCSI2), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PCDO3), SW_SHOW);


            ShowWindow(GetDlgItem(hWnd, PC_SPEAKER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, NORMALAUDIO), SW_SHOW);



            

                  
                  
        }

        if (LOWORD(wParam) == SEARCH)
        {
            /*system("@echo off");
            system("explorer MusicPlayer");    */
            OPENFILENAME ofn;

            ZeroMemory(&ofn, sizeof(OPENFILENAME));
            ofn.lStructSize = sizeof(OPENFILENAME);
            ofn.hwndOwner = hWnd;
            ofn.lpstrFile = str1;
            ofn.nMaxFile = sizeof(str1);
            ofn.lpstrFilter = NULL;
            ofn.nFilterIndex = 1;
            ofn.lpstrFileTitle = NULL;
            ofn.nMaxFileTitle = 0;
            //ofn.lpstrInitialDir = ".";
            ofn.lpstrInitialDir = "MusicPlayer\\Your";
            ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_DONTADDTORECENT | OFN_NOCHANGEDIR;   //Бага больше нет!  А я пока отойду.

            if (GetOpenFileName(&ofn) == TRUE)
            {


                SetWindowText(eMp3, str1);
            }
            ShowWindow(GetDlgItem(hWnd, PLAY), SW_SHOW);


        }
        if (LOWORD(wParam) == PLAY)
        {


            char midi[MAX_PATH];

            GetWindowText(eMp3, midi, MAX_PATH);
            ShowWindow(GetDlgItem(hWnd, PLAY), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STOPS), SW_SHOW);
            YOUTUBER = BASS_StreamCreateFile(FALSE, midi, 0, 0, 0);
            BASS_ChannelPlay(YOUTUBER, false);
            /*playMIDIFile(hWnd, (LPCWSTR)midi);*/
            //mciSendString(midi, NULL, 0, NULL);
        }
        if (LOWORD(wParam) == STOPS)
        {
            BASS_StreamFree(YOUTUBER);
            BASS_Stop();
            BASS_Start();
           
            ShowWindow(GetDlgItem(hWnd, STOPS), SW_HIDE);


            /*playMIDIFile(hWnd, (LPCWSTR)midi);*/
            //mciSendString(midi, NULL, 0, NULL);
        }




        if (LOWORD(wParam) == SKINEMU)
        {


            ShowWindow(GetDlgItem(hWnd, SKINSSTRO), SW_HIDE);
            OPENFILENAME ofnn;

            ZeroMemory(&ofnn, sizeof(OPENFILENAME));
            ofnn.lStructSize = sizeof(OPENFILENAME);
            ofnn.hwndOwner = hWnd;
            ofnn.lpstrFile = str1;
            ofnn.nMaxFile = sizeof(str1);

            ofnn.nFilterIndex = 1;
            ofnn.lpstrFileTitle = NULL;
            ofnn.nMaxFileTitle = 0;
            //ofn.lpstrInitialDir = ".";
            ofnn.lpstrInitialDir = "MusicPlayer\\BMP\\MIXPIANO";
            ofnn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_DONTADDTORECENT | OFN_NOCHANGEDIR;   //Бага больше нет!  А я пока отойду.

            if (GetOpenFileName(&ofnn) == TRUE)
            {
                SetWindowText(eMp3, str1);

                DestroyWindow(hwall);


                skins = GetWindowText(eMp3, StrT, MAX_PATH);
                bmpwall = LoadImage(NULL, StrT, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
                bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);

                if (bmpwall != NULL);
                {

                    hwall = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);
                    SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);
                    SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall);

                }
                /*CreateWindow(TEXT("BUTTON"), TEXT("Установить"), WS_VISIBLE | WS_CHILD, 460, 500, 300, 70, hWnd, (HMENU)INSTBKG, NULL, NULL);*/
            }



        }
 
        if (LOWORD(wParam) == NORMALAUDIO)
        {
            ShowWindow(GetDlgItem(hWnd, NORMALAUDIO), SW_HIDE);


            ShowWindow(GetDlgItem(hWnd, PCDO0), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCDO01), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCRE0), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCRE01), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCMI0), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCLA01), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCFA0), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCFA01), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCSOL0), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCSOL01), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCLA0), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCSI0), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, PCDO), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCDO1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCRE), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCRE1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCMI), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCLA1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCFA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCFA1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCSOL), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCSOL1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCLA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCSI), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCDO2), SW_HIDE);


            ShowWindow(GetDlgItem(hWnd, PCDO2D), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCRE2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCRE2D), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCMI2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCFA2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCFA2D), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCSOL2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCSOL2D), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCLA2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCLA2D), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCSI2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PCDO3), SW_HIDE);




            ShowWindow(GetDlgItem(hWnd, DO0), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, DO01), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, RE0), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, RE01), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MI0), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, LA01), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, FA0), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, FA01), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SOL0), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SOL01), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, LA0), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SI0), SW_SHOW);

            ShowWindow(GetDlgItem(hWnd, DO), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, DO1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, RE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, RE1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MI), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, LA1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, FA), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, FA1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SOL), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SOL1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, LA), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SI), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, DO2), SW_SHOW);


            ShowWindow(GetDlgItem(hWnd, DO2D), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, RE2), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, RE2D), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MI2), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, FA2), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, FA2D), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SOL2), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SOL2D), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, LA2), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, LA2D), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SI2), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, DO3), SW_SHOW);


            ShowWindow(GetDlgItem(hWnd, PC_SPEAKER), SW_SHOW);




        }





        if (LOWORD(wParam) == PIANOVID)
        {








            //ShowWindow(GetDlgItem(hWnd, PCDO0), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCDO01), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCRE0), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCRE01), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCMI0), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCLA01), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCFA0), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCFA01), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCSOL0), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCSOL01), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCLA0), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCSI0), SW_HIDE);

            //ShowWindow(GetDlgItem(hWnd, PCDO), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCDO1), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCRE), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCRE1), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCMI), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCLA1), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCFA), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCFA1), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCSOL), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCSOL1), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCLA), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCSI), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCDO2), SW_HIDE);


            //ShowWindow(GetDlgItem(hWnd, PCDO2D), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCRE2), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCRE2D), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCMI2), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCFA2), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCFA2D), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCSOL2), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCSOL2D), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCLA2), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCLA2D), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCSI2), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, PCDO3), SW_HIDE);




            //ShowWindow(GetDlgItem(hWnd, DO0), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, DO01), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, RE0), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, RE01), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, MI0), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, LA01), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, FA0), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, FA01), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, SOL0), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, SOL01), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, LA0), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, SI0), SW_HIDE);

            //ShowWindow(GetDlgItem(hWnd, DO), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, DO1), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, RE), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, RE1), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, MI), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, LA1), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, FA), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, FA1), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, SOL), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, SOL1), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, LA), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, SI), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, DO2), SW_HIDE);


            //ShowWindow(GetDlgItem(hWnd, DO2D), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, RE2), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, RE2D), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, MI2), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, FA2), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, FA2D), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, SOL2), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, SOL2D), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, LA2), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, LA2D), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, SI2), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, DO3), SW_HIDE);



            //CreateWindow(TEXT("BUTTON"), TEXT("До"), WS_VISIBLE | WS_CHILD, 10 + 20 + d, 75, 40, 25, hWnd, (HMENU)DO0W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("До#"), WS_VISIBLE | WS_CHILD| BS_OWNERDRAW, 35 + 20 + d, 50, 40, 25, hWnd, (HMENU)DO01W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Ре"), WS_VISIBLE | WS_CHILD, 60 + 20 + d, 75, 40, 25, hWnd, (HMENU)RE0W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Ре#"), WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 85 + 20 + d, 50, 40, 25, hWnd, (HMENU)RE01W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Ми"), WS_VISIBLE | WS_CHILD, 104 + 20 + d, 75, 40, 25, hWnd, (HMENU)MI0W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Фа"), WS_VISIBLE | WS_CHILD, 139 + 20 + d, 75, 40, 25, hWnd, (HMENU)FA0W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Фа#"), WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 160 + 20 + d, 50, 40, 25, hWnd, (HMENU)FA01W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Соль"), WS_VISIBLE | WS_CHILD, 185 + 20 + d, 75, 40, 25, hWnd, (HMENU)SOL0W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Соль#"), WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 210 + 20 + d, 50, 40, 25, hWnd, (HMENU)SOL01W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Ля"), WS_VISIBLE | WS_CHILD, 235 + 20 + d, 75, 40, 25, hWnd, (HMENU)LA0W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Ля#"), WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 260 + 20 + d, 50, 40, 25, hWnd, (HMENU)LA01W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Си"), WS_VISIBLE | WS_CHILD, 285 + 20 + d, 75, 40, 25, hWnd, (HMENU)SI0W, NULL, NULL);




            //CreateWindow(TEXT("BUTTON"), TEXT("До"), WS_VISIBLE | WS_CHILD, 10 + 20 + c, 75, 40, 25, hWnd, (HMENU)DOW, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("До#"), WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 35 + 20 + c, 50, 40, 25, hWnd, (HMENU)DO1W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Ре"), WS_VISIBLE | WS_CHILD, 60 + 20 + c, 75, 40, 25, hWnd, (HMENU)REW, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Ре#"), WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 85 + 20 + c, 50, 40, 25, hWnd, (HMENU)RE1W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Ми"), WS_VISIBLE | WS_CHILD, 104 + 20 + c, 75, 40, 25, hWnd, (HMENU)MIW, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Фа"), WS_VISIBLE | WS_CHILD, 139 + 20 + c, 75, 40, 25, hWnd, (HMENU)FAW, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Фа#"), WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 160 + 20 + c, 50, 40, 25, hWnd, (HMENU)FA1W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Соль"), WS_VISIBLE | WS_CHILD, 185 + 20 + c, 75, 40, 25, hWnd, (HMENU)SOLW, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Соль#"), WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 210 + 20 + c, 50, 40, 25, hWnd, (HMENU)SOL1W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Ля"), WS_VISIBLE | WS_CHILD, 235 + 20 + c, 75, 40, 25, hWnd, (HMENU)LAW, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Ля#"), WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 260 + 20 + c, 50, 40, 25, hWnd, (HMENU)LA1W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Си"), WS_VISIBLE | WS_CHILD, 285 + 20 + c, 75, 40, 25, hWnd, (HMENU)SIW, NULL, NULL);


            //CreateWindow(TEXT("BUTTON"), TEXT("До"), WS_VISIBLE | WS_CHILD, 325 + 20 + c, 75, 40, 25, hWnd, (HMENU)DO2W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("До#"), WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 35 + 20 + b, 50, 40, 25, hWnd, (HMENU)DO2DW, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Ре"), WS_VISIBLE | WS_CHILD, 60 + 20 + b, 75, 40, 25, hWnd, (HMENU)RE2W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Ре#"), WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 85 + 20 + b, 50, 40, 25, hWnd, (HMENU)RE2DW, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Ми"), WS_VISIBLE | WS_CHILD, 104 + 20 + b, 75, 40, 25, hWnd, (HMENU)MI2W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Фа"), WS_VISIBLE | WS_CHILD, 139 + 20 + b, 75, 40, 25, hWnd, (HMENU)FA2W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Фа#"), WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 160 + 20 + b, 50, 40, 25, hWnd, (HMENU)FA2DW, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Соль"), WS_VISIBLE | WS_CHILD, 185 + 20 + b, 75, 40, 25, hWnd, (HMENU)SOL2W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Соль#"), WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 210 + 20 + b, 50, 40, 25, hWnd, (HMENU)SOL2DW, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Ля"), WS_VISIBLE | WS_CHILD, 235 + 20 + b, 75, 40, 25, hWnd, (HMENU)LA2W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Ля#"), WS_VISIBLE | WS_CHILD | BS_OWNERDRAW, 260 + 20 + b, 50, 40, 25, hWnd, (HMENU)LA2DW, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Си"), WS_VISIBLE | WS_CHILD, 285 + 20 + b, 75, 40, 25, hWnd, (HMENU)SI2W, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("До"), WS_VISIBLE | WS_CHILD, 325 + 20 + b, 75, 40, 25, hWnd, (HMENU)DO3, NULL, NULL);






            system("start MixOS.exe");


        }




        case WM_CTLCOLORBTN:
        {
            SetTextColor((HDC)wParam, RGB(0, 0, 255));
            SetBkColor((HDC)wParam, (rgbCurrent));
            return (LRESULT)CreateSolidBrush(rgbCurrent);
        }




    case STRANNIK:
    {
        switch (wParam)
        {


        case PCSI0:

            

            break;

        case PCLA01:
            Beep(233, 1000 / 8);
            break;

        case PCLA0:
            Beep(220, 1000 / 8);
            break;

        case PCSOL01:
            Beep(207, 1000 / 8);
            break;

        case PCSOL0:
            Beep(196, 1000/8);
            break;

        case PCFA01:
            Beep(185, 1000 / 8);
            break;

        case PCFA0:
            Beep(174, 1000 / 8);
            break;

        case PCMI0:
            Beep(165, 1000 / 8);
            break;

        case PCRE01:
            Beep(155, 1000 / 8);
            break;

        case PCRE0:
            Beep(148, 1000 / 8);
            break;


        case PCDO01:
            Beep(138,1000 / 8);
            break;
            
        case PCDO0:
            Beep(131, 1000 / 8);
            break;

        case PCDO:
            Beep(261, 1000 / 8);
            break;
        case PCDO1:
            Beep(277, 1000 / 8);
            break;
        case PCRE:
            Beep(293, 1000 / 8);
            break;
        case PCRE1:
            Beep(311, 1000 / 8);
            break;
        case PCMI:
            Beep(329, 1000 / 8);
            break;
        case PCFA:
            Beep(349, 1000 / 8);
            break;
        case PCFA1:
            Beep(370, 1000 / 8);
            break;
        case PCSOL:
            Beep(392, 1000 / 8);
            break;
        case PCSOL1:
            Beep(415, 1000 / 8);
            break;
        case PCLA:
            Beep(440, 1000 / 8);
            break;
        case PCLA1:
            Beep(466, 1000 / 8);
            break;
        case PCSI:
            Beep(494, 1000 / 8);
            break;
        case PCDO2:
            Beep(523, 1000 / 8);
            break;
        case PCDO2D:
            Beep(554, 1000 / 8);
            break;
        case PCRE2:
            Beep(587, 1000 / 8);
            break;
        case PCRE2D:
            Beep(622, 1000 / 8);
            break;
        case PCMI2:
            Beep(659, 1000 / 8);
            break;
        case PCFA2:
            Beep(698, 1000 / 8);
            break;
        case PCFA2D:
            Beep(739, 1000 / 8);
            break;
        case PCSOL2:
            Beep(784, 1000 / 8);
            break;
        case PCSOL2D:
            Beep(830, 1000 / 8);
            break;
        case PCLA2:
            Beep(880, 1000 / 8);
            break;
        case PCLA2D:
            Beep(932, 1000 / 8);
            break;
        case PCSI2:
            Beep(988, 1000 / 8);
            break;
        case PCDO3:
            Beep(1046, 1000 / 8);
            break;
        }
    }
    break;




    break;



        case WM_DROPFILES: {  

        DragQueryFile((HDROP)wParam, 0, str1, MAX_PATH);
        SetWindowText(eMp3, str1);
    }
                     break;
        










                   case WM_CHAR:
                   {
                       switch (wParam)   //Теперь работать стало, когда я сделал Wparam
                       {
                       case 'я':

                       SendMessage(hWnd, WM_COMMAND, PCDO0, 0);
                       break;
                       
                       case 'z':

                           
                               SendMessage(hWnd, WM_COMMAND, DO0, 0);
                               break;


                           //Ладно, обойдемся без русского языка, ок? Ок
                       case 's':
                           SendMessage(hWnd, WM_COMMAND, DO01, 0);
                           break;
                       case 'x':
                           SendMessage(hWnd, WM_COMMAND, RE0, 0);
                           break;
                       case 'd':
                           SendMessage(hWnd, WM_COMMAND, RE01, 0);
                           break;
                       case 'c':
                           SendMessage(hWnd, WM_COMMAND, MI0, 0);
                           break;
                       case 'v':
                           SendMessage(hWnd, WM_COMMAND, FA0, 0);
                           break;
                       case 'g':
                           SendMessage(hWnd, WM_COMMAND, FA01, 0);
                           break;
                       case 'b':
                           SendMessage(hWnd, WM_COMMAND, SOL0, 0);
                           break;
                       case 'h':
                           SendMessage(hWnd, WM_COMMAND, SOL01, 0);
                           break;
                       case 'n':
                           SendMessage(hWnd, WM_COMMAND, LA0, 0);
                           break;
                       case 'j':
                           SendMessage(hWnd, WM_COMMAND, LA01, 0);
                           break;
                       case 'm':
                           SendMessage(hWnd, WM_COMMAND, SI0, 0);
                           break;
                       case ',':
                           SendMessage(hWnd, WM_COMMAND, DO, 0);
                           break;
                       case '.':
                           SendMessage(hWnd, WM_COMMAND, RE, 0);
                           break;
                       case '/':
                           SendMessage(hWnd, WM_COMMAND, MI, 0);
                           break;
                       case ';':
                           SendMessage(hWnd, WM_COMMAND, RE1, 0);
                           break;
                       case 'l':
                           SendMessage(hWnd, WM_COMMAND, DO1, 0);
                           break;
                       case 'q':

                           SendMessage(hWnd, WM_COMMAND, DO, 0);
                           break;
                       case 'w':

                           SendMessage(hWnd, WM_COMMAND, RE, 0);
                           break;
                       case 'e':
                           SendMessage(hWnd, WM_COMMAND, MI, 0);
                           break;
                       case 'r':
                           SendMessage(hWnd, WM_COMMAND, FA, 0);
                           break;
                       case 't':
                           SendMessage(hWnd, WM_COMMAND, SOL, 0);
                           break;
                       case 'y':
                           SendMessage(hWnd, WM_COMMAND, LA, 0);
                           break;
                       case 'u':
                           SendMessage(hWnd, WM_COMMAND, SI, 0);
                           break;
                       case 'i':
                           SendMessage(hWnd, WM_COMMAND, DO2, 0);
                           break;
                       case 'o':
                           SendMessage(hWnd, WM_COMMAND, RE2, 0);
                           break;
                       case 'p':
                           SendMessage(hWnd, WM_COMMAND, MI2, 0);
                           break;
                       case '[':
                           SendMessage(hWnd, WM_COMMAND, FA2, 0);
                           break;
                       case ']':
                           SendMessage(hWnd, WM_COMMAND, SOL2, 0);
                           break;
                       case '2':
                           SendMessage(hWnd, WM_COMMAND, DO1, 0);
                           break;
                       case '3':
                           SendMessage(hWnd, WM_COMMAND, RE1, 0);
                           break;
                       case '5':
                           SendMessage(hWnd, WM_COMMAND, FA1, 0);
                           break;
                       case '6':
                           SendMessage(hWnd, WM_COMMAND, SOL1, 0);
                           break;
                       case '7':
                           SendMessage(hWnd, WM_COMMAND, LA1, 0);
                           break;
                       case '9':
                           SendMessage(hWnd, WM_COMMAND, DO2D, 0);
                           break;
                       case '0':
                           SendMessage(hWnd, WM_COMMAND, RE2D, 0);
                           break;
                       case '=':
                           SendMessage(hWnd, WM_COMMAND, FA2D, 0);
                           break;
                       case 'a':
                           SendMessage(hWnd, WM_COMMAND, SOL2D, 0);
                           break;
                       }
                   }

                   break;








        














        break;
    }


        

       
       case WM_KEYDOWN:
       {
           switch (wParam)
           {


           case VK_ESCAPE:
               DestroyWindow(hWnd);
               break;
           case VK_NUMPAD1:
               SendMessage(hWnd, WM_COMMAND, LOOP1, 0);
               break;
           case VK_NUMPAD2:
               SendMessage(hWnd, WM_COMMAND, LOOP2, 0);
               break;
           case VK_NUMPAD3:
               SendMessage(hWnd, WM_COMMAND, LOOP3, 0);
               break;
           case VK_NUMPAD5:
           {
               BASS_StreamFree(LOOPBREAK);
               BASS_Stop();
               BASS_Start();
               break;
           }
           }
       }

    case WM_PAINT: {
            hdc = BeginPaint(hWnd, &ps);
            FillRect(hdc, &ps.rcPaint, hBrush);
            EndPaint(hWnd, &ps);
            return 0;
        }

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
 

int WINAPI main() 
{
    WNDCLASS op;
    ZeroMemory(&op, sizeof(WNDCLASS));
    op.lpfnWndProc = wnd_proc;
    op.hInstance = GetModuleHandle(NULL);
    op.lpszClassName = "test32cls";
    op.hCursor = LoadCursor(NULL, IDC_ARROW);
    progicon = (HICON)LoadImage(op.hInstance, "MusicPlayer\\BMP\\ico\\piano.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);;
    op.hIcon = progicon;
    
    //op.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    RegisterClass(&op);
    SetProcessDPIAware();

    /*CreateWindowEx(WS_EX_ACCEPTFILES,op.lpszClassName, "Пианино", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX| WS_VISIBLE, 100, 100, 1200, 360, NULL, NULL, op.hInstance, NULL);*/
    CreateWindowEx(WS_EX_LAYERED|WS_EX_ACCEPTFILES, op.lpszClassName, progname, WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE, (GetSystemMetrics(SM_CXSCREEN) - 1280) / 2,
    (GetSystemMetrics(SM_CYSCREEN) - 720) / 2, 1200, 360, NULL, NULL, op.hInstance, NULL);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }

}
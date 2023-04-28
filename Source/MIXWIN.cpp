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
#include <urlmon.h>
#include <afx.h>
#pragma comment (lib, "urlmon.lib")

#define STRANNI 90     

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "bass")
#pragma comment(linker,"/manifestdependency:\"type='win32' \
                        name='Microsoft.Windows.Common-Controls' \
                        version='6.0.0.0' processorArchitecture='*'\
 publicKeyToken='6595b64144ccf1df' language='*'\"")

int len;
TCHAR StrB[1200];
WIN32_FIND_DATA FindFileData;
HANDLE hFind;
int a = -8;
int b = 16;
using namespace std;
char str1[1024];
HSTREAM QUEST_THEME;
HWND eMp3;
HICON progicon;
int skins;
TCHAR StrT[MAX_PATH];
HANDLE bmpwall;
HANDLE bmpwall1;
HWND hwall;
static COLORREF acrCustClr[16];
HBRUSH hBrush = CreateSolidBrush(RGB(0, 128, 0));
static DWORD rgbCurrent = RGB(0, 128, 0);
HWND hTrack;
HDC hdc;
PAINTSTRUCT ps;
const TCHAR progname[] = _T("Сборник ОС Windows");
HWND tardis;
//bool key_pressed = false;
HINSTANCE hInst;
HSTREAM UASSAULT;
HWND LOVE;
HWND LOVE1;
HWND LOVE2;
HWND LOVE3;
HWND LOVE4;




//ifstream w1;
//ifstream w2;
//ifstream w3;
//ifstream w311;
//ifstream w95;
//ifstream w98;
//ifstream wME;
//ifstream w35;
//ifstream w4;
//ifstream w5;
//ifstream w2000;
//ifstream wXP;
//ifstream wVista;
//ifstream w7;
//ifstream w8;
//ifstream w10;
//ifstream w11;








static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {

    case WM_CREATE: {




        NOTIFYICONDATA data;
        ZeroMemory(&data, sizeof(NOTIFYICONDATA));


        data.cbSize = sizeof(data);
        data.hWnd = hWnd;
        data.uID = 1;          // Можно поставить любой идентификатор, всё равно иконка только одна
        data.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
        data.uCallbackMessage = WM_USER_SHELLICON;
        data.hIcon = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\WINXP.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        data.uVersion = NOTIFYICON_VERSION;

        /*     strcpy(data.szInfoTitle, "Загрузчик видео с Youtube");*/
        strcpy(data.szTip, "Сборник ОС Windows");


        Shell_NotifyIcon(NIM_ADD, &data);
        


        HMENU hMenubar = CreateMenu();
        HMENU hAbout = CreateMenu();
        HMENU hOptions = CreateMenu();
        HMENU hLogon = CreateMenu();
        HMENU hLogoff = CreateMenu();

        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "Справка");
        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hOptions, "Настройки");
        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hLogon, "Звук Запуска");
        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hLogoff, "Звук Выключения");

        SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
        AppendMenu(hAbout, MF_STRING, STRANNIK, "О программе");


        AppendMenu(hOptions, MF_STRING, MYCOLOR, "Сменить цвет");
        AppendMenu(hOptions, MF_STRING, MYMUSIC, "Сменить музыку");
        AppendMenu(hOptions, MF_STRING, VOLUMASTA1, "Сменить громкость");
        AppendMenu(hOptions, MF_STRING, polupon, "Включить полупрозрачность");
        AppendMenu(hOptions, MF_STRING, polupoff, "Выключить полупрозрачность");


        AppendMenu(hLogon, MF_STRING, LOGON3, "Звук запуска Windows 3.1");
        AppendMenu(hLogon, MF_STRING, LOGONNT3, "Звук запуска Windows NT 3.1");
        AppendMenu(hLogon, MF_STRING, LOGON95, "Звук запуска Windows 95");
        AppendMenu(hLogon, MF_STRING, LOGONNT4, "Звук запуска Windows NT 4");
        AppendMenu(hLogon, MF_STRING, LOGON98, "Звук запуска Windows 98");
        AppendMenu(hLogon, MF_STRING, LOGONNT5, "Звук запуска Windows NT 5");
        AppendMenu(hLogon, MF_STRING, LOGON2000, "Звук запуска Windows 2000");
        AppendMenu(hLogon, MF_STRING, LOGONME, "Звук запуска Windows ME");
        AppendMenu(hLogon, MF_STRING, LOGONXP, "Звук запуска Windows XP");
        AppendMenu(hLogon, MF_STRING, LOGONVISTA, "Звук запуска Windows Vista/7/8");
        AppendMenu(hLogon, MF_STRING, LOGON10, "Звук запуска Windows 10");
        AppendMenu(hLogon, MF_STRING, LOGON11, "Звук запуска Windows 11");




        AppendMenu(hLogoff, MF_STRING, LOGOFF3, "Звук завершения работы Windows 3.1");
        AppendMenu(hLogoff, MF_STRING, LOGOFFNT3, "Звук завершения работы Windows NT 3.1");
        AppendMenu(hLogoff, MF_STRING, LOGOFF95, "Звук завершения работы Windows 95");
        AppendMenu(hLogoff, MF_STRING, LOGOFFNT4, "Звук завершения работы Windows NT 4");
        AppendMenu(hLogoff, MF_STRING, LOGOFF98, "Звук завершения работы Windows 98");
        AppendMenu(hLogoff, MF_STRING, LOGOFFNT5, "Звук завершения работы Windows NT 5");
        AppendMenu(hLogoff, MF_STRING, LOGOFF2000, "Звук завершения работы Windows 2000");
        AppendMenu(hLogoff, MF_STRING, LOGOFFME, "Звук завершения работы Windows ME");
        AppendMenu(hLogoff, MF_STRING, LOGOFFXP, "Звук завершения работы Windows XP");
        AppendMenu(hLogoff, MF_STRING, LOGOFFVISTA, "Звук завершения работы Windows Vista/7/8");
        AppendMenu(hLogoff, MF_STRING, LOGOFF10, "Звук завершения работы Windows 10");
        AppendMenu(hLogoff, MF_STRING, LOGOFF11, "Звук завершения работы Windows 11");




        SetMenu(hWnd, hMenubar);
        BASS_Init(-1, 44100, 0, 0, NULL);

        HINSTANCE hInst = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);
        HICON hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\MixOS.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);




        eMp3 = CreateWindow(TEXT("Edit"), NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE, 120 + 220, 240, 400, 20, hWnd, (HMENU)MIDIC, NULL, 0);
        ShowWindow(GetDlgItem(hWnd, MIDIC), SW_HIDE);
        CreateWindow(TEXT("BUTTON"), TEXT("Включить музыку"), WS_VISIBLE | WS_CHILD, 15, 15, 160, 30, hWnd, (HMENU)TITLE, NULL, NULL);


        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\play.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

        SendMessage(GetDlgItem(hWnd, TITLE), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT("Выключить музыку"), WS_VISIBLE | WS_CHILD, 15, 15, 160, 30, hWnd, (HMENU)TITLESTOP, NULL, NULL);


        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\pause.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

        SendMessage(GetDlgItem(hWnd, TITLESTOP), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);



        hTrack = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | WS_VISIBLE, 50+a, 270, 550, 20, hWnd, (HMENU)VOLUMASTA, NULL, NULL);
        ShowWindow(GetDlgItem(hWnd, VOLUMASTA), SW_HIDE);
        /*ShowWindow(GetDlgItem(hWnd, LENMUSIC1), SW_SHOW);*/
        SendMessage(hTrack, TBM_SETPOS, 1, 9);
        SendMessage(hTrack, TBM_SETRANGEMAX, TRUE, 100);



        ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_SHOW);


        CreateWindow(TEXT("STATIC"), TEXT("Какую винду хотите запустить?"), WS_VISIBLE | WS_CHILD, 200, 30, 310, 20, hWnd, (HMENU)text1, NULL, NULL);



        CreateWindow(TEXT("STATIC"), TEXT("Windows 80286"), WS_VISIBLE | WS_CHILD, 55+a, 90, 260, 20, hWnd, (HMENU)text1, NULL, NULL); 

        CreateWindow(TEXT("BUTTON"), TEXT("Windows 1.0"), WS_VISIBLE | WS_CHILD, 50+a, 110, 120, 20, hWnd, (HMENU)WINDOWS1_0, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\WIN95.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, WINDOWS1_0), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);



        CreateWindow(TEXT("BUTTON"), TEXT("Windows 2.0"), WS_VISIBLE | WS_CHILD, 50+a, 135, 120, 20, hWnd, (HMENU)WINDOWS2_0, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\WIN95.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, WINDOWS2_0), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


        CreateWindow(TEXT("BUTTON"), TEXT("Windows 3.0"), WS_VISIBLE | WS_CHILD, 50+a, 160, 120, 20, hWnd, (HMENU)WINDOWS3_0, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\WIN95.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, WINDOWS3_0), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT("Windows 3.11"), WS_VISIBLE | WS_CHILD, 50+a, 185, 120, 20, hWnd, (HMENU)WIN311, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\WIN95.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, WIN311), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT("Написать разработчику"), WS_VISIBLE | WS_CHILD, 50 + a, 210, 260, 45, hWnd, (HMENU)MAIL, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\MixOS.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, MAIL), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);
        



        CreateWindow(TEXT("STATIC"), TEXT("Windows 9X"), WS_VISIBLE | WS_CHILD, 200+15+a, 90, 310, 20, hWnd, (HMENU)text1, NULL, NULL);



        CreateWindow(TEXT("BUTTON"), TEXT("Windows 95"), WS_VISIBLE | WS_CHILD, 190 + a, 110, 120, 20, hWnd, (HMENU)WINDOWS_95, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\WIN95.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, WINDOWS_95), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


        CreateWindow(TEXT("BUTTON"), TEXT("Windows 98"), WS_VISIBLE | WS_CHILD, 190 + a, 135, 120, 20, hWnd, (HMENU)WINDOWS_98, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\WIN95.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, WINDOWS_98), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);



        CreateWindow(TEXT("BUTTON"), TEXT("Windows ME"), WS_VISIBLE | WS_CHILD, 190 + a, 160, 120, 20, hWnd, (HMENU)WINDOWS_ME, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\WIN95.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, WINDOWS_ME), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


        CreateWindow(TEXT("BUTTON"), TEXT("Windows CE"), WS_VISIBLE | WS_CHILD, 190 + a, 185, 120, 20, hWnd, (HMENU)WINDOWS_CE, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\WIN95.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, WINDOWS_CE), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);






        CreateWindow(TEXT("STATIC"), TEXT("Windows NT"), WS_VISIBLE | WS_CHILD, 300+40+a+70, 90, 310, 20, hWnd, (HMENU)text1, NULL, NULL);


        CreateWindow(TEXT("BUTTON"), TEXT("Windows NT 3.1"), WS_VISIBLE | WS_CHILD, 190 + 140 + a, 110, 130, 20, hWnd, (HMENU)WINDOWSNT3_1, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\WIN95.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, WINDOWSNT3_1), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT("Windows NT 3.51"), WS_VISIBLE | WS_CHILD, 190+140+a, 135, 130, 20, hWnd, (HMENU)WINDOWSNT3_51, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\WIN95.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, WINDOWSNT3_51), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT("Windows NT 4.0"), WS_VISIBLE | WS_CHILD, 190 + 140+a, 160, 130, 20, hWnd, (HMENU)WINDOWSNT4, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\WIN95.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, WINDOWSNT4), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT("Windows NT 5.0"), WS_VISIBLE | WS_CHILD, 190 + 140+a, 185, 130, 20, hWnd, (HMENU)WINDOWSNT5, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\WIN95.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, WINDOWSNT5), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT("Windows 2000"), WS_VISIBLE | WS_CHILD, 190 + 140+a, 210, 130, 20, hWnd, (HMENU)WINDOWS2000, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\WIN95.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, WINDOWS2000), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);








        CreateWindow(TEXT("BUTTON"), TEXT("Windows XP"), WS_VISIBLE | WS_CHILD, 190 + 140+a, 160+75, 130, 20, hWnd, (HMENU)WINDOWSXP, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\WINXP.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, WINDOWSXP), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


        CreateWindow(TEXT("BUTTON"), TEXT("Windows VISTA"), WS_VISIBLE | WS_CHILD, 190 + 280+a, 110, 130, 20, hWnd, (HMENU)WINDOWSVISTA, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\VISTA.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, WINDOWSVISTA), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT("Windows 7"), WS_VISIBLE | WS_CHILD, 190 + 280+a, 135, 130, 20, hWnd, (HMENU)WINDOWS7, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\VISTA.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, WINDOWS7), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT("Windows 8"), WS_VISIBLE | WS_CHILD, 190 + 280 + a, 160, 130, 20, hWnd, (HMENU)WINDOWS8, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\WIN8.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, WINDOWS8), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT("Windows 8.1"), WS_VISIBLE | WS_CHILD, 190 + 280 + a, 160+25, 130, 20, hWnd, (HMENU)WIN8, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\WIN8.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, WIN8), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT("Windows 10"), WS_VISIBLE | WS_CHILD, 190 + 280 + a, 160+50, 130, 20, hWnd, (HMENU)WINDOWS10, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\WIN8.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, WINDOWS10), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


        CreateWindow(TEXT("BUTTON"), TEXT("Windows 11"), WS_VISIBLE | WS_CHILD, 190 + 140+140+a, 160 + 75, 130, 20, hWnd, (HMENU)WINDOWS11, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\WIN8.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, WINDOWS11), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);



       
        BASS_Stop();
        BASS_Start();
        if (MessageBox(hWnd, "Вы точно хотите попробовать запустить любую шиндовс?", "Внимание", MB_YESNO | MB_ICONQUESTION) == IDYES)
        {
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\Shattered.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }
        else
        {
            PostQuitMessage(0);
        };
        break;


    }
    case WM_COMMAND: {





        if (LOWORD(wParam) == TITLE)
        {
            BASS_Stop();
            BASS_Start();
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            SendMessage(hWnd, WM_COMMAND, MYMUSIC, 0);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            BASS_ChannelPlay(UASSAULT, false);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_SHOW);
        }
        if (LOWORD(wParam) == TITLESTOP)
        {
            BASS_Stop();
            BASS_Start();
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
        }


        if (LOWORD(wParam) == MYMUSIC)
        {
        
             #define MUSICRAND (rand()%100)
            if (MUSICRAND <= 10)
            {
                ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
                ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_SHOW);
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\Shattered.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);

            }
            if (MUSICRAND >= 11 && MUSICRAND <= 20)
            {
                ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
                ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_SHOW);
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\ErrorMIX.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
            }

            if (MUSICRAND >= 21 && MUSICRAND <=  30)
            {
                ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
                ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_SHOW);
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\ME.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
            }


            if (MUSICRAND >= 31 && MUSICRAND <= 40)
            {
                ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
                ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_SHOW);
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\XP.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
            }

            if (MUSICRAND >= 41 && MUSICRAND <= 50)
            {
                ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
                ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_SHOW);
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\XP2.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
            }

            if (MUSICRAND >= 51 && MUSICRAND <= 60)
            {
                ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
                ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_SHOW);
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\7.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
            }


            if (MUSICRAND >= 61 && MUSICRAND <= 70)
            {
                ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
                ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_SHOW);
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\OLDMIX.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
            }
            if (MUSICRAND >= 71 && MUSICRAND <= 80)
            {
                ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
                ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_SHOW);
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\TITLE.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
            }
            if (MUSICRAND >= 81 && MUSICRAND <= 90)
            {
                ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
                ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_SHOW);
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\8.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
            }

            if (MUSICRAND >= 91)
            {
                ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
                ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_SHOW);
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\95.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
            }



        }


       
















        if (LOWORD(wParam) == WINDOWS1_0)
        {
            WIN32_FIND_DATA win1;
            HANDLE hFind = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WIN80286\\WIN1\\WIN1.mixos", &win1);

            
            if (INVALID_HANDLE_VALUE != hFind) {

                FindClose(hFind);
          
                system("start MusicPlayer\\W311\\dosbox.exe -conf MusicPlayer\\W311\\WIN1.conf -noconsole");
            }
            else 
            {





                if (MessageBox(hWnd, "У вас не установлена Шинда 1! \nЖелаете установить?", "WINDOWS1_NOT_FOUND", MB_YESNO | MB_ICONQUESTION) == IDYES)
                {


                    
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/1G", "MusicPlayer\\SYSTEM\\WINDOWS\\EXAMPLE", 0, 0);
                    WIN32_FIND_DATA EXAMPLE;
                    HANDLE hFind = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\EXAMPLE", &EXAMPLE);
                    if (INVALID_HANDLE_VALUE != hFind)
                    {
                        MessageBox(hWnd, "ВСЁ ЗАЕБИСЬ", "W", MB_YESNO | MB_ICONQUESTION == IDYES);
                    }
                    if (INVALID_HANDLE_VALUE == hFind)
                    {
                        MessageBox(hWnd, "ВСЁ ХУЁВО", "W", MB_YESNO | MB_ICONQUESTION == IDYES);
                    }


                }
                return false;
                FindClose(hFind);
            };







                
            
        }
        if (LOWORD(wParam) == WINDOWS2_0)
        {
            //system("start MusicPlayer\\DWL\\bin\\Plugins\\1.bat");   //converter



            WIN32_FIND_DATA win2;
            HANDLE hFind = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WIN80286\\WIN2\\WIN2.mixos", &win2);


            if (INVALID_HANDLE_VALUE != hFind) {

                FindClose(hFind);

                system("start MusicPlayer\\W311\\dosbox.exe -conf MusicPlayer\\W311\\WIN2.conf -noconsole");
            }
            else
            {





                if (MessageBox(hWnd, "У вас не установлена Шинда 2! \nЖелаете установить?", "WINDOWS2_NOT_FOUND", MB_YESNO | MB_ICONQUESTION) == IDYES)
                {
                    MessageBox(hWnd, "Загружается", "Загрузка", MB_ICONWARNING);
                }
                return false;
                FindClose(hFind);
            };










            

        }

        if (LOWORD(wParam) == WINDOWS3_0)
        {

            WIN32_FIND_DATA win3;
            HANDLE hFind = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WIN80286\\WIN3\\WIN3.mixos", &win3);


            if (INVALID_HANDLE_VALUE != hFind) 
            {

                FindClose(hFind);

                system("start MusicPlayer\\W311\\dosbox.exe -conf MusicPlayer\\W311\\WIN3.conf -noconsole");
            }
            else
            {





                if (MessageBox(hWnd, "У вас не установлена Шинда 3! \nЖелаете установить?", "WINDOWS2_NOT_FOUND", MB_YESNO | MB_ICONQUESTION) == IDYES)
                {
                    MessageBox(hWnd, "Загружается", "Загрузка", MB_ICONWARNING);
                    PostQuitMessage(0);
                }
                    
                return false;
                FindClose(hFind);
            };


            

        }
        if (LOWORD(wParam) == WIN311)
        {
            //system("start MusicPlayer\\DWL\\bin\\Plugins\\1.bat");   //converter
            WIN32_FIND_DATA win3;
            HANDLE hFind = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WIN80286\\WIN3.11\\WIN31.mixos", &win3);

            

            if (INVALID_HANDLE_VALUE != hFind)
            {

                FindClose(hFind);
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\Win3.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                system("start MusicPlayer\\W311\\dosbox.exe -conf MusicPlayer\\W311\\dosbox.conf -noconsole");
            }
            else
            {


                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\CHORD.WAV", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);


                if (MessageBox(hWnd, "У вас не установлена Шинда 3.11! \nЖелаете установить?", "Внимание", MB_YESNO | MB_ICONWARNING) == IDYES)
                {
                    /*MessageBox(hWnd, "Загружается", "Загрузка", MB_ICONWARNING);*/
                    PostQuitMessage(0);
                }

                return false;
                FindClose(hFind);
            };




        }










        if (LOWORD(wParam) == WINDOWS_95)
        {
            //system("start MusicPlayer\\DWL\\bin\\Plugins\\1.bat");   //converter

            #define RANDOMIZING (rand()%100)
            WIN32_FIND_DATA win95;
            HANDLE hFind = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WIN9X\\WIN95\\95.mixos", &win95);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\Win95.wav", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                    system("MusicPlayer\\SYSTEM\\WINDOWS\\WIN9X\\WIN95\\95.bat");
                    FindClose(hFind);
            }
            if (INVALID_HANDLE_VALUE == hFind)
            {
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\CHORD.WAV", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                MessageBox(hWnd, "Windows 95 не найдена\nПопробую запустить то, что есть...", "WINDOWS95_NOT_FOUND", MB_ICONWARNING);

                system("start MusicPlayer\\Emulators\\OLDPC\\WIN95\\windows95.exe");
            }    

        }


        if (LOWORD(wParam) == WINDOWS_98)
        {
            WIN32_FIND_DATA win98;
            HANDLE hFind = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WIN9X\\WIN98\\98.mixos", &win98);
            if (INVALID_HANDLE_VALUE != hFind)
            {
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\Win98.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                system("MusicPlayer\\SYSTEM\\WINDOWS\\WIN9X\\WIN98\\98.bat");
            }
            if (INVALID_HANDLE_VALUE == hFind)
            {
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\CHORD.WAV", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                if (MessageBox(hWnd, "У вас не установлена Шинда 98\nЖелаете установить?", "WINDOWS98_NOT_FOUND", MB_YESNO | MB_ICONWARNING) == IDYES)
                {
                    PostQuitMessage(0);
                }

            }
        }

        if (LOWORD(wParam) == WINDOWS_ME)
        {
            //system("start MusicPlayer\\DWL\\bin\\Plugins\\1.bat");   //converter

            WIN32_FIND_DATA winme;
            HANDLE hFind = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WIN9X\\WINME\\ME.mixos", &winme);
            if (INVALID_HANDLE_VALUE != hFind)
            {
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\WinME.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                system("MusicPlayer\\SYSTEM\\WINDOWS\\WIN9X\\WINME\\ME.bat");
            }
            if (INVALID_HANDLE_VALUE == hFind)
            {
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\DING.WAV", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                if (MessageBox(hWnd, "У вас не установлена Шиндовс Бараны\nЖелаете установить?", "WINDOWSME_NOT_FOUND", MB_YESNO | MB_ICONWARNING) == IDYES)
                {
                    PostQuitMessage(0);
                }

            }
        }


        if (LOWORD(wParam) == WINDOWS_CE)
        {
            //system("start MusicPlayer\\DWL\\bin\\Plugins\\1.bat");   //converter

            WIN32_FIND_DATA wince ;
            HANDLE hFind = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WIN9X\\WINCE\\CE.mixos", &wince);
            if (INVALID_HANDLE_VALUE != hFind)
            {
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\Win95.wav", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                system("MusicPlayer\\SYSTEM\\WINDOWS\\WIN9X\\WINCE\\CE.bat");
            }
            if (INVALID_HANDLE_VALUE == hFind)
            {
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\DING.WAV", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                if (MessageBox(hWnd, "У вас не установлена Шиндовс CE\nЖелаете установить?", "WINDOWSCE_NOT_FOUND", MB_YESNO | MB_ICONWARNING) == IDYES)
                {
                    PostQuitMessage(0);
                }

            }
        }









        if (LOWORD(wParam) == WINDOWSNT3_1)
        {
            WIN32_FIND_DATA winNT31;
            HANDLE hFind = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WINNT31\\NT31.mixos", &winNT31);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                MessageBoxA(hWnd, "Пароль от Windows NT 3.1 \n                 1234 ", "Внимание", MB_ICONASTERISK);
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\Win3.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                system("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WINNT31\\NT3.bat");
            }
            if (INVALID_HANDLE_VALUE == hFind)
            {
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\CHORD.WAV", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                if (MessageBox(hWnd, "У вас не установлена серьёзная шинда NT 3\nЖелаете установить?", "WINDOWSNT3_NOT_FOUND", MB_YESNO | MB_ICONWARNING) == IDYES)
                {
                    PostQuitMessage(0);
                }

            }



        }

        if (LOWORD(wParam) == WINDOWSNT3_51)
        {

            WIN32_FIND_DATA winNT35;
            HANDLE hFind = FindFirstFile("MusicPlayer\\Emulators\\OLDPC\\WINNT\\Win351\\NT35.mixos", &winNT35);
            if (INVALID_HANDLE_VALUE != hFind)
            {
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\Win3.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                system("start MusicPlayer\\Emulators\\OLDPC\\WINNT\\Win351\\86box.exe MusicPlayer\\Emulators\\OLDPC\\WINNT\\Win351\\86Box.cfg");
            }
            if (INVALID_HANDLE_VALUE == hFind)
            {
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\CHORD.WAV", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                if (MessageBox(hWnd, "Для корректной работы Windows NT 3.5 \nтребуется наличие списка эмуляторов!!!\n              Желаете установить?", "WINDOWSNT3.5_NOT_FOUND", MB_YESNO | MB_ICONWARNING) == IDYES)
                {
                    PostQuitMessage(0);
                }

            }
        }


        if (LOWORD(wParam) == WINDOWSNT4)
        {
            WIN32_FIND_DATA winNT4;
            HANDLE hFind = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WINNT4\\NT4.mixos", &winNT4);
            if (INVALID_HANDLE_VALUE != hFind)
            {
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\WinNT4.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                system("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WINNT4\\NT4.bat");
            }
            if (INVALID_HANDLE_VALUE == hFind)
            {
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\CHORD.WAV", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                if (MessageBox(hWnd, "У вас не стоит. В смысле не установлена Шинда NT 4 \n                 Желаете установить?", "WINDOWSNT4_NOT_FOUND", MB_YESNO | MB_ICONWARNING) == IDYES)
                {
                    PostQuitMessage(0);
                }
            }
        }

        if (LOWORD(wParam) == WINDOWSNT5)
        {
            WIN32_FIND_DATA winNT5;
            HANDLE hFind = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WINNT5\\NT5.mixos", &winNT5);
            if (INVALID_HANDLE_VALUE != hFind)

            {
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\WinNT5.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                system("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WINNT5\\NT5.bat");
            }
            if (INVALID_HANDLE_VALUE == hFind)
            {
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\DING.WAV", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                if (MessageBox(hWnd, "У вас не установлена Windows NT 5.0 \n                Желаете установить?", "WINDOWSNT5_NOT_FOUND", MB_YESNO | MB_ICONWARNING) == IDYES)
                {
                    PostQuitMessage(0);
                }
            }
        }

        if (LOWORD(wParam) == WINDOWS2000)
        {
            WIN32_FIND_DATA win2000;
            HANDLE hFind = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WIN2000\\2000.mixos", &win2000);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\DING.WAV", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                MessageBox(hWnd, "Пароль от Windows 2000 \n                 6842 ", "Внимание", MB_ICONASTERISK);
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\Win2000.wav", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                system("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WIN2000\\2000.bat");
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGOFF\\Win2000.wav", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);

            }

            if (INVALID_HANDLE_VALUE == hFind)
            {
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\DING.WAV", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                if (MessageBox(hWnd, "У вас не установлена Windows 2000 \n                Желаете установить?", "WINDOWS2000_NOT_FOUND", MB_YESNO | MB_ICONWARNING) == IDYES)
                {
                    PostQuitMessage(0);
                }
            }


        }





        if (LOWORD(wParam) == WINDOWSXP)
        {
            WIN32_FIND_DATA winXP;
            HANDLE hFind = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WINXP\\XP.mixos", &winXP);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\WinXP.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                system("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WINXP\\xp.bat");

            }

            if (INVALID_HANDLE_VALUE == hFind)
            {
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\xp.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                if (MessageBox(hWnd, "У вас не установлена Windows XP!\n\rВы не не не желаете установить?", "WINDOWSXP_NOT_FOUND", MB_YESNO | MB_ICONWARNING) == IDYES)
                {
                    PostQuitMessage(0);
                }
            }

            
        }


        if (LOWORD(wParam) == WINDOWSVISTA)
        {
            WIN32_FIND_DATA win6;
            HANDLE hFind = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WINVISTA\\VISTA.mixos", &win6);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\Win7.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                system("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WINVISTA\\vista.bat");

            }

            if (INVALID_HANDLE_VALUE == hFind)
            {
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\7.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                if (MessageBox(hWnd, "У вас не установлена легендарная VISTA!!!\n\rНе желаете установить?", "WINDOWSVISTA_NOT_FOUND", MB_YESNO | MB_ICONWARNING) == IDYES)
                {
                    PostQuitMessage(0);
                }
            }

            
        }

        if (LOWORD(wParam) == WINDOWS7)
        {

            WIN32_FIND_DATA win7;
            HANDLE hFind = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WIN7\\7.mixos", &win7);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\Win7.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                system("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WIN7\\7.bat");

            }

            if (INVALID_HANDLE_VALUE == hFind)
            {
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\7.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                if (MessageBox(hWnd, "У вас не установлена WINDOWS 7!!!\n\rНе желаете установить?", "WINDOWS7_NOT_FOUND", MB_YESNO | MB_ICONWARNING) == IDYES)
                {
                    PostQuitMessage(0);
                }
            }

        }

        if (LOWORD(wParam) == WIN8)

        {

            WIN32_FIND_DATA win8IGOR;
            HANDLE hFind = FindFirstFile("MusicPlayer\\SUBS\\IGOR2677\\WIN8\\F\\GoogleChromePortable.exe", &win8IGOR);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\Win10.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                system("start MusicPlayer\\SUBS\\IGOR2677\\Win8\\F\\GoogleChromePortable.exe file://C://WIN//WIN8//index.html");

            }

            if (INVALID_HANDLE_VALUE == hFind)
            {
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\10.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                if (MessageBox(hWnd, "Скорее всего у вас не стоят программы от подписчиков.\n\rЗайдите в загрузчик плагинов и установите", "WINDOWS8_NOT_FOUND", MB_OK | MB_ICONWARNING) == IDYES)
                {
                    PostQuitMessage(0);
                }
            }

            
        }

        if (LOWORD(wParam) == WINDOWS8)
        {
            WIN32_FIND_DATA win8;
            HANDLE hFind = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WIN8\\8.mixos", &win8);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\Win10.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                system("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WIN8\\8.bat");

            }

            if (INVALID_HANDLE_VALUE == hFind)
            {
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\10.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                if (MessageBox(hWnd, "У вас не установлена WINDOWS 8!!!\n\rЖелаете установить?", "WINDOWS8_1_NOT_FOUND", MB_YESNO | MB_ICONWARNING) == IDYES)
                {
                    PostQuitMessage(0);
                }
            }
        }

        if (LOWORD(wParam) == WINDOWS10)
        {
            WIN32_FIND_DATA win10;
            HANDLE hFind = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WIN10\\10.mixos", &win10);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\Win10.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                system("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WIN10\\10.bat");

            }

            if (INVALID_HANDLE_VALUE == hFind)
            {
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\10.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                if (MessageBox(hWnd, "У вас не установлена WINDOWS 10!!!\n\rЖелаете установить?", "WINDOWS10_NOT_FOUND", MB_YESNO | MB_ICONWARNING) == IDYES)
                {
                    PostQuitMessage(0);
                }
            }
            
        }




        if (LOWORD(wParam) == WINDOWS11)
        {
            WIN32_FIND_DATA win11;
            HANDLE hFind = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WIN11\\11.mixos", &win11);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                BASS_StreamFree(UASSAULT);
                BASS_ChannelStop(UASSAULT);
                BASS_SampleFree(UASSAULT);
                BASS_Stop();
                BASS_Start();
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\Win10.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                system("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WIN11\\11.bat");

            }

            if (INVALID_HANDLE_VALUE == hFind)
            {
                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\10.mp3", 0, 0, 0);
                BASS_ChannelPlay(UASSAULT, false);
                if (MessageBox(hWnd, "У вас не установлена WINDOWS 11!!!\n\rЖелаете установить?", "WINDOWS11_NOT_FOUND", MB_YESNO | MB_ICONWARNING) == IDYES)
                {
                    PostQuitMessage(0);
                }
            }
            
        }







    




        if (LOWORD(wParam) == STRANNIK)
        {
            ShellAbout(hWnd, progname, "Разработчик: Captain Strannik", progicon);
        }



        if (LOWORD(wParam) == polupon)
        {
            ShowWindow(GetDlgItem(hWnd, polupon), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, polupoff), SW_SHOW);
            SetWindowLongPtr(hWnd, GWL_EXSTYLE, WS_EX_ACCEPTFILES | WS_EX_LAYERED);
            SetLayeredWindowAttributes(hWnd, NULL, 230, LWA_ALPHA);
        }
        if (LOWORD(wParam) == polupoff)
        {
            ShowWindow(GetDlgItem(hWnd, polupon), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, polupoff), SW_HIDE);
            SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);
            SetWindowLongPtr(hWnd, GWL_EXSTYLE, WS_EX_ACCEPTFILES);
        }








//=======================================================================================================================================








        if (LOWORD(wParam) == LOGON3)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\Win3.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }
        if (LOWORD(wParam) == LOGONNT3)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\Win3.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }
        if (LOWORD(wParam) == LOGON95)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\Win95.wav", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }

        if (LOWORD(wParam) == LOGONNT4)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\WinNT4.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }


        if (LOWORD(wParam) == LOGON98)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\Win98.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }
        if (LOWORD(wParam) == LOGONNT5)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\WinNT5.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }
        if (LOWORD(wParam) == LOGON2000)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\Win2000.wav", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }

        if (LOWORD(wParam) == LOGONME)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\WinME.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }

        if (LOWORD(wParam) == LOGONXP)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\WinXP.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }

        if (LOWORD(wParam) == LOGONVISTA)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\Win7.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }
        if (LOWORD(wParam) == LOGON10)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\Win10.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }

        if (LOWORD(wParam) == LOGON11)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGON\\Win11.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }

























        //=============================================================================================================================









        if (LOWORD(wParam) == LOGOFF3)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGOFF\\Win3.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }
        if (LOWORD(wParam) == LOGOFFNT3)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGOFF\\Win3.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }
        if (LOWORD(wParam) == LOGOFF95)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGOFF\\Win95.wav", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }

        if (LOWORD(wParam) == LOGOFFNT4)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGOFF\\WinNT4.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }


        if (LOWORD(wParam) == LOGOFF98)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGOFF\\Win98.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }
        if (LOWORD(wParam) == LOGOFFNT5)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGOFF\\WinNT5.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }
        if (LOWORD(wParam) == LOGOFF2000)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGOFF\\Win2000.wav", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }

        if (LOWORD(wParam) == LOGOFFME)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGOFF\\WinME.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }

        if (LOWORD(wParam) == LOGOFFXP)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGOFF\\WinXP.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }

        if (LOWORD(wParam) == LOGOFFVISTA)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGOFF\\Win7.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }
        if (LOWORD(wParam) == LOGOFF10)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGOFF\\Win10.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }

        if (LOWORD(wParam) == LOGOFF11)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\LOGOFF\\Win11.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }


        if (LOWORD(wParam) == MAIL)
        {
            BASS_StreamFree(UASSAULT);
            BASS_ChannelStop(UASSAULT);
            BASS_SampleFree(UASSAULT);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\title4.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
            system("start mailto:lesergig@gmail.com?subject=Operating%20Environment%20MixOS");
        }

        if (LOWORD(wParam) == VOLUMASTA1)
        {
            ShowWindow(GetDlgItem(hWnd, VOLUMASTA), SW_SHOW);
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
                hBrush = CreateSolidBrush(RGB(0, 0, 204));
                rgbCurrent = RGB(0, 76, 153);
                return 0;
            };


            InvalidateRect(hWnd, NULL, FALSE);

            // ТО АХРИНЕТЬ ОХУЕТЬ ТОЧНЕЕ. Теперь надо такое же добавить в Терминал... И в Пианино... И еще много куда...
        }

    case WM_HSCROLL:
     {
        if (hTrack == (HWND)lParam /*&& wParam != 0*/)
        {
            int volume = SendMessage(hTrack, TBM_GETPOS, 0, 0);
            BASS_ChannelSetAttribute(UASSAULT, BASS_ATTRIB_VOL, (float)volume/100);


        }
            

    } 
     break;


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

            SetBkColor(hdcStatic, RGB(255, 255, 255));


            return (LRESULT)(COLOR_WINDOW + 1);

        }
        if (GetDlgCtrlID((HWND)lParam) == VOLUMASTA)
        {
            HDC hdcStatic = (HDC)wParam;
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color

            SetBkColor(hdcStatic, RGB(255, 255, 255));


            return (LRESULT)(COLOR_WINDOW + 1);

        }
    }break;

    case WM_PAINT: {
        hdc = BeginPaint(hWnd, &ps);
        //ТАК, слушай, , я щас некоторое время не буду говорить, но скоро начну.Но я тут подумал, что смену скинов надо добавить и в остальные подпрограммы.Хотя бы в список эмуляторов
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
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
    return 0;
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
    progicon = (HICON)LoadImage(op.hInstance, "MusicPlayer\\BMP\\ico\\WINXP.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
    op.hIcon = progicon;

    //op.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    RegisterClass(&op);


    CreateWindowA(op.lpszClassName, "Сборник ОС Windows", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE, (GetSystemMetrics(SM_CXSCREEN) - 1280) / 2,
        (GetSystemMetrics(SM_CYSCREEN) - 720) / 2, 650-2, 360, NULL, NULL, op.hInstance, NULL);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }

}
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

int len;
TCHAR StrB[1200];


using namespace std;
char str1[1024];
HSTREAM QUEST_THEME;

HICON progicon;
int skins;
TCHAR StrT[MAX_PATH];
HANDLE bmpwall;
HANDLE bmpwall1;
HWND hwall;
static COLORREF acrCustClr[16];
HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 204));
static DWORD rgbCurrent = RGB(0, 0, 204);
HWND hTrack;
HDC hdc;
PAINTSTRUCT ps;
const TCHAR progname[] = _T("Urban Assault Сборник");
HWND tardis;
//bool key_pressed = false;
HINSTANCE hInst;
HSTREAM UASSAULT;
HSTREAM ABOUT;
HWND LOVE;
HWND LOVE1;
HWND LOVE2;
HWND LOVE3;
HWND LOVE4;

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
        data.hIcon = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\ghor.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        data.uVersion = NOTIFYICON_VERSION;

        /*     strcpy(data.szInfoTitle, "Загрузчик видео с Youtube");*/
        strcpy(data.szTip, "Шашнахме квест");


        Shell_NotifyIcon(NIM_ADD, &data);



        HMENU hMenubar = CreateMenu();
        HMENU hAbout = CreateMenu();
        HMENU hOptions = CreateMenu();


        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "Справка");
        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hOptions, "Настройки");



        SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
        AppendMenu(hAbout, MF_STRING, STRANNIK, "О программе");


        AppendMenu(hOptions, MF_STRING, MYCOLOR, "Сменить цвет");
        AppendMenu(hOptions, MF_SEPARATOR,MYCOLOR,0);
        AppendMenu(hOptions, MF_STRING, CHANGEMUSIC, "Сменить музыку");


        SetMenu(hWnd, hMenubar);
        BASS_Init(-1, 44100, 0, 0, NULL);

        HINSTANCE hInst = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);
        HICON hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\MixOS.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

        CreateWindow(TEXT("STATIC"), TEXT("Какую версию игры желаете запустить?"), WS_VISIBLE | WS_CHILD, 200, 30, 280, 20, hWnd, (HMENU)text1, NULL, NULL);


        CreateWindow(TEXT("BUTTON"), TEXT("Urban Assault Original"), WS_VISIBLE | WS_CHILD, 170, 100, 300, 20, hWnd, (HMENU)UAORIG, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\UA.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, UAORIG), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);



        CreateWindow(TEXT("BUTTON"), TEXT("Urban Assault Metropolis Dawn Ghor"), WS_VISIBLE | WS_CHILD, 170, 130, 300, 20, hWnd, (HMENU)UAMETROGHOR, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\ghor.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, UAMETROGHOR), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


        CreateWindow(TEXT("BUTTON"), TEXT("Urban Assault Metropolis Dawn Taer"), WS_VISIBLE | WS_CHILD, 170, 160, 300, 20, hWnd, (HMENU)UAMETROTAER, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Taer.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, UAMETROTAER), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);



        CreateWindow(TEXT("BUTTON"), TEXT("Urban Assault Ghor Campaign"), WS_VISIBLE | WS_CHILD, 170, 190, 300, 20, hWnd, (HMENU)UAORIGGHOR, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\UA.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, UAORIGGHOR), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT("ВИЖУ ПРОТИВНИКА"), WS_VISIBLE | WS_CHILD, 170, 220, 300, 60, hWnd, (HMENU)UASEENENEMY, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\UA.ico", IMAGE_ICON, 64, 64, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, UASEENENEMY), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT(" "), WS_VISIBLE | WS_CHILD, 480, 100, 150, 150, hWnd, (HMENU)UASEENENEMY1, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\ghor.ico", IMAGE_ICON, 132, 128, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, UASEENENEMY1), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT(" "), WS_VISIBLE | WS_CHILD, 480, 100, 150, 150, hWnd, (HMENU)UASEENENEMY2, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\taer.ico", IMAGE_ICON, 132, 128, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, UASEENENEMY2), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT(" "), WS_VISIBLE | WS_CHILD, 480, 100, 150, 150, hWnd, (HMENU)UASEENENEMY3, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\UA.ico", IMAGE_ICON, 132, 128, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, UASEENENEMY3), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        ShowWindow(GetDlgItem(hWnd, UASEENENEMY), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, UASEENENEMY2), SW_HIDE);
        ShowWindow(GetDlgItem(hWnd, UASEENENEMY3), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\UA.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);

            CreateWindow(TEXT("BUTTON"), TEXT("1"), WS_VISIBLE | WS_CHILD, 30, 100, 30, 30, hWnd, (HMENU)MUA1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("2"), WS_VISIBLE | WS_CHILD, 70, 100, 30, 30, hWnd, (HMENU)MUA2, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("3"), WS_VISIBLE | WS_CHILD, 110, 100, 30, 30, hWnd, (HMENU)MUA3, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("4"), WS_VISIBLE | WS_CHILD, 30, 140, 30, 30, hWnd, (HMENU)MUA4, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("5"), WS_VISIBLE | WS_CHILD, 70, 140, 30, 30, hWnd, (HMENU)MUA5, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("6"), WS_VISIBLE | WS_CHILD, 110, 140, 30, 30, hWnd, (HMENU)MUA6, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("8"), WS_VISIBLE | WS_CHILD, 70, 180, 30, 30, hWnd, (HMENU)MUA8, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("9"), WS_VISIBLE | WS_CHILD, 110, 180, 30, 30, hWnd, (HMENU)MUA9, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("7"), WS_VISIBLE | WS_CHILD, 30, 180, 30, 30, hWnd, (HMENU)MUA7, NULL, NULL);
            
            CreateWindow(TEXT("BUTTON"), TEXT("Выключить"), WS_VISIBLE | WS_CHILD, 30, 220, 110, 30, hWnd, (HMENU)STOPSOUNDUA, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Включить"), WS_VISIBLE | WS_CHILD, 30, 220, 110, 30, hWnd, (HMENU)PLAYSOUNDUA, NULL, NULL);



            ShowWindow(GetDlgItem(hWnd, MUA1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUA2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUA3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUA4), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUA5), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUA6), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUA7), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUA8), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUA9), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STOPSOUNDUA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PLAYSOUNDUA), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, UASEENENEMY1), SW_HIDE);
        break;


    }
    case WM_COMMAND: {

        //ShowWindow(GetDlgItem(hWnd, LENMUSIC), SW_SHOW);





        //if (LOWORD(wParam) == QUESTION2)
        //{
        //    if (StrB == "ДА")
        //    {
        //        MessageBoxA(hWnd, "Не переживай по этому поводу.\n", "Разбор проблемы 2", MB_ICONINFORMATION);
        //        CreateWindow(TEXT("STATIC"), TEXT("Тебе одиноко? ДА/НЕТ?"), WS_VISIBLE | WS_CHILD, 150 + 50 + 5 + 60, 50, 180, 20, hWnd, (HMENU)text1, NULL, NULL);
        //        len = GetWindowText(LOVE, StrB, 1200);
        //        CreateWindow(TEXT("BUTTON"), TEXT("Сказать"), WS_VISIBLE | WS_CHILD, 220, 180, 150, 30, hWnd, (HMENU)QUESTION2, NULL, NULL);
        //    }
        //    if (StrB == "НЕТ")
        //    {
        //        CreateWindow(TEXT("STATIC"), TEXT("Тебе одиноко? ДА/НЕТ?"), WS_VISIBLE | WS_CHILD, 150 + 50 + 5 + 60, 50, 180, 20, hWnd, (HMENU)text1, NULL, NULL);
        //        len = GetWindowText(LOVE, StrB, 1200);
        //        CreateWindow(TEXT("BUTTON"), TEXT("Сказать"), WS_VISIBLE | WS_CHILD, 220, 180, 150, 30, hWnd, (HMENU)QUESTION2, NULL, NULL);


        //    }


      /*  }*/

        if (LOWORD(wParam) == UASEENENEMY1)
        {
            BASS_StreamFree(ABOUT);
            BASS_Start();
            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\17331.WAV", 0, 0, 0);
            BASS_ChannelPlay(ABOUT, false);
            ShowWindow(GetDlgItem(hWnd, UASEENENEMY1), SW_HIDE);
        }
        if (LOWORD(wParam) == UASEENENEMY2)
        {
            BASS_StreamFree(ABOUT);
            BASS_Start();
            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\17331.WAV", 0, 0, 0);
            BASS_ChannelPlay(ABOUT, false);
            ShowWindow(GetDlgItem(hWnd, UASEENENEMY2), SW_HIDE);
        }
        if (LOWORD(wParam) == UASEENENEMY3)
        {
            BASS_StreamFree(ABOUT);
            BASS_Start();
            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\21211.WAV", 0, 0, 0);
            BASS_ChannelPlay(ABOUT, false);
            ShowWindow(GetDlgItem(hWnd, UASEENENEMY3), SW_HIDE);
        }
        if (LOWORD(wParam) == STRANNIK)
        {
            BASS_StreamFree(ABOUT);
            BASS_Start();  
            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1A121.WAV", 0, 0, 0); 
            
            BASS_ChannelPlay(ABOUT, false);
            ShellAbout(hWnd, progname, "Разработчик: Captain Strannik", progicon);

            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1A231.WAV", 0, 0, 0);
            BASS_ChannelPlay(ABOUT, false);
        }
        if (LOWORD(wParam) == UASEENENEMY)
        {
            
            BASS_Start();
            BASS_StreamFree(ABOUT);
            
            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\11221.WAV", 0, 0, 0);
            BASS_ChannelPlay(ABOUT, false);

        }
        if (LOWORD(wParam) == UAORIG)
        {
            system("MusicPlayer\\UA\\StartOrig.bat");
            PostQuitMessage(0);
        }
        if (LOWORD(wParam) == UAORIGGHOR)
        {
            system("MusicPlayer\\UA\\StartOrigGhor.bat");
            PostQuitMessage(0);
        }
        if (LOWORD(wParam) == UAMETROGHOR)
        {
            system("MusicPlayer\\UA\\StartMetroGhor.bat");
            PostQuitMessage(0);
        }
        if (LOWORD(wParam) == UAMETROTAER)
        {
            system("MusicPlayer\\UA\\StartMetroTaer.bat");
            PostQuitMessage(0);
        }
        if (LOWORD(wParam) == CHANGEMUSIC)
        {

            CreateWindow(TEXT("STATIC"), TEXT("Музыка"), WS_VISIBLE | WS_CHILD, 60, 80, 60, 20, hWnd, (HMENU)text1, NULL, NULL);

            ShowWindow(GetDlgItem(hWnd, MUA1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MUA2), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MUA3), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MUA4), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MUA5), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MUA6), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MUA7), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MUA8), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MUA9), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, text1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, STOPSOUNDUA), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PLAYSOUNDUA), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, UASEENENEMY1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, UASEENENEMY), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PLAYSOUNDUA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STOPSOUNDUA), SW_SHOW);
            BASS_Start();
            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1A132.WAV", 0, 0, 0);
            BASS_ChannelPlay(ABOUT, false);
        }
        if (LOWORD(wParam) == STOPSOUNDUA)
        {
            BASS_MusicFree(UASSAULT);
            BASS_StreamFree(UASSAULT);
            BASS_Stop();
            BASS_Start();
            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1A141.WAV", 0, 0, 0);
            BASS_ChannelPlay(ABOUT, false);
            ShowWindow(GetDlgItem(hWnd, PLAYSOUNDUA), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, STOPSOUNDUA), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, MUA1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUA2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUA3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUA4), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUA5), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUA6), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUA7), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUA8), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MUA9), SW_HIDE);
        }
        if (LOWORD(wParam) == PLAYSOUNDUA)
        {
            BASS_MusicFree(UASSAULT);
            BASS_StreamFree(UASSAULT);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\UA.mp3", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
            ShowWindow(GetDlgItem(hWnd, PLAYSOUNDUA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STOPSOUNDUA), SW_SHOW);

            ShowWindow(GetDlgItem(hWnd, MUA1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MUA2), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MUA3), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MUA4), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MUA5), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MUA6), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MUA7), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MUA8), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, MUA9), SW_SHOW);
        }
        if (LOWORD(wParam)==MUA1)
        { 
        BASS_MusicFree(UASSAULT);
        BASS_StreamFree(UASSAULT);
        BASS_StreamFree(ABOUT);
        BASS_Stop();
        BASS_Start();
        ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1A231.WAV", 0, 0, 0);
        BASS_ChannelPlay(ABOUT, false);
        UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\UA\\UAORIG\\music\\2.ogg", 0, 0, 0);
        BASS_ChannelPlay(UASSAULT, false);
        ShowWindow(GetDlgItem(hWnd, UASEENENEMY1), SW_SHOW);
        }
        if (LOWORD(wParam) == MUA2)
        {
            BASS_MusicFree(UASSAULT);
            BASS_StreamFree(UASSAULT);
            BASS_StreamFree(ABOUT);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\UA\\UAORIG\\music\\3.ogg", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }
        if (LOWORD(wParam) == MUA3)
        {
            BASS_MusicFree(UASSAULT);
            BASS_StreamFree(UASSAULT);
            BASS_StreamFree(ABOUT);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\UA\\UAORIG\\music\\4.ogg", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }
        if (LOWORD(wParam) == MUA4)
        {
            BASS_MusicFree(UASSAULT);
            BASS_StreamFree(UASSAULT);
            BASS_StreamFree(ABOUT);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\UA\\UAORIG\\music\\5.ogg", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }
        if (LOWORD(wParam) == MUA5)
        {
            BASS_MusicFree(UASSAULT);
            BASS_StreamFree(UASSAULT);
            BASS_StreamFree(ABOUT);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\UA\\UAORIG\\music\\6.ogg", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1A231.WAV", 0, 0, 0);
            BASS_ChannelPlay(ABOUT, false);
            ShowWindow(GetDlgItem(hWnd, UASEENENEMY2), SW_SHOW);
        }
        if (LOWORD(wParam) == MUA6)
        {
            BASS_MusicFree(UASSAULT);
            BASS_StreamFree(UASSAULT);
            BASS_StreamFree(ABOUT);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\UA\\UAORIG\\music\\7.ogg", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }
        if (LOWORD(wParam) == MUA7)
        {
            BASS_MusicFree(UASSAULT);
            BASS_StreamFree(UASSAULT);
            BASS_StreamFree(ABOUT);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\UA\\UAORIG\\music\\9.ogg", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }
        if (LOWORD(wParam) == MUA8)
        {
            BASS_MusicFree(UASSAULT);
            BASS_StreamFree(UASSAULT);
            BASS_StreamFree(ABOUT);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\UA\\UAORIG\\music\\10.ogg", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\UA\\UAORIG\\music\\1A231.WAV", 0, 0, 0);
            BASS_ChannelPlay(ABOUT, false);
            ShowWindow(GetDlgItem(hWnd, UASEENENEMY3), SW_SHOW);
        }
        if (LOWORD(wParam) == MUA9)
        {
            BASS_MusicFree(UASSAULT);
            BASS_StreamFree(UASSAULT);
            BASS_StreamFree(ABOUT);
            BASS_Stop();
            BASS_Start();
            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\UA\\UAORIG\\music\\11.ogg", 0, 0, 0);
            BASS_ChannelPlay(UASSAULT, false);
        }

        if (LOWORD(wParam) == MYCOLOR)
        {
            BASS_Start();
            BASS_StreamFree(ABOUT);
            
            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1B122.WAV", 0, 0, 0);
            BASS_ChannelPlay(ABOUT, false);
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

                BASS_Start();
                BASS_StreamFree(ABOUT);

                ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1B131.WAV", 0, 0, 0);
                BASS_ChannelPlay(ABOUT, false);
            }
            else
            {
                BASS_Start();
                BASS_StreamFree(ABOUT);

                ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1A141.WAV", 0, 0, 0);
                BASS_ChannelPlay(ABOUT, false);
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
        if (hTrack == (HWND)lParam)
        {
            BASS_ChannelSetAttribute(QUEST_THEME, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 25, 75));
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
    progicon = (HICON)LoadImage(op.hInstance, "MusicPlayer\\BMP\\ico\\ghor.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
    op.hIcon = progicon;

    //op.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    RegisterClass(&op);


    CreateWindowA(op.lpszClassName, "Urban Assault Сборник", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE, (GetSystemMetrics(SM_CXSCREEN) - 1280) / 2,
                (GetSystemMetrics(SM_CYSCREEN) - 720) / 2, 670, 360, NULL, NULL, op.hInstance, NULL);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }

}
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
const TCHAR progname[] = _T("�������� �����");
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
        data.uID = 1;          // ����� ��������� ����� �������������, �� ����� ������ ������ ����
        data.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
        data.uCallbackMessage = WM_USER_SHELLICON;
        data.hIcon = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\quest.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        data.uVersion = NOTIFYICON_VERSION;

        /*     strcpy(data.szInfoTitle, "��������� ����� � Youtube");*/
        strcpy(data.szTip, "�������� �����");

 
        Shell_NotifyIcon(NIM_ADD, &data);



        HMENU hMenubar = CreateMenu();
        HMENU hAbout = CreateMenu();
        HMENU hOptions = CreateMenu();


        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "�������");
        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hOptions, "���������");



        SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
        AppendMenu(hAbout, MF_STRING, STRANNIK, "� ���������");
        AppendMenu(hAbout, MF_STRING, STRANNI, "��������");


        AppendMenu(hOptions, MF_STRING, MYCOLOR, "������� ����");
        AppendMenu(hOptions, MF_SEPARATOR, NULL, NULL);
        AppendMenu(hOptions, MF_STRING, polupon, "�������� ����������������");
        AppendMenu(hOptions, MF_STRING, polupoff, "��������� ����������������");

        SetMenu(hWnd, hMenubar);
        BASS_Init(-1, 44100, 0, 0, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("������ ����"), WS_VISIBLE | WS_CHILD, 200, 100, 250, 150, hWnd, (HMENU)ID_BUTTON, NULL, NULL);


        
        
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
            ShellAbout(hWnd, progname, "�����������: Captain Strannik, ��������: Z_Kraf1er_Z", progicon);
            MessageBoxA(hWnd, "���� ����� �������� ����� ���� ������� ��������� ������. �� ������������� �������. � ��� �� ������� �����?", "� ���������", MB_OK);
        }
        if (LOWORD(wParam) == STRANNI)
        {
            SCREAM = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\skrimer.mp3", 0, 0, 0);
            BASS_ChannelPlay(SCREAM, false);
            REMIX = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\REMIX.mp3", 0, 0, 0);
            BASS_ChannelPlay(REMIX, false);
            MessageBoxA(hWnd, "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������", "��������", MB_ICONERROR);
            MessageBoxA(hWnd, "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������", "��������", MB_ICONERROR);
            MessageBoxA(hWnd, "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������", "��������", MB_ICONERROR);
            MessageBoxA(hWnd, "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������", "��������", MB_ICONERROR);
            MessageBoxA(hWnd, "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������", "��������", MB_ICONERROR);
            MessageBoxA(hWnd, "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������", "��������", MB_ICONERROR);
            MessageBoxA(hWnd, "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������", "��������", MB_ICONERROR);
            MessageBoxA(hWnd, "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������", "��������", MB_ICONERROR);
            MessageBoxA(hWnd, "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������", "��������", MB_ICONERROR);
            MessageBoxA(hWnd, "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������", "��������", MB_ICONERROR);
            MessageBoxA(hWnd, "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������", "��������", MB_ICONERROR);
            MessageBoxA(hWnd, "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������", "��������", MB_ICONERROR);
            MessageBoxA(hWnd, "��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������", "��������", MB_ICONERROR);
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
            CreateWindow(TEXT("STATIC"), TEXT("�� ���������� � ������ ��������, ������� �� ��� ������ ����,����� ����, ������ �� ��� ��������, ������� ������.\n���� ������?"), WS_VISIBLE | WS_CHILD | SS_CENTER, 100, 10, 450, 50, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("������ "), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)FIRST, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("����� "), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)SECOND, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("��������� �� �������� "), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)THIRD, NULL, NULL);

            CreateWindow(TEXT("STATIC"), TEXT("���������"), WS_VISIBLE | WS_CHILD, 210+60, 180+80+30-10, 200, 20, hWnd, (HMENU)text1, NULL, NULL);
            hTrack = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | WS_VISIBLE, 210, 180+80-20, 200, 20, hWnd, (HMENU)LENMUSIC, NULL, NULL);

            //SetWindowLong(hWnd, GWL_STYLE, WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE);
            //CreateWindow(_T("STATIC"), _T("�� ��� ��������"), WS_VISIBLE | WS_CHILD, 650, 60, 150, 20, hWnd, (HMENU)text1, NULL, NULL);
            //tardis = CreateWindow(_T("LISTBOX"), _T("���������� 3000"), WS_CHILD | LBS_HASSTRINGS | LBS_WANTKEYBOARDINPUT | WS_VSCROLL|WS_VISIBLE, 650, 100, 120, 150, hWnd, NULL, NULL, NULL);
            //CreateWindow(_T("BUTTON"), _T("������������"), WS_CHILD | WS_VISIBLE, 650, 270, 120, 22, hWnd, (HMENU)TELEPORT, NULL, NULL);
        }
        if (LOWORD(wParam) == FIRST)
        {
            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));

            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);

            CreateWindow(TEXT("STATIC"), TEXT(""), WS_VISIBLE | WS_CHILD, 225, 10, 450, 12, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("������ 32 ���� �� ������ � �������, ��� ����� ��� ������: BMW X5, LADA VESTA, Toyota Camri. � ��� ��� �������, ������� �� ����!                                                                                     "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);


            CreateWindow(TEXT("BUTTON"), TEXT("����� � Toyota"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)FIRST2, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("����� � BMW"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)SECOND2, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("����� � LADA "), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)THIRD2, NULL, NULL);


        }
        if (LOWORD(wParam) == SECOND)
        {
            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));

            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT(""), WS_VISIBLE | WS_CHILD, 225, 10, 450, 12, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("� ��������� �� ����� � ��������, � ������ � ��� ��� ��������... ���� �������� =( ������: ������� �� ������ �����. ���� �� ����� ���������� ������ ������. � ��������� ���, ��� �������� =)"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
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

            CreateWindow(TEXT("STATIC"), TEXT("���������� �� �������� �� ��������� �� ����� ������. �� ������� ����� ��������, ������ � ���������. ���� �����?                                                                                              "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);


            CreateWindow(TEXT("BUTTON"), TEXT("����� � ���������"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)VELOSIPED, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("����� � ������"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)MASHINA, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("����� � �������� "), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)HELICOPTER, NULL, NULL);
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
            CreateWindow(TEXT("STATIC"), TEXT("                ��� �� ��������� �� ������� ��������                                                                                                                                                             "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("������� �� ����������"), WS_VISIBLE | WS_CHILD, 220, 75, 185, 35, hWnd, (HMENU)VELOSIPED1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("������ � ����������"), WS_VISIBLE | WS_CHILD, 220, 115, 185, 35, hWnd, (HMENU)VELOSIPED2, NULL, NULL);
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
            CreateWindow(TEXT("STATIC"), TEXT("�� ���? ������ ��������? ������� ������. �� ������������ ������������ ������. �� �������� ������, ��� ������� �� ������ � �������� � ����� �� ��������? ���.... ������: <<����� �����, ����� � ����� �� �������� � �������� ��������, ���� ����� ��� ��� �� ����!>>"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
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
            CreateWindow(TEXT("STATIC"), TEXT("�� ��� �� ������ ������ � ���������� � ����� � ������ ���������"), WS_VISIBLE | WS_CHILD, 100, 10, 470, 80, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("����� � ���������"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)VELOSIPED3, NULL, NULL);


 

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
            CreateWindow(TEXT("STATIC"), TEXT("����� ���������� �������� � ����,�� ���� ������ ������������, ��� �� ��������, ������� �� ������ ���������, ����� �� �� ������ ����� ��������"), WS_VISIBLE | WS_CHILD, 100, 10, 480, 80, hWnd, (HMENU)text1, NULL, NULL);

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
            CreateWindow(TEXT("STATIC"), TEXT("��� ��������� ������ �������. � ��� ���� �������� � �����������. � ����� ��������� ���������� =). � �����, � ����� ����� �������?"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("� ������� �������"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)FUTURE, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("� ������� �������"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)BACK, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("���������� ������"), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)SUDBA, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("�������� �� ������� ����"), WS_VISIBLE | WS_CHILD, 220, 195, 185, 35, hWnd, (HMENU)FLY, NULL, NULL);
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
            CreateWindow(TEXT("STATIC"), TEXT("�� ������ � ������� �������, ��� ����� ���� ������, ��� ������� �� ��������. � ��� ���� ������.  ������:<<������� �� ��������, �� ������ ��������>> "), WS_VISIBLE | WS_CHILD, 100, 10, 480, 80, hWnd, (HMENU)text1, NULL, NULL);
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
            CreateWindow(TEXT("STATIC"), TEXT("�� ������ � ������� ������� � ������ � ���. � ������� ����� 10 ����� ��� ���� ��������. ���� ��������. ������:                       <<�� ������ ���� � ��� ����. ��� ����� � ��������������>>. "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
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
            CreateWindow(TEXT("STATIC"), TEXT("������� ���� ������ �� �������� ������ �� ������ ����������� ������, ������� ������ ������������ ����������. � ����� 5 ������ �� ����������. ������: <<�� ������� ���� c ���������� ��� ��������. ������� ������������>>."), WS_VISIBLE | WS_CHILD, 100, 10, 480, 80, hWnd, (HMENU)text1, NULL, NULL);
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
            CreateWindow(TEXT("STATIC"), TEXT("�� �������� ���� Kavinsky - Testarossa Autodrive � �������� ������ =). ������..  � ����� ��� ����� ���� ������? �� ������� �������!      "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
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
            CreateWindow(TEXT("STATIC"), TEXT("�� ��� ����� �� ������ �� ��������� ����� 1 ���, � ��, ��� ���� � ���� GTA VICE CITY. �� ������, �� �������� �� ������ ��� �������. ���� �������?"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("� ��������� �� ����"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)PARENTS, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("��������� � ������"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)CREMLIN, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("� ���"), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)USA, NULL, NULL);

        }
        if (LOWORD(wParam) == PARENTS)
        {
            ShowWindow(GetDlgItem(hWnd, USA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PARENTS), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, CREMLIN), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("                                                                                                                                                                                                                                                                                                                                                   "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 400, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("                                         ������� ���"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("�������"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)BOY, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("�������"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)GIRLOCHKA, NULL, NULL);


        }
        if (LOWORD(wParam) == USA)
        {
            ShowWindow(GetDlgItem(hWnd, USA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PARENTS), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, CREMLIN), SW_HIDE);
            BASS_ChannelStop(QUEST_THEME);
            CreateWindow(TEXT("STATIC"), TEXT("�� ���������� ��������� � ���. � �� �����-�� ������� ��� �� ���������� �� �������, �����������, ���� ���, ����� 5 ����� �� ���� �������� ������� ���. � ������� ��������� �������� � ��� ��������. �� ��������. ������: <<�� ����������� ���� �������, � �� ����� ��������>> "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            JACKSON = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\Stranger in Moscow.mp3", 0, 0, 0);
            BASS_ChannelPlay(JACKSON, false);
        }
        if (LOWORD(wParam) == CREMLIN)
        {
            ShowWindow(GetDlgItem(hWnd, USA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PARENTS), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, CREMLIN), SW_HIDE);
            BASS_ChannelStop(QUEST_THEME);
            CreateWindow(TEXT("STATIC"), TEXT("�������� � ������, �� ��������� �������� ������, ������� ��� ������ ����� ��������, ��� ��� ����� ����� ����� �� �������, ����� ��� �������� =). ������: <<���� �� ������, ���� �� ��������� ����� � �����, � �� �������� �������� � ����>> "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
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

            CreateWindow(TEXT("STATIC"), TEXT("�� �������� �� ���� � ���������. ��� ������ ������?"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("�������� ���������"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)HELP1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("����� � ���"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)SHOWER, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("����� � �����"), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)BOYFRIEND1, NULL, NULL);


        }
        if (LOWORD(wParam) == BOY)
        {
            ShowWindow(GetDlgItem(hWnd, USA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PARENTS), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, CREMLIN), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, BOY), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, GIRLOCHKA), SW_HIDE);

            CreateWindow(TEXT("STATIC"), TEXT("�� �������� �� ���� � ���������. ��� ������ ������?"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("�������� ���������"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)HELP1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("����� � ���"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)SHOWER, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("����� � �������"), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)DEVA1, NULL, NULL);

        }
        if (LOWORD(wParam) == BOYFRIEND1)
        {
            ShowWindow(GetDlgItem(hWnd, BOYFRIEND1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, BOY), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, GIRLOCHKA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELP1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SHOWER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, DEVA1), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("�� �� ��� �� ����� �� ������� ����������! ������ ������! ���� ��������! �� ����� � ��������! ������: <<������� �� ��������, �� ������ ���������!>>"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
        }
        if (LOWORD(wParam) == DEVA1)

        {
            ShowWindow(GetDlgItem(hWnd, BOY), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, GIRLOCHKA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELP1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SHOWER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, DEVA1), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("�� �� ��� �� ����� �� ������� ����������! ������� ������� � ������!! ���� ��������! �� ����� � ��������! ������: <<������� �� ��������, �� ������ ���������!>>"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
        }
        if (LOWORD(wParam) == HELP1)
        {
            ShowWindow(GetDlgItem(hWnd, SHOWER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, DEVA1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, BOYFRIEND1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELP1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LOVING), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("��������� �� ����������, ��������� ���������. �� � ����� ������� ����� ����������? ���� ��, �� �������. ���������� ��� ������! � ���� � ������: <<��������� �������>>"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
        }
        if (LOWORD(wParam) == SHOWER)
        {
            ShowWindow(GetDlgItem(hWnd, SHOWER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, DEVA1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, BOYFRIEND1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HELP1), SW_SHOW);
            CreateWindow(TEXT("BUTTON"), TEXT("����� ��������� �����"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)LOVING, NULL, NULL);
            

        }
        if (LOWORD(wParam) == LOVING)
        {
            ShowWindow(GetDlgItem(hWnd, HELP1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LOVING), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("����� ���� ������ �� ����� ���� ����� � ���������. ������:<<��� � ����� ������ ������ �������� � �������>>."), WS_VISIBLE | WS_CHILD, 100, 10, 470, 80, hWnd, (HMENU)text1, NULL, NULL);
            MessageBoxA(hWnd, "���������� �������� � ������������ �����, � ������� ����� ������ ��� ���� =)","������ �� MixOS Beta 2.2", MB_ICONASTERISK);

        }
        //if (LOWORD(wParam) == LOVING1)
        //{
        //    ShowWindow(GetDlgItem(hWnd, LOVING1), SW_HIDE);
        //    ShowWindow(GetDlgItem(hWnd, LOVING2), SW_HIDE);
        //    ShowWindow(GetDlgItem(hWnd, LOVING3), SW_HIDE);
        //    CreateWindow(TEXT("STATIC"), TEXT("�������! ������:<<� �������� ���� ����� ���� ������������ � �������."), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
        //}
        //if (LOWORD(wParam) == LOVING2)
        //{
        //    ShowWindow(GetDlgItem(hWnd, LOVING1), SW_HIDE);
        //    ShowWindow(GetDlgItem(hWnd, LOVING2), SW_HIDE);
        //    ShowWindow(GetDlgItem(hWnd, LOVING3), SW_HIDE);
        //    CreateWindow(TEXT("STATIC"), TEXT("�� ������� �������� �����! ������:<<����� �� ��������� �����, ����� ��������� ��-�� ����� �����>>."), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
        //}       
        //if (LOWORD(wParam) == LOVING3)
        //{
        //    ShowWindow(GetDlgItem(hWnd, LOVING1), SW_HIDE);
        //    ShowWindow(GetDlgItem(hWnd, LOVING2), SW_HIDE);
        //    ShowWindow(GetDlgItem(hWnd, LOVING3), SW_HIDE);
        //    CreateWindow(TEXT("STATIC"), TEXT("�� ������� �������� �����! ������:<<������ ������ ����������. ��� ������� �������, ������� ���������� ������� ��� �����������������. ��� �� ���������� � ������� ��� �� �������. � ����� ���������� ��� ���, �� ���. � ��� �� ������, � ������...>>."), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
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
            CreateWindow(TEXT("STATIC"), TEXT("��� � toyota �� ����������� � ������� ������, ����� ������ ������� � ����� �� ��� �����, ���� �� ��������� ������� �� ��������� ��� � ��������: <<�� �� ������ �������� ��� ��?>>. ���� ��������.������: �� �������� ���� � ������ ��� ����, ��� ����� � ����� ������. �� ����������� ����� ���� � ����������.     "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 480, hWnd, (HMENU)text1, NULL, NULL);
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
            CreateWindow(TEXT("STATIC"), TEXT("��� � BMW, �� �������� ���� Kavinsky-Nightcall � �������� �� ������!!!                                                                                                                                   "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
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
            CreateWindow(TEXT("STATIC"), TEXT("����������� ������� ������, ������ 50 �����, �� ���� ������ ������� �� ������� ����� ��� �� ��������, �� ������ 100 ������ ������ �������� � ��������� ������. �� ������ ���������, � ������ 5 ������ ����� �������, �� ������� 1% �������, ��� ��� ��������� ����� ������ 1 ���. ���� ��������?    "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("��������� ����"), WS_VISIBLE | WS_CHILD, 220,115, 185, 35, hWnd, (HMENU)FIRST3, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("��������� ������������"), WS_VISIBLE | WS_CHILD, 220, 155, 185, 35, hWnd, (HMENU)SECOND3, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("�������� � Geometry Dash"), WS_VISIBLE | WS_CHILD, 220, 195, 185, 35, hWnd, (HMENU)THIRD3, NULL, NULL);
        }
        if (LOWORD(wParam) == FIRST3)
        {
            CreateWindow(TEXT("STATIC"), TEXT("������ ��� �������, ��� �� ���? ������ �� �������? � ������� �� ���� ���� ������ �������, ��� � ����� � ���� ���� ������ ����. ���� ��� ������, �� � ����� ��� ����������, � ������ � ������� ���� �����. ��� �� ���?                                                                                                                                         "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD3), SW_HIDE);
            CreateWindow(TEXT("BUTTON"), TEXT("����, � ��� � �����-�� ��������..."), WS_VISIBLE | WS_CHILD, 150, 155, 300, 35, hWnd, (HMENU)MOTHER, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("����, � ��� ������!!!"), WS_VISIBLE | WS_CHILD, 150, 200, 300, 35, hWnd, (HMENU)EDU, NULL, NULL);
        }
        if (LOWORD(wParam) == EDU)
        {
            CreateWindow(TEXT("STATIC"), TEXT("�� ������ ������� ���� ��� �����, ����� ������� ����������. �� ������� ������ �������� �� ��������, ��������� �� ��� � �������                        ���������, ������ � ��������.                                                                                 ���� �����?"), WS_VISIBLE | WS_CHILD, 100, 10, 480, 108, hWnd, (HMENU)text1, NULL, NULL);
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

 


                CreateWindow(TEXT("BUTTON"), TEXT("����� � ���������"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)VELOSIPED, NULL, NULL);
                CreateWindow(TEXT("BUTTON"), TEXT("����� � ������"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)MASHINA, NULL, NULL);
                CreateWindow(TEXT("BUTTON"), TEXT("����� � �������� "), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)HELICOPTER, NULL, NULL);
            



        }
        if (LOWORD(wParam) == SECOND3)
        {
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FIRST3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SECOND3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, THIRD3), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("������� ������������ ������ ��� ��������. �� ��� �� ������, ������ ��� � ��� �� ������� �����. � ����������� ������� ��� ������� ������������� �����."), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)text1, NULL, NULL);
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
            CreateWindow(TEXT("STATIC"), TEXT("<<����� �� �� ��������� �������� � �������! ���� � ���� ��������� ����! ��� ��� ������ ����, ����� ����� �� ���� ������. ��, ������ ���� ���������! ������ ��� � ������? ���� � ���� ��� ����� ������!>> - ��� ��� ������ ������� ����. ����� ������� ����������. ������ ������: �� ����� � ������ �������� ����� �����, ����� �� ��������� ������� �� �������� =( "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 480, hWnd, (HMENU)text1, NULL, NULL);
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
            CreateWindow(TEXT("STATIC"), TEXT("������� �����-�� 5 ����� � �� ������ ���� ���� ������� � ����, �� ������� �������. ����� ���� =). ������: �� ������� ���� ����� �������. ����������� ��� ������, �� � ����. ����� �����, ��� � ������."), WS_VISIBLE | WS_CHILD, 100, 10, 450, 480, hWnd, (HMENU)NULL, NULL, NULL);
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

              // �� �������� ������ ������. ������ ���� ����� �� �������� � ��������... � � �������... � ��� ����� ����...
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
                //���, ������, , � ��� ��������� ����� �� ���� ��������, �� ����� �����.�� � ��� �������, ��� ����� ������ ���� �������� � � ��������� ������������.���� �� � ������ ����������
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


    CreateWindowEx(WS_EX_LAYERED,op.lpszClassName, "�������� �����", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE, 100, 100, 640, 360, NULL, NULL, op.hInstance, NULL);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }

}
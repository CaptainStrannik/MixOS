//#include <windows.h>
//#include <cstring>
//#include <cstdlib>
//#include <cstdio>
//#include <tchar.h>
//#include <wchar.h>
//#include "resource.h"
//#include"targetver.h"
//#include "framework.h"
//#include "targetver.h"
//#include <conio.h>
//#include <shlobj.h>
//#include <ks.h>     
//#include <string>    
//#include<mciapi.h>                 
//#include<Mmsystem.h>
//#include "Names.h"
//#include "bass.h"  
//#include "LoveInQuest.h"
//#include "names2.h"
//#define STRANNI 90     
//#pragma comment (lib, "urlmon.lib")
//#pragma comment(lib, "winmm.lib")
//#pragma comment(lib, "bass")
//#pragma comment(linker,"/manifestdependency:\"type='win32' \
//                        name='Microsoft.Windows.Common-Controls' \
//                        version='6.0.0.0' processorArchitecture='*'\
// publicKeyToken='6595b64144ccf1df' language='*'\"")
//
//int len;
//TCHAR StrB[1200];
//
//
//using namespace std;
//char str1[1024];
//HSTREAM QUEST_THEME;
//
//HICON progicon;
//int skins;
//TCHAR StrT[MAX_PATH];
//HANDLE bmpwall;
//HANDLE bmpwall1;
//HWND hwall;
//static COLORREF acrCustClr[16];
//HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 204));
//static DWORD rgbCurrent = RGB(0, 0, 204);
//HWND hTrack;
//HDC hdc;
//PAINTSTRUCT ps;
//const TCHAR progname[] = _T("Urban Assault �������");
//HWND tardis;
////bool key_pressed = false;
//HINSTANCE hInst;
//HSTREAM UASSAULT;
//HSTREAM ABOUT;
//HWND LOVE;
//HWND LOVE1;
//HWND LOVE2;
//HWND LOVE3;
//HWND LOVE4;
//
//static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//    switch (uMsg) {
//
//    case WM_CREATE: {
//
//
//
//
//        NOTIFYICONDATA data;
//        ZeroMemory(&data, sizeof(NOTIFYICONDATA));
//
//
//        data.cbSize = sizeof(data);
//        data.hWnd = hWnd;
//        data.uID = 1;          // ����� ��������� ����� �������������, �� ����� ������ ������ ����
//        data.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
//        data.uCallbackMessage = WM_USER_SHELLICON;
//        data.hIcon = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\ghor.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        data.uVersion = NOTIFYICON_VERSION;
//
//        /*     strcpy(data.szInfoTitle, "��������� ����� � Youtube");*/
//        strcpy(data.szTip, "�������� �����");
//
//
//        Shell_NotifyIcon(NIM_ADD, &data);
//
//
//
//        HMENU hMenubar = CreateMenu();
//        HMENU hAbout = CreateMenu();
//        HMENU hOptions = CreateMenu();
//        HMENU hMods = CreateMenu();
//
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "�������");
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hOptions, "���������");
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hMods, "�����������");
//
//
//
//        SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//        AppendMenu(hAbout, MF_STRING, STRANNIK, "� ���������");
//
//
//        AppendMenu(hOptions, MF_STRING, MYCOLOR, "������� ����");
//        AppendMenu(hOptions, MF_SEPARATOR,MYCOLOR,0);
//        AppendMenu(hOptions, MF_STRING, CHANGEMUSIC, "������� ������");
//        AppendMenu(hOptions, MF_SEPARATOR, MYCOLOR, 0);
//        AppendMenu(hOptions, MF_STRING, UAKILL, "������� UA");
//
//        AppendMenu(hMods, MF_STRING, UADOMDOM, "UA DOMINATION");
//
//
//        SetMenu(hWnd, hMenubar);
//        BASS_Init(-1, 44100, 0, 0, 0);
//        BASS_ChannelSetAttribute(UASSAULT, BASS_ATTRIB_VOL, 0.2F);
//
//        HINSTANCE hInst = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);
//        HICON hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\MixOS.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//
//        CreateWindow(TEXT("STATIC"), TEXT("����� ������ ���� ������� ���������?"), WS_VISIBLE | WS_CHILD, 200, 30, 280, 20, hWnd, (HMENU)text1, NULL, NULL);
//
//
//        CreateWindow(TEXT("BUTTON"), TEXT("Urban Assault Original"), WS_VISIBLE | WS_CHILD, 170, 100, 300, 20, hWnd, (HMENU)UAORIG, NULL, NULL);
//        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\UA.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        SendMessage(GetDlgItem(hWnd, UAORIG), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);
//
//
//
//        CreateWindow(TEXT("BUTTON"), TEXT("Urban Assault Metropolis Dawn Ghor"), WS_VISIBLE | WS_CHILD, 170, 130, 300, 20, hWnd, (HMENU)UAMETROGHOR, NULL, NULL);
//        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\ghor.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        SendMessage(GetDlgItem(hWnd, UAMETROGHOR), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);
//
//
//        CreateWindow(TEXT("BUTTON"), TEXT("Urban Assault Metropolis Dawn Taer"), WS_VISIBLE | WS_CHILD, 170, 160, 300, 20, hWnd, (HMENU)UAMETROTAER, NULL, NULL);
//        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Taer.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        SendMessage(GetDlgItem(hWnd, UAMETROTAER), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);
//
//
//
//        CreateWindow(TEXT("BUTTON"), TEXT("Urban Assault Ghor Campaign"), WS_VISIBLE | WS_CHILD, 170, 190, 300, 20, hWnd, (HMENU)UAORIGGHOR, NULL, NULL);
//        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\UA.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        SendMessage(GetDlgItem(hWnd, UAORIGGHOR), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);
//
//        CreateWindow(TEXT("BUTTON"), TEXT("���� ����������"), WS_VISIBLE | WS_CHILD, 170, 220, 300, 60, hWnd, (HMENU)UASEENENEMY, NULL, NULL);
//        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\UA.ico", IMAGE_ICON, 64, 64, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        SendMessage(GetDlgItem(hWnd, UASEENENEMY), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);
//
//        CreateWindow(TEXT("BUTTON"), TEXT(" "), WS_VISIBLE | WS_CHILD, 480, 100, 150, 150, hWnd, (HMENU)UASEENENEMY1, NULL, NULL);
//        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\ghor.ico", IMAGE_ICON, 132, 128, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        SendMessage(GetDlgItem(hWnd, UASEENENEMY1), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);
//
//        CreateWindow(TEXT("BUTTON"), TEXT(" "), WS_VISIBLE | WS_CHILD, 480, 100, 150, 150, hWnd, (HMENU)UASEENENEMY2, NULL, NULL);
//        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\taer.ico", IMAGE_ICON, 132, 128, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        SendMessage(GetDlgItem(hWnd, UASEENENEMY2), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);
//
//        CreateWindow(TEXT("BUTTON"), TEXT(" "), WS_VISIBLE | WS_CHILD, 480, 100, 150, 150, hWnd, (HMENU)UASEENENEMY3, NULL, NULL);
//        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\UA.ico", IMAGE_ICON, 132, 128, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        SendMessage(GetDlgItem(hWnd, UASEENENEMY3), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);
//
//        ShowWindow(GetDlgItem(hWnd, UASEENENEMY), SW_HIDE);
//        ShowWindow(GetDlgItem(hWnd, UASEENENEMY2), SW_HIDE);
//        ShowWindow(GetDlgItem(hWnd, UASEENENEMY3), SW_HIDE);
//            BASS_Stop();
//            BASS_Start();
//            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\UA.mp3", 0, 0, 0);
//            BASS_ChannelPlay(UASSAULT, false);
//            
//            CreateWindow(TEXT("BUTTON"), TEXT("1"), WS_VISIBLE | WS_CHILD, 30, 100, 30, 30, hWnd, (HMENU)MUA1, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("2"), WS_VISIBLE | WS_CHILD, 70, 100, 30, 30, hWnd, (HMENU)MUA2, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("3"), WS_VISIBLE | WS_CHILD, 110, 100, 30, 30, hWnd, (HMENU)MUA3, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("4"), WS_VISIBLE | WS_CHILD, 30, 140, 30, 30, hWnd, (HMENU)MUA4, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("5"), WS_VISIBLE | WS_CHILD, 70, 140, 30, 30, hWnd, (HMENU)MUA5, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("6"), WS_VISIBLE | WS_CHILD, 110, 140, 30, 30, hWnd, (HMENU)MUA6, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("8"), WS_VISIBLE | WS_CHILD, 70, 180, 30, 30, hWnd, (HMENU)MUA8, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("9"), WS_VISIBLE | WS_CHILD, 110, 180, 30, 30, hWnd, (HMENU)MUA9, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("7"), WS_VISIBLE | WS_CHILD, 30, 180, 30, 30, hWnd, (HMENU)MUA7, NULL, NULL);
//            
//            CreateWindow(TEXT("BUTTON"), TEXT("���������"), WS_VISIBLE | WS_CHILD, 30, 220, 110, 30, hWnd, (HMENU)STOPSOUNDUA, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("��������"), WS_VISIBLE | WS_CHILD, 30, 220, 110, 30, hWnd, (HMENU)PLAYSOUNDUA, NULL, NULL);
//
//
//
//            ShowWindow(GetDlgItem(hWnd, MUA1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MUA2), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MUA3), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MUA4), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MUA5), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MUA6), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MUA7), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MUA8), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MUA9), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, STOPSOUNDUA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, PLAYSOUNDUA), SW_HIDE);
//
//            ShowWindow(GetDlgItem(hWnd, UASEENENEMY1), SW_HIDE);
//        break;
//
//
//    }
//    case WM_COMMAND: {
//
//        //ShowWindow(GetDlgItem(hWnd, LENMUSIC), SW_SHOW);
//
//
//
//
//
//        //if (LOWORD(wParam) == QUESTION2)
//        //{
//        //    if (StrB == "��")
//        //    {
//        //        MessageBoxA(hWnd, "�� ��������� �� ����� ������.\n", "������ �������� 2", MB_ICONINFORMATION);
//        //        CreateWindow(TEXT("STATIC"), TEXT("���� �������? ��/���?"), WS_VISIBLE | WS_CHILD, 150 + 50 + 5 + 60, 50, 180, 20, hWnd, (HMENU)text1, NULL, NULL);
//        //        len = GetWindowText(LOVE, StrB, 1200);
//        //        CreateWindow(TEXT("BUTTON"), TEXT("�������"), WS_VISIBLE | WS_CHILD, 220, 180, 150, 30, hWnd, (HMENU)QUESTION2, NULL, NULL);
//        //    }
//        //    if (StrB == "���")
//        //    {
//        //        CreateWindow(TEXT("STATIC"), TEXT("���� �������? ��/���?"), WS_VISIBLE | WS_CHILD, 150 + 50 + 5 + 60, 50, 180, 20, hWnd, (HMENU)text1, NULL, NULL);
//        //        len = GetWindowText(LOVE, StrB, 1200);
//        //        CreateWindow(TEXT("BUTTON"), TEXT("�������"), WS_VISIBLE | WS_CHILD, 220, 180, 150, 30, hWnd, (HMENU)QUESTION2, NULL, NULL);
//
//
//        //    }
//
//
//      /*  }*/
//
//        if (LOWORD(wParam) == UAKILL)
//        {
//            system("start MusicPlayer\\UA\\DELUA.bat");
//        }
//        if (LOWORD(wParam) == UASEENENEMY1)
//        {
//            BASS_StreamFree(ABOUT);
//            BASS_Start();
//            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\17331.WAV", 0, 0, 0);
//            BASS_ChannelPlay(ABOUT, false);
//            ShowWindow(GetDlgItem(hWnd, UASEENENEMY1), SW_HIDE);
//        }
//        if (LOWORD(wParam) == UASEENENEMY2)
//        {
//            BASS_StreamFree(ABOUT);
//            BASS_Start();
//            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\17331.WAV", 0, 0, 0);
//            BASS_ChannelPlay(ABOUT, false);
//            ShowWindow(GetDlgItem(hWnd, UASEENENEMY2), SW_HIDE);
//        }
//        if (LOWORD(wParam) == UASEENENEMY3)
//        {
//            BASS_StreamFree(ABOUT);
//            BASS_Start();
//            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\21211.WAV", 0, 0, 0);
//            BASS_ChannelPlay(ABOUT, false);
//            ShowWindow(GetDlgItem(hWnd, UASEENENEMY3), SW_HIDE);
//        }
//        if (LOWORD(wParam) == STRANNIK)
//        {
//            BASS_StreamFree(ABOUT);
//            BASS_Start();  
//            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1A121.WAV", 0, 0, 0); 
//            
//            BASS_ChannelPlay(ABOUT, false);
//            ShellAbout(hWnd, progname, "�����������: Captain Strannik", progicon);
//
//            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1A231.WAV", 0, 0, 0);
//            BASS_ChannelPlay(ABOUT, false);
//        }
//        if (LOWORD(wParam) == UASEENENEMY)
//        {
//            
//            BASS_Start();
//            BASS_StreamFree(ABOUT);
//            
//            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\11221.WAV", 0, 0, 0);
//            BASS_ChannelPlay(ABOUT, false);
//
//        }
//        if (LOWORD(wParam) == UAORIG)
//        {
// UAORIGINAL:
//
//
//            WIN32_FIND_DATA EXAMPLE;
//            HANDLE hFind = FindFirstFile("MusicPlayer\\UA\\UAORIG\\UA.mixos", &EXAMPLE);
//            if (INVALID_HANDLE_VALUE != hFind)
//            {
//                BASS_ChannelStop(UASSAULT);
//                system("MusicPlayer\\UA\\StartOrig.bat");
//
//
//            }
//            else
//            {
//                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1A141.WAV", 0, 0, 0);
//                BASS_ChannelPlay(UASSAULT, false);
//                MessageBox(hWnd, "������ ��������� ����� ��������� ����� ����\n�� ��� ���� ����� � ��������� ����� ��������� ��������\n������� �� ��������� ��������� � ����������!!!\n����������� ������� ������ ��������, �� �� �����.\n����� ����������, ����� ��� ��������)", "��������", MB_OK | MB_ICONASTERISK);
//                URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UA/UAORIG.zip", "MusicPlayer\\UAORIG.zip", 0, 0);
//                /*URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UA/UA.mixos", "MusicPlayer\\UA\\UAORIG", 0, 0);*/
//
//                system("MusicPlayer\\UA.bat");
//                WIN32_FIND_DATA EXAMPLE;
//                HANDLE hFind = FindFirstFile("MusicPlayer\\UA\\UAORIG\\UA.mixos", &EXAMPLE);
//                if (INVALID_HANDLE_VALUE != hFind)
//                {
//                    UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\11221.WAV", 0, 0, 0);
//                    BASS_ChannelPlay(UASSAULT, false);
//
//                    MessageBoxA(hWnd, "Urban Assault ������� �����������\n������ � ������������ Metropolis Dawn\n������� �� ��������!", "�������!!!", MB_ICONINFORMATION);
//
//
//                }
//                if (INVALID_HANDLE_VALUE == hFind)
//                {
//                    UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\10.mp3", 0, 0, 0);
//                    BASS_ChannelPlay(UASSAULT, false);
//                    if (MessageBox(hWnd, "�� ������������, �������� �������� � ����������\n����������� ��� ���?", "�������  =(", MB_YESNO | MB_ICONQUESTION == IDYES))
//                    {
//                        goto UAORIGINAL;
//                    }
//                    else
//                    {
//                        return 0;
//                    };
//
//                }
//
//            };
//         
//
//
//            return false;
//            FindClose(hFind);
//        }
//        if (LOWORD(wParam) == UAORIGGHOR)
//        {
//        UAORIGINALRED:
//
//
//            WIN32_FIND_DATA EXAMPLE;
//            HANDLE hFind = FindFirstFile("MusicPlayer\\UA\\UAORIGGHOR\\UA.mixos", &EXAMPLE);
//            if (INVALID_HANDLE_VALUE != hFind)
//            {
//                BASS_ChannelStop(UASSAULT);
//                system("MusicPlayer\\UA\\StartOrigGhor.bat");
//
//
//            }
//            else
//            {
//                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1A141.WAV", 0, 0, 0);
//                BASS_ChannelPlay(UASSAULT, false);
//                MessageBox(hWnd, "������ ��������� ����� ��������� ����� ����\n�� ��� ���� ����� � ��������� ����� ��������� ��������\n������� �� ��������� ��������� � ����������!!!\n����������� ������� ������ ��������, �� �� �����.\n����� ����������, ����� ��� ��������)", "��������", MB_OK | MB_ICONASTERISK);
//                URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UA/UAORIGGHOR.zip", "MusicPlayer\\UAORIGGHOR.zip", 0, 0);
//                /*URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UA/UA.mixos", "MusicPlayer\\UA\\UAORIG", 0, 0);*/
//
//                system("MusicPlayer\\UA1.bat");
//                WIN32_FIND_DATA EXAMPLE;
//                HANDLE hFind = FindFirstFile("MusicPlayer\\UA\\UAORIGGHOR\\UA.mixos", &EXAMPLE);
//                if (INVALID_HANDLE_VALUE != hFind)
//                {
//                    UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\11221.WAV", 0, 0, 0);
//                    BASS_ChannelPlay(UASSAULT, false);
//
//                    MessageBoxA(hWnd, "��� ��� �� Urban Assault (HARD RED MODE) ������� ����������!\n������� �� ��������!", "�������!!!", MB_ICONINFORMATION);
//
//
//                }
//                if (INVALID_HANDLE_VALUE == hFind)
//                {
//                    UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\10.mp3", 0, 0, 0);
//                    BASS_ChannelPlay(UASSAULT, false);
//                    if (MessageBox(hWnd, "�� ������������, �������� �������� � ����������\n����������� ��� ���?", "�������  =(", MB_YESNO | MB_ICONQUESTION == IDYES))
//                    {
//                        goto UAORIGINALRED;
//                    }
//                    else
//                    {
//                        return 0;
//                    };
//
//                }
//
//            };
//
//
//            return false;
//            FindClose(hFind);
//        }
//        if (LOWORD(wParam) == UAMETROGHOR)
//        {
//            
//            
//   UAORIGINALGHOR:
//
//
//            WIN32_FIND_DATA EXAMPLE;
//            HANDLE hFind = FindFirstFile("MusicPlayer\\UA\\UAORIG\\UA.mixos", &EXAMPLE);
//            if (INVALID_HANDLE_VALUE != hFind)
//            {
//                BASS_ChannelStop(UASSAULT);
//                system("MusicPlayer\\UA\\StartMetroGhor.bat");
//
//
//            }
//            else
//            {
//                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1A141.WAV", 0, 0, 0);
//                BASS_ChannelPlay(UASSAULT, false);
//                MessageBox(hWnd, "������ ��������� ����� ��������� ����� ����\n�� ��� ���� ����� � ��������� ����� ��������� ��������\n������� �� ��������� ��������� � ����������!!!\n����������� ������� ������ ��������, �� �� �����.\n����� ����������, ����� ��� ��������)", "��������", MB_OK | MB_ICONASTERISK);
//                URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UA/UAORIG.zip", "MusicPlayer\\UAORIG.zip", 0, 0);
//                /*URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UA/UA.mixos", "MusicPlayer\\UA\\UAORIG", 0, 0);*/
//
//                system("MusicPlayer\\UA.bat");
//                WIN32_FIND_DATA EXAMPLE;
//                HANDLE hFind = FindFirstFile("MusicPlayer\\UA\\UAORIG\\UA.mixos", &EXAMPLE);
//                if (INVALID_HANDLE_VALUE != hFind)
//                {
//                    UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\11221.WAV", 0, 0, 0);
//                    BASS_ChannelPlay(UASSAULT, false);
//
//                    MessageBoxA(hWnd, "Urban Assault ������� �����������\n������ � ������������ Metropolis Dawn\n������� �� ��������!", "�������!!!", MB_ICONINFORMATION);
//
//
//                }
//                if (INVALID_HANDLE_VALUE == hFind)
//                {
//                    UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\10.mp3", 0, 0, 0);
//                    BASS_ChannelPlay(UASSAULT, false);
//                    if (MessageBox(hWnd, "�� ������������, �������� �������� � ����������\n����������� ��� ���?", "�������  =(", MB_YESNO | MB_ICONQUESTION == IDYES))
//                    {
//                        goto UAORIGINALGHOR;
//                    }
//                    else
//                    {
//                        return 0;
//                    };
//
//                }
//
//            };
//
//
//
//            return false;
//            FindClose(hFind);
//
//
//        }
//        if (LOWORD(wParam) == UAMETROTAER)
//        {
//
//        UAORIGINALTAER:
//
//
//            WIN32_FIND_DATA EXAMPLE;
//            HANDLE hFind = FindFirstFile("MusicPlayer\\UA\\UAORIG\\UA.mixos", &EXAMPLE);
//            if (INVALID_HANDLE_VALUE != hFind)
//            {
//                BASS_ChannelStop(UASSAULT);
//                system("MusicPlayer\\UA\\StartMetroTaer.bat");
//
//
//            }
//            else
//            {
//                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1A141.WAV", 0, 0, 0);
//                BASS_ChannelPlay(UASSAULT, false);
//                MessageBox(hWnd, "������ ��������� ����� ��������� ����� ����\n�� ��� ���� ����� � ��������� ����� ��������� ��������\n������� �� ��������� ��������� � ����������!!!\n����������� ������� ������ ��������, �� �� �����.\n����� ����������, ����� ��� ��������)", "��������", MB_OK | MB_ICONASTERISK);
//                URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UA/UAORIG.zip", "MusicPlayer\\UAORIG.zip", 0, 0);
//                URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UA/UA.mixos", "MusicPlayer\\UA\\UAORIG", 0, 0);
//
//                system("MusicPlayer\\UA.bat");
//                WIN32_FIND_DATA EXAMPLE;
//                HANDLE hFind = FindFirstFile("MusicPlayer\\UA\\ORIG\\UA.mixos", &EXAMPLE);
//                if (INVALID_HANDLE_VALUE != hFind)
//                {
//                    UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\11221.WAV", 0, 0, 0);
//                    BASS_ChannelPlay(UASSAULT, false);
//
//                    MessageBoxA(hWnd, "Urban Assault ������� �����������\n������ � ������������ Metropolis Dawn\n������� �� ��������!", "�������!!!", MB_ICONINFORMATION);
//
//
//                }
//                if (INVALID_HANDLE_VALUE == hFind)
//                {
//                    UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\10.mp3", 0, 0, 0);
//                    BASS_ChannelPlay(UASSAULT, false);
//                    if (MessageBox(hWnd, "�� ������������, �������� �������� � ����������\n����������� ��� ���?", "�������  =(", MB_YESNO | MB_ICONQUESTION == IDYES))
//                    {
//                        goto UAORIGINALTAER;
//                    }
//                    else
//                    {
//                        return 0;
//                    };
//
//                }
//
//
//            }
//
//
//            return false;
//            FindClose(hFind);
//
//
//        }
//
//
//
//        if (LOWORD(wParam) == UADOMDOM)
//        {
//
//        UADOM:
//
//
//            WIN32_FIND_DATA EXAMPLE;
//            HANDLE hFind = FindFirstFile("MusicPlayer\\UA\\UADOM\\UA.mixos", &EXAMPLE);
//            if (INVALID_HANDLE_VALUE != hFind)
//            {
//                BASS_ChannelStop(UASSAULT);
//
//                system("MusicPlayer\\UA\\StartDOM.bat");
//
//
//            }
//            else
//            {
//                UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1A141.WAV", 0, 0, 0);
//                BASS_ChannelPlay(UASSAULT, false);
//                MessageBox(hWnd, "������ ��������� ����� ��������� ����� ����\n�� ��� ���� ����� � ��������� ����� ��������� ��������\n������� �� ��������� ��������� � ����������!!!\n����������� ������� ������ ��������, �� �� �����.\n����� ����������, ����� ��� ��������)", "��������", MB_OK | MB_ICONASTERISK);
//                URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UA/MODS/UADOM/UADOM.zip", "MusicPlayer\\UAORIG.zip", 0, 0);
//                system("MusicPlayer\\UA.bat");
//                WIN32_FIND_DATA EXAMPLE;
//                HANDLE hFind = FindFirstFile("MusicPlayer\\UA\\UADOM\\UA.mixos", &EXAMPLE);
//                if (INVALID_HANDLE_VALUE != hFind)
//                {
//                    UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\11221.WAV", 0, 0, 0);
//                    BASS_ChannelPlay(UASSAULT, false);
//
//                    MessageBoxA(hWnd, "��� UA DOMINATION ������� ����������\n������� �� ��������!", "�������!!!", MB_ICONINFORMATION);
//
//
//                }
//                if (INVALID_HANDLE_VALUE == hFind)
//                {
//                    UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\10.mp3", 0, 0, 0);
//                    BASS_ChannelPlay(UASSAULT, false);
//                    if (MessageBox(hWnd, "�� ������������, �������� �������� � ����������\n����������� ��� ���?", "�������  =(", MB_YESNO | MB_ICONQUESTION == IDYES))
//                    {
//                        goto UADOM;
//                    }
//                    else
//                    {
//                        return 0;
//                    };
//
//                }
//
//
//            }
//
//
//            return false;
//            FindClose(hFind);
//
//
//        }
//
//
//
//        if (LOWORD(wParam) == CHANGEMUSIC)
//        {
//
//            CreateWindow(TEXT("STATIC"), TEXT("������"), WS_VISIBLE | WS_CHILD, 60, 80, 60, 20, hWnd, (HMENU)text1, NULL, NULL);
//
//            ShowWindow(GetDlgItem(hWnd, MUA1), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, MUA2), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, MUA3), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, MUA4), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, MUA5), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, MUA6), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, MUA7), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, MUA8), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, MUA9), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, text1), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, STOPSOUNDUA), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, PLAYSOUNDUA), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, UASEENENEMY1), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, UASEENENEMY), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, PLAYSOUNDUA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, STOPSOUNDUA), SW_SHOW);
//            BASS_Start();
//            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1A132.WAV", 0, 0, 0);
//            BASS_ChannelPlay(ABOUT, false);
//        }
//        if (LOWORD(wParam) == STOPSOUNDUA)
//        {
//            BASS_MusicFree(UASSAULT);
//            BASS_StreamFree(UASSAULT);
//            BASS_Stop();
//            BASS_Start();
//            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1A141.WAV", 0, 0, 0);
//            BASS_ChannelPlay(ABOUT, false);
//            ShowWindow(GetDlgItem(hWnd, PLAYSOUNDUA), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, STOPSOUNDUA), SW_HIDE);
//
//            ShowWindow(GetDlgItem(hWnd, MUA1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MUA2), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MUA3), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MUA4), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MUA5), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MUA6), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MUA7), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MUA8), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MUA9), SW_HIDE);
//        }
//        if (LOWORD(wParam) == PLAYSOUNDUA)
//        {
//            BASS_MusicFree(UASSAULT);
//            BASS_StreamFree(UASSAULT);
//            BASS_Stop();
//            BASS_Start();
//            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\UA.mp3", 0, 0, 0);
//            BASS_ChannelPlay(UASSAULT, false);
//            ShowWindow(GetDlgItem(hWnd, PLAYSOUNDUA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, STOPSOUNDUA), SW_SHOW);
//
//            ShowWindow(GetDlgItem(hWnd, MUA1), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, MUA2), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, MUA3), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, MUA4), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, MUA5), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, MUA6), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, MUA7), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, MUA8), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, MUA9), SW_SHOW);
//        }
//        if (LOWORD(wParam)==MUA1)
//        { 
//        BASS_MusicFree(UASSAULT);
//        BASS_StreamFree(UASSAULT);
//        BASS_StreamFree(ABOUT);
//        BASS_Stop();
//        BASS_Start();
//        ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1A231.WAV", 0, 0, 0);
//        BASS_ChannelPlay(ABOUT, false);
//        UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\UA\\UAORIG\\music\\2.ogg", 0, 0, 0);
//        BASS_ChannelPlay(UASSAULT, false);
//        ShowWindow(GetDlgItem(hWnd, UASEENENEMY1), SW_SHOW);
//        }
//        if (LOWORD(wParam) == MUA2)
//        {
//            BASS_MusicFree(UASSAULT);
//            BASS_StreamFree(UASSAULT);
//            BASS_StreamFree(ABOUT);
//            BASS_Stop();
//            BASS_Start();
//            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\UA\\UAORIG\\music\\3.ogg", 0, 0, 0);
//            BASS_ChannelPlay(UASSAULT, false);
//        }
//        if (LOWORD(wParam) == MUA3)
//        {
//            BASS_MusicFree(UASSAULT);
//            BASS_StreamFree(UASSAULT);
//            BASS_StreamFree(ABOUT);
//            BASS_Stop();
//            BASS_Start();
//            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\UA\\UAORIG\\music\\4.ogg", 0, 0, 0);
//            BASS_ChannelPlay(UASSAULT, false);
//        }
//        if (LOWORD(wParam) == MUA4)
//        {
//            BASS_MusicFree(UASSAULT);
//            BASS_StreamFree(UASSAULT);
//            BASS_StreamFree(ABOUT);
//            BASS_Stop();
//            BASS_Start();
//            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\UA\\UAORIG\\music\\5.ogg", 0, 0, 0);
//            BASS_ChannelPlay(UASSAULT, false);
//        }
//        if (LOWORD(wParam) == MUA5)
//        {
//            BASS_MusicFree(UASSAULT);
//            BASS_StreamFree(UASSAULT);
//            BASS_StreamFree(ABOUT);
//            BASS_Stop();
//            BASS_Start();
//            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\UA\\UAORIG\\music\\6.ogg", 0, 0, 0);
//            BASS_ChannelPlay(UASSAULT, false);
//            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1A231.WAV", 0, 0, 0);
//            BASS_ChannelPlay(ABOUT, false);
//            ShowWindow(GetDlgItem(hWnd, UASEENENEMY2), SW_SHOW);
//        }
//        if (LOWORD(wParam) == MUA6)
//        {
//            BASS_MusicFree(UASSAULT);
//            BASS_StreamFree(UASSAULT);
//            BASS_StreamFree(ABOUT);
//            BASS_Stop();
//            BASS_Start();
//            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\UA\\UAORIG\\music\\7.ogg", 0, 0, 0);
//            BASS_ChannelPlay(UASSAULT, false);
//        }
//        if (LOWORD(wParam) == MUA7)
//        {
//            BASS_MusicFree(UASSAULT);
//            BASS_StreamFree(UASSAULT);
//            BASS_StreamFree(ABOUT);
//            BASS_Stop();
//            BASS_Start();
//            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\UA\\UAORIG\\music\\9.ogg", 0, 0, 0);
//            BASS_ChannelPlay(UASSAULT, false);
//        }
//        if (LOWORD(wParam) == MUA8)
//        {
//            BASS_MusicFree(UASSAULT);
//            BASS_StreamFree(UASSAULT);
//            BASS_StreamFree(ABOUT);
//            BASS_Stop();
//            BASS_Start();
//            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\UA\\UAORIG\\music\\10.ogg", 0, 0, 0);
//            BASS_ChannelPlay(UASSAULT, false);
//            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\UA\\UAORIG\\music\\1A231.WAV", 0, 0, 0);
//            BASS_ChannelPlay(ABOUT, false);
//            ShowWindow(GetDlgItem(hWnd, UASEENENEMY3), SW_SHOW);
//        }
//        if (LOWORD(wParam) == MUA9)
//        {
//            BASS_MusicFree(UASSAULT);
//            BASS_StreamFree(UASSAULT);
//            BASS_StreamFree(ABOUT);
//            BASS_Stop();
//            BASS_Start();
//            UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\UA\\UAORIG\\music\\11.ogg", 0, 0, 0);
//            BASS_ChannelPlay(UASSAULT, false);
//        }
//
//        if (LOWORD(wParam) == MYCOLOR)
//        {
//            BASS_Start();
//            BASS_StreamFree(ABOUT);
//            
//            ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1B122.WAV", 0, 0, 0);
//            BASS_ChannelPlay(ABOUT, false);
//            CHOOSECOLOR cc;
//
//            ZeroMemory(&cc, sizeof(CHOOSECOLOR));
//            cc.lStructSize = sizeof(CHOOSECOLOR);
//            cc.hwndOwner = hWnd;
//            cc.lpCustColors = (LPDWORD)acrCustClr;
//            cc.rgbResult = rgbCurrent;
//            cc.Flags = CC_FULLOPEN | CC_RGBINIT;
//
//            if (ChooseColor(&cc) == TRUE) {
//                bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
//                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);
//
//                hBrush = CreateSolidBrush(cc.rgbResult);
//                rgbCurrent = cc.rgbResult;
//
//                BASS_Start();
//                BASS_StreamFree(ABOUT);
//
//                ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1B131.WAV", 0, 0, 0);
//                BASS_ChannelPlay(ABOUT, false);
//            }
//            else
//            {
//                BASS_Start();
//                BASS_StreamFree(ABOUT);
//
//                ABOUT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\1A141.WAV", 0, 0, 0);
//                BASS_ChannelPlay(ABOUT, false);
//                /*   bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
//                   SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);*/
//                hBrush = CreateSolidBrush(RGB(0, 0, 204));
//                rgbCurrent = RGB(0, 76, 153);
//                return 0;
//            };
//
//
//            InvalidateRect(hWnd, NULL, FALSE);
//
//              // �� �������� ������ ������. ������ ���� ����� �� �������� � ��������... � � �������... � ��� ����� ����...
//        }
//
//    case WM_HSCROLL:
//    {
//        if (hTrack == (HWND)lParam)
//        {
//            BASS_ChannelSetAttribute(QUEST_THEME, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 25, 75));
//        }
//    } break;
//
//
//    case WM_CTLCOLORSTATIC:
//    {
//        if (GetDlgCtrlID((HWND)lParam) == text1)
//        {
//            HDC hdcStatic = (HDC)wParam;
//            // or obtain the static handle in some other way
//            SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color
//
//            SetBkColor(hdcStatic, rgbCurrent);
//
//            return (LRESULT)GetStockObject(NULL_BRUSH);
//
//        }
//        if (GetDlgCtrlID((HWND)lParam) == LENMUSIC)
//        {
//            HDC hdcStatic = (HDC)wParam;
//            // or obtain the static handle in some other way
//            SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color
//
//            SetBkColor(hdcStatic, RGB(255,255,255));
//
//
//            return (LRESULT)(COLOR_WINDOW + 1);
//
//        }
//
//    }break;
//
//            case WM_PAINT: {
//                hdc = BeginPaint(hWnd, &ps);
//                //���, ������, , � ��� ��������� ����� �� ���� ��������, �� ����� �����.�� � ��� �������, ��� ����� ������ ���� �������� � � ��������� ������������.���� �� � ������ ����������
//                FillRect(hdc, &ps.rcPaint, hBrush);
//                /*SetBkMode(hdc, TRANSPARENT);*/
//
//                //BitBlt(hdc, 0, 0, bm., 720, memBit, 0, 0, SRCCOPY);
//
//                EndPaint(hWnd, &ps);
//                //return 0;
//
//            } break;
//
//    //case WM_KEYDOWN:
//    //    switch (lParam)
//    //    {
//    //        case VK_NUMPAD5:
//    //            if (key_pressed == false)
//    //            {
//    //                ShowWindow(tardis, SW_SHOW);
//    //                key_pressed = true;
//    //            }
//    //            else if (key_pressed == true)
//    //            {
//    //                ShowWindow(tardis, SW_HIDE);
//    //                key_pressed = false;
//    //            };
//    //            break;
//    //    }
//    //    break;
//
//    case WM_DESTROY: {
//        PostQuitMessage(0);
//        return 0;
//
//        break;
//
//    }
// 
//
//    default:
//        return DefWindowProc(hWnd, uMsg, wParam, lParam);
//    }
//                   return 0; 
//    }
//}
//
//int WINAPI main()
//{
// 
//    SetProcessDPIAware();
//    WNDCLASS op;
//    ZeroMemory(&op, sizeof(WNDCLASS));
//    op.lpfnWndProc = wnd_proc;
//    op.hInstance = GetModuleHandle(NULL);
//    op.lpszClassName = "test32cls";
//    op.hCursor = LoadCursor(NULL, IDC_ARROW);
//    progicon = (HICON)LoadImage(op.hInstance, "MusicPlayer\\BMP\\ico\\ghor.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//    op.hIcon = progicon;
//
//    //op.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
//    RegisterClass(&op);
//
//
//    CreateWindowA(op.lpszClassName, "Urban Assault �������", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE, (GetSystemMetrics(SM_CXSCREEN) - 1280) / 2,
//                (GetSystemMetrics(SM_CYSCREEN) - 720) / 2, 670, 360, NULL, NULL, op.hInstance, NULL);
//    MSG msg;
//    while (GetMessage(&msg, NULL, 0, 0)) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//
//    }
//
//}
#include <windows.h>
#include <cstring>
#include<iostream>
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
#include <fstream>
#include "bass.h"
#include <random>
#include <ctime>





HWND COM;
HSTREAM stroka;
HSTREAM CHASTUSHKI;
HSTREAM BONUS;
HSTREAM REMAX;
HSTREAM NYANCAT;
HSTREAM KILL;
HSTREAM IMPOTENT;
HSTREAM OXYENNA;
HSTREAM LIRIKAHOI;
HSTREAM LJSPQK;
HSTREAM AEZAKMI;
HSTREAM TITLED;
HSTREAM Z_KRAF1ER_Z;
HDC hdc;
HICON progicon;
static DWORD rgbCurrent = RGB(0, 153, 0);
HBRUSH hBrush = CreateSolidBrush(RGB(0, 153, 0));
PAINTSTRUCT ps;
HWND hwall;
HANDLE bmpwall;
HANDLE bmpwall1;
HWND eMp3;
int skins;
HINSTANCE hInst;
const TCHAR progname[] = _T("�������� �� MixOS");
TCHAR StrT[MAX_PATH];
char str1[MAX_PATH];
#pragma comment(linker,"/manifestdependency:\"type='win32' \
                        name='Microsoft.Windows.Common-Controls' \
                        version='6.0.0.0' processorArchitecture='*'\
 publicKeyToken='6595b64144ccf1df' language='*'\"")

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "bass")
using namespace std;
static COLORREF acrCustClr[16];


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
        data.hIcon = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\terminal.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        data.uVersion = NOTIFYICON_VERSION;

        /*     strcpy(data.szInfoTitle, "��������� ����� � Youtube");*/
        strcpy(data.szTip, "������� �� MixOS");


        Shell_NotifyIcon(NIM_ADD, &data);





        eMp3 = CreateWindow(TEXT("Edit"), NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD, 40, 430, 1175 - 30, 20, hWnd, (HMENU)YOUMUSIC, NULL, 0);
        ShowWindow(GetDlgItem(hWnd, YOUMUSIC), SW_HIDE);

        DeleteObject((HBRUSH)SetClassLongPtr(hWnd, GCLP_HBRBACKGROUND, (LONG_PTR)CreateSolidBrush(RGB(70, 125, 0))));
        COM = CreateWindow(TEXT("EDIT"), TEXT(""), WS_CHILD | WS_VISIBLE /*| WS_THICKFRAME |WS_CAPTION*/ | WS_VSCROLL | WS_HSCROLL | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE | ES_UPPERCASE, 10, 50, 350, 350, hWnd, (HMENU)WRITING, NULL, 0);
        CreateWindow(TEXT("STATIC"), TEXT("������� �������, ��� ��� ���-�� ��� =)."), WS_VISIBLE | WS_CHILD, 35, 15, 280, 25, hWnd, (HMENU)text1, NULL, NULL);


        HINSTANCE hInst = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);
        HICON hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\MixOS.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);


        int a = 120;

        HMENU hMenubar = CreateMenu();

        HMENU hAbout = CreateMenu();
        HMENU hColor = CreateMenu();

        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "�������");
        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hColor, "������� ����");
        BASS_Init(-1, 44100, 0, 0, NULL);


        SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));


        AppendMenu(hAbout, MF_STRING, STRANNIK, "� ���������");
        AppendMenu(hColor, MF_STRING, MYCOLOR, "���� ����");
        AppendMenu(hColor, MF_SEPARATOR, NULL, NULL);
        AppendMenu(hColor, MF_STRING, SKIN1, "�������� 1");
        AppendMenu(hColor, MF_STRING, SETBKG, "���� ����");
        AppendMenu(hColor, MF_SEPARATOR, NULL, NULL);
        AppendMenu(hColor, MF_STRING, polupon, "�������� ����������������");
        AppendMenu(hColor, MF_STRING, polupoff, "��������� ����������������");

        SetMenu(hWnd, hMenubar);

        CreateWindowA(TEXT("BUTTON"), TEXT("������ �������"), WS_VISIBLE | WS_CHILD, 400, 230, 150, 35, hWnd, (HMENU)COMMANDA, NULL, NULL);

        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\terminal.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, COMMANDA), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


        CreateWindowA(TEXT("BUTTON"), TEXT("������ ������"), WS_VISIBLE | WS_CHILD, 400, 130, 150, 35, hWnd, (HMENU)HELPAS, NULL, NULL);

        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\menumaker.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, HELPAS), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


        CreateWindowA(TEXT("BUTTON"), TEXT("�������� ����"), WS_VISIBLE | WS_CHILD, 10 + 160, 350 + 100, 150, 35, hWnd, (HMENU)GTX745, NULL, NULL);

        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\cheat.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, GTX745), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindowA(TEXT("BUTTON"), TEXT("Windows 3.11"), WS_VISIBLE | WS_CHILD, 10, 350 + 100, 150, 35, hWnd, (HMENU)WIN311, NULL, NULL);

        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\WIN95.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, WIN311), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


        break;
    }

    case WM_COMMAND:
    {


        int len5;
        TCHAR StrC[1200];
        len5 = GetWindowText(COM, StrC, 1200);




        if (LOWORD(wParam) == polupon)
        {

            SetLayeredWindowAttributes(hWnd, NULL, 230, LWA_ALPHA);
        }
        if (LOWORD(wParam) == polupoff)
        {

            SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);
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





        if (LOWORD(wParam) == SKIN1)

        {
            DestroyWindow(hwall);
            BASS_StreamFree(TITLED);
            BASS_Stop();
            BASS_Start();
            TITLED = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\white.mp3", 0, 0, 0);
            BASS_ChannelPlay(TITLED, false);




            bmpwall = LoadImage(NULL, "MusicPlayer\\BMP\\MIXTERMINAL\\Terminal1.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);

            if (bmpwall != NULL);
            {

                hwall = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall);

            }



        }
        if (LOWORD(wParam) == SKIN2)

        {
            DestroyWindow(hwall);
            BASS_StreamFree(TITLED);
            BASS_Stop();
            BASS_Start();
            bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            if (bmpwall != NULL);
            {
                hwall = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);
            }
        }
        if (LOWORD(wParam) == SKIN3)

        {
            DestroyWindow(hwall);
            BASS_StreamFree(TITLED);
            BASS_Stop();
            BASS_Start();
            TITLED = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\Kaer Morhen.mp3", 0, 0, 0);
            BASS_ChannelPlay(TITLED, false);




            bmpwall = LoadImage(NULL, "MusicPlayer\\BMP\\MIXTERMINAL\\800x600.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);

            if (bmpwall != NULL);
            {

                hwall = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall);

            }



        }


        if (LOWORD(wParam) == SETBKG)
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
            ofnn.lpstrInitialDir = "MusicPlayer\\BMP\\MIXTERMINAL";
            ofnn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_DONTADDTORECENT | OFN_NOCHANGEDIR;   //���� ������ ���!  � � ���� ������.

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
                /*CreateWindow(TEXT("BUTTON"), TEXT("����������"), WS_VISIBLE | WS_CHILD, 460, 500, 300, 70, hWnd, (HMENU)INSTBKG, NULL, NULL);*/
            }



        }




















        if (LOWORD(wParam) == STRANNIK)

        {
            ShellAbout(hWnd, progname, "�����������: Captain Strannik, ��������: Z_Kraf1er_Z", progicon);
            MessageBoxA(hWnd, "��� ���������-����������� ��������, ���������� � �����.\n����� �� ����� ��� ������� � ������ ��� ��������� ������������������� ����������� =)", "� ���������", MB_OK);
        }

        if (LOWORD(wParam) == HELPAS)
        {
            MessageBoxA(hWnd, "HELP - ����� ������ �������  \nINFO - ���������� � ���������  \nKILL - ��������������� ������ ������ �����  \nNYANCAT - ������������ ������ ������� ����.  \nSTOPMUSIC - ���������� ������.  \n�� ��������� ������ CON!!!  \n��������� ������� � �������, �� �� ����� 30 ���� =).", "������ �������", MB_OK);
            MessageBoxA(hWnd, "����� ������� ��� ����� ��� ��������.\n�� ���� �� �� ������ �������� � ���� ���������, �� ������� ������� ������� ��� tarkvara.\n� ������ mangima � ��� �����. ��� ���� ����� ��� ��� =). �� ������� ����, �� WINDOWS...", "������ 1", MB_OK);
        }
        if (LOWORD(wParam) == GTX745)
        {
            MessageBoxA(hWnd, "���� �������? � ���� ���� � GTA ��������� ������? ���, �� ���, ���� ��� ����, ����� ��� ��� �� 6 ����� �� GTA san andreas", "�����! ��!!!!", MB_OK);
            ShowWindow(GetDlgItem(hWnd, GTX745), SW_HIDE);
        }

        if (LOWORD(wParam) == WIN311)
        {
            MessageBoxA(hWnd, "�� ������ ��������� Windows 3.11? ����� �������� ������� ������� ����� =)", "� ���� �� �������?", MB_OK);
            ShowWindow(GetDlgItem(hWnd, WIN311), SW_HIDE);
        }



        if (LOWORD(wParam) == COMMANDA)
        {
            string text = StrC;

            if (text == "HELP")
            {
                MessageBoxA(hWnd, "HELP - ����� ������ �������  \nINFO - ���������� � ���������  \nKILL - ��������������� ������ ������ �����  \nNYANCAT - ������������ ������ ������� ����.  \nSTOPMUSIC - ���������� ������  \nCMD - ��������� ������ � ���������.  \nQUIT ��� EXIT - ������� ��������.  \n��������� ������� ����� ��������� �� ���� ����������� =).  \nBROWSER - ������� �������  \nP.S ������ ���������� ������ - STRANNIK.", "������ �������", MB_OK);
            }
            if (text == "INFO")
            {
                MessageBoxA(hWnd, "��� ��������. ����������� ��������. \n������� �������� � ����������� ������ ������ BETA 1.7.\n�, ������, ��� �������� �� �������. \n��� ������� �������, �������� ����������� ����. \n����� �������� ����� ���������� ����� �����, ���� � �� �������.", "���������� � ���������", MB_OK);

            }
            if (text == "KILL")
            {

                BASS_StreamFree(KILL);
                KILL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\kill.mp3", 0, 0, 0);


                BASS_ChannelPlay(KILL, false);

                if (LOWORD(wParam) == CLEARRAM)
                {
                    BASS_MusicFree(KILL);
                    BASS_StreamFree(KILL);
                }

            }
            if (text == "NYANCAT")
            {

                NYANCAT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\TERMINAL\\NYANCAT.mp3", 0, 0, 0);
                BASS_ChannelPlay(NYANCAT, false);

            }
            if (text == "CMD")
            {
                MessageBoxA(hWnd, "� ���, ������. ������ �������� �����? \n� ����� ������ ����������, ��� ��� ���������? \n��, ��� �� ������.", "�������?", MB_ICONERROR);
            }
            if (text == "POWERSHELL")
            {
                MessageBoxA(hWnd, "�� ������ ��� ��? �� �����. ������ ��������, � ����� ��� ���������� ����. � �������� ����� ������� POWERSHELL1", "��������� � ���������", MB_ICONERROR);
                BONUS = BASS_StreamCreateFile(FALSE, "MusicPlayer\\TERMINAL\\bonus.mp3", 0, 0, 0);
                BASS_ChannelPlay(BONUS, false);
            }
            if (text == "POWERSHELL1")
            {
                system("powershell");
            }
            if (text == "RD C: /S/Q")
            {
                BONUS = BASS_StreamCreateFile(FALSE, "MusicPlayer\\TERMINAL\\bonus.mp3", 0, 0, 0);
                BASS_ChannelPlay(BONUS, false);
                REMAX = BASS_StreamCreateFile(FALSE, "MusicPlayer\\TERMINAL\\REMAX.mp3", 0, 0, 0);
                BASS_ChannelPlay(REMAX, false);
                MessageBoxA(hWnd, "�������� ���� ��������� ������ - \nCMDCOLOR XX (������ ��, ����� �� 00, �� FF).  \nMLP - �������� My little pony.  \nBROWSER - ������� �������.  \n����� ������� �� ��, � ��� �� ����� ���� �����", "����� �������", MB_ICONASTERISK);
                system("start MusicPlayer\\TERMINAL\\RD.bat");
            }
            if (text == "STOPMUSIC")
            {
                BASS_ChannelFree(NYANCAT);
                BASS_ChannelFree(BONUS);
                BASS_ChannelFree(REMAX);
                BASS_ChannelFree(CHASTUSHKI);
                BASS_ChannelFree(Z_KRAF1ER_Z);
                BASS_StreamFree(NYANCAT);
                BASS_StreamFree(BONUS);
                BASS_StreamFree(REMAX);
                BASS_StreamFree(CHASTUSHKI);
                BASS_StreamFree(Z_KRAF1ER_Z);
                BASS_ChannelStop(CHASTUSHKI);
                BASS_ChannelStop(NYANCAT);
                BASS_ChannelStop(BONUS);
                BASS_ChannelStop(REMAX);
                BASS_ChannelStop(Z_KRAF1ER_Z);
                BASS_Stop();
                BASS_Start();
            }
            if (text == "MLP")
            {
                system("start https://www.youtube.com/watch?v=KDcdkNM0zh0&list=PLPiN9r5uRuh3ZuWfLw6HxmRAZCrNTV7Ts");
            }
            if (text == "BROWSER")
            {
                system("start https://yandex.ru");
            }





            if (text == "QUIT" || text == "EXIT")
            {
                PostQuitMessage(0);
                return 0;
            }
            if (text == "STRANNIK")
            {
                system("start https://www.youtube.com/channel/UCWlCZoSIqf7mm167pjwIJCw");
            }
            if (text == "QUEST")
            {
                system("start MusicPlayer\\Quest\\quest.exe");
            }





            if (text == "CMDCOLOR 00")
            {
                system("start color 00");
            }
            if (text == "CMDCOLOR 01")
            {
                system("start color 01");
            }
            if (text == "CMDCOLOR 02")
            {
                system("start color 02");
            }
            if (text == "CMDCOLOR 03")
            {
                system("start color 03");
            }
            if (text == "CMDCOLOR 04")
            {
                system("start color 04");
            }
            if (text == "CMDCOLOR 05")
            {
                system("start color 05");
            }
            if (text == "CMDCOLOR 06")
            {
                system("start color 06");
            }
            if (text == "CMDCOLOR 07")
            {
                system("start color 07");
            }
            if (text == "CMDCOLOR 08")
            {
                system("start color 08");
            }
            if (text == "CMDCOLOR 09")
            {
                system("start color 09");
            }
            if (text == "CMDCOLOR 0A")
            {
                system("start color 0A");
            }
            if (text == "CMDCOLOR 0B")
            {
                system("start color 0B");
            }
            if (text == "CMDCOLOR 0C")
            {
                system("start color 0C");
            }
            if (text == "CMDCOLOR 0D")
            {
                system("start color 0D");
            }
            if (text == "CMDCOLOR 0E")
            {
                system("start color 0E");
            }
            if (text == "CMDCOLOR 0F")
            {
                system("start color 0F");
            }





            if (text == "CMDCOLOR 10")
            {
                system("start color 10");
            }
            if (text == "CMDCOLOR 11")
            {
                system("start color 11");
            }
            if (text == "CMDCOLOR 12")
            {
                system("start color 12");
            }
            if (text == "CMDCOLOR 13")
            {
                system("start color 13");
            }
            if (text == "CMDCOLOR 14")
            {
                system("start color 14");
            }
            if (text == "CMDCOLOR 15")
            {
                system("start color 15");
            }
            if (text == "CMDCOLOR 16")
            {
                system("start color 16");
            }
            if (text == "CMDCOLOR 17")
            {
                system("start color 17");
            }
            if (text == "CMDCOLOR 18")
            {
                system("start color 18");
            }
            if (text == "CMDCOLOR 19")
            {
                system("start color 19");
            }
            if (text == "CMDCOLOR 1A")
            {
                system("start color 1A");
            }
            if (text == "CMDCOLOR 1B")
            {
                system("start color 1B");
            }
            if (text == "CMDCOLOR 1C")
            {
                system("start color 1C");
            }
            if (text == "CMDCOLOR 1D")
            {
                system("start color 1D");
            }
            if (text == "CMDCOLOR 1E")
            {
                system("start color 1E");
            }
            if (text == "CMDCOLOR 1F")
            {
                system("start color 1F");
            }






            if (text == "CMDCOLOR 20")
            {
                system("start color 20");
            }
            if (text == "CMDCOLOR 21")
            {
                system("start color 21");
            }
            if (text == "CMDCOLOR 22")
            {
                system("start color 22");
            }
            if (text == "CMDCOLOR 23")
            {
                system("start color 23");
            }
            if (text == "CMDCOLOR 24")
            {
                system("start color 24");
            }
            if (text == "CMDCOLOR 25")
            {
                system("start color 25");
            }
            if (text == "CMDCOLOR 26")
            {
                system("start color 26");
            }
            if (text == "CMDCOLOR 27")
            {
                system("start color 27");
            }
            if (text == "CMDCOLOR 28")
            {
                system("start color 28");
            }
            if (text == "CMDCOLOR 29")
            {
                system("start color 29");
            }
            if (text == "CMDCOLOR 2A")
            {
                system("start color 2A");
            }
            if (text == "CMDCOLOR 2B")
            {
                system("start color 2B");
            }
            if (text == "CMDCOLOR 2C")
            {
                system("start color 2C");
            }
            if (text == "CMDCOLOR 2D")
            {
                system("start color 2D");
            }
            if (text == "CMDCOLOR 2E")
            {
                system("start color 2E");
            }
            if (text == "CMDCOLOR 2F")
            {
                system("start color 2F");
            }





            if (text == "CMDCOLOR 30")
            {
                system("start color 30");
            }
            if (text == "CMDCOLOR 31")
            {
                system("start color 31");
            }
            if (text == "CMDCOLOR 32")
            {
                system("start color 32");
            }
            if (text == "CMDCOLOR 33")
            {
                system("start color 33");
            }
            if (text == "CMDCOLOR 34")
            {
                system("start color 34");
            }
            if (text == "CMDCOLOR 35")
            {
                system("start color 35");
            }
            if (text == "CMDCOLOR 36")
            {
                system("start color 36");
            }
            if (text == "CMDCOLOR 37")
            {
                system("start color 37");
            }
            if (text == "CMDCOLOR 38")
            {
                system("start color 38");
            }
            if (text == "CMDCOLOR 39")
            {
                system("start color 39");
            }
            if (text == "CMDCOLOR 3A")
            {
                system("start color 3A");
            }
            if (text == "CMDCOLOR 3B")
            {
                system("start color 3B");
            }
            if (text == "CMDCOLOR 3C")
            {
                system("start color 3C");
            }
            if (text == "CMDCOLOR 3D")
            {
                system("start color 3D");
            }
            if (text == "CMDCOLOR 3E")
            {
                system("start color 3E");
            }
            if (text == "CMDCOLOR 3F")
            {
                system("start color 3F");
            }




            if (text == "CMDCOLOR 40")
            {
                system("start color 40");
            }
            if (text == "CMDCOLOR 41")
            {
                system("start color 41");
            }
            if (text == "CMDCOLOR 42")
            {
                system("start color 42");
            }
            if (text == "CMDCOLOR 43")
            {
                system("start color 43");
            }
            if (text == "CMDCOLOR 44")
            {
                system("start color 44");
            }
            if (text == "CMDCOLOR 45")
            {
                system("start color 45");
            }
            if (text == "CMDCOLOR 46")
            {
                system("start color 46");
            }
            if (text == "CMDCOLOR 47")
            {
                system("start color 47");
            }
            if (text == "CMDCOLOR 48")
            {
                system("start color 48");
            }
            if (text == "CMDCOLOR 49")
            {
                system("start color 49");
            }
            if (text == "CMDCOLOR 4A")
            {
                system("start color 4A");
            }
            if (text == "CMDCOLOR 4B")
            {
                system("start color 4B");
            }
            if (text == "CMDCOLOR 4C")
            {
                system("start color 4C");
            }
            if (text == "CMDCOLOR 0D")
            {
                system("start color 0D");
            }
            if (text == "CMDCOLOR 0E")
            {
                system("start color 0E");
            }
            if (text == "CMDCOLOR 0F")
            {
                system("start color 0F");
            }
            if (text == "DIR")
            {
                MessageBoxA(hWnd, "�� ������ ���������� ����������? ��� ������. �� ��� ��� �������� ����������, ������� SECRET", "��������", MB_ICONASTERISK);

            }
            if (text == "SECRET")
            {
                MessageBoxA(hWnd, "�������� ����� �������� ��� CHASTUSHKI, �������������� �������� ��������� �� ������ � ���������, ��� ������ �����.", "� ���� ���� ���������!!!! =(", MB_ICONASTERISK);

            }

            if (text == "��������" || text == "CHASTUSHKI")
            {
                BASS_StreamFree(CHASTUSHKI);
                BASS_MusicFree(CHASTUSHKI);
                BASS_ChannelStop(CHASTUSHKI);
                BASS_SampleFree(CHASTUSHKI);
                BASS_StreamFree(IMPOTENT);
                BASS_MusicFree(IMPOTENT);
                BASS_ChannelStop(IMPOTENT);
                BASS_SampleFree(IMPOTENT);
                BASS_StreamFree(OXYENNA);
                BASS_MusicFree(OXYENNA);
                BASS_ChannelStop(OXYENNA);
                BASS_SampleFree(OXYENNA);
                BASS_StreamFree(LIRIKAHOI);
                BASS_MusicFree(LIRIKAHOI);
                BASS_ChannelStop(LIRIKAHOI);
                BASS_SampleFree(LIRIKAHOI);
                BASS_StreamFree(LJSPQK);
                BASS_MusicFree(LJSPQK);
                BASS_ChannelStop(LJSPQK);
                BASS_SampleFree(LJSPQK);

                BASS_StreamFree(AEZAKMI);
                BASS_MusicFree(AEZAKMI);
                BASS_ChannelStop(AEZAKMI);
                BASS_SampleFree(AEZAKMI);
                BASS_StreamFree(Z_KRAF1ER_Z);
                BASS_MusicFree(Z_KRAF1ER_Z);
                BASS_ChannelStop(Z_KRAF1ER_Z);
                BASS_SampleFree(Z_KRAF1ER_Z);
                CHASTUSHKI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Sektor\\Chastushki.mp3", 0, 0, 0);


                BASS_ChannelPlay(CHASTUSHKI, false);




            }
            if (text == "MD LPT")
            {
                MessageBoxA(hWnd, "� ����� ������� � ���������?\n�� �������� ��� �� �������, � � ��� ���� ����� �����������.\n�� �������� ����������� � �������� ����.", "�������� � ���������?", MB_ICONASTERISK);
                MessageBoxA(hWnd, "��� � ������ ���������� ������ �������� ����� �� LPT?", "������ ������:", MB_ICONASTERISK);
                return 0;
            }

            if (text == "COVOX")
            {
                MessageBoxA(hWnd, "������ ����� - WANT, I", "������� 1", MB_ICONASTERISK);
                MessageBoxA(hWnd, "����� ���������� � ������ ����� ������ � 2022 ���� �� 30000 ������?", "������ ������:", MB_ICONASTERISK);
                return 0;
            }
            if (text == "RTX 3050" || text == "��� 3050")
            {
                MessageBoxA(hWnd, "������� �����, �� ��� �� �����. ������ ����� ����������� - PLAY, TO ", "�������, 2!", MB_ICONASTERISK);
                MessageBoxA(hWnd, "��������� ����������� �� ���� ����. ����� ����������, ����� �������� �������. ", "����!", MB_ICONASTERISK);
                return 0;
            }
            if (text == "I WANT TO PLAY")
            {
                MessageBoxA(hWnd, "������� �� ����������� =)", "����� =)", MB_ICONASTERISK);
                system("start MusicPlayer\\X3\\M\\1.bat");
            }
            if (text == "CON")
            {
                MessageBoxA(hWnd, "������ ������� �����? �� ��� ������ ������� ���������. MD CON ��� MKDIR CON", "��������", MB_ICONASTERISK);
                return 0;
            }
            if (text == "COM")
            {
                MessageBoxA(hWnd, "������ ������� �����? �� ��� ������ ������� ���������. MD COM ��� MKDIR COM", "�������� 2", MB_ICONASTERISK);
                return 0;
            }
            if (text == "MD CON" || text == "MKDIR CON")
            {
                BASS_StreamFree(CHASTUSHKI);
                BASS_MusicFree(CHASTUSHKI);
                BASS_ChannelStop(CHASTUSHKI);
                BASS_SampleFree(CHASTUSHKI);
                BASS_StreamFree(IMPOTENT);
                BASS_MusicFree(IMPOTENT);
                BASS_ChannelStop(IMPOTENT);
                BASS_SampleFree(IMPOTENT);
                BASS_StreamFree(OXYENNA);
                BASS_MusicFree(OXYENNA);
                BASS_ChannelStop(OXYENNA);
                BASS_SampleFree(OXYENNA);
                BASS_StreamFree(LJSPQK);
                BASS_MusicFree(LJSPQK);
                BASS_ChannelStop(LJSPQK);
                BASS_SampleFree(LJSPQK);
                BASS_StreamFree(LIRIKAHOI);
                BASS_MusicFree(LIRIKAHOI);
                BASS_ChannelStop(LIRIKAHOI);
                BASS_SampleFree(LIRIKAHOI);
                BASS_StreamFree(AEZAKMI);
                BASS_MusicFree(AEZAKMI);
                BASS_ChannelStop(AEZAKMI);
                BASS_SampleFree(AEZAKMI);
                BASS_StreamFree(Z_KRAF1ER_Z);
                BASS_MusicFree(Z_KRAF1ER_Z);
                BASS_ChannelStop(Z_KRAF1ER_Z);
                BASS_SampleFree(Z_KRAF1ER_Z);
                IMPOTENT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Sektor\\IMP.mp3", 0, 0, 0);


                BASS_ChannelPlay(IMPOTENT, false);
            }
            if (text == "MD COM" || text == "MKDIR COM")
            {
                BASS_StreamFree(CHASTUSHKI);
                BASS_MusicFree(CHASTUSHKI);
                BASS_ChannelStop(CHASTUSHKI);
                BASS_SampleFree(CHASTUSHKI);
                BASS_StreamFree(OXYENNA);
                BASS_MusicFree(OXYENNA);
                BASS_ChannelStop(OXYENNA);
                BASS_SampleFree(OXYENNA);
                BASS_StreamFree(IMPOTENT);
                BASS_MusicFree(IMPOTENT);
                BASS_ChannelStop(IMPOTENT);
                BASS_SampleFree(IMPOTENT);
                BASS_StreamFree(LIRIKAHOI);
                BASS_MusicFree(LIRIKAHOI);
                BASS_ChannelStop(LIRIKAHOI);
                BASS_SampleFree(LIRIKAHOI);
                BASS_StreamFree(LJSPQK);
                BASS_MusicFree(LJSPQK);
                BASS_ChannelStop(LJSPQK);
                BASS_SampleFree(LJSPQK);

                BASS_StreamFree(AEZAKMI);
                BASS_MusicFree(AEZAKMI);
                BASS_ChannelStop(AEZAKMI);
                BASS_SampleFree(AEZAKMI);
                BASS_StreamFree(Z_KRAF1ER_Z);
                BASS_MusicFree(Z_KRAF1ER_Z);
                BASS_ChannelStop(Z_KRAF1ER_Z);
                BASS_SampleFree(Z_KRAF1ER_Z);
                OXYENNA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Sektor\\VIA.mp3", 0, 0, 0);


                BASS_ChannelPlay(OXYENNA, false);
            }
            if (text == "PRN")
            {
                MessageBoxA(hWnd, "�������? �� ���� �������� � ��������! ������ ����� ��� ����� MD PRN ��� MKDIR PRN", "�������� 3", MB_ICONASTERISK);
                return 0;
            }
            if (text == "MD PRN" || text == "MKDIR PRN")
            {
                BASS_StreamFree(CHASTUSHKI);
                BASS_MusicFree(CHASTUSHKI);
                BASS_ChannelStop(CHASTUSHKI);
                BASS_SampleFree(CHASTUSHKI);
                BASS_StreamFree(OXYENNA);
                BASS_MusicFree(OXYENNA);
                BASS_ChannelStop(OXYENNA);
                BASS_SampleFree(OXYENNA);
                BASS_StreamFree(IMPOTENT);
                BASS_MusicFree(IMPOTENT);
                BASS_ChannelStop(IMPOTENT);
                BASS_SampleFree(IMPOTENT);
                BASS_StreamFree(LIRIKAHOI);
                BASS_MusicFree(LIRIKAHOI);
                BASS_ChannelStop(LIRIKAHOI);
                BASS_SampleFree(LIRIKAHOI);
                BASS_StreamFree(LJSPQK);
                BASS_MusicFree(LJSPQK);
                BASS_ChannelStop(LJSPQK);
                BASS_SampleFree(LJSPQK);

                BASS_StreamFree(AEZAKMI);
                BASS_MusicFree(AEZAKMI);
                BASS_ChannelStop(AEZAKMI);
                BASS_SampleFree(AEZAKMI);
                BASS_StreamFree(Z_KRAF1ER_Z);
                BASS_MusicFree(Z_KRAF1ER_Z);
                BASS_ChannelStop(Z_KRAF1ER_Z);
                BASS_SampleFree(Z_KRAF1ER_Z);
                LIRIKAHOI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Sektor\\LIRIKA.mp3", 0, 0, 0);


                BASS_ChannelPlay(LIRIKAHOI, false);
            }
            if (text == "MD AUX" || text == "MKDIR AUX")
            {
                MessageBoxA(hWnd, "�� �������� ��� ����� ������ ��������. �� ��� ���� �������: <<����� ���������� ����� 4 �� DDR 3 ����������� � ��������������� ���������. ������������ � ��� ������?>>", "��������?", MB_ICONERROR);

            }

            if (text == "�������" || text == "PORNO" || text == "PORN")
            {
                system("start https://www.xvideos.com/");
            }
            if (text == "LJSPQK" || text == "BRINGITON")
            {
                MessageBoxA(hWnd, "���� ���������� �������� � �������. ���� ������ �������, ������ ��� ��� �� ������� � GTA San Andreas", "�������, � ����� ��, ����������, � ��� ��������", MB_ICONERROR);
                BASS_StreamFree(CHASTUSHKI);
                BASS_MusicFree(CHASTUSHKI);
                BASS_ChannelStop(CHASTUSHKI);
                BASS_SampleFree(CHASTUSHKI);
                BASS_StreamFree(OXYENNA);
                BASS_MusicFree(OXYENNA);
                BASS_ChannelStop(OXYENNA);
                BASS_SampleFree(OXYENNA);
                BASS_StreamFree(IMPOTENT);
                BASS_MusicFree(IMPOTENT);
                BASS_ChannelStop(IMPOTENT);
                BASS_SampleFree(IMPOTENT);
                BASS_StreamFree(LIRIKAHOI);
                BASS_MusicFree(LIRIKAHOI);
                BASS_ChannelStop(LIRIKAHOI);
                BASS_SampleFree(LIRIKAHOI);
                BASS_StreamFree(LJSPQK);
                BASS_MusicFree(LJSPQK);
                BASS_ChannelStop(LJSPQK);
                BASS_SampleFree(LJSPQK);
                BASS_StreamFree(AEZAKMI);
                BASS_MusicFree(AEZAKMI);
                BASS_ChannelStop(AEZAKMI);
                BASS_SampleFree(AEZAKMI);
                BASS_StreamFree(Z_KRAF1ER_Z);
                BASS_MusicFree(Z_KRAF1ER_Z);
                BASS_ChannelStop(Z_KRAF1ER_Z);
                BASS_SampleFree(Z_KRAF1ER_Z);
                LJSPQK = BASS_StreamCreateFile(FALSE, "MusicPlayer\\GTA\\LJSPQK.mp3", 0, 0, 0);
                BASS_ChannelPlay(LJSPQK, false);
            }
            if (text == "AEZAKMI" || text == "IDOASIPLEASE")
            {
                MessageBoxA(hWnd, "�� ��������� �������", "YOU ARE SERIOUS?", MB_ICONERROR);
                BASS_StreamFree(CHASTUSHKI);
                BASS_MusicFree(CHASTUSHKI);
                BASS_ChannelStop(CHASTUSHKI);
                BASS_SampleFree(CHASTUSHKI);
                BASS_StreamFree(OXYENNA);
                BASS_MusicFree(OXYENNA);
                BASS_ChannelStop(OXYENNA);
                BASS_SampleFree(OXYENNA);
                BASS_StreamFree(IMPOTENT);
                BASS_MusicFree(IMPOTENT);
                BASS_ChannelStop(IMPOTENT);
                BASS_SampleFree(IMPOTENT);

                BASS_StreamFree(LIRIKAHOI);
                BASS_MusicFree(LIRIKAHOI);
                BASS_ChannelStop(LIRIKAHOI);
                BASS_SampleFree(LIRIKAHOI);

                BASS_StreamFree(LJSPQK);
                BASS_MusicFree(LJSPQK);
                BASS_ChannelStop(LJSPQK);
                BASS_SampleFree(LJSPQK);

                BASS_StreamFree(AEZAKMI);
                BASS_MusicFree(AEZAKMI);
                BASS_ChannelStop(AEZAKMI);
                BASS_SampleFree(AEZAKMI);
                BASS_StreamFree(Z_KRAF1ER_Z);
                BASS_MusicFree(Z_KRAF1ER_Z);
                BASS_ChannelStop(Z_KRAF1ER_Z);
                BASS_SampleFree(Z_KRAF1ER_Z);
                AEZAKMI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\GTA\\AEZAKMI.mp3", 0, 0, 0);
                BASS_ChannelPlay(AEZAKMI, false);
            }
            if (text == "GTX745" || text == "GTX 745" || text == "NVIDIA GTX 745")
            {
                MessageBoxA(hWnd, "�����, ��� �� �����", "�������", MB_ICONINFORMATION);
                system("start https://www.youtube.com/watch?v=900cJATeGQU");
            }
            if (text == "WIN" || text == "WIN.COM" /* || text == "Win" || text == "win"*/)
            {
                system("start MusicPlayer\\W311\\dosbox.exe -conf MusicPlayer\\W311\\dosbox.conf -noconsole");
            }

            //if (text == "WINDOWS 7 IS THE BEST")
            //{
            //    SendMessage(hWnd, WM_NCPAINT, 1, 1);
            //}

            //if (text == "KILLMEMORY")
            //{
            //    HANDLE hMem;

            //    while (true) {
            //        hMem = HeapCreate(MEMORY_PRIORITY_NORMAL, 0x7FFFFFFFFFFFFE, 0x7FFFFFFFFFFFFE)
            //            HeapAlloc()
            //    }
            //};

            if (text == "Z_CRAF1ER_Z" || text == "Z_CRAFTER_Z" || text == "Z_KRAFTER_Z" || text == "Z_KRAFLER_Z" || text == "Z_CRAFLER_Z")
            {
                SetWindowText(COM, "Z_KRAF1ER_Z");
            }

            if (text == "Z_KRAF1ER_Z")
            {
                BASS_StreamFree(CHASTUSHKI);
                BASS_MusicFree(CHASTUSHKI);
                BASS_ChannelStop(CHASTUSHKI);
                BASS_SampleFree(CHASTUSHKI);
                BASS_StreamFree(IMPOTENT);
                BASS_MusicFree(IMPOTENT);
                BASS_ChannelStop(IMPOTENT);
                BASS_SampleFree(IMPOTENT);
                BASS_StreamFree(OXYENNA);
                BASS_MusicFree(OXYENNA);
                BASS_ChannelStop(OXYENNA);
                BASS_SampleFree(OXYENNA);
                BASS_StreamFree(LIRIKAHOI);
                BASS_MusicFree(LIRIKAHOI);
                BASS_ChannelStop(LIRIKAHOI);
                BASS_SampleFree(LIRIKAHOI);
                BASS_StreamFree(LJSPQK);
                BASS_MusicFree(LJSPQK);
                BASS_ChannelStop(LJSPQK);
                BASS_SampleFree(LJSPQK);
                BASS_StreamFree(AEZAKMI);
                BASS_MusicFree(AEZAKMI);
                BASS_ChannelStop(AEZAKMI);
                BASS_SampleFree(AEZAKMI);
                BASS_StreamFree(Z_KRAF1ER_Z);
                BASS_MusicFree(Z_KRAF1ER_Z);
                BASS_ChannelStop(Z_KRAF1ER_Z);
                BASS_SampleFree(Z_KRAF1ER_Z);
                Z_KRAF1ER_Z = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Z_Kraf1er_Z\\Trespasser.mp3", 0, 0, 0);


                BASS_ChannelPlay(Z_KRAF1ER_Z, false);
            }



            //if (text == "Z_KRAF1ER_Z")
            //{
            //    __asm {

            //        /*include win64.inc*/
            //        //include kernel32.inc
            //        //include user32.inc
            //        //includelib kernel32.lib
            //        //includelib user32.lib

            //        //.data
            //        MsgCaption      db 'Win64 Iczelion''s lesson #2: MessageBox', 0
            //        MsgBoxText      db 'Win64 Assembly is Great!', 0

            //        //.code
            //        //WinMain proc

            //            //sub rsp,28h

            //            xor ecx, ecx
            //            lea rdx, MsgBoxText
            //            lea r8, MsgCaption
            //            xor r11d, r11d
            //            call MessageBox

            //            xor ecx, ecx
            //            call ExitProcess

            //            //WinMain endp
            //            //end

            //    }
            //}

            char str2[] = "�������";

            if (text == "A")
            {
                MessageBox(hWnd, "�", str2, MB_ICONERROR);
            }
            if (text == "�")
            {
                MessageBox(hWnd, "�", str2, MB_ICONERROR);
            }
            if (text == "�")
            {
                MessageBox(hWnd, "�", str2, MB_ICONERROR);
            }
            if (text == "�")
            {
                MessageBox(hWnd, "�", str2, MB_ICONERROR);
            }
            if (text == "�")
            {
                MessageBox(hWnd, "�", str2, MB_ICONERROR);
            }
            if (text == "�")
            {
                MessageBox(hWnd, "�", str2, MB_ICONERROR);
            }
            if (text == "�")
            {
                MessageBox(hWnd, "�", str2, MB_ICONERROR);
            }




        }


        break;
    }
    case WM_PAINT: {
        hdc = BeginPaint(hWnd, &ps);
        FillRect(hdc, &ps.rcPaint, hBrush);
        EndPaint(hWnd, &ps);

    }
                 break;

    case WM_DESTROY: {
        PostQuitMessage(0);
        return 0;

        break;

    }






    case WM_KEYDOWN:
    {
        switch (LOWORD(wParam))
        {
        case VK_ESCAPE:
            DestroyWindow(hWnd);
            break;
        case VK_SPACE:
            SendMessage(hWnd, WM_COMMAND, SETBKG, 0);
            break;
        case VK_RETURN:
            SendMessage(hWnd, WM_COMMAND, COMMANDA, 0);
            break;
        case VK_MBUTTON:
            SendMessage(hWnd, WM_COMMAND, MYCOLOR, 0);
            break;

        case VK_ADD:
            SendMessage(GetDlgItem(hWnd, CHB1), BM_SETCHECK, BST_CHECKED, 0);
            break;
        case VK_NUMPAD1:
            SendMessage(hWnd, WM_COMMAND, SKIN1, 0);
            break;
        case VK_NUMPAD3:
            SendMessage(hWnd, WM_COMMAND, SKIN2, 0);
            break;
        case VK_NUMPAD2:
            SendMessage(hWnd, WM_COMMAND, SKIN3, 0);
            break;
        case VK_SUBTRACT:
            SendMessage(GetDlgItem(hWnd, CHB1), BM_SETCHECK, BST_UNCHECKED, 0);
            break;

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


    }break;

    default:
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
    progicon = (HICON)LoadImage(op.hInstance, "MusicPlayer\\BMP\\ico\\terminal.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
    op.hIcon = progicon;
    //op.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    RegisterClass(&op);


    CreateWindowEx(WS_EX_LAYERED, op.lpszClassName, "�������� StrannikCorp ver 1.2", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE, 100, 100, 800, 600, NULL, NULL, op.hInstance, NULL);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }

}
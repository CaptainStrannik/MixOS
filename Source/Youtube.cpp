#include <windows.h>
#include <cstring>
#include <cstdlib>                   //�� ��������� ��������
// ������ � ���� emulate.cpp ���     //� ���� � ��� ������ ������, �� �� �������?
// ������� 3 ��� � ������
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
#include <fstream>



HWND MENUMENUMENU;
HWND MENUMENUMENU1;
HWND MENUMENUMENU2;
HWND MENUMENUMENU3;
HSTREAM YOUTUBER;
HWND eMp3;
int skins;
HANDLE bmpwall;
HANDLE bmpwall1;
HWND hwall;
TCHAR StrT[MAX_PATH];
static COLORREF acrCustClr[16];
#pragma comment(linker,"/manifestdependency:\"type='win32' \
                        name='Microsoft.Windows.Common-Controls' \
                        version='6.0.0.0' processorArchitecture='*'\
 publicKeyToken='6595b64144ccf1df' language='*'\"")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "bass")
using namespace std;
char str1[1024];

HDC hdc;
PAINTSTRUCT ps;
HBRUSH hBrush = CreateSolidBrush(RGB(76,0 ,153));
HWND hTrack;
HINSTANCE hInst;
HICON progicon;

const TCHAR progname[] = "��������� ����� � ����� ver 1.11";

//������ ��� ����� =)
static DWORD rgbCurrent = RGB(76,0,153);

static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {

    case WM_CREATE: {

        eMp3 = CreateWindow(TEXT("Edit"), NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD, 120, 50, 1000 + 30, 20, hWnd, (HMENU)SKINSSTRO, NULL, 0);
        int a = 140;

        HMENU hMenubar = CreateMenu();

        HMENU hAbout = CreateMenu();
        HMENU hColorYT = CreateMenu();


        NOTIFYICONDATA data;
        ZeroMemory(&data, sizeof(NOTIFYICONDATA));




        SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);
 

        data.cbSize = sizeof(data);
        data.hWnd = hWnd;
        data.uID = 1;          // ����� ��������� ����� �������������, �� ����� ������ ������ ����
        data.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
        data.uCallbackMessage = WM_USER_SHELLICON;
        data.hIcon = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Youtube.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        data.uVersion = NOTIFYICON_VERSION;
        
   /*     strcpy(data.szInfoTitle, "��������� ����� � Youtube");*/
        strcpy(data.szTip, "��������� ����� � Youtube");

        Shell_NotifyIcon(NIM_ADD, &data);

        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "�������");
        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hColorYT, "������� ����");



        CreateWindow(TEXT("BUTTON"), TEXT("������� ����� � Youtube"), WS_VISIBLE | WS_CHILD, 45 + a, 130, 240, 25, hWnd, (HMENU)MENUMAKER, NULL, NULL);


        BASS_Init(-1, 44100, 0, 0, NULL); 


        SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));


        AppendMenu(hAbout, MF_STRING, STRANNIK, "� ���������");
        AppendMenu(hColorYT, MF_STRING, COLORYT, "��� ����");
        AppendMenu(hColorYT, MF_STRING, SETBKG, "��� ����");
        AppendMenu(hColorYT, MF_SEPARATOR, NULL, NULL);
        AppendMenu(hColorYT, MF_STRING, polupon, "�������� ����������������");
        AppendMenu(hColorYT, MF_STRING, polupoff, "��������� ����������������");



        SetMenu(hWnd, hMenubar); 


        BASS_Start();     //��� ����� ������� � �������� ���. �� ���� ������ ������ ������ ������ ����� ������� �� ������ ������. ��� ���� ����� ����� �������� ��������
        // ����� ��� ��� �����    //��, �� �� �������, ������ �������� � ������ ������ ���� ���? �������� ������, ��� ��� ������ � ������ ������ �� ������. �� ����� ������ � ������ ���������� ���� ���? ���� ��� emulate.cpp ����������.
        // ������ ��� � �� ����� ������� ����
        // � ��������� � ��������� �� �������� ����� ��� ������ 
        YOUTUBER = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\Youtube.mp3", 0, 0, 0);
        BASS_ChannelPlay(YOUTUBER, false);// ��� ������ ��� �������� ��������. � ��� ���� ��?
        // ��������������� ���� � ������     ��� �� ���.... �������. �� ������ ��� ��������� ��������.
        // � ����� ����� �����???  ��� � ������ ��� �������� ���� ���� ���������� �� ������� �� ������ ������. �� ��� ��� ��������� ����� ��������� ����� �������. ���

        break;
    }
    case WM_COMMAND:
            //������ ����� ����� �� ��������, � ���� �����������....
    {









        if (LOWORD(wParam) == polupon)
        {

            SetLayeredWindowAttributes(hWnd, NULL, 230, LWA_ALPHA);
        }
        if (LOWORD(wParam) == polupoff)
        {

            SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);
        }








        int len90;                                                                                                              
        TCHAR video[1200];
        len90 = GetWindowText(MENUMENUMENU, video, 1200);
        if (LOWORD(wParam) == MENUMAKER)
        {
            int a = 140;   //���, ������ ������ ����� ��� ���. ������ ������. ���� �������� ������ ��������� �� ��� ������������, ��� ������������ ����. =) ��� Youtube.cpp Emulate.cpp, quest.cpp.  �� ����� ����� ���� ��� ����� ����������. ����� �������, �� �����, ��� ��� ����� ��� ��� ������ ���������.
            // � ���� � ������ ��������???    //� � ������, ��� �������, ���� ��� ��� ���������, ��� �� ����� ��� ���� ������ ����� ����, �� ���� �� �������� ��������� �������������, �����-������, �� ������ ����� ������ ������������� ���� ��������� =).
            //��
            MENUMENUMENU = CreateWindow(TEXT("EDIT"), TEXT("������ �� ����� �� Youtube"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE, 10, 500, 605, 70, hWnd, (HMENU)WRITING, NULL, 0);
            CreateWindow(TEXT("BUTTON"), TEXT("�������"), WS_VISIBLE | WS_CHILD, 120 + a, 360, 100, 25, hWnd, (HMENU)MAKEMAKE, NULL, NULL);
            ShowWindow(GetDlgItem(hWnd, MENUMAKER), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("                 ����� ������� ����� ���� : \n\n1) �������� ������ �� ����� � ���� ��� �����.\n2) ������ ������ << ������� >> .\n\nP.S ����������, ��� �� �� �������� = )\n\nP.S.S ������ ���� ������ ����� = ) "), WS_VISIBLE | WS_CHILD, 150, 90, 325, 140, hWnd, (HMENU)text1, NULL, NULL);

            hTrack = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | LVS_EX_TRANSPARENTBKGND | WS_VISIBLE, 150, 250, 320, 30, hWnd, (HMENU)LENMUSIC, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("���������"), WS_VISIBLE | WS_CHILD, 130 + a, 290, 70, 18, hWnd, (HMENU)text1, NULL, NULL);
                                            //PERFECT
                                            // PROFIT     ������ ����� �� ������ � Emulate.cpp ������ ���� ��������� �������� ������� ��������� ������ �� 20
        
        }                              //��������� �����, ��� ������ ���� ������ ��������� =)
        // ��� ����������� :)   �� ������ �������  �� ���� ����� ����� ��� � � Createwindowstext(static)


        if (LOWORD(wParam) == STRANNIK)
        {
            ShellAbout(hWnd, progname, "�����������: Captain Strannik. ��������: Z_Kraf1er_Z. ����� ����: Daniel Myslivets", progicon);
            MessageBoxA(hWnd, "��� ��������� ��� ���������� ������� � Youtube.\n������� Daniel Myslivets �� ��������������� ���������� ����������, ��� ������� � ������ ������ ���� GUI", "�������", MB_ICONASTERISK);
        
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
            ofnn.lpstrInitialDir = "MusicPlayer\\BMP\\MIXMENU";
            ofnn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_DONTADDTORECENT | OFN_NOCHANGEDIR;   //���� ������ ���!  � � ���� ������.

            if (GetOpenFileName(&ofnn) == TRUE)
            {
                SetWindowText(eMp3, str1);

                DestroyWindow(hwall);
                DestroyWindow(GetDlgItem(hWnd, INSTBKG));
                ShowWindow(GetDlgItem(hWnd, SKINSSTRO), SW_HIDE);

                ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);

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
            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_HIDE);

        }
        if (LOWORD(wParam) == MAKEMAKE)
        {
            
            ofstream Proga;
            string videos = video;
 





    

            Proga.open("MusicPlayer\\Youtube\\bat.bat");
            Proga << "MusicPlayer\\Youtube\\yt-dlp.exe �format mp4 " << videos << endl;
            Proga << "echo Your video has been downloaded, and stay in MusicPlayer's directory" << endl;
            Proga.close();
            system("MusicPlayer\\Youtube\\bat.bat");
            system("del MusicPlayer\\Youtube\\bat.bat");
            MessageBox(hWnd, _T("���� ����� ���� �������!\n������ ��� ����� � ����� � �������"), _T("�����!"), MB_ICONASTERISK);
    
        }

                if (LOWORD(wParam) == COLORYT)
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
                break;

        case WM_HSCROLL: {
            if (hTrack == (HWND)lParam)
            {
                BASS_ChannelSetAttribute(YOUTUBER, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 80, 100));
            }
        } break;

        case WM_PAINT: {
            hdc = BeginPaint(hWnd, &ps);
            FillRect(hdc, &ps.rcPaint, hBrush);
            EndPaint(hWnd, &ps);
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
                }
                break;





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
    progicon = (HICON)LoadImage(op.hInstance, "MusicPlayer\\BMP\\ico\\Youtube.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
    op.hIcon = progicon;
    //op.hbrBackground = CreateSolidBrush(RGB(76,0 ,153));
    RegisterClass(&op);


    CreateWindowEx(WS_EX_LAYERED,op.lpszClassName, progname, WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX| WS_VISIBLE, 100, 100, 640, 640, NULL, NULL, op.hInstance, NULL);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }

}
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
//#define STRANNI 90     
//
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
//HBRUSH hBrush = CreateSolidBrush(RGB(255, 155, 155));
//static DWORD rgbCurrent = RGB(255, 155, 155);
//HWND hTrack;
//HDC hdc;
//PAINTSTRUCT ps;
//const TCHAR progname[] = _T("����������");
//HWND tardis;
////bool key_pressed = false;
//HINSTANCE hInst;
//
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
//        data.hIcon = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\quest.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
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
//
//
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "�������");
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hOptions, "���������");
//
//
//
//        SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//        AppendMenu(hAbout, MF_STRING, STRANNIK, "� ���������");
//        AppendMenu(hAbout, MF_STRING, STRANNI, "��������");
//
//
//        AppendMenu(hOptions, MF_STRING, MYCOLOR, "������� ����");
//
//        SetMenu(hWnd, hMenubar);
//        BASS_Init(-1, 44100, 0, 0, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("������"), WS_VISIBLE | WS_CHILD, 200, 100, 250, 150, hWnd, (HMENU)ID_BUTTON, NULL, NULL);
//
//
//
//
//        break;
//
//
//    }
//    case WM_COMMAND: {
//
//        //ShowWindow(GetDlgItem(hWnd, LENMUSIC), SW_SHOW);
//
//        if (LOWORD(wParam) == STRANNIK)
//        {
//            ShellAbout(hWnd, progname, "�����������: Captain Strannik", progicon);
//            MessageBoxA(hWnd, "��� ��������� ��� �������� ���������� � ����������,\n �� ���� ��� ������ ��� ���������� ������� =).\n��� ��������� �������� �������� �������� �������\n������������ � ������� � ��������� ����� ������.\n���� �����, ��� ��������� ��� �������, ����� �� � ��� � �������� ��� =).", "� ���������", MB_OK);
//        }
//        if (LOWORD(wParam) == ID_BUTTON)
//        {
//
//            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//            BASS_Stop();
//            BASS_Start();
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//
//            CreateWindow(TEXT("STATIC"), TEXT("��� ������ ������ ��� ���"), WS_VISIBLE | WS_CHILD, 150 + 50, 50, 230, 20, hWnd, (HMENU)text1, NULL, NULL);
//
//            LOVE = CreateWindow(TEXT("Edit"), NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE, 120 + 70, 150, 220, 20, hWnd, (HMENU)SKINSSTRO, NULL, 0);
//
//            CreateWindow(TEXT("BUTTON"), TEXT("��������"), WS_VISIBLE | WS_CHILD, 220, 180, 150, 30, hWnd, (HMENU)GIRLNAME, NULL, NULL);
//
//
//            //SetWindowLong(hWnd, GWL_STYLE, WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE);
//            //CreateWindow(_T("STATIC"), _T("�� ��� ��������"), WS_VISIBLE | WS_CHILD, 650, 60, 150, 20, hWnd, (HMENU)text1, NULL, NULL);
//            //tardis = CreateWindow(_T("LISTBOX"), _T("���������� 3000"), WS_CHILD | LBS_HASSTRINGS | LBS_WANTKEYBOARDINPUT | WS_VSCROLL|WS_VISIBLE, 650, 100, 120, 150, hWnd, NULL, NULL, NULL);
//            //CreateWindow(_T("BUTTON"), _T("������������"), WS_CHILD | WS_VISIBLE, 650, 270, 120, 22, hWnd, (HMENU)TELEPORT, NULL, NULL);
//        }
//        if (LOWORD(wParam) == GIRLNAME)
//        {
//
//
//
//
//            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//            BASS_Stop();
//            BASS_Start();
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, GIRLNAME), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, text1), SW_HIDE);
//
//            DestroyWindow(GetDlgItem(hWnd, SKINSSTRO));
//            len = GetWindowText(LOVE, StrB, 1200);
//            SendMessageW(LOVE, EM_SETCUEBANNER, FALSE, (LPARAM)L" ");
//            CreateWindow(TEXT("STATIC"), TEXT("������, "), WS_VISIBLE | WS_CHILD, 150, 50, 60, 20, hWnd, (HMENU)text1, NULL, NULL);
//            CreateWindow(TEXT("STATIC"), TEXT(StrB), WS_VISIBLE | WS_CHILD, 150 + 50 + 5, 50, 60, 20, hWnd, (HMENU)text1, NULL, NULL);
//            LOVE = CreateWindow(TEXT("Edit"), NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE, 120 + 70, 150, 220, 20, hWnd, (HMENU)SKINSSTRO, NULL, 0);
//            MessageBoxA(hWnd, "�������� ����� �����, � ���� ��� ������.\n�� ���� ��� ���� ����� ������\n����� ���� ���� ����, ����.\n��� ������� ����� ������ ����, ����.", "��������� � �����?", MB_ICONINFORMATION);
//            MessageBoxA(hWnd, "�������, ��� ���� �����, ��� �� ����������, ������.\n����� ������� �� ������� � ����\n� �� ������� ���� ���������\n��������� ���� ���� � ����� �����\n� �������� �� ���� ����������.\n <<����������, ������� ��� �������� =)>>", "��������� � �����?", MB_ICONINFORMATION);
//            MessageBoxA(hWnd, "�����, ����� ������� �������, ������ ������ ���������.\n� ���� �������� ���������, � �� �������.\n� � ����� � ���� ������� ������, ������ � ����������.\n������ ���� ���� ��������������.\n��, �, ����������, ������ ��� ������ � ��������.", "��������� � �����?", MB_ICONINFORMATION);
//            CreateWindow(TEXT("STATIC"), TEXT("���� �������? ��/���?"), WS_VISIBLE | WS_CHILD, 150 + 50 + 5 + 60, 50, 180, 20, hWnd, (HMENU)text1, NULL, NULL);
//            len = GetWindowText(LOVE, StrB, 1200);
//            CreateWindow(TEXT("BUTTON"), TEXT("�������"), WS_VISIBLE | WS_CHILD, 220, 180, 150, 30, hWnd, (HMENU)QUESTION2, NULL, NULL);
//        }
//
//        if (LOWORD(wParam) == QUESTION2)
//        {
//            string text = StrB;
//
//
//            if (text == "��")
//            {
//                LOVE = CreateWindow(TEXT("Edit"), NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE, 120 + 70, 150, 220, 20, hWnd, (HMENU)SKINSSTRO, NULL, 0);
//                MessageBoxA(hWnd, "�������, ��� �� �� ����� ����. � �� ����, �������, ��� � ���� ����, �� ��� �������, �� ������ ����.\n�� �� ���� �������� =). ��������� �������, ������ ������ �� �� ����� � ��� ������, ��������.\n�� � ���� ���� ����� �� 100% ������ �������� �������, ������� ����� ���� ������� � �� ��� ������ ���� ����� ������.\n���� ������ ���� ���� ������, � ����� � ��� ����� =). ", "������ �������� 1", MB_ICONINFORMATION);
//                CreateWindow(TEXT("STATIC"), TEXT("���� �������? ��/���?"), WS_VISIBLE | WS_CHILD, 150 + 50 + 5 + 60, 50, 180, 20, hWnd, (HMENU)text1, NULL, NULL);
//                len = GetWindowText(LOVE, StrB, 1200);
//                ShowWindow(GetDlgItem(hWnd, QUESTION1), SW_HIDE);
//                CreateWindow(TEXT("BUTTON"), TEXT("�������"), WS_VISIBLE | WS_CHILD, 220, 180, 150, 30, hWnd, (HMENU)QUESTION3, NULL, NULL);
//            }
//            if (text == "���")
//            {
//                LOVE = CreateWindow(TEXT("Edit"), NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE, 120 + 70, 150, 220, 20, hWnd, (HMENU)SKINSSTRO, NULL, 0);
//                CreateWindow(TEXT("STATIC"), TEXT("���� �������? ��/���?"), WS_VISIBLE | WS_CHILD, 150 + 50 + 5 + 60, 50, 180, 20, hWnd, (HMENU)text1, NULL, NULL);
//                len = GetWindowText(LOVE, StrB, 1200);
//                CreateWindow(TEXT("BUTTON"), TEXT("�������"), WS_VISIBLE | WS_CHILD, 220, 180, 150, 30, hWnd, (HMENU)QUESTION3, NULL, NULL);
//
//
//            }
//
//
//
//
//
//        }
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
//
//
//
//
//
//
//
//    
//
//
//        if (LOWORD(wParam) == MYCOLOR)
//        {
//            
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
//
//            }
//            else
//            {
//
//                /*   bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
//                   SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);*/
//                hBrush = CreateSolidBrush(RGB(0, 76, 153));
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
//    progicon = (HICON)LoadImage(op.hInstance, "MusicPlayer\\BMP\\ico\\quest.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//    op.hIcon = progicon;
//
//    //op.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
//    RegisterClass(&op);
//
//
//    CreateWindowA(op.lpszClassName, "����������", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE, 100, 100, 640, 360, NULL, NULL, op.hInstance, NULL);
//    MSG msg;
//    while (GetMessage(&msg, NULL, 0, 0)) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//
//    }
//
//}
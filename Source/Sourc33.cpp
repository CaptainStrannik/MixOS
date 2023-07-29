//
//
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
//using namespace std;
//HICON progicon;
//
//HANDLE bmpwall;
//HANDLE bmpwall1;
//HWND hwall;
//static COLORREF acrCustClr[16];
//HBRUSH hBrush = CreateSolidBrush(RGB(255, 128, 0));
//static DWORD rgbCurrent = RGB(255, 128, 0);
//HWND hTrack;
//HDC hdc;
//PAINTSTRUCT ps;
//const TCHAR progname[] = _T("Шашнахме квест");
//HWND tardis;
////bool key_pressed = false;
//HINSTANCE hInst;
//
//static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//    switch (uMsg) {
//
//    case WM_CREATE: {
//
//
//        SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);
//
//        NOTIFYICONDATA data;
//        ZeroMemory(&data, sizeof(NOTIFYICONDATA));
//
//
//        data.cbSize = sizeof(data);
//        data.hWnd = hWnd;
//        data.uID = 1;          // Можно поставить любой идентификатор, всё равно иконка только одна
//        data.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
//        data.uCallbackMessage = WM_USER_SHELLICON;
//        data.hIcon = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\quest.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        data.uVersion = NOTIFYICON_VERSION;
//
//
//        strcpy(data.szTip, "Шашнахме квест");
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
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "Справка");
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hOptions, "Настройки");
//
//
//        SetMenu(hWnd, hMenubar);
//        CreateWindow(TEXT("BUTTON"), TEXT("КНОПКА"), WS_VISIBLE | WS_CHILD, 200, 100, 250, 150, hWnd, (HMENU)ID_BUTTON, NULL, NULL);
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
//
//    }
//
//    case WM_HSCROLL:
//    {
//
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
//            SetBkColor(hdcStatic, RGB(255, 255, 255));
//
//
//            return (LRESULT)(COLOR_WINDOW + 1);
//
//        }
//
//    }break;
//
//    case WM_PAINT: {
//        hdc = BeginPaint(hWnd, &ps);
//        //ТАК, слушай, , я щас некоторое время не буду говорить, но скоро начну.Но я тут подумал, что смену скинов надо добавить и в остальные подпрограммы.Хотя бы в список эмуляторов
//        FillRect(hdc, &ps.rcPaint, hBrush);
//        /*SetBkMode(hdc, TRANSPARENT);*/
//
//        //BitBlt(hdc, 0, 0, bm., 720, memBit, 0, 0, SRCCOPY);
//
//        EndPaint(hWnd, &ps);
//        //return 0;
//
//    } break;
//
//
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
//    return 0;
//}
//
//
//
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
//    //progicon = (HICON)LoadImage(op.hInstance,"C:\\1\\", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        op.hIcon = progicon;
//
//    //op.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
//    RegisterClass(&op);
//
//
//    CreateWindowEx(WS_EX_LAYERED, op.lpszClassName, "Тестовое окно", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE, 100, 100, 640, 360, NULL, NULL, op.hInstance, NULL);
//    MSG msg;
//    while (GetMessage(&msg, NULL, 0, 0)) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//
//    }
//
//}
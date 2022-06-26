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
//#include <fstream>
//
//
//#pragma comment(lib, "winmm.lib")
//using namespace std;
//
//static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//    switch (uMsg) {
//
//    case WM_CREATE: {
//
//
//
//        SetWindowText(hWnd, ("Инструкция"));
//
//        CreateWindow(TEXT("STATIC"), TEXT("                                                    Для создания сервера                                                                              (1) Заходите в виртуалку, от нее будут доступный пароли и id                                             (2) Узнайте свой ip.Он на фоне рабочего стола.                                                                       (3) Заходите в игру, нажимаете Multiplayer-- 3 вариант, тот что по TCP / IP                          (4) -- ок -- пишете ник -- выбираете карту.                                                                                  (5) Оппоненту сообщаете свой ip адрес.                                                                                   (6) А оппонент заходит к вам уже через свою виртуалку.                                                       (7) Присоединяетесь и играете!"), WS_VISIBLE | WS_CHILD, 10, 20, 600, 540, hWnd, (HMENU)NULL, NULL, NULL);
//         
//    
//        break;
//    }
//    case WM_COMMAND: 
//
//    {
//
//
//        
//
//        break;
//    }
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
//                   return 0;
//    }
//
//
//int WINAPI main()
//{
//    WNDCLASS op;
//    ZeroMemory(&op, sizeof(WNDCLASS));
//    op.lpfnWndProc = wnd_proc;
//    op.hInstance = GetModuleHandle(NULL);
//    op.lpszClassName = "test32cls";
//    op.hCursor = LoadCursor(NULL, IDC_ARROW);
//    op.hbrBackground = CreateSolidBrush(RGB(76,0 ,153));
//    RegisterClass(&op);
//
//
//    CreateWindowA(op.lpszClassName, "Title", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX| WS_VISIBLE, 100, 100, 640, 640, NULL, NULL, op.hInstance, NULL);
//    MSG msg;
//    while (GetMessage(&msg, NULL, 0, 0)) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//
//    }
//
//}
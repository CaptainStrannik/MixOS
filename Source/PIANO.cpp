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
//
//HSTREAM NOTEDO;
//HSTREAM NOTERE;
//HSTREAM NOTEMI;
//HSTREAM NOTEFA;
//HSTREAM NOTESOL;
//HSTREAM NOTELA;
//HSTREAM NOTESI;
//
//HSTREAM NOTEDODI;
//HSTREAM NOTEREDI;
//HSTREAM NOTEFADI;
//HSTREAM NOTESOLDI;
//HSTREAM NOTELADI;
//HSTREAM NOTEDO2;
//HDC hdc;
//PAINTSTRUCT ps;
//HBRUSH hBrush = CreateSolidBrush(RGB(0, 76, 153));
//
//#pragma comment(linker,"/manifestdependency:\"type='win32' \
//                        name='Microsoft.Windows.Common-Controls' \
//                        version='6.0.0.0' processorArchitecture='*'\
// publicKeyToken='6595b64144ccf1df' language='*'\"")
//#pragma comment(lib, "winmm.lib")
//#pragma comment(lib, "bass")
//using namespace std;
//char str1[1024];
//
//static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//    switch (uMsg) {
//
//    case WM_CREATE: {
//
//
//        int a = 120;
//        
//
//        HMENU hMenubar = CreateMenu();
//
//        HMENU hAbout = CreateMenu();
//        HMENU hColor = CreateMenu();
//
//        
//
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "Справка");
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hColor, "Сменить цвет");
//
//        CreateWindow(TEXT("BUTTON"), TEXT("До"), WS_VISIBLE | WS_CHILD, 10+a, 75, 40, 25, hWnd, (HMENU)DO, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("До#"), WS_VISIBLE | WS_CHILD, 35+a, 50, 40, 25, hWnd, (HMENU)DO1, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Ре"), WS_VISIBLE | WS_CHILD, 60+a, 75, 40, 25, hWnd, (HMENU)RE, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Ре#"), WS_VISIBLE | WS_CHILD, 85+a, 50, 40, 25, hWnd, (HMENU)RE1, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Ми"), WS_VISIBLE | WS_CHILD, 104+a, 75, 40, 25, hWnd, (HMENU)MI, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Фа"), WS_VISIBLE | WS_CHILD, 139+a, 75, 40, 25, hWnd, (HMENU)FA, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Фа#"), WS_VISIBLE | WS_CHILD, 160+a, 50, 40, 25, hWnd, (HMENU)FA1, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Соль"), WS_VISIBLE | WS_CHILD, 185+a, 75, 40, 25, hWnd, (HMENU)SOL, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Соль#"), WS_VISIBLE | WS_CHILD, 210+a, 50, 40, 25, hWnd, (HMENU)SOL1, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Ля"), WS_VISIBLE | WS_CHILD, 235+a, 75, 40, 25, hWnd, (HMENU)LA, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Ля#"), WS_VISIBLE | WS_CHILD, 260+a, 50, 40, 25, hWnd, (HMENU)LA1, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Си"), WS_VISIBLE | WS_CHILD, 285+a, 75, 40, 25, hWnd, (HMENU)SI, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("До"), WS_VISIBLE | WS_CHILD, 325+a, 75, 40, 25, hWnd, (HMENU)DO2, NULL, NULL);
//        BASS_Init(-1, 44100, 0, 0, NULL);
//
//
//        SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//
//
//        AppendMenu(hAbout, MF_STRING, STRANNIK, "О программе");
//        AppendMenu(hColor, MF_STRING, MYCOLOR, "Мой цвет");
//
//
//
//
//        SetMenu(hWnd, hMenubar);
//
//
//
//
//    
//        break;
//    }
//    case WM_COMMAND: 
//    {
//        if (LOWORD(wParam) == STRANNIK)
//        {
//            MessageBoxA(hWnd, "Ну, это обычное пианино, для обычных пользователей.", "О программе", MB_OK);
//        }
//
//        if (LOWORD(wParam) == DO)
//        {
//            BASS_StreamFree(NOTEDO);
//            BASS_Stop();
//            BASS_Start();
//            NOTEDO = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\do.mp3", 0, 0, 0);
//            BASS_ChannelPlay(NOTEDO, false); // проигрывание файла
//
//        }
//        if (LOWORD(wParam) == DO1)
//        {
//            BASS_StreamFree(NOTEDODI);
//            BASS_Stop();
//            BASS_Start();
//            NOTEDODI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\do#.mp3", 0, 0, 0);
//            BASS_ChannelPlay(NOTEDODI, false); // проигрывание файла
//
//        }
//        if (LOWORD(wParam) == RE)
//        {
//            BASS_StreamFree(NOTERE);
//            BASS_Stop();
//            BASS_Start();
//            NOTERE = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\re.mp3", 0, 0, 0);
//            BASS_ChannelPlay(NOTERE, false); // проигрывание файла
//
//        }
//        if (LOWORD(wParam) == RE1)
//        {
//            BASS_StreamFree(NOTEREDI);
//            BASS_Stop();
//            BASS_Start();
//            NOTEREDI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\re#.mp3", 0, 0, 0);
//            BASS_ChannelPlay(NOTEREDI, false); // проигрывание файла
//
//        }       
//        if (LOWORD(wParam) == MI)
//        {
//            BASS_StreamFree(NOTEMI);
//            BASS_Stop();
//            BASS_Start();
//            NOTEMI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\mi.mp3", 0, 0, 0);
//            BASS_ChannelPlay(NOTEMI, false); // проигрывание файла
//
//        }
//        if (LOWORD(wParam) == FA)
//        {
//            BASS_StreamFree(NOTEFA);
//            BASS_Stop();
//            BASS_Start();
//            NOTEFA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\fa.mp3", 0, 0, 0);
//            BASS_ChannelPlay(NOTEFA, false); // проигрывание файла
//
//        }
//        if (LOWORD(wParam) == FA1)
//        {
//            BASS_StreamFree(NOTEFADI);
//            BASS_Stop();
//            BASS_Start();
//            NOTEFADI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\fa#.mp3", 0, 0, 0);
//            BASS_ChannelPlay(NOTEFADI, false); // проигрывание файла
//
//        }
//        if (LOWORD(wParam) == SOL)
//
//        {
//            BASS_StreamFree(NOTESOL);
//            BASS_Stop();
//            BASS_Start();
//            NOTESOL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\sol.mp3", 0, 0, 0);
//            BASS_ChannelPlay(NOTESOL, false); // проигрывание файла
//
//        }
//        if (LOWORD(wParam) == SOL1)
//        {
//            BASS_StreamFree(NOTESOLDI);
//            BASS_Stop();
//            BASS_Start();
//            NOTESOLDI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\sol#.mp3", 0, 0, 0);
//            BASS_ChannelPlay(NOTESOLDI, false); // проигрывание файла
//
//        }
//        if (LOWORD(wParam) == LA)
//        {
//            BASS_StreamFree(NOTELA);
//            BASS_Stop();
//            BASS_Start();
//            NOTELA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\la.mp3", 0, 0, 0);
//            BASS_ChannelPlay(NOTELA, false); // проигрывание файла
//
//        }
//
//        if (LOWORD(wParam) == LA1)
//        {
//            BASS_StreamFree(NOTELADI);
//            BASS_Stop();
//            BASS_Start();
//            NOTELADI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\la#.mp3", 0, 0, 0);
//            BASS_ChannelPlay(NOTELADI, false); // проигрывание файла
//
//        }
//        if (LOWORD(wParam) == SI)
//        {
//            BASS_StreamFree(NOTESI);
//            BASS_Stop();
//            BASS_Start();
//            NOTESI = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\si.mp3", 0, 0, 0);
//            BASS_ChannelPlay(NOTESI, false); // проигрывание файла
//
//        }
//        if (LOWORD(wParam) == DO2)
//        {
//            BASS_StreamFree(NOTEDO2);
//            BASS_Stop();
//            BASS_Start();
//            NOTEDO2 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Piano\\do2.mp3", 0, 0, 0);
//            BASS_ChannelPlay(NOTEDO2, false); // проигрывание файла
//
//        }
//        if (LOWORD(wParam) == MYCOLOR)
//        {
//
//            CHOOSECOLOR cc;
//            static COLORREF acrCustClr[16]; // массив доп. цветов
//            static DWORD rgbCurrent;        // начальный выбранный цвет
//
//            ZeroMemory(&cc, sizeof(CHOOSECOLOR));
//            cc.lStructSize = sizeof(CHOOSECOLOR);
//            cc.hwndOwner = hWnd;
//            cc.lpCustColors = (LPDWORD)acrCustClr;
//            cc.rgbResult = rgbCurrent;
//            cc.Flags = CC_FULLOPEN | CC_RGBINIT;
//
//            if (ChooseColor(&cc) == TRUE) {
//                hBrush = CreateSolidBrush(cc.rgbResult);
//                rgbCurrent = cc.rgbResult;
//            }
//
//            InvalidateRect(hWnd, NULL, FALSE);   // ТО АХРИНЕТЬ ОХУЕТЬ ТОЧНЕЕ. Теперь надо такое же добавить в Терминал... И в Пианино... И еще много куда...
//        }
//        break;
//    }
//
//    case WM_PAINT: {
//            hdc = BeginPaint(hWnd, &ps);
//            FillRect(hdc, &ps.rcPaint, hBrush);
//            EndPaint(hWnd, &ps);
//            return 0;
//        }
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
//    //op.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
//    RegisterClass(&op);
//
//
//    CreateWindowA(op.lpszClassName, "Пианино", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX| WS_VISIBLE, 100, 100, 640, 360, NULL, NULL, op.hInstance, NULL);
//    MSG msg;
//    while (GetMessage(&msg, NULL, 0, 0)) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//
//    }
//
//}
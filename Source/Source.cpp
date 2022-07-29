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
//
//
//
//#pragma comment(lib, "winmm.lib")
//#pragma comment(lib, "bass")
//using namespace std;
//char str1[1024];
//LRESULT CALLBACK wnd_proc(HWND hWnd, UINT messg,
//    WPARAM wParam, LPARAM lParam)
//{
//    HDC hdc; //создаём контекст устройства
//    PAINTSTRUCT ps; //создаём экземпляр структуры графического вывода
//    LOGFONT lf;
//    HFONT hFont;
//    RECT r;
//    HBRUSH hBrush;
//    HPEN hPen;
//
//    //Цикл обработки сообщений
//    switch (messg)
//    {
//        //сообщение рисования
//    case WM_PAINT:
//        hdc = BeginPaint(hWnd, &ps);
//
//        //Создаём свой шрифт
//        strcpy_s(lf.lfFaceName, "Segoe UI"); //копируем в строку название шрифта
//        lf.lfHeight = 20;
//        lf.lfItalic = 1;
//        lf.lfStrikeOut = 0;
//        lf.lfUnderline = 0;
//        lf.lfWidth = 10;
//        lf.lfWeight = 40;
//        lf.lfCharSet = DEFAULT_CHARSET; //значение по умолчанию
//        lf.lfPitchAndFamily = DEFAULT_PITCH; //значения по умолчанию
//        lf.lfEscapement = 0;
//
//        hFont = CreateFontIndirect(&lf);
//        SelectObject(hdc, hFont);
//        SetTextColor(hdc, RGB(130, 0, 255));
//        TextOut(hdc, 80, 40, "Привет привет. Это шрифт times new roman", 40);
//
//        //рисуем красный прямоугольник
//        r.top = 300;
//        r.left = 300;
//        r.right = 60;
//        r.bottom = 200;
//        FillRect(hdc, &r, HBRUSH(CreateSolidBrush(RGB(0, 255, 255))));
//
//        //рисуем зелёный эллипс
//        hBrush = CreateSolidBrush(RGB(10, 200, 100));
//        SelectObject(hdc, hBrush);
//        Ellipse(hdc, 20, 100, 200, 200);
//
//        //рисуем закруглённый прямоугольник
//        hBrush = CreateSolidBrush(RGB(250, 200, 100));
//        SelectObject(hdc, hBrush);
//        hPen = CreatePen(2, 2, RGB(0, 0, 255));
//        SelectObject(hdc, hPen);
//        RoundRect(hdc, 20, 250, 250, 350, 15, 15);
//
//
//        ValidateRect(hWnd, NULL);
//        EndPaint(hWnd, &ps);
//        break;
//
//        //сообщение выхода - разрушение окна
//    case WM_DESTROY:
//        PostQuitMessage(0); //Посылаем сообщение выхода с кодом 0 - нормальное завершение
//        break;
//
//    default:
//        return(DefWindowProc(hWnd, messg, wParam, lParam)); //освобождаем очередь приложения от нераспознаных
//    }
//    return 0;  
//}
//
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
//    op.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
//    RegisterClass(&op);
//
//
//    CreateWindowA(op.lpszClassName, "Графика", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 640, 400, NULL, NULL, op.hInstance, NULL);
//    MSG msg;
//    while (GetMessage(&msg, NULL, 0, 0)) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//
//    }
//
//}

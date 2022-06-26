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
//#include <fstream>
//
//
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
//HWND MENUMENUMENU;
//HWND MENUMENUMENU1;
//HWND MENUMENUMENU2;
//HWND MENUMENUMENU3;
//#pragma comment(linker,"/manifestdependency:\"type='win32' \
//                        name='Microsoft.Windows.Common-Controls' \
//                        version='6.0.0.0' processorArchitecture='*'\
// publicKeyToken='6595b64144ccf1df' language='*'\"")
//#pragma comment(lib, "winmm.lib")
//#pragma comment(lib, "bass")
//using namespace std;
//char str1[1024];
//
//HDC hdc; //создаём контекст устройства
//PAINTSTRUCT ps; //создаём экземпляр структуры графического вывода
//
//HBRUSH hBrush = CreateSolidBrush(RGB(0, 139, 139));
//
//static COLORREF acrCustClr[16]; // массив доп. цветов
//static DWORD rgbCurrent;        // начальный выбранный цвет
//
//
//static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//    switch (uMsg) {
//
//    case WM_CREATE: {
//
//
//        int a = 140;
//        SetWindowText(hWnd, (""));
//
//        HMENU hMenubar = CreateMenu();
//
//        HMENU hAbout = CreateMenu();
//        HMENU hColor = CreateMenu();
//
//
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "Справка");
//
//        CreateWindow(TEXT("BUTTON"), TEXT("Сломать ПК"), WS_VISIBLE | WS_CHILD, 10, 10, 100, 25, hWnd, (HMENU)BREAKPC, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Удалить ненужный софт"), WS_VISIBLE | WS_CHILD, 430, 10, 190, 25, hWnd, (HMENU)BOMB, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Отлючить шпионаж в Windows 8-11"), WS_VISIBLE | WS_CHILD, 170, 10, 250, 25, hWnd, (HMENU)SPY, NULL, NULL);
//        //CreateWindow(TEXT("BUTTON"), TEXT("Поиграть в UA"), WS_VISIBLE | WS_CHILD, 210 + a, 75, 100, 25, hWnd, (HMENU)UA, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Не трогай меня"), WS_VISIBLE | WS_CHILD, 120 + a, 103, 105, 25, hWnd, (HMENU)DONTTOUCHME, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Сделать свое контекстное меню"), WS_VISIBLE | WS_CHILD, 45 + a, 130, 240, 25, hWnd, (HMENU)MENUMAKER, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Удалить свое контекстное меню"), WS_VISIBLE | WS_CHILD, 45 + a, 130+40, 240, 25, hWnd, (HMENU)DELMAKE, NULL, NULL);
//
//        BASS_Init(-1, 44100, 0, 0, NULL);
//
//
//        SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//
//   
//        AppendMenu(hAbout, MF_STRING, STRANNIK, "О программе");
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hColor, "Сменить цвет");
//        AppendMenu(hColor, MF_STRING, COLORMENUMAKE, "Мой цвет");
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
//
//    {
//
//        ofstream Strannik;
//        int len5;
//        int len6;
//        int len7;
//        int len8;
//        TCHAR Name[1200];
//        TCHAR NameName[1200];
//        TCHAR EXECUTION[1200];
//        TCHAR IconName[1200];
//        len8 = GetWindowText(MENUMENUMENU3, IconName, 1200);
//        len7 = GetWindowText(MENUMENUMENU2, Name, 1200);
//        len5 = GetWindowText(MENUMENUMENU, NameName, 1200);    //Название
//        len6 = GetWindowText(MENUMENUMENU1, EXECUTION, 1200);  //Действие
//        if (LOWORD(wParam) == STRANNIK)
//        {
//            MessageBoxA(hWnd, "Эта программка позволяет удобно\nпод себя настроить контекстное меню\nв Windows. Здесь вы сможете сделать\nсвои пункты контекстного меню", "Контекстменюмейкер", MB_ICONASTERISK);
//        }
//        if (LOWORD(wParam) == DONTTOUCHME)
//        {
//            int a = 140;
//            ShowWindow(GetDlgItem(hWnd, DONTTOUCHME), SW_HIDE);
//            CreateWindow(TEXT("BUTTON"), TEXT("Мне же больно!"), WS_VISIBLE | WS_CHILD, 120 + a, 50, 110, 25, hWnd, (HMENU)DONTTOUCHME1, NULL, NULL);
//        }
//        if (LOWORD(wParam) == DONTTOUCHME1)
//        {
//            int a = 140;
//            ShowWindow(GetDlgItem(hWnd, DONTTOUCHME1), SW_HIDE);
//            CreateWindow(TEXT("BUTTON"), TEXT("МОЖЕТ ХВАТИТ!"), WS_VISIBLE | WS_CHILD, 10, 110, 120, 25, hWnd, (HMENU)DONTTOUCHME2, NULL, NULL);
//        }
//        if (LOWORD(wParam) == DONTTOUCHME2)
//        {
//            int a = 140;
//            ShowWindow(GetDlgItem(hWnd, DONTTOUCHME2), SW_HIDE);
//            CreateWindow(TEXT("BUTTON"), TEXT("Сам напросился!"), WS_VISIBLE | WS_CHILD, 120 + a, 50, 110, 25, hWnd, (HMENU)DONTTOUCHME3, NULL, NULL);
//        }
//        if (LOWORD(wParam) == DONTTOUCHME3)
//        {
//            int a = 140;
//            ShowWindow(GetDlgItem(hWnd, DONTTOUCHME3), SW_HIDE);
//            CreateWindow(TEXT("BUTTON"), TEXT("Я тут!"), WS_VISIBLE | WS_CHILD, 115, 10, 50, 25, hWnd, (HMENU)DONTTOUCHME4, NULL, NULL);
//        }
//        if (LOWORD(wParam) == DONTTOUCHME4)
//        {
//            int a = 140;
//            ShowWindow(GetDlgItem(hWnd, DONTTOUCHME4), SW_HIDE);
//            CreateWindow(TEXT("BUTTON"), TEXT("ЕРМАКЛОООООП"), WS_VISIBLE | WS_CHILD, 120 + a, 50, 130, 25, hWnd, (HMENU)DONTTOUCHME5, NULL, NULL);
//        }
//        if (LOWORD(wParam) == DONTTOUCHME5)
//        {
//            int a = 140;
//            ShowWindow(GetDlgItem(hWnd, DONTTOUCHME5), SW_HIDE);
//            CreateWindow(TEXT("BUTTON"), TEXT("ТЫК"), WS_VISIBLE | WS_CHILD, 115, 10, 50, 25, hWnd, (HMENU)BREAKPC1, NULL, NULL);
//            system("start https://www.youtube.com/c/dan55800");
//        }
//        if (LOWORD(wParam) == BREAKPC)
//        {
//            int a = 140;
//            MessageBoxA(hWnd, "Эта штука реально вырубит винду. И Будет BSOD после еще одного нажатия на эту кнопку!!!", "Внимание!!!", MB_ICONINFORMATION);
//            ShowWindow(GetDlgItem(hWnd, BREAKPC), SW_HIDE);
//            CreateWindow(TEXT("BUTTON"), TEXT("Сломать ПК!"), WS_VISIBLE | WS_CHILD, 10, 10, 100, 25, hWnd, (HMENU)BREAKPC1, NULL, NULL);
//
//        }
//        if (LOWORD(wParam) == BREAKPC1)
//        {
//            system("powershell wininit");
//        }
//        if (LOWORD(wParam) == SPY)
//        {
//            system("start MusicPlayer\\Progs\\SHUTUP\\KILLSPY.exe");
//            return 0;
//        }
//        if (LOWORD(wParam) == BOMB)
//        {
//            system("start MusicPlayer\\Progs\\REVO\\RevoUnin.exe");
//        }
//        if (LOWORD(wParam) == MENUMAKER)
//        {
//            int a = 140;
//            ShowWindow(GetDlgItem(hWnd, DELMAKE), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MENUMAKER), SW_HIDE);
//            MENUMENUMENU2 = CreateWindow(TEXT("EDIT"), TEXT("Любое название раздела на инглише"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE, 170, 190, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
//            MENUMENUMENU3 = CreateWindow(TEXT("EDIT"), TEXT("Путь к icon(например C:\\\\windows\\\\icon.ico)"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE, 170, 270, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
//            MENUMENUMENU = CreateWindow(TEXT("EDIT"), TEXT("Напишите название пункта меню"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE, 10, 500, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
//            MENUMENUMENU1 = CreateWindow(TEXT("EDIT"), TEXT("Команда,например C:\\\\windows\\\\explorer.exe"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE, 315, 500, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
//            CreateWindow(TEXT("BUTTON"), TEXT("Сделать"), WS_VISIBLE | WS_CHILD, 120 + a, 360, 100, 25, hWnd, (HMENU)MAKEMAKE, NULL, NULL);
//
//        }
//        if (LOWORD(wParam) == DELMAKE)
//        {
//            int a = 140;
//            ShowWindow(GetDlgItem(hWnd, DELMAKE), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MENUMAKER), SW_HIDE);
//            MENUMENUMENU2 = CreateWindow(TEXT("EDIT"), TEXT("Название удаляемого раздела на инглише"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE, 170, 190, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
//           // MENUMENUMENU3 = CreateWindow(TEXT("EDIT"), TEXT("Путь к icon(например C:\\\\windows\\\\icon.ico)"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE, 170, 270, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
//           // MENUMENUMENU = CreateWindow(TEXT("EDIT"), TEXT("Напишите название пункта меню"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE, 10, 500, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
//            //MENUMENUMENU1 = CreateWindow(TEXT("EDIT"), TEXT("Та команда, что вы вводили"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE, 315, 500, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
//            CreateWindow(TEXT("BUTTON"), TEXT("Удалить"), WS_VISIBLE | WS_CHILD, 120 + a, 360, 100, 25, hWnd, (HMENU)DELMAKE1, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Открыть список введенных имен"), WS_VISIBLE | WS_CHILD, 45 + a, 130 , 240, 25, hWnd, (HMENU)MAKEMAKENAMES, NULL, NULL);
//
//        }
//        if (LOWORD(wParam) == DELMAKE1)
//        {
//            ofstream Proga;
//            string text2 = Name;
//            string text1 = NameName;
//            string text = EXECUTION;
//            string text3 = IconName;
//            Proga.open("MusicPlayer\\MENUMAKER\\tmp\\reg.reg");
//            Proga << "Windows Registry Editor Version 5.00" << endl << endl;
//            Proga << "[-HKEY_CLASSES_ROOT\\DesktopBackground\\Shell\\" << Name << "]" << endl;
//            Proga.close();
//            system("regedit /f MusicPlayer\\MENUMAKER\\tmp\\reg.reg");
//            system("del MusicPlayer\\MENUMAKER\\tmp\\reg.reg");
//        }
//        if (LOWORD(wParam) == MAKEMAKE)
//        {
//            ofstream Proga;
//            string text2 = Name;
//            string text1 = NameName;
//            string text = EXECUTION;
//            string text3 = IconName;
//            Proga.open("MusicPlayer\\MENUMAKER\\tmp\\reg.reg");
//            Proga << "Windows Registry Editor Version 5.00" << endl << endl; 
//            Proga << "[HKEY_CLASSES_ROOT\\DesktopBackground\\Shell\\" << Name << "]" << endl;
//            Proga <<"\"\MUIVerb\"=" <<"\"" << NameName << "\"" << endl;
//            Proga << "\"\Icon\"=" << "\"" << IconName << "\"" << endl;
//            Proga << endl;
//            Proga << "[HKEY_CLASSES_ROOT\\DesktopBackground\\Shell\\"<<Name<<"\\command]" << endl;
//            Proga << "@" << "=" << "\""  << EXECUTION << "\"" << endl;
//            Proga.close();
//            system("regedit /f MusicPlayer\\MENUMAKER\\tmp\\reg.reg");
//            system("del MusicPlayer\\MENUMAKER\\tmp\\reg.reg");
//        }
//
//        if (LOWORD(wParam) == MAKEMAKE)
//        {
//            ofstream SPISOK;
//            string text2 = Name;
//            SPISOK.open("MusicPlayer\\MENUMAKER\\tmp\\SPISOK.txt",ios::app);
//            SPISOK<<"Name of section which you have wroten : "<<Name << endl;
//            SPISOK << "Command which you have wroten: "<<EXECUTION << endl;
//            SPISOK<<"\n";
//            SPISOK.close();
//
//
//        }
//        if (LOWORD(wParam) == MAKEMAKENAMES)
//        {
//            system("start notepad MusicPlayer\\MENUMAKER\\tmp\\SPISOK.txt");
//        }
//        if (LOWORD(wParam) == COLORMENUMAKE)
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
//                hBrush = CreateSolidBrush(cc.rgbResult);
//                rgbCurrent = cc.rgbResult;
//            }
//
//            InvalidateRect(hWnd, NULL, FALSE);   // ТО АХРИНЕТЬ ОХУЕТЬ ТОЧНЕЕ. Теперь надо такое же добавить в Терминал... И в Пианино... И еще много куда...
//        }
//
//        break;
//    }
//
//    case WM_PAINT: {
//        hdc = BeginPaint(hWnd, &ps);
//        FillRect(hdc, &ps.rcPaint, hBrush);
//        EndPaint(hWnd, &ps);
//    } break;
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
//    RegisterClass(&op);
//
//
//    CreateWindowA(op.lpszClassName, "Контекстменюмейкер ver 1.0", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE, 100, 100, 640, 640, NULL, NULL, op.hInstance, NULL);
//    MSG msg;
//    while (GetMessage(&msg, NULL, 0, 0)) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//
//    }
//
//}
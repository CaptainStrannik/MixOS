//#include <windows.h>
//#include <cstring>
//#include <cstdlib> //для работы system
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
////#include <uxtheme.h>
////#include <vssym32.h>
//
////#pragma comment(lib, "uxtheme.lib")
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
//HWND eMp3;
//int skins;
//HANDLE bmpwall;
//HANDLE bmpwall1;
//HWND hwall;
//TCHAR StrT[MAX_PATH];
//
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
//HDC hdc; //создаём контекст устройства
//PAINTSTRUCT ps; //создаём экземпляр структуры графического вывода
//
//HBRUSH hBrush = CreateSolidBrush(RGB(0, 139, 139));
//
//const TCHAR progname[] = "Контекстменюмейкер ver 1.0";
//HICON progicon;
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
//        SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);
//
//
//
//        NOTIFYICONDATA data;
//        ZeroMemory(&data, sizeof(NOTIFYICONDATA));
//
//
//
//
//
//
//        data.cbSize = sizeof(data);
//        data.hWnd = hWnd;
//        data.uID = 1;          // Можно поставить любой идентификатор, всё равно иконка только одна
//        data.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
//        data.uCallbackMessage = WM_USER_SHELLICON;
//        data.hIcon = progicon;
//        data.uVersion = NOTIFYICON_VERSION;
//
//        /*     strcpy(data.szInfoTitle, "Загрузчик видео с Youtube");*/
//        strcpy(data.szTip, progname);
//
//        Shell_NotifyIcon(NIM_ADD, &data);
//
//
//
//
//        int a = 140;
//
//        HMENU hMenubar = CreateMenu();
//
//        HMENU hAbout = CreateMenu();
//        HMENU hColor = CreateMenu();
//
//
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "Справка");
//        eMp3 = CreateWindow(TEXT("Edit"), NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD, 120, 50, 1000 + 30, 20, hWnd, (HMENU)SKINSSTRO, NULL, 0);
//        CreateWindow(TEXT("BUTTON"), TEXT("Сломать ПК"), WS_VISIBLE | WS_CHILD, 10, 10, 100, 25, hWnd, (HMENU)BREAKPC, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Удалить ненужный софт"), WS_VISIBLE | WS_CHILD|WS_DISABLED, 430, 10, 190, 25, hWnd, (HMENU)BOMB, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Отлючить шпионаж в Windows 8-11"), WS_VISIBLE | WS_CHILD|WS_DISABLED, 170, 10, 250, 25, hWnd, (HMENU)SPY, NULL, NULL);
//        //CreateWindow(TEXT("BUTTON"), TEXT("Поиграть в UA"), WS_VISIBLE | WS_CHILD, 210 + a, 75, 100, 25, hWnd, (HMENU)UA, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Не трогай меня"), WS_VISIBLE | WS_CHILD, 120 + a, 103, 105, 25, hWnd, (HMENU)DONTTOUCHME, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Сделать свое контекстное меню"), WS_VISIBLE | WS_CHILD, 45 + a, 130, 240, 25, hWnd, (HMENU)MENUMAKER, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Удалить свое контекстное меню"), WS_VISIBLE | WS_CHILD, 45 + a, 130+40, 240, 25, hWnd, (HMENU)DELMAKE, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), _T("Выключить монитор"), WS_VISIBLE | WS_CHILD, 45+a, 130+40+40, 240, 25, hWnd, (HMENU)TURNOFF, NULL, NULL);
//        
//
//        BASS_Init(-1, 44100, 0, 0, NULL);
//
//
//        SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//
//   
//        AppendMenu(hAbout, MF_STRING, STRANNIK, "О программе");
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hColor, "Настройки");
//
//        AppendMenu(hColor, MF_STRING, COLORMENUMAKE, "Мой цвет");
//        AppendMenu(hColor, MF_STRING, SETBKG, "Мой скин");
//        AppendMenu(hColor, MF_SEPARATOR, NULL, NULL);
//        AppendMenu(hColor, MF_STRING, polupon, "Включить полупрозрачность");
//        AppendMenu(hColor, MF_STRING, polupoff, "Выключить полупрозрачность");
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
//
//
//
//
//
//
//
//
//
//        if (LOWORD(wParam) == polupon)
//        {
//
//            SetLayeredWindowAttributes(hWnd, NULL, 230, LWA_ALPHA);
//        }
//        if (LOWORD(wParam) == polupoff)
//        {
//
//            SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);
//        }
//
//
//
//
//
//        if (LOWORD(wParam) == STRANNIK)
//        {
//            ShellAbout(hWnd, progname, "Разработчик: Captain Strannik, Помощник: Z_Kraf1er_Z", progicon);
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
//            ShowWindow(GetDlgItem(hWnd, TURNOFF), SW_HIDE);
//            MENUMENUMENU2 = CreateWindow(TEXT("EDIT"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL , 170, 190, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
//            MENUMENUMENU3 = CreateWindow(TEXT("EDIT"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL , 170, 270, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
//            MENUMENUMENU = CreateWindow(TEXT("EDIT"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL , 10, 500, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
//            MENUMENUMENU1 = CreateWindow(TEXT("EDIT"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL , 315, 500, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
//            CreateWindow(TEXT("BUTTON"), TEXT("Сделать"), WS_VISIBLE | WS_CHILD, 120 + a, 360, 100, 25, hWnd, (HMENU)MAKEMAKE, NULL, NULL);
//
//            SendMessage(MENUMENUMENU2, EM_SETCUEBANNER, 0, (LPARAM)L"Любое название раздела на инглише");
//            SendMessage(MENUMENUMENU3, EM_SETCUEBANNER, 0, (LPARAM)L"Путь к icon(например C:\\\\windows\\\\icon.ico");
//            SendMessage(MENUMENUMENU, EM_SETCUEBANNER, 0, (LPARAM)L"Напишите название пункта меню");
//            SendMessage(MENUMENUMENU1, EM_SETCUEBANNER, 0, (LPARAM)L"Команда,например C:\\\\windows\\\\explorer.exe");
//            
//        }
//        if (LOWORD(wParam) == DELMAKE)
//        {
//            int a = 140;
//            ShowWindow(GetDlgItem(hWnd, DELMAKE), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MENUMAKER), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, TURNOFF), SW_HIDE);
//            MENUMENUMENU2 = CreateWindow(TEXT("EDIT"), NULL, WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL, 170, 190, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
//            SendMessage(MENUMENUMENU2, EM_SETCUEBANNER, 0, (LPARAM)L"Название удаляемого раздела на инглише");
//            // MENUMENUMENU3 = CreateWindow(TEXT("EDIT"), TEXT("Путь к icon(например C:\\\\windows\\\\icon.ico)"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE, 170, 270, 300, 70, hWnd, (HMENU)WRITING, NULL, 0);
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
//            string text9 = NameName;
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
//            string text9 = NameName;
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
//                if (LOWORD(wParam) == COLORMENUMAKE)
//                {
//                    
//                    CHOOSECOLOR cc;
//        
//                    ZeroMemory(&cc, sizeof(CHOOSECOLOR));
//                    cc.lStructSize = sizeof(CHOOSECOLOR);
//                    cc.hwndOwner = hWnd;
//                    cc.lpCustColors = (LPDWORD)acrCustClr;
//                    cc.rgbResult = rgbCurrent;
//                    cc.Flags = CC_FULLOPEN | CC_RGBINIT;
//        
//                    if (ChooseColor(&cc) == TRUE) {
//                        bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
//                        SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);
//        
//                        hBrush = CreateSolidBrush(cc.rgbResult);
//                        rgbCurrent = cc.rgbResult;
//        
//        
//                    }
//                    else
//                    {
//        
//                        /*   bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
//                           SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);*/
//                        hBrush = CreateSolidBrush(RGB(0, 76, 153));
//                        rgbCurrent = RGB(0, 76, 153);
//                        return 0;
//                    };
//        
//        
//                    InvalidateRect(hWnd, NULL, FALSE);
//        
//                      // ТО АХРИНЕТЬ ОХУЕТЬ ТОЧНЕЕ. Теперь надо такое же добавить в Терминал... И в Пианино... И еще много куда...
//                }
//
//
//
//
//                if (LOWORD(wParam) == SETBKG)
//        {
//            
//          
//            ShowWindow(GetDlgItem(hWnd, SKINSSTRO), SW_HIDE);
//            OPENFILENAME ofnn;
//
//            ZeroMemory(&ofnn, sizeof(OPENFILENAME));
//            ofnn.lStructSize = sizeof(OPENFILENAME);
//            ofnn.hwndOwner = hWnd;
//            ofnn.lpstrFile = str1;
//            ofnn.nMaxFile = sizeof(str1);
//            
//            ofnn.nFilterIndex = 1;
//            ofnn.lpstrFileTitle = NULL;
//            ofnn.nMaxFileTitle = 0;
//            //ofn.lpstrInitialDir = ".";
//            ofnn.lpstrInitialDir = "MusicPlayer\\BMP\\MIXMENU";
//            ofnn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_DONTADDTORECENT | OFN_NOCHANGEDIR;   //Бага больше нет!  А я пока отойду.
//
//            if (GetOpenFileName(&ofnn) == TRUE)
//            {
//                SetWindowText(eMp3, str1);
//
//                DestroyWindow(hwall);
//                DestroyWindow(GetDlgItem(hWnd, INSTBKG));
//                ShowWindow(GetDlgItem(hWnd, SKINSSTRO), SW_HIDE);
//
//                ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
//
//                skins = GetWindowText(eMp3, StrT, MAX_PATH);
//                bmpwall = LoadImage(NULL, StrT, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
//                bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
//
//                if (bmpwall != NULL);
//                {
//
//                    hwall = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);
//                    SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);
//                    SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall);
//
//                }
//                /*CreateWindow(TEXT("BUTTON"), TEXT("Установить"), WS_VISIBLE | WS_CHILD, 460, 500, 300, 70, hWnd, (HMENU)INSTBKG, NULL, NULL);*/
//            }
//            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_HIDE);
//            
//        }
//
//
//
//        if (LOWORD(wParam) == TURNOFF) {
//            SendMessage(hWnd, WM_SYSCOMMAND, SC_MONITORPOWER, 2);
//            SetTimer(hWnd, POWER_ON_TIMER, 5000, NULL);
//            
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
//    case WM_TIMER: {
//        if (wParam == POWER_ON_TIMER)
//            KillTimer(hWnd, POWER_ON_TIMER);
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
// 
//    SetProcessDPIAware();
//    WNDCLASS op;
//    ZeroMemory(&op, sizeof(WNDCLASS));
//    op.lpfnWndProc = wnd_proc;
//    op.hInstance = GetModuleHandle(NULL);
//    op.lpszClassName = "test32cls";
//    op.hCursor = LoadCursor(NULL, IDC_ARROW);
//    progicon = (HICON)LoadImage(op.hInstance, "MusicPlayer\\BMP\\ico\\menumaker.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//    op.hIcon = progicon;
//    RegisterClass(&op);
//
//    CreateWindowEx(WS_EX_LAYERED,op.lpszClassName, progname, WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE, 100, 100, 640, 640, NULL, NULL, op.hInstance, NULL);
//    MSG msg;
//    while (GetMessage(&msg, NULL, 0, 0)) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//
//    }
//
//}
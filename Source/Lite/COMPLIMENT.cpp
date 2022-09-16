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
//const TCHAR progname[] = _T("Комплимент");
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
//        data.uID = 1;          // Можно поставить любой идентификатор, всё равно иконка только одна
//        data.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
//        data.uCallbackMessage = WM_USER_SHELLICON;
//        data.hIcon = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\quest.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        data.uVersion = NOTIFYICON_VERSION;
//
//        /*     strcpy(data.szInfoTitle, "Загрузчик видео с Youtube");*/
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
//
//        SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//        AppendMenu(hAbout, MF_STRING, STRANNIK, "О программе");
//        AppendMenu(hAbout, MF_STRING, STRANNI, "Шашнахме");
//
//
//        AppendMenu(hOptions, MF_STRING, MYCOLOR, "Сменить цвет");
//
//        SetMenu(hWnd, hMenubar);
//        BASS_Init(-1, 44100, 0, 0, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Начать"), WS_VISIBLE | WS_CHILD, 200, 100, 250, 150, hWnd, (HMENU)ID_BUTTON, NULL, NULL);
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
//            ShellAbout(hWnd, progname, "Разработчик: Captain Strannik", progicon);
//            MessageBoxA(hWnd, "Эта программа для поднятия самооценки и настроения,\n но пока что только для прекрасных девушек =).\nЭта программа пытается отражать истинные чувства\nразработчика к общению и отношению между людьми.\nЕсли вдруг, эта программа вас обидела, дайте ей в нос и сообщите мне =).", "О программе", MB_OK);
//        }
//        if (LOWORD(wParam) == ID_BUTTON)
//        {
//
//            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//            BASS_Stop();
//            BASS_Start();
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//
//            CreateWindow(TEXT("STATIC"), TEXT("Для начала напиши своё имя"), WS_VISIBLE | WS_CHILD, 150 + 50, 50, 230, 20, hWnd, (HMENU)text1, NULL, NULL);
//
//            LOVE = CreateWindow(TEXT("Edit"), NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE, 120 + 70, 150, 220, 20, hWnd, (HMENU)SKINSSTRO, NULL, 0);
//
//            CreateWindow(TEXT("BUTTON"), TEXT("Написала"), WS_VISIBLE | WS_CHILD, 220, 180, 150, 30, hWnd, (HMENU)GIRLNAME, NULL, NULL);
//
//
//            //SetWindowLong(hWnd, GWL_STYLE, WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE);
//            //CreateWindow(_T("STATIC"), _T("Не для шашнахме"), WS_VISIBLE | WS_CHILD, 650, 60, 150, 20, hWnd, (HMENU)text1, NULL, NULL);
//            //tardis = CreateWindow(_T("LISTBOX"), _T("Телепортер 3000"), WS_CHILD | LBS_HASSTRINGS | LBS_WANTKEYBOARDINPUT | WS_VSCROLL|WS_VISIBLE, 650, 100, 120, 150, hWnd, NULL, NULL, NULL);
//            //CreateWindow(_T("BUTTON"), _T("Телепортация"), WS_CHILD | WS_VISIBLE, 650, 270, 120, 22, hWnd, (HMENU)TELEPORT, NULL, NULL);
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
//            CreateWindow(TEXT("STATIC"), TEXT("Привет, "), WS_VISIBLE | WS_CHILD, 150, 50, 60, 20, hWnd, (HMENU)text1, NULL, NULL);
//            CreateWindow(TEXT("STATIC"), TEXT(StrB), WS_VISIBLE | WS_CHILD, 150 + 50 + 5, 50, 60, 20, hWnd, (HMENU)text1, NULL, NULL);
//            LOVE = CreateWindow(TEXT("Edit"), NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE, 120 + 70, 150, 220, 20, hWnd, (HMENU)SKINSSTRO, NULL, 0);
//            MessageBoxA(hWnd, "Возможно рифма груба, а речь моя скудна.\nНо зато она пред тобою честна\nСкажу пару слов тебе, цыпа.\nБез чувства юмора сложно жить, типа.", "Признание в любви?", MB_ICONINFORMATION);
//            MessageBoxA(hWnd, "Неважно, как тебя зовут, что ты чувствуешь, важнее.\nСамое главное не сбиться с пути\nИ не бросить свои увлеченья\nПризванье свое надо в жизни найти\nИ получать от него настроенье.\n <<Разумеется, помнить мои поучения =)>>", "Признание в любви?", MB_ICONINFORMATION);
//            MessageBoxA(hWnd, "Ладно, устал болтать стихами, сейчас просто поговорим.\nЯ буду задавать вопросики, а ты отвечай.\nИ я узнаю о тебе немного больше, помогу с самооцекой.\nРаздам тебе пару комплиментиков.\nНу, и, разумеется, выложу все данные в ПЕНТАГОН.", "Признание в любви?", MB_ICONINFORMATION);
//            CreateWindow(TEXT("STATIC"), TEXT("Тебе грустно? ДА/НЕТ?"), WS_VISIBLE | WS_CHILD, 150 + 50 + 5 + 60, 50, 180, 20, hWnd, (HMENU)text1, NULL, NULL);
//            len = GetWindowText(LOVE, StrB, 1200);
//            CreateWindow(TEXT("BUTTON"), TEXT("Сказать"), WS_VISIBLE | WS_CHILD, 220, 180, 150, 30, hWnd, (HMENU)QUESTION2, NULL, NULL);
//        }
//
//        if (LOWORD(wParam) == QUESTION2)
//        {
//            string text = StrB;
//
//
//            if (text == "ДА")
//            {
//                LOVE = CreateWindow(TEXT("Edit"), NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE, 120 + 70, 150, 220, 20, hWnd, (HMENU)SKINSSTRO, NULL, 0);
//                MessageBoxA(hWnd, "Вспомни, кто ты на самом деле. Я не знаю, конечно, как у тебя дела, но как минимум, ты сейчас дома.\nНу по моим расчетам =). Выглядишь отлично, просто видимо не до конца в это веришь, наверное.\nНо в этом мире почти со 100% шансом найдется человек, который будет тебя достоин и вы оба будете друг друга любить.\nТвоя судьба сама тебя найдет, а может и уже нашла =). ", "Разбор проблемы 1", MB_ICONINFORMATION);
//                CreateWindow(TEXT("STATIC"), TEXT("Тебе одиноко? ДА/НЕТ?"), WS_VISIBLE | WS_CHILD, 150 + 50 + 5 + 60, 50, 180, 20, hWnd, (HMENU)text1, NULL, NULL);
//                len = GetWindowText(LOVE, StrB, 1200);
//                ShowWindow(GetDlgItem(hWnd, QUESTION1), SW_HIDE);
//                CreateWindow(TEXT("BUTTON"), TEXT("Сказать"), WS_VISIBLE | WS_CHILD, 220, 180, 150, 30, hWnd, (HMENU)QUESTION3, NULL, NULL);
//            }
//            if (text == "НЕТ")
//            {
//                LOVE = CreateWindow(TEXT("Edit"), NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE, 120 + 70, 150, 220, 20, hWnd, (HMENU)SKINSSTRO, NULL, 0);
//                CreateWindow(TEXT("STATIC"), TEXT("Тебе одиноко? ДА/НЕТ?"), WS_VISIBLE | WS_CHILD, 150 + 50 + 5 + 60, 50, 180, 20, hWnd, (HMENU)text1, NULL, NULL);
//                len = GetWindowText(LOVE, StrB, 1200);
//                CreateWindow(TEXT("BUTTON"), TEXT("Сказать"), WS_VISIBLE | WS_CHILD, 220, 180, 150, 30, hWnd, (HMENU)QUESTION3, NULL, NULL);
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
//        //    if (StrB == "ДА")
//        //    {
//        //        MessageBoxA(hWnd, "Не переживай по этому поводу.\n", "Разбор проблемы 2", MB_ICONINFORMATION);
//        //        CreateWindow(TEXT("STATIC"), TEXT("Тебе одиноко? ДА/НЕТ?"), WS_VISIBLE | WS_CHILD, 150 + 50 + 5 + 60, 50, 180, 20, hWnd, (HMENU)text1, NULL, NULL);
//        //        len = GetWindowText(LOVE, StrB, 1200);
//        //        CreateWindow(TEXT("BUTTON"), TEXT("Сказать"), WS_VISIBLE | WS_CHILD, 220, 180, 150, 30, hWnd, (HMENU)QUESTION2, NULL, NULL);
//        //    }
//        //    if (StrB == "НЕТ")
//        //    {
//        //        CreateWindow(TEXT("STATIC"), TEXT("Тебе одиноко? ДА/НЕТ?"), WS_VISIBLE | WS_CHILD, 150 + 50 + 5 + 60, 50, 180, 20, hWnd, (HMENU)text1, NULL, NULL);
//        //        len = GetWindowText(LOVE, StrB, 1200);
//        //        CreateWindow(TEXT("BUTTON"), TEXT("Сказать"), WS_VISIBLE | WS_CHILD, 220, 180, 150, 30, hWnd, (HMENU)QUESTION2, NULL, NULL);
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
//              // ТО АХРИНЕТЬ ОХУЕТЬ ТОЧНЕЕ. Теперь надо такое же добавить в Терминал... И в Пианино... И еще много куда...
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
//                //ТАК, слушай, , я щас некоторое время не буду говорить, но скоро начну.Но я тут подумал, что смену скинов надо добавить и в остальные подпрограммы.Хотя бы в список эмуляторов
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
//    CreateWindowA(op.lpszClassName, "Комплимент", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE, 100, 100, 640, 360, NULL, NULL, op.hInstance, NULL);
//    MSG msg;
//    while (GetMessage(&msg, NULL, 0, 0)) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//
//    }
//
//}
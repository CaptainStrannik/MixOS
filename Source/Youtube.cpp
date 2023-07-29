//#include <windows.h>
//#include <cstring>
//#include <cstdlib>                   
//#include <urlmon.h>
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
//#include <afx.h>
//#define YT 8192
//
//HWND MENUMENUMENU;
//HWND MENUMENUMENU1;
//HWND MENUMENUMENU2;
//HWND MENUMENUMENU3;
//HSTREAM YOUTUBER;
//HWND eMp3;
//int skins;
//HANDLE bmpwall;
//HANDLE bmpwall1;
//HWND hwall;
//TCHAR StrT[MAX_PATH];
//static COLORREF acrCustClr[16];
//#pragma comment(linker,"/manifestdependency:\"type='win32' \
//                        name='Microsoft.Windows.Common-Controls' \
//                        version='6.0.0.0' processorArchitecture='*'\
// publicKeyToken='6595b64144ccf1df' language='*'\"")
//#pragma comment(lib, "winmm.lib")
//#pragma comment(lib, "bass")
//#pragma comment (lib, "urlmon.lib")
//using namespace std;
//char str1[1024];
//int a = 140;
//HDC hdc;
//PAINTSTRUCT ps;
//HBRUSH hBrush = CreateSolidBrush(RGB(76,0 ,153));
//HWND hTrack;
//HINSTANCE hInst;
//HICON progicon;
//
//const TCHAR progname[] = "Загрузчик видео с ютуба ver 1.11";
//
////теперь нет звука =)
//static DWORD rgbCurrent = RGB(76,0,153);
//
//static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//    switch (uMsg) {
//
//    case WM_CREATE: {
//        //HINSTANCE hInst = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);
//        //HICON hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\MixOS.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        eMp3 = CreateWindow(TEXT("Edit"), NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD, 120, 50, 1000 + 30, 20, hWnd, (HMENU)SKINSSTRO, NULL, 0);
//        
//
//        HMENU hMenubar = CreateMenu();
//
//        HMENU hAbout = CreateMenu();
//        HMENU hColorYT = CreateMenu();
//        HMENU hOption = CreateMenu();
//
//        NOTIFYICONDATA data;
//        ZeroMemory(&data, sizeof(NOTIFYICONDATA));
//
//        HINSTANCE hInst = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);
//
// 
//        HICON hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\MixOS.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//
//
//        CreateWindow(TEXT("BUTTON"), TEXT("Написать разработчику"), WS_VISIBLE | WS_CHILD, 80 + a, 390, 180, 25, hWnd, (HMENU)MAIL, NULL, NULL);
//        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\MixOS.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        SendMessage(GetDlgItem(hWnd, MAIL), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);
//        ShowWindow(GetDlgItem(hWnd,MAIL),SW_HIDE);
//
//
//        SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);
// 
//
//        data.cbSize = sizeof(data);
//        data.hWnd = hWnd;
//        data.uID = 1;          // Можно поставить любой идентификатор, всё равно иконка только одна
//        data.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
//        data.uCallbackMessage = WM_USER_SHELLICON;
//        data.hIcon = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Youtube.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        data.uVersion = NOTIFYICON_VERSION;
//        
// 
//        strcpy(data.szTip, "Загрузчик видео с Youtube");
//
//        Shell_NotifyIcon(NIM_ADD, &data);
//
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "Справка");
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hColorYT, "Опции");
//        //AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hOption, "Опции");
//
//
//        CreateWindow(TEXT("BUTTON"), TEXT("Скачать ролик с Youtube"), WS_VISIBLE | WS_CHILD, 45 + a, 130, 240, 25, hWnd, (HMENU)MENUMAKER, NULL, NULL);
//        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\download.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//        SendMessage(GetDlgItem(hWnd, MENUMAKER), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);
//        BASS_Init(-1, 44100, 0, 0, NULL); 
//
//
//        SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//
//
//        AppendMenu(hAbout, MF_STRING, STRANNIK, "О программе");
//
//        AppendMenu(hColorYT, MF_STRING, COLORYT, "Мой цвет");
//        AppendMenu(hColorYT, MF_STRING, SETBKG, "Мой скин");
//        AppendMenu(hColorYT, MF_SEPARATOR, NULL, NULL);
//        AppendMenu(hColorYT, MF_STRING, polupon, "Включить полупрозрачность");
//        AppendMenu(hColorYT, MF_STRING, polupoff, "Выключить полупрозрачность");
//
//        AppendMenu(hColorYT, MF_STRING, YT, "Скачать обновление");
//
//        SetMenu(hWnd, hMenubar); 
//
//
//        BASS_Start();     
//
//        YOUTUBER = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\Youtube.mp3", 0, 0, 0);
//        BASS_ChannelPlay(YOUTUBER, false);
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
//
//
//
//        int len90;                                                                                                              
//        TCHAR video[1200];
//        len90 = GetWindowText(MENUMENUMENU, video, 1200);
//        if (LOWORD(wParam) == MENUMAKER)
//        {
//         
//
//            ShowWindow(GetDlgItem(hWnd, MAIL), SW_SHOW);
//       
//         
//            MENUMENUMENU = CreateWindow(TEXT("EDIT"), TEXT("Ссылка на ролик на Youtube"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE, 10, 500, 605, 70, hWnd, (HMENU)WRITING, NULL, 0);
//            CreateWindow(TEXT("BUTTON"), TEXT("Скачать"), WS_VISIBLE | WS_CHILD, 120 + a, 360, 100, 25, hWnd, (HMENU)MAKEMAKE, NULL, NULL);
//            HICON hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\download.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//            SendMessage(GetDlgItem(hWnd, MAKEMAKE), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);
//            ShowWindow(GetDlgItem(hWnd, MENUMAKER), SW_HIDE);
//            CreateWindow(TEXT("STATIC"), TEXT("                 Чтобы скачать ролик надо : \n\n1) Вставить ссылку на ролик в поле для ввода.\n2) Нажать кнопку << Скачать >> .\n\nP.S Радоваться, что вы не шашнахме = )\n\nP.S.S Беречь свои тонкие кости = ) "), WS_VISIBLE | WS_CHILD, 150, 90, 325, 140, hWnd, (HMENU)text1, NULL, NULL);
//
//            hTrack = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | WS_VISIBLE, 150, 250, 320, 30, hWnd, (HMENU)LENMUSIC, NULL, NULL);
//            CreateWindow(TEXT("STATIC"), TEXT("Громкость"), WS_VISIBLE | WS_CHILD, 130 + a, 290, 70, 18, hWnd, (HMENU)text1, NULL, NULL);
//                                            
//        }                     
//        
//
//
//        if (LOWORD(wParam) == STRANNIK)
//        {
//            ShellAbout(hWnd, progname, "Разработчик: Captain Strannik. Помощник: Z_Kraf1er_Z. Автор идеи: Daniel Myslivets", progicon);
//            MessageBoxA(hWnd, "Это программа для скачивания роликов с Youtube.\nСпасибо Daniel Myslivets за предоставленную консольную программку, для которой я просто сделал этот GUI", "Справка", MB_ICONASTERISK);
//        
//        }
//        if (LOWORD(wParam) == YT)
//        {
//
//            URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/YOUTUBE/yt-dlp.exe", "MusicPlayer\\Youtube\\yt-dlp.exe", 0, 0);
//            WIN32_FIND_DATA youtubckic;
//            HANDLE hFind = FindFirstFile("MusicPlayer\\Youtube\\yt-dlp.exe", &youtubckic);
//            if (INVALID_HANDLE_VALUE != hFind)
//            {
//                MessageBoxA(hWnd, "Обновление было скачано. Если не работает, пишите разработчику", "Успех!", MB_ICONASTERISK);
//            }
//            if (INVALID_HANDLE_VALUE == hFind)
//            {
//                MessageBoxA(hWnd, "Обновление не было скачано. Возможно проблема с интернетом. Либо пишите разработчику", "Неудача", MB_ICONASTERISK);
//            }
//
//
//        }
//        if (LOWORD(wParam) == SETBKG)
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
//        if (LOWORD(wParam) == MAIL)
//        {
//            BASS_StreamFree(YOUTUBER);
//            BASS_ChannelStop(YOUTUBER);
//            BASS_SampleFree(YOUTUBER);
//            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
//            BASS_Stop();
//            BASS_Start();
//            YOUTUBER = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\title4.mp3", 0, 0, 0);
//            BASS_ChannelPlay(YOUTUBER, false);
//            system("start https://lesergig.wixsite.com/strannikyt/voprosy-i-otvety");
//        }
//        if (LOWORD(wParam) == MAKEMAKE)
//        {
//            
//            ofstream Proga;
//            string videos = video;
// 
//
//
//
//
//
//    
//
//            Proga.open("MusicPlayer\\Youtube\\bat.bat");
//            Proga << "MusicPlayer\\Youtube\\yt-dlp.exe —format mp4 " << videos << endl;
//            Proga << "echo Your video has been downloaded, and stay in MusicPlayer's directory" << endl;
//            Proga.close();
//            system("MusicPlayer\\Youtube\\bat.bat");
//            system("del MusicPlayer\\Youtube\\bat.bat");
//            MessageBox(hWnd, _T("Ваше видео было скачано!\nСейчас оно лежит в папке с плеером"), _T("Успех!"), MB_ICONASTERISK);
//            MessageBox(hWnd, _T("Проверьте наличие ролика в директории MixOS\nЕсли его там нет, то скачайте обновление для программы. "), _T("ВНИМАНИЕ"), MB_ICONWARNING);
//            system("start explorer MusicPlayer");
//        }
//
//                if (LOWORD(wParam) == COLORYT)
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
//                    // ТО АХРИНЕТЬ ОХУЕТЬ ТОЧНЕЕ. Теперь надо такое же добавить в Терминал... И в Пианино... И еще много куда...
//                }
//                break;
//
//        case WM_HSCROLL: {
//            int volume = SendMessage(hTrack, TBM_GETPOS, 0, 0);
//            if (hTrack == (HWND)lParam)
//            {
//                /*BASS_ChannelSetAttribute(YOUTUBER, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 80, 100));*/
//
//                BASS_ChannelSetAttribute(YOUTUBER, BASS_ATTRIB_VOL, (float)volume / 100);
//            }
//        } break;
//
//        case WM_PAINT: {
//            hdc = BeginPaint(hWnd, &ps);
//            FillRect(hdc, &ps.rcPaint, hBrush);
//            EndPaint(hWnd, &ps);
//        } break;
//
//                case WM_CTLCOLORSTATIC:
//                {
//
//
//
//                    if (GetDlgCtrlID((HWND)lParam) == text1)
//                    {
//                        HDC hdcStatic = (HDC)wParam;
//                        // or obtain the static handle in some other way
//                        SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color
//
//                        SetBkColor(hdcStatic, rgbCurrent);
//
//                        return (LRESULT)GetStockObject(NULL_BRUSH);
//
//                    }
//                    if (GetDlgCtrlID((HWND)lParam) == LENMUSIC)
//                    {
//                        HDC hdcStatic = (HDC)wParam;
//                        // or obtain the static handle in some other way
//                        SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color
//
//                        SetBkColor(hdcStatic, RGB(255, 255, 255));
//
//
//                        return (LRESULT)(COLOR_WINDOW + 1);
//
//                    }
//                    if (GetDlgCtrlID((HWND)lParam) == VOLUMASTA)
//                    {
//                        HDC hdcStatic = (HDC)wParam;
//                        // or obtain the static handle in some other way
//                        SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color
//
//                        SetBkColor(hdcStatic, RGB(255, 255, 255));
//
//
//                        return (LRESULT)(COLOR_WINDOW + 1);
//
//                    }
//                }
//                break;
//
//
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
//    }  
//    return false;
//}  
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
//    progicon = (HICON)LoadImage(op.hInstance, "MusicPlayer\\BMP\\ico\\Youtube.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
//    op.hIcon = progicon;
//    //op.hbrBackground = CreateSolidBrush(RGB(76,0 ,153));
//    RegisterClass(&op);
//
//
//    CreateWindowEx(WS_EX_LAYERED,op.lpszClassName, progname, WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX| WS_VISIBLE, 100, 100, 640, 640, NULL, NULL, op.hInstance, NULL);
//    MSG msg;
//    while (GetMessage(&msg, NULL, 0, 0)) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//
//    }
//
//}
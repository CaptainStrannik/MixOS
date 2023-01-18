#include <windows.h>
#include <cstring>
#include <cstdlib>
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
#include "LoveInQuest.h"
#include <urlmon.h>
#pragma comment (lib, "urlmon.lib")

#define STRANNI 90     

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "bass")
#pragma comment(linker,"/manifestdependency:\"type='win32' \
                        name='Microsoft.Windows.Common-Controls' \
                        version='6.0.0.0' processorArchitecture='*'\
 publicKeyToken='6595b64144ccf1df' language='*'\"")

int len;
TCHAR StrB[1200];


using namespace std;
char str1[1024];
HSTREAM QUEST_THEME;

HICON progicon;
int skins;
TCHAR StrT[MAX_PATH];
HANDLE bmpwall;
HANDLE bmpwall1;
HWND hwall;
static COLORREF acrCustClr[16];
HBRUSH hBrush = CreateSolidBrush(RGB(0, 100, 204));
static DWORD rgbCurrent = RGB(0, 100, 204);
HWND hTrack;
HDC hdc;
PAINTSTRUCT ps;
const TCHAR progname[] = _T("Загрузчик плагинов для MixOS ver. 1.0");
HWND tardis;
//bool key_pressed = false;
HINSTANCE hInst;
HSTREAM UASSAULT;
HWND LOVE;
HWND LOVE1;
HWND LOVE2;
HWND LOVE3;
HWND LOVE4;

static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {

    case WM_CREATE: {




        NOTIFYICONDATA data;
        ZeroMemory(&data, sizeof(NOTIFYICONDATA));


        data.cbSize = sizeof(data);
        data.hWnd = hWnd;
        data.uID = 1;          // Можно поставить любой идентификатор, всё равно иконка только одна
        data.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
        data.uCallbackMessage = WM_USER_SHELLICON;
        data.hIcon = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\download.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        data.uVersion = NOTIFYICON_VERSION;

        /*     strcpy(data.szInfoTitle, "Загрузчик видео с Youtube");*/
        strcpy(data.szTip, "Загрузчик плагинов для MixOS");


        Shell_NotifyIcon(NIM_ADD, &data);
        


        HMENU hMenubar = CreateMenu();
        HMENU hAbout = CreateMenu();
        HMENU hOptions = CreateMenu();


        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "Справка");
        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hOptions, "Настройки");



        SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
        AppendMenu(hAbout, MF_STRING, STRANNIK, "О программе");


        AppendMenu(hOptions, MF_STRING, MYCOLOR, "Сменить цвет");
       


        SetMenu(hWnd, hMenubar);
        BASS_Init(-1, 44100, 0, 0, NULL);

        HINSTANCE hInst = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);
        HICON hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\MixOS.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

        CreateWindow(TEXT("STATIC"), TEXT("Какие плагины для MixOS хотите установить?"), WS_VISIBLE | WS_CHILD, 200, 30, 310, 20, hWnd, (HMENU)text1, NULL, NULL);


        CreateWindow(TEXT("BUTTON"), TEXT("Конвертер Валют"), WS_VISIBLE | WS_CHILD, 170, 100, 150, 20, hWnd, (HMENU)PLUGCONVERT, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Convert.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, PLUGCONVERT), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


        CreateWindow(TEXT("BUTTON"), TEXT("Старые версии MixOS"), WS_VISIBLE | WS_CHILD, 330, 100, 210, 20, hWnd, (HMENU)PLUGMIX, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\MixOS.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, PLUGMIX), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);




        CreateWindow(TEXT("BUTTON"), TEXT("Список эмуляторов"), WS_VISIBLE | WS_CHILD, 170, 130, 150, 20, hWnd, (HMENU)PLUGEMULATE, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Emulate.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, PLUGEMULATE), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT("Сборник игры из моего детства <<Urban Assault>>"), WS_VISIBLE | WS_CHILD, 170, 160, 370, 20, hWnd, (HMENU)PLUGUA, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Ghor.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, PLUGUA), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT("Все мои утилиты для MixOS"), WS_VISIBLE | WS_CHILD, 170, 190, 370, 20, hWnd, (HMENU)PLUGALL, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\MixOS.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, PLUGALL), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT("Удалить всё"), WS_VISIBLE | WS_CHILD, 170, 220, 370, 20, hWnd, (HMENU)PLUGDEL, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\delete.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, PLUGDEL), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

        CreateWindow(TEXT("BUTTON"), TEXT("Программы от подписчиков"), WS_VISIBLE | WS_CHILD, 330, 130, 210, 20, hWnd, (HMENU)PLUGSUBS, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Win8.ico", IMAGE_ICON, 16, 16, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
        SendMessage(GetDlgItem(hWnd, PLUGSUBS), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);
        
        BASS_Stop();
        BASS_Start();
        UASSAULT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\Skellige.mp3", 0, 0, 0);
        BASS_ChannelPlay(UASSAULT, false);

        break;


    }
    case WM_COMMAND: {


        if (LOWORD(wParam) == PLUGCONVERT)
        {
            //system("start MusicPlayer\\DWL\\bin\\Plugins\\1.bat");   //converter
            URLDownloadToFile(0, "https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1GaZh8_L6MWy2o34QB8qfeA6ixTc-UfYx", "MusicPlayer\\Convert.zip", 0, 0);
            system("MusicPlayer\\Convert.bat");
            MessageBoxA(hWnd, "Конвертер валют установлен", "Внимание", MB_ICONASTERISK);
        }
        if (LOWORD(wParam) == PLUGEMULATE)
        {
            //system("start MusicPlayer\\DWL\\bin\\Plugins\\1.bat");   //converter
            MessageBoxA(hWnd, "Этот архив весит более 1 ГБ, так что качаться будет относительно долго!\nКогда скачается и установится вам придёт уведомление", "Внимание", MB_ICONASTERISK);
            URLDownloadToFile(0, "https://drive.google.com/uc?export=download&confirm=no_antivirus&id=10nypgMPXwJP3iyXprG9HUAcsdsJjZ2Ck", "MusicPlayer\\Emulate.zip", 0, 0);
            URLDownloadToFile(0, "https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1IJzP1W8YFHJJ9hBdj2QsqkF6_HuiZ5XD", "MusicPlayer\\Music.zip", 0, 0);
            system("MusicPlayer\\Emulate.bat");
            MessageBoxA(hWnd, "Список эмуляторов успешно скачался и установился =)", "Внимание", MB_ICONASTERISK);
        }
    
        if (LOWORD(wParam) == PLUGSUBS)
        {
            //system("start MusicPlayer\\DWL\\bin\\Plugins\\1.bat");   //converter
            MessageBoxA(hWnd, "Этот архив весит 300 МБ, так что качаться будет относительно долго!\nКогда скачается и установится, вам придёт уведомление", "Внимание", MB_ICONASTERISK);
            URLDownloadToFile(0, "https://drive.google.com/uc?export=download&confirm=no_antivirus&id=18LIVItWYt7m3J2kHAjK3YhbBulKFxTOg", "MusicPlayer\\Viewer.zip", 0, 0);
            URLDownloadToFile(0, "https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1XVht4aatv9a60EbLzZLIJ0IJUGRNTt2i", "MusicPlayer\\SUBS.zip", 0, 0);
            system("MusicPlayer\\SUBS.bat");
            MessageBoxA(hWnd, "Программы от подписчиков успешно установлены", "Внимание", MB_ICONASTERISK);
        }

        if (LOWORD(wParam) == PLUGMIX)
        {
            //system("start MusicPlayer\\DWL\\bin\\Plugins\\1.bat");   //converter
            MessageBoxA(hWnd, "Этот архив весит 820 МБ, так что качаться будет относительно долго!\nКогда скачается вам придёт уведомление", "Внимание", MB_ICONASTERISK);
            URLDownloadToFile(0, "https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1lcYSrZIA-_UoEXRfMZ0WCAZw5xg1uGJZ", "MusicPlayer\\OLD.zip", 0, 0);
            system("MusicPlayer\\OLD.bat");
            MessageBoxA(hWnd, "Старые версии MixOS успешно были скачаны и установлены", "Внимание", MB_ICONASTERISK);
        }




        if (LOWORD(wParam) == PLUGUA)
        {
            MessageBoxA(hWnd, "Этот архив весит 500 МБ, так что качаться будет относительно долго!\nКогда скачается вам придёт уведомление", "Внимание", MB_ICONASTERISK);
            URLDownloadToFile(0, "https://drive.google.com/uc?export=download&confirm=no_antivirus&id=10r0C0dTVdDt2ukUB18ReNli8uyOQPH4a", "MusicPlayer\\UA.zip", 0, 0);
            system("MusicPlayer\\UA.bat");
            MessageBoxA(hWnd, "Urban Assault для MixOS был установлен", "Внимание", MB_ICONASTERISK);
        }


        if (LOWORD(wParam) == PLUGALL)
        {
            MessageBoxA(hWnd, "Это основные программы для MixOS от пианино и квеста до загрузчика роликов с Youtube и Терминала", "Внимание", MB_ICONASTERISK);
            URLDownloadToFile(0, "https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1WMcHZA-wSkntqDcPkvtHI2YGUgkgAjhc", "MusicPlayer\\ALLMYUTILITIES.zip", 0, 0);
            URLDownloadToFile(0, "https://drive.google.com/uc?export=download&confirm=no_antivirus&id=1UNGNc57-UPIp6zh9Q4dCLgNTkasMeUmR", "MusicPlayer\\WIN3.zip", 0, 0);
            system("MusicPlayer\\All.bat");
            MessageBoxA(hWnd, "Все основные плагины для MixOS были успешно установлены", "Внимание", MB_ICONASTERISK);
        }

        if (LOWORD(wParam) == PLUGDEL)
        {
            MessageBoxA(hWnd, "Это удалит все плагины для MixOS и превратит его в плеер!", "Внимание", MB_ICONASTERISK);
            system("MusicPlayer\\del.bat");
            MessageBoxA(hWnd, "Все плагины были успешно удалены!", "Внимание", MB_ICONASTERISK);
        }


















        if (LOWORD(wParam) == STRANNIK)
        {
            ShellAbout(hWnd, progname, "Разработчик: Captain Strannik", progicon);
        }



        if (LOWORD(wParam) == MYCOLOR)
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
                hBrush = CreateSolidBrush(RGB(0, 0, 204));
                rgbCurrent = RGB(0, 76, 153);
                return 0;
            };


            InvalidateRect(hWnd, NULL, FALSE);

            // ТО АХРИНЕТЬ ОХУЕТЬ ТОЧНЕЕ. Теперь надо такое же добавить в Терминал... И в Пианино... И еще много куда...
        }

    case WM_HSCROLL:
    {
        if (hTrack == (HWND)lParam)
        {
            BASS_ChannelSetAttribute(QUEST_THEME, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 25, 75));
        }
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
        if (GetDlgCtrlID((HWND)lParam) == LENMUSIC)
        {
            HDC hdcStatic = (HDC)wParam;
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color

            SetBkColor(hdcStatic, RGB(255, 255, 255));


            return (LRESULT)(COLOR_WINDOW + 1);

        }

    }break;

    case WM_PAINT: {
        hdc = BeginPaint(hWnd, &ps);
        //ТАК, слушай, , я щас некоторое время не буду говорить, но скоро начну.Но я тут подумал, что смену скинов надо добавить и в остальные подпрограммы.Хотя бы в список эмуляторов
        FillRect(hdc, &ps.rcPaint, hBrush);
        /*SetBkMode(hdc, TRANSPARENT);*/

        //BitBlt(hdc, 0, 0, bm., 720, memBit, 0, 0, SRCCOPY);

        EndPaint(hWnd, &ps);
        //return 0;

    } break;

        //case WM_KEYDOWN:
        //    switch (lParam)
        //    {
        //        case VK_NUMPAD5:
        //            if (key_pressed == false)
        //            {
        //                ShowWindow(tardis, SW_SHOW);
        //                key_pressed = true;
        //            }
        //            else if (key_pressed == true)
        //            {
        //                ShowWindow(tardis, SW_HIDE);
        //                key_pressed = false;
        //            };
        //            break;
        //    }
        //    break;

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
    progicon = (HICON)LoadImage(op.hInstance, "MusicPlayer\\BMP\\ico\\download.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
    op.hIcon = progicon;

    //op.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
    RegisterClass(&op);


    CreateWindowA(op.lpszClassName, "Загрузчик плагинов для MixOS", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE, (GetSystemMetrics(SM_CXSCREEN) - 1280) / 2,
        (GetSystemMetrics(SM_CYSCREEN) - 720) / 2, 720, 360, NULL, NULL, op.hInstance, NULL);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }

}
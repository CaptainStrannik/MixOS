#include <windows.h>
#include <winuser.h>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <tchar.h>
#include <wchar.h>
#include "resource.h"       
#include "resource1.h"
#include "resource2.h"
#include"targetver.h"
#include "framework.h"
#include "targetver.h"
#include <conio.h>
#include <shlobj.h>
#include <ks.h>
#include <string>
#include<mciapi.h>
#include<Mmsystem.h>
#include <mmeapi.h>
#include<mmdeviceapi.h>
#include "Names.h"
#include "bass.h"
#include "wingdi.h"
#include <commdlg.h>
#include <fstream>
#include <iostream>
#include <set>
#include <algorithm>
#include "Commctrl.h"
#define TRYING 3050
//#include <shlwapi.h> 
//#include <filesystem>

#pragma comment(linker,"/manifestdependency:\"type='win32' \
                        name='Microsoft.Windows.Common-Controls' \
                        version='6.0.0.0' processorArchitecture='*'\
 publicKeyToken='6595b64144ccf1df' language='*'\"")

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "bass")
//#pragma comment(lib, "shlwapi.lib")
#pragma comment(lib, "comctl32.lib")
#pragma comment (lib, "urlmon.lib")
using namespace std;
HWND eDit;
HWND eMp3;
HWND SKIN;
HWND okno;
HWND ERRORs;
char str1[MAX_PATH];

































HSTREAM stro;
HSTREAM MORNING;
HSTREAM UFO;
HSTREAM SAMPLEADV;
HSTREAM DNO;
HSTREAM VISTA;
HSTREAM EYES;
HSTREAM LONELY;
HSTREAM GIRL;
HSTREAM START;

HSTREAM ERRORS;
















HDC hdc; //создаём контекст устройства
HDC hcdc;


PAINTSTRUCT ps; //создаём экземпляр структуры графического вывода   
LOGFONT lf;
HFONT hFont;
RECT r;


HPEN hPen;
HBRUSH hBrush = CreateSolidBrush(RGB(0, 76, 153));

HWND hTrack;
HWND hTrack1;
HWND FOR6COMPOSIT;
HWND hTrack2;
HWND FOR6COMPOSIT1;
HSTREAM ERRORS1 = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\xp.mp3", 0, 0, 0);
HWND sbar;
HWND playlist;
char str2[MAX_PATH];
HWND eSearch;
char strs[MAX_PATH];

int skins;
TCHAR StrT[MAX_PATH];
HANDLE bmpwall;
HANDLE bmpwall1;
HWND hwall;

TCHAR progname[] = _T("MixOS Beta 2.5");
HICON progicon;
HINSTANCE hInst;

static HDC memBit;
static HBITMAP hBitmap;
static BITMAP bm;

WIN32_FIND_DATA MAINCOMPONENTS;
HANDLE hFindFind = FindFirstFile("MusicPlayer\\Your\\Audio.mixos", &MAINCOMPONENTS);

static COLORREF acrCustClr[16]; 
static DWORD rgbCurrent1 = RGB(0, 76, 153);        
static DWORD rgbCurrent = RGB(0, 76, 153);

inline void free_samples_all();
inline void without_stro();

static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    

MXS:    

    switch (uMsg) {

        

    case WM_CREATE: {

        /*rgbCurrent1 = RGB(255, 255, 255);*/

        if (INVALID_HANDLE_VALUE != hFindFind)
        {
            SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);




            NOTIFYICONDATA data;
            ZeroMemory(&data, sizeof(NOTIFYICONDATA));






            data.cbSize = sizeof(data);
            data.hWnd = hWnd;
            data.uID = 1;          // Можно поставить любой идентификатор, всё равно иконка только одна
            data.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
            data.uCallbackMessage = WM_USER_SHELLICON;
            data.hIcon = progicon;
            data.uVersion = NOTIFYICON_VERSION;

            /*     strcpy(data.szInfoTitle, "Загрузчик видео с Youtube");*/
            strcpy(data.szTip, progname);

            Shell_NotifyIcon(NIM_ADD, &data);



            SetBkMode(hdc, OPAQUE);
            BASS_Init(-1, 44100, 0, 0, NULL);

            HINSTANCE hInst = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);
            HICON hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\MixOS.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);





            CreateWindow(TEXT("STATIC"), TEXT("Вас приветствует MixOS"), WS_VISIBLE | WS_CHILD | WS_EX_LAYERED, 550, 20, 170, 15, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("Что желаете запустить?"), WS_VISIBLE | WS_CHILD, 550, 40, 160, 15, hWnd, (HMENU)text1, NULL, NULL);







            CreateWindow(TEXT("BUTTON"), TEXT("Плеер (Num2)"), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 120, 200, 500, 300, hWnd, (HMENU)ID_BUTTON, NULL, NULL);
            SendMessage(GetDlgItem(hWnd, ID_BUTTON), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            CreateWindow(TEXT("BUTTON"), TEXT("Проверка установленных плагинов)"), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 830, 20, 320, 50, hWnd, (HMENU)TRYING, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\download.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
            SendMessage(GetDlgItem(hWnd, TRYING), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);



            CreateWindow(TEXT("BUTTON"), TEXT("Эмуляторы (Num5)"), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 650, 200, 500, 300, hWnd, (HMENU)Emulators, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Emulate.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, Emulators), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            CreateWindow(TEXT("BUTTON"), TEXT("Контекстменюмейкер (Num3)"), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 120, 530, 500, 100, hWnd, (HMENU)MENUMAKER, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\menumaker.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, MENUMAKER), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            CreateWindow(TEXT("BUTTON"), TEXT("Квест (Num6)"), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 650, 530, 500, 100, hWnd, (HMENU)QUEST, NULL, NULL);

            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\quest.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, QUEST), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);     //Иконка нормально смотрится теперь..


            CreateWindow(TEXT("BUTTON"), TEXT("Пианино (Num4)"), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 650, 80, 500, 100, hWnd, (HMENU)PIANINO, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\piano.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, PIANINO), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            CreateWindow(TEXT("BUTTON"), TEXT("Терминал (Num1)"), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 120, 80, 500, 100, hWnd, (HMENU)TERMINAL, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\terminal.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, TERMINAL), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);



            CreateWindow(TEXT("BUTTON"), TEXT("Скачать ролик с Youtube (Num7)"), WS_VISIBLE | WS_CHILD | WS_TABSTOP, 120, 650, 1030, 25, hWnd, (HMENU)YOUTUBE, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\youtube.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, YOUTUBE), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll); // а ты в войс впустишь?   да щас поговорю и продолжим кодить. я щас.


            //CreateWindow(TEXT("BUTTON"), TEXT("Запустить все подпрограммы MixOS при нажатии на кнопку \"Плеер\""), WS_VISIBLE | WS_CHILD | BS_CHECKBOX | WS_EX_LAYERED | BS_AUTOCHECKBOX,
            //    120 + 600, 20, 450 + 50 - 20, 16, hWnd, (HMENU)CHB1, NULL, NULL);

            BASS_Start();
            START = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\Mozart.mp3", 0, 0, 0);
            BASS_ChannelPlay(START, false);


            hTrack1 = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS /*| LVS_EX_TRANSPARENTBKGND*/ | WS_VISIBLE | TBS_ENABLESELRANGE, 10, 20, 100, 20, hWnd, (HMENU)LENMUSIC4, NULL, NULL);
            /*ShowWindow(GetDlgItem(hWnd, LENMUSIC1), SW_SHOW);*/
            SendMessage(hTrack1, TBM_SETPOS, 0, 1);
            SendMessage(hTrack1, TBM_SETRANGEMAX, TRUE, 100);
            CreateWindow(TEXT("STATIC"), TEXT("Громкость"), WS_VISIBLE | WS_CHILD, 25, 60 - 20, 70, 18, hWnd, (HMENU)text11, NULL, NULL);

            eMp3 = CreateWindow(TEXT("Edit"), NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE, 120, 50, 1000 + 30, 20, hWnd, (HMENU)SKINSSTRO, NULL, 0);
            ShowWindow(GetDlgItem(hWnd, SKINSSTRO), SW_HIDE);
            SendMessageW(eMp3, EM_SETCUEBANNER, FALSE, (LPARAM)L"Путь до картинки BMP, например MusicPlayer\\BMP\\st.bmp");




            CreateWindow("BUTTON", "Установить скин", WS_VISIBLE | WS_CHILD, 120, 80 - 30 - 30, 150, 20, hWnd, (HMENU)SETBKG, NULL, NULL);



            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\instskin.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, SETBKG), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);











            CreateWindow("BUTTON", "Установить полупрозрачность", WS_VISIBLE | WS_CHILD, 120, 80 - 30 - 30 + 30, 320, 20, hWnd, (HMENU)polupon, NULL, NULL);

            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\desktop.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, polupon), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);
















            CreateWindow("BUTTON", "Выключить полупрозрачность", WS_CHILD, 120, 80 - 30 - 30 + 30, 320, 20, hWnd, (HMENU)polupoff, NULL, NULL);

            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\computer.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, polupoff), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);




            //Че это? это описание функции для генерации документации   а ок
            CreateWindow("BUTTON", "Удалить скин", WS_VISIBLE | WS_CHILD, 120 + 150 + 20, 80 - 30 - 30, 150, 20, hWnd, (HMENU)CLEARSKIN, NULL, NULL);

            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\delete.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, CLEARSKIN), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            //SetWindowLongPtr(hWnd, GWL_EXSTYLE, WS_EX_ACCEPTFILES);

            //SendMessage(hWnd, WM_COMMAND, ID_BUTTON, 0);




            WIN32_FIND_DATA CreeperYT;
            HANDLE INSTALLACreeperYT = FindFirstFile("MusicPlayer\\PhotoViewer\\CreeperPhotoViewer.exe", &CreeperYT);

        }

        else
        {

            MessageBoxA(hWnd, "При первом запуске MixOS\nЕй нужно скачать основные данные\nПожалуйста подождите!", "Внимание!", MB_ICONASTERISK);


            URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/CONVERT", "MusicPlayer\\CONVERT.zip", 0, 0);
            URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/BMP", "MusicPlayer\\BMP.zip", 0, 0);
            URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/HeadlessNick", "MusicPlayer\\HeadlessNick.zip", 0, 0);
            URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/PhotoViewer", "MusicPlayer\\PhotoViewer.zip", 0, 0);
            URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/Your", "MusicPlayer\\Your.zip", 0, 0);
            URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/Violet", "MusicPlayer\\Violet.zip", 0, 0);
            URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/POLZ", "MusicPlayer\\POLZ.zip", 0, 0);
            system("MusicPlayer\\MAIN.bat");

            WIN32_FIND_DATA MAINCOMPONENTS;
            HANDLE hFindFind = FindFirstFile("MusicPlayer\\Your\\Audio.mixos", &MAINCOMPONENTS);

            if (INVALID_HANDLE_VALUE != hFindFind)
            {
                MessageBoxA(hWnd, "Файлы были успешно скачаны\nПерезапустите MixOS", "Внимание!", MB_ICONASTERISK);


                PostQuitMessage(0);
                return 0;

            }

            WIN32_FIND_DATA MAINCOMPONENTSS;
            HANDLE hFindFindFIND = FindFirstFile("MusicPlayer\\Your\\Audio.mixos", &MAINCOMPONENTSS);
            if (INVALID_HANDLE_VALUE == hFindFindFIND)
            {
                MessageBoxA(hWnd, "Не удалось скачать минимальные данные\nПроверьте интернет соединение\nи настройки брандмауэра\nЕсли не помогло, скачайте минимальную версию по ссылке:\nhttps://github.com/captainstrannik/Mixos", "Внимание!", MB_ICONASTERISK);
                PostQuitMessage(0);
                return 0;
            }

        };

        return false;
        FindClose(hFindFind);
        PostQuitMessage(0);

    }

                  break;

    case WM_COMMAND: {

        if (LOWORD(wParam) == ID_BUTTON)
        {








            DestroyWindow(hwall);














            SetWindowText(hWnd, "MixPlayer из MixOS Beta 2.5");
            bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);

            HINSTANCE hInst = (HINSTANCE)GetWindowLongPtr(hWnd, GWLP_HINSTANCE);
            HICON hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\MixOS.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            if (SendMessage(GetDlgItem(hWnd, CHB1), BM_GETCHECK, 0, 0) == BST_CHECKED)
            {

                SendMessage(hWnd, WM_COMMAND, QUEST, 0);
                SendMessage(hWnd, WM_COMMAND, TERMINAL, 0);
                SendMessage(hWnd, WM_COMMAND, PIANINO, 0);
                SendMessage(hWnd, WM_COMMAND, ERTOR, 0);
                SendMessage(hWnd, WM_COMMAND, Emulators, 0);
                SendMessage(hWnd, WM_COMMAND, YOUTUBE, 0);
                SendMessage(hWnd, WM_COMMAND, MENUMAKER, 0);
                SendMessage(hWnd, WM_COMMAND, SELFUP, 0);
                SendMessage(hWnd, WM_COMMAND, CONVERTER, 0);
                SendMessage(hWnd, WM_COMMAND, VIDEO, 0);
                SendMessage(hWnd, WM_COMMAND, PHOTOVIEWER, 0);
                SendMessage(hWnd, WM_COMMAND, TRANSLATE, 0);

            }
            DestroyWindow(GetDlgItem(hWnd, CHB1));
            DestroyWindow(GetDlgItem(hWnd, SETBKG));
            DestroyWindow(GetDlgItem(hWnd, CLEARSKIN));
            DestroyWindow(GetDlgItem(hWnd, polupoff));
            DestroyWindow(GetDlgItem(hWnd, polupon));
            //DestroyWindow(GetDlgItem(hWnd, SKINSSTRO));
            ShowWindow(GetDlgItem(hWnd, SKINSSTRO), SW_HIDE);
            DestroyWindow(GetDlgItem(hWnd, LENMUSIC4));
            DestroyWindow(GetDlgItem(hWnd, SEARCH));                     //Главное правило инженера: Работает - не трогай!  =)
            //ShowWindow(GetDlgItem(hWnd, SEARCH), SW_HIDE);
            //ShowWindow(eMp3, SW_HIDE);
            skins = GetWindowText(eMp3, StrT, MAX_PATH);
            bmpwall = LoadImage(NULL, StrT, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);

            if (bmpwall != NULL);
            {
                hwall = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall);
            }


            ShowWindow(GetDlgItem(hWnd, text11), SW_HIDE);
            BASS_SampleFree(START);
            BASS_ChannelFree(START);
            BASS_StreamFree(START);
            BASS_Stop();
            BASS_Start();
            VISTA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\Vista.mp3", 0, 0, 0);
            BASS_ChannelPlay(VISTA, false);


            ShowWindow(GetDlgItem(hWnd, Emulators), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LENMUSIC1), SW_HIDE);


            HMENU hMenubar = CreateMenu();
            HMENU hFile = CreateMenu();
            HMENU hAbout = CreateMenu();
            HMENU hCreator = CreateMenu();
            HMENU hHelp = CreateMenu();
            HMENU hUtils = CreateMenu();
            HMENU hInstall = CreateMenu();
            HMENU hRasvl = CreateMenu();
            HMENU hOptions = CreateMenu();
            HMENU hChangeFont = CreateMenu();
            HMENU hChangeColor = CreateMenu();
            HMENU hWhat = CreateMenu();

            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hFile, "Файл");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "Справка");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hCreator, "О разработчике");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hHelp, "Шашнахме");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hUtils, "Системные утилиты");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hInstall, "Установка полезного софта");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hRasvl, "Развлечения");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hOptions, "Настройки");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hWhat, "С чего начиналась разработка?");


            //AppendMenu(hOptions, MF_STRING, SAVEINI, "Сохранить настройки");





            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));

            AppendMenu(hFile, MF_STRING, IU_STR, "Выход");
            AppendMenu(hFile, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hFile, MF_STRING /*| MF_OWNERDRAW*/, MENUMENUMENUMENU, "Вернуться в меню");

            AppendMenu(hFile, MF_STRING, SOURCE, "Исходный код");
            AppendMenu(hFile, MF_STRING, FASTRESTART, "Быстрая перезагрузка Windows");

            AppendMenu(hAbout, MF_STRING, STRANNIK, "О программе");
            AppendMenu(hAbout, MF_STRING, MAIL, "Написать разработчику");


            AppendMenu(hCreator, MF_STRING, WOZRAST, "Возраст");
            AppendMenu(hCreator, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hCreator, MF_STRING, WEIGHT, "Вес");
            AppendMenu(hCreator, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hCreator, MF_STRING, ROSTE, "Рост");
            AppendMenu(hCreator, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hCreator, MF_STRING, DUSHA, "Душа");
            AppendMenu(hCreator, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hCreator, MF_STRING, POL, "Пол");
            AppendMenu(hCreator, MF_SEPARATOR, NULL, NULL);

            AppendMenu(hCreator, MF_STRING, ABOUTDEV, "О процессе разработки");

            AppendMenu(hHelp, MF_STRING, HELP, "Помощь");
            AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hHelp, MF_STRING, QUEST, "Поиграть в шашнахме квест");
            AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hHelp, MF_STRING, PIANINO, "Поиграть на пианино");
            AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hHelp, MF_STRING, TERMINAL, "Открыть терминал");
            AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hHelp, MF_STRING, CONVERTER, "Открыть конвертер валют");
            AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);

            AppendMenu(hHelp, MF_STRING, MENUMAKER, "Открыть контекстменюмейкер для Windows");
            AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hHelp, MF_STRING, YOUTUBE, "Открыть загрузчик видосов с ютуба");
            AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hHelp, MF_STRING, ERTOR, "Открыть генератор случайных чисел");
            AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            //AppendMenu(hHelp, MF_STRING, VIDEO, "Открыть видеоплеер");
            //AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hHelp, MF_STRING, PHOTOVIEWER, "Открыть просмотрщик фотографий");
            AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hHelp, MF_STRING, TRANSLATE, "Открыть руингтранслит");
            //AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            //AppendMenu(hHelp, MF_STRING, RADIO, "Открыть радио");
            //AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            //AppendMenu(hHelp, MF_STRING, SELFUP, "Открыть помощник по повышению самооценки (для девушек).");

            AppendMenu(hUtils, MF_STRING, NOTEPAD, "Открыть блокнот");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, RSTRUI, "Открыть восстановление системы");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, DEFRAG, "Открыть дефрагментацию диска");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, TASKMGR, "Открыть диспетчер задач");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, DEVICES, "Открыть диспетчер устройств");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, CALC, "Открыть калькулятор");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, RESMON, "Открыть монитор ресурсов");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, CLEANMGR, "Открыть очистку диска");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, PANEL, "Открыть панель управления");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, PERSONALIZE, "Открыть персонализацию");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);

            AppendMenu(hUtils, MF_STRING, GPEDIT, "Открыть редактор групповых политик");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, REGEDIT, "Открыть редактор реестра");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, SYSTEMA, "Открыть свойства системы");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, COMPMGMT, "Открыть управление компьютером");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, MSCONFIG, "Открыть msconfig");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, MSINFO32, "Открыть msinfo32");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, MSPAINT, "Открыть paint");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, VERIFIER, "Открыть verifier");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, MRT, "Открыть MRT");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, EVENTVWR, "Открыть просмотр событий");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, SERVICES, "Открыть службы");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, TASKSCHD, "Открыть планировщик заданий");
            AppendMenu(hUtils, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hUtils, MF_STRING, MDSCHED, "Открыть средство проверки памяти Windows");






            AppendMenu(hInstall, MF_STRING, VISUAL, "Установить Visual C++ редисты");
            AppendMenu(hInstall, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hInstall, MF_STRING, VISUALSTUDIO, "Установить Visual Studio 2022");
            AppendMenu(hInstall, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hInstall, MF_STRING, OBS, "Установить OBS");
            AppendMenu(hInstall, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hInstall, MF_STRING, VEGAS, "Открыть CPU-Z");
            AppendMenu(hInstall, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hInstall, MF_STRING, HW, "Открыть HW monitor");
            AppendMenu(hInstall, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hInstall, MF_STRING, BOMB, "Открыть Revo Uninstaller");



            AppendMenu(hRasvl, MF_STRING, EMULATE, "Эмуляторы");
            AppendMenu(hRasvl, MF_STRING, COMP4, "Компьютерная эволюция 4");


            AppendMenu(hOptions, MF_STRING, MYCOLOR, "Сменить цвет");
            //AppendMenu(hOptions, MF_STRING, MYFONT, "Сменить шрифт");
            AppendMenu(hOptions, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hOptions, MF_STRING, SETBKG, "Сменить фон на картинку");
            AppendMenu(hOptions, MF_STRING, SKIN1, "Картинка 1");
            AppendMenu(hOptions, MF_STRING, SKIN2, "Картинка 2");
            AppendMenu(hOptions, MF_STRING, SKIN3, "Картинка 3");
            AppendMenu(hOptions, MF_STRING, SKIN4, "Картинка 4");
            AppendMenu(hOptions, MF_STRING, SKIN5, "Картинка 5");
            AppendMenu(hOptions, MF_STRING, SKIN6, "Картинка 6");
            AppendMenu(hOptions, MF_STRING, SKIN7, "Картинка 7");
            AppendMenu(hOptions, MF_STRING, SKIN8, "Картинка 8");
            AppendMenu(hOptions, MF_STRING, SKIN9, "Картинка 9");
            AppendMenu(hOptions, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hOptions, MF_STRING, polupon, "Включить полупрозрачность");
            AppendMenu(hOptions, MF_STRING, polupoff, "Выключить полупрозрачность");
            AppendMenu(hOptions, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hOptions, MF_STRING, TRYING, "Проверка установленных плагинов");
            AppendMenu(hOptions, MF_STRING, UPDATEFIND, "Проверка обновлений");




            AppendMenu(hWhat, MF_STRING, OLDVER13, "MusicPlayer Beta 1.3");
            AppendMenu(hWhat, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hWhat, MF_STRING, OLDVER15, "MusicPlayer Beta 1.5");


            SetMenu(hWnd, hMenubar);
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, Emulators), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, TERMINAL), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PIANINO), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MENUMAKER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, YOUTUBE), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, QUEST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, TRYING), SW_HIDE);

            //CreateWindow(TEXT("STATIC"), TEXT("MixPlayer Version Beta 2.5. copyright ©StrannikCorp. All rights reserved"), WS_VISIBLE | WS_CHILD, 400, 20, 500, 25, hWnd, (HMENU)text1, NULL, NULL);

            //CreateWindow(TEXT("STATIC"), TEXT("*************************************Привет, этот плеер проигрывает музыку в любых форматах*********************************************"), WS_VISIBLE | WS_CHILD, 200, 40, 899, 25, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("Расширение указывать не нужно. За вас это сделает плейлист =)"), WS_VISIBLE | WS_CHILD, 480 - 25-50, 60, 450, 20, hWnd, (HMENU)text1, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("Тут уже имеется пара композиций"), WS_VISIBLE | WS_CHILD, 500, 100, 230, 20, hWnd, (HMENU)text1, NULL, NULL);







            CreateWindow(TEXT("BUTTON"), TEXT("Headless Nick - Morning "), WS_VISIBLE | WS_CHILD, 150, 150, 300, 70, hWnd, (HMENU)DEVUSHKA, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\music.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, DEVUSHKA), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            CreateWindow(TEXT("BUTTON"), TEXT("Captain Strannik - SeasonFlights"), WS_VISIBLE | WS_CHILD, 460, 150, 300, 70, hWnd, (HMENU)LETO, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\music.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, LETO), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            CreateWindow(TEXT("BUTTON"), TEXT("Headless Nick - Sample Adventures "), WS_VISIBLE | WS_CHILD, 770, 150, 300, 70, hWnd, (HMENU)SHAG, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\music.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, SHAG), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            CreateWindow(TEXT("BUTTON"), TEXT("Deteez - Above the Sky"), WS_VISIBLE | WS_CHILD, 150, 230, 300, 70, hWnd, (HMENU)SLOVO, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\music.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, SLOVO), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            CreateWindow(TEXT("BUTTON"), TEXT("Violet S - Lonely "), WS_VISIBLE | WS_CHILD, 770, 230, 300, 70, hWnd, (HMENU)CIGARET, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\music.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, CIGARET), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            CreateWindow(TEXT("BUTTON"), TEXT("Phasmaton - Heresy"), WS_VISIBLE | WS_CHILD, 460, 230, 300, 70, hWnd, (HMENU)PEREMEN, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\music.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, PEREMEN), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);




            



            CreateWindow(TEXT("BUTTON"), TEXT("Witcher 3 Skellige Theme"), WS_VISIBLE | WS_CHILD, 150, 150, 300, 70, hWnd, (HMENU)WITCHER1, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\music.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, WITCHER1), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            CreateWindow(TEXT("BUTTON"), TEXT("Witcher 3 Kaer Morhen"), WS_VISIBLE | WS_CHILD, 460, 150, 300, 70, hWnd, (HMENU)WITCHER2, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\music.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, WITCHER2), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            CreateWindow(TEXT("BUTTON"), TEXT("Fast Music from YT studio"), WS_VISIBLE | WS_CHILD, 770, 150, 300, 70, hWnd, (HMENU)FAST, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\music.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, FAST), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            CreateWindow(TEXT("BUTTON"), TEXT("Captan Strannik - Hard Thing"), WS_VISIBLE | WS_CHILD, 150, 230, 300, 70, hWnd, (HMENU)STR9, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\music.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, STR9), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            CreateWindow(TEXT("BUTTON"), TEXT("Ark Music from YT studio"), WS_VISIBLE | WS_CHILD, 770, 230, 300, 70, hWnd, (HMENU)ARK, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\music.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, ARK), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            CreateWindow(TEXT("BUTTON"), TEXT("Robocop 3 NES"), WS_VISIBLE | WS_CHILD, 460, 230, 300, 70, hWnd, (HMENU)ROBI, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\music.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, ROBI), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);














            CreateWindow(TEXT("BUTTON"), TEXT("Sonic CD US - (Tidal Tempest)"), WS_VISIBLE | WS_CHILD, 150, 150, 300, 70, hWnd, (HMENU)GHZ, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Sonic.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, GHZ), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            CreateWindow(TEXT("BUTTON"), TEXT("Sonic 3 - Ice Cap"), WS_VISIBLE | WS_CHILD, 460, 150, 300, 70, hWnd, (HMENU)ICZ, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Sonic.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, ICZ), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            CreateWindow(TEXT("BUTTON"), TEXT("Sonic 3 and Knucles - Lava Reef"), WS_VISIBLE | WS_CHILD, 770, 150, 300, 70, hWnd, (HMENU)LRZ, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Sonic.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, LRZ), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            CreateWindow(TEXT("BUTTON"), TEXT("Sonic 2 - Hidden Palace"), WS_VISIBLE | WS_CHILD, 150, 230, 300, 70, hWnd, (HMENU)HPZ, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Sonic.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, HPZ), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            CreateWindow(TEXT("BUTTON"), TEXT("Sonic 1 (SMS) - Scrap Brain"), WS_VISIBLE | WS_CHILD, 770, 230, 300, 70, hWnd, (HMENU)SBZ, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Sonic.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, SBZ), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            CreateWindow(TEXT("BUTTON"), TEXT("Sonic CD JP - Stardust speedway (BAD)"), WS_VISIBLE | WS_CHILD, 460, 230, 300, 70, hWnd, (HMENU)SSZ, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\Sonic.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, SSZ), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);











            CreateWindow(TEXT("BUTTON"), TEXT("Earthworm Jim (ROCK COVER)"), WS_VISIBLE | WS_CHILD, 150, 150, 300, 70, hWnd, (HMENU)EJI, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\music.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, EJI), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            CreateWindow(TEXT("BUTTON"), TEXT("Street Fighter II (ROCK COVER)"), WS_VISIBLE | WS_CHILD, 460, 150, 300, 70, hWnd, (HMENU)SFII, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\music.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, SFII), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            CreateWindow(TEXT("BUTTON"), TEXT("Alladin (ROCK COVER)"), WS_VISIBLE | WS_CHILD, 770, 150, 300, 70, hWnd, (HMENU)ASI, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\music.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, ASI), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            CreateWindow(TEXT("BUTTON"), TEXT("Sonic 3 (ROCK THEME)"), WS_VISIBLE | WS_CHILD, 150, 230, 300, 70, hWnd, (HMENU)SIII, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\music.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, SIII), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            CreateWindow(TEXT("BUTTON"), TEXT("TMNT (KINAMAN ROCK COVER)"), WS_VISIBLE | WS_CHILD, 770, 230, 300, 70, hWnd, (HMENU)TMNT, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\music.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, TMNT), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            CreateWindow(TEXT("BUTTON"), TEXT("Lion King (ROCK COVER)"), WS_VISIBLE | WS_CHILD, 460, 230, 300, 70, hWnd, (HMENU)LKI, NULL, NULL);
            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\music.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, LKI), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);








            ShowWindow(GetDlgItem(hWnd, WITCHER1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, WITCHER2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FAST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STR9), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ARK), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ROBI), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, EJI), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ASI), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LKI), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SFII), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SIII), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, TMNT), SW_HIDE);


            CreateWindow(TEXT("BUTTON"), TEXT(">"), WS_VISIBLE | WS_CHILD, 1090, 200, 40, 40, hWnd, (HMENU)STRELKA1, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT(">"), WS_VISIBLE | WS_CHILD, 1090, 200, 40, 40, hWnd, (HMENU)STRELKA3, NULL, NULL);
            

            CreateWindow(TEXT("BUTTON"), TEXT("<"), WS_VISIBLE | WS_CHILD, 90, 200, 40, 40, hWnd, (HMENU)STRELKA2, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("<"), WS_VISIBLE | WS_CHILD, 90, 200, 40, 40, hWnd, (HMENU)STRELKA4, NULL, NULL);

            CreateWindow(TEXT("BUTTON"), TEXT(">"), WS_VISIBLE | WS_CHILD, 1090, 200, 40, 40, hWnd, (HMENU)STRELKA5, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("<"), WS_VISIBLE | WS_CHILD, 90, 200, 40, 40, hWnd, (HMENU)STRELKA6, NULL, NULL);

            ShowWindow(GetDlgItem(hWnd, STRELKA1), SW_SHOW);   //->
            ShowWindow(GetDlgItem(hWnd, STRELKA2), SW_SHOW);   //<-
            ShowWindow(GetDlgItem(hWnd, STRELKA4), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STRELKA3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STRELKA5), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STRELKA6), SW_HIDE);
            

            ShowWindow(GetDlgItem(hWnd, SSZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HPZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LRZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SBZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ICZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SPZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, GHZ), SW_HIDE);

            CreateWindow(TEXT("BUTTON"), TEXT("Остановить музыку "), WS_VISIBLE | WS_CHILD, 770, 500, 300, 70, hWnd, (HMENU)STOPS, NULL, NULL);

            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\instskin.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, STOPS), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            CreateWindow(TEXT("BUTTON"), TEXT("Открыть свой файл"), WS_VISIBLE | WS_CHILD, 150, 500, 300, 70, hWnd, (HMENU)FILEY2, NULL, NULL);

            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\instskin.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, FILEY2), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            /*  Слушай, как сделать так, чтобы текст был без фона белого?  */


            CreateWindow(TEXT("BUTTON"), TEXT("Продолжить"), WS_VISIBLE | WS_CHILD, 460, 500, 300, 70, hWnd, (HMENU)PAUSE2, NULL, NULL);

            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\play.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, PAUSE2), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);

            CreateWindow(TEXT("BUTTON"), TEXT("Пауза"), WS_VISIBLE | WS_CHILD, 460, 500, 300, 70, hWnd, (HMENU)PAUSE1, NULL, NULL);


            hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\pause.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

            SendMessage(GetDlgItem(hWnd, PAUSE1), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);


            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);
            // ShowWin
              //CreateWindow(TEXT("BUTTON"), TEXT("Очистить RAM"), WS_VISIBLE | WS_CHILD, 550, 600, 110, 20, hWnd, (HMENU)RAMRAM, NULL, NULL);


            eMp3 = CreateWindow(TEXT("Edit"), NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE, 40, 430, 1175 - 30, 20, hWnd, (HMENU)YOUMUSIC, NULL, 0);
            //CreateWindow("BUTTON", "Поиск", WS_VISIBLE | WS_CHILD, 460, 500-80, 300, 70, hWnd, (HMENU)SEARCH, NULL, NULL);
            SendMessageW(eMp3, EM_SETCUEBANNER, FALSE, (LPARAM)L"Путь до вашей музыки, в любом формате =) (С расширением) Например:  MusicPlayer\\Violet S\\Lonely.mp3");
            //SetWindowLongPtr(hWnd, GWL_EXSTYLE, WS_EX_ACCEPTFILES);
            /*hTrack = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | LVS_EX_TRANSPARENTBKGND | WS_VISIBLE, 150, 250, 320, 30, hWnd, (HMENU)LENMUSIC, NULL, NULL);*/



            hTrack = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | LVS_EX_TRANSPARENTBKGND | TBS_ENABLESELRANGE, 450 - 150 - 100, 590 - 220, 320, 30, hWnd, (HMENU)LENMUSIC, NULL, NULL);
            SendMessage(hTrack, TBM_SETPOS, 0, 1);
            SendMessage(hTrack, TBM_SETRANGEMAX, TRUE, 100);


            hTrack2 = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | LVS_EX_TRANSPARENTBKGND | TBS_ENABLESELRANGE, 450 + 150 + 100, 590 - 220, 320, 30, hWnd, (HMENU)LENMUSIC3, NULL, NULL);

            FOR6COMPOSIT = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | LVS_EX_TRANSPARENTBKGND | TBS_ENABLESELRANGE, 450-150-100, 590 - 220, 320, 30, hWnd, (HMENU)LENMUSIC2, NULL, NULL);
            SendMessage(FOR6COMPOSIT, TBM_SETPOS, 0, 1);
            SendMessage(FOR6COMPOSIT, TBM_SETRANGEMAX, TRUE, 100);

            FOR6COMPOSIT1 = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | LVS_EX_TRANSPARENTBKGND | TBS_ENABLESELRANGE | WS_VISIBLE, 450+150+100, 590-220, 320, 30, hWnd, (HMENU)LENMUSIC5, NULL, NULL);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGE, 0, 0);

            //hTrack1 = CreateWindow(TRACKBAR_CLASS, "LENGTH", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | LVS_EX_TRANSPARENTBKGND, 150, 390, 923, 30, hWnd, (HMENU)LENMUSIC1, NULL, NULL);
            //SendMessageA(hWnd, TBM_SETPOS, TRUE, 50);
            CreateWindow(TEXT("STATIC"), TEXT("Громкость"), WS_CHILD, 570 - 150 - 100, 590 - 240 + 50, 70, 20, hWnd, (HMENU)VOLUMASTA, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("Громкость"), WS_CHILD, 570-150-100, 590 - 240+50, 70, 20, hWnd, (HMENU)VOLUMASTA1, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("Ползунок воспроизведения"), WS_CHILD, 515 + 150 + 100, 590 - 240 + 20 + 30, 190, 20, hWnd, (HMENU)SOUNDMASTA, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("Ползунок воспроизведения"), WS_CHILD | WS_VISIBLE, 515+150+100, 590-240+20+30, 190, 20, hWnd, (HMENU)SOUNDMASTA1, NULL, NULL);

            ShowWindow(GetDlgItem(hWnd, LENMUSIC2), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, VOLUMASTA1), SW_SHOW);

            CreateWindow(TEXT("STATIC"), TEXT("Для файлов теперь работает Drag'n Drop"), WS_CHILD, 470, 100, 280, 20, hWnd, (HMENU)textdnd, NULL, NULL);

            sbar = CreateStatusWindow(WS_CHILD | WS_VISIBLE, NULL, hWnd, 0);

            CreateWindow(TEXT("STATIC"), TEXT("Плейлист"), WS_CHILD, 570, 130, 65, 18, hWnd, (HMENU)textpl, NULL, NULL);
            playlist = CreateWindow(/*WS_EX_NOACTIVATE,*/ "LISTBOX", NULL, WS_CHILD | LBS_HASSTRINGS | WS_HSCROLL | WS_VSCROLL, 150, 150, 920, 180, hWnd, NULL, NULL, NULL);
            SendMessage(playlist, LB_INITSTORAGE, 0x7FFF, MAX_PATH); // выделяем память для списка
            UpdateWindow(playlist);
            CreateWindow("BUTTON", "Выбрать/Проиграть" /*"Вставить файл"*/, WS_CHILD, (150 * 1.75) - 10, 330, 150, 30, hWnd, (HMENU)PLSEL, NULL, NULL);
            CreateWindow("BUTTON", "Добавить файл", WS_CHILD, (310 * 1.75) - 10, 330, 150, 30, hWnd, (HMENU)PLADD, NULL, NULL);
            CreateWindow("BUTTON", "Удалить файл", WS_CHILD, (470 * 1.75) - 10, 330, 150, 30, hWnd, (HMENU)PLDEL, NULL, NULL);


            ShowWindow(GetDlgItem(hWnd, YOUMUSIC), SW_HIDE);

        }



        if (LOWORD(wParam) == COMP4)
        {
            WIN32_FIND_DATA CompEVO;
            HANDLE hFind = FindFirstFile("MusicPlayer\\EVO.mixos", &CompEVO);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                system("MusicPlayer\\W311\\SYSTEM\\WIN\\COMP4\\1.bat");

            }

            else
            {
                BASS_StreamFree(ERRORS);

                ERRORS = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\xp.mp3", 0, 0, 0);
                BASS_ChannelPlay(ERRORS, false);

                if (MessageBox(hWnd, "Ошибка с кодом 0xc000011b \n(Установите CompEvo4)\nЖелаете установить?", "COMP_EVO_NOT_FOUND", MB_YESNO | MB_ICONWARNING) == IDYES)
                {
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/EMULATORS/EVO", "MusicPlayer\\EVO.mixos", 0, 0);

                    WIN32_FIND_DATA CompEVO;
                    HANDLE hFind = FindFirstFile("MusicPlayer\\EVO.mixos", &CompEVO);

                    if (INVALID_HANDLE_VALUE != hFind)
                    {
                        MessageBoxA(hWnd, "Теперь можете играть!\nОшибка исправлена!!", "Успех!", MB_ICONASTERISK);
                    }
                    else
                    {
                        MessageBoxA(hWnd, "Ошибка не была исправлена. Возможно проблема с интернетом. Либо пишите разработчику", "Неудача", MB_ICONASTERISK);
                    };

                }

            };
            return false;
            FindClose(hFind);
        }









        
        if (LOWORD(wParam) == TRANSLATE)
        {
            system("start MusicPlayer\\SUBS\\NBR\\ru4en.hta");


        }
        if (LOWORD(wParam) == STRELKA1)
        {
            ShowWindow(GetDlgItem(hWnd, WITCHER1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, WITCHER2), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, FAST), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, STR9), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, ARK), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, ROBI), SW_SHOW);

            ShowWindow(GetDlgItem(hWnd, TMNT), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ASI), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SFII), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SIII), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LKI), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, EJI), SW_HIDE);


            ShowWindow(GetDlgItem(hWnd, DEVUSHKA),SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LETO), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SHAG), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SLOVO), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, CIGARET), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PEREMEN), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, SSZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HPZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LRZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SBZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ICZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SPZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, GHZ), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, STRELKA1), SW_HIDE);   //->
            ShowWindow(GetDlgItem(hWnd, STRELKA2), SW_HIDE);   //<-
            ShowWindow(GetDlgItem(hWnd, STRELKA4), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, STRELKA3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STRELKA5), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, STRELKA6), SW_HIDE);



        }

        if (LOWORD(wParam) == STRELKA2)
        {
            ShowWindow(GetDlgItem(hWnd, WITCHER1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, WITCHER2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FAST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STR9), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ARK), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ROBI), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, SSZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HPZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LRZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SBZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ICZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SPZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, GHZ), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, DEVUSHKA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LETO), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SHAG), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SLOVO), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, CIGARET), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PEREMEN), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, TMNT), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, ASI), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SFII), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SIII), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, LKI), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, EJI), SW_SHOW);


            ShowWindow(GetDlgItem(hWnd, STRELKA1), SW_HIDE);   //->
            ShowWindow(GetDlgItem(hWnd, STRELKA2), SW_HIDE);   //<-
            ShowWindow(GetDlgItem(hWnd, STRELKA4), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STRELKA3), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, STRELKA5), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, STRELKA6), SW_HIDE);

        }
        if (LOWORD(wParam) == STRELKA3)
        {
            ShowWindow(GetDlgItem(hWnd, SSZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HPZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LRZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SBZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ICZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SPZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, GHZ), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, WITCHER1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, WITCHER2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FAST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STR9), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ARK), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ROBI), SW_HIDE);


            ShowWindow(GetDlgItem(hWnd, DEVUSHKA), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, LETO), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SHAG), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SLOVO), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, CIGARET), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PEREMEN), SW_SHOW);


            ShowWindow(GetDlgItem(hWnd, LKI), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ASI), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SFII), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SIII), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, TMNT), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, EJI), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, STRELKA1), SW_SHOW);   //->
            ShowWindow(GetDlgItem(hWnd, STRELKA2), SW_SHOW);   //<-
            ShowWindow(GetDlgItem(hWnd, STRELKA4), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STRELKA3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STRELKA5), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STRELKA6), SW_HIDE);

        }
        if (LOWORD(wParam) == STRELKA4)
        {
            ShowWindow(GetDlgItem(hWnd, SSZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HPZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LRZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SBZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ICZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SPZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, GHZ), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, WITCHER1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, WITCHER2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FAST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STR9), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ARK), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ROBI), SW_HIDE);


            ShowWindow(GetDlgItem(hWnd, DEVUSHKA), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, LETO), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SHAG), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SLOVO), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, CIGARET), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PEREMEN), SW_SHOW);


            ShowWindow(GetDlgItem(hWnd, LKI), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ASI), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SFII), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SIII), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, TMNT), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, EJI), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, STRELKA1), SW_SHOW);   //->
            ShowWindow(GetDlgItem(hWnd, STRELKA2), SW_SHOW);   //<-
            ShowWindow(GetDlgItem(hWnd, STRELKA4), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STRELKA3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STRELKA5), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STRELKA6), SW_HIDE);
        }
        if (LOWORD(wParam) == STRELKA5)
        {
            ShowWindow(GetDlgItem(hWnd, SSZ), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, HPZ), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, LRZ), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SBZ), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, ICZ), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SPZ), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, GHZ), SW_SHOW);

            ShowWindow(GetDlgItem(hWnd, WITCHER1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, WITCHER2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FAST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STR9), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ARK), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ROBI), SW_HIDE);


            ShowWindow(GetDlgItem(hWnd, DEVUSHKA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LETO), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SHAG), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SLOVO), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, CIGARET), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PEREMEN), SW_HIDE);

            



            ShowWindow(GetDlgItem(hWnd, LKI), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ASI), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SFII), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SIII), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, TMNT), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, EJI), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, STRELKA1), SW_HIDE);   //->
            ShowWindow(GetDlgItem(hWnd, STRELKA2), SW_HIDE);   //<-
            ShowWindow(GetDlgItem(hWnd, STRELKA4), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STRELKA3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STRELKA5), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STRELKA6), SW_SHOW);

        }


        if (LOWORD(wParam) == STRELKA6)
        {
            ShowWindow(GetDlgItem(hWnd, SSZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HPZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LRZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SBZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ICZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SPZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, GHZ), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, WITCHER1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, WITCHER2), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, FAST), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, STR9), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, ARK), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, ROBI), SW_SHOW);


            ShowWindow(GetDlgItem(hWnd, DEVUSHKA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LETO), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SHAG), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SLOVO), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, CIGARET), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PEREMEN), SW_HIDE);


            ShowWindow(GetDlgItem(hWnd, LKI), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ASI), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SFII), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SIII), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, TMNT), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, EJI), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, STRELKA1), SW_HIDE);   //->
            ShowWindow(GetDlgItem(hWnd, STRELKA2), SW_HIDE);   //<-
            ShowWindow(GetDlgItem(hWnd, STRELKA4), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, STRELKA3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STRELKA5), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, STRELKA6), SW_HIDE);

        }



        if (LOWORD(wParam) == polupon)
        {
            ShowWindow(GetDlgItem(hWnd, polupon), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, polupoff), SW_SHOW);
            SetWindowLongPtr(hWnd, GWL_EXSTYLE, WS_EX_ACCEPTFILES | WS_EX_LAYERED);
            SetLayeredWindowAttributes(hWnd, NULL, 230, LWA_ALPHA);
        }
        if (LOWORD(wParam) == polupoff)
        {
            ShowWindow(GetDlgItem(hWnd, polupon), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, polupoff), SW_HIDE);
            SetLayeredWindowAttributes(hWnd, NULL, 255, LWA_ALPHA);
            SetWindowLongPtr(hWnd, GWL_EXSTYLE, WS_EX_ACCEPTFILES);
        }





        if (LOWORD(wParam) == SETBKG)
        {


            ShowWindow(GetDlgItem(hWnd, SKINSSTRO), SW_HIDE);
            OPENFILENAME ofnn;

            ZeroMemory(&ofnn, sizeof(OPENFILENAME));
            ofnn.lStructSize = sizeof(OPENFILENAME);
            ofnn.hwndOwner = hWnd;
            ofnn.lpstrFile = str1;
            ofnn.nMaxFile = sizeof(str1);

            ofnn.nFilterIndex = 1;
            ofnn.lpstrFileTitle = NULL;
            ofnn.nMaxFileTitle = 0;
            //ofn.lpstrInitialDir = ".";
            ofnn.lpstrInitialDir = "MusicPlayer\\BMP\\MIXSKIN";
            ofnn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_DONTADDTORECENT | OFN_NOCHANGEDIR;   //Бага больше нет!  А я пока отойду.

            if (GetOpenFileName(&ofnn) == TRUE)
            {
                SetWindowText(eMp3, str1);

                DestroyWindow(hwall);
                DestroyWindow(GetDlgItem(hWnd, INSTBKG));
                ShowWindow(GetDlgItem(hWnd, SKINSSTRO), SW_HIDE);

                ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);

                skins = GetWindowText(eMp3, StrT, MAX_PATH);
                bmpwall = LoadImage(NULL, StrT, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
                bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);

                if (bmpwall != NULL);
                {

                    hwall = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);
                    SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);
                    SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall);

                }
                /*CreateWindow(TEXT("BUTTON"), TEXT("Установить"), WS_VISIBLE | WS_CHILD, 460, 500, 300, 70, hWnd, (HMENU)INSTBKG, NULL, NULL);*/
            }
            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_HIDE);


        }


        if (LOWORD(wParam) == SKIN1)

        {
            DestroyWindow(hwall);

            bmpwall = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\image.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);

            if (bmpwall != NULL);
            {

                hwall = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall);

            }
        }
        if (LOWORD(wParam) == SKIN2)

        {
            DestroyWindow(hwall);

            bmpwall = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\image2.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);

            if (bmpwall != NULL);
            {

                hwall = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall);

            }
        }
        if (LOWORD(wParam) == SKIN3)

        {
            DestroyWindow(hwall);

            bmpwall = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\image3.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);

            if (bmpwall != NULL);
            {

                hwall = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall);

            }
        }
        if (LOWORD(wParam) == SKIN4)

        {
            DestroyWindow(hwall);

            bmpwall = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\image4.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);

            if (bmpwall != NULL);
            {

                hwall = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall);

            }
        }
        if (LOWORD(wParam) == SKIN5)

        {
            DestroyWindow(hwall);

            bmpwall = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\image5.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);

            if (bmpwall != NULL);
            {

                hwall = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall);

            }
        }
        if (LOWORD(wParam) == SKIN6)

        {
            DestroyWindow(hwall);

            bmpwall = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\image6.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);

            if (bmpwall != NULL);
            {

                hwall = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall);

            }
        }
        if (LOWORD(wParam) == SKIN7)

        {
            DestroyWindow(hwall);

            bmpwall = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\image7.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);

            if (bmpwall != NULL);
            {

                hwall = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall);

            }
        }
        if (LOWORD(wParam) == SKIN8)

        {
            DestroyWindow(hwall);

            bmpwall = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\image8.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);

            if (bmpwall != NULL);
            {

                hwall = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall);

            }
        }
        if (LOWORD(wParam) == SKIN9)

        {
            DestroyWindow(hwall);

            bmpwall = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\image9.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);
            bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);

            if (bmpwall != NULL);
            {

                hwall = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall);

            }
        }
        if (LOWORD(wParam) == CLEARSKIN)

        {
            DestroyWindow(hwall);

            bmpwall1 = LoadImage(NULL, "MusicPlayer\\BMP\\MIXSKIN\\clear.png", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT | LR_DEFAULTSIZE);

            if (bmpwall != NULL);
            {

                hwall = CreateWindow("STATIC", NULL, WS_CHILD | WS_VISIBLE | SS_BITMAP | WS_BORDER, 0, 0, 0, 0, hWnd, NULL, NULL, NULL);
                SendMessage(hwall, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bmpwall1);

            }
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


                hBrush = CreateSolidBrush(RGB(0, 76, 153));
                rgbCurrent = RGB(0, 76, 153);
                return 0;
            };


            InvalidateRect(hWnd, NULL, FALSE);

    
        }

        if (LOWORD(wParam) == PLSEL)
        {
            SendMessage(playlist, LB_GETTEXT, SendMessage(playlist, LB_GETCURSEL, 0, 0), (LPARAM)str2);
            SetWindowText(eMp3, str2);
            free_samples_all();
            BASS_Stop();
            BASS_Start();

            int len;
            TCHAR StrB[1200];
            len = GetWindowText(eMp3, StrB, 1200);
            BASS_ChannelStop(stro);

            stro = BASS_StreamCreateFile(FALSE, StrB, 0, 0, 0);

            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается ваша музыка)                                                          "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)text1, NULL, NULL);
            SetWindowText(sbar, "Проигрывается ваша музыка)");
            BASS_ChannelPlay(stro, false); // проигрывание файла
            SendMessage(hTrack2, TBM_SETPOS, TRUE, BASS_ChannelBytes2Seconds(stro, BASS_ChannelGetLength(stro, BASS_POS_BYTE)));
            SendMessage(hTrack2, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(stro, BASS_ChannelGetLength(stro, BASS_POS_BYTE)));
            
            //UpdateWindow(hTrack2);

            //SendMessage(hTrack1, TBM_SETRANGEMIN, TRUE, 0);
            //SendMessage(hTrack1, TBM_SETRANGEMAX, TRUE, BASS_ChannelGetPosition(stro, BASS_POS_BYTE));
            //BASS_ChannelSetAttribute(stro, BASS_ATTRIB_VOL, 1);
            //SendMessage(hTrack, TBM_SETLINESIZE, NULL, 100);
            SetWindowText(sbar, "Проигрывается ваша музыка)");
            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);

            without_stro();


            ShowWindow(GetDlgItem(hWnd, LENMUSIC), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, VOLUMASTA), SW_SHOW);
            ShowWindow(hTrack2, SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SOUNDMASTA), SW_SHOW);


        }
        if (LOWORD(wParam) == PLADD)
        {



            OPENFILENAME ofn;

            ZeroMemory(&ofn, sizeof(OPENFILENAME));
            ofn.lStructSize = sizeof(OPENFILENAME);
            ofn.hwndOwner = hWnd;
            ofn.lpstrFile = str1;
            ofn.nMaxFile = sizeof(str1);
            //ofn.lpstrFilter = "MP3\0.MP3\0WAV\0.WAV\0";
            //ofn.lpstrFilter = ".mp3\0.wav\0.mp4\0.ogg\0";
            ofn.nFilterIndex = 1;
            ofn.lpstrFileTitle = NULL;
            ofn.nMaxFileTitle = 0;
            //ofn.lpstrInitialDir = ".";
            ofn.lpstrInitialDir = "MusicPlayer\\Your";
            ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_DONTADDTORECENT | OFN_NOCHANGEDIR;   //Бага больше нет!  А я пока отойду.

            if (GetOpenFileName(&ofn) == TRUE)
            {
               
                SetWindowText(eMp3, str1);
                GetWindowText(eMp3, str1, MAX_PATH);
                SendMessage(playlist, LB_ADDSTRING, 0, (LPARAM)str1);
            }








        }
        if (LOWORD(wParam) == PLDEL)
        {
            SendMessage(playlist, LB_DELETESTRING, 0, SendMessage(playlist, LB_GETCURSEL, 0, 0));
        }


        if (LOWORD(wParam) == MENUMAKER)
        {
            WIN32_FIND_DATA menumaker;
            HANDLE hFind = FindFirstFile("MusicPlayer\\MENUMAKER\\MENUMAKER.exe", &menumaker);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                system("start MusicPlayer\\MENUMAKER\\MENUMAKER.exe");

            }


            else
            {
                VISTA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\xp.mp3", 0, 0, 0);
                BASS_ChannelPlay(VISTA, false);
                if (MessageBox(hWnd, "Ошибка с кодом 0xc000008b \n(Установите контекстменюмейкер)\nХотите установить и исправить ошибку?", "MixOS: YOUTUBE NOT FOUND", MB_YESNO | MB_ICONQUESTION) == IDYES)
                {
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/MENUMAKER/MENUMAKER.zip", "MusicPlayer\\MENUMAKER.zip", 0, 0);
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UTILITIES/Install.zip", "MusicPlayer\\Install.zip", 0, 0);
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UTILITIES/Progs.zip", "MusicPlayer\\Progs.zip", 0, 0);
                    system("MusicPlayer\\MENUMAKER.bat");
                    WIN32_FIND_DATA youtubckic;
                    HANDLE hFind = FindFirstFile("MusicPlayer\\MENUMAKER\\MENUMAKER.exe", &youtubckic);
                    if (INVALID_HANDLE_VALUE != hFind)
                    {
                        MessageBoxA(hWnd, "Теперь можете пользоваться\nКонтекстменюмейкером\nОшибка исправлена!!", "Успех!", MB_ICONASTERISK);
                    }
                    else
                    {
                        MessageBoxA(hWnd, "Ошибка не была исправлена. Возможно проблема с интернетом. Либо пишите разработчику", "Неудача", MB_ICONASTERISK);
                    };

                }

            };
            return false;
            FindClose(hFind);

        
        }
        if (LOWORD(wParam) == ERTOR)
        {
            system("start MusicPlayer\\SUBS\\ERTOR\\gen.exe");

        }
        if (LOWORD(wParam) == PHOTOVIEWER)
        { 
            WIN32_FIND_DATA photoview;
            HANDLE hFind = FindFirstFile("MusicPlayer\\MENUMAKER\\MENUMAKER.exe", &photoview);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                system("start MusicPlayer\\PhotoViewer\\CreeperPhotoViewer.exe");

            }

            if (INVALID_HANDLE_VALUE == hFind)
            {
                BASS_ChannelPlay(ERRORS, false);
                if (MessageBox(hWnd, "Ошибка с кодом 0xc000009b \n(Установите просмотрщик фотографий)\nЖелаете установить?", "MixOS: PHOTOVIEWER_NOT_FOUND", MB_YESNO | MB_ICONERROR) == IDYES)
                {
                    PostQuitMessage(0);
                }
            }
        }

        if (LOWORD(wParam) == YOUTUBE)
        {
            WIN32_FIND_DATA youtubckic;
            HANDLE hFind = FindFirstFile("MusicPlayer\\Youtube\\yt-dlp.exe", &youtubckic);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                system("start MusicPlayer\\Youtube\\Youtube.exe");

            }

            else
            {
                VISTA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\xp.mp3", 0, 0, 0);
                BASS_ChannelPlay(VISTA, false);
                if (MessageBox(hWnd, "Ошибка с кодом 0xc000002b \n(Загрузчик видео с Youtube не найден)\nХотите установить и исправить ошибку?", "MixOS: YOUTUBE NOT FOUND",MB_YESNO| MB_ICONQUESTION) == IDYES)
                {
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/YOUTUBE/Youtube.zip", "MusicPlayer\\Youtube.zip", 0, 0);

                    system("MusicPlayer\\YT.bat");
                    WIN32_FIND_DATA youtubckic;
                    HANDLE hFind = FindFirstFile("MusicPlayer\\Youtube\\yt-dlp.exe", &youtubckic);
                    if (INVALID_HANDLE_VALUE != hFind)
                    {
                        MessageBoxA(hWnd, "Теперь можете пользоваться\nЗагрузчиком видеороликов\nОшибка исправлена!!", "Успех!", MB_ICONASTERISK);
                    }
                    else
                    {
                        MessageBoxA(hWnd, "Ошибка не была исправлена. Возможно проблема с интернетом. Либо пишите разработчику", "Неудача", MB_ICONASTERISK);
                    };

                }

            };
            return false;
            FindClose(hFind);
        }
        if (LOWORD(wParam) == UPDATEFIND)
        {
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UPDATE.mixos", "MusicPlayer\\UPDATE.MIXOS", 0, 0);
                    system("start notepad MusicPlayer\\UPDATE.MIXOS");
                    system("del MusicPlayer\\UPDATE.MIXOS");
                    
          

        }
        if (LOWORD(wParam) == HW)
        {
            //WIN32_FIND_DATA hwmon;
            //HANDLE hFind = FindFirstFile("MusicPlayer\\Install\\HW\\HW.exe", &hwmon);

            //if (INVALID_HANDLE_VALUE != hFind)
            //{
            //    system("start MusicPlayer\\Install\\HW\\HW.exe");

            //}

            //if (INVALID_HANDLE_VALUE == hFind)
            //{
            //    BASS_ChannelPlay(ERRORS, false);
            //    if (MessageBox(hWnd, "Ошибка с кодом 0xc000001c \n(HW monitor не найден)\nЖелаете установить?", "MixOS: HW_NOT_FOUND", MB_YESNO | MB_ICONERROR) == IDYES)
            //    {
            //        PostQuitMessage(0);
            //    }
            //}

            WIN32_FIND_DATA youtubckic;
            HANDLE hFind = FindFirstFile("MusicPlayer\\Install\\HW\\HW.exe", &youtubckic);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                system("start MusicPlayer\\Install\\HW\\HW.exe");

            }

            else
            {
                VISTA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\xp.mp3", 0, 0, 0);
                BASS_ChannelPlay(VISTA, false);
                if (MessageBox(hWnd, "Ошибка с кодом 0xc000008b \n(Установите Утилиты+Контекстменюмейке)\nХотите установить и исправить ошибку?", "MixOS: UTILITIES NOT FOUND", MB_YESNO | MB_ICONQUESTION) == IDYES)
                {
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/MENUMAKER/MENUMAKER.zip", "MusicPlayer\\MENUMAKER.zip", 0, 0);
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UTILITIES/Install.zip", "MusicPlayer\\Install.zip", 0, 0);
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UTILITIES/Progs.zip", "MusicPlayer\\Progs.zip", 0, 0);
                    system("MusicPlayer\\MENUMAKER.bat");
                    WIN32_FIND_DATA youtubckic;
                    HANDLE hFind = FindFirstFile("MusicPlayer\\MENUMAKER\\MENUMAKER.exe", &youtubckic);
                    if (INVALID_HANDLE_VALUE != hFind)
                    {
                        MessageBoxA(hWnd, "Теперь можете пользоваться\nУтилитами+контекстменюмейкером\nОшибка исправлена!!", "Успех!", MB_ICONASTERISK);
                    }
                    else
                    {
                        MessageBoxA(hWnd, "Ошибка не была исправлена. Возможно проблема с интернетом. Либо пишите разработчику", "Неудача", MB_ICONASTERISK);
                    };

                }

            };
            return false;
            FindClose(hFind);


            
        }

        if (LOWORD(wParam) == VEGAS)
        {


            WIN32_FIND_DATA cpuzz;
            HANDLE hFind = FindFirstFile("MusicPlayer\\Install\\CPUZ\\cpuz64.exe", &cpuzz);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                system("start MusicPlayer\\Install\\CPUZ\\cpuz64.exe");

            }

            else
            {
                VISTA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\xp.mp3", 0, 0, 0);
                BASS_ChannelPlay(VISTA, false);
                if (MessageBox(hWnd, "Ошибка с кодом 0xc000008b \n(Установите Утилиты+Контекстменюмейкер)\nХотите установить и исправить ошибку?", "MixOS: UTILITIES NOT FOUND", MB_YESNO | MB_ICONQUESTION) == IDYES)
                {
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/MENUMAKER/MENUMAKER.zip", "MusicPlayer\\MENUMAKER.zip", 0, 0);
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UTILITIES/Install.zip", "MusicPlayer\\Install.zip", 0, 0);
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UTILITIES/Progs.zip", "MusicPlayer\\Progs.zip", 0, 0);
                    system("MusicPlayer\\MENUMAKER.bat");
                    WIN32_FIND_DATA youtubckic;
                    HANDLE hFind = FindFirstFile("MusicPlayer\\MENUMAKER\\MENUMAKER.exe", &youtubckic);
                    if (INVALID_HANDLE_VALUE != hFind)
                    {
                        MessageBoxA(hWnd, "Теперь можете пользоваться\nУтилитами+контекстменюмейкером\nОшибка исправлена!!", "Успех!", MB_ICONASTERISK);
                    }
                    else
                    {
                        MessageBoxA(hWnd, "Ошибка не была исправлена. Возможно проблема с интернетом. Либо пишите разработчику", "Неудача", MB_ICONASTERISK);
                    };

                }

            };
            return false;
            FindClose(hFind);

            
        }

        if (LOWORD(wParam) == OBS)
        {
            WIN32_FIND_DATA cpuzz;
            HANDLE hFind = FindFirstFile("MusicPlayer\\Install\\CPUZ\\cpuz64.exe", &cpuzz);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                system("start MusicPlayer\\Install\\CPUZ\\cpuz64.exe");

            }

            else
            {
                VISTA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\xp.mp3", 0, 0, 0);
                BASS_ChannelPlay(VISTA, false);
                if (MessageBox(hWnd, "Ошибка с кодом 0xc000008b \n(Установите Утилиты+Контекстменюмейкер)\nХотите установить и исправить ошибку?", "MixOS: UTILITIES NOT FOUND", MB_YESNO | MB_ICONQUESTION) == IDYES)
                {
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/MENUMAKER/MENUMAKER.zip", "MusicPlayer\\MENUMAKER.zip", 0, 0);
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UTILITIES/Install.zip", "MusicPlayer\\Install.zip", 0, 0);
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UTILITIES/Progs.zip", "MusicPlayer\\Progs.zip", 0, 0);
                    system("MusicPlayer\\MENUMAKER.bat");
                    WIN32_FIND_DATA youtubckic;
                    HANDLE hFind = FindFirstFile("MusicPlayer\\MENUMAKER\\MENUMAKER.exe", &youtubckic);
                    if (INVALID_HANDLE_VALUE != hFind)
                    {
                        MessageBoxA(hWnd, "Теперь можете пользоваться\nУтилитами+контекстменюмейкером\nОшибка исправлена!!", "Успех!", MB_ICONASTERISK);
                    }
                    else
                    {
                        MessageBoxA(hWnd, "Ошибка не была исправлена. Возможно проблема с интернетом. Либо пишите разработчику", "Неудача", MB_ICONASTERISK);
                    };

                }

            };
            return false;
            FindClose(hFind);
        }

        if (LOWORD(wParam) == VISUALSTUDIO)
        {
            WIN32_FIND_DATA cpuzz;
            HANDLE hFind = FindFirstFile("MusicPlayer\\Install\\VisualStudio\\Setup.exe", &cpuzz);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                system("start MusicPlayer\\Install\\VisualStudio\\Setup.exe");

            }

            else
            {
                VISTA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\xp.mp3", 0, 0, 0);
                BASS_ChannelPlay(VISTA, false);
                if (MessageBox(hWnd, "Ошибка с кодом 0xc000008b \n(Установите Утилиты+Контекстменюмейкер)\nХотите установить и исправить ошибку?", "MixOS: UTILITIES NOT FOUND", MB_YESNO | MB_ICONQUESTION) == IDYES)
                {
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/MENUMAKER/MENUMAKER.zip", "MusicPlayer\\MENUMAKER.zip", 0, 0);
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UTILITIES/Install.zip", "MusicPlayer\\Install.zip", 0, 0);
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UTILITIES/Progs.zip", "MusicPlayer\\Progs.zip", 0, 0);
                    system("MusicPlayer\\MENUMAKER.bat");
                    WIN32_FIND_DATA youtubckic;
                    HANDLE hFind = FindFirstFile("MusicPlayer\\MENUMAKER\\MENUMAKER.exe", &youtubckic);
                    if (INVALID_HANDLE_VALUE != hFind)
                    {
                        MessageBoxA(hWnd, "Теперь можете пользоваться\nУтилитами+контекстменюмейкером\nОшибка исправлена!!", "Успех!", MB_ICONASTERISK);
                    }
                    else
                    {
                        MessageBoxA(hWnd, "Ошибка не была исправлена. Возможно проблема с интернетом. Либо пишите разработчику", "Неудача", MB_ICONASTERISK);
                    };

                }

            };
            return false;
            FindClose(hFind);
            
        }

        if (LOWORD(wParam) == MAIL)
        {
            BASS_StreamFree(VISTA);
            BASS_ChannelStop(VISTA);
            BASS_SampleFree(VISTA);
            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
            BASS_Stop();
            BASS_Start();
            VISTA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\title4.mp3", 0, 0, 0);
            BASS_ChannelPlay(VISTA, false);
            system("start https://lesergig.wixsite.com/strannikyt/voprosy-i-otvety");
        }



        if (LOWORD(wParam) == BOMB)
        {
            WIN32_FIND_DATA cpuzz;
            HANDLE hFind = FindFirstFile("MusicPlayer\\Install\\CPUZ\\cpuz64.exe", &cpuzz);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                system("start MusicPlayer\\Install\\CPUZ\\cpuz64.exe");

            }

            else
            {
                VISTA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\xp.mp3", 0, 0, 0);
                BASS_ChannelPlay(VISTA, false);
                if (MessageBox(hWnd, "Ошибка с кодом 0xc000008b \n(Установите Утилиты+Контекстменюмейкер)\nХотите установить и исправить ошибку?", "MixOS: UTILITIES NOT FOUND", MB_YESNO | MB_ICONQUESTION) == IDYES)
                {
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/MENUMAKER/MENUMAKER.zip", "MusicPlayer\\MENUMAKER.zip", 0, 0);
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UTILITIES/Install.zip", "MusicPlayer\\Install.zip", 0, 0);
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UTILITIES/Progs.zip", "MusicPlayer\\Progs.zip", 0, 0);
                    system("MusicPlayer\\MENUMAKER.bat");
                    WIN32_FIND_DATA youtubckic;
                    HANDLE hFind = FindFirstFile("MusicPlayer\\MENUMAKER\\MENUMAKER.exe", &youtubckic);
                    if (INVALID_HANDLE_VALUE != hFind)
                    {
                        MessageBoxA(hWnd, "Теперь можете пользоваться\nУтилитами+контекстменюмейкером\nОшибка исправлена!!", "Успех!", MB_ICONASTERISK);
                    }
                    else
                    {
                        MessageBoxA(hWnd, "Ошибка не была исправлена. Возможно проблема с интернетом. Либо пишите разработчику", "Неудача", MB_ICONASTERISK);
                    };

                }

            };
            return false;
            FindClose(hFind);
            
        }
        if (LOWORD(wParam) == SPY)
        {
            system("start MusicPlayer\\Progs\\SHUTUP\\KILLSPY.exe");
        }
        if (LOWORD(wParam) == PANEL)
        {
            system("start control");
        }








        


        if (LOWORD(wParam) == VISUAL)
        {



            WIN32_FIND_DATA VSS;
            HANDLE hFind = FindFirstFile("MusicPlayer\\Install\\VS\\Visual\\Visual.bat", &VSS);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                system("start MusicPlayer\\Install\\VS\\Visual\\Visual.bat");

            }

            else
            {
                VISTA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\xp.mp3", 0, 0, 0);
                BASS_ChannelPlay(VISTA, false);
                if (MessageBox(hWnd, "Ошибка с кодом 0xc000012c \n(Установите VS C++)\nХотите установить и исправить ошибку?", "MixOS: VS NOT FOUND", MB_YESNO | MB_ICONQUESTION) == IDYES)
                {
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/UTILITIES/VS.zip", "MusicPlayer\\VS.zip", 0, 0);
                    system("start MusicPlayer\\VS.bat");
                    WIN32_FIND_DATA youtubckic;
                    HANDLE hFind = FindFirstFile("MusicPlayer\\MENUMAKER\\MENUMAKER.exe", &youtubckic);
                    if (INVALID_HANDLE_VALUE != hFind)
                    {
                        MessageBoxA(hWnd, "Ошибка исправлена!!", "Успех!", MB_ICONASTERISK);
                    }
                    else
                    {
                        MessageBoxA(hWnd, "Ошибка не была исправлена. Возможно проблема с интернетом. Либо пишите разработчику", "Неудача", MB_ICONASTERISK);
                    };

                }

            };
            return false;
            FindClose(hFind);




        }
        if (LOWORD(wParam) == OLDVER13)
        {


            WIN32_FIND_DATA OLDOLD;
            HANDLE hFind = FindFirstFile("MusicPlayer\\OLD\\1.3.bat", &OLDOLD);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                MessageBoxA(hWnd, "Сейчас будет запущен плеер версии Beta 1.3. По сути это прадедушка MixOS. С него всё и началось.", "MusicPlayer Beta 1.3", MB_ICONINFORMATION);
                system("start MusicPlayer\\OLD\\1.3.bat");

            }

            else
            {
                VISTA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\xp.mp3", 0, 0, 0);
                BASS_ChannelPlay(VISTA, false);
                if (MessageBox(hWnd, "Ошибка с кодом 0xс000035b \n(Установите MixOS Beta 1.3)\nЖелаете установить?", "MixOS: MixOS NOT FOUND", MB_YESNO | MB_ICONERROR) == IDYES)
                {

                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/OLD/OLD.mixos", "MusicPlayer\\OLD.zip", 0, 0);

                    system("MusicPlayer\\OLD.bat");
                    WIN32_FIND_DATA OLDOLD;
                    HANDLE hFind = FindFirstFile("MusicPlayer\\OLD\\1.3.bat", &OLDOLD);
                    if (INVALID_HANDLE_VALUE != hFind)
                    {
                        MessageBoxA(hWnd, "Теперь можете пользоваться MixOS beta 1.3\nОшибка исправлена!!", "Успех!", MB_ICONASTERISK);
                    }
                    else
                    {
                        MessageBoxA(hWnd, "Ошибка не была исправлена. Возможно проблема с интернетом. Либо пишите разработчику", "Неудача", MB_ICONASTERISK);
                    };

                }

            };
            return false;
            FindClose(hFind);




        }
        if (LOWORD(wParam) == OLDVER15)
        {
            
            

            WIN32_FIND_DATA OLDOLD;
            HANDLE hFind = FindFirstFile("MusicPlayer\\OLD\\1.5.bat", &OLDOLD);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                MessageBoxA(hWnd, "Сейчас будет запущен плеер версии Beta 1.5. Официально это первая графическая версия моего плеера.\nНеофициально это была Beta 1.4. ", "MusicPlayer Beta 1.5", MB_ICONINFORMATION);
                system("start MusicPlayer\\OLD\\1.5.bat");

            }

            else
            {
                VISTA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\xp.mp3", 0, 0, 0);
                BASS_ChannelPlay(VISTA, false);
                if (MessageBox(hWnd, "Ошибка с кодом 0xс000034b \n(Установите MixOS Beta 1.5)\nЖелаете установить?", "MixOS: MixOS NOT FOUND", MB_YESNO | MB_ICONERROR) == IDYES)
                {

                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/OLD/OLD.mixos", "MusicPlayer\\OLD.zip", 0, 0);

                    system("MusicPlayer\\OLD.bat");
                    WIN32_FIND_DATA OLDOLD;
                    HANDLE hFind = FindFirstFile("MusicPlayer\\OLD\\1.5.bat", &OLDOLD);
                    if (INVALID_HANDLE_VALUE != hFind)
                    {
                        MessageBoxA(hWnd, "Теперь можете пользоваться MixOS beta 1.5\nОшибка исправлена!!", "Успех!", MB_ICONASTERISK);
                    }
                    else
                    {
                        MessageBoxA(hWnd, "Ошибка не была исправлена. Возможно проблема с интернетом. Либо пишите разработчику", "Неудача", MB_ICONASTERISK);
                    };

                }

            };
            return false;
            FindClose(hFind);





        }
        if (LOWORD(wParam) == TERMINAL)
        {

            WIN32_FIND_DATA TERM;
            HANDLE hFind = FindFirstFile("MusicPlayer\\TERMINAL\\TERMINAL.exe", &TERM);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                system("start MusicPlayer\\TERMINAL\\TERMINAL.EXE");

            }
        
        else
        {
            VISTA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\xp.mp3", 0, 0, 0);
            BASS_ChannelPlay(VISTA, false);
            if (MessageBox(hWnd, "Ошибка с кодом 0xс000024b \n(Установите терминал)\nЖелаете установить?", "MixOS: TERMINAL NOT FOUND", MB_YESNO | MB_ICONERROR) == IDYES)
            {

                URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/TERMINAL/TERMINAL.zip", "MusicPlayer\\TERMINAL.zip", 0, 0);

                system("MusicPlayer\\TERMINAL.bat");
                WIN32_FIND_DATA TERM;
                HANDLE hFind = FindFirstFile("MusicPlayer\\TERMINAL\\TERMINAL.exe", &TERM);
                if (INVALID_HANDLE_VALUE != hFind)
                {
                    MessageBoxA(hWnd, "Теперь можете пользоваться терминалом\nОшибка исправлена!!", "Успех!", MB_ICONASTERISK);
                }
                else
                {
                    MessageBoxA(hWnd, "Ошибка не была исправлена. Возможно проблема с интернетом. Либо пишите разработчику", "Неудача", MB_ICONASTERISK);
                };

            }

        };
        return false;
        FindClose(hFind);




        }

        if (LOWORD(wParam) == PIANINO)
        {
            WIN32_FIND_DATA Piano;
            HANDLE hFind = FindFirstFile("MusicPlayer\\Piano\\Piano.exe", &Piano);

            //if (INVALID_HANDLE_VALUE != hFind)
            //{
            //    system("start MusicPlayer\\Piano\\Piano.exe");

            //}

            //if (INVALID_HANDLE_VALUE == hFind)
            //{
            //    TERMINALERROR = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\xp.mp3", 0, 0, 0);
            //    BASS_ChannelPlay(TERMINALERROR, false);
            //    if (MessageBox(hWnd, "Ошибка с кодом 0xс000004b \n(Установите пианино)", "MixOS: PIANO NOT FOUND", MB_OK | MB_ICONERROR) != IDOK)
            //    {
            //        PostQuitMessage(0);
            //    }
            //}
            if (INVALID_HANDLE_VALUE != hFind)
            {
                system("start MusicPlayer\\Piano\\Piano.exe");

            }

            else
            {
                VISTA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\xp.mp3", 0, 0, 0);
                BASS_ChannelPlay(VISTA, false);
                if (MessageBox(hWnd, "Ошибка с кодом 0xс000004b \n(Установите пианино)\nЖелаете установить?", "MixOS: PIANO NOT FOUND", MB_YESNO | MB_ICONERROR) == IDYES)
                {
                    
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/PIANO/Piano.zip", "MusicPlayer\\Piano.zip", 0, 0);

                    system("MusicPlayer\\Piano.bat");
                    WIN32_FIND_DATA youtubckic;
                    HANDLE hFind = FindFirstFile("MusicPlayer\\Piano\\Piano.exe", &youtubckic);
                    if (INVALID_HANDLE_VALUE != hFind)
                    {
                        MessageBoxA(hWnd, "Теперь можете пользоваться пианино\nОшибка исправлена!!", "Успех!", MB_ICONASTERISK);
                    }
                    else
                    {
                        MessageBoxA(hWnd, "Ошибка не была исправлена. Возможно проблема с интернетом. Либо пишите разработчику", "Неудача", MB_ICONASTERISK);
                    };

                }

            };
            return false;
            FindClose(hFind);

        }
        if (LOWORD(wParam) == CONVERTER)
        {
            system("start MusicPlayer\\CONVERT\\converter.exe");

        }

        if (LOWORD(wParam) == EMULATE || LOWORD(wParam) == Emulators)
        {

            WIN32_FIND_DATA WINCOLLECTION;
            HANDLE hFind = FindFirstFile("MusicPlayer\\Emulators\\Emulate.exe", &WINCOLLECTION);

            if (INVALID_HANDLE_VALUE != hFind)
            {
                system("start MusicPlayer\\Emulators\\Emulate.exe");

            }

            else
            {
                VISTA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\SYSTEM\\WINDOWS\\SOUNDS\\ERROR\\xp.mp3", 0, 0, 0);
                BASS_ChannelPlay(VISTA, false);
                if (MessageBox(hWnd, "Ошибка с кодом 0xс000009b \n(Установите Список Эмуляторов)\nХотите установить?", "MixOS: EMULATORS NOT FOUND", MB_OK | MB_ICONERROR) == IDOK)
                {
                    /*thread th(CreateWindow(TEXT("STATIC"), TEXT("Скачано 6,25%"), WS_VISIBLE | WS_CHILD, 400, 15, 280, 25, hWnd, (HMENU)NULL, NULL, NULL));*/
                    MessageBoxA(hWnd, "Пока терминал будет скачивать,\nон зависнет, но доверьтесь и не закрывайте)", "ВНИМАНИЕ", MB_ICONASTERISK);
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/EMULATORS/1.zip", "MusicPlayer\\1.zip", 0, 0);


                    /*SendMessage(eMp3, EM_SETCUEBANNER, 0, (LPARAM)L"Напишите название пункта меню");*/
                    /*SendMessage(hwall, EM_SETCUEBANNER, 0, (LPARAM)L"Напишите название пункта меню");*/
                    /*SendMessage(COM, EM_SETCUEBANNER, 0, (LPARAM)L"Напишите название пункта меню");*/

                    /*SendMessage(hProgBar, PBM_STEPIT, 0, 0);*/
                    system("echo Скачивается 2.zip");
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/EMULATORS/2.zip", "MusicPlayer\\2.zip", 0, 0);

                    /*CreateWindow(TEXT("STATIC"), TEXT("Скачано 12,50%"), WS_VISIBLE | WS_CHILD, 400, 15, 280, 25, hWnd, (HMENU)NULL, NULL, NULL);*/

                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/EMULATORS/3.zip", "MusicPlayer\\3.zip", 0, 0);
                    /*CreateWindow(TEXT("STATIC"), TEXT("Скачано 18,75%"), WS_VISIBLE | WS_CHILD, 400, 15, 280, 25, hWnd, (HMENU)NULL, NULL, NULL);*/


                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/EMULATORS/4.zip", "MusicPlayer\\4.zip", 0, 0);
                    /* CreateWindow(TEXT("STATIC"), TEXT("Скачано 25,00%"), WS_VISIBLE | WS_CHILD, 400, 15, 280, 25, hWnd, (HMENU)text2, NULL, NULL);*/

                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/EMULATORS/5.zip", "MusicPlayer\\5.zip", 0, 0);
                    /*CreateWindow(TEXT("STATIC"), TEXT("Скачано 31,25"), WS_VISIBLE | WS_CHILD, 400, 15, 280, 25, hWnd, (HMENU)text2, NULL, NULL);*/

                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/EMULATORS/6.zip", "MusicPlayer\\6.zip", 0, 0);
                    /*CreateWindow(TEXT("STATIC"), TEXT("Скачано 37,50%"), WS_VISIBLE | WS_CHILD, 400, 15, 280, 25, hWnd, (HMENU)text2, NULL, NULL);*/


                    /*system("MusicPlayer\\emulate.bat");*/
                    /*URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/EMULATORS/W311.zip", "MusicPlayer\\W311.zip", 0, 0);*/
                    system("MusicPlayer\\emulate2.bat");
                    /*CreateWindow(TEXT("STATIC"), TEXT("Скачано 42,50%"), WS_VISIBLE | WS_CHILD, 400, 15, 280, 25, hWnd, (HMENU)text2, NULL, NULL);*/
                    /*URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/EMULATORS/W311.zip", "MusicPlayer\\7.zip", 0, 0);*/
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/EMULATORS/R/W311.7z.001", "MusicPlayer\\W311.7z.001", 0, 0);
                    /*CreateWindow(TEXT("STATIC"), TEXT("Скачано 43,75%"), WS_VISIBLE | WS_CHILD, 400, 15, 280, 25, hWnd, (HMENU)text2, NULL, NULL);*/

                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/EMULATORS/R/W311.7z.002", "MusicPlayer\\W311.7z.002", 0, 0);
                    /*CreateWindow(TEXT("STATIC"), TEXT("Скачано 50,00%"), WS_VISIBLE | WS_CHILD, 400, 15, 280, 25, hWnd, (HMENU)text2, NULL, NULL);*/
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/EMULATORS/R/W311.7z.003", "MusicPlayer\\W311.7z.003", 0, 0);
                    /*CreateWindow(TEXT("STATIC"), TEXT("Скачано 56,25%"), WS_VISIBLE | WS_CHILD, 400, 15, 280, 25, hWnd, (HMENU)text2, NULL, NULL);*/
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/EMULATORS/R/W311.7z.004", "MusicPlayer\\W311.7z.004", 0, 0);
                    /*CreateWindow(TEXT("STATIC"), TEXT("Скачано 62,50%"), WS_VISIBLE | WS_CHILD, 400, 15, 280, 25, hWnd, (HMENU)text2, NULL, NULL);*/
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/EMULATORS/R/W311.7z.005", "MusicPlayer\\W311.7z.005", 0, 0);
                    /*CreateWindow(TEXT("STATIC"), TEXT("Скачано 68,75%"), WS_VISIBLE | WS_CHILD, 400, 15, 280, 25, hWnd, (HMENU)text2, NULL, NULL);*/
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/EMULATORS/R/W311.7z.006", "MusicPlayer\\W311.7z.006", 0, 0);
                    /*CreateWindow(TEXT("STATIC"), TEXT("Скачано 75,00%"), WS_VISIBLE | WS_CHILD, 400, 15, 280, 25, hWnd, (HMENU)text2, NULL, NULL);*/
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/EMULATORS/R/W311.7z.007", "MusicPlayer\\W311.7z.007", 0, 0);
                    /*CreateWindow(TEXT("STATIC"), TEXT("Скачано 81,25%"), WS_VISIBLE | WS_CHILD, 400, 15, 280, 25, hWnd, (HMENU)text2, NULL, NULL);*/
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/EMULATORS/R/W311.7z.008", "MusicPlayer\\W311.7z.008", 0, 0);
                    /*CreateWindow(TEXT("STATIC"), TEXT("Скачано 87,5%"), WS_VISIBLE | WS_CHILD, 400, 15, 280, 25, hWnd, (HMENU)text2, NULL, NULL);*/
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/EMULATORS/R/W311.7z.009", "MusicPlayer\\W311.7z.009", 0, 0);
                    /*CreateWindow(TEXT("STATIC"), TEXT("Скачано 93,75%"), WS_VISIBLE | WS_CHILD, 400, 15, 280, 25, hWnd, (HMENU)text2, NULL, NULL);*/
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/EMULATORS/R/W311.7z.010", "MusicPlayer\\W311.7z.010", 0, 0);
                    /*CreateWindow(TEXT("STATIC"), TEXT("Скачано 99,99%"), WS_VISIBLE | WS_CHILD, 400, 15, 280, 25, hWnd, (HMENU)text2, NULL, NULL);*/
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/EMULATORS/8.zip", "MusicPlayer\\8.zip", 0, 0);
                    /*CreateWindow(TEXT("STATIC"), TEXT("              "), WS_VISIBLE | WS_CHILD, 400, 15, 280, 25, hWnd, (HMENU)text2, NULL, NULL);*/

                    system("MusicPlayer\\emulate3.bat");
                    WIN32_FIND_DATA youtubckic;
                    HANDLE hFind = FindFirstFile("MusicPlayer\\Emulators\\Emulate.exe", &youtubckic);
                    if (INVALID_HANDLE_VALUE != hFind)
                    {
                        MessageBoxA(hWnd, "Теперь можете пользоваться Сборником Эмуляторов\nОшибка исправлена!!", "Успех!", MB_ICONASTERISK);
                    }
                    else
                    {
                        MessageBoxA(hWnd, "Ошибка не была исправлена. Возможно проблема с интернетом. Либо пишите разработчику", "Неудача", MB_ICONASTERISK);
                    };

                }

            };
            return false;
            FindClose(hFind);
        }
        if (LOWORD(wParam) == DEVUSHKA)
        {
            BASS_Stop();

            BASS_Start();
         
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - Morning                                                 "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)DEFDEF, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Headless Nick - Morning");
            free_samples_all();
            MORNING = BASS_StreamCreateFile(FALSE, "MusicPlayer\\HeadlessNick\\Morning.mp3", 0, 0, 0);


            BASS_ChannelPlay(MORNING, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(MORNING, BASS_ChannelGetLength(MORNING, BASS_POS_BYTE)));

        }
        if (LOWORD(wParam) == LETO)
        {
            BASS_Stop();
            BASS_Start();
            ShowWindow(GetDlgItem(hWnd, DEFDEF), SW_HIDE);
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - UFO                                                               "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Captain Strannik - SeasonFlights");
            free_samples_all();
            UFO = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\SF.mp3", 0, 0, 0);

            BASS_ChannelPlay(UFO, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(UFO, BASS_ChannelGetLength(UFO, BASS_POS_BYTE)));

        }
        if (LOWORD(wParam) == SHAG)
        {
            BASS_Stop();
            BASS_Start();
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - Sample Adventures.mp3                                                 "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI1, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Headless Nick - Sample Adventures.mp3");
            free_samples_all();
            SAMPLEADV = BASS_StreamCreateFile(FALSE, "MusicPlayer\\HeadlessNick\\Sample Adventures.mp3", 0, 0, 0);


            BASS_ChannelPlay(SAMPLEADV, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(SAMPLEADV, BASS_ChannelGetLength(SAMPLEADV, BASS_POS_BYTE)));
        }
        if (LOWORD(wParam) == SLOVO)
        {
            BASS_Stop();
            BASS_Start();
            BASS_SampleFree(VISTA);
            BASS_ChannelFree(VISTA);
            BASS_StreamFree(VISTA);
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Deteez - Above the Sky.mp3                                         "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI2, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Deteez - Above the Sky.mp3");
            free_samples_all();
            EYES = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Violet S\\Above the Sky.mp3", 0, 0, 0);

            BASS_ChannelPlay(EYES, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(EYES, BASS_ChannelGetLength(EYES, BASS_POS_BYTE)));

        }
        if (LOWORD(wParam) == CIGARET)
        {
            BASS_Stop();
            BASS_Start();
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Violet S - Lonely.mp3                                                         "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI3, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Violet S - Lonely.mp3");
            free_samples_all();
            LONELY = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Violet S\\Lonely.mp3", 0, 0, 0);

            BASS_ChannelPlay(LONELY, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(LONELY, BASS_ChannelGetLength(LONELY, BASS_POS_BYTE)));

        }
        if (LOWORD(wParam) == PEREMEN)
        {
            BASS_Stop();
            BASS_Start();

            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Captain Strannik - Hard Thing.mp3           "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI4, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Phasmaton - Heresy.mp3");
            free_samples_all();
            GIRL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Violet S\\Phasmaton - Heresy.mp3", 0, 0, 0);


            BASS_ChannelPlay(GIRL, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(GIRL, BASS_ChannelGetLength(GIRL, BASS_POS_BYTE)));
        }





















        if (LOWORD(wParam) == WITCHER1)
        {
            BASS_Stop();

            BASS_Start();

            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - Morning                                                 "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)DEFDEF, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Witcher 3 Skellige Theme");
            free_samples_all();
            MORNING = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\Skellige.mp3", 0, 0, 0);


            BASS_ChannelPlay(MORNING, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(MORNING, BASS_ChannelGetLength(MORNING, BASS_POS_BYTE)));

        }
        if (LOWORD(wParam) == WITCHER2)
        {
            BASS_Stop();
            BASS_Start();
            ShowWindow(GetDlgItem(hWnd, DEFDEF), SW_HIDE);
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - UFO                                                               "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Witcher 3 Kaer Morhen");
            free_samples_all();
            UFO = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\Kaer Morhen.mp3", 0, 0, 0);

            BASS_ChannelPlay(UFO, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(UFO, BASS_ChannelGetLength(UFO, BASS_POS_BYTE)));

        }
        if (LOWORD(wParam) == FAST)
        {
            BASS_Stop();
            BASS_Start();
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - Sample Adventures.mp3                                                 "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI1, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Fast Music from YT studio");
            free_samples_all();
            SAMPLEADV = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\Fast.mp3", 0, 0, 0);


            BASS_ChannelPlay(SAMPLEADV, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(SAMPLEADV, BASS_ChannelGetLength(SAMPLEADV, BASS_POS_BYTE)));
        }
        if (LOWORD(wParam) == ARK)
        {
            BASS_Stop();
            BASS_Start();
            BASS_SampleFree(VISTA);
            BASS_ChannelFree(VISTA);
            BASS_StreamFree(VISTA);
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Deteez - Above the Sky.mp3                                         "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI2, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Ark Music from YT studio");
            free_samples_all();
            EYES = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\Ark.mp3", 0, 0, 0);

            BASS_ChannelPlay(EYES, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(EYES, BASS_ChannelGetLength(EYES, BASS_POS_BYTE)));

        }
        if (LOWORD(wParam) == STR9)
        {
            BASS_Stop();
            BASS_Start();
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Violet S - Lonely.mp3                                                         "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI3, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Captain Strannik - Hard Thing");
            free_samples_all();
            LONELY = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\HTM.mp3", 0, 0, 0);

            BASS_ChannelPlay(LONELY, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(LONELY, BASS_ChannelGetLength(LONELY, BASS_POS_BYTE)));

        }
        if (LOWORD(wParam) == ROBI)
        {
            BASS_Stop();
            BASS_Start();

            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Captain Strannik - Hard Thing.mp3           "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI4, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Robocop 3 NES");
            free_samples_all();
            GIRL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\Robocop.mp3", 0, 0, 0);


            BASS_ChannelPlay(GIRL, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(GIRL, BASS_ChannelGetLength(GIRL, BASS_POS_BYTE)));
        }









/*





        CreateWindow(TEXT("BUTTON"), TEXT("Sonic CD JP - Stardust speedway (BAD)"), WS_VISIBLE | WS_CHILD, 460, 230, 300, 70, hWnd, (HMENU)SSZ, NULL, NULL);
        hIconAll = (HICON)LoadImage(hInst, "MusicPlayer\\BMP\\ico\\music.ico", IMAGE_ICON, 0, 0, LR_LOADFROMFILE | LR_LOADTRANSPARENT);

        SendMessage(GetDlgItem(hWnd, ROBI), BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIconAll);*/





        if (LOWORD(wParam) == GHZ)
        {
            BASS_Stop();

            BASS_Start();

            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - Morning                                                 "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)DEFDEF, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Sonic CD US - (Tidal Tempest)");
            free_samples_all();
            MORNING = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\TTZ.mp3", 0, 0, 0);


            BASS_ChannelPlay(MORNING, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(MORNING, BASS_ChannelGetLength(MORNING, BASS_POS_BYTE)));

        }
        if (LOWORD(wParam) == ICZ)
        {
            BASS_Stop();
            BASS_Start();
            ShowWindow(GetDlgItem(hWnd, DEFDEF), SW_HIDE);
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - UFO                                                               "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Sonic 3 - Ice Cap");
            free_samples_all();
            UFO = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\ICZ.mp3", 0, 0, 0);

            BASS_ChannelPlay(UFO, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(UFO, BASS_ChannelGetLength(UFO, BASS_POS_BYTE)));

        }
        if (LOWORD(wParam) == LRZ)
        {
            BASS_Stop();
            BASS_Start();
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - Sample Adventures.mp3                                                 "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI1, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Sonic 3 and Knucles - Lava Reef");
            free_samples_all();
            SAMPLEADV = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\LRZ.mp3", 0, 0, 0);


            BASS_ChannelPlay(SAMPLEADV, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(SAMPLEADV, BASS_ChannelGetLength(SAMPLEADV, BASS_POS_BYTE)));
        }
        if (LOWORD(wParam) == HPZ)
        {
            BASS_Stop();
            BASS_Start();
            BASS_SampleFree(VISTA);
            BASS_ChannelFree(VISTA);
            BASS_StreamFree(VISTA);
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Deteez - Above the Sky.mp3                                         "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI2, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Sonic 2 - Hidden Palace");
            free_samples_all();
            EYES = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\HPZ.mp3", 0, 0, 0);

            BASS_ChannelPlay(EYES, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(EYES, BASS_ChannelGetLength(EYES, BASS_POS_BYTE)));

        }
        if (LOWORD(wParam) == SBZ)
        {
            BASS_Stop();
            BASS_Start();
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Violet S - Lonely.mp3                                                         "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI3, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Sonic 1 (SMS) - Scrap Brain");
            free_samples_all();
            LONELY = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\SBZSMS.mp3", 0, 0, 0);

            BASS_ChannelPlay(LONELY, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(LONELY, BASS_ChannelGetLength(LONELY, BASS_POS_BYTE)));

        }
        if (LOWORD(wParam) == SSZ)
        {
            BASS_Stop();
            BASS_Start();

            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Captain Strannik - Hard Thing.mp3           "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI4, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Sonic CD JP - Stardust speedway (BAD)");
            free_samples_all();
            GIRL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\SSJP.mp3", 0, 0, 0);


            BASS_ChannelPlay(GIRL, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(GIRL, BASS_ChannelGetLength(GIRL, BASS_POS_BYTE)));
        }













        if (LOWORD(wParam) == SFII)
        {
            BASS_Stop();

            BASS_Start();

            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - Morning                                                 "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)DEFDEF, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Street Fighter 2 Guile Theme (SEGA MEGA DRIVE) (ROCK COVER)");
            free_samples_all();
            MORNING = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\SFII.mp3", 0, 0, 0);


            BASS_ChannelPlay(MORNING, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(MORNING, BASS_ChannelGetLength(MORNING, BASS_POS_BYTE)));

        }
        if (LOWORD(wParam) == LKI)
        {
            BASS_Stop();
            BASS_Start();
            ShowWindow(GetDlgItem(hWnd, DEFDEF), SW_HIDE);
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - UFO                                                               "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Lion King (SEGA MEGA DRIVE) (CAN'T WAIT TO BE KING) (ROCK COVER)");
            free_samples_all();
            UFO = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\LKI.mp3", 0, 0, 0);

            BASS_ChannelPlay(UFO, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(UFO, BASS_ChannelGetLength(UFO, BASS_POS_BYTE)));

        }
        if (LOWORD(wParam) == ASI)
        {
            BASS_Stop();
            BASS_Start();
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - Sample Adventures.mp3                                                 "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI1, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Alladin (SEGA MEGA DRIVE) (ROCK COVER)");
            free_samples_all();
            SAMPLEADV = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\ASI.mp3", 0, 0, 0);


            BASS_ChannelPlay(SAMPLEADV, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(SAMPLEADV, BASS_ChannelGetLength(SAMPLEADV, BASS_POS_BYTE)));
        }
        if (LOWORD(wParam) == EJI)
        {
            BASS_Stop();
            BASS_Start();
            BASS_SampleFree(VISTA);
            BASS_ChannelFree(VISTA);
            BASS_StreamFree(VISTA);
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Deteez - Above the Sky.mp3                                         "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI2, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Earthworm Jim 1 (SEGA MEGA DRIVE) (ROCK COVER)");
            free_samples_all();
            EYES = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\EJI.mp3", 0, 0, 0);

            BASS_ChannelPlay(EYES, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(EYES, BASS_ChannelGetLength(EYES, BASS_POS_BYTE)));
            /*SendMessage(FOR6COMPOSIT1, TBM_SETPOS,TRUE, BASS_ChannelSetPosition(EYES, 10000, BASS_POS_BYTE));*/

        }
        if (LOWORD(wParam) == SIII)
        {
            BASS_Stop();
            BASS_Start();
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Violet S - Lonely.mp3                                                         "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI3, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Sonic 3 (SEGA MEGA DRIVE) (BOSS THEME) (ROCK COVER)");
            free_samples_all();
            LONELY = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\SIII.mp3", 0, 0, 0);

            BASS_ChannelPlay(LONELY, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(LONELY, BASS_ChannelGetLength(LONELY, BASS_POS_BYTE)));

        }
        if (LOWORD(wParam) == TMNT)
        {
            BASS_Stop();
            BASS_Start();

            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Captain Strannik - Hard Thing.mp3           "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI4, NULL, NULL);
            SetWindowText(sbar, "Проигрывается Teenage Mutant Ninja Turtles (ROCK COVER) (KINAMAN)");
            free_samples_all();
            GIRL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\TMNT.mp3", 0, 0, 0);


            BASS_ChannelPlay(GIRL, false); // проигрывание файла
            SendMessage(FOR6COMPOSIT1, TBM_SETPOS, 0, 0);
            SendMessage(FOR6COMPOSIT1, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(GIRL, BASS_ChannelGetLength(GIRL, BASS_POS_BYTE)));
        }










        if (LOWORD(wParam) == STOPS)
        {
            //CreateWindow(TEXT("STATIC"), TEXT("Музыка выключена                                                                 "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)text1, NULL, NULL);
            SetWindowText(sbar, "Музыка выключена");
            //ShowWindow(GetDlgItem(hWnd, LENMUSIC2), SW_HIDE);
            //ShowWindow(GetDlgItem(hWnd, LENMUSIC), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);
            free_samples_all();
            BASS_Stop();
            BASS_Start();

        }

        if (LOWORD(wParam) == WEIGHT)
        {
            MessageBoxA(hWnd, "А зачем вам знать? Вес штука сложная", "Вес", MB_ICONINFORMATION);
        }
        if (LOWORD(wParam) == WOZRAST)
        {
            MessageBoxA(hWnd, "Возраст? Так прям интересно? Ну переведите 10101 в десятичную систему\nА вообще, если вы шашнахме, то знайте, др у меня в хеллоуин", "Возраст 21", MB_ICONINFORMATION);
        }
        if (LOWORD(wParam) == ROSTE)
        {
            MessageBoxA(hWnd, "В какое время суток вам это нужно? Если утром, то зачем, а если вечером, то для чего?\nНу, утром я самый высокий, а ближе к ночи я карапуз.\nА так, шашнахме... Не знаю. Ну 190 СМ", "Рост", MB_ICONINFORMATION);
        }
        if (LOWORD(wParam) == DUSHA)
        {
            MessageBoxA(hWnd, "Душа у меня такая ранимая, а у вас?\nСомневаюсь, что такая же ранимая, как у меня.\nВедь я Шашнахме, а кость у вас видно толстая", "Душа", MB_ICONINFORMATION);
        }
        if (LOWORD(wParam) == POL)
        {
            MessageBoxA(hWnd, "Пол? А зачем вы спрашиваете? И так понятно, что пол штука плосская =). И где конкретно? Например дома \nу меня паркет и линолеум. А на даче древесина =).", "Пол", MB_ICONINFORMATION);
        }


        if (LOWORD(wParam) == STRANNIK)
        {
            ShellAbout(hWnd, progname, "Разработчик: Captain Strannik", progicon);
            MessageBoxA(hWnd, "Добро пожаловать в MixOS версии BETA 2.5.\nКоторая нужна для того, чтобы автор набрался опыта.\nЭто уже не просто плеер. Это больше похоже на свою ОС\nПравда без своего ядра (пока что).\nВсё что в ней есть это зеркало автора.\nТо есть, психологически, если углубляться, то можно понять, что MixOS это отражение всего что делает автор и как поступает. ", "О программе MixOS Beta 2.5", MB_ICONINFORMATION);

        }
        if (LOWORD(wParam) == HELP)
        {
            MessageBoxA(hWnd, "Если Вы шашнахме в моем плеере, то я вам щас все расскажу. Короче, есть кнопки, которые проигрывают музыку. Эти кнопки проигрывают конкретные песни моих друзей. Что написано, то и сыграется. Чтобы сыграть свою мелодию, просто впишите путь к ней с ее названием и нажмите кнопку <<Открыть свой файл>>. Если вдруг вы не знаете путь до музыки или если у вас толстая кость, просто нажмите кнопку <<Поиск>>. Если вы до сих пор хз как этим пользоваться, то че вы тут вообще делаете?", "Помощь", MB_OK);
            MessageBoxA(hWnd, "Также тут есть простой доступ к системным утилитам, попробуйте =)", "Помощь", MB_OK);
            MessageBoxA(hWnd, "И это, я вижу, у вас не толстая кость. Раз так, отожмитесь 10 раз. Чтобы проверить, толстая кость у вас или нет, я запущу шашнахме квест, который вы могли и без меня пройти =)", "Помощь", MB_ICONINFORMATION);
            system("start MusicPlayer\\Quest\\quest.exe");
        }

        if (LOWORD(wParam) == ABOUTDEV)
        {
            MessageBoxA(hWnd, "      Здравствуйте, это Strannik. И этот плеер нужен для того, для чего он нужен =). Я же - Создатель этого плеера. Мое имя Вам ни о чем не скажет. Но я расскажу вам историю о том, с чего начинался этот проект.                                                   Сидел я как-то вечером, за компом, и хотел уже наконец сделать что-то хорошее на с++, полезное. До этого, опыта в написании программ языке С++ у меня было мало. Конвертер валют и пара консольных программ. В итоге я решил: <<Почему бы не сделать музыкальный плеер?>>. Написание первой версии кода было ужасным времяпрепровождением. Я писал плохо, но со временем получалось лучше. И ура, я сделал первую версию плеера. Alpha 1.0. Она проигрывала только wav файлы и только конкретные 8 композиций, но начало уже было положено. На следующий день я выпустил версию beta 1.1, которая проигрывала около 20 wav композиций. Знания по функции PlaySound я отточил максимально тогда. Потом друзья мне сказали, что было бы неплохо добавить возможность проигрывать любые wav файлы. Так и сразу появилась beta 1.3. Как понимаете, тут у меня такая же история, как у microsoft =). Плеер уже умел проигрывать любую wav музыку, но это все было не то. Поэтому в версии Beta 1.4, которая вышла буквально позавчера (30.06.2021), Появился графический интерфейс, который работал даже на linux, но через wine. Самое главное чего мне не хватало это поддержки mp3. И я покопался в библиотеке bass, которую, к слову, используют все кому не лень, начиная с 90х годов 20 века. Также, чтобы было не так грустно, и, чтобы обновление было более глобальным, я добавил в плеер удобное меню, для запуска системных утилит. Вы спросите зачем? Ну так они ничего не жрут, занимают пару строк кода в программе. И самое главное, реально удобно! Попробуйте сами!                                                                                                           Сейчас (03.07.2021) Это версия beta 1.6, и в ней добавилась поддержка других форматов, при этом, для вашего удобства две строки ввода заменились на одну! Но, не без жертв, теперь музыку снова надо будет указывать с расширением. Но тут мои полномочия всё.                                           Всему виной библиотека bass.dll, которой надо скормить путь к мелодии и ее название с расширением. Пока не знаю, что с этим делать. Думаю, что до версии beta 1.8 уже точно додумаю =).", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "Сейчас 22.10.2021. Прошло блин уже 3 месяца с создания версии 1.6. Много чего произошло у меня в жизни.\nЯ набрался опыта. И в целом, добавил просто ТОННУ возможностей в этот плеер.\nВ частности это Пианино, Терминал с пасхалками и командами. Практически полностью доделанный Шашнахме квест.\nНовые кнопки в стиле Windows 7.\nКонвертер валют. В общем, идем в ногу со временем\nТолько часики отстали лет на 15 =). ", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "Версия 1.8. Выпущена 10.02.2022.\nДобавилось много всего интересного.\nВпервые я исправил баг с памятью.\nТеперь плеер почти ничего не ест.\nДобавил сюда кучу всего интересного, все пасхалки найдете сами. Их более 30 штук. =)", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "Версия 1.9. Привнесла достаточно много изменений, впрочем, это уже неважно, потому что вы используете как минимум версию 2.0", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "Версия 2.0. Я не помню, какие конкретно вещи были добавлены в 1.9.\nПоэтому назову всё то новое, что есть в 2.0,\nпо сравнению с 1.8. А добавлено:\n\n1) Терминал со своими командами\n2) Пианино\n3) Контекстменюмейкер\n5) Загрузчик роликов с youtube\n6) Эмуляторы приставок и компов с играми\n7) Различные программы и утилиты\n8) Смена цвета =). \n\n\nНа данный момент (15.06.2022)\nВпервые программа называется гордо: MixOS", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "Версия 2.1. Теперь это не плеер, а MixOS. Причем полноценно. Хотя пока что без своего ядра =).\nЧто нового:\n 1) Улучшен графический интерфейс и кастомизация цвета.\n2) Добавлены ползунки громкости.\n3) Генератор случайных чисел от The Ertor.\n4) Цифра в названии.\n5) Drag and drop.\n6) В контекстменюмейкере теперь можно также и удалять пункты меню.\n7) Скрытая команда для 18+ аудитории в терминале. Первая буква P, последняя N. Всего 4 буквы\n8) Исправление некоторых багов. (КОНЕЧНО БАГИ ЕСТЬ ЕЩЕ!).  ", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "Версия 2.2. Интерфейс в MixOS был переработан глобально. Сложно представить более серъезный апдейт.\nЧто нового:\n1) Еще более скрупулёзное улучшение графического интерфейса.\nПолностью переработан дизайн и общая атмосфера программы.\n2) Обновлены: \nа) Пианино\nб) Контекстменюмейкер\nв) Терминал\nг) Список эмуляторов\nд) Загрузчик роликов с Youtube\n\rКонечно, я бы не справился так быстро, если бы не один мой подписчик: Z_Kraf1er_Z, который тоже приложил руку\nк этой версии MixOS.", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "    Было добавлено : \n1) Видеоплеер\n2) Просмотрщик фотографий\n3) Рандомайзер\n4) Старые версии MusicPlayer\n5) Компьютерная эволюция 4\n6) Руинтранслитор\n7) Прочие улучшения визуала. ", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "Версия 2.3. Её код был основан на коде LITE версии.\nК сожалению, помощник Z_Krafter_Z более не участвует в проекте.\nЯ максимально не хотел ссориться, потому что как\nпрограммист он знает толк.\nНо как человек. В общем там отдельная история\nсвязанная с политикой. Но я думал и верил, что\nтворчество должно быть аполитичным.\nПоэтому я убрал всякое упоминание в коде о нём, чтобы не вспоминать. ", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "Версия 2.3. Из нововведений здесь:\n 1) Мой сборник игры из детства, которую я перенёс на новый игровой движок.\n 2) Всё, что было в LITE версии, а именно плейлист", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "Версия 2.4. Мораль: <<Не судите про апдейт по обложке. Внешность обманчива>>. Теперь вы можете скачивать различные подпрограммы для MixOS", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "Версия 2.5. Это глобальное обновление, которое добавило множество возможностей.\nДа, интерфейс по прежнему простой, хотя я ставку делаю\nне на него, а на тот функционал что в нём есть.\nНапример, вы можете общаться со мной через MixOS.\nВы можете теперь попробовать любую операционную систему семейства Windows, и программа теперь\nполностью автономна. Если Вам что-то не нужно, то Вы всегда можете удалить отдельные компоненты\nили установить их.\n", "О процессе разработки", MB_ICONINFORMATION);
        }
        if (LOWORD(wParam) == IU_STR)
        {
            if (MessageBox(hWnd, "Вы действительно хотите выйти из MixOS?", "Выход", MB_YESNO | MB_ICONWARNING) == IDYES)
            {
                PostQuitMessage(0);
                return 0;
            }

        }





        if (LOWORD(wParam) == TRYING)
        {
            ofstream Log;



            string ICONKITRY;
            string CONVERTERTRY;
            string EMULTRY;
            string MENUETTRY;
            string CPUZZTRY;
            string HWPROTRY;
            string OBSSAKATRY;
            string VISUKAKATRY;
            string INSTREDISTTRY;
            string QUESTQUESTTRY;
            string TERMINALKATRY;
            string UAUAUATRY;
            string UAUAUA1TRY;
            string UAUAUA2TRY;
            string UAUAUA3TRY;
            string PIANINKATRY;
            string PROGSPROGSREVOTRY;
            string PROGSPROGSSHUTTRY;
            string SUBSERTORTRY;
            string SUBSIGOROKNA8TRY;
            string SUBSNBRTRY;


            string WINWINWINWINMENUTRY;
            string WINWINWINWIN1TRY;
            string WINWINWINWIN2TRY;
            string WINWINWINWIN3TRY;
            string WINWINWINWIN31TRY;
            string WINWINWINWIN95TRY;
            string WINWINWINWIN98TRY;
            string WINWINWINWINMETRY;
            string WINWINWINWINCETRY;

            string WINWINWINWINNТ31TRY;
            string WINWINWINWINNT35TRY;
            string WINWINWINWINNT4TRY;
            string WINWINWINWINNT5TRY;
            string WINWINWINWIN2000TRY;
            string WINWINWINWINXPTRY;
            string WINWINWINWINVISTATRY;
            string WINWINWINWIN7TRY;
            string WINWINWINWIN8TRY;
            string WINWINWINWIN10TRY;
            string WINWINWINWIN11TRY;
            string MXS13TRY;
            string MXS15TRY;
            string CreeperYTTRY;
            string MINETERMTRY;
            string AUDIOTERMTRY;
            string AUDIORESTRY;
            string YTRESTRY;

            




            string segatry;
            string saturntry;
            string dendytry;
            string atari7800try;
            string PS1TRY;
            string PS2TRY;
            string EMU3000;
            string SNTRY;
            string PSPTRY;
            string GBATRY;
            string DS3TRY;




            WIN32_FIND_DATA ICONS ;
            HANDLE ICONSS = FindFirstFile("MusicPlayer\\BMP\\ico\\icon.mixos", &ICONS);          //icons




            WIN32_FIND_DATA EMU;
            HANDLE EMUL = FindFirstFile("MusicPlayer\\Emulators\\Emulate.exe", &EMU);    //emulate




            WIN32_FIND_DATA MENUET;
            HANDLE MINET = FindFirstFile("MusicPlayer\\MENUMAKER\\MENUMAKER.exe", &MENUET);    //menumaker





            WIN32_FIND_DATA CPUZZ;
            HANDLE INSTALLACPI = FindFirstFile("MusicPlayer\\Install\\CPUZ\\cpuz64.exe", &CPUZZ);  //cpuz

            WIN32_FIND_DATA HWPRO;
            HANDLE INSTALLA2 = FindFirstFile("MusicPlayer\\Install\\HW\\HW.exe", &HWPRO);     //hwmonitor

            WIN32_FIND_DATA OBSSAKA;
            HANDLE INSTALLA3 = FindFirstFile("MusicPlayer\\Install\\OBS\\OBS.exe", &OBSSAKA);  //OBS

            WIN32_FIND_DATA VISUKAKA;
            HANDLE INSTALLA4 = FindFirstFile("MusicPlayer\\Install\\VisualStudio\\Setup.exe", &VISUKAKA);  //VS STUDIO

            WIN32_FIND_DATA INSTREDIST;
            HANDLE INSTALLA5REDIST = FindFirstFile("MusicPlayer\\Install\\VS\\Visual\\Visual.bat", &INSTREDIST);  //VS redist



            WIN32_FIND_DATA QUESTQUEST;
            HANDLE INSTALLA6QUEST = FindFirstFile("MusicPlayer\\Quest\\quest.exe", &QUESTQUEST);    //QUEST



            WIN32_FIND_DATA TERMINALKA;
            HANDLE INSTALLA7TERM = FindFirstFile("MusicPlayer\\TERMINAL\\TERMINAL.exe", &TERMINALKA);             //TERMINAL






            WIN32_FIND_DATA UAUAUA;
            HANDLE INSTALLA8UA = FindFirstFile("MusicPlayer\\UA\\UAMENU.exe", &UAUAUA);            //UAMENU

            WIN32_FIND_DATA UAUAUA1;
            HANDLE INSTALLA9UA = FindFirstFile("MusicPlayer\\UA\\UADOM\\Ghor.ico", &UAUAUA1);        //UA DOMINATION

            WIN32_FIND_DATA UAUAUA2;
            HANDLE INSTALLA10UA = FindFirstFile("MusicPlayer\\UA\\UAORIG\\Ghor.ico", &UAUAUA2);     //UA ORIG + METROPOLIS

            WIN32_FIND_DATA UAUAUA3;
            HANDLE INSTALLA11UA = FindFirstFile("MusicPlayer\\UA\\UAORIGGHOR\\MSS32.DLL", &UAUAUA3); //UA GHOR




            WIN32_FIND_DATA PIANINKA;
            HANDLE INSTALLA12PIANO = FindFirstFile("MusicPlayer\\Piano\\Piano.exe", &PIANINKA); //PIANO





            WIN32_FIND_DATA PROGSPROGSREVO;
            HANDLE INSTALLA13REVO = FindFirstFile("MusicPlayer\\Progs\\REVO\\RevoUnin.exe", &PROGSPROGSREVO); //REVOUNIN

            WIN32_FIND_DATA PROGSPROGSSHUT;
            HANDLE INSTALLA14SHUT = FindFirstFile("MusicPlayer\\Progs\\SHUTUP\\KILLSPY.exe", &PROGSPROGSSHUT); //SHUT

            WIN32_FIND_DATA SUBSERTOR;
            HANDLE INSTALLA16ERTOR = FindFirstFile("MusicPlayer\\SUBS\\ERTOR\\gen.exe", &SUBSERTOR); //ERTOR

            WIN32_FIND_DATA SUBSIGOROKNA8;
            HANDLE INSTALLA15IGOR = FindFirstFile("MusicPlayer\\SUBS\\IGOR2677\\Win8\\F\\GoogleChromePortable.exe", &SUBSIGOROKNA8); //IGOR

            WIN32_FIND_DATA SUBSNBR;
            HANDLE INSTALLA16NBR = FindFirstFile("MusicPlayer\\SUBS\\NBR\\ru4en.hta", &SUBSNBR); //NBR






            WIN32_FIND_DATA WINWINWINWINMENU;
            HANDLE INSTALLA17WIN = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\MENU.exe", &WINWINWINWINMENU); //WINMENU

            WIN32_FIND_DATA WINWINWINWIN3;
            HANDLE INSTALLA18WIN3 = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WIN80286\\WIN3\\WIN3.mixos", &WINWINWINWIN3); //WIN3

            WIN32_FIND_DATA WINWINWINWIN2;
            HANDLE INSTALLA18WIN2 = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WIN80286\\WIN2\\WIN2.mixos", &WINWINWINWIN2); //WIN2

            WIN32_FIND_DATA WINWINWINWIN1;
            HANDLE INSTALLA18WIN1 = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WIN80286\\WIN1\\WIN1.mixos", &WINWINWINWIN1); //WIN1

            WIN32_FIND_DATA WINWINWINWIN31;
            HANDLE INSTALLA18WIN31 = FindFirstFile("MusicPlayer\\W311\\dosbox.exe", &WINWINWINWIN31); //WIN31





            WIN32_FIND_DATA WINWINWINWIN95;
            HANDLE INSTALLA18WIN95 = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WIN9X\\WIN95\\95.bat", &WINWINWINWIN95); //WIN95

            WIN32_FIND_DATA WINWINWINWIN98;
            HANDLE INSTALLA18WIN98 = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WIN9X\\WIN98\\98.bat", &WINWINWINWIN98); //WIN98

            WIN32_FIND_DATA WINWINWINWINME;
            HANDLE INSTALLA18WINME = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WIN9X\\WINME\\ME.bat", &WINWINWINWINME); //WINME

            WIN32_FIND_DATA WINWINWINWINCE;
            HANDLE INSTALLA18WINCE = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WIN9X\\WINCE\\CE.bat", &WINWINWINWINCE); //WINCE






            WIN32_FIND_DATA WINWINWINWINТ31;
            HANDLE INSTALLA18WINNT31 = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WINNT31\\NT3.bat", &WINWINWINWINТ31); //WIN31

            WIN32_FIND_DATA WINWINWINWINNT35;
            HANDLE INSTALLA18WIN35 = FindFirstFile("MusicPlayer\\Emulators\\OLDPC\\WINNT\\Win351\\86Box.exe", &WINWINWINWINNT35); //WIN35

            WIN32_FIND_DATA WINWINWINWINNT4;
            HANDLE INSTALLA18WINNT4 = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WINNT4\\NT4.bat", &WINWINWINWINNT4);

            WIN32_FIND_DATA WINWINWINWINNT5;
            HANDLE INSTALLA18WINNT5 = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WINNT5\\NT5.bat", &WINWINWINWINNT5); //WINNT5

            WIN32_FIND_DATA WINWINWINWIN2000;
            HANDLE INSTALLA18WIN2000 = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WIN2000\\2000.bat", &WINWINWINWIN2000); //WIN2000

            WIN32_FIND_DATA WINWINWINWINXP;
            HANDLE INSTALLA18WINXP = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WINXP\\XP.bat", &WINWINWINWINXP); //WINXP

            WIN32_FIND_DATA WINWINWINWINVISTA;
            HANDLE INSTALLA18WINVISTA = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WINVISTA\\VISTA.bat", &WINWINWINWINVISTA); //WINVISTA

            WIN32_FIND_DATA WINWINWINWIN7;
            HANDLE INSTALLA18WIN7 = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WIN7\\7.bat", &WINWINWINWIN7); //WIN7

            WIN32_FIND_DATA WINWINWINWIN8;
            HANDLE INSTALLA18WIN8 = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WIN8\\8.bat", &WINWINWINWIN8); //WIN8

            WIN32_FIND_DATA WINWINWINWIN10;
            HANDLE INSTALLA18WIN10 = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WIN10\\10.bat", &WINWINWINWIN10); //WIN8

            WIN32_FIND_DATA WINWINWINWIN11;
            HANDLE INSTALLA18WIN11 = FindFirstFile("MusicPlayer\\SYSTEM\\WINDOWS\\WINNT\\WIN11\\11.bat", &WINWINWINWIN11); //WIN8



            WIN32_FIND_DATA MXS13;
            HANDLE INSTALLAMXS13 = FindFirstFile("MusicPlayer\\OLD\\1.3.bat", &MXS13); //OLD MIX OS beta 1.3

            WIN32_FIND_DATA MXS15;
            HANDLE INSTALLAMXS15 = FindFirstFile("MusicPlayer\\OLD\\1.5.bat", &MXS15); //OLD MIX OS beta 1.5


            WIN32_FIND_DATA CreeperYT;
            HANDLE INSTALLACreeperYT = FindFirstFile("MusicPlayer\\PhotoViewer\\CreeperPhotoViewer.exe", &CreeperYT); //PhotoViewer

            WIN32_FIND_DATA MINETERM;
            HANDLE INSTALLAMINECRAFT = FindFirstFile("MusicPlayer\\X3\\M\\launcher.jar", &MINETERM); //Minecraft

            WIN32_FIND_DATA AUDIORES;
            HANDLE INSTALLAAUDIO = FindFirstFile("MusicPlayer\\Your\\Audio.mixos", &AUDIORES); //AUDIO

            WIN32_FIND_DATA YTRES;
            HANDLE INSTALLAYOUTUBE = FindFirstFile("MusicPlayer\\Youtube\\Youtube.exe", &YTRES); //YT




            if (INVALID_HANDLE_VALUE != ICONSS)
            {

                ICONKITRY = "Картинки - ЕСТЬ!";

            }
            else
            {

                ICONKITRY = "Картинки - НЕ УСТАНОВЛЕНЫ!";

            };

            if (INVALID_HANDLE_VALUE != EMUL)
            {

                EMULTRY = "Список эмуляторов - ЕСТЬ!";
                segatry = "Эмулятор SEGA genesis/32x/cd/SG1000/MASTERSYSTEM - ЕСТЬ!";
                saturntry = "Эмулятор SEGA SATURN - ЕСТЬ!";
                dendytry = "Эмулятор Dendy/NES/FAMICOM - ЕСТЬ!";
                atari7800try = "Эмулятор ATARI 7800 - ЕСТЬ";
                PS1TRY = "Эмулятор PS1 - ЕСТЬ!";
                PS2TRY = "Эмулятор PS2 - ЕСТЬ!";
                EMU3000 = "Эмулятор старых компов (Emulator3000) - ЕСТЬ!";
                SNTRY = "Эмулятор Super Nintendo - ЕСТЬ!";
                PSPTRY = "Эмулятор PSP (PPSSPP) - ЕСТЬ!";
                GBATRY = "Эмулятор GameboyAdvance - ЕСТЬ!";
                DS3TRY = "Эмулятор 3DS - ЕСТЬ!";
                
            }
            else
            {

                EMULTRY = "Список эмуляторов - НЕ УСТАНОВЛЕН!";
                segatry = "Эмулятор SEGA genesis/32x/cd/SG1000/MASTERSYSTEM - НЕ УСТАНОВЛЕН!";
                saturntry = "Эмулятор SEGA SATURN - НЕ УСТАНОВЛЕН!";
                dendytry = "Эмулятор Dendy/NES/FAMICOM - НЕ УСТАНОВЛЕН!";
                atari7800try = "Эмулятор ATARI 7800 - НЕ УСТАНОВЛЕН!";
                PS1TRY = "Эмулятор PS1 - НЕ УСТАНОВЛЕН!";
                PS2TRY = "Эмулятор PS2 - НЕ УСТАНОВЛЕН!";
                EMU3000 = "Эмулятор старых компов (Emulator3000) - НЕ УСТАНОВЛЕН!";
                SNTRY = "Эмулятор Super Nintendo - НЕ УСТАНОВЛЕН!";
                PSPTRY = "Эмулятор PSP (PPSSPP) - НЕ УСТАНОВЛЕН!";
                GBATRY = "Эмулятор GameboyAdvance - НЕ УСТАНОВЛЕН!";
                DS3TRY = "Эмулятор 3DS - НЕ УСТАНОВЛЕН!";
            };


            if (INVALID_HANDLE_VALUE != MINET)
            {

                MENUETTRY = "Менюмейкер - ЕСТЬ!";

            }
            else
            {

                MENUETTRY = "Менюмейкер - НЕ УСТАНОВЛЕН!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA2)
            {

                CPUZZTRY = "CPU-Z - ЕСТЬ!";

            }
            else
            {

                CPUZZTRY = "CPU-Z - НЕ УСТАНОВЛЕН!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLACPI)
            {

                HWPROTRY = "HW MONITOR - ЕСТЬ!";

            }
            else
            {

                HWPROTRY = "MW MONITOR - НЕ УСТАНОВЛЕН!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA3)
            {

                OBSSAKATRY = "Установщик OBS - ЕСТЬ!";

            }
            else
            {

                OBSSAKATRY = "Установщик OBS - НЕ УСТАНОВЛЕН!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA4)
            {

                VISUKAKATRY = "Установщик Visual Studio - ЕСТЬ!";

            }
            else
            {

                VISUKAKATRY = "Установщик Visual Studio - НЕ УСТАНОВЛЕН!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA5REDIST)
            {

                INSTREDISTTRY = "Установщик Visual С++ redistributable - ЕСТЬ!";

            }
            else
            {

                INSTREDISTTRY = "Установщик Visual C++ redistributable - НЕ УСТАНОВЛЕН!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA6QUEST)
            {

                QUESTQUESTTRY = "Шашнахме квест - ЕСТЬ!";

            }
            else
            {

                QUESTQUESTTRY = "Шашнахме квест - НЕ УСТАНОВЛЕН!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA7TERM)
            {

                TERMINALKATRY = "Терминал MixTerminal - ЕСТЬ!";

            }
            else
            {

                TERMINALKATRY = "Терминал MixTerminal - НЕ УСТАНОВЛЕН!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA8UA)
            {

                UAUAUATRY = "Сборник UA - ЕСТЬ!";

            }
            else
            {

                UAUAUATRY = "Сборник UA - НЕ УСТАНОВЛЕН!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA9UA)
            {

                UAUAUA1TRY = "UA DOMINATION BY MR_GHORKOV - ЕСТЬ!";

            }
            else
            {

                UAUAUA1TRY = "UA DOMINATION BY MR_GHORKOV - НЕ УСТАНОВЛЕН!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA10UA)
            {

                UAUAUA2TRY = "UA ORIGINAL + METROPOLIS - ЕСТЬ!";

            }
            else
            {

                UAUAUA2TRY = "UA ORIGINAL + METROPOLIS - НЕ УСТАНОВЛЕН!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA11UA)
            {

                UAUAUA3TRY = "UA GHOR BY STRANNIK - ЕСТЬ!";

            }
            else
            {

                UAUAUA3TRY = "UA GHOR BY STRANNIK - НЕ УСТАНОВЛЕН!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA12PIANO)
            {

                PIANINKATRY = "Пианино - ЕСТЬ!";

            }
            else
            {

                PIANINKATRY = "Пианино - НЕ УСТАНОВЛЕНО!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA13REVO)
            {

                PROGSPROGSREVOTRY = "Revo Uninstaller - ЕСТЬ!";

            }
            else
            {

                PROGSPROGSREVOTRY = "Revo Uninstaller - НЕ УСТАНОВЛЕНО!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA14SHUT)
            {

                PROGSPROGSSHUTTRY = "SHUT UP 10 - ЕСТЬ!";

            }
            else
            {

                PROGSPROGSSHUTTRY = "SHUT UP 10 - НЕ УСТАНОВЛЕНО!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA15IGOR)
            {

                SUBSIGOROKNA8TRY = "ОКНА 8 by Igor Kosov - ЕСТЬ!";

            }
            else
            {

                SUBSIGOROKNA8TRY = "ОКНА 8 by Igor Kosov - НЕ УСТАНОВЛЕНО!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA16ERTOR)
            {

                SUBSERTORTRY = "Генератор случайных чисел by Egor Komarov - ЕСТЬ!";

            }
            else
            {

                SUBSERTORTRY = "Генератор случайных чисел by Egor Komarov - НЕ УСТАНОВЛЕН!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA16NBR)
            {

                SUBSNBRTRY = "РУИНГТРАНСЛИТ - ЕСТЬ!";

            }
            else
            {

                SUBSNBRTRY = "РУИНГТРАНСЛИТ - НЕ УСТАНОВЛЕН!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA17WIN)
            {

                WINWINWINWINMENUTRY = "Сборник ОС Windows - ЕСТЬ!";

            }
            else
            {

                WINWINWINWINMENUTRY = "Сборник ОС Windows - НЕ УСТАНОВЛЕН!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA18WIN1)
            {

                WINWINWINWIN1TRY = "Windows 1.01 - ЕСТЬ!";

            }
            else
            {

                WINWINWINWIN1TRY = "Windows 1.01 - НЕ УСТАНОВЛЕНА!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA18WIN2)
            {

                WINWINWINWIN2TRY = "Windows 2.03 - ЕСТЬ!";

            }
            else
            {

                WINWINWINWIN2TRY = "Windows 2.03 - НЕ УСТАНОВЛЕНА!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA18WIN3)
            {

                WINWINWINWIN3TRY = "Windows 2.03 - ЕСТЬ!";

            }
            else
            {

                WINWINWINWIN3TRY = "Windows 2.03 - НЕ УСТАНОВЛЕНА!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA18WIN31)
            {

                WINWINWINWIN31TRY = "Windows 3.1 - ЕСТЬ!";

            }
            else
            {

                WINWINWINWIN31TRY = "Windows 3.1 - НЕ УСТАНОВЛЕНА!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA18WIN95)
            {

                WINWINWINWIN95TRY = "Windows 95 - ЕСТЬ!";

            }
            else
            {

                WINWINWINWIN95TRY = "Windows 95 - НЕ УСТАНОВЛЕНА!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA18WIN98)
            {

                WINWINWINWIN98TRY = "Windows 98 - ЕСТЬ!";

            }
            else
            {

                WINWINWINWIN98TRY = "Windows 98 - НЕ УСТАНОВЛЕНА!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA18WINME)
            {

                WINWINWINWINMETRY = "Windows ME - ЕСТЬ!";

            }
            else
            {

                WINWINWINWINMETRY = "Windows ME - НЕ УСТАНОВЛЕНА!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA18WINCE)
            {

                WINWINWINWINCETRY = "Windows CE - ЕСТЬ!";

            }
            else
            {

                WINWINWINWINCETRY = "Windows CE - НЕ УСТАНОВЛЕНА!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA18WINNT31)
            {

                WINWINWINWINNТ31TRY  = "Windows NT 3.1 - ЕСТЬ!";

            }
            else
            {

                WINWINWINWINNТ31TRY = "Windows NT 3.1 - НЕ УСТАНОВЛЕНА!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA18WIN35)
            {

                WINWINWINWINNT35TRY = "Windows NT 3.51 - ЕСТЬ!";

            }
            else
            {

                WINWINWINWINNT35TRY = "Windows NT 3.51 - НЕ УСТАНОВЛЕНА!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA18WINNT4)
            {

                WINWINWINWINNT4TRY = "Windows NT 4 - ЕСТЬ!";

            }
            else
            {

                WINWINWINWINNT4TRY = "Windows NT 4 - НЕ УСТАНОВЛЕНА!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA18WINNT5)
            {

                WINWINWINWINNT5TRY = "Windows NT 5 - ЕСТЬ!";

            }
            else
            {

                WINWINWINWINNT5TRY = "Windows NT 5 - НЕ УСТАНОВЛЕНА!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA18WIN2000)
            {

                WINWINWINWIN2000TRY = "Windows 2000 - ЕСТЬ!";

            }
            else
            {

                WINWINWINWIN2000TRY = "Windows 2000 - НЕ УСТАНОВЛЕНА!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA18WINXP)
            {

                WINWINWINWINXPTRY = "Windows XP - ЕСТЬ!";

            }
            else
            {

                WINWINWINWINXPTRY = "Windows XP - НЕ УСТАНОВЛЕНА!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA18WINVISTA)
            {

                WINWINWINWINVISTATRY = "Windows VISTA - ЕСТЬ!";

            }
            else
            {

                WINWINWINWINVISTATRY = "Windows VISTA - НЕ УСТАНОВЛЕНА!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA18WIN7)
            {

                WINWINWINWIN7TRY = "Windows 7 - ЕСТЬ!";

            }
            else
            {

                WINWINWINWIN7TRY = "Windows 7 - НЕ УСТАНОВЛЕНА!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA18WIN8)
            {

                WINWINWINWIN8TRY = "Windows 8 - ЕСТЬ!";

            }
            else
            {

                WINWINWINWIN8TRY = "Windows 8 - НЕ УСТАНОВЛЕНА!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA18WIN10)
            {

                WINWINWINWIN10TRY = "Windows 10 - ЕСТЬ!";

            }
            else
            {

                WINWINWINWIN10TRY = "Windows 10 - НЕ УСТАНОВЛЕНА!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLA18WIN11)
            {

                WINWINWINWIN11TRY = "Windows 11 - ЕСТЬ!";

            }
            else
            {

                WINWINWINWIN11TRY = "Windows 11 - НЕ УСТАНОВЛЕНА!";

            };


            if (INVALID_HANDLE_VALUE != INSTALLAMXS13)
            {

                MXS13TRY = "MixOS Beta 1.3 - ЕСТЬ!";

            }
            else
            {

                MXS13TRY = "MixOS Beta 1.3 - НЕ УСТАНОВЛЕНА!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLAMXS15)
            {

                MXS15TRY = "MixOS Beta 1.5 - ЕСТЬ!";

            }
            else
            {

                MXS15TRY = "MixOS Beta 1.5 - НЕ УСТАНОВЛЕНА!";

            };

           


            if (INVALID_HANDLE_VALUE != INSTALLACreeperYT)
            {

                CreeperYTTRY = "Просмотрщик фотографий - ЕСТЬ!";

            }
            else
            {

                CreeperYTTRY = "Просмотрщик фотографий - НЕ УСТАНОВЛЕН!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLAMINECRAFT)
            {

                MINETERMTRY = "Minecraft - ЕСТЬ!";
                AUDIOTERMTRY = "Звуковые компоненты установлены!";
            }
            else
            {
                AUDIOTERMTRY = "Звуковые компоненты отсутствуют!";
                MINETERMTRY = "Minecraft - НЕ УСТАНОВЛЕН!";

            };


            if (INVALID_HANDLE_VALUE != INSTALLAAUDIO)
            {

                AUDIORESTRY = "Аудиофайлы для MixOS - ЕСТЬ!";

            }
            else
            {

                AUDIORESTRY = "Аудиофайлы для MixOS - НЕ УСТАНОВЛЕНЫ!";

            };

            if (INVALID_HANDLE_VALUE != INSTALLAYOUTUBE)
            {

                YTRESTRY = "Загрузчик видео с Youtube - ЕСТЬ!";

            }
            else
            {

                YTRESTRY = "Загрузчик видео с Youtube - НЕ УСТАНОВЛЕНЫ!";

            };
     
            Log.open("MusicPlayer\\LOGINST.TXT");
            Log << "Информация об установленных компонентах MixOS..." << endl;
            Log << "Загружаю данные..." << endl;
            Log << "======================";
            Log << endl << "ОСНОВНЫЕ КОМПОНЕНТЫ  |" << endl;
            Log << "======================" << endl;
            Log << endl<<"I Основные компоненты/программы MixOS..." << endl;
            Log << ICONKITRY << endl;
            Log << AUDIORESTRY << endl; 
            Log << TERMINALKATRY << endl;
            Log << YTRESTRY << endl;
            Log << QUESTQUESTTRY << endl;
            Log << MENUETTRY << endl;
            Log << PIANINKATRY << endl;
            Log << EMULTRY << endl;
            Log << "=====================";
            Log << endl << "II Микропрограммы   |" << endl;
            Log << "=====================" << endl;
            Log << CONVERTERTRY << endl;
            Log << CreeperYTTRY << endl;
            Log << SUBSERTORTRY << endl;
            Log << SUBSERTORTRY << endl;
            Log << CPUZZTRY << endl;
            Log << HWPROTRY << endl;
            Log << OBSSAKATRY << endl;
            Log << VISUKAKATRY << endl;
            Log << INSTREDISTTRY << endl;
            Log << "==================================" << endl;
            Log << "III КОМПОНЕНТЫ ПОДПРОГРАММ MixOS |" << endl;
            Log << "==================================" << endl;
            Log << endl << "Компоненты Терминала" << endl;
            Log << MINETERMTRY << endl;
            Log << AUDIOTERMTRY<< endl;
            Log << endl << "Компоненты квеста" << endl;
            Log << QUESTQUESTTRY << endl;
            Log << endl << "Компоненты Загрузчика роликов с Youtube" << endl;
            Log << YTRESTRY << endl;
            Log << endl << "Компоненты Контекстменюмейкера" << endl;
            Log << MENUETTRY << endl;
            Log << endl << "Компоненты сборника эмуляторов" << endl;
            Log << UAUAUATRY << endl;
            Log << WINWINWINWINMENUTRY << endl;
            Log << segatry << endl;
            Log << saturntry << endl;
            Log << dendytry << endl;
            Log << atari7800try << endl;
            Log << atari7800try << endl;
            Log << PS1TRY << endl;
            Log << PS2TRY << endl;
            Log << EMU3000 << endl;
            Log << SNTRY << endl;
            Log << PSPTRY << endl;
            Log << GBATRY << endl;
            Log << DS3TRY << endl;
            Log << endl << "Компоненты сборника Windows" << endl;

           

            Log << endl << "Проверяю наличие систем..." << endl;
            Log << endl << WINWINWINWINMENUTRY << endl;
            Log << WINWINWINWIN1TRY << endl;
            Log << WINWINWINWIN2TRY << endl;
            Log << WINWINWINWIN3TRY << endl;
            Log << WINWINWINWIN31TRY << endl;
            Log << WINWINWINWIN95TRY << endl;
            Log << WINWINWINWIN98TRY << endl;
            Log << WINWINWINWINMETRY << endl;
            Log << WINWINWINWINCETRY << endl;
            Log << WINWINWINWINNТ31TRY << endl;
            Log << WINWINWINWINNT35TRY << endl;
            Log << WINWINWINWINNT4TRY << endl;
            Log << WINWINWINWINNT5TRY << endl;
            Log << WINWINWINWIN2000TRY << endl;
            Log << WINWINWINWINXPTRY << endl;
            Log << WINWINWINWINVISTATRY << endl;
            Log << WINWINWINWIN7TRY << endl;
            Log << WINWINWINWIN8TRY << endl;
            Log << SUBSIGOROKNA8TRY << endl;
            Log << WINWINWINWIN10TRY << endl;
            Log << WINWINWINWIN11TRY << endl;
            Log << endl << "Компоненты UA (Urban Assault)" << endl;
            Log << UAUAUATRY << endl;
            Log << UAUAUA1TRY << endl;
            Log << UAUAUA2TRY << endl;
            Log << UAUAUA3TRY << endl;
            Log << "========================" << endl;
            Log << endl << "Отчёт завершён" << endl;

            


            Log.close();
            system("start notepad MusicPlayer\\LOGINST.TXT");
            system("del MusicPlayer\\LOGINST.TXT");







           /* return false;
            FindClose(ICONSS);
            FindClose(EMUL);
            FindClose(MINET);
            FindClose(INSTALLA2);
            FindClose(INSTALLACPI);
            FindClose(INSTALLA3);
            FindClose(INSTALLA4);
            FindClose(INSTALLA5REDIST);
            FindClose(INSTALLA6QUEST);
            FindClose(INSTALLA7TERM);
            FindClose(INSTALLA8UA);
            FindClose(INSTALLA9UA);
            FindClose(INSTALLA10UA);
            FindClose(INSTALLA11UA);
            FindClose(INSTALLA12PIANO);
            FindClose(INSTALLA13REVO);
            FindClose(INSTALLA14SHUT);
            FindClose(INSTALLA15IGOR);
            FindClose(INSTALLA16ERTOR);
            FindClose(INSTALLA16NBR);
            FindClose(INSTALLA17WIN);
            FindClose(INSTALLA18WIN1);

            FindClose(INSTALLA18WIN2);
            FindClose(INSTALLA18WIN3);
            FindClose(INSTALLA18WIN31);
            FindClose(INSTALLA18WIN95);
            FindClose(INSTALLA18WIN98);
            FindClose(INSTALLA18WINME);
            FindClose(INSTALLA18WINCE);
            FindClose(INSTALLA18WINNT31);

            FindClose(INSTALLA18WIN35);
            FindClose(INSTALLA18WINNT4);
            FindClose(INSTALLA18WINNT5);
            FindClose(INSTALLA18WIN2000);
            FindClose(INSTALLA18WINXP);
            FindClose(INSTALLA18WINVISTA);
            FindClose(INSTALLA18WIN7);
            FindClose(INSTALLA18WIN8);
            FindClose(INSTALLA18WIN10);
            FindClose(INSTALLA18WIN11);*/
        }

























        if (LOWORD(wParam) == SOURCE)
        {
            MessageBoxA(hWnd, "Исходники лежат на гитхабе", "Исходный код", MB_OK);
            system("start https://github.com/CaptainStrannik/MixOS");

        }
        if (LOWORD(wParam) == PAUSE1)
        {
            //CreateWindow(TEXT("STATIC"), TEXT("Пауза                                                        \n                                      "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)text1, NULL, NULL);
            SetWindowText(sbar, "Пауза");
            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_SHOW);

            without_stro();
            ShowWindow(GetDlgItem(hWnd, LENMUSIC), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VOLUMASTA), SW_HIDE);
            ShowWindow(hTrack2, SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SOUNDMASTA), SW_HIDE);
            BASS_ChannelStop(stro);
            //пауза
        }
        if (LOWORD(wParam) == PAUSE2)   //продолжить
        {
            BASS_ChannelPlay(stro, false); //плей
            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается ваша музыка)                                                                "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)DEFDEF, NULL, NULL);
            SetWindowText(sbar, "Проигрывается ваша музыка)");
            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);

            without_stro();


            ShowWindow(GetDlgItem(hWnd, LENMUSIC), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, VOLUMASTA), SW_SHOW);
            ShowWindow(hTrack2, SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SOUNDMASTA), SW_SHOW);
        }
        if (LOWORD(wParam) == FILEY2)
        {

            ShowWindow(GetDlgItem(hWnd, LENMUSIC), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, VOLUMASTA), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, textpl), SW_SHOW);

            ShowWindow(GetDlgItem(hWnd, DEVUSHKA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LETO), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, CIGARET), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PEREMEN), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SHAG), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SLOVO), SW_HIDE);


            ShowWindow(GetDlgItem(hWnd, LRZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ICZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, HPZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SBZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SSZ), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, GHZ), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, SFII), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ASI), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, TMNT), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, EJI), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SIII), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LKI), SW_HIDE);



            ShowWindow(GetDlgItem(hWnd, STRELKA1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STRELKA2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STRELKA3), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STRELKA4), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, STRELKA5), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STRELKA6), SW_HIDE);


            ShowWindow(GetDlgItem(hWnd, WITCHER1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, WITCHER2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, FAST), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STR9), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ROBI), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, ARK), SW_HIDE);



            ShowWindow(GetDlgItem(hWnd, textdnd), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, LENMUSIC2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VOLUMASTA1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SOUNDMASTA1), SW_HIDE);
            ShowWindow(FOR6COMPOSIT1, SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, STRELKA1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, STRELKA2), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);

            ShowWindow(hTrack2, SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, SOUNDMASTA), SW_SHOW);
            ShowWindow(playlist, SW_SHOW);
            //ShowWindow(eSearch, SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PLSEL), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PLADD), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PLDEL), SW_SHOW);
            //ShowWindow(GetDlgItem(hWnd, PLSEARCH), SW_SHOW);

            free_samples_all();
            BASS_Stop();
            BASS_Start();

            int len;
            TCHAR StrB[1200];
            len = GetWindowText(eMp3, StrB, 1200);
            BASS_ChannelStop(stro);

            stro = BASS_StreamCreateFile(FALSE, StrB, 0, 0, 0);

            //CreateWindow(TEXT("STATIC"), TEXT("Проигрывается ваша музыка)                                                          "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)text1, NULL, NULL);
            SetWindowText(sbar, "Проигрывается ваша музыка)");
            BASS_ChannelPlay(stro, false); // проигрывание файла
            SendMessage(hTrack2, TBM_SETPOS, 0, 0);
            SendMessage(hTrack2, TBM_SETRANGEMAX, TRUE, BASS_ChannelBytes2Seconds(stro, BASS_ChannelGetLength(stro, BASS_POS_BYTE)));

            //UpdateWindow(hTrack2);

            //SendMessage(hTrack1, TBM_SETRANGEMIN, TRUE, 0);
            //SendMessage(hTrack1, TBM_SETRANGEMAX, TRUE, BASS_ChannelGetPosition(stro, BASS_POS_BYTE));
            //BASS_ChannelSetAttribute(stro, BASS_ATTRIB_VOL, 1);
            //SendMessage(hTrack, TBM_SETLINESIZE, NULL, 100);
        }













        //if (LOWORD(wParam) == LOADDLL)
        //{
        //    system("start MusicPlayer\\DWL\\MixDownload.exe");   
        //}














        if (LOWORD(wParam) == QUEST)
        {
            quest:
                WIN32_FIND_DATA EXAMPLE;
                HANDLE hFind = FindFirstFile("MusicPlayer\\Quest\\quest.exe", &EXAMPLE);
                if (INVALID_HANDLE_VALUE != hFind)
                {

                    system("start MusicPlayer\\Quest\\quest.exe");

                }
                else
                {

                    MessageBox(hWnd, "Сейчас быстро скачается\nШашнахме квест.", "ВНИМАНИЕ", MB_OK | MB_ICONASTERISK);
                    URLDownloadToFile(0, "https://cdn.lisikpng.com/MixOS/QUEST/Quest.zip", "MusicPlayer\\Quest.zip", 0, 0);


                    system("MusicPlayer\\QUEST.bat");
                    WIN32_FIND_DATA EXAMPLE;
                    HANDLE hFind = FindFirstFile("MusicPlayer\\Quest\\quest.exe", &EXAMPLE);
                    if (INVALID_HANDLE_VALUE != hFind)
                    {


                        MessageBoxA(hWnd, "Шашнахме квест успешно установлен!\nИграйте на здоровье!", "ОТЛИЧНО!!!", MB_ICONINFORMATION);


                    }
                    if (INVALID_HANDLE_VALUE == hFind)
                    {

                        if (MessageBox(hWnd, "Не установился, возможно проблема с интернетом\nПопробовать ещё раз?", "Неудача  =(", MB_YESNO | MB_ICONQUESTION == IDYES))
                        {
                            goto quest;
                        }
                        else
                        {
                            return 0;
                        };

                    }

                };


                return false;
                FindClose(hFind);


        }
        if (LOWORD(wParam) == VIDEO)
        {
            system("start MusicPlayer\\VideoPlayer\\VideoPlayer.exe");
        }
        if (LOWORD(wParam) == CALC)
        {
            system("start calc.exe");
        }
        if (LOWORD(wParam) == TASKMGR)
        {
            system("start taskmgr.exe");
        }
        if (LOWORD(wParam) == CLEANMGR)
        {
            system("start cleanmgr.exe");
        }
        if (LOWORD(wParam) == REGEDIT)
        {
            system("start regedit.exe");
        }

        if (LOWORD(wParam) == SEARCH)
        {
            /*system("@echo off");
            system("explorer MusicPlayer");    */
            OPENFILENAME ofn;

            ZeroMemory(&ofn, sizeof(OPENFILENAME));
            ofn.lStructSize = sizeof(OPENFILENAME);
            ofn.hwndOwner = hWnd;
            ofn.lpstrFile = str1;
            ofn.nMaxFile = sizeof(str1);
            //ofn.lpstrFilter = "MP3\0.MP3\0WAV\0.WAV\0";
            //ofn.lpstrFilter = ".mp3\0.wav\0.mp4\0.ogg\0";
            ofn.nFilterIndex = 1;
            ofn.lpstrFileTitle = NULL;
            ofn.nMaxFileTitle = 0;
            //ofn.lpstrInitialDir = ".";
            ofn.lpstrInitialDir = "MusicPlayer\\Your";
            ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_DONTADDTORECENT | OFN_NOCHANGEDIR;   //Бага больше нет!  А я пока отойду.

            if (GetOpenFileName(&ofn) == TRUE)
            {
                SetWindowText(eMp3, str1);
              
                GetWindowText(eMp3, str1, MAX_PATH);
                SendMessage(playlist, LB_ADDSTRING, 0, (LPARAM)str1);
            }
        }
        if (LOWORD(wParam) == DEFRAG)
        {
            system("start dfrgui.exe");
        }
        if (LOWORD(wParam) == GPEDIT)
        {
            system("start gpedit.msc");
        }
        if (LOWORD(wParam) == PERSONALIZE)
        {
            system("explorer shell:::{ED834ED6-4B5A-4bfe-8F11-A626DCB6A921}");
        }
        if (LOWORD(wParam) == RSTRUI)
        {
            system("start rstrui.exe");
        }
        if (LOWORD(wParam) == SYSTEMA)
        {
            system("explorer shell:::{bb06c0e4-d293-4f75-8a90-cb05b6477eee}");
        }
        if (LOWORD(wParam) == DEVICES)
        {
            system("start devmgmt.msc");
        }
        if (LOWORD(wParam) == MSCONFIG)
        {
            system("start msconfig.exe");
        }
        if (LOWORD(wParam) == RESMON)
        {
            system("start resmon.exe");
        }
        if (LOWORD(wParam) == NOTEPAD)
        {
            system("start notepad.exe");
        }
        if (LOWORD(wParam) == MSINFO32)
        {
            system("start msinfo32.exe");
        }
        if (LOWORD(wParam) == COMPMGMT)
        {
            system("start compmgmt.msc");
        }
        if (LOWORD(wParam) == VERIFIER)
        {
            system("start verifier.exe");
        }
        if (LOWORD(wParam) == MSPAINT)
        {
            system("start mspaint.exe");
        }
        if (LOWORD(wParam) == MRT)
        {
            system("start MRT.exe");
            //WinExec("MRT.exe", SW_SHOW);
        }
        if (LOWORD(wParam) == EVENTVWR)
        {
            system("start eventvwr.msc");
        }
        if (LOWORD(wParam) == SERVICES)
        {
            system("start services.msc");
        }
        if (LOWORD(wParam) == TASKSCHD)
        {
            system("start taskschd.msc");
        }
        if (LOWORD(wParam) == MDSCHED)
        {
            system("start mdsched.exe");
        }

        if (LOWORD(wParam) == MENUMENUMENUMENU)
        {

            system("start MixOS.exe");
            PostQuitMessage(0);

        }
        if (LOWORD(wParam) == FASTRESTART)
        {
            if (MessageBox(hWnd, "Перед тем как перезагрузиться, обязательно закройте все программы!", "Внимание!", MB_YESNO | MB_ICONWARNING) == IDYES)
                ExitWindowsEx(EWX_RESTARTAPPS, NULL);
        }




        break;

    case WM_HSCROLL: {

        int volume = SendMessage(hTrack, TBM_GETPOS, 0, 0);
        int volume1 = SendMessage(hTrack1, TBM_GETPOS, 0, 0);
        int volume2 = SendMessage(FOR6COMPOSIT, TBM_GETPOS, 0, 0);

        if (hTrack == (HWND)lParam /*&& wParam != 0*/)
            BASS_ChannelSetAttribute(stro, BASS_ATTRIB_VOL, (float)volume / 100);
        if (hTrack1 == (HWND)lParam)
            BASS_ChannelSetAttribute(START, BASS_ATTRIB_VOL, (float)volume1 / 100);
        if (hTrack2 == (HWND)lParam && LOWORD(wParam) == SB_THUMBPOSITION /*|| LOWORD(wParam) == SB_PAGELEFT || LOWORD(wParam) == SB_PAGERIGHT*/)
            BASS_ChannelSetPosition(stro, BASS_ChannelSeconds2Bytes(stro, SendMessage(hTrack2, TBM_GETPOS, 40, 80)), BASS_POS_BYTE);
        if (FOR6COMPOSIT == (HWND)lParam)
        {
            BASS_ChannelSetAttribute(GIRL, BASS_ATTRIB_VOL, (float)volume2 / 100);
            BASS_ChannelSetAttribute(LONELY, BASS_ATTRIB_VOL, (float)volume2 / 100);
            BASS_ChannelSetAttribute(MORNING, BASS_ATTRIB_VOL, (float)volume2 / 100);
            BASS_ChannelSetAttribute(UFO, BASS_ATTRIB_VOL, (float)volume2 / 100);
            BASS_ChannelSetAttribute(SAMPLEADV, BASS_ATTRIB_VOL, (float)volume2 / 100);
            BASS_ChannelSetAttribute(EYES, BASS_ATTRIB_VOL, (float)volume2 / 100);
            BASS_ChannelSetAttribute(VISTA, BASS_ATTRIB_VOL, (float)volume2 / 100);
        }
        if (FOR6COMPOSIT1 == (HWND)lParam && LOWORD(wParam) == SB_THUMBPOSITION /*|| LOWORD(wParam) == SB_PAGELEFT || LOWORD(wParam) == SB_PAGERIGHT*/)
        {
            BASS_ChannelSetPosition(GIRL, BASS_ChannelSeconds2Bytes(GIRL, SendMessage(FOR6COMPOSIT1, TBM_GETPOS, 40, 80)), BASS_POS_BYTE);
            BASS_ChannelSetPosition(LONELY, BASS_ChannelSeconds2Bytes(LONELY, SendMessage(FOR6COMPOSIT1, TBM_GETPOS, 40, 80)), BASS_POS_BYTE);
            BASS_ChannelSetPosition(MORNING, BASS_ChannelSeconds2Bytes(MORNING, SendMessage(FOR6COMPOSIT1, TBM_GETPOS, 40, 80)), BASS_POS_BYTE);
            BASS_ChannelSetPosition(UFO, BASS_ChannelSeconds2Bytes(UFO, SendMessage(FOR6COMPOSIT1, TBM_GETPOS, 40, 80)), BASS_POS_BYTE);
            BASS_ChannelSetPosition(SAMPLEADV, BASS_ChannelSeconds2Bytes(SAMPLEADV, SendMessage(FOR6COMPOSIT1, TBM_GETPOS, 40, 80)), BASS_POS_BYTE);
            BASS_ChannelSetPosition(EYES, BASS_ChannelSeconds2Bytes(EYES, SendMessage(FOR6COMPOSIT1, TBM_GETPOS, 40, 80)), BASS_POS_BYTE);
            //BASS_ChannelSetPosition(VISTA, BASS_ChannelSeconds2Bytes(VISTA, SendMessage(FOR6COMPOSIT1, TBM_GETPOS, 40, 80)), BASS_POS_BYTE);
        }
    } break;

        //Цикл обработки сообщений
    case WM_DROPFILES: {

        DragQueryFile((HDROP)wParam, 0, str1, MAX_PATH);
        SetWindowText(eMp3, str1);
        GetWindowText(eMp3, str2, MAX_PATH);
        SendMessage(playlist, LB_ADDSTRING, 0, (LPARAM)str2);
    }
                     break;

    case WM_PAINT: {
        hdc = BeginPaint(hWnd, &ps);
        //SetBkMode(hdc, TRANSPARENT);
        FillRect(hdc, &ps.rcPaint, hBrush);
        /*SetBkMode(hdc, TRANSPARENT);*/

        //BitBlt(hdc, 0, 0, bm. 720, memBit, 0, 0, SRCCOPY);

        //strcpy(lf.lfFaceName, "Verdana");


        //lf.lfHeight = 20;
        //lf.lfItalic = 0;   //Гнутый
        //lf.lfStrikeOut = 0;
        //lf.lfUnderline = 0; 
        //lf.lfWidth = 10;
        //lf.lfWeight = 40;
        //lf.lfCharSet = DEFAULT_CHARSET; //значение по умолчанию
        //lf.lfPitchAndFamily = DEFAULT_PITCH; //значения по умолчанию
        //lf.lfEscapement = 1;

        //hFont = CreateFontIndirect(&lf);
        //SelectObject(hdc, hFont);
        //SetTextColor(hdc, RGB(255, 255, 255));

        //TextOut(hdc, 550, 20, "Вас приветствует MixOS Beta", 27);






        EndPaint(hWnd, &ps);





        //return 0;

    } break;


    case WM_KEYDOWN:
    {
        switch (LOWORD(wParam))
        {
        case VK_ESCAPE:
            DestroyWindow(hWnd);
            break;
        case VK_SPACE:
            SendMessage(hWnd, WM_COMMAND, SETBKG, 0);
            break;
        case VK_RETURN:
            SendMessage(hWnd, WM_COMMAND, FILEY2, 0);
            break;
        case '1':
            SendMessage(hWnd, WM_COMMAND, TERMINAL, 0);
            break;
        case '2':
        {   

            SendMessage(hWnd, WM_COMMAND, ID_BUTTON, 0);

                                                    //need to fix this bug
        }
            break;
        case '3':
            SendMessage(hWnd, WM_COMMAND, MENUMAKER, 0);
            break;
        case '4':
            SendMessage(hWnd, WM_COMMAND, PIANINO, 0);
            break;
        case '5':
            SendMessage(hWnd, WM_COMMAND, Emulators, 0);
            break;
        case '6':
            SendMessage(hWnd, WM_COMMAND, QUEST, 0);
            break;
        case '7':
            SendMessage(hWnd, WM_COMMAND, YOUTUBE, 0);
            break;
        case VK_NUMPAD1:
            SendMessage(hWnd, WM_COMMAND, SKIN1, 0);
            break;
        case VK_NUMPAD2:
            SendMessage(hWnd, WM_COMMAND, SKIN2, 0);
            break;
        case VK_NUMPAD3:
            SendMessage(hWnd, WM_COMMAND, SKIN3, 0);
            break;
        case VK_NUMPAD4:
            SendMessage(hWnd, WM_COMMAND, SKIN4, 0);
            break;
        case VK_NUMPAD5:
            SendMessage(hWnd, WM_COMMAND, SKIN5, 0);
            break;
        case VK_NUMPAD6:
            SendMessage(hWnd, WM_COMMAND, SKIN6, 0);
            break;
        case VK_NUMPAD7:
            SendMessage(hWnd, WM_COMMAND, SKIN7, 0);
            break;
        case VK_NUMPAD8:
            SendMessage(hWnd, WM_COMMAND, SKIN8, 0);
            break;
        case VK_NUMPAD9:
            SendMessage(hWnd, WM_COMMAND, SKIN9, 0);
            break;


        case VK_MBUTTON:
            SendMessage(hWnd, WM_COMMAND, MYCOLOR, 0);
            break;

        case VK_ADD:
            SendMessage(GetDlgItem(hWnd, CHB1), BM_SETCHECK, BST_CHECKED, 0);
            break;



        case VK_SUBTRACT:
            SendMessage(GetDlgItem(hWnd, CHB1), BM_SETCHECK, BST_UNCHECKED, 0);
            break;




        }

    }
    break;



    case WM_DESTROY:
    {

        PostQuitMessage(0);
        return 0;



    }break;


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

        if (GetDlgCtrlID((HWND)lParam) == text11)
        {
            HDC hdcStatic = (HDC)wParam;
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }
        if (GetDlgCtrlID((HWND)lParam) == textdnd)
        {
            HDC hdcStatic = (HDC)wParam;
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }
        if (GetDlgCtrlID((HWND)lParam) == textpl)
        {
            HDC hdcStatic = (HDC)wParam;
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }
        if (GetDlgCtrlID((HWND)lParam) == LENMUSIC1)
        {
            HDC hdcStatic = (HDC)wParam;
            // or obtain the static handle in some other way
           /* SetTextColor(hdcStatic, RGB(255, 255, 255));*/ // text color

            SetBkColor(hdcStatic, rgbCurrent1);

            return (LRESULT)GetStockObject(RGB(255, 255, 255));

        }

        if (GetDlgCtrlID((HWND)lParam) == VOLUMASTA1)
        {
            HDC hdcStatic = (HDC)wParam;
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }
        if (GetDlgCtrlID((HWND)lParam) == VOLUMASTA)
        {
            HDC hdcStatic = (HDC)wParam;
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }
        if (GetDlgCtrlID((HWND)lParam) == SOUNDMASTA)
        {
            HDC hdcStatic = (HDC)wParam;
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }
        if (GetDlgCtrlID((HWND)lParam) == SOUNDMASTA1)
        {
            HDC hdcStatic = (HDC)wParam;
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }

        if (GetDlgCtrlID((HWND)lParam) == DEFDEF)
        {
            HDC hdcStatic = (HDC)wParam;
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }
        if (GetDlgCtrlID((HWND)lParam) == XAI2)
        {
            HDC hdcStatic = (HDC)wParam;
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }
        if (GetDlgCtrlID((HWND)lParam) == XAI3)
        {
            HDC hdcStatic = (HDC)wParam;
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }
        if (GetDlgCtrlID((HWND)lParam) == XAI4)
        {
            HDC hdcStatic = (HDC)wParam;
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(NULL_BRUSH);

        }
        if (GetDlgCtrlID((HWND)lParam) == CHB1)
        {
            HDC hdcStatic = (HDC)wParam;
            // or obtain the static handle in some other way
            SetTextColor(hdcStatic, RGB(255, 255, 255)); // text color

            SetBkColor(hdcStatic, rgbCurrent);

            return (LRESULT)GetStockObject(RGB(0, 76, 153));

        }





    }break;

    break;

    default:
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
                   return 0;
    }
    
   
}


inline void free_samples_all()
{

    BASS_StreamFree(VISTA);
    BASS_SampleFree(VISTA);
    BASS_ChannelFree(VISTA);
    BASS_ChannelFree(stro);
    BASS_StreamFree(stro);
    BASS_SampleFree(stro);
    BASS_ChannelFree(MORNING);
    BASS_SampleFree(MORNING);
    BASS_ChannelStop(MORNING);
    BASS_ChannelFree(UFO);
    BASS_SampleFree(UFO);
    BASS_ChannelStop(UFO);
    BASS_ChannelStop(SAMPLEADV);
    BASS_SampleFree(SAMPLEADV);
    BASS_ChannelFree(SAMPLEADV);
    BASS_ChannelStop(EYES);
    BASS_SampleFree(EYES);
    BASS_ChannelFree(EYES);
    BASS_ChannelStop(LONELY);
    BASS_ChannelFree(LONELY);
    BASS_SampleFree(LONELY);
    BASS_ChannelStop(GIRL);
    BASS_ChannelFree(GIRL);
    BASS_SampleFree(GIRL);



}
inline void without_stro()
{
    BASS_StreamFree(VISTA);
    BASS_SampleFree(VISTA);
    BASS_ChannelFree(VISTA);
    BASS_ChannelFree(MORNING);
    BASS_SampleFree(MORNING);
    BASS_ChannelStop(MORNING);
    BASS_ChannelFree(UFO);
    BASS_SampleFree(UFO);
    BASS_ChannelStop(UFO);
    BASS_ChannelStop(SAMPLEADV);
    BASS_SampleFree(SAMPLEADV);
    BASS_ChannelFree(SAMPLEADV);
    BASS_ChannelStop(EYES);
    BASS_SampleFree(EYES);
    BASS_ChannelFree(EYES);
    BASS_ChannelStop(LONELY);
    BASS_ChannelFree(LONELY);
    BASS_SampleFree(LONELY);
    BASS_ChannelStop(GIRL);
    BASS_ChannelFree(GIRL);
    BASS_SampleFree(GIRL);


}

int WINAPI main(int argc, char* argv[])
{

    SetProcessDPIAware();

    WNDCLASS wc;
    ZeroMemory(&wc, sizeof(WNDCLASS));
    wc.lpfnWndProc = wnd_proc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "MixOS";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    progicon = (HICON)LoadImage(wc.hInstance, "MusicPlayer\\BMP\\ico\\MixOS.ico", IMAGE_ICON, 48, 48, LR_LOADFROMFILE | LR_LOADTRANSPARENT);
    wc.hIcon = progicon;

    RegisterClass(&wc);



    CreateWindowEx(WS_EX_ACCEPTFILES, wc.lpszClassName, progname,/* WS_POPUPWINDOW |*/ WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX /*|WS_OVERLAPPEDWINDOW*/| WS_VISIBLE, (GetSystemMetrics(SM_CXSCREEN) - 1280) / 2,
        (GetSystemMetrics(SM_CYSCREEN) - 720) / 2, 1280, 720, NULL, NULL, wc.hInstance, NULL);

 

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }

    return 0;

}


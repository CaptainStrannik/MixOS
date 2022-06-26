#include <windows.h>
#include<winuser.h>
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
#include<set>
#include <algorithm>
#include <shlwapi.h> 
#include <filesystem>

#pragma comment(linker,"/manifestdependency:\"type='win32' \
                        name='Microsoft.Windows.Common-Controls' \
                        version='6.0.0.0' processorArchitecture='*'\
 publicKeyToken='6595b64144ccf1df' language='*'\"")

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "bass")
#pragma comment(lib, "shlwapi.lib")


using namespace std;
HWND eDit;
HWND eMp3;
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

HDC hdc; //создаём контекст устройства
PAINTSTRUCT ps; //создаём экземпляр структуры графического вывода
LOGFONT lf;
RECT r;
HPEN hPen;
HBRUSH hBrush = CreateSolidBrush(RGB(0, 76, 153));
HFONT hFont;
HWND hTrack;
HWND hTrack1;
HWND FOR6COMPOSIT;



HDC hDC, hCompatibleDC;
PAINTSTRUCT PaintStruct;
HANDLE hBitmap, hOldBitmap;
RECT Rect;
BITMAP Bitmap;

static COLORREF acrCustClr[16]; // массив доп. цветов
static DWORD rgbCurrent;        // начальный выбранный цвет


static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {

    case WM_CREATE: {
        SendMessage(hWnd, WM_SETICON, ICON_BIG, ICON_SMALL);
        BASS_Init(-1, 44100, 0, 0, NULL);
        CreateWindow(TEXT("STATIC"), TEXT("Что желаете запустить?"), WS_VISIBLE | WS_CHILD, 550, 20, 160, 15, hWnd, (HMENU)NULL, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Плеер"), WS_VISIBLE | WS_CHILD, 120, 200, 500, 300, hWnd, (HMENU)ID_BUTTON, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Эмуляторы"), WS_VISIBLE | WS_CHILD, 650, 200, 500, 300, hWnd, (HMENU)Emulators, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Контекстменюмейкер"), WS_VISIBLE | WS_CHILD, 120, 530, 500, 100, hWnd, (HMENU)MENUMAKER, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Квест"), WS_VISIBLE | WS_CHILD, 650, 530, 500, 100, hWnd, (HMENU)QUEST, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Пианино"), WS_VISIBLE | WS_CHILD, 650, 80, 500, 100, hWnd, (HMENU)PIANINO, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Терминал"), WS_VISIBLE | WS_CHILD, 120, 80, 500, 100, hWnd, (HMENU)TERMINAL, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("Скачать ролик с Youtube"), WS_VISIBLE | WS_CHILD, 120, 650, 1030, 25, hWnd, (HMENU)YOUTUBE, NULL, NULL);
        BASS_Start();
        START = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\Mozart.mp3", 0, 0, 0);
        BASS_ChannelPlay(START, false);
        hTrack1 = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | LVS_EX_TRANSPARENTBKGND, 10, 20, 100, 30, hWnd, (HMENU)LENMUSIC1, NULL, NULL);
        ShowWindow(GetDlgItem(hWnd, LENMUSIC1), SW_SHOW);
        CreateWindow(TEXT("STATIC"), TEXT("Громкость"), WS_VISIBLE | WS_CHILD, 25, 60, 70, 18, hWnd, (HMENU)MAKEMAKE, NULL, NULL);
        

    }

                  break;

    case WM_COMMAND: {
        

        if (LOWORD(wParam) == ID_BUTTON)
        {
            ShowWindow(GetDlgItem(hWnd, MAKEMAKE), SW_HIDE);
            BASS_SampleFree(START);
            BASS_ChannelFree(START);
            BASS_StreamFree(START);
            BASS_Stop();
            BASS_Start();
            VISTA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\Vista.mp3", 0, 0, 0);
            BASS_ChannelPlay(VISTA, false);

            SetBkMode(hdc, OPAQUE);
            ShowWindow(GetDlgItem(hWnd, Emulators), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LENMUSIC1), SW_HIDE);

            //ifstream Proga1("settings.cfg");
            //string settings;
            //while (getline(Proga1, settings)) {
            //    hBrush = (HBRUSH)atoi(settings.c_str());
            //}
           /* Proga1.close();*/
            InvalidateRect(hWnd, NULL, FALSE);

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

            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hFile, "Файл");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "Справка");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hCreator, "О разработчике");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hHelp, "Шашнахме");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hUtils, "Системные утилиты");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hInstall, "Установка полезного софта");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hRasvl, "Развлечения");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hOptions, "Настройки");

            AppendMenu(hOptions, MF_STRING, MYCOLOR, "Сменить цвет");
            //AppendMenu(hOptions, MF_STRING, SAVEINI, "Сохранить настройки");





            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));

            AppendMenu(hFile, MF_STRING, IU_STR, "Выход");
            AppendMenu(hFile, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hFile, MF_STRING, MENUMENUMENUMENU, "Вернуться в меню");
            AppendMenu(hFile, MF_STRING, SOURCE, "Исходный код");

            AppendMenu(hAbout, MF_STRING, STRANNIK, "О программе");


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
            //AppendMenu(hHelp, MF_STRING, VIDEO, "Открыть видеоплеер (бета)");
            //AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hHelp, MF_STRING, MENUMAKER, "Открыть контекстменюмейкер для Windows");
            AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hHelp, MF_STRING, YOUTUBE, "Открыть загрузчик видосов с ютуба");
            AppendMenu(hHelp, MF_SEPARATOR, NULL, NULL); 
            AppendMenu(hHelp, MF_STRING, ERTOR, "Открыть генератор случайных чисел");

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


            SetMenu(hWnd, hMenubar);
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, Emulators), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, TERMINAL), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PIANINO), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, MENUMAKER), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, YOUTUBE), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, QUEST), SW_HIDE);

            CreateWindow(TEXT("STATIC"), TEXT("MixPlayer Version Beta 2.1, copyright ©StrannikCorp. All rights reserved"), WS_VISIBLE | WS_CHILD, 400, 20, 475, 25, hWnd, (HMENU)NULLA, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("*************************************Привет, этот плеер проигрывает музыку в любых форматах*********************************************"), WS_VISIBLE | WS_CHILD, 200, 40, 899, 25, hWnd, (HMENU)NULLAS, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("Но расширение надо указывать обязательно!"), WS_VISIBLE | WS_CHILD, 480 - 25, 60, 312, 20, hWnd, (HMENU)NULLASA, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("Тут уже имеется пара композиций"), WS_VISIBLE | WS_CHILD, 500, 100, 230, 20, hWnd, (HMENU)NULLASAS, NULL, NULL);







            CreateWindow(TEXT("BUTTON"), TEXT("Headless Nick - Morning "), WS_VISIBLE | WS_CHILD, 150, 150, 300, 70, hWnd, (HMENU)DEVUSHKA, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Headless Nick - UFO "), WS_VISIBLE | WS_CHILD, 460, 150, 300, 70, hWnd, (HMENU)LETO, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Headless Nick - Sample Adventures "), WS_VISIBLE | WS_CHILD, 770, 150, 300, 70, hWnd, (HMENU)SHAG, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Deteez - Above the Sky"), WS_VISIBLE | WS_CHILD, 150, 230, 300, 70, hWnd, (HMENU)SLOVO, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Violet S - Lonely "), WS_VISIBLE | WS_CHILD, 460, 230, 300, 70, hWnd, (HMENU)CIGARET, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Deteez - Waxie "), WS_VISIBLE | WS_CHILD, 770, 230, 300, 70, hWnd, (HMENU)PEREMEN, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Остановить музыку "), WS_VISIBLE | WS_CHILD, 770, 500, 300, 70, hWnd, (HMENU)STOPS, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Открыть свой файл"), WS_VISIBLE | WS_CHILD, 150, 500, 300, 70, hWnd, (HMENU)FILEY2, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Продолжить"), WS_VISIBLE | WS_CHILD, 460, 500, 300, 70, hWnd, (HMENU)PAUSE2, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Пауза"), WS_VISIBLE | WS_CHILD, 460, 500, 300, 70, hWnd, (HMENU)PAUSE1, NULL, NULL);
            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);
           // ShowWin
             //CreateWindow(TEXT("BUTTON"), TEXT("Очистить RAM"), WS_VISIBLE | WS_CHILD, 550, 600, 110, 20, hWnd, (HMENU)RAMRAM, NULL, NULL);
            

            eMp3 = CreateWindow(TEXT("Edit"), NULL, WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE, 40, 430, 1175, 20, hWnd, (HMENU)YOUMUSIC, NULL, 0);
            CreateWindow("BUTTON", "...", WS_VISIBLE | WS_CHILD, 1220, 430, 20, 20, hWnd, (HMENU)SEARCH, NULL, NULL);
            SendMessageW(eMp3, EM_SETCUEBANNER, FALSE, (LPARAM)L"Путь до вашей музыки, в любом формате =) (С расширением) Например:  MusicPlayer\\Violet S\\Lonely.mp3");
            SetWindowLongPtr(hWnd, GWL_EXSTYLE, WS_EX_ACCEPTFILES);

            hTrack = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | LVS_EX_TRANSPARENTBKGND, 450, 590, 320, 30, hWnd, (HMENU)LENMUSIC, NULL, NULL);
            FOR6COMPOSIT = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | LVS_EX_TRANSPARENTBKGND, 450, 590-270, 320, 30, hWnd, (HMENU)LENMUSIC2, NULL, NULL);
            //hTrack1 = CreateWindow(TRACKBAR_CLASS, "LENGTH", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | LVS_EX_TRANSPARENTBKGND, 150, 390, 923, 30, hWnd, (HMENU)LENMUSIC1, NULL, NULL);
            //SendMessageA(hWnd, TBM_SETPOS, TRUE, 50);
            CreateWindow(TEXT("STATIC"), TEXT("Изменить громкость музыки"), WS_CHILD, 510, 620, 195, 20, hWnd, (HMENU)VOLUMASTA, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("Громкость"), WS_CHILD, 570, 590-240, 70, 20, hWnd, (HMENU)VOLUMASTA1, NULL, NULL);
            ShowWindow(GetDlgItem(hWnd, LENMUSIC2), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, VOLUMASTA1), SW_SHOW);
           //if (PathFileExistsA(str1))
           //{
           //    SetWindowText(eMp3, str1);
           //}

            //Ну вот это уже похоже на С++   =)
            // а как проверить наличие файла?       Нуууу
            // без winapi&        можно попробовать через else.  типа

            
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
                hBrush = CreateSolidBrush(cc.rgbResult);
                rgbCurrent = cc.rgbResult;
            }

            InvalidateRect(hWnd, NULL, FALSE);   // ТО АХРИНЕТЬ ОХУЕТЬ ТОЧНЕЕ. Теперь надо такое же добавить в Терминал... И в Пианино... И еще много куда...
        }
        //if (LOWORD(wParam) == SAVEINI)
        //{
        //    string rgb = to_string(rgbCurrent);

        //    // не удалять ни в коем случае
        //    //if (SHCreateDirectoryEx(NULL, Directory, NULL) ||
        //    //    GetLastError() == ERROR_ALREADY_EXISTS)

        //    //WritePrivateProfileSection("color", "test", "settings.ini");
        //    //WritePrivateProfileString("color", "selected", rgb.c_str(), "settings.ini");




  /*     
            ofstream Proga;

            Proga.open("settings.cfg");
            Proga << rgb;
            Proga.close();*/









        //    //CloseHandle(hIni);
        //}
        //if (LOWORD(wParam) == MYFONT)
        //{
        //    CHOOSEFONT cf;
        //    static LOGFONT lf;        // структура логического шрифта
        //    static DWORD rgbCurrent;  // текущий цвет текста
        //    HFONT hfont, hfontPrev;
        //    DWORD rgbPrev;

        //    ZeroMemory(&cf, sizeof(CHOOSEFONT));
        //    cf.lStructSize = sizeof(CHOOSEFONT);
        //    cf.hwndOwner = hWnd;
        //    cf.lpLogFont = &lf;
        //    cf.rgbColors = rgbCurrent;
        //    cf.Flags = CF_SCREENFONTS | CF_EFFECTS;

        //    if (ChooseFont(&cf) == TRUE)
        //    {
        //        hfont = CreateFontIndirect(cf.lpLogFont);
        //        hfontPrev = (HFONT)SelectObject(hdc, hfont);
        //        rgbCurrent = cf.rgbColors;
        //        rgbPrev = SetTextColor(hdc, rgbCurrent);
        //        SendMessage(hWnd, WM_SETFONT, (WPARAM)hfont, FALSE);
        //        InvalidateRect(hWnd, NULL, TRUE);
        //        // ладно
        //    }     
        //}
        //if (LOWORD(wParam) == MYFONT)
        //{
        //    HFONT hFont = CreateFont(15, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, _T("Consolas"));
        //    SendMessage(hWnd, WM_SETFONT, (WPARAM)hFont, NULL);
        //}
        if (LOWORD(wParam) == MENUMAKER)
        {
            system("start MusicPlayer\\MENUMAKER\\MENUMAKER.exe");
          
        }
        if (LOWORD(wParam) == ERTOR)
        {
            system("start MusicPlayer\\SUBS\\ERTOR\\gen.exe");
            
        }
        if (LOWORD(wParam) == YOUTUBE)
        {
            system("start MusicPlayer\\Youtube\\Youtube.exe");
        }
        if (LOWORD(wParam) == HW)
        {
            system("start MusicPlayer\\Install\\HW\\HW.exe");
        }

        if (LOWORD(wParam) == VEGAS)
        {
            system("start MusicPlayer\\Install\\CPUZ\\cpuz64.exe");
        }

        if (LOWORD(wParam) == OBS)
        {
            system("start MusicPlayer\\Install\\OBS\\OBS.exe");
        }

        if (LOWORD(wParam) == VISUALSTUDIO)
        {
            system("start MusicPlayer\\Install\\VisualStudio\\Setup.exe");
        }
        if (LOWORD(wParam) == BOMB)
        {
            system("start MusicPlayer\\Progs\\REVO\\RevoUnin.exe");
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
            MessageBoxA(hWnd, "После закрытия этого окна будут переустановлены все VISUAL C++ редисты, если вы не уверены, то отменить это можно чуть позже в консоли.", "Внимание", MB_ICONINFORMATION);
            system("start MusicPlayer\\Install\\Visual\\Visual.bat");
        }

        if (LOWORD(wParam) == TERMINAL)
        {
            system("start MusicPlayer\\TERMINAL\\TERMINAL.EXE");

        }

        if (LOWORD(wParam) == PIANINO)
        {
            system("start MusicPlayer\\Piano\\piano.exe");

        }
        if (LOWORD(wParam) == CONVERTER)
        {
            system("start MusicPlayer\\CONVERT\\converter.exe");

        }

        if (LOWORD(wParam) == EMULATE || LOWORD(wParam) == Emulators)
        {

            system("start MusicPlayer\\Emulators\\Emulate.exe");
        }
        if (LOWORD(wParam) == DEVUSHKA)
        {
            BASS_Stop();

            BASS_Start();

            CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - Morning"), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)DEFDEF, NULL, NULL);
            BASS_StreamFree(VISTA);
            BASS_SampleFree(VISTA);
            BASS_ChannelFree(VISTA);
            BASS_StreamFree(VISTA);
            BASS_StreamFree(stro);
            BASS_StreamFree(MORNING);
            BASS_StreamFree(UFO);
            BASS_StreamFree(SAMPLEADV);
            BASS_StreamFree(EYES);
            BASS_StreamFree(LONELY);
            BASS_StreamFree(GIRL);
            MORNING = BASS_StreamCreateFile(FALSE, "MusicPlayer\\HeadlessNick\\Morning.mp3", 0, 0, 0);

            BASS_ChannelStop(stro);
            BASS_ChannelStop(MORNING);
            BASS_ChannelStop(UFO);
            BASS_ChannelStop(SAMPLEADV);
            BASS_ChannelStop(EYES);
            BASS_ChannelStop(LONELY);
            BASS_ChannelStop(GIRL);
            BASS_SampleFree(stro);
            BASS_SampleFree(MORNING);
            BASS_SampleFree(UFO);
            BASS_SampleFree(SAMPLEADV);
            BASS_SampleFree(EYES);
            BASS_SampleFree(LONELY);
            BASS_SampleFree(GIRL);
            BASS_ChannelPlay(MORNING, false); // проигрывание файла

        }
        if (LOWORD(wParam) == LETO)
        {
            BASS_Stop();
            BASS_Start();
            ShowWindow(GetDlgItem(hWnd, DEFDEF), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - UFO"), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI, NULL, NULL);
            BASS_StreamFree(VISTA);
            BASS_SampleFree(VISTA);
            BASS_ChannelFree(VISTA);
            BASS_StreamFree(VISTA);
            BASS_StreamFree(stro);
            BASS_StreamFree(MORNING);
            BASS_StreamFree(UFO);
            BASS_StreamFree(SAMPLEADV);
            BASS_StreamFree(EYES);
            BASS_StreamFree(LONELY);
            BASS_StreamFree(GIRL);
            UFO = BASS_StreamCreateFile(FALSE, "MusicPlayer\\HeadlessNick\\UFO.mp3", 0, 0, 0);
            BASS_ChannelStop(MORNING);
            BASS_ChannelStop(UFO);
            BASS_ChannelStop(SAMPLEADV);
            BASS_ChannelStop(EYES);
            BASS_ChannelStop(LONELY);
            BASS_ChannelStop(GIRL);
            BASS_ChannelStop(stro);
            BASS_SampleFree(stro);
            BASS_SampleFree(MORNING);
            BASS_SampleFree(UFO);
            BASS_SampleFree(SAMPLEADV);
            BASS_SampleFree(EYES);
            BASS_SampleFree(LONELY);
            BASS_SampleFree(GIRL);
            BASS_ChannelPlay(UFO, false); // проигрывание файла

        }
        if (LOWORD(wParam) == SHAG)
        {
            BASS_Stop();
            BASS_Start();
            CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - Sample Adventures.mp3"), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI1, NULL, NULL);
            BASS_StreamFree(VISTA);
            BASS_SampleFree(VISTA);
            BASS_ChannelFree(VISTA);
            BASS_StreamFree(VISTA);
            BASS_StreamFree(stro);
            BASS_StreamFree(MORNING);
            BASS_StreamFree(UFO);
            BASS_StreamFree(SAMPLEADV);
            BASS_StreamFree(EYES);
            BASS_StreamFree(LONELY);
            BASS_StreamFree(GIRL);
            SAMPLEADV = BASS_StreamCreateFile(FALSE, "MusicPlayer\\HeadlessNick\\Sample Adventures.mp3", 0, 0, 0);

            BASS_ChannelStop(stro);
            BASS_ChannelStop(MORNING);
            BASS_ChannelStop(UFO);
            BASS_ChannelStop(EYES);
            BASS_ChannelStop(LONELY);
            BASS_ChannelStop(GIRL);
            BASS_SampleFree(stro);
            BASS_SampleFree(MORNING);
            BASS_SampleFree(UFO);
            BASS_SampleFree(SAMPLEADV);
            BASS_SampleFree(EYES);
            BASS_SampleFree(LONELY);
            BASS_SampleFree(GIRL);
            BASS_ChannelPlay(SAMPLEADV, false); // проигрывание файла
        }
        if (LOWORD(wParam) == SLOVO)
        {
            BASS_Stop();
            BASS_Start();
            BASS_SampleFree(VISTA);
            BASS_ChannelFree(VISTA);
            BASS_StreamFree(VISTA);
            CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Deteez - Above the Sky.mp3"), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI2, NULL, NULL);
            BASS_StreamFree(stro);
            BASS_StreamFree(MORNING);
            BASS_StreamFree(UFO);
            BASS_StreamFree(SAMPLEADV);
            BASS_StreamFree(EYES);
            BASS_StreamFree(LONELY);
            BASS_StreamFree(GIRL);
            EYES = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Violet S\\Above the Sky.mp3", 0, 0, 0);
            BASS_ChannelStop(MORNING);
            BASS_ChannelStop(UFO);
            BASS_ChannelStop(SAMPLEADV);
            BASS_ChannelStop(EYES);
            BASS_ChannelStop(LONELY);
            BASS_ChannelStop(GIRL);
            BASS_ChannelStop(stro);
            BASS_SampleFree(stro);
            BASS_SampleFree(MORNING);
            BASS_SampleFree(UFO);
            BASS_SampleFree(SAMPLEADV);
            BASS_SampleFree(EYES);
            BASS_SampleFree(LONELY);
            BASS_SampleFree(GIRL);
            BASS_ChannelPlay(EYES, false); // проигрывание файла

        }
        if (LOWORD(wParam) == CIGARET)
        {
            BASS_Stop();
            BASS_Start();
            BASS_StreamFree(VISTA);
            BASS_SampleFree(VISTA);
            BASS_ChannelFree(VISTA);
            BASS_StreamFree(VISTA);
            CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Violet S - Lonely.mp3"), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI3, NULL, NULL);
            BASS_StreamFree(stro);
            BASS_StreamFree(MORNING);
            BASS_StreamFree(UFO);
            BASS_StreamFree(SAMPLEADV);
            BASS_StreamFree(EYES);
            BASS_StreamFree(LONELY);
            BASS_StreamFree(GIRL);
            LONELY = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Violet S\\Lonely.mp3", 0, 0, 0);
            BASS_ChannelStop(MORNING);
            BASS_ChannelStop(UFO);
            BASS_ChannelStop(SAMPLEADV);
            BASS_ChannelStop(EYES);
            BASS_ChannelStop(LONELY);
            BASS_ChannelStop(GIRL);
            BASS_ChannelStop(stro);
            BASS_SampleFree(stro);
            BASS_SampleFree(MORNING);
            BASS_SampleFree(UFO);
            BASS_SampleFree(SAMPLEADV);
            BASS_SampleFree(EYES);
            BASS_SampleFree(LONELY);
            BASS_SampleFree(GIRL);
            BASS_ChannelPlay(LONELY, false); // проигрывание файла

        }
        if (LOWORD(wParam) == PEREMEN)
        {
            BASS_Stop();
            BASS_Start();
            BASS_StreamFree(VISTA);
            BASS_SampleFree(VISTA);
            BASS_ChannelFree(VISTA);
            BASS_StreamFree(VISTA);
            CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Deteez - Waxie.mp3"), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)XAI4, NULL, NULL);
            BASS_StreamFree(stro);
            BASS_StreamFree(MORNING);
            BASS_StreamFree(UFO);
            BASS_StreamFree(SAMPLEADV);
            BASS_StreamFree(EYES);
            BASS_StreamFree(LONELY);
            BASS_StreamFree(GIRL);
            GIRL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Violet S\\Waxie.mp3", 0, 0, 0);
            BASS_ChannelStop(MORNING);
            BASS_ChannelStop(UFO);
            BASS_ChannelStop(SAMPLEADV);
            BASS_ChannelStop(EYES);
            BASS_ChannelStop(LONELY);
            BASS_ChannelStop(GIRL);
            BASS_ChannelStop(stro);
            BASS_SampleFree(stro);
            BASS_SampleFree(MORNING);
            BASS_SampleFree(UFO);
            BASS_SampleFree(SAMPLEADV);
            BASS_SampleFree(EYES);
            BASS_SampleFree(LONELY);
            BASS_SampleFree(GIRL);
            BASS_ChannelPlay(GIRL, false); // проигрывание файла

        }
        if (LOWORD(wParam) == STOPS)
        {
            CreateWindow(TEXT("STATIC"), TEXT("Музыка выключена"), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)NULL, NULL, NULL);
            BASS_StreamFree(VISTA);
            BASS_SampleFree(VISTA);
            BASS_ChannelFree(VISTA);
            BASS_StreamFree(VISTA);
            BASS_ChannelStop(stro);
            BASS_ChannelStop(MORNING);
            BASS_ChannelStop(UFO);
            BASS_ChannelStop(SAMPLEADV);
            BASS_ChannelStop(EYES);
            BASS_ChannelStop(LONELY);
            BASS_ChannelStop(GIRL);
            BASS_SampleFree(stro);
            BASS_SampleFree(MORNING);
            BASS_SampleFree(UFO);
            BASS_SampleFree(SAMPLEADV);
            BASS_SampleFree(EYES);
            BASS_SampleFree(LONELY);
            BASS_SampleFree(GIRL);
            BASS_StreamFree(stro);
            BASS_StreamFree(MORNING);
            BASS_StreamFree(UFO);
            BASS_StreamFree(SAMPLEADV);
            BASS_StreamFree(EYES);
            BASS_StreamFree(LONELY);
            BASS_StreamFree(GIRL);
            BASS_Stop();
            BASS_Start();

        }

        if (LOWORD(wParam) == WEIGHT)
        {
            MessageBoxA(hWnd, "А зачем вам знать? Вес штука сложная", "Вес", MB_ICONINFORMATION);
        }
        if (LOWORD(wParam) == WOZRAST)
        {
            MessageBoxA(hWnd, "Возраст? Так прям интересно? Ну переведите 10100 в десятичную систему\nА вообще, если вы шашнахме, то знайте, др у меня в хеллоуин", "Возраст 20", MB_ICONINFORMATION);
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
            MessageBoxA(hWnd, "Добро пожаловать в MixOS версии BETA 2.1.\nКоторая нужна для того, чтобы автор набрался опыта.\nЭто уже не просто плеер. Это больше похоже на свою ОС\nПравда без своего ядра (пока что).\nВсё что в ней есть это зеркало автора.\nТо есть, психологически, если углубляться, то можно понять, что MixOS это отражение всего что делает автор и как поступает. ", "О программе MixOS Beta 2.1", MB_ICONINFORMATION);
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
        }
        if (LOWORD(wParam) == IU_STR)
        {
            exit(1);
        }
        if (LOWORD(wParam) == SOURCE)
        {
            MessageBoxA(hWnd, "Исходники лежат на гитхабе", "Исходный код", MB_OK);
            system("start https://github.com/CaptainStrannik/MixOS");

        }
        if (LOWORD(wParam) == PAUSE1)
        {
            CreateWindow(TEXT("STATIC"), TEXT("Пауза"), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)NULL, NULL, NULL);
            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_SHOW);
            BASS_StreamFree(VISTA);
            BASS_SampleFree(VISTA);
            BASS_ChannelFree(VISTA);
            BASS_StreamFree(VISTA);
            BASS_ChannelPause(stro);
            BASS_ChannelStop(MORNING);
            BASS_ChannelStop(UFO);
            BASS_ChannelStop(SAMPLEADV);
            BASS_ChannelStop(EYES);
            BASS_ChannelStop(LONELY);
            BASS_ChannelStop(GIRL);
            BASS_SampleFree(MORNING);
            BASS_SampleFree(UFO);
            BASS_SampleFree(SAMPLEADV);
            BASS_SampleFree(EYES);
            BASS_SampleFree(LONELY);
            BASS_SampleFree(GIRL);
            ShowWindow(GetDlgItem(hWnd, LENMUSIC), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VOLUMASTA), SW_HIDE);

            //пауза
        }
        if (LOWORD(wParam) == PAUSE2)
        {
            BASS_ChannelPlay(stro, false); //плей
            CreateWindow(TEXT("STATIC"), TEXT("Проигрывается ваша музыка)"), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)NULL, NULL, NULL);
            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);
            BASS_StreamFree(VISTA);
            BASS_SampleFree(VISTA);
            BASS_ChannelFree(VISTA);
            BASS_StreamFree(VISTA);
            BASS_ChannelStop(MORNING);
            BASS_ChannelStop(UFO);
            BASS_ChannelStop(SAMPLEADV);
            BASS_ChannelStop(EYES);
            BASS_ChannelStop(LONELY);
            BASS_ChannelStop(GIRL);
            BASS_SampleFree(MORNING);
            BASS_SampleFree(UFO);
            BASS_SampleFree(SAMPLEADV);
            BASS_SampleFree(EYES);
            BASS_SampleFree(LONELY);
            BASS_SampleFree(GIRL);
            ShowWindow(GetDlgItem(hWnd, LENMUSIC), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, VOLUMASTA), SW_SHOW);
        }
        if (LOWORD(wParam) == FILEY2)
        {

            ShowWindow(GetDlgItem(hWnd, LENMUSIC), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, VOLUMASTA), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, DEVUSHKA), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, LETO), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, CIGARET), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, PEREMEN), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SHAG), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, SLOVO), SW_HIDE);
            CreateWindow(TEXT("STATIC"), TEXT("Для файлов теперь работает Drag'n Drop"), WS_VISIBLE | WS_CHILD, 470, 100, 280, 20, hWnd, (HMENU)NULL, NULL, NULL);
            ShowWindow(GetDlgItem(hWnd, LENMUSIC2), SW_HIDE);
            ShowWindow(GetDlgItem(hWnd, VOLUMASTA1), SW_HIDE);

            ShowWindow(GetDlgItem(hWnd, PAUSE1), SW_SHOW);
            ShowWindow(GetDlgItem(hWnd, PAUSE2), SW_HIDE);
            BASS_StreamFree(VISTA);
            BASS_SampleFree(VISTA);
            BASS_ChannelFree(VISTA);
            BASS_StreamFree(VISTA);
            BASS_ChannelStop(MORNING);
            BASS_ChannelStop(UFO);
            BASS_ChannelStop(SAMPLEADV);
            BASS_ChannelStop(EYES);
            BASS_ChannelStop(LONELY);
            BASS_ChannelStop(GIRL);
            BASS_SampleFree(MORNING);
            BASS_SampleFree(UFO);
            BASS_SampleFree(SAMPLEADV);
            BASS_SampleFree(EYES);
            BASS_SampleFree(LONELY);
            BASS_SampleFree(GIRL);
            BASS_SampleFree(stro);


            BASS_StreamFree(MORNING);
            BASS_StreamFree(UFO);
            BASS_StreamFree(SAMPLEADV);
            BASS_StreamFree(EYES);
            BASS_StreamFree(LONELY);
            BASS_StreamFree(GIRL);
            BASS_StreamFree(stro);
            BASS_Stop();
            BASS_Start();

            int len;
            TCHAR StrB[1200];
            len = GetWindowText(eMp3, StrB, 1200);
            BASS_ChannelStop(stro);

            stro = BASS_StreamCreateFile(FALSE, StrB, 0, 0, 0);
            CreateWindow(TEXT("STATIC"), TEXT("Проигрывается ваша музыка) "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)NULL, NULL, NULL);
            BASS_ChannelPlay(stro, false); // проигрывание файла
            //SendMessage(hTrack1, TBM_SETRANGEMIN, TRUE, 0);
            //SendMessage(hTrack1, TBM_SETRANGEMAX, TRUE, BASS_ChannelGetPosition(stro, BASS_POS_BYTE));
            //BASS_ChannelSetAttribute(stro, BASS_ATTRIB_VOL, 1);
            //SendMessage(hTrack, TBM_SETLINESIZE, NULL, 100);
        }
        if (LOWORD(wParam) == QUEST)
        {
            system("start MusicPlayer\\Quest\\quest.exe");
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
            ofn.nFilterIndex = 1;
            ofn.lpstrFileTitle = NULL;
            ofn.nMaxFileTitle = 0;
            ofn.lpstrInitialDir = NULL;
            ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_DONTADDTORECENT;

            if (GetOpenFileName(&ofn) == TRUE)
                SetWindowText(eMp3, str1);
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
        


        if (LOWORD(wParam) == MENUMENUMENUMENU)
        {
            
            system("start MixOS.exe");
            PostQuitMessage(0);

        }
        break;

    case WM_HSCROLL: {
        if (hTrack == (HWND)lParam)
        {
            BASS_ChannelSetAttribute(stro, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 25, 75));
           
        }
        if (hTrack1 == (HWND)lParam)
        {
            BASS_ChannelSetAttribute(START, BASS_ATTRIB_VOL, SendMessage(hTrack1, TBM_GETPOS, 40, 80));

        }
        if (FOR6COMPOSIT == (HWND)lParam)
        {
            BASS_ChannelSetAttribute(GIRL, BASS_ATTRIB_VOL, SendMessage(FOR6COMPOSIT, TBM_GETPOS, 40, 80));
            BASS_ChannelSetAttribute(LONELY, BASS_ATTRIB_VOL, SendMessage(FOR6COMPOSIT, TBM_GETPOS, 40, 80));
            BASS_ChannelSetAttribute(MORNING, BASS_ATTRIB_VOL, SendMessage(FOR6COMPOSIT, TBM_GETPOS, 40, 80));
            BASS_ChannelSetAttribute(UFO, BASS_ATTRIB_VOL, SendMessage(FOR6COMPOSIT, TBM_GETPOS, 40, 80));
            BASS_ChannelSetAttribute(SAMPLEADV, BASS_ATTRIB_VOL, SendMessage(FOR6COMPOSIT, TBM_GETPOS, 40, 80));
            BASS_ChannelSetAttribute(EYES, BASS_ATTRIB_VOL, SendMessage(FOR6COMPOSIT, TBM_GETPOS, 40, 80));
            BASS_ChannelSetAttribute(VISTA, BASS_ATTRIB_VOL, SendMessage(FOR6COMPOSIT, TBM_GETPOS, 40, 80));
        }
        
    } break;

        //Цикл обработки сообщений
    case WM_DROPFILES: {
        DragQueryFile((HDROP)wParam, 0, str1, MAX_PATH);
        SetWindowText(eMp3, str1);
    }
                     break;

    case WM_PAINT: {
        hdc = BeginPaint(hWnd, &ps);
        FillRect(hdc, &ps.rcPaint, hBrush);
        EndPaint(hWnd, &ps);
        return 0;

    } break;

    {

    }
    case WM_DESTROY: {
        PostQuitMessage(0);
        return 0;



    }
                   break;


    default:
        return DefWindowProc(hWnd, uMsg, wParam, lParam);
    }
                   return 0;
    }


}

int WINAPI main(int argc, char* argv[])
{
    if (argc > 1)
    {
        strcpy(str1, argv[1]);
    } 
    WNDCLASS wc;
    ZeroMemory(&wc, sizeof(WNDCLASS));
    wc.lpfnWndProc = wnd_proc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "test32cls";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    //wc.hbrBackground = CreateSolidBrush(RGB(0,76,153));    //0 76 153




    RegisterClass(&wc);
    
    
    CreateWindowA(wc.lpszClassName, "MixOS Beta 2.1", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE|WM_SETICON, (GetSystemMetrics(SM_CXSCREEN) - 1280) / 2,
        
        (GetSystemMetrics(SM_CYSCREEN) - 720) / 2, 1280, 720, NULL, NULL, wc.hInstance, NULL);
    
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

    }

}
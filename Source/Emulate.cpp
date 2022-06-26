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
//#include <iostream>
//#define STRANNI 90
//
//#pragma comment(lib, "winmm.lib")
//#pragma comment(lib, "bass")
//#pragma comment(linker,"/manifestdependency:\"type='win32' \
//                        name='Microsoft.Windows.Common-Controls' \
//                        version='6.0.0.0' processorArchitecture='*'\
// publicKeyToken='6595b64144ccf1df' language='*'\"")
//
//using namespace std;
//char str1[1024];
//
//HSTREAM TITLED;
//HSTREAM HAHA;
//HSTREAM ROBOCOP;
//HBRUSH hBrush = CreateSolidBrush(RGB(72, 161, 139));
//HDC hdc;
//PAINTSTRUCT ps;
//HWND hTrack;
//
//static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//    switch (uMsg) {
//
//    case WM_CREATE: {
//
//        
//        HMENU hMenubar = CreateMenu();
//        HMENU hAbout = CreateMenu();
//        HMENU h8bit = CreateMenu();
//        HMENU h16bit = CreateMenu();
//        HMENU hPS = CreateMenu();
//        HMENU hWindows = CreateMenu();
//        HMENU hPortable = CreateMenu();
//        HMENU hColor = CreateMenu();
//
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "Справка");
//        AppendMenu(hAbout, MF_STRING, ABOUTEMUL, "О программе");
//
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)h8bit, "8 BIT");
//        AppendMenu(h8bit, MF_STRING, DENDY, "Dendy");
//        AppendMenu(h8bit, MF_STRING, ATARI7800, "Atari7800");
//        AppendMenu(h8bit, MF_STRING, EMULATOR3000, "OLDPC");
//        
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)h16bit, "16 BIT");
//        AppendMenu(h16bit, MF_STRING, MEGADRIVE, "SEGA MEGA DRIVE");
//        AppendMenu(h16bit, MF_STRING, SATURN, "SEGA SATURN");
//        AppendMenu(h16bit, MF_STRING, SNES, "SNES");
//
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hPS, "32BIT");
//        AppendMenu(hPS, MF_STRING, PS1, "PlayStation 1");
//        AppendMenu(hPS, MF_STRING, PS2, "PlayStation 2");
//
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hWindows, "Windows");
//        AppendMenu(hWindows, MF_STRING, W311, "Windows 3.11/DOS");
//        AppendMenu(hWindows, MF_STRING, WIN86, "Windows NT 3.51");
//        AppendMenu(hWindows, MF_STRING, W95, "Windows 95");
//        AppendMenu(hWindows, MF_STRING, WINXP, "Windows XP");
//        AppendMenu(hWindows, MF_STRING, WIN8, "Windows 8");
//
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hPortable, "Портативки");
//        AppendMenu(hPortable, MF_STRING, PSP, "PSP");
//        AppendMenu(hPortable, MF_STRING, GBA, "GBA");
//        AppendMenu(hPortable, MF_STRING, treeDS, "3DS");
//
//
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hColor, "Сменить цвет");
//            AppendMenu(hColor, MF_STRING, REDA, "Красный");
//            AppendMenu(hColor, MF_STRING, ORANGEA, "Оранжевый");
//            AppendMenu(hColor, MF_STRING, YELLOWA, "Жёлтый");
//            AppendMenu(hColor, MF_STRING, GREENA, "Зелёный");
//            AppendMenu(hColor, MF_STRING, AZUREA, "Голубой");
//            AppendMenu(hColor, MF_STRING, BLUEA, "Синий");
//            AppendMenu(hColor, MF_STRING, VIOLETA, "Фиолетовый");
//            AppendMenu(hColor, MF_STRING, STANDARTA, "Стандартный");
//            AppendMenu(hColor, MF_STRING, STRACOLOR, "Strannik");
//            AppendMenu(hColor, MF_STRING, COLOREMU,"Мой цвет");
//
//        SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//        CreateWindow(TEXT("STATIC"), TEXT("Список эмуляторов версия 2.0."), WS_VISIBLE | WS_CHILD, 500, 18, 210, 18, hWnd, (HMENU)NULL, NULL, NULL);
//        SetMenu(hWnd, hMenubar);
//        BASS_Init(-1, 44100, 0, 0, NULL);
//
//        CreateWindow(TEXT("STATIC"), TEXT("Программы от подписчиков v.1.1"), WS_VISIBLE | WS_CHILD, 500, 600, 228, 18, hWnd, (HMENU)NULL, NULL, NULL);
//
//        CreateWindow(TEXT("STATIC"), TEXT("Приставки 8 BIT"), WS_VISIBLE | WS_CHILD, 220, 70, 110, 18, hWnd, (HMENU)NULL, NULL, NULL);
//        CreateWindow(TEXT("STATIC"), TEXT("Приставки 8/16 BIT/(SEGA)"), WS_VISIBLE | WS_CHILD, 445, 70, 190, 18, hWnd, (HMENU)NULL, NULL, NULL);
//        CreateWindow(TEXT("STATIC"), TEXT("В представлении не нуждается"), WS_VISIBLE | WS_CHILD, 428, 175, 215, 18, hWnd, (HMENU)NULL, NULL, NULL);
//        CreateWindow(TEXT("STATIC"), TEXT("Старые компы от 1982 до 2000 года"), WS_VISIBLE | WS_CHILD, 830, 70, 250, 18, hWnd, (HMENU)NULL, NULL, NULL);
//        CreateWindow(TEXT("STATIC"), TEXT("Приставки (32BIT)"), WS_VISIBLE | WS_CHILD, 700, 70, 120, 18, hWnd, (HMENU)NULL, NULL, NULL);
//
//
//
//
//        CreateWindow(TEXT("STATIC"), TEXT("Windows и DOS"), WS_VISIBLE | WS_CHILD, 220, 175, 110, 18, hWnd, (HMENU)NULL, NULL, NULL);
//        CreateWindow(TEXT("STATIC"), TEXT("Портативные игровые приставки"), WS_VISIBLE | WS_CHILD, 760, 175, 220, 18, hWnd, (HMENU)NULL, NULL, NULL);
//
//        //CreateWindow(TEXT("STATIC"), TEXT("                                               "), WS_VISIBLE | WS_CHILD, 95, 380, 630, 5, hWnd, (HMENU)NULL, NULL, NULL);
//
//
//        CreateWindow(TEXT("STATIC"), TEXT("Все игры для SEGA MEGA DRIVE находятся в MusicPlayer\\Emulators\\16BIT\\SMDSG\\GAMES"), WS_VISIBLE | WS_CHILD, 105, 400, 620, 18, hWnd, (HMENU)NULL, NULL, NULL);
//        CreateWindow(TEXT("STATIC"), TEXT("Все игры для PlayStation 1 находятся в MusicPlayer\\Emulators\\32BIT\\PlayStation1\\GAMES"), WS_VISIBLE | WS_CHILD, 105, 419, 620, 18, hWnd, (HMENU)NULL, NULL, NULL);
//        CreateWindow(TEXT("STATIC"), TEXT("Все игры для PlayStation 2 находятся в MusicPlayer\\Emulators\\32BIT\\PlayStation2\\GAMES"), WS_VISIBLE | WS_CHILD, 105, 438, 620, 18, hWnd, (HMENU)NULL, NULL, NULL);
//        CreateWindow(TEXT("STATIC"), TEXT("Все игры для Atari7800 находятся в MusicPlayer\\Emulators\\8BIT\\Atari7800\\GAMES"), WS_VISIBLE | WS_CHILD, 105, 438, 620, 18, hWnd, (HMENU)NULL, NULL, NULL);
//        CreateWindow(TEXT("STATIC"), TEXT("Эмулятор старых компов это Эмулятор 3000. В нем уже есть различные компы от 1981 до 2000 года выпуска."), WS_VISIBLE | WS_CHILD, 105, 457, 620, 36, hWnd, (HMENU)NULL, NULL, NULL);
//        CreateWindow(TEXT("STATIC"), TEXT("Эмулятор Sega Saturn работает только если путь до BIOS и до игр написан на инглише. Там уже есть SonicJAM"), WS_VISIBLE | WS_CHILD, 105, 494, 620, 36, hWnd, (HMENU)NULL, NULL, NULL);
//        CreateWindow(TEXT("STATIC"), TEXT("Для экономии места ГТА 3 для PS2 была вырезана, так что качайте ромы для плойки сами"), WS_VISIBLE | WS_CHILD, 105, 531, 620, 36, hWnd, (HMENU)NULL, NULL, NULL);
//        //CreateWindow(TEXT("BUTTON"), TEXT("SEGA MASTER SYSTEM"), WS_VISIBLE | WS_CHILD, 180, 155, 200, 20, hWnd, (HMENU)SMS, NULL, NULL);
//        //CreateWindow(TEXT("BUTTON"), TEXT("SEGA SG 1000"), WS_VISIBLE | WS_CHILD, 180, 200, 200, 20, hWnd, (HMENU)SG1000, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("ATARI 7800"), WS_VISIBLE | WS_CHILD, 180, 135, 200, 20, hWnd, (HMENU)ATARI7800, NULL, NULL);
//
//
//        CreateWindow(TEXT("BUTTON"), TEXT("WINDOWS 3.1 и DOS"), WS_VISIBLE | WS_CHILD, 180, 210, 200, 20, hWnd, (HMENU)W311, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("WINDOWS 95"), WS_VISIBLE | WS_CHILD, 180, 235, 200, 20, hWnd, (HMENU)W95, NULL, NULL);
//        //CreateWindow(TEXT("BUTTON"), TEXT("NINTENDO GAMEBOY"), WS_VISIBLE | WS_CHILD, 180, 245, 200, 20, hWnd, (HMENU)GAMEBOYORIG, NULL, NULL);
//
//        CreateWindow(TEXT("BUTTON"), TEXT("Dendy/NES"), WS_VISIBLE | WS_CHILD, 180, 110, 200, 20, hWnd, (HMENU)DENDY, NULL, NULL);
//
//        CreateWindow(TEXT("BUTTON"), TEXT("Все приставки SEGA от SG1000 до CD32X"), WS_VISIBLE | WS_CHILD, 390, 110, 300, 20, hWnd, (HMENU)MEGADRIVE, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("SEGA SATURN"), WS_VISIBLE | WS_CHILD, 390, 135, 300, 20, hWnd, (HMENU)SATURN, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("SUPER NINTENDO!!!"), WS_VISIBLE | WS_CHILD, 390, 210, 300, 45, hWnd, (HMENU)SNES, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Включить музыку"), WS_VISIBLE | WS_CHILD, 15, 15, 150, 20, hWnd, (HMENU)TITLE, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Выключить музыку"), WS_VISIBLE | WS_CHILD, 15, 15, 150, 20, hWnd, (HMENU)TITLESTOP, NULL, NULL);
//        TITLED = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\title.mp3", 0, 0, 0);
//
//        BASS_ChannelPlay(TITLED, false);
//        CreateWindow(TEXT("BUTTON"), TEXT("PlayStation 1"), WS_VISIBLE | WS_CHILD, 700, 110, 120, 20, hWnd, (HMENU)PS1, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("PlayStation 2"), WS_VISIBLE | WS_CHILD, 700, 135, 120, 20, hWnd, (HMENU)PS2, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("PSP"), WS_VISIBLE | WS_CHILD, 700, 210, 120, 45, hWnd, (HMENU)PSP, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("GBA"), WS_VISIBLE | WS_CHILD, 830, 210, 120, 45, hWnd, (HMENU)GBA, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("3DS"), WS_VISIBLE | WS_CHILD, 960, 210, 120, 45, hWnd, (HMENU)treeDS, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Скачать ромы для 3DS"), WS_VISIBLE | WS_CHILD, 1090, 15, 160, 20, hWnd, (HMENU)Download, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Скачать ромы для PS2"), WS_VISIBLE | WS_CHILD, 1090, 40, 160, 20, hWnd, (HMENU)Download1, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Эмулятор старых компов 1981-2000"), WS_VISIBLE | WS_CHILD, 830, 110, 250, 45, hWnd, (HMENU)EMULATOR3000, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("ШАШНАХМЕ ВСЕХ В ТАРКВАРУ"), WS_VISIBLE | WS_CHILD, 735, 400, 420, 167, hWnd, (HMENU)HAHAHA, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("WINDOWS XP BROWSER EDITION WTF IS GOING ON?!!!"), WS_VISIBLE | WS_CHILD, 180, 270, 900, 35, hWnd, (HMENU)WINXP, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("86box+Windows NT 3.51"), WS_VISIBLE | WS_CHILD, 180, 310, 900, 35, hWnd, (HMENU)WIN86, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("Windows 8 [IGORPC]"), WS_VISIBLE | WS_CHILD, 180+360, 640, 150, 35, hWnd, (HMENU)WIN8, NULL, NULL);
//        CreateWindow(TEXT("BUTTON"), TEXT("GENERATOR [ERTOR]"), WS_VISIBLE | WS_CHILD, 180 + 360, 640+40, 150, 35, hWnd, (HMENU)ERTOR, NULL, NULL);
//
//        //hTrack = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | LVS_EX_TRANSPARENTBKGND|WS_VISIBLE, 20, 350, 320, 30, hWnd, (HMENU)LENMUSIC, NULL, NULL);
//        hTrack = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS| TBS_VERT | TBSTYLE_TOOLTIPS | LVS_EX_TRANSPARENTBKGND | WS_VISIBLE, 1100, 80, 25, 170, hWnd, (HMENU)LENMUSIC, NULL, NULL);
//        CreateWindow(TEXT("STATIC"), TEXT("Громкость"), WS_VISIBLE | WS_CHILD, 1140, 130, 70, 18, hWnd, (HMENU)MAKEMAKE, NULL, NULL);    //Это не бегунок, а текст      //MAX VOLUME почему-то внизу.
//
//        // Не...
//        // Можешь тогда сделать так, чтобы окно по центру экрана спавнилось?
//        // покажи   ОООЛ ПОЛУЧИЛОСЬ   Вот только звук и его громкость не меняется
//        ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
//        ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_SHOW);
//        break;
//    }
//    case WM_COMMAND: 
//    {
//
//        BASS_Init(-1, 44100, 0, 0, NULL);
//        if (LOWORD(wParam) == ABOUTEMUL)
//        {
//            MessageBoxA(hWnd, "Это сборник эмуляторов и игр. Для вашего удобства =)", "О программе", MB_OK);
//        }
//        if (LOWORD(wParam) == DENDY)
//        {
//            system("start MusicPlayer\\Emulators\\8BIT\\NES-FAMICOM\\fceux64.exe MusicPlayer\\Emulators\\8BIT\\NES-FAMICOM\\Coolgirl.nes");
//        }
//        if (LOWORD(wParam) == ERTOR)
//        {
//            system("start MusicPlayer\\SUBS\\ERTOR\\gen.exe");
//        }
//        if (LOWORD(wParam) == WIN8)
//        {
//            system("start MusicPlayer\\SUBS\\IGOR2677\\Win8\\F\\GoogleChromePortable.exe file://C://WIN//WIN8//index.html");
//        }
//        if (LOWORD(wParam) == ATARI7800)
//        {
//            system("start MusicPlayer\\Emulators\\8BIT\\ATARI7800\\ProSystem.exe MusicPlayer\\Emulators\\8BIT\\ATARI7800\\GAMES\\32.bin");
//        }
//
//        if (LOWORD(wParam) == MEGADRIVE)
//        {
//            system("start MusicPlayer\\Emulators\\16BIT\\SMDSG\\Fusion.exe MusicPlayer\\Emulators\\16BIT\\SMDSG\\GAMES\\Sonic.gen");
//        }
//        if (LOWORD(wParam) == PS1)
//        {
//            system("start MusicPlayer\\Emulators\\32BIT\\PlayStation1\\PSXeven_v0.19.exe");
//
//        }
//        if (LOWORD(wParam) == PS2)
//        {
//            system("start MusicPlayer\\Emulators\\32BIT\\PlayStation2\\pcsx2.exe");
//
//        }
//        if (LOWORD(wParam) == EMULATOR3000)
//        {
//            system("del MusicPlayer\\Emulators\\OLDPC\\Emulator3000\\Emulator3000.autosave");
//            system("del MusicPlayer\\Emulators\\OLDPC\\Emulator3000\\Emulator3000.BAK");
//            system("del MusicPlayer\\Emulators\\OLDPC\\Emulator3000\\Emulator3000.config");
//            system("start MusicPlayer\\Emulators\\OLDPC\\Emulator3000\\Emulator3000.exe");
//        }
//        if (LOWORD(wParam) == SATURN)
//        {
//            system("start MusicPlayer\\Emulators\\16BIT\\SEGASATURN\\yabause.exe");
//        }
//        if (LOWORD(wParam) == GBA)
//        {
//            system("start MusicPlayer\\Emulators\\PORTABLE\\GBA\\mGBA.exe MusicPlayer\\Emulators\\PORTABLE\\GBA\\GAMES\\Sonic.gba");
//        }
//        if (LOWORD(wParam) == PSP)
//        {
//            system("start MusicPlayer\\Emulators\\PORTABLE\\PSP\\PPSSPPWindows64.exe");
//        }
//        if (LOWORD(wParam) == treeDS)
//        {
//            system("start MusicPlayer\\Emulators\\PORTABLE\\3DS\\citra-qt.exe MusicPlayer\\Emulators\\Portable\\3DS\\GAMES\\Mario.cia");
//        }
//        if (LOWORD(wParam) == SNES)
//        {
//            system("start MusicPlayer\\Emulators\\16BIT\\SNES\\bsnes_hd.exe MusicPlayer\\Emulators\\16BIT\\SNES\\GAMES\\MARIO.sfc");
//        }
//
//        if (LOWORD(wParam) == TITLE)
//        {
//            BASS_Stop();
//            BASS_Start();
//            BASS_StreamFree(TITLED);
//            BASS_ChannelStop(TITLED);
//            BASS_SampleFree(TITLED);
//            BASS_StreamFree(HAHA);
//            BASS_ChannelStop(HAHA);
//            BASS_SampleFree(HAHA);
//            TITLED = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\title.mp3", 0, 0, 0);
//            BASS_ChannelStop(TITLED);
//            BASS_SampleFree(TITLED);
//            BASS_ChannelPlay(TITLED, false);
//            ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_SHOW);
//        }
//        if (LOWORD(wParam) == TITLESTOP)
//        {
//            BASS_Stop();
//            BASS_Start();
//            BASS_StreamFree(TITLED);
//            BASS_ChannelStop(TITLED);
//            BASS_SampleFree(TITLED);
//            BASS_StreamFree(HAHA);
//            BASS_ChannelStop(HAHA);
//            BASS_SampleFree(HAHA);
//            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
//        }
//        if (LOWORD(wParam) == W311)
//        {
//            system("start MusicPlayer\\W311\\dosbox.exe -conf MusicPlayer\\W311\\dosbox.conf -noconsole");
//        }
//        if (LOWORD(wParam) == W95)
//        {
//            system("start MusicPlayer\\Emulators\\OLDPC\\WIN95\\windows95.exe");
//        }
//        if (LOWORD(wParam) == Download)
//        {
//            system("start https://archive.org/download/3dsdecrypted");
//        }
//        if (LOWORD(wParam) == Download1)
//        {
//            system("start https://wowroms.com/ru/isos/list/playstation%2B2?sort=download");
//        }
//        if (LOWORD(wParam) == WINXP)
//        {
//            system("start https://winxp.vercel.app/");
//        }
//        if (LOWORD(wParam) == HAHAHA)
//        {
//            BASS_Stop();
//            BASS_Start();
//            BASS_StreamFree(TITLED);
//            BASS_ChannelStop(TITLED);
//            BASS_SampleFree(TITLED);
//            BASS_StreamFree(HAHA);
//            BASS_ChannelStop(HAHA);
//            BASS_SampleFree(HAHA);
//            system("start https://www.youtube.com/watch?v=vNbDeuOzXdA");
//            HAHA = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\i.mp3", 0, 0, 0);
//            BASS_ChannelPlay(HAHA, false);
//        }
//        if (LOWORD(wParam) == WIN86)
//        {
//            system("start MusicPlayer\\Emulators\\OLDPC\\WINNT\\Win351\\86box.exe MusicPlayer\\Emulators\\OLDPC\\WINNT\\Win351\\86Box.cfg");
//        }
//
//        if (LOWORD(wParam) == REDA)
//        {
//            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
//        BASS_Stop();
//        BASS_Start();
//        BASS_StreamFree(TITLED);
//        BASS_ChannelStop(TITLED);
//        BASS_SampleFree(TITLED);
//        BASS_Start();
//        TITLED = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\title7.mp3", 0, 0, 0);
//        BASS_ChannelPlay(TITLED, false);
//        hBrush = CreateSolidBrush(RGB(204, 0, 0));
//        InvalidateRect(hWnd, NULL, FALSE);
//        }
//        if (LOWORD(wParam) == ORANGEA)
//        {
//            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
//            BASS_Stop();
//            BASS_Start();
//            BASS_StreamFree(TITLED);
//            BASS_ChannelStop(TITLED);
//            BASS_SampleFree(TITLED);
//            BASS_Start();
//            TITLED = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\title1.mp3", 0, 0, 0);
//            BASS_ChannelPlay(TITLED, false);
//            hBrush = CreateSolidBrush(RGB(255, 128, 0));
//            InvalidateRect(hWnd, NULL, FALSE);
//        }
//        if (LOWORD(wParam) == YELLOWA)
//        {
//            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
//            BASS_Stop();
//            BASS_Start();
//            BASS_StreamFree(TITLED);
//            BASS_ChannelStop(TITLED);
//            BASS_SampleFree(TITLED);
//            BASS_Start();
//            TITLED = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\title6.mp3", 0, 0, 0);
//            BASS_ChannelPlay(TITLED, false);
//            hBrush = CreateSolidBrush(RGB(255, 255, 0));
//            InvalidateRect(hWnd, NULL, FALSE);
//        }
//        if (LOWORD(wParam) == GREENA)
//        {
//            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
//            BASS_Stop();
//            BASS_Start();
//            BASS_StreamFree(TITLED);
//            BASS_ChannelStop(TITLED);
//            BASS_SampleFree(TITLED);
//            BASS_Start();
//            TITLED = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\title2.mp3", 0, 0, 0);
//            BASS_ChannelPlay(TITLED, false);
//            hBrush = CreateSolidBrush(RGB(0, 153, 0));
//            InvalidateRect(hWnd, NULL, FALSE);
//        }
//        if (LOWORD(wParam) == AZUREA)
//        {
//            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
//            BASS_Stop();
//            BASS_Start();
//            BASS_StreamFree(TITLED);
//            BASS_ChannelStop(TITLED);
//            BASS_SampleFree(TITLED);
//            BASS_Start();
//            TITLED = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\title3.mp3", 0, 0, 0);
//            BASS_ChannelPlay(TITLED, false);
//            hBrush = CreateSolidBrush(RGB(0, 255, 255));
//            InvalidateRect(hWnd, NULL, FALSE);
//        }
//        if (LOWORD(wParam) == BLUEA)
//        {
//            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
//            BASS_Stop();
//            BASS_Start();
//            BASS_StreamFree(TITLED);
//            BASS_ChannelStop(TITLED);
//            BASS_SampleFree(TITLED);
//            BASS_Start();
//            TITLED = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\title5.mp3", 0, 0, 0);
//            BASS_ChannelPlay(TITLED, false);
//            hBrush = CreateSolidBrush(RGB(0, 0, 200));
//            InvalidateRect(hWnd, NULL, FALSE);
//        }
//        if (LOWORD(wParam) == VIOLETA)
//        {
//            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
//            BASS_Stop();
//            BASS_Start();
//            BASS_StreamFree(TITLED);
//            BASS_ChannelStop(TITLED);
//            BASS_SampleFree(TITLED);
//            BASS_Start();
//            TITLED = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\title4.mp3", 0, 0, 0);
//            BASS_ChannelPlay(TITLED, false);
//            hBrush = CreateSolidBrush(RGB(51, 0, 102));
//            InvalidateRect(hWnd, NULL, FALSE);
//        }
//        if (LOWORD(wParam) == STANDARTA)
//        {
//            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, TITLE), SW_SHOW);
//            BASS_Stop();
//            BASS_Start();
//            BASS_StreamFree(TITLED);
//            BASS_ChannelStop(TITLED);
//            BASS_SampleFree(TITLED);
//            BASS_Start();
//            TITLED = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\title.mp3", 0, 0, 0);
//            BASS_ChannelPlay(TITLED, false);
//            hBrush = CreateSolidBrush(RGB(72, 161, 139));
//            InvalidateRect(hWnd, NULL, FALSE);
//        }
//        if (LOWORD(wParam) == STRACOLOR)
//        {
//            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
//            BASS_Stop();
//            BASS_Start();
//            BASS_StreamFree(TITLED);
//            BASS_ChannelStop(TITLED);
//            BASS_SampleFree(TITLED);
//            BASS_Start();
//            TITLED = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\HTM.mp3", 0, 0, 0);
//            BASS_ChannelPlay(TITLED, false);
//            hBrush = CreateSolidBrush(RGB(142, 97, 38));
//            InvalidateRect(hWnd, NULL, FALSE);
//        }
//        if (LOWORD(wParam) == COLOREMU)
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
//            if (ChooseColor(&cc) == TRUE)
//            {
//                hBrush = CreateSolidBrush(cc.rgbResult);
//                rgbCurrent = cc.rgbResult;
//            }
//
//            InvalidateRect(hWnd, NULL, FALSE);   // ТО АХРИНЕТЬ ОХУЕТЬ ТОЧНЕЕ. Теперь надо такое же добавить в Терминал... И в Пианино... И еще много куда...
//            ShowWindow(GetDlgItem(hWnd, TITLESTOP), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, TITLE), SW_HIDE);
//            BASS_Stop();
//            BASS_Start();
//            BASS_StreamFree(TITLED);
//            BASS_ChannelStop(TITLED);
//            BASS_SampleFree(TITLED);
//            BASS_Start();
//            TITLED = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\Youtube.mp3", 0, 0, 0);
//            BASS_ChannelPlay(TITLED, false);
//            
//        }
//        break;
//
//        case WM_VSCROLL: {    //Короче, бегунок работает, но макс громкость та, что внизу... надо поменять, как-то...
//            if (hTrack == (HWND)lParam)
//            {
//                //Потому что недавно вышла статья, которая запрещает как-либо критиковать тот пиздец, что происходит... И если ее нарушить, то это минимум 15 лет тюрьмы. А я не хочу жизнь ломать свою...
//
//                BASS_ChannelSetAttribute(TITLED, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 80, 100)); //ПРОБОВАТЬ?
//                /*BASS_ChannelSetAttribute(ROBOCOP, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 80, 100));*/
//                //Типа это в целом не обязательно, учитывая, что до конца композициивсё равно никто не дожидается.. Но тип.. так чист на досуге посмотреть. А сейчас всё работает, просто координаты надо подобрать
//
//            }
//        
//    } break;
//
//        case WM_PAINT: {
//    hdc = BeginPaint(hWnd, &ps);
//    FillRect(hdc, &ps.rcPaint, hBrush);
//    EndPaint(hWnd, &ps);
//
//}
//             break;
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
//    WNDCLASS op;
//    ZeroMemory(&op, sizeof(WNDCLASS));
//    op.lpfnWndProc = wnd_proc;
//    op.hInstance = GetModuleHandle(NULL);
//    op.lpszClassName = "test32cls";
//    op.hCursor = LoadCursor(NULL, IDC_ARROW);
//    op.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
//    //op.hbrBackground = CreateSolidBrush(RGB(72,161 , 139));     //72 61 139      204 0 0             255 128 0        51 255 255      0 153 0
//    RegisterClass(&op);
//
//
//    //Вот тут видишь, всё работает исправно, и цвет меняется и всё остальное. И при этом звук не дублируется. По-любому, где- то в Youtube.cpp мы забыли BassSTOP
//
//    CreateWindowA(op.lpszClassName, "Эмуляторы", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_VISIBLE, 100, 100, 1280, 800, NULL, NULL, op.hInstance, NULL);
//    MSG msg;
//    while (GetMessage(&msg, NULL, 0, 0)) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//
//    }
//
//}
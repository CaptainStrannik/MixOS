//#include <windows.h>
//#include <cstring>
//#include<iostream>
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
//#include <fstream>
//#include "bass.h"
//#include <random>
//#include <ctime>
//
//
//
//
//
//HWND COM;
//HSTREAM stroka;
//
//
//#pragma comment(linker,"/manifestdependency:\"type='win32' \
//                        name='Microsoft.Windows.Common-Controls' \
//                        version='6.0.0.0' processorArchitecture='*'\
// publicKeyToken='6595b64144ccf1df' language='*'\"")
//
//#pragma comment(lib, "winmm.lib")
//#pragma comment(lib, "bass")
//using namespace std;
//char str1[1024];
//
//
//static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//    switch (uMsg) {
//    case WM_CREATE: {
//        DeleteObject((HBRUSH)SetClassLongPtr(hWnd, GCLP_HBRBACKGROUND, (LONG_PTR)CreateSolidBrush(RGB(70, 125, 0))));
//        COM = CreateWindow(TEXT("EDIT"), TEXT(""), WS_CHILD | WS_VISIBLE | WS_VSCROLL | WS_HSCROLL | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE, 10, 10, 350, 350, hWnd, (HMENU)WRITING, NULL, 0);
//        int a = 120;
//
//        HMENU hMenubar = CreateMenu();
//
//        HMENU hAbout = CreateMenu();
//
//        SetWindowText(hWnd, ("Терминал StrannikCorp ver 1.0"));
//
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "Справка");
//
//        BASS_Init(-1, 44100, 0, 0, NULL);
//
//
//        SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//
//
//        AppendMenu(hAbout, MF_STRING, STRANNIK, "О программе");
//        SetMenu(hWnd, hMenubar);
//        
//        CreateWindowA(TEXT("BUTTON"), TEXT("Ввести команду"), WS_VISIBLE | WS_CHILD  , 400, 230, 150, 35, hWnd, (HMENU)COMMANDA, NULL, NULL);
//        CreateWindowA(TEXT("BUTTON"), TEXT("Список комманд"), WS_VISIBLE | WS_CHILD, 400, 130, 150, 35, hWnd, (HMENU)HELPAS, NULL, NULL);
//
//
//        break;
//    }
//
//    case WM_COMMAND: 
//    {
//     
//
//        int len5;
//        TCHAR StrC[1200];
//        len5 = GetWindowText(COM, StrC, 1200);
//        if (LOWORD(wParam) == STRANNIK)
//        
//        {
//            MessageBoxA(hWnd, "Это консольно-графический терминал, встроенный в плеер.\nНужен по факту для отладки и просто для приятного времяпрепровождения консольщика =)", "О программе", MB_OK);
//        }
//
//        if (LOWORD(wParam) == HELPAS)
//        {
//            MessageBoxA(hWnd, "HELP - Вывод списка комманд  \nINFO - Информация о программе  \nKILL - Воспроизведение музыки смерти Марио  \nNYANCAT - Проигрывание музыки няшного кота.  \nSTOPMUSIC - Выключение музыки", "Список комманд", MB_OK);
//        }
//        if (LOWORD(wParam) == COMMANDA)
//        {
//            string text = StrC;
//   
//            if (text == "HELP")
//            {
//                MessageBoxA(hWnd, "HELP - Вывод списка комманд  \nINFO - Информация о программе  \nKILL - Воспроизведение музыки смерти Марио  \nNYANCAT - Проигрывание музыки няшного кота.  \nSTOPMUSIC - Выключение музыки  \nCMD - Командная строка с секреткой.  \nQUIT или EXIT - Закрыть терминал.  \nОстальные команды могут открыться по мере прохождения =).  \nBROWSER - Открыть браузер  \nP.S ТОЛЬКО ПОПРОБУЙТЕ ВВЕСТИ - STRANNIK.", "Список комманд", MB_OK);
//            }
//            if (text == "INFO")
//            {
//                MessageBoxA(hWnd, "Это терминал. Графический терминал. \nВпервые появился в музыкальном плеере версии BETA 1.7.\nИ, честно, был добавлен по приколу. \nТут имеются команды, довольно прикольного типа. \nЧерез терминал почти невозможно убить винду, хотя я не пытался.", "Информация о терминале", MB_OK);
//
//            }
//            if (text == "KILL")
//            {
//                HSTREAM KILL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\kill.mp3", 0, 0, 0);
//
//                
//                BASS_ChannelPlay(KILL, false);
//
//                if (LOWORD(wParam) == CLEARRAM)
//                {
//                    BASS_MusicFree(KILL);
//                    BASS_StreamFree(KILL);
//                }
//
//            }
//            if (text == "NYANCAT")
//            {
//
//                HSTREAM NYANCAT = BASS_StreamCreateFile(FALSE, "MusicPlayer\\TERMINAL\\NYANCAT.mp3", 0, 0, 0);
//                BASS_ChannelPlay(NYANCAT, false);
//                
//            }
//            if (text == "CMD")
//            {
//                MessageBoxA(hWnd, "Э нет, братан. Хочешь угробить винду? \nА потом будешь жаловаться, что она сломалась? \nНе, так не пойдет.", "АХРИНЕЛ?", MB_ICONERROR);
//            }
//            if (text == "POWERSHELL")
//            {
//                MessageBoxA(hWnd, "Ты вообще что ли? Ну ладно. Открыл секретку, в честь нее полагается приз. В качестве приза команда POWERSHELL1", "Переиграл и уничтожил", MB_ICONERROR);
//                HSTREAM BONUS = BASS_StreamCreateFile(FALSE, "MusicPlayer\\TERMINAL\\bonus.mp3", 0, 0, 0);
//                BASS_ChannelPlay(BONUS, false);
//            }
//            if (text == "POWERSHELL1")
//            {
//                system("powershell");
//            }
//            if (text == "rd C: /s/q")
//            {
//                HSTREAM BONUS = BASS_StreamCreateFile(FALSE, "MusicPlayer\\TERMINAL\\bonus.mp3", 0, 0, 0);
//                BASS_ChannelPlay(BONUS, false);
//                HSTREAM REMAX = BASS_StreamCreateFile(FALSE, "MusicPlayer\\TERMINAL\\REMAX.mp3", 0, 0, 0);
//                BASS_ChannelPlay(REMAX, false);
//              MessageBoxA(hWnd, "Изменить цвет командной строки - \nCMDCOLOR XX (Вместо ХХ, цифры от 00, до FF).  \nMLP - Включить My little pony.  \nBROWSER - Открыть Браузер.  \nПосле нажатия на ОК, я все же удалю тебе винду", "Бонус команды", MB_ICONASTERISK);
//              system("start MusicPlayer\\TERMINAL\\RD.bat");
//            }
//            if (text == "STOPMUSIC")
//            {
//                BASS_Stop();
//                BASS_Start();
//            }
//            if (text == "MLP")
//            {
//                system("start https://www.youtube.com/watch?v=KDcdkNM0zh0&list=PLPiN9r5uRuh3ZuWfLw6HxmRAZCrNTV7Ts");
//            }
//            if (text == "BROWSER")
//            {
//                system("start https://yandex.ru");
//            }
//
//
//
//
//
//            if (text == "QUIT" || text == "EXIT")
//            {
//                PostQuitMessage(0);
//                return 0;
//            }
//            if (text == "STRANNIK")
//            {
//                system("start https://www.youtube.com/channel/UCWlCZoSIqf7mm167pjwIJCw");
//            }
//            if (text == "QUEST")
//            {
//                system("start MusicPlayer\\Quest\\quest.exe");
//            }
//
//
//
//
//
//            if (text == "CMDCOLOR 00")
//            {
//                system("start color 00");
//            }
//            if (text == "CMDCOLOR 01")
//            {
//                system("start color 01");
//            }
//            if (text == "CMDCOLOR 02")
//            {
//                system("start color 02");
//            }
//            if (text == "CMDCOLOR 03")
//            {
//                system("start color 03");
//            }
//            if (text == "CMDCOLOR 04")
//            {
//                system("start color 04");
//            }
//            if (text == "CMDCOLOR 05")
//            {
//                system("start color 05");
//            }
//            if (text == "CMDCOLOR 06")
//            {
//                system("start color 06");
//            }
//            if (text == "CMDCOLOR 07")
//            {
//                system("start color 07");
//            }
//            if (text == "CMDCOLOR 08")
//            {
//                system("start color 08");
//            }
//            if (text == "CMDCOLOR 09")
//            {
//                system("start color 09");
//            }
//            if (text == "CMDCOLOR 0A")
//            {
//                system("start color 0A");
//            }
//            if (text == "CMDCOLOR 0B")
//            {
//                system("start color 0B");
//            }
//            if (text == "CMDCOLOR 0C")
//            {
//                system("start color 0C");
//            }
//            if (text == "CMDCOLOR 0D")
//            {
//                system("start color 0D");
//            }
//            if (text == "CMDCOLOR 0E")
//            {
//                system("start color 0E");
//            }
//            if (text == "CMDCOLOR 0F")
//            {
//                system("start color 0F");
//            }
//
//
//
//
//
//            if (text == "CMDCOLOR 10")
//            {
//                system("start color 10");
//            }
//            if (text == "CMDCOLOR 11")
//            {
//                system("start color 11");
//            }
//            if (text == "CMDCOLOR 12")
//            {
//                system("start color 12");
//            }
//            if (text == "CMDCOLOR 13")
//            {
//                system("start color 13");
//            }
//            if (text == "CMDCOLOR 14")
//            {
//                system("start color 14");
//            }
//            if (text == "CMDCOLOR 15")
//            {
//                system("start color 15");
//            }
//            if (text == "CMDCOLOR 16")
//            {
//                system("start color 16");
//            }
//            if (text == "CMDCOLOR 17")
//            {
//                system("start color 17");
//            }
//            if (text == "CMDCOLOR 18")
//            {
//                system("start color 18");
//            }
//            if (text == "CMDCOLOR 19")
//            {
//                system("start color 19");
//            }
//            if (text == "CMDCOLOR 1A")
//            {
//                system("start color 1A");
//            }
//            if (text == "CMDCOLOR 1B")
//            {
//                system("start color 1B");
//            }
//            if (text == "CMDCOLOR 1C")
//            {
//                system("start color 1C");
//            }
//            if (text == "CMDCOLOR 1D")
//            {
//                system("start color 1D");
//            }
//            if (text == "CMDCOLOR 1E")
//            {
//                system("start color 1E");
//            }
//            if (text == "CMDCOLOR 1F")
//            {
//                system("start color 1F");
//            }
//
//
//
//
//
//
//            if (text == "CMDCOLOR 20")
//            {
//                system("start color 20");
//            }
//            if (text == "CMDCOLOR 21")
//            {
//                system("start color 21");
//            }
//            if (text == "CMDCOLOR 22")
//            {
//                system("start color 22");
//            }
//            if (text == "CMDCOLOR 23")
//            {
//                system("start color 23");
//            }
//            if (text == "CMDCOLOR 24")
//            {
//                system("start color 24");
//            }
//            if (text == "CMDCOLOR 25")
//            {
//                system("start color 25");
//            }
//            if (text == "CMDCOLOR 26")
//            {
//                system("start color 26");
//            }
//            if (text == "CMDCOLOR 27")
//            {
//                system("start color 27");
//            }
//            if (text == "CMDCOLOR 28")
//            {
//                system("start color 28");
//            }
//            if (text == "CMDCOLOR 29")
//            {
//                system("start color 29");
//            }
//            if (text == "CMDCOLOR 2A")
//            {
//                system("start color 2A");
//            }
//            if (text == "CMDCOLOR 2B")
//            {
//                system("start color 2B");
//            }
//            if (text == "CMDCOLOR 2C")
//            {
//                system("start color 2C");
//            }
//            if (text == "CMDCOLOR 2D")
//            {
//                system("start color 2D");
//            }
//            if (text == "CMDCOLOR 2E")
//            {
//                system("start color 2E");
//            }
//            if (text == "CMDCOLOR 2F")
//            {
//                system("start color 2F");
//            }
//                
//        
//
//
//
//            if (text == "CMDCOLOR 30")
//            {
//                system("start color 30");
//            }
//            if (text == "CMDCOLOR 31")
//            {
//                system("start color 31");
//            }
//            if (text == "CMDCOLOR 32")
//            {
//                system("start color 32");
//            }
//            if (text == "CMDCOLOR 33")
//            {
//                system("start color 33");
//            }
//            if (text == "CMDCOLOR 34")
//            {
//                system("start color 34");
//            }
//            if (text == "CMDCOLOR 35")
//            {
//                system("start color 35");
//            }
//            if (text == "CMDCOLOR 36")
//            {
//                system("start color 36");
//            }
//            if (text == "CMDCOLOR 37")
//            {
//                system("start color 37");
//            }
//            if (text == "CMDCOLOR 38")
//            {
//                system("start color 38");
//            }
//            if (text == "CMDCOLOR 39")
//            {
//                system("start color 39");
//            }
//            if (text == "CMDCOLOR 3A")
//            {
//                system("start color 3A");
//            }
//            if (text == "CMDCOLOR 3B")
//            {
//                system("start color 3B");
//            }
//            if (text == "CMDCOLOR 3C")
//            {
//                system("start color 3C");
//            }
//            if (text == "CMDCOLOR 3D")
//            {
//                system("start color 3D");
//            }
//            if (text == "CMDCOLOR 3E")
//            {
//                system("start color 3E");
//            }
//            if (text == "CMDCOLOR 3F")
//            {
//                system("start color 3F");
//            }
//      
//
//
//
//            if (text == "CMDCOLOR 40")
//            {
//                system("start color 40");
//            }
//            if (text == "CMDCOLOR 41")
//            {
//                system("start color 41");
//            }
//            if (text == "CMDCOLOR 42")
//            {
//                system("start color 42");
//            }
//            if (text == "CMDCOLOR 43")
//            {
//                system("start color 43");
//            }
//            if (text == "CMDCOLOR 44")
//            {
//                system("start color 44");
//            }
//            if (text == "CMDCOLOR 45")
//            {
//                system("start color 45");
//            }
//            if (text == "CMDCOLOR 46")
//            {
//                system("start color 46");
//            }
//            if (text == "CMDCOLOR 47")
//            {
//                system("start color 47");
//            }
//            if (text == "CMDCOLOR 48")
//            {
//                system("start color 48");
//            }
//            if (text == "CMDCOLOR 49")
//            {
//                system("start color 49");
//            }
//            if (text == "CMDCOLOR 4A")
//            {
//                system("start color 4A");
//            }
//            if (text == "CMDCOLOR 4B")
//            {
//                system("start color 4B");
//            }
//            if (text == "CMDCOLOR 4C")
//            {
//                system("start color 4C");
//            }
//            if (text == "CMDCOLOR 0D")
//            {
//                system("start color 0D");
//            }
//            if (text == "CMDCOLOR 0E")
//            {
//                system("start color 0E");
//            }
//            if (text == "CMDCOLOR 0F")
//            {
//                system("start color 0F");
//            }
//        }
//        
//        
//        
//        
//        
//        break;
//    }
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
//    op.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
//    RegisterClass(&op);
//
//
//    CreateWindowA(op.lpszClassName, "Title", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 800, 600, NULL, NULL, op.hInstance, NULL);
//    MSG msg;
//    while (GetMessage(&msg, NULL, 0, 0)) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//
//    }
//
//}
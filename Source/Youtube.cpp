//#include <windows.h>
//#include <cstring>
//#include <cstdlib>                   //Всё нормально работает
//// только у меня emulate.cpp нет     //А если я его просто открою, то ты увидишь?
//// подожди 3 сек и открой
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
//HWND MENUMENUMENU;
//HWND MENUMENUMENU1;
//HWND MENUMENUMENU2;
//HWND MENUMENUMENU3;
//HSTREAM YOUTUBER;
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
//HDC hdc;
//PAINTSTRUCT ps;
//HBRUSH hBrush = CreateSolidBrush(RGB(76,0 ,153));
//HWND hTrack;
////теперь нет звука =)
//
//
//static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//    switch (uMsg) {
//
//    case WM_CREATE: {
//
//
//        int a = 140;
//
//        HMENU hMenubar = CreateMenu();
//
//        HMENU hAbout = CreateMenu();
//        HMENU hColorYT = CreateMenu();
//
//        
//
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "Справка");
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hColorYT, "Сменить цвет");
//
//
//
//        CreateWindow(TEXT("BUTTON"), TEXT("Скачать ролик с Youtube"), WS_VISIBLE | WS_CHILD, 45 + a, 130, 240, 25, hWnd, (HMENU)MENUMAKER, NULL, NULL);
//
//
//        BASS_Init(-1, 44100, 0, 0, NULL);
//
//
//        SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//
//
//        AppendMenu(hAbout, MF_STRING, STRANNIK, "О программе");
//        AppendMenu(hColorYT, MF_STRING, COLORYT, "Мой цвет");
//
//
//
//
//
//        SetMenu(hWnd, hMenubar);
//
//
//        BASS_Start();     //Вот таким образом я исправил баг. Ну типа теперь музыка играет только после нажатия на первую кнопку. При этом смена цвета работает исправно
//        // лучше так чем никак    //Да, но не понятно, почему например в плеере такого бага нет? Наверное потому, что там музыка с самого начала не играет. Ну тогда почему в списке эмуляторов бага нет? Надо код emulate.cpp посмотреть.
//        // только вот я не смогу открыть файл
//        // я перезайду и пожалуста не открывай файлы так быстро 
//        YOUTUBER = BASS_StreamCreateFile(FALSE, "MusicPlayer\\Your\\Youtube.mp3", 0, 0, 0);
//        BASS_ChannelPlay(YOUTUBER, false);// Вот теперь все ИДЕАЛЬНО работает. А что было то?
//        // воспроизведение было в начале     Вот но что.... Понятно. Ну теперь все нормально работает.
//        // а когда релиз будет???  Кхм а теперь баг вернулся Типа звук включается по нажатию на первую кнопку. Но это щас исправить можно удалением одной строчки. Щас
//
//        break;
//    }
//    case WM_COMMAND:
//            //теперь смена цвета не работает, а звук дублируется....
//    {
//
//        int len90;                                                                                                              
//        TCHAR video[1200];
//        len90 = GetWindowText(MENUMENUMENU, video, 1200);
//        if (LOWORD(wParam) == MENUMAKER)
//        {
//            int a = 140;   //Вот, теперь больше багов тут нет. теперь смотри. Надо добавить микшер громкости во все подпрограммы, где используется звук. =) Это Youtube.cpp Emulate.cpp, quest.cpp.  Но квест потом надо еще будет допиливать. Когда допилим, то думаю, что это можно уже как апдейт выпустить.
//            // а меня в авторы добавишь???    //Я ж сказал, что добавлю, пока что как помощника, ибо всё равно тут пока больше моего кода, но если ты сделаешь отдельную подпрограммку, какую-нибудь, то считай сразу будешь разработчиком этой программы =).
//            //ок
//            MENUMENUMENU = CreateWindow(TEXT("EDIT"), TEXT("Ссылка на ролик на Youtube"), WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL | ES_AUTOVSCROLL | ES_MULTILINE, 10, 500, 605, 70, hWnd, (HMENU)WRITING, NULL, 0);
//            CreateWindow(TEXT("BUTTON"), TEXT("Скачать"), WS_VISIBLE | WS_CHILD, 120 + a, 360, 100, 25, hWnd, (HMENU)MAKEMAKE, NULL, NULL);
//            ShowWindow(GetDlgItem(hWnd, MENUMAKER), SW_HIDE);
//            CreateWindow(TEXT("STATIC"), TEXT("                Чтобы скачать ролик надо:\n\n1) Вставить ссылку на ролик в поле для ввода.\n2) Нажать кнопку <<Скачать>>.\n\nP.S Радоваться, что вы не шашнахме =)\n\nP.S.S Беречь свои тонкие кости =)"), WS_VISIBLE | WS_CHILD, 150, 90, 325, 140, hWnd, (HMENU)NULL, NULL, NULL);
//
//            hTrack = CreateWindow(TRACKBAR_CLASS, "SOUND", WS_CHILD | TBS_AUTOTICKS | TBSTYLE_TOOLTIPS | LVS_EX_TRANSPARENTBKGND | WS_VISIBLE, 150, 250, 320, 30, hWnd, (HMENU)LENMUSIC, NULL, NULL);
//            CreateWindow(TEXT("STATIC"), TEXT("Громкость"), WS_VISIBLE | WS_CHILD, 130 + a, 290, 70, 18, hWnd, (HMENU)MAKEMAKE, NULL, NULL);
//                                            //PERFECT
//                                            // PROFIT     Теперь такой же микшер в Emulate.cpp Только надо начальное значение микшера поставить скажем на 20
//        
//        }                              //ЗАРАБОТАЛ СРАЗУ, Ток коорды надо другие поставить =)
//        // Код универсален :)   ща коорды вычислю  По иксу будет также как и в Createwindowstext(static)
//
//
//        if (LOWORD(wParam) == STRANNIK)
//        {
//            MessageBoxA(hWnd, "Это программа для скачивания роликов с Youtube.\nСпасибо Daniel Myslivets за предоставленную консольную программку, для которой я просто сделал этот GUI", "Справка", MB_ICONASTERISK);
//
//        }
//        if (LOWORD(wParam) == MAKEMAKE)
//        {
//            
//            ofstream Proga;
//            string videos = video;
//            Proga.open("MusicPlayer\\Youtube\\bat.bat");
//            Proga << "MusicPlayer\\Youtube\\yt-dlp.exe —format mp4 " << videos << endl;
//            Proga << "echo Your video has been downloaded, and stay in MusicPlayer's directory" << endl;
//            Proga.close();
//            system("MusicPlayer\\Youtube\\bat.bat");
//            system("del MusicPlayer\\Youtube\\bat.bat");
//            MessageBoxA(hWnd, "Ваше видео было скачано!\nСейчас оно лежит в папке с плеером", "Успех!", MB_ICONASTERISK);
//        }
//        if (LOWORD(wParam) == COLORYT)
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
//                InvalidateRect(hWnd, NULL, FALSE);
//            }                   //Почему, смена цвета сбивает проигрываение композиции? В других прогах такого бага нет.ага,а теперь компоиция дублируется.....
//            
//             //Почему-то мелодия запускается сразу, как только я выбираю цвет....     //Теперь цвет меняется, но звук при этом дублируется.
//        }
//        break;
//
//        case WM_HSCROLL: {
//            if (hTrack == (HWND)lParam)
//            {
//                BASS_ChannelSetAttribute(YOUTUBER, BASS_ATTRIB_VOL, SendMessage(hTrack, TBM_GETPOS, 80, 100));
//            }
//        } break;
//
//        case WM_PAINT: {
//            hdc = BeginPaint(hWnd, &ps);
//            FillRect(hdc, &ps.rcPaint, hBrush);
//            EndPaint(hWnd, &ps);
//        } break;
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
//}
//int WINAPI main()
//{
//    WNDCLASS op;
//    ZeroMemory(&op, sizeof(WNDCLASS));
//    op.lpfnWndProc = wnd_proc;
//    op.hInstance = GetModuleHandle(NULL);
//    op.lpszClassName = "test32cls";
//    op.hCursor = LoadCursor(NULL, IDC_ARROW);
//    //op.hbrBackground = CreateSolidBrush(RGB(76,0 ,153));
//    RegisterClass(&op);
//
//
//    CreateWindowA(op.lpszClassName, "Загрузчик видео с ютуба ver 1.1", WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX| WS_VISIBLE, 100, 100, 640, 640, NULL, NULL, op.hInstance, NULL);
//    MSG msg;
//    while (GetMessage(&msg, NULL, 0, 0)) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//
//    }
//
//}
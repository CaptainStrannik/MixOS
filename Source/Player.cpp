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
#include "Names.h"
#include "bass.h"



#pragma comment(linker,"/manifestdependency:\"type='win32' \
                        name='Microsoft.Windows.Common-Controls' \
                        version='6.0.0.0' processorArchitecture='*'\
 publicKeyToken='6595b64144ccf1df' language='*'\"")

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "bass")

using namespace std;
HWND eDit;
HWND eMp3;
HWND okno;
HWND ERRORs;
char str1[1024];

HSTREAM stro;
HSTREAM MORNING;
HSTREAM UFO;
HSTREAM SAMPLEADV;
HSTREAM DNO;

HSTREAM EYES;
HSTREAM LONELY;
HSTREAM GIRL;


HDC hdc; //создаём контекст устройства
PAINTSTRUCT ps; //создаём экземпляр структуры графического вывода
LOGFONT lf;
RECT r;
HBRUSH hBrush;
HPEN hPen;



static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {


    case WM_CREATE: {
        
        SetWindowText(hWnd, ("MusicPlayer Beta 1.8 © StrannikCorp"));
        CreateWindow(TEXT("STATIC"), TEXT("Желаете запустить?"), WS_VISIBLE | WS_CHILD, 550, 20, 140, 15, hWnd, (HMENU)NULL, NULL, NULL);
        CreateWindow(TEXT("BUTTON"), TEXT("ДА!"), WS_VISIBLE | WS_CHILD, 400, 200, 500, 300, hWnd, (HMENU)ID_BUTTON, NULL, NULL);


    }

        break;
    case WM_COMMAND: {
        BASS_Init(-1, 44100, 0, 0, NULL);

        if (LOWORD(wParam) == ID_BUTTON)
        {
           




          
            HMENU hMenubar = CreateMenu();
            HMENU hFile = CreateMenu();
            HMENU hAbout = CreateMenu();
            HMENU hCreator = CreateMenu();
            HMENU hHelp = CreateMenu();
            HMENU hUtils = CreateMenu();
            HMENU hInstall = CreateMenu();
            
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hFile, "Файл");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "Справка");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hCreator, "О разработчике");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hHelp, "Шашнахме");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hUtils, "Системные утилиты");
            AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hInstall, "Установка полезного софта");


            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
            
            AppendMenu(hFile, MF_STRING, IU_STR, "Выход");
            AppendMenu(hFile, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hFile, MF_STRING, SOURCE, "Исходный код");
            
            AppendMenu(hAbout, MF_STRING, STRANNIK, "О программе");
            

            AppendMenu(hCreator, MF_STRING, WOZRAST, "Возраст");
            AppendMenu(hCreator, MF_SEPARATOR, NULL, NULL);
            AppendMenu(hCreator, MF_STRING, WEIGHT, "Вес");
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
            AppendMenu(hHelp, MF_STRING, VIDEO, "Открыть видеоплеер (бета)");


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

            SetMenu(hWnd, hMenubar);
            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
            
           
            CreateWindow(TEXT("STATIC"), TEXT("MusicPlayer Version Beta 1.8, copyright ©StrannikCorp. All rights reserved"), WS_VISIBLE | WS_CHILD, 400, 20, 490, 25, hWnd, (HMENU)NULL, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("*************************************Привет, этот плеер проигрывает музыку в любых форматах*********************************************"), WS_VISIBLE | WS_CHILD, 200, 40, 899, 25, hWnd, (HMENU)NULL, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("Но расширение надо указывать обязательно!!!"), WS_VISIBLE | WS_CHILD, 480, 60, 317, 20, hWnd, (HMENU)NULL, NULL, NULL);
            CreateWindow(TEXT("STATIC"), TEXT("Тут уже имеется пара композиций"), WS_VISIBLE | WS_CHILD, 520, 100, 230, 25, hWnd, (HMENU)NULL, NULL, NULL);
            string Priet = "C:\\Windows\\media\\Windows Logon.wav";
            PlaySoundA(Priet.c_str(), NULL, SND_ASYNC);
           
            CreateWindow(TEXT("BUTTON"), TEXT("Headless Nick - Morning "), WS_VISIBLE | WS_CHILD, 150, 150, 300, 70, hWnd, (HMENU)DEVUSHKA, NULL, NULL);    
            CreateWindow(TEXT("BUTTON"), TEXT("Headless Nick - UFO "), WS_VISIBLE | WS_CHILD, 460, 150, 300, 70, hWnd, (HMENU)LETO, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Headless Nick - Sample Adventures "), WS_VISIBLE | WS_CHILD, 770, 150, 300, 70, hWnd, (HMENU)SHAG, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Deteez - Above the Sky"), WS_VISIBLE | WS_CHILD, 150, 230, 300, 70, hWnd, (HMENU)SLOVO, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Violet S - Lonely "), WS_VISIBLE | WS_CHILD, 460, 230, 300, 70, hWnd, (HMENU)CIGARET, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Deteez - Waxie "), WS_VISIBLE | WS_CHILD, 770, 230, 300, 70, hWnd, (HMENU)PEREMEN, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Остановить музыку "), WS_VISIBLE | WS_CHILD, 460, 310, 300, 70, hWnd, (HMENU)STOPS, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Открыть свой файл"), WS_VISIBLE | WS_CHILD, 150, 500, 300, 70, hWnd, (HMENU)FILEY2, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Поиск "), WS_VISIBLE | WS_CHILD, 770, 500, 300, 70, hWnd, (HMENU)SEARCH, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Продолжить"), WS_VISIBLE | WS_CHILD, 620, 500, 140, 70, hWnd, (HMENU)PAUSE2, NULL, NULL);
            CreateWindow(TEXT("BUTTON"), TEXT("Пауза"), WS_VISIBLE | WS_CHILD, 460, 500, 140, 70, hWnd, (HMENU)PAUSE1, NULL, NULL);
            //CreateWindow(TEXT("BUTTON"), TEXT("Очистить RAM"), WS_VISIBLE | WS_CHILD, 550, 600, 110, 20, hWnd, (HMENU)RAMRAM, NULL, NULL);
            

           eMp3 = CreateWindow(TEXT("Edit"), TEXT("Путь до вашей музыки, в любом формате =) (С расширением) Например:  MusicPlayer\\Violet S\\Lonely.mp3"), WS_EX_CLIENTEDGE | WS_BORDER | WS_CHILD | WS_VISIBLE, 40, 430, 1200, 20, hWnd, (HMENU)YOUMUSIC, NULL, 0);

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
        if (LOWORD(wParam) == DEVUSHKA)
        {
            BASS_Stop();

            BASS_Start();

            CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - Morning"), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)NULL, NULL, NULL);
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
            CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - UFO"), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)NULL, NULL, NULL);
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
            CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Headless Nick - Sample Adventures.mp3"), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)NULL, NULL, NULL);
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
            CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Deteez - Above the Sky.mp3"), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)NULL, NULL, NULL);
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
            CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Violet S - Lonely.mp3"), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)NULL, NULL, NULL);
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
            CreateWindow(TEXT("STATIC"), TEXT("Проигрывается Deteez - Waxie.mp3"), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)NULL, NULL, NULL);
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
            MessageBoxA(hWnd, "А зачем вам знать? Вес штука сложная", "Вес",MB_ICONINFORMATION);
        }
        if (LOWORD(wParam) == WOZRAST)
        {
            MessageBoxA(hWnd, "Возраст? Так прям интересно? Ну переведите 10100 в десятичную систему\nА вообще, если вы шашнахме, то знайте, др у меня в хеллоуин", "Возраст 20", MB_ICONINFORMATION);
        }
        if (LOWORD(wParam) == STRANNIK)
        {
            MessageBoxA(hWnd, "Добро пожаловать в музыкальный плеер версии BETA 1.8. Который нужен, чтобы проигрывать музыку удобным образом. Хотя скорее для того, чтобы автор набрался опыта. Эта версия поддерживает большинство современных форматов музыки!! Каких именно? Да я сам хз =) Тестируйте, только не забывайте указывать расширение. =)", "О программе MusicPlayer Beta 1.8", MB_ICONINFORMATION);
        }
        if (LOWORD(wParam) == HELP)
        {
            MessageBoxA(hWnd, "Если Вы шашнахме в моем плеере, то я вам щас все расскажу. Короче, есть кнопки, которые проигрывают музыку. Эти кнопки проигрывают конкретные песни моих друзей. Что написано, то и сыграется. Чтобы сыграть свою мелодию, просто впишите путь к ней с ее названием и нажмите кнопку <<Открыть свой файл>>. Если вдруг вы не знаете путь до музыки или если у вас толстая кость, просто нажмите кнопку <<Поиск>>. Если вы до сих пор хз как этим пользоваться, то че вы тут вообще делаете?","Помощь", MB_OK);
            MessageBoxA(hWnd, "Также тут есть простой доступ к системным утилитам, попробуйте =)","Помощь", MB_OK);
            MessageBoxA(hWnd, "И это, я вижу, у вас не толстая кость. Раз так, отожмитесь 10 раз. Чтобы проверить, толстая кость у вас или нет, я запущу шашнахме квест, который вы могли и без меня пройти =)", "Помощь", MB_ICONINFORMATION);
            system("start MusicPlayer\\Quest\\quest.exe");
        }

        if (LOWORD(wParam) == ABOUTDEV)
        {
            MessageBoxA(hWnd, "      Здравствуйте, это Strannik. И этот плеер нужен для того, для чего он нужен =). Я же - Создатель этого плеера. Мое имя Вам ни о чем не скажет. Но я расскажу вам историю о том, с чего начинался этот проект.                                                   Сидел я как-то вечером, за компом, и хотел уже наконец сделать что-то хорошее на с++, полезное. До этого, опыта в написании программ языке С++ у меня было мало. Конвертер валют и пара консольных программ. В итоге я решил: <<Почему бы не сделать музыкальный плеер?>>. Написание первой версии кода было ужасным времяпрепровождением. Я писал плохо, но со временем получалось лучше. И ура, я сделал первую версию плеера. Alpha 1.0. Она проигрывала только wav файлы и только конкретные 8 композиций, но начало уже было положено. На следующий день я выпустил версию beta 1.1, которая проигрывала около 20 wav композиций. Знания по функции PlaySound я отточил максимально тогда. Потом друзья мне сказали, что было бы неплохо добавить возможность проигрывать любые wav файлы. Так и сразу появилась beta 1.3. Как понимаете, тут у меня такая же история, как у microsoft =). Плеер уже умел проигрывать любую wav музыку, но это все было не то. Поэтому в версии Beta 1.4, которая вышла буквально позавчера (30.06.2021), Появился графический интерфейс, который работал даже на linux, но через wine. Самое главное чего мне не хватало это поддержки mp3. И я покопался в библиотеке bass, которую, к слову, используют все кому не лень, начиная с 90х годов 20 века. Также, чтобы было не так грустно, и, чтобы обновление было более глобальным, я добавил в плеер удобное меню, для запуска системных утилит. Вы спросите зачем? Ну так они ничего не жрут, занимают пару строк кода в программе. И самое главное, реально удобно! Попробуйте сами!                                                                                                           Сейчас (03.07.2021) Это версия beta 1.6, и в ней добавилась поддержка других форматов, при этом, для вашего удобства две строки ввода заменились на одну! Но, не без жертв, теперь музыку снова надо будет указывать с расширением. Но тут мои полномочия всё.                                           Всему виной библиотека bass.dll, которой надо скормить путь к мелодии и ее название с расширением. Пока не знаю, что с этим делать. Думаю, что до версии beta 1.8 уже точно додумаю =).", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "Сейчас 22.10.2021. Прошло блин уже 3 месяца с создания версии 1.6. Много чего произошло у меня в жизни.\nЯ набрался опыта. И в целом, добавил просто ТОННУ возможностей в этот плеер.\nВ частности это Пианино, Терминал с пасхалками и командами. Практически полностью доделанный Шашнахме квест.\nНовые кнопки в стиле Windows 7.\nКонвертер валют. В общем, идем в ногу со временем\nТолько часики отстали лет на 15 =). ", "О процессе разработки", MB_ICONINFORMATION);
            MessageBoxA(hWnd, "Версия 1.8. Выпущена 10.02.2022.\nДобавилось много всего интересного.\nВпервые я исправил баг с памятью.\nТеперь плеер почти ничего не ест.\nДобавил сюда кучу всего интересного, все пасхалки найдете сами. Их более 30 штук. =)", "О процессе разработки", MB_ICONINFORMATION);
        }
          if (LOWORD(wParam) == IU_STR)
        {
            exit(1);
        }
          if (LOWORD(wParam) == SOURCE)
        {
            MessageBoxA(hWnd,"Исходники лежат на гитхабе. Ссылка в readme.\nНо для вас исходники лежат в 1 папке" ,"Исходный код",MB_OK );
            system("start explorer SourceCode");

        }
          if (LOWORD(wParam) == PAUSE1)
        {
            CreateWindow(TEXT("STATIC"), TEXT("Пауза"), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)NULL, NULL, NULL);
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

            //пауза
        }
          if (LOWORD(wParam) == PAUSE2)
        {
            BASS_ChannelPlay(stro,false); //плей
            CreateWindow(TEXT("STATIC"), TEXT("Проигрывается ваша музыка)"), WS_VISIBLE | WS_CHILD, 10, 600, 300, 50, hWnd, (HMENU)NULL, NULL, NULL);
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
        }
          if (LOWORD(wParam) == FILEY2)
          {

          


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

              stro = BASS_StreamCreateFile(FALSE,StrB,0,0,0);
              CreateWindow(TEXT("STATIC"), TEXT("Проигрывается ваша музыка) "), WS_VISIBLE | WS_CHILD, 10, 600, 300, 25, hWnd, (HMENU)NULL, NULL, NULL);
              BASS_ChannelPlay(stro, false); // проигрывание файла
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
          if (LOWORD(wParam) == REGEDIT)
          {
              system("start regedit.exe");
          }
          if (LOWORD(wParam) == SEARCH)
          {
              system("@echo off");
              system("explorer MusicPlayer");     
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
        break;
        //Цикл обработки сообщений

                 
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
    WNDCLASS wc;
    ZeroMemory(&wc, sizeof(WNDCLASS));
    wc.lpfnWndProc = wnd_proc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = "test32cls";
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = CreateSolidBrush(RGB(0,139,139));



    RegisterClass(&wc);
    
    
    CreateWindowA(wc.lpszClassName, "Title", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 1280, 720, NULL, NULL, wc.hInstance, NULL);
    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
        

    }

}
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
//HSTREAM QUEST_THEME;
//HSTREAM KILL;
//HSTREAM LADAV;
//HSTREAM SVOBODA;
//HSTREAM SCREAM;
//HSTREAM REMIX;
//
//
//
//
//static LRESULT CALLBACK wnd_proc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
//    switch (uMsg) {
//
//    case WM_CREATE: {
//        
//        HMENU hMenubar = CreateMenu();
//        HMENU hAbout = CreateMenu();
//        AppendMenu(hMenubar, MF_POPUP, (UINT_PTR)hAbout, "Ñןנאגךא");
//        SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//        AppendMenu(hAbout, MF_STRING, STRANNIK, "Î ןנמדנאללו");
//        AppendMenu(hAbout, MF_STRING, STRANNI, "Øארםאץלו");
//        SetMenu(hWnd, hMenubar);
//        BASS_Init(-1, 44100, 0, 0, NULL);
//        SetWindowText(hWnd, ("Øארםאץלו ךגוסע"));
//        CreateWindow(TEXT("BUTTON"), TEXT("Íאקאעü טדנף"), WS_VISIBLE | WS_CHILD, 200, 100, 250, 150, hWnd, (HMENU)ID_BUTTON, NULL, NULL);
//        break;
//    }
//    case WM_COMMAND: {
//        if (LOWORD(wParam) == STRANNIK)
//        {
//            MessageBoxA(hWnd, "Ýעמע ךגוסע ÿגכÿועסÿ גסודמ כטרü במכüםמי פאםעאחטוי אגעמנא. Íו גמסןנטםטלאיעו גסונüוח. Ó גאס זו עמכסעאÿ ךמסעü?", "Î ןנמדנאללו", MB_OK);
//        }
//        if (LOWORD(wParam) == STRANNI)
//        {
//            HSTREAM SCREAM = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\skrimer.mp3", 0, 0, 0);
//            BASS_ChannelPlay(SCREAM, false);
//            HSTREAM REMIX = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\REMIX.mp3", 0, 0, 0);
//            BASS_ChannelPlay(REMIX, false);
//            MessageBoxA(hWnd, "ØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅ", "ØÀØÍÀÕÌÅ", MB_ICONERROR);
//            MessageBoxA(hWnd, "ØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅ", "ØÀØÍÀÕÌÅ", MB_ICONERROR);
//            MessageBoxA(hWnd, "ØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅ", "ØÀØÍÀÕÌÅ", MB_ICONERROR);
//            MessageBoxA(hWnd, "ØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅ", "ØÀØÍÀÕÌÅ", MB_ICONERROR);
//            MessageBoxA(hWnd, "ØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅ", "ØÀØÍÀÕÌÅ", MB_ICONERROR);
//            MessageBoxA(hWnd, "ØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅ", "ØÀØÍÀÕÌÅ", MB_ICONERROR);
//            MessageBoxA(hWnd, "ØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅ", "ØÀØÍÀÕÌÅ", MB_ICONERROR);
//            MessageBoxA(hWnd, "ØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅ", "ØÀØÍÀÕÌÅ", MB_ICONERROR);
//            MessageBoxA(hWnd, "ØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅ", "ØÀØÍÀÕÌÅ", MB_ICONERROR);
//            MessageBoxA(hWnd, "ØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅ", "ØÀØÍÀÕÌÅ", MB_ICONERROR);
//            MessageBoxA(hWnd, "ØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅ", "ØÀØÍÀÕÌÅ", MB_ICONERROR);
//            MessageBoxA(hWnd, "ØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅ", "ØÀØÍÀÕÌÅ", MB_ICONERROR);
//            MessageBoxA(hWnd, "ØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅØÀØÍÀÕÌÅ", "ØÀØÍÀÕÌÅ", MB_ICONERROR);
//            BASS_Stop();
//            BASS_Start();
//        }
//        if (LOWORD(wParam) == ID_BUTTON)
//        {
//            
//            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//            QUEST_THEME = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\quest.mp3", 0, 0, 0);
//            BASS_Stop();
//            BASS_Start();
//            BASS_ChannelPlay(QUEST_THEME, false);
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            CreateWindow(TEXT("STATIC"), TEXT(""), WS_VISIBLE | WS_CHILD, 225, 10, 450, 12, hWnd, (HMENU)NULL, NULL, NULL);
//            CreateWindow(TEXT("STATIC"), TEXT("Âû םאץמהטעוסü ג עולםמל ןונוףכךו, גןונוהט מע גאס סגועטע סגוע,סחאהט עüלא, סןנאגא מע גאס כוסעםטצא, גוהףשאÿ םאגונץ.                                                     Êףהא ןמיהול?      "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 50, hWnd, (HMENU)NULL, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Âןונוה "), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)FIRST, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Íאחאה "), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)SECOND, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ïמהםÿעüסÿ ןמ כוסעםטצו "), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)THIRD, NULL, NULL);
//        }
//        if (LOWORD(wParam) == FIRST)
//        {
//            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
//
//            CreateWindow(TEXT("STATIC"), TEXT(""), WS_VISIBLE | WS_CHILD, 225, 10, 450, 12, hWnd, (HMENU)NULL, NULL, NULL);
//            CreateWindow(TEXT("STATIC"), TEXT("Ïנמיהÿ 32 ראדא גû ןמןאכט ג ךמלםאעף, דהו סעמÿע ענט לארטםû: BMW X5, LADA VESTA, Toyota Camri. È גסו מםט מעךנûעû, Çאבטנאי םו ץמקף!    "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//
//
//            CreateWindow(TEXT("BUTTON"), TEXT("Ñוסעü ג Toyota"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)FIRST2, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ñוסעü ג BMW"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)SECOND2, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ñוסעü ג LADA "), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)THIRD2, NULL, NULL);
//
//
//        }
//        if (LOWORD(wParam) == SECOND)
//        {
//            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
//            CreateWindow(TEXT("STATIC"), TEXT(""), WS_VISIBLE | WS_CHILD, 225, 10, 450, 12, hWnd, (HMENU)NULL, NULL, NULL);
//            CreateWindow(TEXT("STATIC"), TEXT("Ê סמזאכוםט‏ גû ףןאכט ג ןנמןאסעü, ס זטחםü‏ ף גאס גסו רארםאץלו... Èדנא מךמםקוםא =( Ìמנאכü: Íטךמדהא םו ץמהטעו םאחאה. Äאזו ןמ זטחםט הגטדאיעוסü עמכüךמ גןונוה. È ןמכףקטעסÿ גסו, קעמ חאץמעטעו =)"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//            BASS_ChannelStop(QUEST_THEME);
//            BASS_ChannelStop(LADAV);
//            HSTREAM KILL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\kill.mp3", 0, 0, 0);
//            BASS_ChannelPlay(KILL, false);
//
//        }
//        if (LOWORD(wParam) == THIRD)
//        {
//            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
//
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
//
//            CreateWindow(TEXT("STATIC"), TEXT(""), WS_VISIBLE | WS_CHILD, 225, 10, 450, 12, hWnd, (HMENU)NULL, NULL, NULL);
//            CreateWindow(TEXT("STATIC"), TEXT("Ïמהםÿגרטסü ןמ כוסעםטצו גû ןמהםÿכטסü םא ךנûרף חהאםטÿ. Íא ךמעמנמי סעמטע גונעמכוע, לארטםא ט גוכמסטןוה. Êףהא סÿהול?"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//
//
//            CreateWindow(TEXT("BUTTON"), TEXT("Ñוסעü ג גוכמסטןוה"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)VELOSIPED, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ñוסעü ג לארטםף"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)MASHINA, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ñוסעü ג גונעמכוע "), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)HELICOPTER, NULL, NULL);
//        }
//
//        if (LOWORD(wParam) == VELOSIPED)
//        {
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
//            CreateWindow(TEXT("STATIC"), TEXT("                Ñוג םא גוכמסטןוה גû ףגטהוכט ענאלןכטם"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ïמוץאעü םא גוכמסטןוהו"), WS_VISIBLE | WS_CHILD, 220, 75, 185, 35, hWnd, (HMENU)VELOSIPED1, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ñכוחעü ס גוכמסטןוהא"), WS_VISIBLE | WS_CHILD, 220, 115, 185, 35, hWnd, (HMENU)VELOSIPED2, NULL, NULL);
//        }
//
//        if (LOWORD(wParam) == VELOSIPED1)
//        {
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
//            CreateWindow(TEXT("STATIC"), TEXT("Âû קעמ? Ñמגסול רארםאץלו? Ïמםÿעםמ ןמקולף. Âû ןונוסלמענוכט Ãמככטגףהסךטו פטכüלû. Âû סונעוחםמ הףלאכט, קעמ ןנמוץאג םא גוכטךו ט סןנûדםףג ס ךנûרט גû גûזטגועו? Ìהא.... Ìמנאכü: <<Óקטעו םאףךף, קעמבû ג זטחםט םו ןמןאהאעü ג ןמהמבםûו סטעףאצטט, גוהü זטחםü ‎עמ גאל םו טדנא!>>"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//            BASS_ChannelStop(QUEST_THEME);
//            BASS_ChannelStop(LADAV);
//            HSTREAM KILL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\kill.mp3", 0, 0, 0);
//            BASS_ChannelPlay(KILL, false);
//
//        }
//        if (LOWORD(wParam) == VELOSIPED2)
//        {
//
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_SHOW);
//            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_SHOW);
//            CreateWindow(TEXT("STATIC"), TEXT(""), WS_VISIBLE | WS_CHILD, 225, 10, 450, 12, hWnd, (HMENU)NULL, NULL, NULL);
//            CreateWindow(TEXT("STATIC"), TEXT("Âû גסו זו נורטכט סכוחעü ס גוכמסטןוהא ט סוסעü ג הנףדמי ענאםסןמנע"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ñוסעü ג גוכמסטןוה"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)VELOSIPED3, NULL, NULL);
//
//
// 
//
//        }
//
//        if (LOWORD(wParam) == VELOSIPED3)
//        {
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED3), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED3), SW_HIDE);
//            CreateWindow(TEXT("STATIC"), TEXT(""), WS_VISIBLE | WS_CHILD, 225, 10, 450, 12, hWnd, (HMENU)NULL, NULL, NULL);
//            CreateWindow(TEXT("STATIC"), TEXT("Äוכאÿ םוכמדטקםûו הויסעגטÿ ג טדנו, גû האכט ןמםÿעü נאחנאבמעקטךף, קעמ גû רארםאץלו, ןמ‎עמלף מם ףהאכטכ גוכמסטןוה, קעמבû גû םו הוכאכט עףןûו הויסעגטÿ"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//
//        }
//        if (LOWORD(wParam) == MASHINA)
//        {
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED3), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
//            CreateWindow(TEXT("STATIC"), TEXT("Ýעמ מךאחאכאסü לארטםא גנולוםט. Â םוי ךףקא ךםמןמקוך ט צטפונבכאעמג. À עאךזו ןמעמךמגûי םאךמןטעוכü =). Â מבשול, ג ךאךמו גנולÿ ןמכועטל?"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Â האכוךמו בףהףשוו"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)FUTURE, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Â האכוךמו ןנמרכמו"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)BACK, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ïמםאזטלאעü ךםמןךט"), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)SUDBA, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ïמכועאעü ןמ םמקםמלף םובף"), WS_VISIBLE | WS_CHILD, 220, 195, 185, 35, hWnd, (HMENU)FLY, NULL, NULL);
//        }
//
//        if (LOWORD(wParam) == FUTURE)
//        {
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED3), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FUTURE), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, BACK), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SUDBA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FLY), SW_HIDE);
//            CreateWindow(TEXT("STATIC"), TEXT("Âû ןמןאכט ג האכוךמו בףהףשוו, Ãהו Çולכÿ בûכא קטסעאÿ, גסו סכוהטכט חא ןנטנמהמי. È גסו בûכמ ץמנמרמ. Ìמנאכü:<<Ñכוהטעו חא ןנטנמהמי, םו בףהüעו רארםאץלו>> "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//            BASS_ChannelStop(QUEST_THEME);
//            HSTREAM MODEL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\Model.mp3", 0, 0, 0);
//            BASS_ChannelPlay(MODEL, false);
//
//        }
//        if (LOWORD(wParam) == BACK)
//        {
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FUTURE), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED3), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, BACK), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SUDBA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FLY), SW_HIDE);
//            CreateWindow(TEXT("STATIC"), TEXT("Âû ןמןאכט ג האכוךמו ןנמרכמו ט ןמןאכט ג כוס. Â ךמעמנמל קונוח 10 לטםףע גאס ףבטכ הטםמחאגנ. Èדנא מךמםקוםא. Ìמנאכü: <<Íו ץמהטעו הועט ג כוס מהםט. Òול במכוו ג המטסעמנטקוסךטי>>. "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//            BASS_ChannelStop(QUEST_THEME);
//            BASS_ChannelStop(LADAV);
//            HSTREAM KILL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\kill.mp3", 0, 0, 0);
//            BASS_ChannelPlay(KILL, false);
//
//        }
//        if (LOWORD(wParam) == SUDBA)
//        {
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED3), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FUTURE), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, BACK), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SUDBA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FLY), SW_HIDE);
//            CreateWindow(TEXT("STATIC"), TEXT("Ïמעûךאג ןאנף ךםמןמך גû סכףקאיםמ םאזאכט םא ךםמןךף הואךעטגאצטט לארטםû, ךמעמנאÿ ןנמסעמ אךעטגטנמגאכא גחנûגקאעךף. È קונוח 5 סוךףםה גû גחמנגאכטסü. Ìמנאכü: <<Íו טדנאיעו הועט םוחםאךמלמי גאל עוץםטךמי. ×טעאיעו המךףלוםעאצט‏>>."), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//            BASS_ChannelStop(QUEST_THEME);
//            BASS_ChannelStop(LADAV);
//            HSTREAM KILL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\kill.mp3", 0, 0, 0);
//            BASS_ChannelPlay(KILL, false);
//        }
//        if (LOWORD(wParam) == FLY)
//        {
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED3), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FUTURE), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, BACK), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SUDBA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FLY), SW_HIDE);
//            CreateWindow(TEXT("STATIC"), TEXT("Âû גךכ‏קטכט ענוך Kavinsky - Testarossa Autodrive ט ףלקאכטסü גןונוה =). Ìמנאכü..  À ךאךאÿ עףע למזוע בûעü למנאכü? Âû סכמלאכט סטסעולף!"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//            BASS_ChannelStop(QUEST_THEME);
//            HSTREAM KAVUL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\Testarossa Autodrive.mp3", 0, 0, 0);
//            BASS_ChannelPlay(KAVUL, false);
//
//        }
//        if (LOWORD(wParam) == HELICOPTER)
//        {
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED3), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
//            CreateWindow(TEXT("STATIC"), TEXT("Çא גס‏ זטחםü גû כועאכט םא גונעמכועו גסודמ 1 נאח, ט עמ, ‎עמ בûכמ ג טדנו GTA VICE CITY. Íמ םטקודמ, סמ גנולוםול גû סלמדכט חאגוסעט. Êףהא ןמכועטל?"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ê נמהטעוכÿל םא האקף"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)PARENTS, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Âנוחאעüסÿ ג Êנולכü"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)CREMLIN, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Â ÑØÀ"), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)USA, NULL, NULL);
//
//        }
//        if (LOWORD(wParam) == PARENTS)
//        {
//            ShowWindow(GetDlgItem(hWnd, USA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, PARENTS), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, CREMLIN), SW_HIDE);
//
//            CreateWindow(TEXT("STATIC"), TEXT("Óךאזטעו ןמכ"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ìףזסךמי"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)BOY, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Æוםסךטי"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)GIRLOCHKA, NULL, NULL);
//
//
//        }
//        if (LOWORD(wParam) == USA)
//        {
//            ShowWindow(GetDlgItem(hWnd, USA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, PARENTS), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, CREMLIN), SW_HIDE);
//            BASS_ChannelStop(QUEST_THEME);
//            CreateWindow(TEXT("STATIC"), TEXT("Âû ןמןûעאכטסü ןנטכועועü ג ÑØÀ. È ןמ ךאךמי-עמ ןנטקטםו גאס םו מסעאםמגטכט םא דנאםטצו, ףהטגטעוכüםמ, ץמעÿ םוע, קונוח 5 לטםףע חא גאלט ןנטכועוכ סאלמכוע ÔÁÐ. È גוזכטגמ סענוכüםףכ נאךועאלט ג גאר גונעמכוע. Âû רארםאץלו. Ìמנאכü: <<Íו ןונוסוךאיעו הועט דנאםטצף, א עמ בףהוע רארםאץלו>> "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//            HSTREAM JACKSON = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\Stranger in Moscow.mp3", 0, 0, 0);
//            BASS_ChannelPlay(JACKSON, false);
//        }
//        if (LOWORD(wParam) == CREMLIN)
//        {
//            ShowWindow(GetDlgItem(hWnd, USA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, PARENTS), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, CREMLIN), SW_HIDE);
//            BASS_ChannelStop(QUEST_THEME);
//            CreateWindow(TEXT("STATIC"), TEXT("Ïנטכועוג ך Êנולכ‏, גû גסענועטכט רטנמךמדמ Ïףעטםא, ךמעמנûי גאל סהוכאכ עאךמי רארםאץלו, קעמ גאל גארוי ץףהמי ךמסעט םו ץגאעטכמ, קעמבû ודמ ןמגאכטעü =). Ìמנאכü: <<Åסכט גû סכאבוו, האזו םו ןûעאיעוסü כוחעü ג הנאךף, א עמ ןמכףקטעו רארםאץלו ג דכאח>> "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//            HSTREAM PUTIN = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\WIDE.mp3", 0, 0, 0);
//            BASS_ChannelPlay(PUTIN, false);
//        }
//
//        if (LOWORD(wParam) == GIRLOCHKA)
//        {
//            ShowWindow(GetDlgItem(hWnd, USA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, PARENTS), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, CREMLIN), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, BOY), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, GIRLOCHKA), SW_HIDE);
//
//            CreateWindow(TEXT("STATIC"), TEXT("Âû ןנטוץאכט םא האקף ך נמהטעוכÿל. ×עמ בףהועו הוכאעü?"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ïמלמדאעü נמהטעוכÿל"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)HELP1, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ïמיעט ג הףר"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)SHOWER, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ïמיעט ך ןאנם‏"), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)BOYFRIEND1, NULL, NULL);
//
//
//        }
//        if (LOWORD(wParam) == BOY)
//        {
//            ShowWindow(GetDlgItem(hWnd, USA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, PARENTS), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, CREMLIN), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, BOY), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, GIRLOCHKA), SW_HIDE);
//
//            CreateWindow(TEXT("STATIC"), TEXT("Âû ןנטוץאכט םא האקף ך נמהטעוכÿל. ×עמ בףהועו הוכאעü?"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ïמלמדאעü נמהטעוכÿל"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)HELP1, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ïמיעט ג הףר"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)SHOWER, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ïמיעט ך הוגףרךו"), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)DEVA1, NULL, NULL);
//
//        }
//        if (LOWORD(wParam) == BOYFRIEND1)
//        {
//            ShowWindow(GetDlgItem(hWnd, BOYFRIEND1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, BOY), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, GIRLOCHKA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, HELP1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SHOWER), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, DEVA1), SW_HIDE);
//            CreateWindow(TEXT("STATIC"), TEXT("ÄÀ ÎÒ ÂÀÑ ÆÅ ÏÀÑÅÒ ÍÀ ÌÈËËÈÎÍ ÊÈËÎÌÅÒÐÎÂ! ÏÀÐÅÍÜ ÓÁÅÆÀË! ÈÃÐÀ ÎÊÎÍ×ÅÍÀ! ÂÛ ËÎØÀØ È ØÀØÍÀÕÌÅ! Ìמנאכü: <<Ñכוהטעו חא דטדטוםמי, םו בףהüעו גמם‏קךאלט!>>"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//        }
//        if (LOWORD(wParam) == DEVA1)
//
//        {
//            ShowWindow(GetDlgItem(hWnd, BOY), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, GIRLOCHKA), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, HELP1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SHOWER), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, DEVA1), SW_HIDE);
//            CreateWindow(TEXT("STATIC"), TEXT("ÄÀ ÎÒ ÂÀÑ ÆÅ ÏÀÑÅÒ ÍÀ ÌÈËËÈÎÍ ÊÈËÎÌÅÒÐÎÂ! ÄÅÂÓØÊÀ ÓÁÅÆÀËÀ Â ÑËÅÇÀÕ!! ÈÃÐÀ ÎÊÎÍ×ÅÍÀ! ÂÛ ËÎØÀØ È ØÀØÍÀÕÌÅ! Ìמנאכü: <<Ñכוהטעו חא דטדטוםמי, םו בףהüעו גמם‏קךאלט!>>"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//        }
//        if (LOWORD(wParam) == HELP1)
//        {
//            ShowWindow(GetDlgItem(hWnd, SHOWER), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, DEVA1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, BOYFRIEND1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, HELP1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, LOVING), SW_HIDE);
//            CreateWindow(TEXT("STATIC"), TEXT("Ïנאגטכüםמ גû ןמסעףןאועו, ןמלמדאועו נמהטעוכÿל. Âû ג זטחםט םאהו‏סü עאךזו ןמסעףןאועו? Åסכט הא, עמ למכמהצû. Ïמסעףןאיעו עאך גסודהא! Â ‎עמל ט למנאכü: <<Ïמלמדאיעו בכטחךטל>>"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//        }
//        if (LOWORD(wParam) == SHOWER)
//        {
//            ShowWindow(GetDlgItem(hWnd, SHOWER), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, DEVA1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, BOYFRIEND1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, HELP1), SW_SHOW);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ïמיעט םאגסענוקף כ‏בגט"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)LOVING, NULL, NULL);
//            
//
//        }
//        if (LOWORD(wParam) == LOVING)
//        {
//            ShowWindow(GetDlgItem(hWnd, HELP1), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, LOVING), SW_HIDE);
//            CreateWindow(TEXT("STATIC"), TEXT("Íאיהÿ סגמ‏ כ‏במגü גû סעאכט זטעü המכדמ ט סקאסעכטגמ. Ìמנאכü:<<Íוע ג זטחםט םטקודמ גאזםוו חהמנמגüÿ ט סקאסעüÿ>>."), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//        }
//
//
//        if (LOWORD(wParam) == FIRST2)
//        {
//            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//            UpdateWindow(hWnd);
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FIRST2), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SECOND2), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD2), SW_HIDE);                                                                                                           
//            CreateWindow(TEXT("STATIC"), TEXT("Ñוג ג toyota גû נאחמדםאכטסü ט ןנמבטכט סעוםךף, ןמעמל ףהאקםמ גûוץאכט ט וץאכט בû ושו המכדמ, וסכט בû בכטזאירטי דאטרםטך םו מסעאםמגטכ גאס ס גמןנמסמל: <<ÝÉ ÂÛ ÑÎÂÑÅÌ ØÀØÍÀÕÌÅ ×ÒÎ ËÈ?>>. Èדנא מךמםקוםא.Ìמנאכü: םו סאהטעוסü הועט ג לארטםף בוח ןנאג, עול במכוו ג קףזף‏ לארטםף. Íו ןמהגונדאיעו נטסךף סובÿ ט מךנףזא‏שטץ.     "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 480, hWnd, (HMENU)NULL, NULL, NULL);
//            BASS_ChannelStop(QUEST_THEME);
//            BASS_ChannelStop(LADAV);
//            BASS_Stop();
//            BASS_Start();
//
//            HSTREAM ROSB = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\RASB.mp3", 0, 0, 0);
//            BASS_ChannelPlay(ROSB, false);
//
//
//        }
//
//        if (LOWORD(wParam) == SECOND2)
//        {
//            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FIRST2), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SECOND2), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD2), SW_HIDE);
//            BASS_ChannelStop(QUEST_THEME);
//            HSTREAM KAVINSKY = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\kav.mp3", 0, 0, 0);
//            BASS_ChannelPlay(KAVINSKY, false);
//            CreateWindow(TEXT("STATIC"), TEXT("Ñוג ג BMW, גû גךכ‏קטכט ענוך Kavinsky-Nightcall ט ףלקאכטסü סמ סעטכול!!!    "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//        }
//        if (LOWORD(wParam) == THIRD2)
//        {
//            SetClassLong(hWnd, GCL_STYLE, GetClassLong(hWnd, GCL_STYLE));
//
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FIRST2), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SECOND2), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD2), SW_HIDE);
//            BASS_ChannelPause(QUEST_THEME);
//            HSTREAM LADAV = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\trombone.mp3", 0, 0, 0);
//            
//            BASS_ChannelPlay(LADAV, false);
//            BASS_ChannelPlay(QUEST_THEME, false);
//            CreateWindow(TEXT("STATIC"), TEXT("Ïמןûעאגרטסü חאגוסעט לארטםף, סןףסעÿ 50 לטםףע, גû עאךט סלמדכט גûוץאעü חא ןנוהוכû לוסעא דהו גû חאסענÿכט, םמ סןףסעÿ 100 לוענמג לארטםא חאסענÿכא ג בכטזאירול במכמעו. Âû סלמדכט גûבנאעüסÿ, ט ןנמיהÿ 5 לוענמג םארכט עוכופמם, םא ךמעמנמל 1% חאנÿהךט, עאך קעמ ןמחגמםטעü למזםמ עמכüךמ 1 נאח. Êמלף ןמחגמםטל?    "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ïמחגמםטעü לאלו"), WS_VISIBLE | WS_CHILD, 220,115, 185, 35, hWnd, (HMENU)FIRST3, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ïמחגמםטעü Ðאחנאבמעקטךף"), WS_VISIBLE | WS_CHILD, 220, 155, 185, 35, hWnd, (HMENU)SECOND3, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ïמטדנאעü ג Geometry Dash"), WS_VISIBLE | WS_CHILD, 220, 195, 185, 35, hWnd, (HMENU)THIRD3, NULL, NULL);
//        }
//        if (LOWORD(wParam) == FIRST3)
//        {
//            CreateWindow(TEXT("STATIC"), TEXT("Ïנטגוע למי נובוםמך, ךאך עû עאל? Ïמקולף םו חגמםטרü? Â הונוגםו ןמ עובו עגמÿ כ‏במגü סךףקאוע, עאך ט סטהטע ף מךםא המלא ךאזהûי הוםü. Íאהמ םאל ןמלמקü, לû ס ןאןמי ףזו סעאנוםüךטו, א נאבמעû ג הונוגםו גûרו ךנûרט. Êאך עû עאל?"), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FIRST3), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SECOND3), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD3), SW_HIDE);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ìאלא, ÿ עףע ג ךאךמל-עמ ןונוףכךו..."), WS_VISIBLE | WS_CHILD, 150, 155, 300, 35, hWnd, (HMENU)MOTHER, NULL, NULL);
//            CreateWindow(TEXT("BUTTON"), TEXT("Ìאלא, ÿ שאס ןנטוהף!!!"), WS_VISIBLE | WS_CHILD, 150, 200, 300, 35, hWnd, (HMENU)EDU, NULL, NULL);
//        }
//        if (LOWORD(wParam) == EDU)
//        {
//            CreateWindow(TEXT("STATIC"), TEXT("Âû ףסןוכט סךאחאעü לאלו ‎עט סכמגא, ןמעמל עוכופמם מעךכ‏קטכסÿ. Âû ףסןורםמ ןורךמל המבוזאכט המ כוסעםטצû, ןמהםÿכטסü ןמ םוי ט ףגטהוכט גוכמסטןוה, לארטםף ט גונעמכוע. Êףהא סÿהול? "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//            ShowWindow(GetDlgItem(hWnd, MOTHER), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, EDU), SW_HIDE);
//
//
//
//
//                ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//                ShowWindow(GetDlgItem(hWnd, FIRST), SW_HIDE);
//                ShowWindow(GetDlgItem(hWnd, SECOND), SW_HIDE);
//                ShowWindow(GetDlgItem(hWnd, THIRD), SW_HIDE);
//
//                ShowWindow(GetDlgItem(hWnd, VELOSIPED1), SW_HIDE);
//                ShowWindow(GetDlgItem(hWnd, VELOSIPED2), SW_HIDE);
//                ShowWindow(GetDlgItem(hWnd, VELOSIPED), SW_HIDE);
//                ShowWindow(GetDlgItem(hWnd, HELICOPTER), SW_HIDE);
//                ShowWindow(GetDlgItem(hWnd, MASHINA), SW_HIDE);
//
// 
//
//
//                CreateWindow(TEXT("BUTTON"), TEXT("Ñוסעü ג גוכמסטןוה"), WS_VISIBLE | WS_CHILD, 230, 75, 165, 35, hWnd, (HMENU)VELOSIPED, NULL, NULL);
//                CreateWindow(TEXT("BUTTON"), TEXT("Ñוסעü ג לארטםף"), WS_VISIBLE | WS_CHILD, 230, 115, 165, 35, hWnd, (HMENU)MASHINA, NULL, NULL);
//                CreateWindow(TEXT("BUTTON"), TEXT("Ñוסעü ג גונעמכוע "), WS_VISIBLE | WS_CHILD, 230, 155, 165, 35, hWnd, (HMENU)HELICOPTER, NULL, NULL);
//            
//
//
//
//        }
//        if (LOWORD(wParam) == SECOND3)
//        {
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FIRST3), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SECOND3), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD3), SW_HIDE);
//            CreateWindow(TEXT("STATIC"), TEXT("Çגמםטעü נאחנאבמעקטךף גנוהםמ הכÿ חהמנמגüÿ. Âû עףע זו ףלונכט, ןמעמלף קעמ ף גאס םו עמכסעאÿ ךמסעü. È נאחנאבמעקטך ןמנאחטכ גאס גוכטךטל רארםאץלולסךטל לוקמל."), WS_VISIBLE | WS_CHILD, 100, 10, 450, 80, hWnd, (HMENU)NULL, NULL, NULL);
//            BASS_ChannelStop(QUEST_THEME);
//            BASS_ChannelStop(LADAV);
//            HSTREAM KILL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\kill.mp3", 0, 0, 0);
//            BASS_ChannelPlay(KILL, false);
//
//        }
//        if (LOWORD(wParam) == MOTHER)
//        {
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FIRST3), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SECOND3), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD3), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MOTHER), SW_HIDE);
//
//            CreateWindow(TEXT("STATIC"), TEXT("<<Îןÿעü עû ןמ ןונוףכךאל רכÿורüסÿ ט בףץאורü! Õמעÿ ÿ עובו חאןנועטכא ןטעü! Ýעמ גסו הנףחüÿ עגמט, מקוםü ןכמץמ םא עובÿ גכטÿ‏ע. Íף, םטקודמ המלא ןמדמגמנטל! Íובמסü ושו ט ךףנטרü? Îעוצ ס עובÿ גס‏ רךףנף סםטלוע!>> - Âסו קעמ ףסןוכא סךאחאעü לאלא. Ïמעמל עוכופמם מעךכ‏קטכסÿ. Ìמנאכü עאךמגא: Íו ןויעו ט גוהטעו חהמנמגûי מבנאח זטחםט, עמדהא ןמ ןונוףכךאל רכÿעüסÿ םו ןנטהועסÿ =( "), WS_VISIBLE | WS_CHILD, 100, 10, 450, 480, hWnd, (HMENU)NULL, NULL, NULL);
//            BASS_ChannelStop(QUEST_THEME);
//            BASS_ChannelStop(LADAV);
//            HSTREAM KILL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\kill.mp3", 0, 0, 0);
//            BASS_ChannelPlay(KILL, false);
//        }
//        if (LOWORD(wParam) == THIRD3)
//        {
//            ShowWindow(GetDlgItem(hWnd, ID_BUTTON), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, FIRST3), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, SECOND3), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, THIRD3), SW_HIDE);
//            ShowWindow(GetDlgItem(hWnd, MOTHER), SW_HIDE);
//            CreateWindow(TEXT("STATIC"), TEXT("Ïמטדנאג ךאךטץ-עמ 5 לטםףע ט םו ןנמיהÿ האזו מהטם ףנמגוםü ג טדנו, גû נאחבטכט עוכופמם. Êמםוצ טדנû =). Ìמנאכü: םו ענאעüעו סגמ‏ זטחםü גןףסעף‏. Ðאחגכוקוםטÿ ‎עמ ץמנמרמ, םמ ג לונף. Ðמגםמ עאךזו, ךאך ט נאבמעא."), WS_VISIBLE | WS_CHILD, 100, 10, 450, 480, hWnd, (HMENU)NULL, NULL, NULL);
//            BASS_ChannelStop(QUEST_THEME);
//            BASS_ChannelStop(LADAV);
//            HSTREAM KILL = BASS_StreamCreateFile(FALSE, "MusicPlayer\\quest\\kill.mp3", 0, 0, 0);
//            BASS_ChannelPlay(KILL, false);
//        }
//        break;
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
//    RegisterClass(&op);
//
//
//    CreateWindowA(op.lpszClassName, "Title", WS_OVERLAPPEDWINDOW | WS_VISIBLE, 100, 100, 640, 360, NULL, NULL, op.hInstance, NULL);
//    MSG msg;
//    while (GetMessage(&msg, NULL, 0, 0)) {
//        TranslateMessage(&msg);
//        DispatchMessage(&msg);
//
//    }
//
//}
#include <windows.h>
#include <math.h>
#include <string.h>
#include <stdio.h>
#define ZERO 100
#define ONE 101
#define TWO 102
#define THREE 103
#define FOUR 104
#define FIVE 105
#define SIX 106
#define SEVEN 107
#define EIGHT 108
#define NINE 109
#define CLEAR 110
#define DIVIDE 111
#define MULTIPLY 112
#define MINUS 113
#define PLUS 114
#define POINT 115
#define EQUALS 116
#define DISP 117

float iHold1=0.00, iHold2, iAns=0.00;
char display[64], *op;

static HINSTANCE g_hInst=NULL;
HBITMAP back;
BITMAP bm;
HDC hdcWindow,hdcMemory;
PAINTSTRUCT ps;

HWND hwnd,disp, zero, one, two, three, four,
five, six, seven, eight, nine, plus,
minus, multiply, divide, point, equals, clear;
                 
HWND Edit(HWND hwnd, HINSTANCE hInst, char *name, int x, int y, int ID)
{return CreateWindowEx(0,"EDIT",name,WS_CHILD|WS_VISIBLE|ES_RIGHT|ES_AUTOHSCROLL,x,y,80,20,hwnd,(HMENU)ID,hInst,NULL);}
HWND Button(HWND hwnd, HINSTANCE hInst, char *name, int x, int y, int ID)
{return CreateWindowEx(0,"BUTTON",name,WS_CHILD|WS_VISIBLE,x,y,20,20,hwnd,(HMENU)ID,hInst,NULL);}
HWND ButtonPE(HWND hwnd, HINSTANCE hInst, char *name, int x, int y, int ID)
{return CreateWindowEx(0,"BUTTON",name,WS_CHILD|WS_VISIBLE,x,y,20,40,hwnd,(HMENU)ID,hInst,NULL);}
HWND ButtonZ(HWND hwnd, HINSTANCE hInst, char *name, int x, int y, int ID)
{return CreateWindowEx(0,"BUTTON",name,WS_CHILD|WS_VISIBLE,x,y,40,20,hwnd,(HMENU)ID,hInst,NULL);}
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);

int WINAPI WinMain (HINSTANCE hThisInstance,
                    HINSTANCE hPrevInstance,
                    LPSTR lpszArgument,
                    int nFunsterStil)

{
    MSG messages;
    WNDCLASSEX wincl;
    g_hInst=hThisInstance;
    wincl.hInstance = g_hInst;
    wincl.lpszClassName = "MAIN";
    wincl.lpfnWndProc = WindowProcedure;
    wincl.style = CS_DBLCLKS;
    wincl.cbSize = sizeof (WNDCLASSEX);
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;
    wincl.cbClsExtra = 0;
    wincl.cbWndExtra = 0;
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;
    if (!RegisterClassEx (&wincl))return 0;

    hwnd = CreateWindowEx (0,"MAIN","Happy Calc-ulator v1.0",WS_OVERLAPPEDWINDOW|WS_POPUP,
           GetSystemMetrics(SM_CXSCREEN)/2-160,GetSystemMetrics(SM_CYSCREEN)/2-120,
           328,265,HWND_DESKTOP,NULL,g_hInst,NULL);

back = LoadBitmap(g_hInst, "BACK");
GetObject(back, sizeof(bm), &bm);
disp=Edit(hwnd,g_hInst,"",0,0,DISP);
clear=Button(hwnd,g_hInst,"C",0,20,CLEAR);
divide=Button(hwnd,g_hInst,"/",20,20,DIVIDE);
multiply=Button(hwnd,g_hInst,"*",40,20,MULTIPLY);
minus=Button(hwnd,g_hInst,"-",60,20,MINUS);
seven=Button(hwnd,g_hInst,"7",0,40,SEVEN);
eight=Button(hwnd,g_hInst,"8",20,40,EIGHT);
nine=Button(hwnd,g_hInst,"9",40,40,NINE);
plus=ButtonPE(hwnd,g_hInst,"+",60,40,PLUS);
four=Button(hwnd,g_hInst,"4",0,60,FOUR);
five=Button(hwnd,g_hInst,"5",20,60,FIVE);
six=Button(hwnd,g_hInst,"6",40,60,SIX);
one=Button(hwnd,g_hInst,"1",0,80,ONE);
two=Button(hwnd,g_hInst,"2",20,80,TWO);
three=Button(hwnd,g_hInst,"3",40,80,THREE);
equals=ButtonPE(hwnd,g_hInst,"=",60,80,EQUALS);
zero=ButtonZ(hwnd,g_hInst,"0",0,100,ZERO);
point=Button(hwnd,g_hInst,".",40,100,POINT);

    ShowWindow (hwnd, nFunsterStil);
    while (GetMessage (&messages, NULL, 0, 0))
    {
        TranslateMessage(&messages);
        DispatchMessage(&messages);
    }
    return messages.wParam;
}

LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_PAINT:
         if(back)
         {
             hdcWindow = BeginPaint(hwnd,&ps);
             hdcMemory = CreateCompatibleDC(hdcWindow);
             SelectObject(hdcMemory,back);
             BitBlt(hdcWindow, 0, 0, 320, 240, hdcMemory, 0, 0, SRCPAINT);
             BitBlt(hdcWindow, 0, 0, 320, 240, hdcMemory, 0, 0, SRCAND);
             DeleteDC(hdcMemory);
             EndPaint(hwnd, &ps);
         }
        break;
        case WM_COMMAND:
        {
             GetWindowText(disp, display, 64);
            case BN_CLICKED:
            switch(LOWORD(wParam))
            {
                 case ONE:
                     strcat(display,"1");
                     SetWindowText(disp, display);
                 break;
                 case TWO:
                      strcat(display,"2");
                      SetWindowText(disp,display);
                 break;
                 case THREE:
                     strcat(display,"3");
                     SetWindowText(disp, display);
                 break;
                 case FOUR:
                     strcat(display,"4");
                     SetWindowText(disp, display);
                 break;
                 case FIVE:
                     strcat(display,"5");
                     SetWindowText(disp, display);
                 break;
                 case SIX:
                     strcat(display,"6");
                     SetWindowText(disp, display);
                 break;
                 case SEVEN:
                     strcat(display,"7");
                     SetWindowText(disp, display);
                 break;
                 case EIGHT:
                     strcat(display,"8");
                     SetWindowText(disp, display);
                 break;
                 case NINE:
                     strcat(display,"9");
                     SetWindowText(disp, display);
                 break;
                 case ZERO:
                     strcat(display,"0");
                     SetWindowText(disp, display);
                 break;
                 case PLUS:
                    op = "+";
                    iHold1 = atoi(display);
                    SetWindowText(disp, "");
                 break;
                 case MINUS:
                    op = "-";
                    iHold1 = atoi(display);
                    SetWindowText(disp, "");
                 break;
                 case MULTIPLY:
                    op = "*";
                    iHold1 = atoi(display);
                    SetWindowText(disp, "");
                 break;
                 case DIVIDE:
                    op = "/";
                    iHold1 = atoi(display);
                    SetWindowText(disp, "");
                 break;
                 case EQUALS:
                     iHold2 = atoi(display);
                     if(op == "*"){iAns = iHold1 * iHold2;}
                     if(op == "+"){iAns = iHold1 + iHold2;}
                     if(op == "-"){iAns = iHold1 - iHold2;}
                     if(op == "/"){iAns = iHold1 / iHold2;}
                     char cI2A[64];
                     itoa(iAns, cI2A, 10);
                     SetWindowText(disp, cI2A); 
                 break;
                 case CLEAR:
                     iHold1 = 0;
                     iHold2 = 0;
                     iAns = 0;
                     SetWindowText(disp, "");
                 break;
            }
        }
        break;
        case WM_DESTROY:
            DeleteObject(back);
            PostQuitMessage (0);
            break;
        default:
            return DefWindowProc (hwnd, message, wParam, lParam);
    }
    return 0;
}

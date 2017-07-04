#include "gm_sys.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>

POINT GetGMCursor()
{
	CONSOLE_SCREEN_BUFFER_INFO bi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &bi);
	POINT Ret;
	Ret.x = bi.dwCursorPosition.X;
	Ret.y = bi.dwCursorPosition.Y;
	return Ret;
}

void SetGMCursor(int x, int y)
{
	COORD position = {x,y}; //позиция x и y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
}
void SetGMCursor(POINT p)
{
	SetGMCursor(p.x,p.y);
}

void DrawConsoleText(int x, int y, std::string Text)
{
	POINT lastp = GetGMCursor();
    SetGMCursor(x,y);
	std::cout << Text;
	SetGMCursor(lastp);
}

void DrawConsoleLine(int x1,int y1,int x2,int y2)
{
	POINT lastp = GetGMCursor();
    int pBegin = 0;
	int pEnd = 0;
	bool Horizont = true;
	if (x1!=x2){
        pBegin = x1<x2 ? x1 : x2;
        pEnd = x1<x2 ? x2 : x1;
        Horizont = true;
	}else{
	    pBegin = y1<y2 ? y1 : y2;
        pEnd = y1<y2 ? y2 : y1;
        Horizont = false;
	}
	for (int i=pBegin;i<=pEnd;i++){
		if (Horizont){
			SetGMCursor(i,y1);
			std::cout << "\xC4";
		}else{
			SetGMCursor(x1,i);
			std::cout << "\xB3";
		}
	}
	SetGMCursor(lastp);
}

void DrawConsoleRectangle(int x1,int y1,int x2,int y2)
{
	DrawConsoleLine(x1+1,y1,x2-1,y1);
	DrawConsoleLine(x1+1,y2,x2-1,y2);
	DrawConsoleLine(x1,y1+1,x1,y2-1);
	DrawConsoleLine(x2,y1+1,x2,y2-1);
	DrawConsoleText(x1,y1,"\xDA");
	DrawConsoleText(x2,y1,"\xBF");
	DrawConsoleText(x1,y2,"\xC0");
	DrawConsoleText(x2,y2,"\xD9");
}

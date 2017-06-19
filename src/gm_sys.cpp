#include "gm_sys.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

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

#ifndef GM_SYS_H
#define GM_SYS_H
#include <windows.h>
#include <string>

using namespace std;

void SetGMCursor(int x, int y);
void SetGMCursor(POINT);
POINT GetGMCursor();
void DrawConsoleLine(int x1,int y1,int x2,int y2);
void DrawConsoleRectangle(int x1,int y1,int x2,int y2);
void DrawConsoleText(int x, int y, std::string Text);

#endif // GM_SYS_H

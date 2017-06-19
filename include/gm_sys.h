#ifndef GM_SYS_H
#define GM_SYS_H
#include <windows.h>

void SetGMCursor(int x, int y);
void SetGMCursor(POINT);
POINT GetGMCursor();

#endif // GM_SYS_H

#include <iostream>
#include <windows.h>
#include "Card.h"
#include "gm_sys.h"
//#include <clocale> //Обязательно для функции setlocale()
using namespace std;

int main()
{
	SetConsoleCP(866);
    SetConsoleOutputCP(866);
	Card A(3,10);
	A.Draw(10,1);
	A.DrawHirt(1,5);
	A.DrawHirt(1,4);
	A.DrawHirt(1,3);
	A.DrawHirt(1,2);
	A.DrawHirt(1,1);
	SetGMCursor(1,20);
	return 0;
}

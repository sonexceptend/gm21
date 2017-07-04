#include "Card.h"
#include "gm_sys.h"
#include <iostream>
#include <conio.h>
#include <windows.h>
//rfhns

using namespace std;

Card::Card() : Suite(Hearts),Value(Six) {}
Card::Card(int _Suite, int _Value) : Suite((CardSuite)_Suite),Value((CardValue)_Value) {}
Card::Card(CardSuite _Suite, CardValue _Value) : Suite(_Suite),Value(_Value) {}
Card::~Card(){}
Card::Card(const Card &obj)
{
	Suite = obj.Suite;
	Value = obj.Value;
}
std::string DrawSuite(CardSuite Suite)
{
	switch(Suite)
	{
	case Spades:
        return "\x06";
	case Clubs:
        return "\x05";
	case Diamonds:
        return "\x04";
	case Hearts:
        return "\x03";
	}
}
std::string DrawValue(CardValue Value)
{
	switch(Value)
	{
	case Six:
        return (std::string)("\x36");
	case Seven:
        return (std::string)("\x37");
	case Eight:
        return (std::string)("\x38");
	case Nine:
        return (std::string)("\x39");
	case Ten:
        return (std::string)("\x31\x30");
	case Jack:
        return (std::string)("\x4A");
	case Queen:
        return (std::string)("\x51");
	case King:
        return (std::string)("\x4B");
	case Ace:
        return (std::string)("\x41");
	}
}
Card::Draw(int x, int y){
	//setlocale(LC_ALL,"C"); //Функция setlocale() с аргументами
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    POINT lastp = GetGMCursor();
    DrawConsoleRectangle(x,y,x+6,y+5);
    DrawConsoleText(x+1,y+1,DrawValue(Value));
    DrawConsoleText(x+(Value==10?1:2),y+1,DrawSuite(Suite));
    DrawConsoleText(x+4,y+4,DrawValue(Value));
    DrawConsoleText(x+(Value==10?6:5),y+4,DrawSuite(Suite));
    //SetConsoleTextAttribute(hConsole, (WORD) ((15 << 4) | 0));
    SetGMCursor(lastp);
}
Card::DrawHirt(int x, int y){
	//setlocale(LC_ALL,"C"); //Функция setlocale() с аргументами

    POINT lastp = GetGMCursor();
    SetGMCursor(x,y);
	cout << "\xDA\xC4\xC4\xC4\xC4\xC4\xBF" << endl;
	SetGMCursor(x,y+1);
	cout << "\xB3\xB0\xB0\xB0\xB0\xB0\xB3" << endl;
	SetGMCursor(x,y+2);
	cout << "\xB3\xB0\xB0\xB0\xB0\xB0\xB3" << endl;
	SetGMCursor(x,y+3);
	cout << "\xB3\xB0\xB0\xB0\xB0\xB0\xB3" << endl;
	SetGMCursor(x,y+4);
	cout << "\xB3\xB0\xB0\xB0\xB0\xB0\xB3" << endl;
	SetGMCursor(x,y+5);
	cout << "\xC0\xC4\xC4\xC4\xC4\xC4\xD9" << endl;
	SetGMCursor(lastp);
}


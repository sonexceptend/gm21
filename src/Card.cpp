#include "Card.h"
#include "gm_sys.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

Card::Card() : Suite(Hearts),Value(Six) {}
Card::Card(int _Suite, int _Value) : Suite((CardSuite)_Suite),Value((CardValue)_Value) {}
Card::Card(CardSuite _Suite, CardValue _Value) : Suite(_Suite),Value(_Value) {}
Card::~Card(){}
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
        return "\x36";
	case Seven:
        return "\x37";
	case Eight:
        return "\x38";
	case Nine:
        return "\x39";
	case Ten:
        return "\x31\x30";
	case Jack:
        return "\x4A";
	case Queen:
        return "\x51";
	case King:
        return "\x4B";
	case Ace:
        return "\x41";
	}
}
Card::Draw(int x, int y){
	//setlocale(LC_ALL,"C"); //Функция setlocale() с аргументами

    POINT lastp = GetGMCursor();
    SetGMCursor(x,y);
	cout << "\xDA\xC4\xC4\xC4\xC4\xC4\xBF" << endl;
	SetGMCursor(x,y+1);
	cout << "\xB3"<< DrawValue(Value)<<DrawSuite(Suite)<<(Value==10?"":" ")<<"  \xB3" << endl;
	SetGMCursor(x,y+2);
	cout << "\xB3     \xB3" << endl;
	SetGMCursor(x,y+3);
	cout << "\xB3     \xB3" << endl;
	SetGMCursor(x,y+4);
	cout << "\xB3  "<<(Value==10?"":" ")<<DrawValue(Value)<<DrawSuite(Suite)<<"\xB3" << endl;
	SetGMCursor(x,y+5);
	cout << "\xC0\xC4\xC4\xC4\xC4\xC4\xD9" << endl;
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


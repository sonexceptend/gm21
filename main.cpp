#include <iostream>
#include <windows.h>
#include "Card.h"
#include "gm_sys.h"
#include "GameManager.h"
#include "conio.h"


using namespace std;

int main()
{
	SetConsoleCP(866);
    SetConsoleOutputCP(866);

    GameManager* game = new GameManager();
    //getch();
	int i_input;
    while (game->GetStatus()!=None){
		game->Draw();
		SetGMCursor(20,20);
		i_input = getch();
		game->ApplyKey(i_input);
    }


	/*Card A(3,10);
	A.Draw(10,1);
	A.DrawHirt(1,5);
	A.DrawHirt(1,4);
	A.DrawHirt(1,3);
	A.DrawHirt(1,2);
	A.DrawHirt(1,1);*/
	delete game;
	return 0;
}

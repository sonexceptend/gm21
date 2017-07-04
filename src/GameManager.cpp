#include "GameManager.h"
#include "gm_sys.h"
#include "Card.h"
#include <iostream>
#include <list>
#include <ctime>
#include "conio.h"
#include <algorithm>
#include <iterator>

using namespace std;

GameManager::GameManager()
{
	gmState = Menu;
	for (int s=0; s<4;s++){
		for (int v=6; v<15;v++){
			Card* NewCard = new Card(s,v);
			Deck.push_front(*NewCard);
		}
    }
    ShuffleDeck();
}

GameManager::Draw()
{
	switch(gmState){
	case Menu:
		DrawMenu();
		break;
	case Game:
		DrawGame();
		break;
	case None:
		DrawNone();
		break;
	};
}
GameManager::ApplyKey(int KeyCode){
	switch(KeyCode){
	case 27:
		gmState = (gmState==Game) ? Menu : None;
		break;
	case 59:
		gmState = Game;
		break;
	};

}
GameManager::~GameManager()
{
	list<Card>::iterator it = Deck.begin();
	while (it!=Deck.end()){
		(*it++).~Card();
	}
	list<Card>::iterator itp = PlayerCard.begin();
	while (itp!=PlayerCard.end()){
		(*itp++).~Card();
	}
	Deck.clear();
	PlayerCard.clear();
}

GameManager::DrawMenu()
{
	system("cls");
	DrawConsoleRectangle(0,2,51,15);
	//вывод меню
	DrawConsoleText(3,3,"Programm menu");
	DrawConsoleLine(2,4,48,4);
	DrawConsoleText(3,6,"F1\t-\tNew game");
	DrawConsoleText(3,8,"F2\t-\tHelp");
	DrawConsoleText(3,10,"Esc\t-\tExit");
}
GameManager::DrawGame()
{
	system("cls");
	DrawConsoleRectangle(0,2,51,15);
	//вывод меню
	DrawConsoleText(1,1,"0\t-\tComputer source");
	DrawConsoleText(1,16,"0\t-\tPlayer source");
	Card A(3,10);
	A.DrawHirt(1,8);
	A.DrawHirt(1,7);
	A.DrawHirt(1,6);
	A.DrawHirt(1,5);
	A.DrawHirt(1,4);
	TakeOneCard(true);
	TakeOneCard(true);
	list<Card>::iterator cIter = Deck.begin();
	(*cIter).Draw(10,3);
	cIter++;
	(*cIter).Draw(17,3);

	list<Card>::iterator cPlaeyIter = PlayerCard.begin();
	(*cPlaeyIter).Draw(10,9);
	cPlaeyIter++;
	(*cPlaeyIter).Draw(17,9);
}

GameManager::DrawNone()
{
	system("cls");
}

void GameManager::TakeOneCard(bool TakePlayer){
	list<Card>::iterator cIter = Deck.begin();
	if (TakePlayer){
		PlayerCard.push_front(*cIter);
        Deck.pop_front();
	}
}

void GameManager::ShuffleDeck(){
	list<Card> TempDeck;
	list<Card>::iterator cIter ;
	srand(time(0));
	for (int i=0; i<36;i++){
		cIter= Deck.begin();//+ (int)(rand() % Deck.size());
		std::advance(cIter,(int)(rand() % Deck.size()));
		cout <<(int)(rand() % Deck.size()) << " "<< Deck.size()<< endl;

		Deck.push_back(*cIter);
		Deck.erase(cIter);
	}

	getch();
	/*
	cIter =TempDeck.begin();
	for (int i=0; i<36;i++){
		Deck.push_back(*cIter);
		TempDeck.erase(cIter);
		cIter++;
	}*/
}

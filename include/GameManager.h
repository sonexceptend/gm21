#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "Card.h"
#include <list>

enum GameState
{
	None = 0,
	Menu = 1,
	Game = 2,
	Pause = 3,
	Win = 4,
	Loss = 5
};

class GameManager
{
	private:
		GameState gmState = None;
		std::list<Card> Deck;
		std::list<Card> PlayerCard;
		std::list<Card> BotCard;

		void ShuffleDeck();
		void TakeOneCard(bool TakePlayer = true);
	public:
		GameManager();
		~GameManager();
		Draw();
		GameState GetStatus(){return gmState;}
		ApplyKey(int KeyCode);
	protected:
		DrawMenu();
		DrawGame();
		DrawNone();

};

#endif // GAMEMANAGER_H

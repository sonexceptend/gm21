#ifndef CARD_H
#define CARD_H
#include <stdio.h>
//using namespace std;

enum CardSuite{
	Spades = 0,
	Clubs = 1,
	Diamonds = 2,
	Hearts = 3
};

enum CardValue{
	Six = 6,
	Seven = 7,
	Eight = 8,
	Nine = 9,
	Ten = 10,
	Jack = 11,
	Queen = 12,
	King = 13,
	Ace = 14
};

class Card
{
	public:
		Card();
		Card(int, int);
		Card(CardSuite, CardValue);
		~Card();

		Draw(int,int);
		DrawHirt(int,int);

		CardSuite GetSuite(){return Suite;};
		CardValue GetValue(){return Value;};

	protected:

	private:
		CardSuite Suite;
		CardValue Value;
};

#endif // CARD_H

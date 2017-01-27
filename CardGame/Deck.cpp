#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

Deck::Deck()
{
	cout << "Assembling the deck..." << endl;
	for (int i = 0; i < 13; i++) {
		Card clubCard(i + 1, clubs);
		theDeck[i] = clubCard;

		Card heartCard(i + 1, hearts);
		theDeck[i + 13] = heartCard;

		Card spadeCard(i + 1, spades);
		theDeck[i + 26] = spadeCard;

		Card diamondCard(i + 1, diamonds);
		theDeck[i + 39] = diamondCard;
	}
	topCard = 0;
}

Card Deck::dealCard() {
	topCard++;
	return theDeck[topCard - 1];
}

void Deck::Shuffle() {
	int randPosition;
	Card tempCard;
	srand(time(NULL));
	for (int i = 0; i < 52; i++) {
		randPosition = rand() % 52;
		tempCard = theDeck[i];
		theDeck[i] = theDeck[randPosition];
		theDeck[randPosition] = tempCard;
	}
}

bool Deck::isEmpty() {
	return (topCard >= 52);
}

ostream& operator<<(ostream& os, const Deck& rhs){
	for (int i = 0; i < 52; i++) {
		cout << rhs.theDeck[i];
	}
	return os;
}


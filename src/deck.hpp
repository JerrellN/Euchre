#ifndef DECK_H 
#define DECK_H

#include <vector>
using std::vector;
#include "card.hpp"
#include <sstream>
using std::stringstream;
#include <algorithm>

class Deck
{
private:

	string Suits[4];
	static int DeckSize;
	string m_suits;

public:
	int CurrentTurn;
	int CurrentTopCard;
	vector<Card *> * LeDeck;
    string Ace;
    string Jack;
    string Queen;
    string King;
	

	Deck(){};
	void Shuffle(){};
	
};

#endif 
#ifndef DECK_H 
#define DECK_H

#include <vector>
using std::vector;
#include "card.hpp"
#include <sstream>
using std::stringstream;

class Deck
{
private:

	const string Suits[4];
	static const int DeckSize;
	string m_suits;

public:
	int CurrentTurn;
	int CurrentTopCard;
	vector<Card *> * LeDeck;
    string Ace;
    string Jack;
    string Queen;
    string King;
	

	Deck(){}
	
};

#endif 
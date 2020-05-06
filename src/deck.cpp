#include <vector>
using std::vector;
#include "card.hpp"
#include <sstream>
using std::stringstream;

class Deck
{
private:

	const string Suits[4] = { "Spades", "Hearts", "Clubs", "Diamonds" };
	static const int DeckSize = 52;
	string m_suits;

public:
	int CurrentTurn = 0;
	int CurrentTopCard = 0;
	vector<Card *> * LeDeck;
    string Ace = "Ace";
    string Jack = "Jack";
    string Queen = "Queen";
    string King = "King";
	

	Deck()
	{
		LeDeck = new vector<Card *>();
		string suit = Suits[0];
		int value = 1;
		int SuitLoop = 0;
		for (int i = 1; i < DeckSize + 1; i++)
		{
			suit = m_suits[SuitLoop];
			//Sets aces equal to 11
			if (value == 1)
			{
				LeDeck->push_back(new Card(suit, 11, false, Ace));
			}
			//Sets the 11th card's value, the jack, to 10 instead of 11
			else if (value == 11)
			{
				LeDeck->push_back(new Card(suit, 10, true, Jack));
			}
			//Sets the 12th card's value, the queen, to 10 instead of 12
			else if (value == 12)
			{
				LeDeck->push_back(new Card(suit, 10, true, Queen));
			}
			//Sets the 13th card's value, the king, to 10 instead of 13
			else if (value == 13)
			{
				LeDeck->push_back(new Card(suit, 10, true, King));
			}
			//Ensures the rest of the cards have values according to the incremeatation
			else
			{
				stringstream val;
				string val_str;
				val << value;
				val_str = val.str();
				LeDeck->push_back(new Card(suit, value, false, val_str));
			}
			//Moves to the next suit upon completion of the 13th card, then resets the loop until the 4 suits are complete
			if ((i % 13) == 0)
			{
				SuitLoop++;
				value = 0;
			}

			value++;
		}

			
		
	}
	
};
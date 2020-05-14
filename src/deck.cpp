#include <vector>
using std::vector;
#include "card.hpp"
#include <sstream>
using std::stringstream;
#include "deck.hpp"
#include <algorithm>

Deck::Deck()
{
	string Suits[4] = { "spades", "searts", "clubs", "diamonds" };
	DeckSize = 52;
	CurrentTurn = 0;
	CurrentTopCard = 0;
    Ace = "Ace";
    Jack = "Jack";
    Queen = "Queen";
    King = "King";
	LeDeck = new vector<Card *>();
	string suit = Suits[0];
	int value = 1;
	int SuitLoop = 0;
	for (int i = 1; i < DeckSize + 1; i++)
	{
		suit = m_suits[SuitLoop];
		//Sets aces equal to 14
		if (value == 1)
		{
			if(SuitLoop == 1 || SuitLoop == 3)
			{
				LeDeck->push_back(new Card(suit, 14, false, Ace, true, false));
			}
			else
			{
				LeDeck->push_back(new Card(suit, 14, false, Ace, false, false));
			}
			
		}
		else if (value == 11)
		{
			if(SuitLoop == 1 || SuitLoop == 3)
			{	
				LeDeck->push_back(new Card(suit, 11, true, Jack, true, true));
			}
			else
			{	
				LeDeck->push_back(new Card(suit, 11, true, Jack, false, true));
			}
		}
		else if (value == 12)
		{
			if(SuitLoop == 1 || SuitLoop == 3)
			{
				LeDeck->push_back(new Card(suit, 12, true, Queen, true, false));
			}
			else
			{
				LeDeck->push_back(new Card(suit, 12, true, Queen, false, false));
			}
		}
		else if (value == 13)
		{
			if(SuitLoop == 1 || SuitLoop == 3)
			{
				LeDeck->push_back(new Card(suit, 13, true, King, true, false));
			}
			else
			{
				LeDeck->push_back(new Card(suit, 13, true, King, false, false));
			}
		}
		//Ensures the rest of the cards have values according to the incremeatation
		else
		{
			stringstream val;
			string val_str;
			val << value;
			val_str = val.str();
			if(SuitLoop == 1 || SuitLoop == 3)
			{
				LeDeck->push_back(new Card(suit, value, false, val_str, true, false));
			}
			else
			{
				LeDeck->push_back(new Card(suit, value, false, val_str, false, false));
			}
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

void Deck::Shuffle()
{
	int size = LeDeck->size();
	for(int i = 0; i < size - 1; i++)
	{
		int j = i + rand() % (size - i);
		swap(LeDeck[i], LeDeck[j]);
	}
}
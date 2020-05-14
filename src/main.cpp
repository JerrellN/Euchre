#include "card.hpp"
#include "deck.hpp"
#include "participant.hpp"
#include <string>
using std::string;
#include <iostream>
#include <locale>
using std::locale;
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::cin;

static string Suit[4] = { "hearts", "spades", "diamonds", "clubs"};
bool TrumpColorRed = false;
string TrumpSuit = " ";

string SetTrump(int desiredSuit)
{
    string newTrump = NULL;
    newTrump = Suit[desiredSuit];
    return newTrump;
};

int TrumpInput()
{
    string input = " ";
    cout << "Pick your trump:" << endl << "0 for Hearts." << endl << "1 for Spades." << endl << "2 for Diamonds" << endl << "3 for Clubs." << endl;
    cin >> input;
    if(input == "0")
    {
        return 0;
    }
    else if(input == "1")
    {
        return 1;
    }
    else if(input == "2")
    {
        return 2;
    }
    else if(input == "3")
    {
        return 3;
    }
    else
    {
        cout << "Invalid Input. Please Try Again." << endl;
        TrumpInput();
    }
}

bool TrumpRed(string trump)
{
    if (trump == "diamonds" || trump == "hearts")
    {
        return true;
    }
    else
    {
        return false;
    }
}

float EvaluateHand(string trumpSuit, Participant * player)
{
    float handVal = 0.0;
    for(int i = 0; i < player->Hand->size(); i++)
    {
        if (trumpSuit == player->Hand->at(i)->GetSuit() && player->Hand->at(i)->IsJack())
        {
            player->Hand->at(i)->AddValForTopTrump();
        }
        else if(trumpSuit == player->Hand->at(i)->GetSuit())
        {
            player->Hand->at(i)->AddValForTrump();
        }
        else if(TrumpColorRed && player->Hand->at(i)->IsRed() && player->Hand->at(i)->IsJack())
        {
            player->Hand->at(i)->AddValForSecondTrump();
        }
        if(player->Hand->at(i)->GetValue() < 10)
        {
            handVal += 0.2;
        }
        else if(player->Hand->at(i)->GetValue() == 10)
        {
            handVal += 0.1;
        }
        else
        {
            handVal += 0;
        }
    }
    return handVal;
}

void GiveHand(Participant * player, Deck * deck)
{
    for(int i=0; i < player->getStartingHand(); i++)
    {
        player->Hand->push_back(deck->LeDeck->at(deck->CurrentTopCard));
        deck->CurrentTopCard++;
    }
}

void main()
{
    float handValue = 0.0;
    Participant * player =  new Participant(1);
    Deck * deck = new Deck();
    deck->Shuffle();
    GiveHand(player, deck);
    TrumpSuit = SetTrump(TrumpInput());
    TrumpColorRed = TrumpRed(TrumpSuit);
    handValue = EvaluateHand(TrumpSuit, player);
    cout << "The value of your hand is " << handValue << "/1.0" << endl;
}
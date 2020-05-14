#include "card.hpp"
#include "participant.hpp"
#include <vector>
using std::vector;

Participant::Participant(int playerNum)
{
	this->Hand = new vector<Card *>();
	setStartingHand(5);
	this->score = 0.0;
}

int Participant::getStartingHand()
{
	return m_StartingHand;
}

void Participant::setStartingHand(int val)
{
	this->m_StartingHand = val;
}



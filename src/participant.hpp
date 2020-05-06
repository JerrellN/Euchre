#ifndef PARTICIPANT_H 
#define PARTICIPANT_H

#include "card.hpp"
#include <vector>
using std::vector;

class Participant
{
public:
	int PlayerNum;
	int score;
	vector<Card *> * Hand;
	int CurrentHandValue;
	const static int StartingHand;

	Participant(){};
	
};

#endif
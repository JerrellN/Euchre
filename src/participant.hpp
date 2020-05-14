#ifndef PARTICIPANT_H 
#define PARTICIPANT_H

#include "card.hpp"
#include <vector>
using std::vector;

class Participant
{
private: 
	
	static int m_StartingHand;

	void setStartingHand(int val){};
public:
	int PlayerNum;
	float score;
	vector<Card *> * Hand;
	int CurrentHandValue;
	

	Participant(int playerNum){};

	int getStartingHand(){};

	
};

#endif
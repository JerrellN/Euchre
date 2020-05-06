#include "card.hpp"
#include <vector>
using std::vector;

class Participant
{
public:
	int PlayerNum;
	int score = 0;
	vector<Card *> * Hand;
	int CurrentHandValue;
	const static int StartingHand = 2;

	Participant()
	{
		Hand = new vector<Card *>();
	}
	
};
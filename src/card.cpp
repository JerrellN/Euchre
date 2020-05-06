#include <string>
using std::string;

class Card
{
private: 
    
    string m_suit;
    int m_val;
    bool m_faceCard;
    string m_fullName;
    string m_cardName;
public:
    Card(string _suit, int _val, bool _faceCard, string _cardName)
    {
        m_suit = _suit;
        m_val = _val;
        m_faceCard = _faceCard;
        m_cardName = _cardName;
    }

    string GetFull()
	{
		m_fullName = m_cardName + "_of_" + m_suit;
		return m_fullName;
	}

    int GetValue()
	{
		return m_val;
	}
};
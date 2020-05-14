#include <string>
using std::string;
#include "card.hpp"


    Card::Card(string _suit, int _val, bool _faceCard, string _cardName, bool _redCard, bool _isJack)
    {
        m_redCard = _redCard;
        m_suit = _suit;
        m_val = _val;
        m_faceCard = _faceCard;
        m_cardName = _cardName;
    }

    string Card::GetFull()
	{
		m_fullName = m_cardName + "_of_" + m_suit;
		return m_fullName;
	}

    string Card::GetSuit()
    {
        return m_suit;
    }

    bool Card::IsRed()
    {
        return m_redCard;
    }

    int Card::GetValue()
	{
		return m_val;
	}

    void Card::AddValForTrump()
    {
        m_val += 10;
    }

    void Card::AddValForSecondTrump()
    {
        m_val += 15;
    }

    bool Card::IsJack()
    {
        return m_Jack;
    }

    void Card::AddValForTopTrump()
    {
        m_val += 20;
    }

#ifndef CARD_H 
#define CARD_H
#include <string>
using std::string;


class Card
{
private: 
    bool m_redCard;
    string m_suit;
    int m_val;
    bool m_faceCard;
    string m_fullName;
    string m_cardName;
    bool m_Jack;

public:
    Card(string _suit, int _val, bool _faceCard, string _cardName, bool _redCard, bool _isJack){};

    string GetFull(){};

    int GetValue(){};

    bool IsRed(){};

    string GetSuit(){};

    void AddValForTrump(){};

    void AddValForSecondTrump(){};

    void AddValForTopTrump(){};

    bool IsJack(){};
};

#endif 
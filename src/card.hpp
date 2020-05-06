#ifndef CARD_H 
#define CARD_H
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
    Card(string _suit, int _val, bool _faceCard, string _fullName, string _cardName){};

    string GetFull(){};

    int GetValue(){};
};

#endif 
#pragma once
#include <iostream>
#include <vector>
#include <string>

using namespace std; 

enum ECardSuit { SPADES, CLUBS, DIAMONDS, HEARTS };
enum ECardValue {
    ACE = 1,
    TWO = 2,
    THREE = 3,
    FOUR = 4,
    FIVE = 5,
    SIX = 6,
    SEVEN = 7,
    EIGHT = 8,
    NINE = 9,
    TEN = 10,
    JACK = 10,
    QUEEN = 10,
    KING = 10
};

class Card {
    ECardSuit suit;
    ECardValue value;
    bool isCoverUp;
public:
    Card(ECardSuit _suit, ECardValue _value);
    void flip();
    ECardValue getValue() const;
};

class Hand {
    vector<Card*> cards;
public:
    void add(Card* card);
    void clear();
    int getPoints() const  {
        int result = 0;
        int aces = 0;
        for (int i = 0; i < cards.size(); ++i) {
            if (cards[i]->getValue() == ACE)
                aces++;
            result += cards[i]->getValue();
        }
        while (aces > 0 && result <= 11) {
            result += 10;
            aces--;
        }
        return result;
    }
};

Card::Card(ECardSuit _suit, ECardValue _value) : suit(_suit), value(_value) {
    isCoverUp = true;
}

void Card::flip() {
    isCoverUp = !isCoverUp;
}
ECardValue Card::getValue() const {
    return value;
}

void Hand::add(Card* card) {
    cards.push_back(card);
}
void Hand::clear() {
    cards.clear();
}

class GenericPlayer : public Hand {
    string name;
public:
    GenericPlayer(const string& name) :
        name(name) { }

    virtual bool IsHitting() const = 0;

    bool IsBusted() const
    {        
        if (getPoints() > 21)
        {
            return true;
        }
        return false;
    }

    void Bust() const;
    virtual ~GenericPlayer() { } 
protected:
    string m_Name;
};

bool GenericPlayer::IsHitting() const
{
    if (getPoints() >= 21)
    {
        return false;
    }
    return true;
}


void GenericPlayer::Bust() const
{
    cout << name << " bust\n";
}


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
    friend ostream& operator<<(ostream& os, const Card& aCard);
public:
    Card(ECardSuit _suit, ECardValue _value);
    void flip();
    ECardValue getValue() const;
};

ostream& operator<<(ostream& os, const Card& aCard)
{
    const string RANKS[] = { "0", "A", "2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K" };
    const string SUITS[] = { "c", "d", "h", "s" };

    if (aCard.isCoverUp)
    {
        os << RANKS[aCard.value] << SUITS[aCard.suit];
    }
    else
    {
        os << "XX";
    }

    return os;
}


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
    string m_Name;
    vector<Card*> m_Cards;
    friend ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer);
public:
    GenericPlayer(const string& name) :
        m_Name(name) { }

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

    
};

bool GenericPlayer::IsHitting() const
{
    return (getPoints() >= 21);
}


void GenericPlayer::Bust() const
{
    cout << m_Name << " bust\n";
}

ostream& operator<<(ostream& os, const GenericPlayer& aGenericPlayer)
{
    os << aGenericPlayer.m_Name << ":\t";

    vector<Card*>::const_iterator pCard;
    if (!aGenericPlayer.m_Cards.empty())
    {
        for (pCard = aGenericPlayer.m_Cards.begin();
            pCard != aGenericPlayer.m_Cards.end();
            ++pCard)
        {
            os << *(*pCard) << "\t";
        }
        

        if (aGenericPlayer.getPoints() != 0)
        {
            cout << "(" << aGenericPlayer.getPoints() << ")";
        }
    }
    else
    {
        os << "<empty>";
    }

    return os;
}


class Player : public GenericPlayer {
    string name;
public:
    virtual bool IsHitting() const {
        bool v;
        string ch;
        cout << "One more card?(Y/N):\n";
        cin >> ch;
        v = (ch == "Y" || ch == "y");
        cout << boolalpha << v;
        return v;
    }

    void Win() const {
        cout << "Player " << name << " win!\n";
    }
    void Lose() const {
        cout << "Player " << name << " lose!\n";
    }
    void Push() const {
        cout << "Player " << name << ". Drawn game!\n";
    }
};

class House : public GenericPlayer {
    Card* cards;
public:
    virtual bool IsHitting() const {
        return (getPoints() <= 16);
    }
    void FlipFirstCard() {
        cards[0].flip();
    }
};
#include <iostream>
#include "ArrayInt.h"
#include <vector>
using namespace std;

void printVector(vector<int> &a){
	for (size_t i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int diffValues(vector<int>& a){
	int numValues = 0;
	for (int i = 0; i < a.size(); i++)
	{
		int j = 0;
		while (j < i && a[j] != a[i]) ++j;

		numValues += j == i;
	}
		return numValues;
	}



class Card {
public:
	enum rank {
		ACE = 1,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK = 10,
		QUEEN = 10,
		KING = 10
	};
	enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };
	void Flip()
	{
		m_IsFaceUp = !(m_IsFaceUp);
	}
	int GetValue() const
	{
		//если карта перевернута лицом вниз, ее значение равно О
		int value = 0;
		if (m_IsFaceUp)
		{
			value = m_Rank;
		}
		return value;
	}
// Task 3
	class Hand {
	protected:
		vector<Card*> m_Cards;
	public:
		Hand() {}
		virtual ~Hand() {
			m_Cards.clear();
		}

		void Add(Card* newCard){
			m_Cards.push_back(newCard);
		}
		void Clear() {
			m_Cards.clear();
		}
		int GetValue() {
			if (m_Cards.empty())
				return 0;
			int score = 0;
			for (int i = 0; i < m_Cards.size(); i++)
			{
				score += m_Cards[i]->GetValue();
			}
			return score;
		}
};

private:
	bool m_IsFaceUp;
	rank m_Rank;
	suit m_Suit;
};

int main()
{
// Task1
	ArrayInt arr;
	arr.insertBefore(1, 0);
	arr.insertBefore(2, 1);
	arr.insertBefore(3, 2);
	arr.insertBefore(4, 3);
	arr.insertBefore(5, 4);
	arr.print();
	cout << endl;
	cout << arr.popBack() << "\n";
	cout << "Length: " << arr.getLength();
	cout << endl;
	cout << arr.popBack() << "\n";
	cout << "Length: " << arr.getLength();
	cout << endl;
	cout << endl;
	arr.insertBefore(5, 0);
	arr.print();
	cout << endl;
	cout << arr.popFront() << "\n";
	arr.print();
	arr.insertBefore(5, 0);
	arr.insertBefore(56, 0);
	arr.insertBefore(12, 0);
	arr.print();
	cout << endl;
	arr.sort();
	arr.print();
	cout << endl;
//Task2
	vector<int>arr1 = { 1, 2, 3, 4, 5, 6, 1, 3, 5, 33, 4 };
	cout << arr1.size() << "\n";
	printVector(arr1);
	cout << "Num of unique values is " << diffValues(arr1);


	return 0;
}


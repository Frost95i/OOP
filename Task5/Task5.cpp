#include <iostream>
using namespace std;

template <class T>
class Pair1 {
	const T a;
	const T b;
public:
	Pair1(T v1, T v2) :
		a(v1), b(v2) {}

	T first() const {
		return a;
	}
	T second() const {
		return b;
	}

	~Pair1() {}
};

template <class T, class T2>
class Pair {
	const T a;
	const T2 b;
public:
	Pair(T v1, T2 v2) :
		a(v1), b(v2) {}

	T first() const {
		return a;
	}
	T2 second() const {
		return b;
	}

	~Pair() {}
};

//template<class T, class T2 >
//class StringValuePair : public Pair<T, T2> {
//public:
//
//};

template<class T2>
class StringValuePair: public Pair<string, T2> {
public:
	StringValuePair(string v1, T2 v2):
	Pair<string, T2>(v1, v2){ }
	~StringValuePair() { }
};


int main()
{
//Task1
	Pair1<int> p1(6, 9);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(3.4, 7.8);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
	cout << endl;

//Task2
	Pair<int, double> p11(6, 7.8);
	cout << "Pair: " << p11.first() << ' ' << p11.second() << '\n';

	const Pair<double, int> p12(3.4, 5);
	cout << "Pair: " << p12.first() << ' ' << p12.second() << '\n';
	cout << endl;
// Task3
	StringValuePair<int> svp("Amazing", 7);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
	return 0;
}

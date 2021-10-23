#include <iostream>
using namespace std;

class Person {
protected:
	string name;
	unsigned int age;
	string gender;
	unsigned int weight;
public:
	Person(string name, unsigned int age, string gender, unsigned int weight) :
		name(name), age(age), gender(gender), weight(weight) {}
	void setName(string name);
	void setAge(unsigned int age);
	void setWeight(unsigned int weight);

	string getName() { return name; }
	unsigned int getAge() { return age; }
	string getGender() { return gender; }
	unsigned int getWeight() { return weight; }
};

void Person::setName(string name) {
	this->name = name;
}

void Person::setAge(unsigned int age) {
	this->age = age;
}

void Person::setWeight(unsigned int weight) {
	this->weight = weight;
}

class Student : public Person {
	int yearOfStudy = 0;
	
public:
	static int studentCounter;
	Student(string name, unsigned int age, string gender, unsigned int weight) :
		Person(name, age, gender, weight)
	{
		studentCounter++;
	}
	void setYearOfStudy(int year) {
		this->yearOfStudy = year;
	}

	void incYearOfStudy() {
		this->yearOfStudy++;
	}
	int getYearOfStudy() { return yearOfStudy; }

	void showInfo() {
		cout << "Student: name-" << getName() << ", age-" << getAge() << ", gender-" << getGender() << ", weight-" << getWeight() << ", year of study-" << getYearOfStudy() << endl;
	}
	~Student(){
	studentCounter--;
}
	
};

int Student::studentCounter = 0;
class Fruit {
	string name;
	string color;
public:
	Fruit(string name, string color):
		name(name), color(color)
	{ }
	string getName() { return name; }
	string getColor() { return color; }
};

class Apple : public Fruit {
public:
	Apple(string color):
		Fruit("apple", color) {
	}
	Apple(string name, string color) :
		Fruit(name + " apple", color) {
	}
};

class Banana : public Fruit {
public:
	Banana() :
		Fruit("banana", "yellow") {
	}
};

class GrannySmith : public Apple {
public:
	GrannySmith():
	   Apple("Granny Smith", "green") { }
};

int main()
{
	// Task 1 
	Student* s0 = new Student("Anton", 20, "man", 75);
	s0->incYearOfStudy();
	s0->showInfo();
	cout << "Num of students is " << Student::studentCounter << endl;
	Student s1("Sergey", 25, "man", 80);
	s1.setYearOfStudy(4);
	s1.showInfo();
	cout << "Num of students is " << Student::studentCounter << endl;
	Student s2("Lena", 22, "woman", 60);
	s2.setName("Elena");
	s2.incYearOfStudy();
	s2.showInfo();
	cout << "Num of students is " << Student::studentCounter << endl;

	delete s0;
	cout << "Num of students is " << Student::studentCounter << endl;
	cout << endl;

	// Task 2
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
	
	return 0;
}

/*
Task 3
//---------Ввести структуру карт, включающую в себя наименование карты (2,3,4,5,6,7,8,9,10,J,Q,K,A) и кол-во очков, данной карты
struct card{
	string name;
	int point;
}

//---------Класс Blackjack:
class Blackjack{
//---------Массив колода
struct deck[13] = {c2,c3,c4,c5,c6,c7,c8,c9,c10,cJ,cQ,cK,cA};
//---------Количество колод
int numOfDecks = 6;
//---------необходимое количество очков для дилера
const int pointDealer = 17;
//---------максимальное количество очков
const int maxPoint = 21;
//--------- количество очков дилера
int dealerPoints;


public:
//---------действия игрока
void hit()
void split()
void double()
void surrender()
void stand()
void insurance()
//--------- определяем на наличие Blackjack
bool isBlackJack(card v1, card v2){}
//--------- берем карту из колоды
card takeFromDeck(){return random card}
}
//--------- класс игрок, наследуемый от класса Blackjack
class Player : public Blackjack{
//---------- сумма очков игрока
 int points;
 //--------- ставка игрока
 int bet;
}

PS возможно колоду карт нужно реализовать наподобие стэка, взяв карту из колоды сделать так, чтоб больше ее не достать.
*/
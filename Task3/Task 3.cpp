#include <iostream>
using namespace std;

const float PI = 3.1415926535;

class Figure {
public:
	virtual float area() = 0;
	virtual std::string name() { return " "; };
	virtual ~Figure() { std::cout << "Figure dc" << std::endl; }
};

class Parallelogram : public Figure {
	float a; // сторона
	float h; // высота
public:
	Parallelogram(float a, float h) {
		this->a = a;
		this->h = h;
	}
	float area() override {
		return a * h;
	}
	std::string name() { return "Parallelogram "; }
	~Parallelogram() { std::cout << "Parallelogram dc" << std::endl; }
};

class Circle : public Figure {
	float r; // радиус круга
public:
	Circle(float r) {
		this->r = r;
	}
	float area() override {
		return PI * r * r;
	}
	std::string name() { return "Circle "; }
	~Circle() { std::cout << "Circle dc" << std::endl; }
};

class Rectangle : public Parallelogram {
	float a;
	float b;
public:
	Rectangle(float a, float b) :
		Parallelogram(a, b) {
		this->a = a;
		this->b = b;
	}
	std::string name() { return "Rectangle "; }
	~Rectangle() { std::cout << "Rectangle dc" << std::endl; }
};

class Square : public Parallelogram {
	float a;
	float b;
public:
	Square(float a, float b) :
		Parallelogram(a, b) {
		this->a = a;
		this->b = b;
	}
	std::string name() { return "Square "; }
	~Square() { std::cout << "Square dc" << std::endl; }
};

class Rhombus : public Parallelogram {
	float a;
	float b;
public:
	Rhombus(float a, float b) :
		Parallelogram(a, b) {
		this->a = a;
		this->b = b;
	}
	std::string name() { return "Rhombus "; }
	~Rhombus() { std::cout << "Rhombus dc" << std::endl; }
};


 class Car {
	std::string company;
	std::string model;
public:
	Car(string company, string model) {
		this->company = company;
		this->model = model;
		cout << "Class Car.  Company: " << company << ", model: " << model << endl;
	}
	string getCompany() { return company; }
	string getModel() { return model; }
	~Car() { }
};

class PassengerCar : virtual public Car {
public:
	PassengerCar(string company, string model) :
		Car(company, model) {
		cout << "Class PassengerCar.  Company: " << company << ", model: " << model << endl;
	}
	~PassengerCar() {}
};

class Bus : virtual public Car {
public:
	Bus(string company, string model) :
		Car(company, model) {
		cout << "Class Bus.  Company: " << company << ", model: " << model << endl;
	}
	~Bus() {}
};

class Minivan : public PassengerCar, public Bus {
public:
	Minivan(string company, string model) :
		PassengerCar(company, model),
		Bus(company, model),
		Car(company, model) {
		cout << "Class Minivan.  Company: " << company << ", model: " << model << endl;
	}
	~Minivan() {}
};

class Fraction {
	int divisible;
	int divider;
public:
	Fraction(int de, int dr) {
		this->divisible = de;
		this->divider = dr;
	}
	friend Fraction operator+ (const Fraction& f1, const Fraction& f2);
	friend Fraction operator- (const Fraction& f1, const Fraction& f2);
	friend Fraction operator* (const Fraction& f1, const Fraction& f2);
	friend Fraction operator/ (const Fraction& f1, const Fraction& f2);
	friend bool operator== (const Fraction& f1, const Fraction& f2);
	friend bool operator> (const Fraction& f1, const Fraction& f2);
	friend bool operator< (const Fraction& f1, const Fraction& f2);
	friend bool operator>= (const Fraction& f1, const Fraction& f2);
	friend bool operator<= (const Fraction& f1, const Fraction& f2);
	friend bool operator!= (const Fraction& f1, const Fraction& f2);
	Fraction operator- () const {
		if (divider == 0)
			return Fraction(-1, -1);
		else if (divisible == 0)
			return Fraction(0, divider);
		else if (divisible <= 0 && divider > 0)
		{
			return Fraction(-divisible, divider);
		}
		else if (divisible > 0 && divider < 0)
		{
			return Fraction(divisible, -divider);
		}
		else if (divisible >= 0 && divider >= 0)
		{
			return Fraction(-divisible, divider);
		}
		else if (divisible <= 0 && divider < 0)
		{
			return Fraction(divisible, -divider);
		}
	}
	void showFraction() {
		cout << divisible << "/" << divider << endl;
	}
	~Fraction() {}
};

Fraction operator+(const Fraction& f1, const Fraction& f2) {
	Fraction f3(-1, -1);
	if (f1.divider == 0 || f2.divider == 0)
		return f3;
	if (f1.divider == f2.divider)
	{
		f3.divisible = f1.divisible + f2.divisible;
		f3.divider = f1.divider;
	}
	else
	{
		f3.divisible = (f1.divisible * f2.divider) + (f2.divisible * f1.divider);
		f3.divider = f1.divider * f2.divider;
	}
	return f3;
}

Fraction operator-(const Fraction& f1, const Fraction& f2) {
	Fraction f3(-1, -1);
	if (f1.divider == 0 || f2.divider == 0)
		return f3;
	if (f1.divider == f2.divider)
	{
		f3.divisible = f1.divisible - f2.divisible;
		f3.divider = f1.divider;
	}
	else
	{
		f3.divisible = (f1.divisible * f2.divider) - (f2.divisible * f1.divider);
		f3.divider = f1.divider * f2.divider;
	}
	return f3;
}

Fraction operator*(const Fraction& f1, const Fraction& f2) {
	Fraction f3(-1, -1);
	if (f1.divider == 0 || f2.divider == 0)
		return f3;
	f3.divisible = f1.divisible * f2.divisible;
	f3.divider = f1.divider * f2.divider;
	return f3;
}

Fraction operator/(const Fraction& f1, const Fraction& f2) {
	Fraction f3(-1, -1);
	if (f1.divider == 0 || f2.divider == 0)
		return f3;
	f3.divisible = f1.divisible * f2.divider;
	f3.divider = f1.divider * f2.divisible;
	return f3;
}

bool operator== (const Fraction& f1, const Fraction& f2) {
	if (f1.divider == 0 || f2.divider == 0)
		return false;
	if (f1.divider == f2.divider)
	{
		if (f1.divisible == f2.divisible)
			return true;
		else 
			return false;
	}
	else
	{
		if ((f1.divisible * f2.divider) == (f2.divisible * f1.divider))
			return true;
		else
			return false;
	}
}

bool operator> (const Fraction& f1, const Fraction& f2) {
	if (f1.divider == 0 || f2.divider == 0)
		return false;
	if (f1.divider == f2.divider)
	{
		if (f1.divisible > f2.divisible)
			return true;
		else
			return false;
	}
	else
	{
		if ((f1.divisible * f2.divider) > (f2.divisible * f1.divider))
			return true;
		else
			return false;
	}
}

bool operator< (const Fraction& f1, const Fraction& f2) {
	if (f1.divider == 0 || f2.divider == 0)
		return false;
	if (f1.divider == f2.divider)
	{
		if (f1.divisible < f2.divisible)
			return true;
		else
			return false;
	}
	else
	{
		if ((f1.divisible * f2.divider) < (f2.divisible * f1.divider))
			return true;
		else
			return false;
	}
}

bool operator>= (const Fraction& f1, const Fraction& f2) {
	if (f1 < f2)
		return false;
	else
		return true;	
}

bool operator<= (const Fraction& f1, const Fraction& f2) {
	if (f1 > f2)
		return false;
	else
		return true;
}

bool operator!= (const Fraction& f1, const Fraction& f2) {
	if (f1 == f2)
		return false;
	else
		return true;
}

// Task4
enum Suit { SUIT_SPADES, SUIT_HEARTS, SUIT_CLUBS, SUIT_DIAMONDS, };
enum Rank { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
class Card {
	Suit c_suit;
	Rank c_rank;
	bool isFace;
public:
	Card() {}
	void flip(Card& c0) {
		if (c0.isFace)
			c0.isFace = false;
		else
			c0.isFace = true;
	}
	int getValue(Card& c0) {
		if (c0.c_rank == TEN || c0.c_rank == JACK || c0.c_rank == QUEEN || c0.c_rank == KING)
			return 10;
		else if (c0.c_rank == ACE)
			return 1;
		else
			return c0.c_rank;
	}
};


int main()
{
	 //Task 1
	Figure* p0 = new Parallelogram(2, 3);
	Figure* c0 = new Circle(2.5);
	Figure* rect0 = new Rectangle(5, 7);
	Figure* s0 = new Square(10, 20);
	Figure* rhomb0 = new Rhombus(11, 12);

	Figure* arr[] = { p0, c0, rect0, s0, rhomb0 };
	for (int i = 0; i < 5; i++)
	{
		std::cout << "Area of " << arr[i]->name() << "is " << arr[i]->area() << std::endl;
		delete arr[i];
	}

	cout << endl;

	// Task 2
	Car car0("Lada", "Priora");
	PassengerCar car1("BMW", "X5");
	Bus car2("Scania", "megabuser");
	Minivan car3("Toyota", "Alphard");

	cout << endl;

	//Task 3
	Fraction f0(1, 3);
	Fraction f1(4, 5);
	Fraction f2(1, 3);
	Fraction fractionAdd = f0 + f1;
	fractionAdd.showFraction();
	Fraction fractionSub = f0 - f1;
	fractionSub.showFraction();
	Fraction fractionMul = f0 * f1;
	fractionMul.showFraction();
	Fraction fractionDiv = f0 / f1;
	fractionDiv.showFraction();
	Fraction fractionUnar = -f0;
	fractionUnar.showFraction();
	bool fractionEqual = f0 == f1;
	cout << fractionEqual << endl;
	fractionEqual = f0 == f2;
	cout << fractionEqual << endl;;
	bool fractionMore = f0 > f1;
	cout << fractionMore << endl;
	bool fractionLess = f0 < f1;
	cout << fractionLess << endl;
	bool fractionEqMore = f0 >= f1;
	cout << fractionEqMore << endl;
	bool fractionEqLess = f0 <= f1;
	cout << fractionEqLess << endl;
	bool fractionNotEqual = f0 != f1;
	cout << fractionNotEqual << endl;
	return 0;
}





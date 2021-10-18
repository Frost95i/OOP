#include <iostream>
#include <cstdint>
using namespace std;

class Power {
	float num1 = 2.0;
	float num2 = 10.0;

public:
	void set(float num1, float num2) {
		this->num1 = num1;
		this->num2 = num2;
	}
	float calculate() {
		return pow(num1, num2);
	}
};

class RGBA {
	uint8_t m_red = 0;
	uint8_t m_green = 0;
	uint8_t m_blue = 0;
	uint8_t m_alpha = 255;
public:
	RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha) :
		m_red(red), m_green(green), m_blue(blue), m_alpha(alpha) {

	}
	void print();
};

void RGBA::print() {
	cout << "RED=" << m_red << "\n";
	cout << "GREEN=" << m_green << "\n";
	cout << "BLUE=" << m_blue << "\n";
	cout << "ALPHA=" << m_alpha << "\n";
}

class Stack {
	int arr[10];
	int length;

public:
	void reset() {
		for (int i = 0; i < 9; i++)
		{
			arr[i] = 0;
		}
		length = 0;
	}

	bool push(int num) {
		if (length < 10)
		{
			arr[length] = num;
			length++;
			return true;
		}
		else {
			cout << "Stack owerflow" << endl;
			return false;
		}
	}

	void pop() {
		if (length != -1)
			arr[length--];
		else
			cout << "Stack is empty" << "\n";
	}

	void print() {
		cout << "(";
		for (int i = 0; i < length; i++)
		{
			cout << " " << arr[i] << " ";
		}
		cout << ")\n";
	}
};


int main()
{
	cout << "Task1\n";
	Power c0;
	cout << c0.calculate() << "\n";
	cout << endl;

	cout << "Task2\n";
	RGBA c1(3, 4, 5, 6);
	c1.print();
	cout << endl;

	cout << "Task3\n";
	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();


	return 0;
}

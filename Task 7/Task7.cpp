#include <iostream>
#include <ostream>
using namespace std;

class Date {
	int day;
	int month;
	int year;
public:
	Date(int d, int m, int y)
		: day{ d }, month{ m }, year{ y } {
	}
	Date() {    }

	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }

	Date(Date* a) {
		day = a->day;
		month = a->month;
		year = a->year;
	}


	friend ostream& operator<<(ostream& os, Date& d) {
		return os << '(' << d.getDay() << '.' << d.getMonth() << '.' << d.getYear() << ')' << endl;
	}

	~Date() {    }
};

template<class T>
class Auto_ptr1
{
	T* m_ptr;
public:
	// Получаем указатель для "владения" через конструктор
	Auto_ptr1(T* ptr = nullptr)
		:m_ptr(ptr)
	{
	}
	Auto_ptr1(Auto_ptr1& p)
	{
		m_ptr = p.m_ptr;
		p.m_ptr = nullptr;
	}

	Auto_ptr1& operator=(Auto_ptr1& p)
	{
		if (&p == this)
			return *this;

		delete m_ptr;
		m_ptr = p.m_ptr;
		p.m_ptr = nullptr;

		return *this;
	}
	// Деструктор позаботится об удалении указателя
	~Auto_ptr1()
	{
		delete m_ptr;
	}
	friend ostream& operator<<(ostream& os, Auto_ptr1<T>& d) {
		return os << *d;
	}
	// Выполняем перегрузку оператора разыменования и оператора ->, чтобы иметь возможность использовать Auto_ptr1 как m_ptr
	T& operator*() { return *m_ptr; }
	T* operator->() { return m_ptr; }

};


 Auto_ptr1<Date>& compares_dates( Auto_ptr1<Date>& a,  Auto_ptr1<Date>& b)
{
	if (a->getYear() > b->getYear())
		return a;
	else if (a->getYear() < b->getYear())
		return b;
	else
	{
		if (a->getMonth() > b->getMonth())
			return a;
		else if (a->getMonth() < b->getMonth())
			return b;
		else
		{
			if (a->getDay() > b->getDay())
				return a;
			else
				return b;
		}
	}
}

 void swap_dates(Auto_ptr1<Date>& a, Auto_ptr1<Date>& b)
 {
	 Auto_ptr1<Date> temp(a);
	 a = b;
	 b = temp;
 }

int main()
{
	Date dd{ 10, 10, 2010 };
	cout << dd << endl;
	Auto_ptr1<Date> today(new Date(21, 11, 2021));
	Auto_ptr1<Date> date(new Date(*today));
	cout << today->getDay() << " " << today->getMonth() << " " << today->getYear() << " " << "\n";
	cout << today << "\n";
	cout << date << "\n";

	Auto_ptr1<Date> date1(new Date(21, 11, 2021));
	Auto_ptr1<Date> date2(new Date(22, 11, 2021));
	cout << *compares_dates(date1, date2);
	cout << date1 << date2;
	cout << endl;
	swap_dates(date1, date2);
	cout << date1 << date2;

	return 0;
}

#include <iostream>
#include "BlackJack.h"
using namespace std;

template<class Char, class T >
basic_ostream<Char, T>& endll(basic_ostream<Char, T>& stream) {
    printf("\n\n");
    stream.flush();
    return stream;
}
       

int main()
{
//Task 1
        int num;
        cout << "Insert int : ";
        while (!(cin >> num) || cin.get() != '\n')
        {
            cout << "Warning!Insert INT num!\n";
            cin.clear(); 
            cin.sync();
            break;
        }
 
//Task 2
        cout << "Hello" << endll << "World!\n";

        return 0;
    }






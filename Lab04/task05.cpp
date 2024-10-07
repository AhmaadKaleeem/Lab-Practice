// Create a C++ program which takes an integer number as input and display whether the number is prime or not. This process should continue until the user enter negative number.

#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter an integer : ";
    while (true) {
        cin >> num;
        if (num < 0)
        {
            cout << "Plesse, Enter a Positive Integer.";
            return 0;
        }
        else if (num == 1)
        {
            cout << "This is not a Prime Number";
            break;
        }

        else if (num % num == 0)
        {
            cout << "This is a Prime Number.";

        }
        else {
            cout << "This is not a Prime Number";
        }
    }




}
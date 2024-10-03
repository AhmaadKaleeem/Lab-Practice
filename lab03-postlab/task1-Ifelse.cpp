#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    char operate;

    // Taking Input
    cout << "Enter Your First Number: ";
    cin >> num1;

    cout << "Enter Your Second Number: ";
    cin >> num2;

    cout << "Choose the operation you want to perform (+, -, *, /, %): ";
    cin >> operate;

    if (operate == '+' )
    {
        cout << "The sum of given numbers is: " << num1 + num2;
    }
    else if (operate == '-') {
        cout << "The difference of given numbers is: " << num1 - num2;
    }
    else if (operate == '*') {
        cout << "The product of given numbers is: " << num1 * num2;
    }
    else if (operate == '/') {
        if (num2 == 0) {
            cout << "Denominator cannot be zero. Enter a valid number !";
        }
        else {
            cout << "The result of division of given numbers is: " << num1 / num2;
              }
    }
    else if (operate == '%') {
        if (num2 == 0) {
            cout << "Denominator cannot be zero. Enter a valid number !";
        }
        else {
            cout << "The reminder of division numbers is: " << num1 % num2;
        }
    }
    
        return 0;
    }
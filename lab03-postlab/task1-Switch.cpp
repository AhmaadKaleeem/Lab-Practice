#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    char operation;

    // Taking Input
    cout << "Enter Your First Number: ";
    cin >> num1;

    cout << "Enter Your Second Number: ";
    cin >> num2;

    cout << "Choose the operation you want to perform (+, -, *, /, %): ";
    cin >> operation;

    switch (operation) {
    case '+':
        cout << "The sum of two numbers is: " << num1 + num2;
        break;

    case '-':
        cout << "The result of this subtraction is: " << num1 - num2;
        break;

    case '*':
        cout << "The product of two numbers is: " << num1 * num2;
        break;

    case '/':
        if (num2 == 0) {
            cout << "Denominator cannot be zero, Enter a valid value";
        }
        else {
            cout << "The result of this division is: " << num1 / num2;
        }
        break;

    case '%':
        if (num2 == 0) {
            cout << "Denominator cannot be zero, Enter a valid value";
        }
        else {
            cout << "The remainder of this division is: " << num1 % num2;
        }
        break;

    default:
        cout << "Invalid operation selected!";
        break;
    }

    return 0;
}

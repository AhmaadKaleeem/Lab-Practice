// Write  program to print the factorial of a number


#include <iostream>
using namespace std;

int main() {
    int input, factorial = 1;
    cout << "Enter a number : ";
    cin >> input;
    for (int i = 1; i <= input; i++)
    {
        factorial *= i;
    }
    cout << "Factorial of " << input << " is " << factorial;

}
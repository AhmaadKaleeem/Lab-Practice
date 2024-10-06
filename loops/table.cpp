// Write  program to print the multiplication table of a number entered by the user


#include <iostream>
using namespace std;

int main() {
    int input, result;
    cout << "Enter a number : ";
    cin >> input;
    for (int i = 1; i <= 10; i++)
    {
        result = input * i;
        cout << input << " x " << i << " = " << result << endl;
    }

}
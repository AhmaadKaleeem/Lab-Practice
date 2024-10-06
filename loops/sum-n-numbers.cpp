// Write a program to calculate the sum of the first n natural numbers where n is provided by the user.

#include <iostream>
using namespace std;

int main() {
    int input,result=0;
    cout << "Enter a number : ";
    cin >> input;
    for (int i = 1; i <= input; i++)
    {
        result += i;
    }
    cout << "Sum of first " << input << " numbers is " << result;




}
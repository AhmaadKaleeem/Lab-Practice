// Problem 2: Sum of Positive Numbers
// Problem: Continuously prompt the user for numbers and add only positive numbers until they enter 0 to stop.

#include <iostream>
using namespace std;

int main() {
    int num, sum = 0;
    do {

        cout << "Enter a number for sum (0 to stop) : ";
        cin >> num;
        if (num > 0) {
            sum += num;
        }
       
    } while (num != 0) ;
    cout << "Your sum is " << sum;
}
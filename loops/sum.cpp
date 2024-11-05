// Problem 1: Password Verification
// Problem: Keep asking the user to enter a password until they enter the correct one ("pass123").
//
#include <iostream>
using namespace std;

int main() {
    int num,sum=0;
    do {
        
        cout << "Enter a number for sum (0 to stop) : ";
        cin >> num;
        sum += num;
        cout << "Your sum is : " << sum; 
    } while (num != 0);
}
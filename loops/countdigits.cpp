// Write  program to print the reversed number


#include <iostream>
using namespace std;

int main() {
    int input, ld, count=0;
    cout << "Enter a number : ";
    cin >> input;
    while(input!=0)
    {
        ld = input % 10;
        count ++;
        input = input / 10;

    }
    cout << "No. of Digits" << " are " <<count;
}
   
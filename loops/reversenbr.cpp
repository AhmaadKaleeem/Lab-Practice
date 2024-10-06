// Write  program to print the reversed number


#include <iostream>
using namespace std;

int main() {
    int input, rn = 0, ld;
    cout << "Enter a number : ";
    cin >> input;
    while(input!=0)
    {
        ld = input % 10;
        rn = rn * 10 + ld;
        input = input / 10;

    }
    cout << "Reversed number : " << rn;
}
   
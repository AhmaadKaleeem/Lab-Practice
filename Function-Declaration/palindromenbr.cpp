// palindrome.cpp

#include <iostream>
using namespace  std;
void palindrome(int a) {
    int reversed=0;
    int org = a;
    while (a != 0) {
        int lastdigit = a % 10;
        reversed = reversed * 10 +lastdigit  ;
        a = a / 10;
    }
    if (reversed == org) {
        cout << "It is a Palindrome";
    }
    else {
        cout << "It is not a Palindrome";
    }
}
int main()
{
    int input;
    cout << "Enter a nbr to check : ";
    cin >> input;
    palindrome(input);
}


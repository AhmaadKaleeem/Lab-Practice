// fabonacci.cpp

#include <iostream>
#include <algorithm>
using namespace  std;
void palindrome(string a) {
    string  reversed = a;
  reverse(a.begin(), a.end());
  if (reversed == a) {
      cout << "It is a Palindrome"; 
  }
  else {
      cout << "It is not a Palindrome";
  }
}
int main()
{
    string input;
    cout << "Enter a sentence to check : ";
  cin>> input;
    palindrome(input);
}


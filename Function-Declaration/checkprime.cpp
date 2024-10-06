
#include <iostream>
using namespace  std;
// using void because output is only a text
void prime(int a) {
    if (a % 2 != 0)
    {
        cout << "Yes, It is a prime number.";
    }
    else
    {
        cout << "No, It is not a prime number.";
    }
}
int main()
{
    int input;
    cout << "Enter a number : ";
  cin>> input;
  prime(input);
}


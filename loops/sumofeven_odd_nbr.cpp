// Write a program to calculate the sum of the first n natural numbers where n is provided by the user.

#include <iostream>
using namespace std;

int main() {
    int input,odd=0,even=0;
    cout << "Enter a number : ";
    cin >> input;
    for (int i = 1; i <= input; i++)
    {
      if(i%2==0){
          even +=i;
      }
      else {
        odd += i;
      }
    }
    cout << "Sum of odd number between 1 and " << input << " is " << odd <<endl;
    cout << "Sum of even number between 1 and " << input << " is " << even;




}
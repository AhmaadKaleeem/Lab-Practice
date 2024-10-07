// Task#3: Take 10 integers from keyboard using loop and print their average value on the screen.
#include <iostream>
using namespace std;
int main()
{
    int num1, result = 0;
    float average;
    cout << "Enter 10 integer values : ";
   
   for (int a = 1; a <=10; a++)
    {
     
       
       cin >> num1;
     
      result += num1;

    }
   average = result / 10;
   cout << "The Average of given 10 values is " << average;


}


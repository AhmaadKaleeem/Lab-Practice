// Create a C++ program which takes an integer number as input and display whether the number is prime or not. This process should continue until the user enter negative number.

#include <iostream>
using namespace std;

int main() {
    int num,isprime=1;
    cout << "Enter an Integer : ";
    cin >> num;
    if (num < 0)
    {
        cout << "Plesse, Enter a Positive Integer.";
        return 0;
    }
    else if (num == 1)
    {
        cout << num << " is not a Prime Number";
        return 0;
    }
     
    for (int i = 2; i <= num/2; i++)
{
            if (num % i == 0)
            {
                isprime = 0;
                break;
            }
            
   
}
           if (isprime == 1)
           {
               cout << num << " is a Prime Number";
           }
           else 
           {
               cout << num << " is not a Prime Number";
           }

    

}


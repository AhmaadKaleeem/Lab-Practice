// Write a C++ program which takes five numbers from the user and finds the largest of these numbers. Your output should be as below.//
#include <iostream>
using namespace std;

int main () {
                int num1,num2,num3,num4,num5;
cout << "Enter the First Number : ";
   cin >> num1;
cout << "Enter the Second Number : ";
   cin >> num2;
cout << "Enter the Third Number : ";
   cin >> num3;
cout << "Enter the Fourth Number : ";
   cin >> num4;
cout << "Enter the Fifth Number : ";
   cin >> num5;
cout << "You have Entered " << num1 << " " << num2 << " " << num3 << " " << num4 << " " << num5
<< " as First , Second , Third , Fourth and Fifth Number Respectively. " << endl << endl ;
   if (num5 > num1 && num5 > num2 && num5 > num3 && num5 > num4 ) 
   {
cout << " Fifth Number  is Greater ";
   }
   else if (num4 > num1 && num4 > num2 && num4 > num3 && num4 > num5)
   {
cout << "Fourth Number is Greater";
    }        
   else if (num3 > num1 && num3 > num2 && num3 > num4 && num3 > num5)
   {
cout << "Third Number is Greater";
    }
    else if (num2 > num1 && num2 > num3 && num2 > num3 && num2 > num5)
   {
cout << "Second Number is Greater";
    }      
     else if (num1 > num4 && num1 > num2 && num1 > num3 && num1 > num5)
   {
cout << "First Number is Greater";
    }   
     
}
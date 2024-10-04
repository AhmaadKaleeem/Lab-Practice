/* Write a C++ program which takes a character input from user and tells if it is a digit or not.  If it is not a digit, your program should tell if it is an alphabet or
not. If it is an alphabet, your program should tell if it is uppercase or lowercase. If it is not an alphabet, your
program should print “It is a special symbol”. The output of your program should be as below.  */

#include<iostream>
using namespace std;
int main() {
               char inputt;
               int digit;
    cout << "Enter a value : ";
    cin >> inputt;
    if (isdigit(inputt)) //isdigit is a function used to check if charcter is a digit

       {

        cout << inputt << " is a digit." << endl;
        digit = inputt;
        if (digit % 2 == 0) 

        {  cout << "It is an even digit." << endl; }

        else

        { cout << "It is an odd digit." << endl; }

       }
       
        else if (isalpha(inputt)) //isalpha check weather the char is an alphabat
       {  
            
          cout << inputt << " is an alphabet." << endl;     

        if (isupper(inputt)) //to check that the alphabat is in upper case

        {  cout << "It is an uppercase letter." << endl; }

        else 
        {  cout << "It is a lowercase letter." << endl;  }

        }
        
        else 
        { cout << "It is a special symbol." << endl; }


 }
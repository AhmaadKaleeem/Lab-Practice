// Project: Number Pyramid Generator
#include <iostream>
using namespace std;
int main() {
	// Declaring two variables for input of rows and type of pyramid
	int rows, type;
	// Taking Inputs
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Enter the Number of Rows > ";
	cin  >> rows;
	// Taking Positive Row Numbers
	if (rows <= 0)
	{
		cout << "Inavlid Input ! Select a Valid Range of Positive Numbers";
		return 0;
	}

	cout << endl;
    cout << "Select a type of pyramid you want to create  ";
	cout << "\n" << "1 - Pyramid" << "\n" << "2 - Iverted Pyramid" << "\n" << "3 - Triangle" << "\n";
	cout << endl; 
	cout << "Please, Enter the type > ";
	cin  >> type;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	
	// Using if else and loops to print desired pattern 
	// Pyramid (Type 1)

	if(type == 1) {
		    for (int i = 1; i <= rows; i++) {
			for (int j = 1; j <= rows - i; j++) {
				cout << " ";
			}
			for (int j = 1; j <= i; j++) {
				cout << j;
			}
			for (int j = i - 1; j >= 1; j--) {
				cout << j;
			}
			cout << endl;

		}
	}

	// Inverse Pyramid (Type 2)

	else if (type == 2) {
		    for (int i = 1; i <= rows; i++) {
			for (int j = 1; j <= i-1 ; j++) {
				cout << " "; // Leading spaces
			}
			for (int num = rows - i + 1; num >= 1; num--) {
				cout << num; // First half (decreasing order)
			}

			for (int num = 2; num <= rows - i + 1; num++) {
				cout << num; // Second half (increasing order)
			}
			cout << endl;

		}
	}

	// Triangle (Type 3)
			
	else if (type == 3)
	{
		    for (int i = 1; i <= rows; i++) {
			for (int j = 1; j <= i; j++)
			
				cout << j;
				}
			cout << endl;
		
	}
 
	else {
		 cout << "\t\tInvalid Input! Select a Valid Pyramid Type (1, 2, or 3).";
	     return 0;
	}
}


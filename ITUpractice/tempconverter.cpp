//Write a program that converts a temperature from Celsius to Fahrenheit or Fahrenheit to Celsius based on user input.The formula for the conversions are :
// From Celsius to Fahrenheit : F = (C * 9 / 5) + 32
// From Fahrenheit to Celsius : C = (F - 32) * 5 / 9

#include <iostream>
using namespace std;
int main() {
	int choice, c, f;
	// Making a small interference
	cout << "------------------------------------------------------------------------------" << "\n";
	cout << "\t\t" << " Welcome To Temperature Converter " << "\n";
	cout << "------------------------------------------------------------------------------" << "\n";
	// asking for conversion type
	cout << "\t\t" << "    Choose Your Conversion Type     " << "\n" << endl;
	cout << "1. Celsius to Fahrenheit" << endl << "2. Fahrenheit to Celsius " << endl << "\n";
	cout << "Please Enter Your Choice : ";
	cin >> choice;
	cout << endl;

	// Coversions
	if (choice == 1)
	{
		cout << "Enter the Temperature in Celsius : ";
		cin >> c;
		cout << endl;
		f = (1.8 * c) + 32;
		cout << "The Temperature in Fahrenheit is " << f;
	}
	if (choice == 2)
	{
		cout << "Enter the Temperature in Fahrenheit : ";
		cin >> f;
		c = 0.55 * (f - 32);
		cout << "The Temperature in Celsius is " << c;
	}	
}
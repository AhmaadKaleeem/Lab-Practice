// Write a program in C++ that will take radius of a sphere from the user. Calculate the Volume of sphere in a Function and display its value in main function

#include <iostream>
using namespace std;

// Declaring Function
double volume(double a) {
	const float pi = 3.1415;
	double resultt = (4.0 / 3.0) * pi * ( a * a * a);
	return (resultt);
}

int main()
{
	double radius; double result;
	// Making Interface & Taking Input
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Enter the Radius of Sphere : ";
	cin >> radius;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

	// Calling Function and Calculating Volume
	result = volume(radius);
	cout << "The Volume of a Sphere is : " << result;




}
// Write a program in C++ that contains a function to calculate third angle of triangle. The program should take two angles from user.

#include <iostream>
using namespace std;
int angle3(int angle1, int angle2) {
	int calculate = 180 - (angle1 + angle2);
	return (calculate);
}
int main()
{
	// Taking Input
	int angle1, angle2, result;

	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;
	cout << "Enter the first angle : ";
	cin >> angle1;
	cout << "Enter the second angle:  ";
	cin >> angle2;
	cout << "-----------------------------------------------------------------------------------------------------------------------" << endl;

	// Calling Third Angle Function
	result = angle3(angle1, angle2);
	cout << "The third angle is : " << result;

}
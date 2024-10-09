//Write a program that checks whether a given year is a leap year or not.A leap year is : 1) Divisible by 4. 2)Not divisible by 100 unless it is also divisible by 400.

#include <iostream>
using namespace std;
int main() {
	int year;
	cout << "Please Enter a Year : ";
	cin >> year;
	if (year % 4 ==0)
	{
		cout << year << " is a Leap Year";
	}
	else if (year % 100 ==0 && year % 400 ==0)
	{
		cout << year << " is a Leap Year";
	}
	else {
		cout << year << " is not a Leap Year";
	}
}
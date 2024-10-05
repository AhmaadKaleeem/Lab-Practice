#include <iostream>
using namespace std;
int max(int a, int b) {
	if (a > b) 
	{ return (a); }
	else 
	{ return (b); }
}
int main()
{
	int number1, number2, check;
	cout << "Enter first number : ";
	cin >> number1;
	cout << "Enter second number : ";
	cin >> number2;
	check = max(number1, number2);
	cout << "The larger value is : " << check;
}
#include <iostream>
using namespace std;
int sum(int a, int b) {
	return (a + b);
}
int main()
{
	int number1, number2, result;
	cout << "Enter first number : ";
	cin >> number1;
	cout << "Enter second number : ";
	cin >> number2;
	result = sum(number1, number2);
	cout << "The Sum of " << number1 <<" and " <<number2 << " is " << result;

}
#include <iostream>
using namespace std;
int factorial (int a) {
	int result = 1;
	for (int f=1; f <= a; f++) {
		result *= f;
	}
	return (result);
}
int main()
{
	int number; int factorial_r;
	cout << "Enter a number : ";
	cin >> number;
	factorial_r = factorial(number);
	cout << "The Factorial of " << number << " is " << factorial_r;

}
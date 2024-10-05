#include <iostream>
using namespace std;
int square(int a) {
	return (a * a);
}
int main()
{
	int number; int result;
	cout << "Enter a number : ";
	cin >> number;
	result = square(number);
	cout << "The Square of " << number << " is " << result;




}
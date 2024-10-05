#include <iostream>
using namespace std;
bool iseven(int a) {
	if (a % 2 == 0) {
		return  true;
	}
	else {
		return  false;
	}
}
int main()
{
	int number; int result;
	cout << "Enter a number : ";
	cin >> number;
	if (iseven(number)) {
		cout << "Number is Even";
	}
	else {
		cout << "Number is Odd";
	}
}
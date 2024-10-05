#include <iostream>
using namespace std;
float c_to_f(float a) {
	return (1.8 * a + 32);
}
int main()
{
	float temp, result;
	cout << "Enter the temperature in Celsuis : ";
	cin >> temp;
	result = c_to_f(temp);
	cout << "The temperature in Fahrenheit is : " << result;
}
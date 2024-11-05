/* Problem 2: Correct the Swap Logic
Code:
#include <iostream>
using namespace std;
int main()
{
	int  a, b, c,temp;
	cout << "Enter 3 Numbers ";
	cin >> a >> b >> c;
	cout << "Before Swapping : a = " << a << ", b = " << b << ", c = " << c << endl;
	 a = b;
	 b = c;
	 c = a;
	 cout << "After Swapping : a = " << a << ", b = " << b << ", c = " << c << endl;
}*/
#include <iostream>
using namespace std;
int main()
{
	int  a, b, c,temp;
	cout << "Enter 3 Numbers ";
	cin >> a >> b >> c;
	cout << "Before Swapping : a = " << a << ", b = " << b << ", c = " << c << endl;
	temp = a;
	 a = b;
	 b = a;
	 b = c;
	 c = temp;
	
	 cout << a << "\t" << b << "\t" << c;
}
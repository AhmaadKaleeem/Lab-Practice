#include <iostream>
#include <algorithm> //To use swap function
using namespace std;

void sum(int a, int b)
{
	int even=0, odd=0;
	// Using swap so that loop work prefectly
	if (b > a) {
		swap(b, a);
	}

	for (int i = b; i < a; i++)
	{
		if (i % 2 == 0) {
			even += i;
			
		}
		else if (i % 2 != 0) {
			odd += i;
			
		}
		
	}
	cout << "The sum of even is : " << even << endl;
	cout << "The sum of odd is : " << odd;

}

int main()
{
	int a, b;
	cout << "Enter a number : ";
	cin >> a;
	cout << "Enter another number : ";
	cin >> b;
	
	sum(a, b);
	
}
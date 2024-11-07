
#include <iostream>
using namespace std;

int main() {
    int num,sum=0;
    do {
        
        cout << "Enter a number for sum (0 to stop) : ";
        cin >> num;
        sum += num;
        cout << "Your sum is : " << sum; 
    } while (num != 0);
}
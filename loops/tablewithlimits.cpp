// Write  program to print the multiplication table of a number entered by the user


#include <iostream>
using namespace std;

int main() {
    int input, start, limit, result;
    cout << "Enter a number : ";
    cin >> input;
    cout << "Enter limit for table : ";
    cin >> limit;
    cout << "Enter a number from where the table starts : ";
    cin >> start;

    for (int i = start; i <= limit; i++)
    {
        result = input * i;
        cout << input << " x " << i << " = " << result << endl;
    }

}
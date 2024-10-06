// fabonacci.cpp

#include <iostream>
using namespace std;
int fibonacci(int a) {
    if (a == 0) {
        return 0;
    }
    else if (a == 1) {
        return 1;
    }
    else {
        int result = fibonacci(a - 1) + fibonacci(a - 2);
        return result;

    }
}
int main()
{
    int num, resultt;
    cout << "Enter a number : ";
    cin >> num;
    resultt = fibonacci(num);
    cout << "The values is : " << resultt;
}


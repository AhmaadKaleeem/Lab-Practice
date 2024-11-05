/* Problem 2: Correct the Function Logic
Code:
#include <iostream>
using namespace std;

void multiply(int a, int b) {
    int result;
    result = a * b;
    // Missing output
}

int main() {
    multiply(3, 4);
    return 0;
} */

// Corrected Code
#include <iostream>
using namespace std;

void multiply(int a, int b) {
    int result;
    result = a * b;
    cout << "The Product of " << a << " and " << b << " = " << result;
   
}

int main() {
    multiply(3, 4);
    return 0;
}
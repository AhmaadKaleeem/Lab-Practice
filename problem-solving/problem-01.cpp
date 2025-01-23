/* Problem 1: Find the Syntax Error
Code:
#include <iostream>
using namespace std;
int main() {
    int a = 5, b = 10
    cout << "Sum of a and b is: " << a + b << endl;
    return 0;
    }
} */

// Corrected Code

#include <iostream>
using namespace std;
int main() {
    int a = 5, b = 10;
    cout << "Sum of a and b is: " << a + b << endl;
    return 0;
}
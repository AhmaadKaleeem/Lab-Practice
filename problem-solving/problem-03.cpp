/* Problem 3: Debug the Conditional Check
Code:

#include <iostream>
using namespace std;

void checkEven(int number) {
    if (number = 0) {
        cout << number << " is even." << endl;
    } else {
        cout << number << " is odd." << endl;
    }
}

int main() {
    checkEven(5);
    return 0;
}  */

// Corrected Code
#include <iostream>
using namespace std;

void checkEven(int number) {
    if (number % 2 == 0) {
        cout << number << " is even." << endl;
    } else {
        cout << number << " is odd." << endl;
    }
}

int main() {
    checkEven(5);
    return 0;
}
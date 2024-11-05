/* Problem 4: Fix the Return Issue
Code:
#include <iostream>
using namespace std;

int square(int n) {
    n * n;
}

int main() {
    int result = square(5);
    cout << "Square is: " << result << endl;
    return 0;
} */

// Corrected Cpde
#include <iostream>
using namespace std;

int square(int n) {
    return (n * n);
}

int main() {
    int result = square(5);
    cout << "Square is: " << result << endl;
    return 0;
}
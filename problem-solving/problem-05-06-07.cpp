/* Problem 6: Correct the Parameter Mismatch
Code:  #include <iostream>
using namespace std;
void printMessage(string msg) {
    cout << msg << endl;
}
int main() {
    printMessage(); // Missing argument
    return 0;
} */

// Corrected Code 
#include <iostream>
using namespace std;
void printMessage(string msg) {
    cout << msg << endl;
}
int main() {
    string hello = "Hi";
    printMessage(hello); // Missing argument
    return 0;
}

/* Problem 7: Fix the Scope Issue
Code:  #include <iostream>
using namespace std;
int add(int a, int b) {
    int sum = a + b;
}
int main() {
    cout << "Sum is: " << sum << endl; // Using sum outside of its scope
    return 0;
}*/

// Corrected Code 
#include <iostream>
using namespace std;
int add(int a, int b) {
    int sum = a + b;
    return sum
}
int main() {
    int a =5,b=15,sum;
    sum = add(5,15);
    cout << "Sum is: " << sum << endl; // Using sum outside of its scope
    return 0;
}

/* Problem 8: Debug the Function Call
Code:
#include <iostream>
using namespace std;

void greet() {
    cout << "Hello, World!" << endl;
}
int main() {
    greeting(); // Incorrect function name
    return 0;
}
*/
// Corrected Code 
#include <iostream>
using namespace std;

void greet() {
    cout << "Hello, World!" << endl;
}
int main() {
    greet(); // Incorrect function name
    return 0;
}
#include <iostream>
using namespace std;

void palindrome(string str) {
    string reversed = "";

    // Reverse the string manually
    for (int i = str.length() - 1; i >= 0; i--) {
        reversed += str[i];
    }

    // Compare the original and reversed strings
    if (str == reversed) {
        cout << "It is a Palindrome";
    }
    else {
        cout << "It is not a Palindrome";
    }
}

int main() {
    string input;
    cout << "Enter a string to check: ";
    cin >> input;
    palindrome(input);
}

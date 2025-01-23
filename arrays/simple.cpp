#include <iostream>
using namespace std;

int main() {
    int n = 9; // Maximum number at the center row

    // Upper half including the center row
    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // Print increasing numbers
        for (int j = 1; j <= i; j++) {
            cout << j;
        }

        // Print decreasing numbers
        for (int j = i - 1; j >= 1; j--) {
            cout << j;
        }

        cout << endl;
    }

    // Lower half excluding the center row
    for (int i = n - 1; i >= 1; i--) {
        // Print leading spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // Print increasing numbers
        for (int j = 1; j <= i; j++) {
            cout << j;
        }

        // Print decreasing numbers
        for (int j = i - 1; j >= 1; j--) {
            cout << j;
        }

        cout << endl;
    }

    return 0;
}

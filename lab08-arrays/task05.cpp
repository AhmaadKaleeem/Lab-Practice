#include <iostream>
using namespace std;

int main() {
    int array[10] = {5, 12, 7, 9, 3, 15, 8, 1, 14, 10};
    int search;

    cout << "Enter the element to search: ";
    cin >> search;

    for (int i = 0; i < 10; i++) {
        if (array[i] == search) {
            cout << "Element found at index " << i << endl;
            return 0;
        }
    }

    cout << "Element not found in the arrayay." << endl;
    return 0;
}
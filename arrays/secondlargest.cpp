#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 55, 40, 15};
    int maxvalue = INT_MIN;
    int secmax = INT_MIN;

    for (int i = 0; i < 5; i++) {
        if (arr[i] > maxvalue) {
            secmax = maxvalue;
            maxvalue = arr[i];
        } else if (arr[i] > secmax && arr[i] != maxvalue) {
            secmax = arr[i];
        }
    }
    
    cout << "The 2nd maximum value is: " << secmax << endl;

    return 0;
}
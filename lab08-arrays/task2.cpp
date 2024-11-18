#include <iostream>
using namespace std;

int main() {
    int arr[5] = {10, 20, 55, 40, 15};
    int maxvalue = arr[0];
    int minvalue = arr[0];

    for (int i = 1; i < 5; i++) {
        if (arr[i] > maxvalue) {
            maxvalue = arr[i];
            }
        if (arr[i] < minvalue) {
            minvalue = arr[i];
        }
    }
    cout << "The maximum value  is : " << maxvalue << endl;
    cout << "The maximum value  is : " << minvalue << endl;

    return 0;
}

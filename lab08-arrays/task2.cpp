#include <iostream>
using namespace std;

int main() {
    int arr[5] = {18, 20, 55, 40, 15};
    int maxvalue = arr[0] ;
    int minvalue = arr[0];

    for (int i = 1; i < 5; i++) {
        if (arr[i] > maxvalue) { // 1 - 20   
            maxvalue = arr[i]; //20
            }
        if (arr[i] < minvalue) {
            minvalue = arr[i];
        }
    }
    cout << "The maximum value  is : " << maxvalue << endl;
    cout << "The manimum value  is : " << minvalue << endl;

    return 0;
}

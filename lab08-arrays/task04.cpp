#include <iostream>
using namespace std;

int main() {
    int arr[10] = {5, 7, 10, 15, 20, 25, 30, 35, 40, 45};

    int sum = 0;
    float average;

    // Calculate sum of given integers in array
    for (int i = 0; i < 10; i++) {
        sum += arr[i];
    }

    // Calculate average
    average = sum / 10.0;

    // Output results
    cout << "Sum is equal to : " << sum << endl;
    cout << "Average is equal to : " << average << endl;

    return 0;
}

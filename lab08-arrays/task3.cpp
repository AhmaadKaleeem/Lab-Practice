#include <iostream>
using namespace std;

void reverseArray(int arr[], int size) {
    for (int i = size-1; i >=0 ; i--) {
      cout << arr[i] << " ";
    }
}


int main() {
  
    int arr[6] = {10, 22, 63, 4, 5, 6};

    cout << "The Original Array is : ";
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "The Reversed Array is :";
    reverseArray(arr, 6);
  
}

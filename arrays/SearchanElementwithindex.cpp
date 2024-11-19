

// arrays
#include <iostream>
using namespace std;

int main()
{
int search;
cout << "Enter the number you want to search: ";
cin >> search;
 int x[5] = {1,2,30,4,5};
 for (int i =0;i<=4;i++){
    if (x[i]==search){
        cout << "The index is given as : " << i;
    }
 }
}
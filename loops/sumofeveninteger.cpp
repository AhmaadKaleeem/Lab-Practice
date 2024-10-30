// Sum of even integer with human defined range

#include <iostream>
using namespace std;

int main() {

    int input,input2,sum=0;
    cout << "Enter starting number : ";
    cin >> input;
    cout << "Enter ending number : ";
    cin >> input2;
    while(input<input2)
    {
        if (input % 2 ==0){
        sum += input;
        }
       
        input++;
        
    }
    cout << "Sum : " << sum;
}
   
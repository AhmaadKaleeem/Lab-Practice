#include <iostream>
using namespace std;
void fizzBuzz(int n) {
 for (int i=1 ; i<=n ;i++){
     
    if (i%3==0 && i % 5==0){
        cout << "Fizz Buzz";
    } 
    
 }
}
int main() {
    int n;
    cout << "Enter Limit : ";
    cin >> n;
    fizzBuzz(n);
     }
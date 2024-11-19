// Count Even and Odd Numbers
// arrays
#include <iostream>
using namespace std;

int main()
{
int even=0;
int odd=0;
  int x[5] = {1,2,30,4,5};
 for (int i =0;i<=4;i++){
    if (x[i]%2==0){
       even++;
    }
    else {
        odd++;
    }
 }
cout << even << " " << odd;
}
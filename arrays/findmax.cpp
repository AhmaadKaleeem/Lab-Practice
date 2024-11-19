// arrays
#include <iostream>
using namespace std;

int main()
{
int max=0;
  int x[5] = {1,2,30,4,5};
 for (int i =0;i<=4;i++){
    if (x[i]>max){
        max=x[i];
    }
 }
cout << max;
}
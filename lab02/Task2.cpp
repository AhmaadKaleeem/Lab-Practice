#include <fstream>
#include <iostream>
using namespace std;

int main()
{ 
    ofstream outfile;
    outfile.open("Lab 02.txt");
    outfile << "The rose is red.\n" << "A girl is playing there.\n" << "There is a playground.\n" << 
"An aeroplane is in the sky.\n" << "Numbers are not allowed in the password.\n" ;  ;
//Output Text
    cout << "The rose is red.\n" << "A girl is playing there.\n" << "There is a playground.\n" << 
"An aeroplane is in the sky.\n" << "Numbers are not allowed in the password.\n" ; 
    outfile.close();
    return 0;
} 

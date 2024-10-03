#include <fstream>
#include <iostream>
using namespace std;

int main()
{ 
    ofstream outfile;
    outfile.open("Ahmadd.txt", ios::app);
    if (outfile.is_open())
    {
        outfile << "This is new data that is appended" << endl;
        outfile << "\n";
        outfile << "This is also data";
        cout << "Your data is successfully added";
        outfile.close();
    }
    else {
        "Sorry, Cannot Find The Required File";
    }
    
    } 

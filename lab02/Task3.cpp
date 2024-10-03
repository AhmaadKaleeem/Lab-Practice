#include <fstream>
#include <iostream>
using namespace std;
int main() {

ifstream infile, infile1; // For reading
ofstream outfile; // For writing
fstream f1;
// Opening all the files
infile.open("Lab 01.txt");
infile1.open("Lab 02.txt");
outfile.open("Lab 03.txt");
string line;
// Checking the 1st file to be opened
if (infile.is_open()){
    while(getline(infile,line))
    {  
        outfile << line <<endl; 
        outfile <<"\n";
    }
    infile.close();
}
else {
    cout << "Sorry, There is an error in opening the file (lab01) !";
    }
// Checking the 2nd file to be opened
if (infile1.is_open()){
    while(getline(infile1,line))
    {  
        outfile << line <<endl; 
    }
    infile1.close();
}
else{ 
    cout << "Sorry, There is an error in opening the file (lab 02) !";
    }
    outfile.close();
    string output1;
cout<< "Your have successfully merged your file :> ""\n" ;

}


#include <fstream>
#include <iostream>
using namespace std;

int main()
{ 
    ofstream outfile;
    outfile.open("Lab 01.txt");
    outfile << "Abdullah ibn Mas'ud reported: The Messenger of Allah, peace and blessings be upon hím,said,"
    <<"\"Most of the sins of the children of Adam are on their tongues.\"" << endl <<"\n" <<
    "Ibn Mas'ud said, ""O tongue! Speak goodness and be rewarded, or remain silent and be safe, lest you become regretful." << endl << "\n"
    "Source: al-Mu'jam al-Kabir 10300" ;
    cout << "Abdullah ibn Mas'ud reported: The Messenger of Allah, peace and blessings be upon hím,said,"
    <<"\"Most of the sins of the children of Adam are on their tongues.\"" << endl <<"\n" <<
    "Ibn Mas'ud said, ""O tongue! Speak goodness and be rewarded, or remain silent and be safe, lest you become regretful." << endl << "\n"
    "Source: al-Mu'jam al-Kabir 10300" ;
    outfile.close();
} 

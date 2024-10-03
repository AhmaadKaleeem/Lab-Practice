// Write a C++ program which generates Grades for students depending on their Scores. //
// (85 -100, Grade is ‘A') (72 - 84, Grade is ‘B’) (60 - 71, Grade is ‘C’)  (50 - 59, Grade is ‘D’) (0 - 49, Grade is ‘F’) //

// Requirement : Use Switch Case //
#include <iostream>
using namespace std ;
int main() {
	int score;
	cout << " Enter the Student Score : ";
	cin >> score;
	switch (score / 10)
    {
        case 10:
        case  9:
                 cout << " The Student Passed in \"A\" Grade";
                 break;
        case  8: 
            if (score >= 85 ) {
                 cout << " The Student Passed in \"A\" Grade";
                              }
            else {
                cout << " The Student Passed in \"B\" Grade";
            }
                 break;

        case  7:
             if (score >= 72 ) {
                 cout << " The Student Passed in \"B\" Grade";
                              }
            else {
                cout << " The Student Passed in \"C\" Grade";
            }
                 break;
        case  6:
                 cout << " The Student Passed in \"C\" Grade";
                 break;
        case  5:
                cout << " The Student Passed in \"D\" Grade";
                 break; 
        case  4: 
        case  3:
        case  2:
        case  1:
        case  0:
                cout << " The Student Failed with \"F\" Grade";
	}
         if (score <0 && score >100) {
        cout << "Invalid Score was entered. No Grade can be generated";
         }
}
       

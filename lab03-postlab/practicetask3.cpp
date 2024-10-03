// Write a C++ program which generates Grades for students depending on their Scores. //
// (85 -100, Grade is ‘A') (72 - 84, Grade is ‘B’) (60 - 71, Grade is ‘C’)  (50 - 59, Grade is ‘D’) (0 - 49, Grade is ‘F’) //

// I used std instead of using namespace std , you can use that //
#include <iostream>
int main() {
	int score;
	std::cout << " Enter the Student Score : ";
	std::cin >> score;
	if (score >= 85 && score <= 100) {
		std::cout << " The Student Passed in \"A\" Grade" ;
	}
	else if (score >= 72 && score <= 84) {
		std::cout << " The Student Passed in \"B\" Grade";
	}
	else if (score >= 60 && score <= 71) {
		std::cout << " The Student Passed in \"C\" Grade";
	}
	else if (score >= 50 && score <= 59) {
		std::cout << " The Student Passed in \"D\" Grade";
	}
	else if (score >= 0 && score <= 49) {
		std::cout << " The Student Failed with \"F\" Grade";
	}
	else  {
		std::cout << " Invalid Score was entered. No Grade can be generated ";
	}

}
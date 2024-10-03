
#include <iostream>
int main() {
	int marks;
	std::cout << "Your your marks : ";
	std::cin >> marks;
	if (marks > 80) {
		std::cout << "Congrats ! You Have Got \"A\" Grade" ;
	}
	else if (marks >60 && marks<=80) {
		std::cout << "Congrats ! You Have Got \"B\" Grade";
	}
	else if (marks > 50 && marks <= 60) {
		std::cout << "Congrats ! You Have Got \"C\" Grade";
	}
	else if (marks > 45 && marks <= 50) {
		std::cout << "Congrats ! You Have Got \"D\" Grade";
	}
	else if (marks > 25 && marks <= 45) {
		std::cout << "Congrats ! You Have Got \"E\" Grade";
	}
	else  {
		std::cout << "You Have Got \"F\" Grade";
	}

}
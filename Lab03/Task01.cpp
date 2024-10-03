#include <iostream>
int main() {
	int salary, service, bonus;
	std::cout << "Enter Your Salary : ";
	std::cin >> salary;
	std::cout << "Enter Your Total Years of Service : ";
	std::cin >> service;
	if (service <= 5) {
		std::cout << "You are not eligible for bonus";
	}
	else {
		bonus = (salary * 5 / 100);
		std::cout << "Your bonus is Rs. " << bonus << std::endl;
	}


}
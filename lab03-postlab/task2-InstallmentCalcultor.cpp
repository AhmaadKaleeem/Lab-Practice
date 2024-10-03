// Let's Calculate Installments
#include <iostream>

int main() {
    // Declaring Variables
    int t_cost, downpay, rem_amount, months;
    // Taking Input From User
    std::cout << "\tCalculate your Monthly Installments  " << std::endl << std::endl;
    std::cout << "Enter total cost of car :  ";
    std::cin >> t_cost;
    std::cout << std::endl;
    std::cout << "Enter the paid down payment :  ";
    std::cin >> downpay;
    std::cout << std::endl;
    std::cout << "Enter No. of months :  ";
    std::cin >> months;
    std::cout << std::endl;
    // Calculating Remaining Amount
    rem_amount = t_cost - downpay;
    // Calculating Monthly Installment
    if (months <= 12) {
        std::cout << "Your Monthly Installment is Rs. " << (rem_amount + (rem_amount * 0.1)) / months << std::endl;
    }
    else if (months > 12 && months <= 24) {
        std::cout << "Your Monthly Installment is Rs. " << (rem_amount + (rem_amount * 0.15)) / months << std::endl;
    }
    else if (months > 24 && months <= 36) {
        std::cout << "Your Monthly Installment is Rs. " << (rem_amount + (rem_amount * 0.2)) / months << std::endl;
    }
    else if (months > 36 && months <= 48) {
        std::cout << "Your Monthly Installment is Rs. " << (rem_amount + (rem_amount * 0.25)) / months << std::endl;
    }
    else if (months > 48 && months <= 60) {
        std::cout << "Your Monthly Installment is Rs. " << (rem_amount + (rem_amount * 0.3)) / months << std::endl;
    }
    else if (months > 60) {
        std::cout << "Sorry! Your Installment Months Cannot Exceeed 60 Months " << std::endl;
    }
}
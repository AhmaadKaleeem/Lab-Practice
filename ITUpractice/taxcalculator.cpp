#include <iostream>
int main() {
    // Taking Input From User
    int income;
    std::cout <<"\t\tTax Calculator 2024\n";
    std::cout <<"Enter Your Annual Income : Rs.  ";
    std::cin >>income;
    // Calculating Tax and Showing Net Income
    int limit1 , limit2 , limit3 , limit4, limit5;
    limit1 = 600000, limit2 = 1200000, limit3 = 2200000, limit4 = 3200000, limit5 = 4100000;
    int yearlytax1, yearlytax2, yearlytax3, yearlytax4, yearlytax5 ;

    if (income <=600000) {
        std::cout<<"\tTax\n";
        std::cout <<"Your Annual Tax is : Rs." <<0; // No Tax 
        std::cout <<"Your Monthly Tax is : Rs." <<0;
        std::cout<<"\tNet Income\n";
        std::cout << "Your Net Income Annualy is: Rs." << income<< std::endl;
        std::cout << "Your Net Income Monthly is: Rs." << income/12 << std::endl;
    }
    else if (income >600000 && income<=1200000) { 
        yearlytax1 = 0.05 * (income - limit1); // 5% of the amount exceeding 600000
        std::cout<<"\tTax\n";
        std::cout << "Your Annual Tax is: Rs." << yearlytax1 << std::endl; 
        std::cout << "Your Monthly Tax is: Rs." << yearlytax1 / 12 << std::endl;
        std::cout<<"\tNet Income\n";
        std::cout << "Your Net Income Annualy is: Rs." << income - yearlytax1 << std::endl;
        std::cout << "Your Net Income Monthly is: Rs." << (income/12) - (yearlytax1/12) << std::endl;
    }
    else if (income >1200000 && income<=2200000) {
        yearlytax2 = 0.15 * (income - limit2) + 30000;// 30,000 (Fixed Tax) & 15% of the amount exceeding 1,200,000
        std::cout<<"\tTax\n";
        std::cout << "Your Annual Tax is: Rs." << yearlytax2 << std::endl; 
        std::cout << "Your Monthly Tax is: Rs." << yearlytax2 / 12 << std::endl;
        std::cout<<"\tNet Income\n";
        std::cout << "Your Net Income Annualy is: Rs." << income - yearlytax2 << std::endl;
        std::cout << "Your Net Income Monthly is: Rs." << (income/12) - (yearlytax2/12) << std::endl;
    }
    else if (income >2200000 && income<=3200000) {
        yearlytax3 = 0.25 * (income - limit3) + 180000; // Rs180,000 (Fixed Tax) + 25% of the amount exceeding Rs2,200,000
        std::cout<<"\tTax\n";
        std::cout << "Your Annual Tax is: Rs." << yearlytax3 << std::endl; 
        std::cout << "Your Monthly Tax is: Rs." << yearlytax3 / 12 << std::endl;
        std::cout<<"\tNet Income\n";
        std::cout << "Your Net Income Annualy is: Rs." << income - yearlytax3 << std::endl;
        std::cout << "Your Net Income Monthly is: Rs." << (income/12) - (yearlytax3/12) << std::endl;
    }
    else if (income >3200000 && income<=4100000) {
        yearlytax4 = 0.30 * (income - limit4)+ 430000; // Rs430,000 (Fixed Tax) + 30% of the amount exceeding Rs3,200,000
        std::cout<<"\tTax\n";
        std::cout << "Your Annual Tax is: Rs." << yearlytax4 << std::endl; 
        std::cout << "Your Monthly Tax is: Rs." << yearlytax4 / 12 << std::endl;
        std::cout<<"\tNet Income\n";
        std::cout << "Your Net Income Annualy is: Rs." << income - yearlytax4 << std::endl;
        std::cout << "Your Net Income Monthly is: Rs." << (income/12) - (yearlytax4/12) << std::endl;
    }
    else if (income >4100000) {
        yearlytax5 = 0.35 * (income - limit5) + 700000 ; // Rs700,000 (Fixed Tax) + 35% of the amount exceeding Rs4,100,000
        std::cout<<"\tTax\n";
        std::cout << "Your Annual Tax is: Rs." << yearlytax5 << std::endl; 
        std::cout << "Your Monthly Tax is: Rs." << yearlytax5 / 12 << std::endl;
        std::cout<<"\tNet Income\n";
        std::cout << "Your Net Income Annualy is: Rs." << income - yearlytax5 << std::endl;
        std::cout << "Your Net Income Monthly is: Rs." << (income/12) - (yearlytax5/12) << std::endl;

    }

    return 0;

 






}

#include <iostream>

int main()
{
    int t_class;
    int t_attend;
    float percentage;

    std::cout << " Enter the total number of classes : ";
    std::cin >> t_class;
    std::cout << " Enter the number of classes attended : ";
    std::cin >> t_attend;
    percentage = (t_attend / t_class * 100);
    if (t_attend > t_class) {
        std::cout << "Please input valid values such that toatal classes attended must be less than total classes";
    }
    else if (percentage>=75) {
        std::cout << "You are allowed to sit in exam";
    }
    else if (percentage<75) {
        std::cout << "You are not allowed to sit in exam";
    }


}
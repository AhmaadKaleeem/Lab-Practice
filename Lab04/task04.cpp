// Task#4: Write a C++ program that asks the user to enter positive integers in order to process count, maximum, minimum, and average or terminate the process with -1.
#include <iostream>

int main() {
    int num, count = 0, sum = 0, maxNum = (-9999999999 - 1), minNum = 2147483647;

    std::cout << "Enter positive integers (enter -1 to stop):" << endl;

    while (true) {
        std::cin >> num;

        
        if (num == -1) {
            break;
        }

        
        if (num < 0) {
            std::cout << "Please enter a positive integer or -1 to stop." << endl;
            continue;
        }

       
        count++;
        sum += num;

       
        if (num > maxNum) {
            maxNum = num;
        }
        if (num < minNum) {
            minNum = num;
        }
    }

  
    if (count > 0) {
        double average = sum / count;
       std::cout << "\nCount of numbers: " << count << endl;
        std::cout << "Sum of numbers: " << sum << endl;
        std::cout << "Maximum number: " << maxNum << endl;
        std::cout << "Minimum number: " << minNum << endl;
        std::cout << "Average: " << average << endl;
    }
    else {
        cout << "No numbers were entered." << endl;
    }

    return 0;
}


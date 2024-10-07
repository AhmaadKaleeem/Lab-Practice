// Task#2: Print multiplication table of 24, 50 and 29 using loop:


#include <iostream>
int main()
{
    int table1 = 24, table2 = 50, table3 = 29;
    std::cout << "We are going To Print Tables of 24,50 & 29 respectively" <<std::endl <<"\n";
    for (int a = 1; a <=10; a++)
    {
        int result1 = table1 * a ; 
        int result2 = table2 * a;
        int result3 = table3 * a;
        std::cout << table1 << " x " << a << " = " << result1<< std::endl;
        std::cout <<"\t\t\t" << table2 << " x " << a << " = " << result2 << std::endl;
        std::cout << "\t\t\t\t\t\t" << table3 << " x " << a << " = " << result3 << std::endl;
       
        
       
       
   }
    
}


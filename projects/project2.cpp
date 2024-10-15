// Project: Bank Account Management System
/*Features:
Create an Account : User enters their initial deposit and gets a new account number.
Deposit Money : User can deposit money into their account.
Withdraw Money : User can withdraw money, but only if the balance allows.
Display Account Information : Shows account number, balance, and recent transactions. */

#include <iostream>
#include <string>
using namespace std;
int main()
{
    // Declaring Variables
   // For making a fixed account number before 
    int  deposit, balance=0 , recent,  withdrawal, option = 0, cnic, notfixedacc ;
    string name, fixedaccnbr = "05101324";

    // Making a Interference
    cout << "\t\t\t\t Sharif Bank (Ltd) Account Management System " << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------";
    cout << endl;
    while (option != 5)
    {
        cout << " Please Select an Option  ! " << "\n\n";
        cout << "1. Create New Account in Sharif Bank (Ltd) " << "\n" << "2. Deposit Money in your Account" << "\n"
            << "3. Withdrawl Money From Your Account " << "\n" << "4. View Account Information " << "\n"
            << "5. Exit " << "\n\n";
        cout << "Enter the Selected Option > ";
        cin >> option;
        cout << "\n";

        // using if else to use the desired option 
        // Creating Account
        if (option == 1)
        {
            cout << "\t\t\t\t""Welcome to Sharif Bank (Ltd) " << "\n";
            cout << "Enter Your Name > ";
            cin >> name;
            cout << "Enter Your Identification Number > ";
            cin >> cnic;
            cout << "Enter Your Six Digits Account Number > ";
            cin >> notfixedacc;


            // Making sure that entered account number is not greater than or less than six
            if (notfixedacc >= 7 && notfixedacc < 6)
            {
                cout << "Error! Account Number Cannot Exceed or Less Than Six Digits ";
            }
            else
            {
                cout << "Congratulations " << name << "! You Have Successfully Created Account With Account  Number "
                    << fixedaccnbr << notfixedacc << " Against Identification Number " << cnic << ".\n\n";
            }
        }

        // Depositing Money
        else if (option == 2)
        {
            cout << "Enter The Amount To Deposit Into Your Account : Rs. ";
            cin >> deposit;
            balance = balance + deposit;
            cout << "Your Transaction is Successfully Completed ! " << "\n";
            cout << "Your New Balance is  Rs. " << balance << "\n\n";
        }

        // Withdrawal Money
        else if (option == 3)
        {
            cout << "Enter The Amount To Withdrawal From Your Account : Rs. ";
            cin >> withdrawal;
            if (balance > withdrawal)
            {
                balance = balance - withdrawal;
                cout << "Your Transaction is Successfully Completed ! " << "\n";
                cout << "Your New Balance is  Rs. " << balance << "\n\n";
            }
            else
            {
                cout << "Sorry! Your Account Doesn't Have Sufficient Balance. ";
            }
            
        }

        // Account Information
        else if (option == 4)
        {
            cout << "Your Account Number is " <<fixedaccnbr <<notfixedacc <<"\n";
            cout << "Your Account Balance is Rs. " << balance <<"\n";
        }

        // Exit
        else if (option == 5) {
            return 0;
        }


        option++;
    }

}


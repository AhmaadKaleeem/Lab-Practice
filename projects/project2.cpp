// Project: Bank Account Management System
/*Features:
Create an Account : User enters their initial deposit and gets a new account number.
Deposit Money : User can deposit money into their account.
Withdraw Money : User can withdraw money, but only if the balance allows.
Display Account Information : Shows account number, balance, and recent transactions. */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    // Declaring Variables
   // For making a fixed account number before 
    double  deposit=0.0, balance = 0.0, recent = 0.0, withdrawal, option = 0, cnic=0, notfixedacc;
    string name, fixedaccnbr = "05101324";
    ofstream recenttrans; //Using Filehandling

    // Making a Interference
    cout << "\t\t\t\t Sharif Bank (Ltd) Account Management System " << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------";
    cout << endl;


    recenttrans.open("Recent Transactions.txt", ios::app);
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
        // using if else to use the desired option
        if (option == 1)
        {

            cout << "\t\t\t\t""Welcome to Sharif Bank (Ltd) " << "\n";
            cout << "Enter Your Name > ";
            cin >> name;

            // Taking Input and Making sure that entered Identification number must be of 5 Digits and using for loop to take same input for 4 times 
            cout << "Enter Your 5 Digit National Identification Number > ";
            cin >> cnic;
            for (int tryagain = 0; tryagain <= 4; tryagain++) {
                if (cnic > 99999 || cnic < 10000)
                {
                    cout << "Error! National Identification Number Cannot Exceed or Less Than Six Digits \n";
                    cout << " Please Enter Again (Limit 4 Times) > ";
                    cin >> cnic;
                    cout << "\n\n";
                }
             
            }

            // Taking Input and Making sure that entered account number is not greater than or less than six
            cout << "Enter Your Six Digits Account Number > ";
            cin >> notfixedacc;

            if (notfixedacc > 999999 || notfixedacc < 100000)
            {
                cout << "Error! Account Number Cannot Exceed or Less Than Six Digits ";
                cout << "\n\n";
            }
            else
            {
                cout << "Congratulations " << name << "! You Have Successfully Created Account With Account Number "
                    << fixedaccnbr << notfixedacc << " Against Identification Number " << cnic << "\n\n";
            }

            if (recenttrans.is_open()) { // Check if the file opened successfully
                recenttrans << "Name " << name << ", Account Number " << fixedaccnbr << notfixedacc << ", Identification Number " << cnic
                    << ", Balance " << balance;// Append data to the file
            }

        }

        // Depositing Money
        else if (option == 2)
        {
            cout << "Enter The Amount To Deposit Into Your Account : Rs. ";
            if (deposit >= 0)
            {
                cin >> deposit;
                balance = balance + deposit;
                cout << "Your Transaction is Successfully Completed ! " << "\n";
                cout << "Your New Balance is  Rs. " << balance << "\n\n";
                if (recenttrans.is_open()) { // Check if the file opened successfully
                    recenttrans << "You Have Successfully Deposited Rs. " << deposit << ", Balance " << balance;
                }
            }
            else
            {
                cout << "Please ! Enter Amount in Positive Value \n\n";
            }
        }

        // Withdrawal Money
        else if (option == 3)
        {
            cout << "Enter The Amount To Withdrawal From Your Account : Rs. ";
            cin >> withdrawal;
            if (balance > withdrawal && withdrawal > 0)
            {
                balance = balance - withdrawal;
                cout << "Your Transaction is Successfully Completed ! " << "\n";
                cout << "Your New Balance is  Rs. " << balance << "\n\n";
                if (recenttrans.is_open()) { // Check if the file opened successfully
                    recenttrans << "You Have Successfully Withdrawal Rs. " << withdrawal << ", Balance " << balance;
                }
            }
            else if (balance < withdrawal)
            {
                cout << "Sorry! Your Account Doesn't Have Sufficient Balance. ";
            }
            else
            {
                cout << "Invalid Amount. Please Enter a Positive Value.\n\n";
            }

        }

        // Account Information
        else if (option == 4)
        {
            cout << "\t\t\t\t Account Information \n";
            cout << "Account Holder Name : " << name << "\n";
            cout << "Account Number: " << fixedaccnbr << notfixedacc << "\n";
            cout << "Identification Number : " << cnic << "\n";
            cout << "Current Balance: " << balance << "\n\n";



        }

        // Exit
        else if (option == 5)
        {
            cout << "Exiting the System. Thank You for Using Sharif Bank (Ltd).\n";
            return 0;
        }

        // Checking that the user enerted a valid input 
        else
        {
            cout << "Please Choose a Valid Option From 1-5 \n\n";
        }
        recenttrans.close();

        option++;
    }

}


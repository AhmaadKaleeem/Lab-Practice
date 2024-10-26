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
    long  deposit = 0.0, balance = 0.0, recent = 0.0, withdrawal, option = 0, cnic = 0, notfixedacc;
    string name, fixedaccnbr = "05101324";
    ofstream recenttrans; //Using Filehandling

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
        // using if else to use the desired option
        if (option == 1)
        {

            cout << "\t\t\t\t""Welcome to Sharif Bank (Ltd) " << "\n";
            cout << "Enter Your Name (No Spaces) > ";
            cin >> name;

            // National ID Validation (5-Digit CNIC) with 4 Time Limit
            cout << "Enter Your 5 Digit National Identification Number > ";
            cin >> cnic;
            int tryagain = 4;
            while ((cnic > 99999 || cnic < 10000) && tryagain > 0)
            {
                cout << "Error! National Identification Number Cannot Exceed or Less Than Six Digits \n";
                cout << " Please Enter Again (Limit 4 Times) > ";
                cin >> cnic;
                tryagain--;
            }
            if (tryagain == 0 && (cnic > 99999 || cnic < 10000))
            {
                cout << "\n You Failed to Enter Valid National Identification Number, Returning Back to Main Menu \n\n";
                continue;
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
                // Log Details into the File        
                recenttrans.open("Recent Transactions.txt", ios::app);
                if (recenttrans.is_open())
                { // Check if the file opened successfully
                    recenttrans << "Account Created, User Name: " << name << ", Cnic: " << cnic << ", Account Number: " << notfixedacc << ", New Balance: Rs. " << balance << "\n";// Append data to the file  
                }
                else
                {
                    cout << "There is an Error in Opening The File. ";
                }
                recenttrans.close();
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
            }
            else
            {
                cout << "Please ! Enter Amount in Positive Value \n\n";
            }
            // Log Deposit in the file
            recenttrans.open("Recent Transactions.txt", ios::app);
            if (recenttrans.is_open())
            { // Check if the file opened successfully
                recenttrans << "Deposited Rs. " << deposit << ", New Balance is Rs." << balance << "\n";
            }
            else
            {
                cout << "There is an Error in Opening The File. \n ";
            }
            recenttrans.close();
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

                // Log withdrawal in the file
                recenttrans.open("Recent Transactions.txt",ios::app);
                if (recenttrans.is_open())
                { // Check if the file opened successfully
                    recenttrans << "Withdrawal Rs. " << withdrawal << ", New Balance is Rs. " << balance << "\n";
                }
                else
                {
                    cout << "There is an Error in Opening The File. \n";
                }
                recenttrans.close();
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
            cout << "Current Balance: " << balance << "\n";

            // Show recent transactions by reading from the file
            ifstream recentFile("Recent Transactions.txt");
            if (recentFile.is_open()) {
                cout << "\t\t\t\t  Recent Transactions \n";
                string transaction;
                while (getline(recentFile, transaction)) {
                    cout << transaction << "\n";
                }
                recentFile.close();
            }
            else {
                cout << "Error opening the file.\n";
            }


        }

        // Exit
        else if (option == 5)
        {
            cout << "Exiting the System. Thank You for Using Sharif Bank (Ltd).\n";
            
        }

        // Checking that the user enerted a valid input 
        else

        {
            cout << "Please Choose a Valid Option From 1-5 \n\n";
        }

      
    }

}


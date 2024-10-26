// Project: Bank Account Management System
/* Features:
Create an Account : User enters their details,deposit and gets a new account number.
Deposit Money : User can deposit money into their account.
Withdraw Money : User can withdraw money, but only if the balance allows.
Display Account Information : Shows account number, balance, and recent transactions. */

#include <iostream>
#include <fstream> // For File Handling
#include <string>
#include <ctime> 
# include <stdlib.h> // Create Random Numbers
#include <limits> // To Handle Wrong Data Type Input
using namespace std;

// Function to Validate Respective Input Data Type
long checkinputtype(const string& prompt) {
    int input;
    while (true) {
        cout << prompt;
        cin >> input;
        // Check if input is valid
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\t\t\t\tInvalid input. Please Enter an Integer.\n\n";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return input;
        }
    }
}

// Function to Save All Transactions History
void savetransactiondetails(const string& name, long cnic, long notfixedacc, long balance) {
    ofstream recenttrans("Recent Transactions.txt", ios::app);
    // Check if the file opened successfully
    if (recenttrans.is_open())
    {
        recenttrans << "Account Created, User Name: " << name << ", Cnic: " << cnic << ", Account Number: " << notfixedacc << ", New Balance: Rs. " << balance << "\n";// Append data to the file  
        recenttrans.close();
    }
    else
    {
        cout << "There is an Error in Opening The File. ";
    }
}


// Function to Save Withdrawal Transactions History
void withdrwawalamount(long withdrawal, long balance) {
    ofstream recenttrans("Recent Transactions.txt", ios::app);
    // Check if the file opened successfully
    if (recenttrans.is_open())
    {
        recenttrans << "Withdrawal Rs. " << withdrawal << ", New Balance is Rs. " << balance << "\n";
        recenttrans.close();
    }
    else
    {
        cout << "There is an Error in Opening The File. \n";
    }
}

// Function to Save Deposit Transactions History
void depositamount(long deposit, long balance) {
    ofstream recenttrans("Recent Transactions.txt", ios::app);
    // Check if the file opened successfully
    if (recenttrans.is_open())
    {
        recenttrans << "Deposit Rs. " << deposit << ", New Balance is Rs. " << balance << "\n";
        recenttrans.close();
    }
    else
    {
        cout << "There is an Error in Opening The File. \n";
    }
}

// Function to Save Data and Copy After Exiting System
void copyvariabledata(const string& name, long notfixedacc, long cnic, long balance) {

    ofstream data("data.txt", ios::trunc);
    if (data.is_open())
    {
        data << name << endl;
        data << notfixedacc << endl;
        data << cnic << endl;
        data << balance << endl;
        data.close();
    }
    else
    {
        cout << "There is an Error in Opening The File. \n";
    }

}

// Function to Recall Data
bool loadvariableinfo(string& name, long& notfixedacc, long& cnic, long& balance) {
    ifstream data("data.txt");
    if (data.is_open()) {
        if (data >> name >> notfixedacc >> cnic >> balance) {
            data.close();
            return true;
        }
        else {
            data.close();
            return false;
        }
    }
    return false;
}

int main()
{
    // Declaring Variables
   // For making a fixed account number before 
    long  deposit = 0, balance = 0, recent = 0, withdrawal = 0, option = 0, cnic = 0, notfixedacc=0;
    string name, fixedaccnbr = "05101324";
    ofstream recenttrans; //Using Filehandling

    // Making a Interference
    cout << "\t\t\t\t Sharif Bank (Ltd) Account Management System " << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------";
    cout << endl;

    // Load existing account data if available
    if (loadvariableinfo(name, notfixedacc, cnic, balance)) {
        cout << "Welcome Back, " << name << "! Your Account Information has been Loaded.\n\n";
    }
    else {
        cout << "No Previous Account Data found. Please create a New Account.\n";
    }

    srand(time(0));

    while (option != 5)
    {
        cout << "Please Select an Option  ! " << "\n\n";
        cout << "1. Create New Account in Sharif Bank (Ltd) " << "\n" << "2. Deposit Money in your Account" << "\n"
            << "3. Withdrawl Money From Your Account " << "\n" << "4. View Account Information " << "\n"
            << "5. Exit " << "\n\n";
        option = checkinputtype("Enter the Selected Option > ");

        // using if else to use the desired option 
        // Creating Account
        // using if else to use the desired option
        if (option == 1)
        {
            // Clear previous transactions 
            recenttrans.open("Recent Transactions.txt", ios::trunc);
            recenttrans.close();

            cout << "\t\t\t\t""Welcome to Sharif Bank (Ltd) " << "\n";
            cout << "Enter Your Name (Use Special Letter Insated Of Spaces) > ";
            cin >> name;

            // National ID Validation (5-Digit CNIC) with 4 Time Limit
            cnic = checkinputtype("Enter Your 5 Digit National Identification Number > ");
            int tryagain = 4;
            while ((cnic > 99999 || cnic < 10000) && tryagain > 0)
            {
                cout << "Error! National Identification Number Cannot Exceed or Less Than Five Digits \n";
                cout << " Please Enter Again (Limit 4 Times) > ";
                cin >> cnic;
                tryagain--;
            }
            if (tryagain == 0 && (cnic > 99999 || cnic < 10000))
            {
                cout << "\n You Failed to Enter Valid National Identification Number, Returning Back to Main Menu \n\n";
                continue;
            }

            balance = checkinputtype("Enter Your Intial Deposit > Rs.");

            // Generating Radnom Account Number
            notfixedacc = rand() % 900000 + 100000;

            // Account Created Successfully
            cout << "Congratulations " << name << "! You Have Successfully Created Account With Account Number "
                << fixedaccnbr << notfixedacc << " Against Identification Number " << cnic << "\n\n";

            // Calling Function to Log Details into the File        
            savetransactiondetails(name, notfixedacc, cnic, balance);
            copyvariabledata(name, notfixedacc, cnic, balance);

        }

        // Depositing Money
        else if (option == 2)
        {
            deposit = checkinputtype("Enter The Amount To Deposit Into Your Account : Rs. ");
            if (deposit >= 0)
            {
                balance = balance + deposit;
                cout << "Your Transaction is Successfully Completed ! " << "\n";
                cout << "Your New Balance is  Rs. " << balance << "\n\n";
            }
            else
            {
                cout << "Please ! Enter Amount in Positive Value \n\n";
            }

            // Calling Function to Log Details into the File        
            depositamount(deposit, balance);
            copyvariabledata(name, notfixedacc, cnic, balance);
        }

        // Withdrawal Money
        else if (option == 3)
        {
            withdrawal = checkinputtype("Enter The Amount To Withdrawal From Your Account : Rs. ");
            if (balance > withdrawal && withdrawal > 0)
            {
                balance = balance - withdrawal;
                cout << "Your Transaction is Successfully Completed ! " << "\n";
                cout << "Your New Balance is  Rs. " << balance << "\n\n";

                // Calling Function to Log Details into the File        
                withdrwawalamount(withdrawal, balance);
                copyvariabledata(name, notfixedacc, cnic, balance);
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
        \
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


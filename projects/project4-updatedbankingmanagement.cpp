// Project: Bank Account Management System
/* Features:
Create an Account : User enters their details,deposit,create pin and gets a new account number.
Deposit Money : User can deposit money into their account.
Withdraw Money : User can withdraw money, but only if the balance allows.
Display Account Information : Shows account number, balance, and recent transactions.
Modify Pin : Can Change or Reset Pin Code 
Send Money : User can send money to any bank.
Load and Bundles : User can buy new bundles and load of any Pakistani Number
PUBG UC : User which are Pubg Lover can buy Uc through Bank. */

#include <iostream>
#include <fstream> // For File Handling
#include <string>
#include <sstream>
#include <ctime> 
#include <stdlib.h> // Create Random Numbers
#include <limits> // To Handle Wrong Data Type Input
using namespace std;

// Function to Validate Respective Input Data Type
double checkinputtype(const string& prompt) {
    double input;
    while (true) {
        cout << prompt;
        cin >> input;
        // Check if input is valid
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\n\t\t\t\tInvalid input.Please Enter an Integer.\n\n";
        }
        else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return input;
        }
    }
}
// Validate User Entered Pin
bool pincheck(string& pin, int tryagain = 4) {

    string userpin;
    while (tryagain > 0)
    {
         cout << "\nPlease,Enter Your Pin (Try Again Limit = 4) : ";
         getline (cin,userpin);
        if (userpin == pin) {
            cout << "PIN verified successfully! \n";
            return true;
        }
        else {
            cout << "Sorry,The Entered Pin is Incorrect.Try Again! \n";

            tryagain--;
        }

    }
    cout << "\nYou Failed to Enter Valid Pin, Returning Back to Main Menu. \n\n";
    return false;

}


void savenewaccounts( string& name, string& cnic, double notfixedacc, double& balance ,string& pin) {

    ofstream recenttrans("allaccounts.txt", ios::app);
    // Check if the file opened successfully
    if (recenttrans.is_open())
    {
        recenttrans  << name << "," << cnic << "," << notfixedacc  << "," << balance << "," << pin  << "\n";// Append data to the file  
        recenttrans.close();
    }
    else
    {
        cout << "There is an Error in Opening The File. ";
    }
}

// Function to Recall Data
bool loadvariableinfo( string& name, string& cnic, double& notfixedacc, double& balance ,string& pin) {
    ifstream data("allaccounts.txt");

    if (data.is_open()) {

        string line;

    while (getline(data, line)) {

        stringstream ss(line);
        string notfixedaccount, updatedbalance; // Strings to hold numeric values temporarily
        string name2, cnic2, pin2;

        getline(ss,name2,',' );
        getline(ss, cnic2, ',');
        getline(ss, notfixedaccount, ',');
        getline(ss, updatedbalance, ','); 
        getline(ss, pin2, ','); 
       
        double temp_notfixedaccount = stod(notfixedaccount);
        double temp_updatedbalance = stod(updatedbalance);
        
        if (cnic == cnic2) {
            name = name2;
            notfixedacc = temp_notfixedaccount;
            balance = temp_updatedbalance;
            pin = pin2;
            data.close();
            return true; 
        }
    }
    }
  
    data.close();
    return false;
}

// Function to validate login by checking CNIC, username, and password
bool validatelogin(const string& enteredcnic, const string& enteredusername, const string& enteredpassword) {
    ifstream logindata("logindata.txt");
    if (!logindata) {
        cout << "Error: Unable to open login data file.\n";
        return false;
    }

    string line, cnic, username, password;
   
        bool cnicfound = false;
    
    while (getline(logindata, line)) {
        stringstream ss(line);
        getline(ss, cnic, ',');
        getline(ss, username, ',');
        getline(ss, password, ',');

        if (cnic == enteredcnic) {
            cnicfound = true;
            if (username == enteredusername && password == enteredpassword) {
                logindata.close();
                return true;
            }
        }
    }

    logindata.close();
    
    if (!cnicfound) {
        cout << "There is No Registered Account Against this CNIC, Please Register an Account First.\n";
    } else {
        cout << "Please Enter Correct Username or Password to Login.\n";
    }
    
    return false;
}

bool checkduplicatecnic(const string& enteredcnic, const string& enteredusername, const string& enteredpassword) {
    ifstream logindata("logindata.txt");
    if (!logindata) {
        cout << "Error: Unable to open  data file to check cnic.\n";
        return false;
    }

    string line, cnic, username, password;
   
        bool cnicfound = false;
    
    while (getline(logindata, line)) {
        stringstream ss(line);
        getline(ss, cnic, ',');

        if (cnic == enteredcnic) {
            cnicfound = true;
        }
    }

    logindata.close();
    
    
    return false;
}
// Function To Save Only Username and Password For Login
void savelogindata( const string cnic ,string& username, string& password) {

    ofstream recenttrans("logindata.txt", ios::app);
    // Check if the file opened successfully
    if (recenttrans.is_open())
    {
        recenttrans  << cnic << "," << username << "," << password << "\n" ;// Append data to the file  
        recenttrans.close();
    }
    else
    {
        cout << "There is an Error in Opening The File. ";
    }
}

// Function to Save All Transactions History
void savetransaction(const string& name, string cnic, double notfixedacc, double balance) {
    string filename = "User_" + cnic + ".txt";
    ofstream data(filename, ios::app);
    // Check if the file opened successfully
    if (data.is_open())
    {
        data << "Account Created, User Name: " << name << ", Cnic: " << cnic << ", Account Number: " << notfixedacc << ",  Balance: Rs. " << balance << "\n";// Append data to the file  
        data.close();
    }
    else
    {
        cout << "There is an Error in Opening The File. ";
    }
}


// Function to Save Withdrawal Transactions History
void withdrawamount(string cnic,double& withdrawal, double& balance) {
    string filename = "User_" + cnic + ".txt";
    ofstream recenttrans(filename, ios::app);
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


// Function to Save Transfer Transactions History
void transferamount(string cnic, double moneytranfer, double balance,string reciveraccount)  {
    string filename = "User_" + cnic + ".txt";
    ofstream recenttrans(filename, ios::app);
    // Check if the file opened successfully
    if (recenttrans.is_open())
    {
        recenttrans << "Trasnfered Rs. " << moneytranfer << ", to Wallet " << reciveraccount << ", New Balance is Rs. " << balance << "\n";
        recenttrans.close();
    }
    else
    {
        cout << "There is an Error in Opening The File. \n";
    }
}
// Function to Save Deposit Transactions History
void depositamount(string cnic,double deposit, double balance) {
    string filename = "User_" + cnic + ".txt";
    ofstream recenttrans(filename, ios::app);
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

// Function to Save Data and Copy After Login
void copyvariabledata(const string& name, string cnic , double notfixedacc, string pin,string username,string password) {
     string filename = "User_" + username + ".txt";
    ofstream data(filename, ios::trunc);
    if (data.is_open())
    {
        data << name << endl;
        data << notfixedacc << endl;
        data << cnic << endl;
        data << pin << endl;
        data << username <<endl;
        data << password << endl;
        data.close();
    }
    else
    {
        cout << "There is an Error in Opening The File. \n";
    }

}


// Function to check Wallet Number
bool checklenghtwallet (string account){
 if (account.length() != 11 ){
 return false ; }

 for (int i = 0 ; i <=11 ; i++ ){
    if (account[i] >= '0' || account [i] <= '9' ) {
        return false;
    }
    }
    
    if (account[0] != '0' || account[1] !='3'){
        return false;
    }
 
    return true;
}

// Function to validate cnic

bool checkcnic (string cnicc) {
    if (cnicc.length() !=13){
        return false;
    }
return true;
}
bool checkpin (string pinn) {
    if (pinn.length() !=4){
        return false;
    }
return true;

}

int main()
{   
    // Declaring Variables
    double deposit = 0, balance = 0, withdrawal = 0, notfixedacc = 0,
    transfermoney=0;
    int transferoption,walletnumber,accountoption, option ;
    string receiveraccount,name,cnic, fixedaccnbr = "05101324",pin,username,password;
    ofstream recenttrans;


    // Making a Interference
    cout << "\t\t\t\t Sharif Bank (Ltd) Account Management System " << endl;
    cout << "-----------------------------------------------------------------------------------------------------------------------";
    cout << endl;

  

    srand(time(0)); // To Create DIfferent Randon Number Each Time


        cout << "Welcome to Sharif Bank Ltd , Please Choose an Option to Continue \n\n";
        cout << "1. Register Account"  << "\n" << "2. Login into Existing Account " "\n\n";
        accountoption = checkinputtype("Enter the Selected Option : ");
        
    
        // Creating Account
        if (accountoption == 1)
        {
            
            cout << "Enter Your Name (Use Special Characters Instead Of Space) : ";
            getline(cin, name);

            // National ID Validation (13-Digit CNIC) with 4 Time Limit
            cout << "Enter Your 13 Digit National Identification Number : ";
            getline(cin, cnic);
            int tryagain = 4;
            while (!checkcnic(cnic) && tryagain > 0)
            {
                cout << "Error! National Identification Number is Not Valid, Please Enter Valid  National Identification Number. \n";
                cout << " Please Enter Again (Limit 4 Times) : ";
                cin >> cnic;
                tryagain--;
                if (tryagain == 0)
                {
                    cout << "\n You Failed to Enter Valid National Identification Number, Returning Back to Main Menu. \n\n";
                    break;
                }
            }

            // Checking if cnic already exists
           bool check = checkduplicatecnic(cnic,username,password);
         
           if (check) {
            cout << "This CNIC is Already Registered. Please Login To Continue.\n";
        } 
           else {
            cout << "CNIC is unique. Proceeding..." << endl;
        }        

            // Generating Radnom Account Number
            notfixedacc = rand() % 900000 + 100000;

              // Create a Pin
            cout << "Enter to Create Your 4 Digit Pin Code : ";
            getline(cin, pin);
            if (!checkpin(pin)){
                cout << "Please Enter Valid 4-digit Pin." << "\n";
            }

            // Creating User name and Password For Banking Services
            cout << "Thanks For Creating Account in Sharif Bank Ltd, Please Create a UserName and Password to Enjoy our Banking Services.\n";
            cout << "Enter Your User Name : ";
            getline(cin,username);
            cout << "Enter Your Password : ";
            getline(cin,password);
            // Account Created Successfully
            cout << "Congratulations " << name << "! You Have Successfully Created Account With Account Number "
                << "\n" << fixedaccnbr << notfixedacc << " Against Identification Number " << cnic << ". \n";
            cout << "You have been Given Rs 100 as Bonus on Creating a New Account. \n\n";
            balance = 100; 
            // Calling Function to Log Details into the File        
            savenewaccounts(name,  cnic, notfixedacc, balance ,pin);
            savetransaction(name,cnic,notfixedacc,balance);
            savelogindata(cnic,username,password);

        }

        // Login Back into Account
        else if (accountoption == 2)
        {
            string usercnic,userpass,username;
            cout << "Enter Your CNIC : " ;
            cin >> usercnic;
            
            cout << "Enter Your User Name : " ;
            cin >> username;
            
            cout << "Enter Your Password : " ;
            cin >> userpass; 

         if (validatelogin(usercnic,username,userpass))
        { 

          if (loadvariableinfo(name,usercnic,notfixedacc,balance,pin)){
          cout <<  "Welcome Back " << name << ", Enjoy Your Seamless Banking With Sharif Bank Ltd.\n\n ";
          while (option != 8)
    {
        cout << "Please Select an Option to Proceed ! \n\n";
        cout << "1. Deposit Money in Your Account" << "\n" << "2. Withdrawl Money From Your Account " << "\n" 
             << "3. Transfer Money " << "\n" << "4. View Account Information " << "\n"  
             << "6. Credintials Management " << "\n" << "7. Load and Bundles" << "\n" 
             << "8. Exit " << "\n\n";
        option = checkinputtype("Enter the Selected Option : ");

       
        // Depositing Money
         if (option == 1)
        {
            // Validate Pin To Deposit
            if (pincheck(pin))
            {
                deposit = checkinputtype("Enter The Amount To Deposit Into Your Account : Rs. ");
                if (deposit >= 0)
                {
                    balance = balance + deposit;
                    cout << "Your Transaction is Successfully Completed. " << "\n";
                    cout << "Your New Balance is  Rs. " << balance << "\n\n";
                    // Calling Function to Log Details into the File        
                    depositamount(usercnic,deposit, balance);
                   
                }
                else
                {
                    cout << "Please! Enter Amount in Positive Value \n\n";
                }
            }

        }

        // Withdrawal Money
        else if (option == 2)
        {
            // Validate Pin to Withdraw
            if (pincheck(pin))
            {
                withdrawal = checkinputtype("Enter The Amount To Withdrawal From Your Account : Rs. ");
                if (balance > withdrawal && withdrawal > 0)
                {
                    balance = balance - withdrawal;
                    cout << "Your Transaction is Successfully Completed. " << "\n";
                    cout << "Your New Balance is  Rs. " << balance << "\n\n";

                    // Calling Function to Log Details into the File        
                    withdrawamount(usercnic,withdrawal, balance);
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



        }

          // Transfer Money
       else if (option == 3)
       {
          pincheck(pin); 
          cout << "\t\t\t\t Transfer Money to Another Account" << "\n";
          cout << "1. Transfer to Wallet " << "\n" << "2. Transfer to Bank Account" << "\n\n";
          transferoption = checkinputtype("Enter the Option : ");
          if (transferoption==1)
          {
            cout << "Please Select the Bank Wallet To Transfer Money \n";
            cout << "1. Alfa Pay \n" << "2. Digitt \n" << "3.Easypaisa \n" << "4.FINCA \n"
                 << "5.Finja \n" << "6.Firstpay \n"  <<  "7.HBL Konnect \n" << "8.JazzCash \n"
                 << "9.KEENU \n" << "10.NayaPay \n" << "11.Paymax \n" << "12.SadaPay \n" << "13.SimSim \n" << "14.Upaisa" << "\n\n";
           walletnumber=checkinputtype( "Enter the Wallet : ");
         
        if (walletnumber > 0 && walletnumber<=14)
        {
            do {
                cout << "Enter the 11 Digit User Account Number : ";
                cin >> receiveraccount;
                if (!checklenghtwallet(receiveraccount)){
                cout << "Please Enter a Valid Account Number ! " << endl;
                break;
                }
                 
                transfermoney=checkinputtype("Enter the Amount to Transfer : ");
                if (transfermoney>0 && transfermoney<=balance)
                {
                    balance=balance-transfermoney;
                    cout << "Your Transaction is Successfully Completed. " << "\n";
                    cout << "Your New Balance is  Rs. " << balance << "\n\n";
                    transferamount( usercnic,transfermoney,  balance, receiveraccount);
          
                
                }
                else if (transfermoney>balance)
                {
                    cout << "Sorry! Your Account Doesn't Have Sufficient Balance. ";
                }
                else
                {
                    cout << "Invalid Amount. Please Enter a Positive Value.\n\n";
                }
            }
            while (!checklenghtwallet(receiveraccount));
            
        
          }
          
          }

          if (transferoption==2)
          {
            cout << "Please Select the Bank  To Transfer Money \n";
            cout << "1.Advans Microfinance Bank Limited \n" << "2. Alfa Pay \n" << "3.Allied Bank Limited (ABL) \n" << "4.APNA Microfinance Bank Limited \n"
                 << "5.Askari Bank Limited\n" << "6.Bank Alfalah Limited \n"  <<  "7.Bank Al Habib Limited \n" << "8.Bank Islami Pakistan Limited \n"
                 << "9.Bank Makramah Limited BML \n" << "10.Bank of Punjab \n" << "11.Bank of Khyber\n" << "12.Burj Bank Limited \n" << "13.CDNS \n" << "14.Citi Bank Limited" << "\n"
                 << "15.Digitt \n" << "16. Dubai Islamic Bank Pakistan Limited \n" << "17.Faysal Bank Limited \n" << "18.FINCA Microfinance Bank Limited \n"
                 << "19.Finja\n" << "20.First Pay \n"  <<  "21.First Women Bank Limited \n" << "22.HBL Konnect\n" << "23.Habib Bank Limited (HBL) \n" 
                 << "24.Habib Metropolitan Bank Limited \n" << "25.Industrial and Commercial Bank of China Limited (ICBC)\n" << "26.JS Bank Limited\n" << "27.KASB Bank Limited\n" 

                 << "28.KEENU \n" << "29.Khushhali Microfinance Bank Limited \n" << "30.MCB Bank Limited \n" << "31.Meezan Bank Limited \n" << "32.Mobilink Microfinance Bank Limited \n"
                 << "33.NIB Bank Limited \n" << "34.National Bank of Pakistan (NBP) \n"  <<  "35.NRSP Microfinance Bank Limited \n" << "36.OneZapp \n"
                 << "37.Paymax \n" << "38.Samba Bank Limited \n" << "39.Silk Bank Limited\n" << "40.SimSim by Finca \n" << "41.Sindh Bank Limited \n" << "42.Soneri Bank Limited" << "\n"
                 << "43.Standard Chartered Bank (Pakistan) Limited \n" << "44.Summit Bank Limited \n" << "45.Tameer Microfinance Bank Limited \n" << "46.Telenor Microfinance Bank\n"
                 << "47.U Microfinance Bank Limited\n" << "48.United Bank Limited (UBL)\n"  <<  "49.Zarai Taraqiati Bank Limited (ZTBL) \n\n" ;
          
                 walletnumber=checkinputtype( "Enter the Wallet : ");
         
        if (walletnumber > 0 && walletnumber<=49)
        {
            do {
                cout << "Enter the 14 or 20 Digit Bank Account Number : ";
                cin >> receiveraccount;
                if (!checklenghtwallet(receiveraccount)){
                cout << "Please Enter a Valid Account Number ! " << endl;
                break;
                }
                 
                transfermoney=checkinputtype("Enter the Amount to Transfer : ");
                if (transfermoney>0 && transfermoney<=balance)
                {
                    balance=balance-transfermoney;
                    cout << "Your Transaction is Successfully Completed. " << "\n";
                    cout << "Your New Balance is  Rs. " << balance << "\n\n";
                    transferamount( usercnic,transfermoney,  balance, receiveraccount);
                
                }
                else if (transfermoney>balance)
                {
                    cout << "Sorry! Your Account Doesn't Have Sufficient Balance. ";
                }
                else
                {
                    cout << "Invalid Amount. Please Enter a Positive Value.\n\n";
                }
            }
            while (!checklenghtwallet(receiveraccount));
            
        
          }
          
          }

        }
    
     
        // Account Information
        else if (option == 4)
        {
            pincheck(pin);

            cout << "\t\t\t\t Account Information \n";
            cout << "Account Holder Name : " << name << "\n";
            cout << "Account Number: " << fixedaccnbr << notfixedacc << "\n";
            cout << "Identification Number : " << usercnic << "\n";
            cout << "Current Balance: " << balance << "\n";
            
            // Show recent transactions by reading from the file
            string filename = "User_" + usercnic + ".txt";
            ifstream recentfile(filename);
            if (recentfile.is_open()) {
                cout << "\t\t\t\t  Recent Transactions \n";
                string transaction;
                while (getline(recentfile, transaction)) {
                    cout << transaction << "\n";
                }
                recentfile.close();
            }
            else {
                cout << "Error opening the file.\n";
            }


        }

        // Modify Pin Code
        else if (option == 5)
        {
            double newpin, newoption ; string username,usercnic;
            cout << "\nPlease Select an Option  ! " << "\n\n";
            cout << "1. Change Pin Code " << "\n" << "2. Reset Pin" << "\n\n";
            // Validating Input Data Type
            newoption = checkinputtype("Enter the Option : ");

            if (newoption == 1)
            {
                if (pincheck(pin)) {
                    cout << "Enter Your New Pin : ";
                    cin >> newpin;
                    pin = newpin;
                    cout << "Congratulations! Your Pin Have Been Changed. \n\n";
                    
                }
            }

            if (newoption == 2)
            {
                cout << "Please, Enter The Required Details to Reset Pin Code. \n";
                cout << "Enter the Same Details as Filled During Creating a Account. \n ";
                cout << "Enter Your Name : ";
                cin >> username;
                // National ID Validation (5-Digit CNIC) with 4 Time Limit
                usercnic = checkinputtype("Enter Your 5 Digit National Identification Number > ");
                int tryagain = 4;
                

                // Checking Details
                if (username == name && usercnic == cnic) {
                    cout << "\n Congratulations! Please Enter Your New Pin : ";
                    cin >> newpin;
                    pin = newpin;

                    // Calling Function to Log Details into the File        
                    
                }
                else if (newoption !=0 && newoption!=1){
                    cout << "\t\t\t\tSorry, The Provided Information Doesn't Match With Records.Try Again! \n\n";

                }


            }
            else {
                cout << "\nPlease Choose a Valid Option From 1 and 2 \n\n";
            }

        }

        // Exit
        else if (option == 10)
        {
            cout << "Exiting the System. Thank You for Using Sharif Bank (Ltd).\n\n";

        }

        // Checking that the user enerted a valid input 
        else

        {
            cout << "Please Choose a Valid Option From 1-10 \n\n";
        }


    }
          }
          
          else {
            cout << "Sorry, We Cannot Retrieve Your Information.\n\n";
          }
            
        }


    }
}
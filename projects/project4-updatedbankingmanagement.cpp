// Project: Bank Account Management System
/* Features:

✅ Account Management – Creating accounts with unique CNIC validation, PIN verification, and login credentials.
✅ Secure Login – Validating username & password against registered CNIC.
✅ Deposits & Withdrawals – Ensuring transactions follow deposit/withdrawal limits and balance constraints.
✅ Fund Transfers – Supporting transfers to bank accounts & mobile wallets with format validation.
✅ Transaction History – Logging every deposit, withdrawal, and transfer.
✅ Credential Management – Modifying or resetting PIN, username, and password.
✅ Mobile Load & Bundles – Loading balance to various operators with correct number validation.


*/

#include <iostream>
#include <fstream> // For File Handling
#include <string>
#include <sstream>
#include <ctime> 
#include <stdlib.h> // Create Random Numbers
#include <limits> // To Handle Wrong Data Type Input
using namespace std;

// Function to Load and Bundle Interface
void loadinterface(bool (*validatefunction)(), void (*function2)(string, double, double&),double& balance,string cnic){
    if(!validatefunction()){
        return;
    };
    double loadamount;
                    cout << "Enter the Amount to Load : ";
                    cin >> loadamount;
                    if (loadamount > 0 && loadamount <= balance)
                    {
                        balance = balance - loadamount;
                        cout << "Your Transaction is Successfully Completed. " << "\n";
                        cout << "Your New Balance is  Rs. " << balance << "\n\n";
                        function2(cnic, loadamount, balance);
                    }
                    else if (loadamount > balance)
                    {
                        cout << "Sorry! Your Account Doesn't Have Sufficient Balance. ";
                    }
                    else
                    {
                        cout << "Invalid Amount. Please Enter a Positive Value.\n\n";
                    }
}
// Function To Validate Number for Load and Bundles
bool valiate_jazznbr(){
    string number;
    cout << "Please Enter the Number : ";
                    getline(cin,number);
    if (number.length() != 11){
        cout << "Please Enter a Valid Number ! " << endl;
        return false;
    }
    for (int i = 0; i < 11; i++){
        if (number[i] < '0' || number[i] > '9' ){
            cout << "Please Enter a Valid Number ! " << endl;
            return false;
        if (number[0] != 0 || number[1] != 3 || (number[2] != 0  && number[2] != 2)){
            cout << "Please Enter a Valid Jazz Number ! " << endl;
            return false;
        }
        }
    }
    return true;
   }
bool valiate_telenornbr(){
    string number;
    cout << "Please Enter the Number : ";
                    getline(cin,number);
    if (number.length() != 11){
        cout << "Please Enter a Valid Number ! " << endl;
        return false;
    }
    for (int i = 0; i < 11; i++){
        if (number[i] < '0' || number[i] > '9' ){
            cout << "Please Enter a Valid Number ! " << endl;
            return false;;
        if (number[0] != 0 || number[1] != 3 || number[2] != 4  ){
            cout << "Please Enter a Valid Telenor Number ! " << endl;
            return false;;
        }
        }
    }
    return true;
   }
bool valiate_zongnbr(){
    string number;
    cout << "Please Enter the Number : ";
                    getline(cin,number);
    if (number.length() != 11){
        cout << "Please Enter a Valid Number ! " << endl;
        return false;
    }
    for (int i = 0; i < 11; i++){
        if (number[i] < '0' || number[i] > '9' ){
            cout << "Please Enter a Valid Number ! " << endl;
            return false;;
        if (number[0] != 0 || number[1] != 3 || number[2] != 1  ){
            cout << "Please Enter a Valid Jazz Number ! " << endl;
            return false;;
        }
        }
    }
    return true;
   }
bool valiate_ufonenbr(){
    string number;
    cout << "Please Enter the Number : ";
                    getline(cin,number);
    if (number.length() != 11){
        cout << "Please Enter a Valid Number ! " << endl;
        return false;
    }
    for (int i = 0; i < 11; i++){
        if (number[i] < '0' || number[i] > '9' ){
            cout << "Please Enter a Valid Number ! " << endl;
            return false;;
        if (number[0] != 0 || number[1] != 3 || number[2] != 3  ){
            cout << "Please Enter a Valid Jazz Number ! " << endl;
            return false;;
        }
        }
    }
    return true;
   }
// All Operators Bundles
void jazzbundles(bool (*function)(),void (*function2)(string,double,double&),double& balance,string cnic){
    int option;
    cout << "Welcome to Jazz Bundles and Offers" << "\n\n";
    cout << "1. Daily Social – 1 Day, 1 GB Social Mbs, 100 Jazz Min, 100 SMS" << "\n";
    cout << "2. Daily Super – 1 Day, 2 GB, 200 Jazz Min, 200 SMS" << "\n";
    cout << "3. Daily YouTube – 1 Day, 2 GB, No Calls, No SMS" << "\n";
    cout << "4. Daily Mega – 1 Day, 1 GB, No Calls, No SMS" << "\n";
    cout << "5. Weekly Mega – 7 Days, 5 GB, 500 Jazz Min, 500 SMS" << "\n";
    cout << "6. Weekly Super Plus – 7 Days, 30 GB, 1000 Jazz Min, 1000 SMS" << "\n";
    cout << "7. Weekly Extreme – 7 Days, 10 GB (Night Only), No Calls, No SMS" << "\n";
    cout << "8. Monthly Supreme – 30 Days, 20 GB, 5000 Jazz Min, 5000 SMS" << "\n";
    cout << "9. Monthly Hybrid – 30 Days, 12 GB, 1000 Jazz Min, 1000 SMS" << "\n";
    cout << "10. Monthly YouTube – 30 Days, 10 GB, No Calls, No SMS" << "\n";
    cout << "11. Monthly Extreme – 30 Days, 20 GB, No Calls, No SMS" << "\n";
    cout << "12. Daily Student Package – 1 Day, 2 GB, No Calls, No SMS" << "\n";
    cout << "13. Weekly Premium – 7 Days, 15 GB, No Calls, No SMS" << "\n";
    cout << "14. Monthly Supreme Plus – 30 Days, 45 GB, 10000 Jazz Min, 10000 SMS" << "\n";
    cout << "15. Monthly YouTube Plus – 30 Days, 15 GB, No Calls, No SMS" << "\n";
    cout << "16. Daily Extreme – 1 Day, 2 GB (Midnight Offer), No Calls, No SMS" << "\n";
    cout << "Enter the Selected Bundle : ";
    cin >> option;
   // Using Array For More Readability 
   double loadamount;
    string bundlename[16] = {"Daily Social","Daily Super","Daily YouTube","Daily Mega","Weekly Mega","Weekly Super Plus","Weekly Extreme","Monthly Supreme","Monthly Hybrid","Monthly YouTube","Monthly Extreme","Daily Student Package","Weekly Premium","Monthly Supreme Plus","Monthly YouTube Plus","Daily Extreme"};
    double prices[16] = {30,35,27,25,400,600,250,1300,1000,600,1500,50,450,2000,700,40};
    if (option > 0 && option <= 16) {
        int index = option - 1;
        cout << "You Have Selected " << bundlename[index] << " Bundle. The Price is Rs. " << prices[index] << "\n";
        if (function()) {
            balance -= prices[index];
            loadamount = prices[index];
            cout << "Your Transaction is Successfully Completed. " << "\n";
            cout << "Your New Balance is  Rs. " << balance << "\n\n";
            function2(cnic, loadamount, balance);
        }
    } else {
        cout << "Invalid Selection. Please Enter a Valid Option. \n";
    }
}
void telenorbundles(bool (*function)(),void (*function2)(string,double,double&), double& balance,string cnic) {
    int option;
    cout << "Welcome to Telenor Bundles and Offers" << "\n\n";
    cout << "1. Daily Social Pack – 1 Day, 1 GB, 100 Telenor Min, 100 SMS" << "\n";
    cout << "2. Daily YouTube – 1 Day, 2 GB, No Calls, No SMS" << "\n";
    cout << "3. Daily Heavy Data – 1 Day, 2.5 GB, No Calls, No SMS" << "\n";
    cout << "4. Weekly Easy Card – 7 Days, 6 GB, 1000 Telenor Min, 1000 SMS" << "\n";
    cout << "5. Weekly Mega – 7 Days, 10 GB, 500 Telenor Min, 500 SMS" << "\n";
    cout << "6. Weekly Extreme – 7 Days, 15 GB (Night Only), No Calls, No SMS" << "\n";
    cout << "7. Monthly Social – 30 Days, 12 GB, No Calls, No SMS" << "\n";
    cout << "8. Monthly Heavy – 30 Days, 30 GB, 5000 Telenor Min, 5000 SMS" << "\n";
    cout << "9. Monthly YouTube – 30 Days, 15 GB, No Calls, No SMS" << "\n";
    cout << "10. Monthly Supreme – 30 Days, 50 GB, 10,000 Telenor Min, 10,000 SMS" << "\n";
    cout << "11. Daily Data Max – 1 Day, 3 GB, No Calls, No SMS" << "\n";
    cout << "12. Weekly Hybrid – 7 Days, 12 GB, 2000 Telenor Min, 2000 SMS" << "\n";
    cout << "13. Weekly Social Plus – 7 Days, 4 GB, No Calls, No SMS" << "\n";
    cout << "14. Monthly Extreme – 30 Days, 70 GB (Night Only), No Calls, No SMS" << "\n";
    cout << "15. Monthly YouTube Plus – 30 Days, 20 GB, No Calls, No SMS" << "\n";
    cout << "Enter the Selected Bundle: ";
    cin >> option;
 double loadamount;
    // Using Array for Bundles and Prices
    string bundlename[15] = {
        "Daily Social Pack", "Daily YouTube", "Daily Heavy Data", "Weekly Easy Card",
        "Weekly Mega", "Weekly Extreme", "Monthly Social", "Monthly Heavy",
        "Monthly YouTube", "Monthly Supreme", "Daily Data Max", "Weekly Hybrid",
        "Weekly Social Plus", "Monthly Extreme", "Monthly YouTube Plus"
    };
    double prices[15] = {50, 70, 100, 200, 300, 250, 400, 700, 500, 1000, 120, 350, 150, 800, 600};

    if (option > 0 && option <= 15) {
        int index = option - 1;
        cout << "You Have Selected " << bundlename[index] << " Bundle. The Price is Rs. " << prices[index] << "\n";
        if (function()) {
            balance -= prices[index];
            loadamount = prices[index];
            cout << "Your Transaction is Successfully Completed. " << "\n";
            cout << "Your New Balance is  Rs. " << balance << "\n\n";
            function2(cnic, loadamount, balance);
        }
    } else {
        cout << "Invalid Selection. Please Enter a Valid Option. \n";
    }
}
void zongbundles(bool (*function)(),void (*function2)(string,double,double&), double& balance,string cnic) {
    int option;
    cout << "Welcome to Zong Bundles and Offers" << "\n\n";
    cout << "1. Daily Basic – 1 Day, 500 MB, 50 Zong Min, 50 SMS" << "\n";
    cout << "2. Daily YouTube – 1 Day, 1 GB, No Calls, No SMS" << "\n";
    cout << "3. Daily Data Max – 1 Day, 2.5 GB, No Calls, No SMS" << "\n";
    cout << "4. Weekly Super – 7 Days, 4 GB, 700 Zong Min, 700 SMS" << "\n";
    cout << "5. Weekly Premium – 7 Days, 8 GB, 500 Zong Min, 500 SMS" << "\n";
    cout << "6. Weekly Extreme – 7 Days, 10 GB (Night Only), No Calls, No SMS" << "\n";
    cout << "7. Monthly Premium – 30 Days, 30 GB, 5000 Zong Min, 5000 SMS" << "\n";
    cout << "8. Monthly Social – 30 Days, 12 GB, No Calls, No SMS" << "\n";
    cout << "9. Monthly YouTube – 30 Days, 12 GB, No Calls, No SMS" << "\n";
    cout << "10. Monthly Extreme – 30 Days, 50 GB (Night Only), No Calls, No SMS" << "\n";
    cout << "11. Daily Video – 1 Day, 1.5 GB, No Calls, No SMS" << "\n";
    cout << "12. Weekly Data Max – 7 Days, 12 GB, No Calls, No SMS" << "\n";
    cout << "13. Weekly Mega – 7 Days, 15 GB, No Calls, No SMS" << "\n";
    cout << "14. Monthly YouTube Plus – 30 Days, 20 GB, No Calls, No SMS" << "\n";
    cout << "15. Monthly Ultra – 30 Days, 60 GB, No Calls, No SMS" << "\n";
    cout << "Enter the Selected Bundle: ";
    cin >> option;
    double loadamount;
    string bundlename[15] = {
        "Daily Basic", "Daily YouTube", "Daily Data Max", "Weekly Super",
        "Weekly Premium", "Weekly Extreme", "Monthly Premium", "Monthly Social",
        "Monthly YouTube", "Monthly Extreme", "Daily Video", "Weekly Data Max",
        "Weekly Mega", "Monthly YouTube Plus", "Monthly Ultra"
    };
    double prices[15] = {20, 50, 100, 150, 200, 250, 500, 300, 400, 600, 70, 350, 500, 700, 1000};

    if (option > 0 && option <= 15) {
        int index = option - 1;
        cout << "You Have Selected " << bundlename[index] << " Bundle. The Price is Rs. " << prices[index] << "\n";
        if (function()) {
            balance -= prices[index];
            loadamount = prices[index];
            cout << "Your Transaction is Successfully Completed. " << "\n";
            cout << "Your New Balance is  Rs. " << balance << "\n\n";
            function2(cnic, loadamount, balance);
        }
    } else {
        cout << "Invalid Selection. Please Enter a Valid Option. \n";
    }
}
void ufonebundles(bool (*function)(), void (*function2)(string,double,double&),double& balance,string cnic) {
    int option;
    cout << "Welcome to Ufone Bundles and Offers" << "\n\n";
    cout << "1. Daily Chat – 1 Day, 500 MB, 100 Ufone Min, 100 SMS" << "\n";
    cout << "2. Daily Light – 1 Day, 1 GB, 200 Ufone Min, 200 SMS" << "\n";
    cout << "3. Daily YouTube – 1 Day, 1.5 GB, No Calls, No SMS" << "\n";
    cout << "4. Weekly Light – 7 Days, 5 GB, 1000 Ufone Min, 1000 SMS" << "\n";
    cout << "5. Weekly Heavy – 7 Days, 8 GB, 1500 Ufone Min, 1500 SMS" << "\n";
    cout << "6. Weekly Social – 7 Days, 3 GB (Social Only), No Calls, No SMS" << "\n";
    cout << "7. Monthly Social – 30 Days, 10 GB, No Calls, No SMS" << "\n";
    cout << "8. Monthly Heavy – 30 Days, 25 GB, 5000 Ufone Min, 5000 SMS" << "\n";
    cout << "9. Monthly Prime – 30 Days, 50 GB, 10000 Ufone Min, 10000 SMS" << "\n";
    cout << "10. Monthly Extreme – 30 Days, 75 GB (Night Only), No Calls, No SMS" << "\n";
    cout << "11. Daily Unlimited – 1 Day, 4 GB, No Calls, No SMS" << "\n";
    cout << "12. Weekly Mega – 7 Days, 12 GB, No Calls, No SMS" << "\n";
    cout << "13. Weekly Hybrid – 7 Days, 15 GB, 1000 Ufone Min, 1000 SMS" << "\n";
    cout << "14. Monthly Supreme – 30 Days, 35 GB, No Calls, No SMS" << "\n";
    cout << "15. Monthly YouTube Plus – 30 Days, 18 GB, No Calls, No SMS" << "\n";
    cout << "Enter the Selected Bundle: ";
    cin >> option;
    double loadamount;
    string bundlename[15] = {
        "Daily Chat", "Daily Light", "Daily YouTube", "Weekly Light",
        "Weekly Heavy", "Weekly Social", "Monthly Social", "Monthly Heavy",
        "Monthly Prime", "Monthly Extreme", "Daily Unlimited", "Weekly Mega",
        "Weekly Hybrid", "Monthly Supreme", "Monthly YouTube Plus"
    };
    double prices[15] = {10, 30, 50, 100, 150, 120, 250, 500, 700, 1000, 70, 300, 400, 600, 800};

    if (option > 0 && option <= 15) {
        int index = option - 1;
        cout << "You Have Selected " << bundlename[index] << " Bundle. The Price is Rs. " << prices[index] << "\n";
        if (function()) {
            balance -= prices[index];
            loadamount = prices[index];
            cout << "Your Transaction is Successfully Completed. " << "\n";
            cout << "Your New Balance is  Rs. " << balance << "\n\n";
            function2(cnic, loadamount, balance);
        }
    } else {
        cout << "Invalid Selection. Please Enter a Valid Option. \n";
    }
}


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
// Function to check Wallet Number
bool checklenghtwallet (string account){
    if (account.length() != 11 ){
    return false ; }
   
    for (int i = 0 ; i <11 ; i++ ){
       if (account[i] < '0' || account [i] > '9' ) {
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
       
    for (int i = 0 ; i <13 ; i++ )
        if (cnicc[i] < '0' || cnicc [i] > '9' ) {
            return false;
        }
        
   return true;
   }
// Validate Pin
bool checkpin (string pinn) {
      if (pinn.length() !=4){
    return false;
}
for (int i = 0 ; i <4 ; i++ ){
    if (pinn[i] < '0' || pinn [i] > '9' ) {
        return false;
    }
    }

return true;

}
string removeSpaces(const string& str) {
    string result;
    for (char c : str) {
        if (c != ' ') { // Ignore spaces
            result += c;
        }
    }
    return result;
}

// Saving New Accounts
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
            cnic = cnic2;
            data.close();
            return true; 
        }
    }
    }
  
    data.close();
    if (!data.is_open()) {
        cout << "Error: Unable to open file.\n";
        return false;
    }
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
        string newenteredusername = removeSpaces(enteredusername);
        string newstoredusername = removeSpaces(username);
        string newstoredpassword = removeSpaces(password);
        string newenteredpassword = removeSpaces(enteredpassword);

        if (cnic == enteredcnic) {
            cnicfound = true;

            if (newstoredusername == newenteredusername && newstoredpassword == newenteredpassword) {
                logindata.close();
                return  true;
            }
        }
    }

    logindata.close();
    
    if (!cnicfound) {
        cout << "There is No Registered Account Against this CNIC, Please Register an Account First.\n";
    } else {
        cout << "Please Enter Correct Username or Password to Login.\n";
        return false;
    }
    
    return cnicfound;
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
    
    
    return cnicfound;
}
// Function To Save Only Username and Password For Login
void savelogindata( const string cnic ,string& username, string& password) {

    ofstream recenttrans("logindata.txt", ios::app);
    string newusername = removeSpaces(username);
    string newpassword = removeSpaces(password);
    // Check if the file opened successfully
    if (recenttrans.is_open())
    {
        recenttrans  << cnic << "," << newusername << "," << newpassword << "\n" ;// Append data to the file  
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
void bundletransaction(string cnic,double loadamount, double& balance){
    string filename = "User_" + cnic + ".txt";
    ofstream recenttrans(filename, ios::app);
    // Check if the file opened successfully
    if (recenttrans.is_open())
    {
        recenttrans << "Subscribed Bundle Rs. " << loadamount << ", New Balance is Rs. " << balance << "\n";
        recenttrans.close();
    }
    else
    {
        cout << "There is an Error in Opening The File. \n";
    }
}
void loadtransaction(string cnic,double loadamount, double& balance){
    string filename = "User_" + cnic + ".txt";
    ofstream recenttrans(filename, ios::app);
    // Check if the file opened successfully
    if (recenttrans.is_open())
    {
        recenttrans << "Loaded Rs. " << loadamount << ", New Balance is Rs. " << balance << "\n";
        recenttrans.close();
    }
    else
    {
        cout << "There is an Error in Opening The File. \n";
    }
}


// Function to Reset and Change Credintials Like Username, Password, and Pin.
void resetpassword(string& password, const string& cnic) {
    string userinputcnic;
    cout << "Enter Your 13 Digit National Identification Number : ";
    getline(cin, userinputcnic);
    int tryagain = 4;
    while (!checkcnic(userinputcnic) && tryagain > 0)
{
    cout << "Error! National Identification Number is Not Valid, Please Enter Valid  National Identification Number. \n";
    cout << " Please Enter Again (Limit 4 Times) : ";
    cin >> userinputcnic;
    tryagain--;
    if (tryagain == 0)
    {
        cout << "\n You Failed to Enter Valid National Identification Number, Returning Back to Main Menu. \n\n";
        break;
    }
}
    string newpassword;
    cout << "Enter Your New Password: ";
    cin >> newpassword;

    password = newpassword;
    cout << "Password Reset Successfully!\n";

    // Update password in the file
    ifstream infile("logindata.txt");
    ofstream outfile("temp.txt");
    string line;

    while (getline(infile, line)) {
        stringstream ss(line);
        string cnicfile, usernamefile, passwordfile;
        getline(ss, cnicfile, ',');
        getline(ss, usernamefile, ',');
        getline(ss, passwordfile, ',');

        if (cnicfile == cnic) {
            outfile << cnicfile << "," << usernamefile << "," << password << "\n";
        } else {
            outfile << line << "\n";
        }
    }

    infile.close();
    outfile.close();

    // Replace the old file with the updated one
    remove("logindata.txt");
    rename("temp.txt", "logindata.txt");
}
void changepassword(string& password, const string& cnic) {
    string newpassword;
    cout << "Enter Your New Password: ";
    cin >> newpassword;

    password = newpassword;
    cout << "Password Changed Successfully!\n";

    // Update password in the file
    ifstream infile("logindata.txt");
    ofstream outfile("temp.txt");
    string line;

    while (getline(infile, line)) {
        stringstream ss(line);
        string cnicfile, usernamefile, passwordfile;
        getline(ss, cnicfile, ',');
        getline(ss, usernamefile, ',');
        getline(ss, passwordfile, ',');

        if (cnicfile == cnic) {
            outfile << cnicfile << "," << usernamefile << "," << password << "\n";
        } else {
            outfile << line << "\n";
        }
    }

    infile.close();
    outfile.close();

    // Replace the old file with the updated one
    remove("logindata.txt");
    rename("temp.txt", "logindata.txt");
}
void resetusername(string& username, const string& cnic) {

    string userinputcnic;
    cout << "Enter Your 13 Digit National Identification Number : ";
    getline(cin, userinputcnic);
    int tryagain = 4;
    while (!checkcnic(userinputcnic) && tryagain > 0)
{
    cout << "Error! National Identification Number is Not Valid, Please Enter Valid  National Identification Number. \n";
    cout << " Please Enter Again (Limit 4 Times) : ";
    cin >> userinputcnic;
    tryagain--;
    if (tryagain == 0)
    {
        cout << "\n You Failed to Enter Valid National Identification Number, Returning Back to Main Menu. \n\n";
        break;
    }
}

    string newusername;
    cout << "Enter Your New Username: ";
    cin >> newusername;

    // Check if the new username is unique
    ifstream logindata("logindata.txt");
    string line, cnicfile, usernamefile, passwordfile;
    bool is_unique = true;

    while (getline(logindata, line)) {
        stringstream ss(line);
        getline(ss, cnicfile, ',');
        getline(ss, usernamefile, ',');
        getline(ss, passwordfile, ',');

        if (usernamefile == newusername) {
            is_unique = false;
            break;
        }
    }

    logindata.close();

    if (is_unique) {
        username = newusername;
        cout << "Username Reset Successfully!\n";

        // Update username in the file
        ifstream infile("logindata.txt");
        ofstream outfile("temp.txt");

        while (getline(infile, line)) {
            stringstream ss(line);
            getline(ss, cnicfile, ',');
            getline(ss, usernamefile, ',');
            getline(ss, passwordfile, ',');

            if (cnicfile == cnic) {
                outfile << cnicfile << "," << username << "," << passwordfile << "\n";
            } else {
                outfile << line << "\n";
            }
        }

        infile.close();
        outfile.close();

        // Replace the old file with the updated one
        remove("logindata.txt");
        rename("temp.txt", "logindata.txt");
    } else {
        cout << "Username already exists! Please choose a different username.\n";
    }
}
void changeusername(string& username, const string& cnic) {
    string newusername;
    cout << "Enter Your New Username: ";
    cin >> newusername;

    // Check if the new username is unique
    ifstream logindata("logindata.txt");
    string line, cnicfile, usernamefile, passwordfile;
    bool is_unique = true;

    while (getline(logindata, line)) {
        stringstream ss(line);
        getline(ss, cnicfile, ',');
        getline(ss, usernamefile, ',');
        getline(ss, passwordfile, ',');

        if (usernamefile == newusername) {
            is_unique = false;
            break;
        }
    }

    logindata.close();

    if (is_unique) {
        // Assign the new username only if it is unique
        username = newusername;
        cout << "Username Changed Successfully!\n";

        // Update username in the file
        ifstream infile("logindata.txt");
        ofstream outfile("temp.txt");

        while (getline(infile, line)) {
            stringstream ss(line);
            getline(ss, cnicfile, ',');
            getline(ss, usernamefile, ',');
            getline(ss, passwordfile, ',');

            if (cnicfile == cnic) {
                outfile << cnicfile << "," << username << "," << passwordfile << "\n";
            } else {
                outfile << line << "\n";
            }
        }

        infile.close();
        outfile.close();

        // Replace the old file with the updated one
        remove("logindata.txt");
        rename("temp.txt", "logindata.txt");
    } else {
        cout << "Username already exists! Please choose a different username.\n";
    }
}
void changepin(string& pin, const string& cnic) {
    string existingpin, newpin;
    cout << "Enter Your Current PIN: ";
    cin >> existingpin;

    // Verify current PIN
    if (existingpin != pin) {
        cout << "Error: Incorrect current PIN. Please try again.\n";
        return;
    }

    // Validate new PIN
    cout << "Enter Your New 4-Digit PIN: ";
    cin >> newpin;

    if (newpin.length() == 4 && newpin.find_first_not_of("0123456789") == string::npos) {
        pin = newpin;
        cout << "PIN Changed Successfully!\n";

        // Update PIN in the file
        ifstream infile("allaccounts.txt");
        ofstream outfile("temp.txt");
        string line;

        while (getline(infile, line)) {
            stringstream ss(line);
            string name, cnicfile, acc_num, balance, pinfile;
            getline(ss, name, ',');
            getline(ss, cnicfile, ',');
            getline(ss, acc_num, ',');
            getline(ss, balance, ',');
            getline(ss, pinfile, ',');

            if (cnicfile == cnic) {
                outfile << name << "," << cnicfile << "," << acc_num << "," << balance << "," << pin << "\n";
            } else {
                outfile << line << "\n";
            }
        }

        infile.close();
        outfile.close();

        // Replace the old file with the updated one
        remove("allaccounts.txt");
        rename("temp.txt", "allaccounts.txt");
    } else {
        cout << "Invalid PIN! PIN must be a 4-digit number.\n";
    }
}
void resetpin(string& pin, const string& cnic) {
    string userinputcnic;
    cout << "Enter Your 13 Digit National Identification Number : ";
    getline(cin, userinputcnic);
    int tryagain = 4;
    while (!checkcnic(userinputcnic) && tryagain > 0)
{
    cout << "Error! National Identification Number is Not Valid, Please Enter Valid  National Identification Number. \n";
    cout << " Please Enter Again (Limit 4 Times) : ";
    cin >> userinputcnic;
    tryagain--;
    if (tryagain == 0)
    {
        cout << "\n You Failed to Enter Valid National Identification Number, Returning Back to Main Menu. \n\n";
        break;
    }
}
    string username, newpin;
    cout << "Enter Your Username: ";
    cin >> username;

    // Verify user identity
    ifstream logindata("logindata.txt");
    string line, cnicfile, usernamefile, passwordfile;
    bool user_found = false;

    while (getline(logindata, line)) {
        stringstream ss(line);
        getline(ss, cnicfile, ',');
        getline(ss, usernamefile, ',');
        getline(ss, passwordfile, ',');

        if (cnicfile == cnic && usernamefile == username) {
            user_found = true;
            break;
        }
    }

    logindata.close();

    if (!user_found) {
        cout << "Error: User not found. Please check your CNIC and username.\n";
        return;
    }

    // Validate new PIN
    cout << "Enter Your New 4-Digit PIN: ";
    cin >> newpin;

    if (newpin.length() == 4 && newpin.find_first_not_of("0123456789") == string::npos) {
        // Update PIN in allaccounts.txt
        ifstream infile("allaccounts.txt");
        ofstream outfile("temp.txt");
        string line;

        while (getline(infile, line)) {
            stringstream ss(line);
            string name, cnicfile, acc_num, balance, pinfile;
            getline(ss, name, ',');
            getline(ss, cnicfile, ',');
            getline(ss, acc_num, ',');
            getline(ss, balance, ',');
            getline(ss, pinfile, ',');

            if (cnicfile == cnic) {
                outfile << name << "," << cnicfile << "," << acc_num << "," << balance << "," << newpin << "\n";
            } else {
                outfile << line << "\n";
            }
        }

        infile.close();
        outfile.close();

        // Replace the old file with the updated one
        remove("allaccounts.txt");
        rename("temp.txt", "allaccounts.txt");


        cout << "PIN Reset Successfully!\n";
    } else {
        cout << "Invalid PIN! PIN must be a 4-digit number.\n";
}
}

int main()
{   
    // Declaring Variables
    double deposit = 0, balance = 0, withdrawal = 0, notfixedacc = 0,
    transfermoney=0;
    int transferoption, option,accountoption,walletnumber, tryagain = 4,tryagainn = 4;
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
            
            cout << "Enter Your Name : ";
            getline(cin, name);

            // National ID Validation (13-Digit CNIC) with 4 Time Limit
            cout << "Enter Your 13 Digit National Identification Number : ";
            getline(cin, cnic);
            while (!checkcnic(cnic) && tryagainn > 0)
            {
                cout << "Error! National Identification Number is Not Valid, Please Enter Valid  National Identification Number. \n";
                cout << " Please Enter Again (Limit 4 Times) : ";
                getline (cin,cnic);
                tryagainn--;
                if (tryagain == 0)
                {
                    cout << "\n You Failed to Enter Valid National Identification Number, Returning Back to Main Menu. \n\n";
                
                    return 0;
                }
            }

            // Checking if cnic already exists
           bool check = checkduplicatecnic(cnic,username,password);
         
           if (check) {
            cout << "This CNIC is Already Registered. Please Login To Continue.\n";
            return 0;        
        } 
           else {
            cout << "CNIC is Unique. Proceeding..." << endl;
        }        

            // Generating Radnom Account Number
            notfixedacc = rand() % 900000 + 100000;

              // Create a Pin
            cout << "Enter to Create Your 4 Digit Pin Code : ";
            getline(cin, pin);
           
            while (tryagain > 0 && !checkpin(pin))
   {        cout << "Please Enter Valid 4-Digit Pin  \n";
            cout << "Please,Enter Your Pin (Try Again Limit = 4) : ";
           getline (cin,pin);
           tryagain -- ;
              if (tryagain == 0)
              {
                cout << "You Failed to Enter Valid Pin, Returning Back to Main Menu. \n";
                return 0;
           }
    }
          cout << "Pin is Valid. Proceeding... \n";
                  // Creating User name and Password For Banking Services
            cout << "Thanks For Creating Account in Sharif Bank Ltd, Please Create a UserName and Password to Enjoy our Banking Services.\n";
            cout << "Enter Your User Name (Spaces Will Be Automatically Terminated) : ";
            getline(cin,username);
            cout << "Enter Your Password (Spaces Will Be Automatically Terminated) -: ";
            getline(cin,password);
            // Account Created Successfully
            cout << "Congratulations " << name << "! You Have Successfully Created Account With Account Number "
                << "\n" << fixedaccnbr << notfixedacc << " Against Identification Number " << cnic << ". \n";
            cout << "You have been Given Rs 100 as Bonus on Creating a New Account. \n";
            cout << "Please Login To Continue. \n\n";
            balance = 100; 
            // Calling Function to Log Details into the File        
            savenewaccounts(name,  cnic, notfixedacc, balance ,pin);
            savetransaction(name,cnic,notfixedacc,balance);
            savelogindata(cnic,username,password);
            return 0;
            

}




        // Login Back into Account
    else if (accountoption == 2)
        {
            string usercnic,userpass,username;
            cout << "Enter Your CNIC : " ;
            cin >> usercnic;
            
            cout << "Enter Your User Name : " ;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            getline (cin,username);
            
            cout << "Enter Your Password : " ;
            getline(cin,userpass);

         if (validatelogin(usercnic,username,userpass))
        { 

          if (loadvariableinfo(name,usercnic,notfixedacc,balance,pin)){
          cout <<  "Welcome Back " << name << ", Enjoy Your Seamless Banking With Sharif Bank Ltd.\n\n ";
          while (option != 7)
    {
        cout << "Please Select an Option to Proceed ! \n\n";
        cout << "1. Deposit Money in Your Account" << "\n" << "2. Withdrawl Money From Your Account " << "\n" 
             << "3. Transfer Money " << "\n" << "4. View Account Information " << "\n"  
             << "5. Credentials Management " << "\n" << "6. Load and Bundles" << "\n" 
             << "7. Exit " << "\n\n";
        option = checkinputtype("Enter the Selected Option : ");

       
        // Depositing Money
         if (option == 1)
        {
            // Validate Pin To Deposit
            if (pincheck(pin))
            {    
                cout << "Deposit Limit is Rs. 1000000. \n";
                deposit = checkinputtype("Enter The Amount To Deposit Into Your Account : Rs. ");
                if (deposit >= 0 && deposit <= 1000000 )
                {
                    balance = balance + deposit;
                    cout << "Your Transaction is Successfully Completed. " << "\n";
                    cout << "Your New Balance is  Rs. " << balance << "\n\n";
                    // Calling Function to Log Details into the File        
                    depositamount(usercnic,deposit, balance);
                   
                }
                else if (deposit > 1000000)
                {
                    cout << "Sorry! You Can't Deposit More Than Rs. 1000000. ";
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
                cout << "Withdrawal Limit is Rs. 100000. \n";
                withdrawal = checkinputtype("Enter The Amount To Withdrawal From Your Account : Rs. ");
                if (balance > withdrawal && withdrawal > 0 && withdrawal <= 100000)
                {
                    balance = balance - withdrawal;
                    cout << "Your Transaction is Successfully Completed. " << "\n";
                    cout << "Your New Balance is  Rs. " << balance << "\n\n";

                    // Calling Function to Log Details into the File        
                    withdrawamount(usercnic,withdrawal, balance);
                }
                else if (withdrawal > 100000)
                {
                    cout << "Sorry! You Can't Withdraw More Than Rs. 100000. ";
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
                cout << "Please Enter a Valid Account Number ! " << "\n\n";
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
                cout << "\n";
                recentfile.close();
            }
            else {
                cout << "Error opening the file.\n";
            }


        }

        // Modify Account Information Like Pin,Username,Password
        else if (option == 5)
        {
            int  newoption ;
            cout << "\nPlease Select an Option  ! " << "\n\n";
            cout << "1. Change Pin Code " << "\n" << "2. Reset Pin" << "\n";
            cout << "3. Change Username " << "\n" << "4. Reset Username" << "\n";
            cout << "5. Change Password " << "\n" << "6. Reset Password" << "\n\n";
            // Validating Input Data Type
            newoption = checkinputtype("Enter the Option : ");
            switch (newoption)
            {
            case 1:
                 changepin(pin,usercnic);
                break;
            case 2 :
                  resetpin(pin,usercnic);
                break;
            case 3 :
                  changeusername(username,usercnic);
                break;
            case 4 :
                   resetusername(username,usercnic);
                break;
            case 5 :
                    changepassword(userpass,usercnic);
                break;
            case 6 :
                    resetpassword(userpass,usercnic);
                break;
            
            default:
               cout << "Enter a Valid Option From 1 - 6." << "\n";
                break;
            }

        }

        else if (option==6)
        {
            cout << "Welcome to Load and Bundles Section. \n";
            cout << "1. Load Balance " << "\n" << "2. Buy Bundles " << "\n\n";
            int loadoption = checkinputtype("Enter the Option : ");
            if (loadoption == 1)
            {
                cout << "Please Select the Network to Load Balance \n";
                cout << "1. Jazz \n" << "2. Telenor \n" << "3. Zong \n" << "4. Ufone \n\n";
                int network = checkinputtype("Select the Network : ");

                switch (network)
                {
                    case 1 :
                    loadinterface(valiate_jazznbr,loadtransaction,balance,usercnic);
                    break;
                    case 2 :
                    loadinterface(valiate_telenornbr,loadtransaction,balance,usercnic);
                    break;
                    case 3 :
                    loadinterface(valiate_zongnbr,loadtransaction,balance,usercnic);
                    break;
                    case 4 :
                    loadinterface(valiate_ufonenbr,loadtransaction,balance,usercnic);
                    break;
                }
            
            }
            else if (loadoption == 2)
            {
                cout << "Please Select the Bundle to Buy \n";
                cout << "1. Jazz \n" << "2. Telenor \n" << "3. Zong \n" << "4. Ufone \n\n";
                int network = checkinputtype("Enter the Network : ");
                
                switch (network)
                {
                    case 1 :
                    jazzbundles(valiate_jazznbr, bundletransaction, balance,usercnic);
                    break;
                    break;
                    case 2 :
                    telenorbundles(valiate_telenornbr,bundletransaction,balance,usercnic);
                    break;
                    case 3 :
                    zongbundles(valiate_zongnbr,bundletransaction,balance,usercnic);
                    break;
                    case 4 :
                    ufonebundles(valiate_ufonenbr,bundletransaction,balance,usercnic);
                    break;
                }
            }  

        // Exit
        else if (option == 7)
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
        }
          else {
            cout << "Sorry, We Cannot Retrieve Your Information.\n\n";
          }
            
        }


    }

    else {
        cout << "\nPlease Select a Valid Option.\n";
    }
}
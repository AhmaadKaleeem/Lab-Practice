/* Implement a C++ program for a company that maintains employee records in a text file.
 Each employee record contains the employee ID, name, department, and salary. The program should manage the following tasks:
Add new employee records to the file.
Display all employee records.
Search for an employee by their ID and display their details.
Update the salary of a specific employee.
Delete a specific employee's record from the file.
*/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void validateid(int& employeeid, string& department , int& salary )
{
int tryagain = 10;
while (tryagain!=0){
  cout << "Enter the Employee ID Upto Three Digit: ";
  cin >> employeeid;
  if (employeeid<=999 && employeeid >=1) {
  cout << "Enter the Employee Department : ";
  cin >> department;
  cout << "Enter the Employee Salary : ";
  cin >> salary;
   if (salary<0)
  {cout << "Salary Cannot Be Less Than Zero.";
  }
  break;
  }
  else {
   if (employeeid>=1000 || employeeid==0){
    cout << "Please, Enter a Valid Three Digit Employee Id.\n";
    tryagain--;
    continue;
    
  } 
  else if (employeeid<0){
    cout << "Employee Id must Contain Non-Negative Digits.\n";
    tryagain--;
    continue;
  }
  else if (tryagain==0){
    cout << "Please Try Again Adding The Data.";
    break; }
  }
 }
}

void newdata(string& name , int& employeeid ,  string& department , int& salary)
{
  int tryagain = 10;
  cout << "Enter the Employee Name : ";
  cin >> name;

  validateid(employeeid, department, salary);
  
  ofstream record ("record data.txt", ios::app);
  if (record.is_open()){
  record << "Name : " << name << ", ID : " <<employeeid << ", Department : " << department << ", Salary : Rs." <<salary <<endl;
  record.close();
  }
  else {
  cout << "There is an Error in Opening the File.";
  }

  }

void displaydata(string newdata)
{

  ifstream record("record data.txt");
  if (record.is_open())
  {
  while(getline(record,newdata)){
    cout << newdata <<"\n";
  };
  record.close(); 
  }
  else
  {
   cout << "There is an Error in Opening the File.";
  }
}

void searchemployee(int& employeeid, string&name ,  string& department , int& salary)
{
  int id;
cout << "Please Enter Employee ID : ";
cin >> id;

}
int main() {
string name,department,data;
int employeeid,salary,choice;

cout << "\t\t\t\t Welcome To Sharif (Pvt) Ltd. Management System \n";
cout << "----------------------------------------------------------------------------------------------------------------------------------------------------\n\n";

cout << "1. Add New Employee Record. \n" << "2. Display All Records. \n" << "3. Search For an Employee. \n" << "4. Update Salary of a Employee. \n"
     << "5. Delete an Employee Record From Records. \n\n";
cout << "Select the Task from Given Menu : ";
cin  >> choice;

if (choice==1)
{
newdata(name,employeeid,department,salary);
}
else if(choice==2)
{
  displaydata(data);
}
else if (choice==3)
{

}

}

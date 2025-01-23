#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <iomanip>
#include <vector>
#include <sstream>
#include <map>

using namespace std;

struct User {
    string username;
    string password;
    string role; // Role (Admin, Teacher, Student)
};

// Function to validate login
bool validateLogin(const string &file, const string &username, const string &password, string &role) {
    ifstream inFile(file);
    string storedUsername, storedPassword, storedRole;

    while (inFile >> storedUsername >> storedPassword >> storedRole) {
        if (storedUsername == username && storedPassword == password) {
            role = storedRole;
            return true;
        }
    }
    return false;
}

// Function to add a user (Admin, Teacher, or Student)
void addUser(const string &file, const string &username, const string &password, const string &role) {
    ofstream outFile(file, ios::app);
    outFile << username << " " << password << " " << role << endl;
    cout << "User added successfully.\n";
}

// Function to remove a user
void removeUser(const string &file, const string &username) {
    ifstream inFile(file);
    ofstream tempFile("temp.txt");
    string storedUsername, storedPassword, storedRole;

    while (inFile >> storedUsername >> storedPassword >> storedRole) {
        if (storedUsername != username) {
            tempFile << storedUsername << " " << storedPassword << " " << storedRole << endl;
        }
    }
    inFile.close();
    tempFile.close();
    remove(file.c_str());
    rename("temp.txt", file.c_str());
    cout << "User removed successfully.\n";
}

// Function to update the user profile (password, username)
void updateProfile(string &username, string &password) {
    cout << "Enter new password: ";
    cin >> password;
    cout << "Profile updated successfully.\n";
}

void updateGrades(const string &username, const string &subject) {
    string fileName = username + "_grades.txt";
    ifstream gradeFile(fileName);
    if (!gradeFile) {
        cout << "Grade file not found for student: " << username << endl;
        return;
    }

    // Temporary file to store updated grades
    ofstream tempFile("temp.txt");
    string currentSubject, grade;
    bool found = false;

    // Process each record
    while (gradeFile >> currentSubject >> grade) {
        if (currentSubject == subject) {
            cout << "Current grade for " << subject << ": " << grade << endl;
            cout << "Enter new grade: ";
            cin >> grade;
            found = true;
        }
        tempFile << currentSubject << " " << grade << endl;
    }

    gradeFile.close();
    tempFile.close();

    // Replace original file with updated file
    if (found) {
        remove(fileName.c_str());
        rename("temp.txt", fileName.c_str());
        cout << "Grade updated successfully for " << subject << ".\n";
    } else {
        remove("temp.txt");
        cout << "Subject not found in grade records.\n";
    }
}

// Function to generate report for a class
void generateClassReport(const string &className) {
    ifstream inFile(className + "_students.txt");
    if (!inFile) {
        cout << "No students found for class " << className << ".\n";
        return;
    }

    cout << "\nGenerating Class Report for Class: " << className << endl;
    cout << "-----------------------------------------------\n";
    cout << setw(15) << "Student" << setw(15) << "Subject" << setw(10) << "Grade\n";
    cout << "-----------------------------------------------\n";

    string studentUsername;
    while (inFile >> studentUsername) {
        ifstream gradeFile(studentUsername + "_grades.txt");
        string subject, grade;
        while (gradeFile >> subject >> grade) {
            cout << setw(15) << studentUsername << setw(15) << subject << setw(10) << grade << endl;
        }
        gradeFile.close();
    }
    cout << "-----------------------------------------------\n";
    inFile.close();
}

// Function for generating individual student report
void generateStudentReport(const string &username) {
    ifstream gradeFile(username + "_grades.txt");
    if (!gradeFile) {
        cout << "No grades found for student " << username << ".\n";
        return;
    }

    cout << "\nGenerating Report for Student: " << username << endl;
    cout << "-----------------------------------\n";
    cout << setw(15) << "Subject" << setw(10) << "Grade\n";
    cout << "-----------------------------------\n";

    string subject, grade;
    while (gradeFile >> subject >> grade) {
        cout << setw(15) << subject << setw(10) << grade << endl;
    }
    cout << "-----------------------------------\n";
    gradeFile.close();
}

// Admin menu with added features
void adminMenu() {
    while (true) {
        cout << "\nAdmin Menu:\n";
        cout << "1. Add User\n";
        cout << "2. Remove User\n";
        cout << "3. Update User Profile\n";
        cout << "4. Generate Class Report\n";
        cout << "5. Exit\n";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1: {
                string username, password, role;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                cout << "Enter role (Admin/Teacher/Student): ";
                cin >> role;
                addUser("users.txt", username, password, role);
                break;
            }
            case 2: {
                string username;
                cout << "Enter username to remove: ";
                cin >> username;
                removeUser("users.txt", username);
                break;
            }
            case 3: {
                string username, password;
                cout << "Enter username: ";
                cin >> username;
                cout << "Enter new password: ";
                cin >> password;
                updateProfile(username, password);
                break;
            }
            case 4: {
                string className;
                cout << "Enter class name: ";
                cin >> className;
                generateClassReport(className);
                break;
            }
            case 5:
                return;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

// Teacher menu with added features
void teacherMenu(const string &username) {
    while (true) {
        string className;
        cout << "\nAvailable Classes for Teacher " << username << ":\n";
        cout << "1. IT\n2. CS\n3. CYS\n";
        cout << "Enter the number corresponding to the class you want to manage: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: className = "IT"; break;
            case 2: className = "CS"; break;
            case 3: className = "CYS"; break;
            default: cout << "Invalid choice.\n"; continue;
        }

        while (true) {
            cout << "\nTeacher Menu (Class: " << className << "):\n";
            cout << "1. View Review Requests\n";
            cout << "2. Update Grades\n";
            cout << "3. Generate Class Report\n";
            cout << "4. Exit\n";

            int choice;
            cin >> choice;

            switch (choice) {
                case 1: {
                    ifstream inFile(className + "_reviews.txt");
                    if (!inFile) {
                        cout << "No review requests found.\n";
                    } else {
                        string review;
                        while (getline(inFile, review)) {
                            cout << review << endl;
                        }
                    }
                    break;
                }
                case 2: {
                    cout << "Enter student username: ";
                    string studentUsername;
                    cin >> studentUsername;

                    fstream gradeFile(studentUsername + "_grades.txt", ios::in | ios::out | ios::app);
                    if (!gradeFile) {
                        cout << "No grades found for this student. Creating file...\n";
                        gradeFile.open(studentUsername + "_grades.txt", ios::out);
                    }

                    cout << "Enter new grade (subject grade): ";
                    string subject, grade;
                    cin >> subject >> grade;
                    gradeFile << subject << " " << grade << endl;
                    cout << "Grade updated successfully.\n";

                    gradeFile.close();
                    break;
                }
                case 3:
                    generateClassReport(className);
                    break;
                case 4:
                    return;
                default:
                    cout << "Invalid choice.\n";
            }
        }
    }
}

// Student menu with added features
void studentMenu(const string &username) {
    while (true) {
        cout << "\nStudent Menu:\n";
        cout << "1. View Grades\n";
        cout << "2. Request Grade Review\n";
        cout << "3. Exit\n";
        
        int choice;
        cin >> choice;
        
        switch (choice) {
            case 1: {
                generateStudentReport(username);
                break;
            }
            case 2: {
                string review;
                cout << "Enter your grade review request: ";
                cin.ignore();  // Clear the input buffer
                getline(cin, review);

                ofstream reviewFile(username + "_reviews.txt", ios::app);
                reviewFile << review << endl;
                cout << "Review request submitted.\n";
                break;
            }
            case 3:
                return;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

// Main function
int main() {
    string username, password, role;
    int choice;

    while (true) {
        cout << "\nWelcome to the system. Please select your login type:\n";
        cout << "1. Admin\n2. Teacher\n3. Student\n4. Exit\n";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter admin username: ";
                cin >> username;
                cout << "Enter admin password: ";
                cin >> password;

                if (validateLogin("users.txt", username, password, role) && role == "ADMIN") {
                    cout << "Login successful. Welcome Admin.\n";
                    adminMenu();
                } else {
                    cout << "Invalid credentials or not an admin.\n";
                }
                break;

            case 2:
                cout << "Enter teacher username: ";
                cin >> username;
                cout << "Enter teacher password: ";
                cin >> password;

                if (validateLogin("users.txt", username, password, role) && role == "TEACHER") {
                    cout << "Login successful. Welcome Teacher.\n";
                    teacherMenu(username);
                } else {
                    cout << "Invalid credentials or not a teacher.\n";
                }
                break;

            case 3:
                cout << "Enter student username: ";
                cin >> username;
                cout << "Enter student password: ";
                cin >> password;

                if (validateLogin("users.txt", username, password, role) && role == "STUDENT") {
                    cout << "Login successful. Welcome Student.\n";
                    studentMenu(username);
                } else {
                    cout << "Invalid credentials or not a student.\n";
                }
                break;

            case 4:
                cout << "Exiting system.\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}

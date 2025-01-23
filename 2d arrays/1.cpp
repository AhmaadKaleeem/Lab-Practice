#include <iostream>
#include <fstream>
#include <string>
using namespace std;

const int ROWS = 10;
const int COLS = 10;
char seats[ROWS][COLS];

string createfilename(int month, int date, int year);

// Initialize seats for the given month and date
void initializeSeats(int month, int date ,int year) {
    string filename = createfilename(month, date,year);
    ifstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                file >> seats[i][j];
            }
        }
        file.close();
    }
     else {
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                seats[i][j] = 'A'; 
            }
        }
        ofstream newFile(filename);
        for (int i = 0; i < ROWS; ++i) {
            for (int j = 0; j < COLS; ++j) {
                newFile << seats[i][j] << " ";
            }
            newFile << endl;
        }
        newFile.close();
    }
}

void savetofile(int month, int date,int year) {
    string filename = createfilename(month, date,year);
    ofstream file(filename);
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            file << seats[i][j] << " ";
        }
        file << endl;
    }
    file.close();
}

void displaySeats() {
    cout << "\nSeating Arrangement (A = Available, B = Booked):\n";
    cout << "   ";
    for (int j = 0; j < COLS; ++j) {
        cout << "S" << (j + 1);
        if (j < 9) cout << "  ";
        else cout << " ";
    }
    cout << endl;

    for (int i = 0; i < ROWS; ++i) {
        cout << "R" << (i + 1);
        if (i < 9) cout << "  ";
        else cout << " ";

        for (int j = 0; j < COLS; ++j) {
            cout << seats[i][j] << "   ";
        }
        cout << endl;
    }
}

void bookseat(int month, int date,int year) {
    int row, col;
    cout << "Enter row (1-10): ";
    cin >> row;
    cout << "Enter column (1-10): ";
    cin >> col;
    if (row < 1 || row > ROWS || col < 1 || col > COLS) {
        cout << "Invalid seat position.\n";
        return;
    }
    if (seats[row - 1][col - 1] == 'A') {
        seats[row - 1][col - 1] = 'B';
        savetofile(month, date,year);
        cout << "Seat booked successfully.\n";
        cout << "Thanks For Booking." << endl;
    } else {
        cout << "Seat is already booked.\n";
    }
}

void cancelSeat(int month, int date,int year) {
    int row, col;
    cout << "Enter row (1-10): ";
    cin >> row;
    cout << "Enter column (1-10): ";
    cin >> col;
    if (row < 1 || row > ROWS || col < 1 || col > COLS) {
        cout << "Invalid seat position.\n";
        return;
    }
    if (seats[row - 1][col - 1] == 'B') {
        seats[row - 1][col - 1] = 'A';
        savetofile(month, date,year);
        cout << "Seat reservation canceled successfully.\n";
    } else {
        cout << "Seat is already available.\n";
    }
}

void checkSeatStatus() {
    int row, col;
    cout << "Enter row (1-10): ";
    cin >> row;
    cout << "Enter column (1-10): ";
    cin >> col;
    if (row < 1 || row > ROWS || col < 1 || col > COLS) {
        cout << "Invalid seat position.\n";
        return;
    }
    cout << "Seat is " << (seats[row - 1][col - 1] == 'A' ? "Available.\n" : "Booked.\n");
}

// Function to create a filename based on month,date and year
string createfilename(int month, int date, int year) {
    return "Month_" + to_string(month) + "_Date_" + to_string(date)  + "_Year_" + to_string(year) + ".txt";
}

int main() {
    int choice, month, date, year;
    do {
        cout << "\n\t\t\t     The Four Cinema \n";
        cout << "1. Display Seating Arrangement\n";
        cout << "2. Book a Seat\n";
        cout << "3. Cancel a Booking\n";
        cout << "4. Check Seat Status\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 4) {
            cout << "Enter month (1-12): ";
            cin >> month;
            if (month < 1 || month > 12) {
                cout << "Invalid month. Please try again.\n";
                continue;
            }
            cout << "Enter date (1-31): ";
            cin >> date;
            if (date < 1 || date > 31) {
                cout << "Invalid date. Please try again.\n";
                continue;
            }

            cout << "Enter Year : ";
            cin >> year;
            if (year < 2024) {
                cout << "Year must be after 2024. Please try again.\n";
                continue;
            }
            initializeSeats(month, date,year);
        }

        switch (choice) {
            case 1:
                displaySeats();
                break;
            case 2:
                bookseat(month, date,year);
                break;
            case 3:
                cancelSeat(month, date,year);
                break;
            case 4:
                checkSeatStatus();
                break;
            case 5:
                cout << "Thanks for using our servives.\n";
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

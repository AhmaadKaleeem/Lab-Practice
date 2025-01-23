#include <iostream>
#include <limits> // For numeric_limits
using namespace std;

// Function to initialize and display the board
void initializeAndDisplayBoard(char board[3][3], bool initialize = true) {
    if (initialize) {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = '*';
            }
        }
    }
    cout << "\nCurrent Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if the game is over (win or tie)
bool isGameOver(char board[3][3], char &winner) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] != '*' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] != '*' && board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
            winner = board[i][0] != '*' ? board[i][0] : board[0][i];
            return true;
        }
    }
    if ((board[0][0] != '*' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[0][2] != '*' && board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
        winner = board[1][1];
        return true;
    }

    // Check for a tie
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '*') {
                return false; // Game is not over
            }
        }
    }

    winner = 'T'; // Indicates a tie
    return true;
}

// Function to validate user input
bool validateInput(int &row, int &col, char board[3][3]) {
    if (cin.fail()) { // If invalid input (non-integer)
        cin.clear();   // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "Invalid input! Please enter integers between 0 and 2.\n";
        return false;
    }
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        cout << "Invalid move! Row and column must be between 0 and 2.\n";
        return false;
    }
    if (board[row][col] != '*') {
        cout << "Cell already occupied! Choose another.\n";
        return false;
    }
    return true;
}

int main() {
    char board[3][3];
    initializeAndDisplayBoard(board); // Initialize and display the board

    char currentPlayer = 'X';
    char winner = '*';
    int row, col;

    cout << "Welcome to Tic-Tac-Toe!\n";

    while (!isGameOver(board, winner)) {
        cout << "Player " << (currentPlayer == 'X' ? "1 (X)" : "2 (O)") << "'s turn." << endl;

        // Input for row and column
        bool validMove = false;
        do {
            cout << "Enter row (0-2): ";
            cin >> row;
            cout << "Enter column (0-2): ";
            cin >> col;

            validMove = validateInput(row, col, board);
        } while (!validMove);

        // Update the board and display it
        board[row][col] = currentPlayer;
        initializeAndDisplayBoard(board, false);

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    // Display the result
    if (winner == 'T') {
        cout << "It's a tie!" << endl;
    } else {
        cout << "Player " << (winner == 'X' ? "1 (X)" : "2 (O)") << " wins!" << endl;
    }

    return 0;
}

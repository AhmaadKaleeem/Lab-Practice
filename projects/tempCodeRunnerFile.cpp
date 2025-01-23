#include <iostream>
#include <fstream>
using namespace std;
char** board;
int turn = 0;

void InitializeBoard();
void Display();
bool ValidSource(int x, int y);
bool ValidDestination(int s_x, int s_y, int d_x, int d_y, bool isWhiteTurn);
void MakeMove(int s_x, int s_y, int d_x, int d_y);
void ChangeTurn();
bool ValidRookMove(int s_x, int s_y, int d_x, int d_y, bool isWhiteTurn);
bool ValidKnightMove(int s_x, int s_y, int d_x, int d_y, bool isWhiteTurn);
bool ValidBishopMove(int s_x, int s_y, int d_x, int d_y, bool isWhiteTurn);
bool ValidQueenMove(int s_x, int s_y, int d_x, int d_y, bool isWhiteTurn);
bool ValidKingMove(int s_x, int s_y, int d_x, int d_y, bool isWhiteTurn);
bool ValidPawnMove(int s_x, int s_y, int d_x, int d_y, bool isWhiteTurn);

int main()
{
    InitializeBoard();
    int s_x, s_y, d_x, d_y;
    cout << "Chess Game" << endl;

    while (true)
    {
        Display();
        if (turn == 0)
        {
            cout << "White's Turn (Upper Case)" << endl;
        }
        else
        {
            cout << "Black's Turn (Lower Case)" << endl;
        }

        do
        {
            cout << "Enter source (row and column): ";
            cin >> s_x >> s_y;
        } while (!ValidSource(s_x, s_y));

        do
        {
            cout << "Enter destination (row and column): ";
            cin >> d_x >> d_y;
        } while (!ValidDestination(s_x, s_y, d_x, d_y, turn == 0));

        MakeMove(s_x, s_y, d_x, d_y);
        ChangeTurn();
    }

    return 0;
}

void InitializeBoard()
{
    ifstream file("CHESSBOARD.txt");
    if (!file)
    {
        cout << "Error opening file." << endl;
        return;
    }

    board = new char* [8];
    for (int i = 0; i < 8; i++)
    {
        board[i] = new char[8];
        for (int j = 0; j < 8; j++)
        {
            file >> board[i][j];
        }
    }
    file.close();
}

void Display()
{
    cout << "0 1 2 3 4 5 6 7" << endl;
    for (int i = 0; i < 8; i++)
    {
        cout<< i << " ";
        for (int j = 0; j < 8; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isUpperCase(char piece)
{
    if (piece >= 'A' && piece <= 'Z')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isLowerCase(char piece)
{
    if (piece >= 'a' && piece <= 'z')
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool ValidSource(int x, int y)
{
    if (x < 0 || x >= 8 || y < 0 || y >= 8 || board[x][y] == '.')
    {
        cout << "No piece at this location." << endl;
        return false;
    }
    if ((turn == 0 && isUpperCase(board[x][y])) || (turn == 1 && isLowerCase(board[x][y])))
    {
        return true;
    }
    cout << "You can only move your own pieces." << endl;
    return false;
}

bool ValidDestination(int s_x, int s_y, int d_x, int d_y, bool isWhiteTurn)
{
    if (d_x < 0 || d_x >= 8 || d_y < 0 || d_y >= 8)
    {
        cout << "Destination out of bounds." << endl;
        return false;
    }
    if ((isWhiteTurn && isUpperCase(board[d_x][d_y])) || (!isWhiteTurn && isLowerCase(board[d_x][d_y])))
    {
        cout << "Destination occupied by your own piece." << endl;
        return false;
    }

    char piece = board[s_x][s_y];

    if (piece == 'R' || piece == 'r')
    {
        return ValidRookMove(s_x, s_y, d_x, d_y, isWhiteTurn);
    }
    else if (piece == 'N' || piece == 'n')
    {
        return ValidKnightMove(s_x, s_y, d_x, d_y, isWhiteTurn);
    }
    else if (piece == 'B' || piece == 'b')
    {
        return ValidBishopMove(s_x, s_y, d_x, d_y, isWhiteTurn);
    }
    else if (piece == 'Q' || piece == 'q')
    {
        return ValidQueenMove(s_x, s_y, d_x, d_y, isWhiteTurn);
    }
    else if (piece == 'K' || piece == 'k')
    {
        return ValidKingMove(s_x, s_y, d_x, d_y, isWhiteTurn);
    }
    else if (piece == 'P' || piece == 'p')
    {
        if (ValidPawnMove(s_x, s_y, d_x, d_y, isWhiteTurn))
        {
            return true;
        }
    }
    cout << "Piece movement not implemented yet." << endl;
    return false;
}

bool isOpponentPiece(char piece, bool isWhiteTurn)
{
    if (isWhiteTurn)
    {
        return (piece >= 'a' && piece <= 'z');
    }
    else
    {
        return (piece >= 'A' && piece <= 'Z');
    }
}

bool ValidRookMove(int s_x, int s_y, int d_x, int d_y, bool isWhiteTurn)
{
    if (s_x != d_x && s_y != d_y)
    {
        return false;
    }
    if (s_x == d_x)
    {
        int start, end;

        if (s_y < d_y)
        {
            start = s_y + 1;
            end = d_y;
        }
        else
        {
            start = d_y + 1;
            end = s_y;
        }

        for (int i = start; i < end; i++)
        {
            if (board[s_x][i] != '.')
            {
                return false;
            }
        }
        if (board[s_x][d_y] != '.' && isOpponentPiece(board[s_x][d_y], isWhiteTurn))
        {
            return true;
        }
        return board[s_x][d_y] == '.';
    }
    else if (s_y == d_y)
    {
        int start, end;

        if (s_x < d_x)
        {
            start = s_x + 1;
            end = d_x;
        }
        else
        {
            start = d_x + 1;
            end = s_x;
        }

        for (int i = start; i < end; i++)
        {
            if (board[i][s_y] != '.')
            {
                return false;
            }
        }
        if (board[d_x][s_y] != '.' && isOpponentPiece(board[d_x][s_y], isWhiteTurn))
        {
            return true;
        }
        return board[d_x][s_y] == '.';
    }
    return false;
}


bool ValidKnightMove(int s_x, int s_y, int d_x, int d_y, bool isWhiteTurn)
{
    int dx = d_x - s_x;
    int dy = d_y - s_y;
    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;

    if ((dx == 2 && dy == 1) || (dx == 1 && dy == 2))
    {
        if (board[d_x][d_y] == '.' || isOpponentPiece(board[d_x][d_y], isWhiteTurn))
        {
            return true;
        }
    }
    return false;
}


bool ValidBishopMove(int s_x, int s_y, int d_x, int d_y, bool isWhiteTurn)
{
    int dx = d_x - s_x;
    int dy = d_y - s_y;
    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;

    if (dx != dy) return false;

    int xStep, yStep;

    if (d_x > s_x)
    {
        xStep = 1;
    }
    else
    {
        xStep = -1;
    }

    if (d_y > s_y)
    {
        yStep = 1;
    }
    else
    {
        yStep = -1;
    }


    int x = s_x + xStep;
    int y = s_y + yStep;

    while (x != d_x && y != d_y)
    {
        if (board[x][y] != '.')
        {
            return false;
        }
        x += xStep;
        y += yStep;
    }

    if (board[d_x][d_y] == '.' || isOpponentPiece(board[d_x][d_y], isWhiteTurn))
    {
        return true;
    }

    return false;
}

bool ValidQueenMove(int s_x, int s_y, int d_x, int d_y, bool isWhiteTurn)
{
    int dx = d_x - s_x;
    int dy = d_y - s_y;
    if (dx < 0)
        dx = -dx;
    if (dy < 0)
        dy = -dy;

    if (dx == 0 || dy == 0 || dx == dy)
    {
        int xStep = 0, yStep = 0;
        if (dx != 0)
        {
            if (d_x > s_x)
            {
                xStep = 1;
            }
            else
            {
                xStep = -1;
            }
        }

        if (dy != 0)
        {
            if (d_y > s_y)
            {
                yStep = 1;
            }
            else
            {
                yStep = -1;
            }
        }


        int x = s_x + xStep;
        int y = s_y + yStep;

        while (x != d_x && y != d_y)
        {
            if (board[x][y] != '.')
                return false;
            x += xStep;
            y += yStep;
        }
        if (board[d_x][d_y] == '.' || isOpponentPiece(board[d_x][d_y], isWhiteTurn))
        {
            return true;
        }
    }
    return false;
}

bool ValidKingMove(int s_x, int s_y, int d_x, int d_y, bool isWhiteTurn)
{
    if ((d_x == s_x + 1 || d_x == s_x - 1 || d_x == s_x) &&
        (d_y == s_y + 1 || d_y == s_y - 1 || d_y == s_y))
    {
        if (board[d_x][d_y] == '.' || isOpponentPiece(board[d_x][d_y], isWhiteTurn))
        {
            return true;
        }
    }
    return false;
}

bool ValidPawnMove(int s_x, int s_y, int d_x, int d_y, bool isWhiteTurn)
{
    if (isWhiteTurn)
    {
        if (s_x == d_x + 1 && s_y == d_y && board[d_x][d_y] == '.')
        {
            return true;
        }
        if (s_x == d_x + 1 && (s_y == d_y - 1 || s_y == d_y + 1) && isLowerCase(board[d_x][d_y]))
        {
            return true;
        }
        if (s_x == 6 && d_x == 4 && s_y == d_y && board[d_x][d_y] == '.' && board[d_x + 1][d_y] == '.')
        {
            return true;
        }
    }
    else
    {
        if (s_x == d_x - 1 && s_y == d_y && board[d_x][d_y] == '.')
        {
            return true;
        }
        if (s_x == d_x - 1 && (s_y == d_y - 1 || s_y == d_y + 1) && isUpperCase(board[d_x][d_y]))
        {
            return true;
        }
        if (s_x == 1 && d_x == 3 && s_y == d_y && board[d_x][d_y] == '.' && board[d_x - 1][d_y] == '.')
        {
            return true;
        }
    }
    return false;
}

void MakeMove(int s_x, int s_y, int d_x, int d_y)
{
    board[d_x][d_y] = board[s_x][s_y];
    board[s_x][s_y] = '.';
}

void ChangeTurn()
{
    turn = 1 - turn;
}

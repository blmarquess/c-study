#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to print the Tic Tac Toe board
void PrintBoard(const vector<vector<char>> &board)
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << board[i][j];
            if (j < 2)
                cout << " | ";
        }
        cout << endl;
        if (i < 2)
            cout << "---------" << endl;
    }
    cout << endl;
}

// Function to check if the game is over
bool IsGameOver(const vector<vector<char>> &board)
{
    // Check rows and columns for a win
    for (int i = 0; i < 3; ++i)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return true;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        {
            return true;
        }
    }

    // Check diagonals for a win
    if ((board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') ||
        (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' '))
    {
        return true;
    }

    // Check for a draw
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }

    return true;
}

// Function to check if a move is valid
bool IsValidMove(const vector<vector<char>> &board, int row, int col)
{
    if (row == -1 || col == -1)
    {
        return false;
    }
    if (row < 0 || row >= 3 || col < 0 || col >= 3)
    {
        return false;
    }
    return board[row][col] == ' ';
}

// Function to make a move
void MakeMove(vector<vector<char>> &board, int row, int col, char player)
{
    board[row][col] = player;
}

int main()
{
    vector<vector<char>> board(3, vector<char>(3, ' ')); // Initialize an empty 3x3 board
    bool isPlayer1Turn = true;
    char player1 = 'X';
    char player2 = 'O';
    int totalMoves = 0;

    while (!IsGameOver(board))
    {
        PrintBoard(board);

        int row, col;
        char currentPlayer = isPlayer1Turn ? player1 : player2;

        while (!IsValidMove(board, row, col))
        {
            cout << "Player " << currentPlayer << ", enter your move (row and column): ";
            cin >> row >> col;
            if (!IsValidMove(board, row, col))
            {
                cout << "Invalid move! Try again." << endl;
            }
        }

        MakeMove(board, row, col, currentPlayer);
        isPlayer1Turn = !isPlayer1Turn;
        totalMoves++;
    }

    PrintBoard(board);

    if (IsGameOver(board))
    {
        cout << "Game Over!" << endl;
        cout << "Congratulations! Player " << (isPlayer1Turn ? player2 : player1) << " wins!" << endl;
    }
    else
    {
        cout << "It's a draw!" << endl;
    }

    return 0;
}

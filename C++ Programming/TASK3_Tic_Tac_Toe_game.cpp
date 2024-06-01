/*
TASK 3
TIC-TAC-TOE GAME
Build a simple console-based Tic-Tac-Toe game that
allows two players to play against each other
    Game Board: Create a 3x3 grid as the game board.
    Players: Assign "X" and "O" to two players.
    Display Board: Show the current state of the board.
    Player Input: Prompt the current player to enter their move.
    Update Board: Update the game board with the player's move.
    Check for Win: Check if the current player has won.
    Check for Draw: Determine if the game is a draw.
    Switch Players: Alternate turns between "X" and "O" players.
    Display Result: Show the result of the game (win, draw, or ongoing).
    Play Again: Ask if the players want to play another game.
*/
#include <bits/stdc++.h>
using namespace std;
void gridPrint(vector<vector<int>> &grid)
{
    cout << "       |       |       \n";
    cout << "   ";
    if (grid[0][0] == -1)
        cout << "1";
    else if (grid[0][0])
        cout << "X";
    else
        cout << "O";
    cout << "   |   ";
    if (grid[0][1] == -1)
        cout << "2";
    else if (grid[0][1])
        cout << "X";
    else
        cout << "O";
    cout << "   |   ";
    if (grid[0][2] == -1)
        cout << "3";
    else if (grid[0][2])
        cout << "X";
    else
        cout << "O";
    cout << "   \n";
    cout << "_______|_______|_______\n";
    cout << "       |       |       \n";
    cout << "   ";
    if (grid[1][0] == -1)
        cout << "4";
    else if (grid[1][0])
        cout << "X";
    else
        cout << "O";
    cout << "   |   ";
    if (grid[1][1] == -1)
        cout << "5";
    else if (grid[1][1])
        cout << "X";
    else
        cout << "O";
    cout << "   |   ";
    if (grid[1][2] == -1)
        cout << "6";
    else if (grid[1][2])
        cout << "X";
    else
        cout << "O";
    cout << "   \n";
    cout << "_______|_______|_______\n";
    cout << "       |       |       \n";
    cout << "   ";
    if (grid[2][0] == -1)
        cout << "7";
    else if (grid[2][0])
        cout << "X";
    else
        cout << "O";
    cout << "   |   ";
    if (grid[2][1] == -1)
        cout << "8";
    else if (grid[2][1])
        cout << "X";
    else
        cout << "O";
    cout << "   |   ";
    if (grid[2][2] == -1)
        cout << "9";
    else if (grid[2][2])
        cout << "X";
    else
        cout << "O";
    cout << "   \n";
    cout << "       |       |       \n";
}
bool checkWinner(vector<vector<int>> &grid, int isX)
{
    if (grid[0][0] == isX && grid[0][1] == isX && grid[0][2] == isX)
        return 1;
    else if (grid[1][0] == isX && grid[1][1] == isX && grid[1][2] == isX)
        return 1;
    else if (grid[2][0] == isX && grid[2][1] == isX && grid[2][2] == isX)
        return 1;
    else if (grid[0][0] == isX && grid[1][0] == isX && grid[2][0] == isX)
        return 1;
    else if (grid[0][1] == isX && grid[1][1] == isX && grid[2][1] == isX)
        return 1;
    else if (grid[0][2] == isX && grid[1][2] == isX && grid[2][2] == isX)
        return 1;
    else if (grid[0][0] == isX && grid[1][1] == isX && grid[2][2] == isX)
        return 1;
    else if (grid[2][0] == isX && grid[1][1] == isX && grid[0][2] == isX)
        return 1;
    else
        return 0;
}
void TicTacToe()
{
    vector<vector<int>> grid(3, vector<int>(3, -1));
    string player1, player2;
    cout << "Enter the name of player 1:- ";
    cin.ignore();
    getline(cin, player1);
    cout << "Enter the name of player 2:- ";
    cin.ignore();
    getline(cin, player2);
    int p1, p2, c = 9;
    cout << player1 << " will go first taking for 'x'\n";
    cout << player2 << " will go second taking for 'o'\n";
    while (c)
    {
        gridPrint(grid);
        cout << "Enter player 1 [1-9]: ";
        cin >> p1;
        while (p1 <= 0 || p1 > 9)
        {
            cout << "INVALID!!";
            cout << "Enter again: ";
            cin >> p1;
        }
        while (grid[(p1 - 1) / 3][(p1 - 1) % 3] != -1)
        {
            cout << "Move not allowed due to already filled !!\nEnter again: ";
            cin >> p1;
        }
        grid[(p1 - 1) / 3][(p1 - 1) % 3] = 1;
        if (checkWinner(grid, 1))
        {
            cout << player1 << " WIN!!\n\n";
            return;
        }
        c--;
        gridPrint(grid);
        if (!c)
            break;
        cout << "Enter player 2 [1-9]: ";
        cin >> p2;
        while (p2 <= 0 || p2 > 9)
        {
            cout << "INVALID!!";
            cout << "Enter again: ";
            cin >> p2;
        }
        while (grid[(p2 - 1) / 3][(p2 - 1) % 3] != -1)
        {
            cout << "Move not allowed due to already filed !!\nEnter again: ";
            cin >> p2;
        }
        grid[(p2 - 1) / 3][(p2 - 1) % 3] = 0;
        if (checkWinner(grid, 0))
        {
            cout << player2 << " WIN!!\n\n";
            return;
        }
        c--;
    }
    cout << "\n----------MATCH IS DRAW----------\n";
}
int main()
{
    cout << "\n----------WELCOME TO THE TIC-TAC-TOE GAME----------\n";
    int check = 1;
    while (check)
    {
        TicTacToe();
        cout << "\nThanks for playing the game";
        cout << "\n\nDo you want to play the GAME again?\nEnter 1: YES\nEnter 0: NO\n";
        cin >> check;
    }
}
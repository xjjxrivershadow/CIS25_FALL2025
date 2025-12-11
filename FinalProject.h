// FinalProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <limits>
#include <stdio.h>   

using namespace std;

const int N = 3;           // Board is N x N (3x3)
const int BLANK = 0;
using Board = vector<int>;

// Draw the board in a grid
void drawBoard(const Board& board, int moves)
{
    cout << "\nCurrent board (moves: " << moves << "):\n\n";
    for (int i = 0; i < N * N; ++i) {
        if (i % N == 0) cout << "+---+---+---+\n|";
        if (board[i] == BLANK)
            cout << "   |";
        else
            cout << " " << board[i] << " |";
        if (i % N == N - 1) cout << '\n';
    }
    cout << "+---+---+---+\n";
}

// Check if board is solved: 1..8 then 0
bool isSolved(const Board& board)
{
    for (int i = 0; i < N * N - 1; ++i) {
        if (board[i] != i + 1)
            return false;
    }
    return board[N * N - 1] == BLANK;
}

// Check if the puzzle is solvable (8-puzzle rule)
bool isSolvable(const Board& board)
{
    int inv = 0;
    for (int i = 0; i < N * N; ++i) {
        if (board[i] == BLANK) continue;
        for (int j = i + 1; j < N * N; ++j) {
            if (board[j] == BLANK) continue;
            if (board[i] > board[j]) ++inv;
        }
    }
    return (inv % 2 == 0);
}

// Manhattan distance heuristic (for hints)
int manhattanDistance(const Board& board)
{
    int dist = 0;
    for (int i = 0; i < N * N; ++i) {
        int v = board[i];
        if (v == BLANK) continue;
        int goal = v - 1;
        int x1 = i % N, y1 = i / N;
        int x2 = goal % N, y2 = goal / N;
        dist += abs(x1 - x2) + abs(y1 - y2);
    }
    return dist;
}

// Create a random solvable, non-trivial board
Board createRandomBoard()
{
    Board board(N * N);
    for (int i = 0; i < N * N - 1; ++i)
        board[i] = i + 1;
    board[N * N - 1] = BLANK;

    do {
        random_shuffle(board.begin(), board.end());
    } while (!isSolvable(board) || isSolved(board));

    return board;
}

// Try to move the blank; returns true if move is valid
bool applyMove(Board& board, char move)
{
    move = (char)tolower((unsigned char)move);

    auto it = find(board.begin(), board.end(), BLANK);
    int index = it - board.begin();
    int x = index % N;
    int y = index / N;

    int newIndex = index;

    if (move == 'w' && y < N - 1) newIndex = index + N;
    else if (move == 's' && y > 0) newIndex = index - N;
    else if (move == 'a' && x < N - 1) newIndex = index + 1;
    else if (move == 'd' && x > 0) newIndex = index - 1;
    else
        return false;

    swap(board[index], board[newIndex]);
    return true;
}

int main()
{
    srand((unsigned)time(nullptr));

    cout << "Welcome to the Crystal Puzzle!\n";
    cout << "Arrange the numbers 1-8 in order by sliding tiles into the empty space.\n";
    cout << "Use W (up), A (left), S (down), D (right).\n";
    cout << "Extra commands: H = hint, R = reshuffle, Q = quit.\n\n";

    bool playing = true;
    while (playing) {

        Board board = createRandomBoard();
        int moves = 0;
        time_t startTime = time(nullptr);

        while (!isSolved(board)) {
            drawBoard(board, moves);
            cout << "Command (W/A/S/D/H/R/Q): ";

            char cmd;
            if (!(cin >> cmd)) {
                cout << "\nGoodbye!\n";
                return 0;
            }

            cmd = (char)tolower((unsigned char)cmd);

            if (cmd == 'q') {
                cout << "\nThanks for playing!\n";
                return 0;
            }
            if (cmd == 'r') break;

            if (cmd == 'h') {
                cout << "\nHint:\n";
                cout << "  Manhattan distance: " << manhattanDistance(board) << "\n";

                int misplaced = 0;
                for (int i = 0; i < N * N - 1; ++i)
                    if (board[i] != 0 && board[i] != i + 1) misplaced++;

                cout << "  Misplaced tiles: " << misplaced << "\n\n";
                continue;
            }

            if (applyMove(board, cmd)) moves++;
            else cout << "Invalid move! Try again.\n\n";
        }

        if (isSolved(board)) {
            time_t endTime = time(nullptr);
            cout << "\n?? Congratulations! You solved the Crystal Puzzle!\n";
            cout << "Total moves: " << moves << "\n";
            cout << "Time: " << difftime(endTime, startTime) << " seconds\n";

            cout << "\nPlay again? (y/n): ";
            char a;
            cin >> a;
            if (tolower(a) != 'y')
                playing = false;
        }
    }

    cout << "\nThanks for playing!\n";
    return 0;
}


// Week2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <stdio.h>

using namespace std;


void drawBoard(const vector<int>& board) {
	cout << "\nCurrent board:\n";
	for (int i = 0; i < 9; i++) {
		if (i % 3 == 0) cout << "\n";
		if (board[i] == 0) cout << " _"; // Empty space
		else cout << " " << board[i];
	}
	cout << "\n";
}


bool isSolved(const vector<int>& board) {
	for (int i = 0; i < 8; i++) {
		if (board[i] != i + 1) return false;
	}
	return board[8] == 0;
}


int main() {
	srand(static_cast<unsigned>(time(nullptr)));


	vector<int> board = { 1, 2, 3, 4, 5, 6, 7, 8, 0 };
	random_shuffle(board.begin(), board.end());


	cout << "Welcome to the Crystal Puzzle!" << endl;
	cout << "Arrange the numbers 1-8 in order by sliding tiles into the empty space." << endl;
	cout << "Use W (up), A (left), S (down), D (right) to move the blank space.\n";


	while (!isSolved(board)) {
		drawBoard(board);


		char move;
		cout << "Enter your move: ";
		cin >> move;
		move = tolower(move);


		int index = find(board.begin(), board.end(), 0) - board.begin();
		int x = index % 3;
		int y = index / 3;


		int newIndex = index;
		if (move == 'w' && y < 2) newIndex = index + 3;
		else if (move == 's' && y > 0) newIndex = index - 3;
		else if (move == 'a' && x < 2) newIndex = index + 1;
		else if (move == 'd' && x > 0) newIndex = index - 1;
		else {
			cout << "Invalid move! Try again.\n";
			continue;
		}


		swap(board[index], board[newIndex]);
	}


	drawBoard(board);
	cout << "\nCongratulations! You solved the Crystal Puzzle! 💎\n";
	return 0;
}
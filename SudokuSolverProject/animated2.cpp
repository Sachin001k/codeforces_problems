#include <bits/stdc++.h>
#include <chrono>
#include <thread>
using namespace std;

class SudokuSolver {
private:
    vector<vector<int>> board; // 9x9 sudoku grid

    bool isSafe(int row, int col, int val) {
        for (int i = 0; i < 9; i++) {
            // Row check
            if (board[row][i] == val) return false;
            // Column check
            if (board[i][col] == val) return false;
            // 3x3 box check
            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
                return false;
        }
        return true;
    }

    void printBoard() {
        system("clear"); // use "cls" for Windows
        cout << "-------------------------\n";
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (c % 3 == 0) cout << "| ";
                if (board[r][c] == 0) cout << ". ";
                else cout << board[r][c] << " ";
            }
            cout << "|\n";
            if ((r + 1) % 3 == 0) cout << "-------------------------\n";
        }
        this_thread::sleep_for(chrono::milliseconds(1)); // animation delay
    }

    bool solveWithAnimation() {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == 0) {
                    for (int val = 1; val <= 9; val++) {
                        if (isSafe(row, col, val)) {
                            board[row][col] = val;
                            printBoard(); // Show board after placing a value
                            if (solveWithAnimation()) return true;
                            board[row][col] = 0; // backtrack
                            printBoard(); // Show board after backtracking
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

public:
    SudokuSolver() {
        board.assign(9, vector<int>(9, 0));
    }

    void generatePuzzle() {
        vector<vector<int>> puzzle = {
            {5,3,0,0,7,0,0,0,0},
            {6,0,0,1,9,5,0,0,0},
            {0,9,8,0,0,0,0,6,0},
            {8,0,0,0,6,0,0,0,3},
            {4,0,0,8,0,3,0,0,1},
            {7,0,0,0,2,0,0,0,6},
            {0,6,0,0,0,0,2,8,0},
            {0,0,0,4,1,9,0,0,5},
            {0,0,0,0,8,0,0,7,9}
        };
        board = puzzle;
    }

    void showBoard() {
        printBoard();
    }

    void solve() {
        solveWithAnimation();
    }
};

int main() {
    SudokuSolver solver;
    solver.generatePuzzle(); // generate puzzle
    solver.showBoard();      // show puzzle before solving
    solver.solve();          // solve with animation
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

class SudokuSolver {
private:
    vector<vector<int>> board; // 9x9 Sudoku board

    bool isSafe(int row, int col, int val) {
        for (int i = 0; i < 9; i++) {
            // Row check
            if (board[row][i] == val) return false;

            // Column check
            if (board[i][col] == val) return false;

            // 3x3 box check
            int boxRow = 3 * (row / 3) + i / 3;
            int boxCol = 3 * (col / 3) + i % 3;
            if (board[boxRow][boxCol] == val) return false;
        }
        return true;
    }

    bool solve() {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == 0) { // empty cell
                    for (int val = 1; val <= 9; val++) {
                        if (isSafe(row, col, val)) {
                            board[row][col] = val;
                            if (solve()) return true; // recursive solve
                            board[row][col] = 0; // backtrack
                        }
                    }
                    return false; // no valid number found
                }
            }
        }
        return true; // solved
    }

public:
    // Constructor
    SudokuSolver() {
        board.assign(9, vector<int>(9, 0));
    }

    // Take input
    void inputBoard() {
        cout << "Enter Sudoku puzzle (0 for empty cells):"<<endl;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> board[i][j];
            }
        }
        cout<<endl;
    }

    // Solve and display
    void solveAndDisplay() {
        if (solve()) {
            cout << "Solved Sudoku:"<<endl;
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    cout << board[i][j] << " ";
                }
                cout << endl;
            }
        } else {
            cout << "No solution exists."<<endl;
        }
    }
};

int main() {
    SudokuSolver solver;
    solver.inputBoard();
    solver.solveAndDisplay();
    return 0;
}

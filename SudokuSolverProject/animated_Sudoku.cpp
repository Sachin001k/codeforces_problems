#include <iostream>
#include <vector>
#include <random>
#include <chrono>
#include <thread>

class Sudoku {
public:
    Sudoku()
        : board(9, std::vector<int>(9, 0)),
          animate(false),
          delay_ms(40) {}

    // Configure animation
    void setAnimation(bool enable, int delayMilliseconds = 40) {
        animate = enable;
        delay_ms = delayMilliseconds;
    }

    // Load a random puzzle from built-ins
    void loadRandomPuzzle() {
        static const std::vector<std::vector<std::vector<int>>> puzzles = {
            {
                {5,3,0,0,7,0,0,0,0},
                {6,0,0,1,9,5,0,0,0},
                {0,9,8,0,0,0,0,6,0},
                {8,0,0,0,6,0,0,0,3},
                {4,0,0,8,0,3,0,0,1},
                {7,0,0,0,2,0,0,0,6},
                {0,6,0,0,0,0,2,8,0},
                {0,0,0,4,1,9,0,0,5},
                {0,0,0,0,8,0,0,7,9}
            },
            {
                {0,0,0,2,6,0,7,0,1},
                {6,8,0,0,7,0,0,9,0},
                {1,9,0,0,0,4,5,0,0},
                {8,2,0,1,0,0,0,4,0},
                {0,0,4,6,0,2,9,0,0},
                {0,5,0,0,0,3,0,2,8},
                {0,0,9,3,0,0,0,7,4},
                {0,4,0,0,5,0,0,3,6},
                {7,0,3,0,1,8,0,0,0}
            },
            {
                {3,0,6,5,0,8,4,0,0},
                {5,2,0,0,0,0,0,0,0},
                {0,8,7,0,0,0,0,3,1},
                {0,0,3,0,1,0,0,8,0},
                {9,0,0,8,6,3,0,0,5},
                {0,5,0,0,9,0,6,0,0},
                {1,3,0,0,0,0,2,5,0},
                {0,0,0,0,0,0,0,7,4},
                {0,0,5,2,0,6,3,0,0}
            }
        };

        std::mt19937 rng(static_cast<unsigned>(
            std::chrono::high_resolution_clock::now().time_since_epoch().count()));
        std::uniform_int_distribution<size_t> dist(0, puzzles.size() - 1);
        board = puzzles[dist(rng)];
    }

    // Print the current board (with grid lines)
    void printBoard(const std::string& title = "") const {
        if (!title.empty()) std::cout << title << "\n";
        std::cout << "+-------+-------+-------+\n";
        for (int r = 0; r < 9; ++r) {
            std::cout << "| ";
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == 0) std::cout << ". ";
                else std::cout << board[r][c] << ' ';
                if ((c + 1) % 3 == 0) std::cout << "| ";
            }
            std::cout << "\n";
            if ((r + 1) % 3 == 0) std::cout << "+-------+-------+-------+\n";
        }
        std::cout << std::flush;
    }

    // Solve the puzzle; returns true if solved
    bool solve() {
        return solveBacktrack();
    }

private:
    std::vector<std::vector<int>> board;
    bool animate;
    int delay_ms;

    // Utility: clear screen via ANSI (works in most terminals)
    void clearScreen() const {
        std::cout << "\x1B[2J\x1B[H"; // clear + home
    }

    void maybeAnimateStep(const char* phase, int r, int c, int val) {
        if (!animate) return;
        clearScreen();
        std::cout << phase << " (" << r << "," << c << ") = " << val << "\n\n";
        printBoard();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay_ms));
    }

    bool isSafe(int row, int col, int val) const {
        // row/col
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == val) return false;
            if (board[i][col] == val) return false;
        }
        // 3x3 box
        int br = (row / 3) * 3, bc = (col / 3) * 3;
        for (int r = 0; r < 3; ++r)
            for (int c = 0; c < 3; ++c)
                if (board[br + r][bc + c] == val) return false;

        return true;
    }

    // Find next empty cell; returns true if found
    bool findEmpty(int& outRow, int& outCol) const {
        for (int r = 0; r < 9; ++r)
            for (int c = 0; c < 9; ++c)
                if (board[r][c] == 0) {
                    outRow = r; outCol = c;
                    return true;
                }
        return false;
    }

    bool solveBacktrack() {
        int row, col;
        if (!findEmpty(row, col)) return true; // solved

        for (int val = 1; val <= 9; ++val) {
            if (isSafe(row, col, val)) {
                board[row][col] = val;
                maybeAnimateStep("Place", row, col, val);

                if (solveBacktrack()) return true;

                // backtrack
                board[row][col] = 0;
                maybeAnimateStep("Backtrack", row, col, val);
            }
        }
        return false; // trigger backtracking
    }

public:
    // Convenience: run end-to-end
    void run(bool showAnimation = true, int ms = 40) {
        setAnimation(showAnimation, ms);
        loadRandomPuzzle();
        clearScreen();
        printBoard("Initial Sudoku:");
        if (animate) std::this_thread::sleep_for(std::chrono::milliseconds(600));

        bool ok = solve();

        std::cout << "\n";
        if (ok) printBoard("Solved Sudoku:");
        else std::cout << "No solution exists.\n";
    }
};

int main() {
    Sudoku s;
    // Toggle animation: true/false, and delay in ms (e.g., 20..120 for different speeds)
    s.run(/*showAnimation*/ true, /*delay_ms*/ 50);
    return 0;
}

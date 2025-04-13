#include <stdio.h>
#include <stdbool.h>

#define MAX_N 20

int steps = 0;

// Function to print the chessboard
void printSolution(int board[MAX_N][MAX_N], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

// Function to check if a queen can be placed at board[row][col]
bool isSafe(int board[MAX_N][MAX_N], int row, int col, int n) {
    int i, j;

    // Check this row on left side
    for (i = 0; i < col; i++) {
        steps++;
        if (board[row][i]) return false;
    }

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        steps++;
        if (board[i][j]) return false;
    }

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < n; i++, j--) {
        steps++;
        if (board[i][j]) return false;
    }

    return true;
}

// Function to solve the N-Queens problem using backtracking
bool solveNQueensUtil(int board[MAX_N][MAX_N], int col, int n) {
    // All queens are placed
    if (col >= n) return true;

    // Try placing the queen in all rows one by one
    for (int i = 0; i < n; i++) {
        steps++;
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1; // Place queen

            // Recur to place rest of the queens
            if (solveNQueensUtil(board, col + 1, n)) return true;

            board[i][col] = 0; // Backtrack
        }
    }

    return false;
}

// Function to initialize the chessboard and call the utility function
void solveNQueens(int n) {
    int board[MAX_N][MAX_N] = {0}; // Initialize chessboard with 0s

    if (solveNQueensUtil(board, 0, n) == false) {
        printf("Solution does not exist\n");
        return;
    }

    printSolution(board, n);
}

int main() {
    int n = 8; // Size of the chessboard
    printf("Solving %d-Queens problem:\n", n);
    
    solveNQueens(n);

    // Output the total number of steps taken
    printf("Total number of steps taken: %d\n", steps);

    return 0;
}


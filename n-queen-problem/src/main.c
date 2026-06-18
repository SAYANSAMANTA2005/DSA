#include<stdio.h>
#include<stdbool.h>

#define N 8
 // Define the size of the chessboard

// Function to print the solution
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed safely at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check the row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i]) {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; j >= 0 && i < N; i++, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Recursive function to solve N-Queens problem using backtracking
bool solveNQueens(int board[N][N], int col) {
    // Base case: If all queens are placed then return true
    if (col >= N) {
        return true;
    }

    // Try placing queen in each row of this column
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            // Place queen at board[i][col]
            board[i][col] = 1;

            // Recur to place rest of the queens
            if (solveNQueens(board, col + 1)) {
                return true;
            }

            // If placing queen at board[i][col] doesn't lead to a solution, backtrack
            board[i][col] = 0; // Backtrack
        }
    }

    // If queen can't be placed in any row of this column, return false
    return false;
}

// Main function to solve N-Queens problem
void nQueens() {
    int board[N][N] = {{0}}; // Initialize the chessboard with all cells set to 0

    if (solveNQueens(board, 0) == false) {
        printf("Solution does not exist");
        return;
    }

    // Print the solution
    printSolution(board);
}

// Main function
int main() {
    nQueens();
    return 0;
}
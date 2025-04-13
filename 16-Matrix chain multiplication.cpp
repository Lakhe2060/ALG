#include <stdio.h>
#include <limits.h>

#define MAX 100

// Function to find the minimum cost of matrix chain multiplication
void matrixChainMultiplication(int p[], int n, int *step_count, int m[][MAX], int s[][MAX]) {
    // Initialize the cost matrix with 0s and steps count
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            m[i][j] = (i == j) ? 0 : INT_MAX;
            (*step_count)++; // Increment step count for initialization
        }
    }

    // Fill the cost matrix
    for (int len = 2; len <= n; ++len) {
        for (int i = 1; i <= n - len + 1; ++i) {
            int j = i + len - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; ++k) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                (*step_count)++; // Increment step count for cost computation
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    // Print the minimum cost
    printf("Minimum cost of matrix chain multiplication: %d\n", m[1][n]);
}

// Function to print the optimal parenthesization of matrix chain multiplication
void printOptimalParens(int s[][MAX], int i, int j, int *step_count) {
    (*step_count)++; // Increment step count for function call
    if (i == j) {
        printf("A%d", i);
    } else {
        printf("(");
        printOptimalParens(s, i, s[i][j], step_count);
        printOptimalParens(s, s[i][j] + 1, j, step_count);
        printf(")");
    }
}

int main() {
    int p[] = {10, 20, 30, 40, 30}; // Dimensions of matrices
    int n = sizeof(p) / sizeof(p[0]) - 1; // Number of matrices
    int steps = 0;

    int m[MAX][MAX], s[MAX][MAX]; // Cost and split matrices

    // Perform matrix chain multiplication
    matrixChainMultiplication(p, n, &steps, m, s);

    // Print the optimal parenthesization
    printf("Optimal Parenthesization: ");
    printOptimalParens(s, 1, n, &steps);
    printf("\n");

    // Output the total number of steps taken
    printf("Total number of steps taken: %d\n", steps);

    return 0;
}

#include <stdio.h>

#define MAX_ITEMS 100

// Function to solve the 0/1 Knapsack problem
void knapsack(int weights[], int values[], int n, int capacity, int *step_count) {
    int dp[n + 1][capacity + 1];
    
    // Initialize DP table with 0s and increment step count
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            dp[i][w] = 0;
            (*step_count)++; // Increment step count for initialization
        }
    }
    
    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            (*step_count)++; // Increment step count for each DP table update
            if (weights[i - 1] <= w) {
                // Take the maximum of including or excluding the current item
                dp[i][w] = (values[i - 1] + dp[i - 1][w - weights[i - 1]] > dp[i - 1][w]) ? 
                           values[i - 1] + dp[i - 1][w - weights[i - 1]] : 
                           dp[i - 1][w];
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    
    // Print the maximum value that can be achieved
    printf("Maximum value in Knapsack: %d\n", dp[n][capacity]);
}

int main() {
    int weights[] = {2, 3, 4, 5}; // Weights of items
    int values[] = {3, 4, 5, 6}; // Values of items
    int capacity = 5; // Capacity of knapsack
    int n = sizeof(weights) / sizeof(weights[0]); // Number of items
    int steps = 0;

    // Solve the 0/1 Knapsack problem and count steps
    knapsack(weights, values, n, capacity, &steps);

    // Output the total number of steps taken
    printf("Total number of steps taken: %d\n", steps);

    return 0;
}


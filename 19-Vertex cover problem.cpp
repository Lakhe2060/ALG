#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Function to print the vertex cover
void printVertexCover(int cover[], int n) {
    printf("Vertex Cover: ");
    for (int i = 0; i < n; i++) {
        if (cover[i]) {
            printf("V%d ", i);
        }
    }
    printf("\n");
}

// Function to find the vertex cover using a greedy algorithm
void vertexCover(int graph[MAX_VERTICES][MAX_VERTICES], int n, int *step_count) {
    bool covered[MAX_VERTICES] = {false}; // Array to mark covered vertices
    int cover[MAX_VERTICES] = {0}; // Array to store the vertex cover
    int u, v;

    // Iterate through all edges
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            (*step_count)++; // Increment step count for each edge check
            if (graph[i][j] && !covered[i] && !covered[j]) {
                // Add both vertices to the cover set
                cover[i] = 1;
                cover[j] = 1;
                covered[i] = true;
                covered[j] = true;
                
                // Mark all edges incident to these vertices as covered
                for (int k = 0; k < n; k++) {
                    if (graph[i][k]) {
                        covered[k] = true;
                    }
                    if (graph[j][k]) {
                        covered[k] = true;
                    }
                }
            }
        }
    }

    // Print the vertex cover
    printVertexCover(cover, n);
}

int main() {
    int graph[MAX_VERTICES][MAX_VERTICES] = {0};
    int n; // Number of vertices
    int m; // Number of edges
    int step_count = 0;

    // Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &m);

    // Input edges
    printf("Enter the edges (format: u v):\n");
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    // Find and print the vertex cover
    vertexCover(graph, n, &step_count);

    // Output the total number of steps taken
    printf("Total number of steps taken: %d\n", step_count);

    return 0;
}


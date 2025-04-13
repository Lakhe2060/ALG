#include <stdio.h>
#include <limits.h>
#define V 5 
int min_distance(int dist[], int spt_set[], int *step_count) {
    (*step_count)++; 
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        (*step_count)++; 
        if (!spt_set[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}
void dijkstra(int graph[V][V], int src, int *step_count) {
    int dist[V]; 
    int spt_set[V]; 
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        spt_set[i] = 0;
        (*step_count)++; 
    }
    dist[src] = 0;
    for (int count = 0; count < V - 1; count++) {
        int u = min_distance(dist, spt_set, step_count);
        spt_set[u] = 1;
        for (int v = 0; v < V; v++) {
            (*step_count)++; 
            if (!spt_set[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

main() {
    int graph[V][V] = {
        {0, 10, 0, 30, 100},
        {10, 0, 50, 0, 0},
        {0, 50, 0, 20, 10},
        {30, 0, 20, 0, 60},
        {100, 0, 10, 60, 0}
    };

    int steps = 0;
    int source = 0; 
    dijkstra(graph, source, &steps);
    printf("Total number of steps: %d\n", steps);
}


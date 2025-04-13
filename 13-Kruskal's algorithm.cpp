#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int src, dest, weight;
} Edge;
typedef struct {
    int parent;
    int rank;
} Subset;
int compare(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}
int find(Subset subsets[], int i, int *step_count) {
    (*step_count)++; 
    if (subsets[i].parent != i) {
        subsets[i].parent = find(subsets, subsets[i].parent, step_count);
    }
    return subsets[i].parent;
}
void union_subsets(Subset subsets[], int x, int y, int *step_count) {
    int xroot = find(subsets, x, step_count);
    int yroot = find(subsets, y, step_count);

    (*step_count)++; 

    if (xroot != yroot) {
        if (subsets[xroot].rank < subsets[yroot].rank) {
            subsets[xroot].parent = yroot;
        } else if (subsets[xroot].rank > subsets[yroot].rank) {
            subsets[yroot].parent = xroot;
        } else {
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }
}
void kruskal(Edge edges[], int V, int E, int *step_count) {
    Subset *subsets = (Subset *)malloc(V * sizeof(Subset));
    Edge result[V]; 
    int e = 0; 
    int i = 0;
    for (int v = 0; v < V; ++v) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }
    qsort(edges, E, sizeof(Edge), compare);
    while (e < V - 1 && i < E) {
        (*step_count)++;
        Edge next_edge = edges[i++];

        int x = find(subsets, next_edge.src, step_count);
        int y = find(subsets, next_edge.dest, step_count);
        if (x != y) {
            result[e++] = next_edge;
            union_subsets(subsets, x, y, step_count);
        }
    }
    printf("Edges in the Minimum Spanning Tree:\n");
    int minCost = 0;
    for (i = 0; i < e; ++i) {
        printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
        minCost += result[i].weight;
    }
    printf("Minimum cost of the spanning tree: %d\n", minCost);
    free(subsets);
}
main() {
    int V = 4; 
    int E = 5; 
    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    int steps = 0;
    kruskal(edges, V, E, &steps);
    printf("Total number of steps: %d\n", steps);
}


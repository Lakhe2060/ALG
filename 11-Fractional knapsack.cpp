#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int value;
    int weight;
    float ratio; 
} Item;
int compare(const void *a, const void *b) {
    Item *item1 = (Item *)a;
    Item *item2 = (Item *)b;
    return (item2->ratio - item1->ratio) > 0 ? 1 : -1;
}
float frac_knapsack(Item items[], int n, int capacity, int *step_count) {
    qsort(items, n, sizeof(Item), compare);

    int current_weight = 0;
    float total_value = 0.0;

    *step_count = 0; 

    for (int i = 0; i < n; i++) {
        (*step_count)++; 

        if (current_weight + items[i].weight <= capacity) {
            
            current_weight += items[i].weight;
            total_value += items[i].value;
        } else {
            int remaining_capacity = capacity - current_weight;
            total_value += items[i].value * ((float)remaining_capacity / items[i].weight);
            break;
        }
    }
    return total_value;
}

main() 
{
    Item items[] = {
        {60, 10, 0}, 
        {100, 20, 0},
        {120, 30, 0}
    };
    int n = sizeof(items) / sizeof(items[0]);
    int capacity = 50; 
    int steps;
    for (int i = 0; i < n; i++) {
        items[i].ratio = (float)items[i].value / items[i].weight;
    }
    float max_value = frac_knapsack(items, n, capacity, &steps);
    printf("Maximum value in the knapsack: %.2f\n", max_value);
    printf("Total number of steps: %d\n", steps);
}


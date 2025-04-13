#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int random_number(int low, int high) {
    return low + rand() % (high - low + 1);
}
int partition(int arr[], int low, int high, int *step_count) {
    int pivot_index = random_number(low, high);
    int pivot = arr[pivot_index];
    swap(&arr[pivot_index], &arr[high]);

    int i = low - 1; 

    for (int j = low; j < high; j++) {
        (*step_count)++; 

        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]); 
        }
    }
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}
void randomized_quick_sort(int arr[], int low, int high, int *step_count) {
    if (low < high) {
        int pi = partition(arr, low, high, step_count);
        randomized_quick_sort(arr, low, pi - 1, step_count);
        randomized_quick_sort(arr, pi + 1, high, step_count);
    }
}

main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int steps = 0;
    srand(time(NULL));
    randomized_quick_sort(arr, 0, n - 1, &steps);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nTotal number of steps: %d\n", steps);
}


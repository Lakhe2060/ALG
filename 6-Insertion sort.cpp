#include <stdio.h>
void insertion_sort_with_step_count(int arr[], int n, int *step_count) {
    int i, key, j;
    *step_count = 0; 

    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            (*step_count)++; 
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

main() 
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int steps;

    insertion_sort_with_step_count(arr, n, &steps);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nTotal number of steps taken: %d\n", steps);
}


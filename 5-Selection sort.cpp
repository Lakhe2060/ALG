#include <stdio.h>
void selection_sort_with_step_count(int arr[], int n, int *step_count) {
    int i, j, min_idx;
    *step_count = 0; 
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            (*step_count)++; 

            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

main() 
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int steps;
    selection_sort_with_step_count(arr, n, &steps);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nTotal number of steps taken: %d\n", steps);
}


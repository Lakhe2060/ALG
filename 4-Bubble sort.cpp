#include <stdio.h>
void bubble_sort_with_step_count(int arr[], int n, int *step_count) {
    int i, j;
    *step_count = 0; 

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            (*step_count)++; 
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int steps;
    bubble_sort_with_step_count(arr, n, &steps);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nTotal number of steps taken: %d\n", steps);

    return 0;
}


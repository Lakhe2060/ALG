#include <stdio.h>
void heapify(int arr[], int n, int i, int *step_count) {
    int largest = i;   
    int l = 2 * i + 1;  
    int r = 2 * i + 2;  
    (*step_count)++;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    (*step_count)++;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    (*step_count)++;
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest, step_count);
    }
}
void heap_sort(int arr[], int n, int *step_count) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, step_count);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0, step_count);
    }
}

main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    int steps = 0;
    heap_sort(arr, n, &steps);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\nTotal number of steps: %d\n", steps);
}


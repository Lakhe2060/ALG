#include <stdio.h>
int binary_search_with_step_count(int arr[], int left, int right, int x, int *step_count) {
    while (left <= right) {
        (*step_count)++; 
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

main() {
    int arr[] = {2, 3, 4, 7, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x, steps;
    printf("Enter the element to search: ");
    scanf("%d", &x);
    int result = binary_search_with_step_count(arr, 0, n - 1, x, &steps);
    if (result == -1)
        printf("Element %d is not present in the array\n", x);
    else
        printf("Element %d is present at index %d\n", x, result);
    printf("Total number of steps taken: %d\n", steps);
}


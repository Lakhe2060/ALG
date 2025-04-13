#include <stdio.h>
int fibonacci_with_step_count(int n, int *step_count) 
{
    int a = 0, b = 1, c, i;
    *step_count = 0; 

    if (n == 0)
        return a;
    for (i = 2; i <= n; ++i) {
        (*step_count)++;
        c = a + b;
        a = b;
        b = c;
    }

    return b;
}

main() {
    int num, steps;
    printf("Enter the number of terms: ");
    scanf("%d", &num);

    printf("\nFibonacci Series:\n");
    for (int i = 0; i < num; ++i) {
        int result = fibonacci_with_step_count(i, &steps);
        printf("%d ", result);
    }
    printf("\nTotal number of steps taken: %d\n", steps);
}


#include <stdio.h>
int gcd_with_step_count(int a, int b, int *step_count) 
{
    int temp;
    *step_count = 0; 
    while (b != 0) {
        (*step_count)++; 
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

main() 
{
    int num1, num2, steps;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    int result = gcd_with_step_count(num1, num2, &steps);
    printf("\nGCD of %d and %d is %d\n", num1, num2, result);
    printf("Total number of steps: %d\n", steps);
}


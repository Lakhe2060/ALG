
#include <stdio.h>
int main()
{
    int i;
    int n;
    int x;
    int b[10];

    int a[10];
    printf("\n enter the degree of polynomial:");
    scanf("%d", &n);
    printf("\n enter the magnitude of polynomail divisor:");
    scanf("%d", &x);
    printf("\n enter the coefficients of polynomial:");
    for (i = n; i >= 0; --i)
    {
        scanf("%d", &a[i]);
    }
    b[n] = 0;
    for (i = n; i >= 0; --i)
    {
        b[i - 1] = a[i] + x * b[i];
    }
    printf("\n remainder of the functional value of polynomial at x=%d is %d", x, b[0]);
    printf("\n quotient of the polynomial is:\n");
    for (i = n - 1; i >= 0; --i)
    {
        if (b[i] > 0)
        {
            printf("+");
        }
        // if (b[i] < 0)
        // {
        //     printf("-")
        // }
        printf("%dx^%d", b[i], i);
    }
    printf(" = 0");
}
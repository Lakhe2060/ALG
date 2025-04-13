#include <stdio.h>

int main()
{
    int n;
    int x;
    int i;
    int a[10];
    int b = 0;
    printf("\n enter the  degree of polynomial:");
    scanf("%d", &n);
    printf("\n point to be evaluated:");
    scanf("%d", &x);
    printf("\n enter the coefficients:");
    for (i = 0; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    b = a[0];
    for (i = 1; i <= n; i++)
    {
        b = a[i] + b * x;
    }
    printf("\n the functional value of given polynomail at x=%d is %d", x, b);
    return 0;
}
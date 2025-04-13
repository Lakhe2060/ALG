#include <stdio.h>
#include <stdlib.h>
int main()
{
    float n;
    float X[10];
    int i, j;
    float dd[10];
    float v = 0;

    float fx[10];
    printf("\n enter the number of data:");
    scanf("%f", &n);
    float x;
    printf("\n enter the value of x:");
    scanf("%f", &x);
    printf("\n enter the values of x from table:");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &X[i]);
    }
    printf("\n enter the corresponding functional values:");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &fx[i]);
        dd[i] = fx[i];
    }

    for (i = 0; i < n; i++)
    {
        for (j = n - 1; j > i; --j)
        {
            dd[j] = (dd[j] - dd[j - 1]) / (X[j] - X[j - i - 1]);
        }
    }
    for (i = 0; i < n; i++)
    {
        printf("\n %f", dd[i]);
    }
    v = dd[1] + (dd[2] * ((x - X[0]) + (x - X[1])) + (dd[3] * ((x - X[0]) * (x - X[1]) + (x - X[1]) * (x - X[2]) + ((x - X[0]) * (x - X[2])))));

    printf("\n the first derivative at x=%f is %f", x, v);
    return 0;
}

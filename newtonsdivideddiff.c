#include <stdio.h>
#include <stdlib.h>
int main()
{
    float n;
    float X[10];
    int i, j;
    float dd[10];
    float v = 0;
    float p = 1;
    float fx[10];
    printf("\n enter the number of points:");
    scanf("%f", &n);
    float x;
    printf("\n enter the value at which interpolated:");
    scanf("%f", &x);
    printf("\n enter the values of x:");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &X[i]);
    }
    printf("\n enter the functional values:");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &fx[i]);
    }
    for (i = 0; i < n; i++)
    {
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
    v = fx[0];
    for (i = 1; i < n; i++)
    {
        for (j = 0; j >= i - 1; --j)
        {
            p = p * (x - X[j]);
        }
        v = v + dd[i] * p;
        p = 1;
    }
    printf("\n interpolated value is %f", v);
    return 0;
}
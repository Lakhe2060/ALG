#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    float pivot;
    float value;
    printf("\n enter the dimension of system of equation:");
    scanf("%d", &n);
    printf("\n enter the coefficients of matrix row-wise:");
    float a[10][10], x[10];
    int i, j, k;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }
    // printf("\n enter the RHS vector:");
    // float b[i];
    // for (i = 0; i < n; i++)
    // {
    //     scanf("%f", &b[i]);
    // }
    pivot = a[1][1];
    if (pivot <= 0.00001)
    {
        printf("\n method fails!!!");
        exit(0);
    }
    for (i = 1; i <= n; i++)
    {
        pivot = a[i][i];
        for (j = i + 1; j <= n; j++)
        {
            value = a[j][i] / pivot;
            for (k = 1; k <= n + 1; k++)
            {
                a[j][k] = a[j][k] - (value * a[i][k]);
            }
        }
    }
    x[n] = a[n][n + 1] / a[n][n];
    for (i = n - 1; i > 0; --i)
    {
        x[i] = a[i][n + 1];
        for (j = i + 1; j <= n; j++)
        {
            x[i] = x[i] - (a[i][j] * x[j]);
        }
        x[i] = x[i] / a[i][i];
    }
    printf("\n required answer are:");
    for (i = 1; i <= n; i++)
    {
        printf("\nx[%d]=%f", i, x[i]);
    }
    return (0);
}
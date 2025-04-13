#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void pivotswap(int n, float a[10][10], int m)
{
    float temp;
    int i, j;
    for (i = m; i < n; i++)
    {
        if (fabs(a[1][1]) < fabs(a[i + 1][1]))
        {
            for (j = 1; j <= n; j++)
            {
                temp = a[1][j];
                a[1][j] = a[i + 1][j];
                a[i + 1][j] = temp;
            }
        }
    }
}
int main()
{
    int n;
    float value, pivot;

    printf("\n enter the dimension of system of :");
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

    for (i = 1; i < n; i++)
    {
        pivotswap(n, a, i);
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
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
    float a[10][10];
    int i, j, k, l;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    for (i = 1; i <= n; i++)
    {
        pivot = a[i][i];
        for (j = 1; j <= n + 1; j++)
        {
            a[i][j] = a[i][j] / pivot;
        }
        for (k = 1; k <= n; k++)
        {
            if (i != k)
            {
                value = a[k][i];
                for (l = 1; l <= n + 1; l++)
                {
                    a[k][l] = a[k][l] - (a[i][l] * value);
                }
            }
        }
    }

    printf("\n required answer are:");
    for (i = 1; i <= n; i++)
    {
        printf("\nx[%d]=%f", i, a[i][n + 1]);
    }
    return (0);
}
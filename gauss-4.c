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
    float a[10][10], m;
    int i, j, k, l;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%f", &a[i][j]);
            if (i == j)
            {
                m = 1;
            }
            else
            {
                m = 0;
            }

            a[i][n + j] = m;
        }
    }

    for (i = 1; i <= n; i++)
    {
        pivot = a[i][i];
        for (j = 1; j <= n * 2; j++)
        {
            a[i][j] = a[i][j] / pivot;
        }
        for (k = 1; k <= n; k++)
        {
            if (i != k)
            {
                value = a[k][i];
                for (l = 1; l <= 2 * n; l++)
                {
                    a[k][l] = a[k][l] - (a[i][l] * value);
                }
            }
        }
    }

    printf("\n inverse of the matrix is:");
    for (i = 1; i <= n; i++)
    {
        printf("\n");
        for (j = 1; j <= n; j++)
        {
            printf("\t%f", a[i][n + j]);
        }
    }
    return (0);
}
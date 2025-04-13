#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n;
    float sum = 0;
    int i, j, k;
    float a[10][10], l[10][10], u[10][10], c[10], z[10];
    float x[10];
    printf("\n enter the dimension of matrix:");
    scanf("%d", &n);
    printf("\n enter the data of matrix a:");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }
    printf("\n enter the RHS vextor:");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &c[i]);

        u[0][i] = a[0][i];
        l[i][0] = a[i][0] / u[0][0];
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i < j)
            {
                l[i][j] = 0;
            }
            else if (i == j)
            {
                l[i][j] = 1;
            }
            else
            {
                u[i][j] = 0;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (k = i; k < n; k++)
        {
            sum = 0;
            for (j = 0; j < i; j++)
            {
                sum = sum + (l[i][j] * u[j][k]);
            }

            u[i][k] = a[i][k] - sum;
        }

        for (k = i; k < n; k++)
        {
            if (i != k)
            {
                sum = 0;
                for (j = 0; j < i; j++)
                {
                    sum = sum + (l[k][j] * u[j][i]);
                }

                l[k][i] = (a[k][i] - sum) / u[i][i];
            }
        }
    }
    printf("\n check l matrix:");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            printf("\t %f", l[i][j]);
        }
    }
    printf("\n check u matrix:");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
        {
            printf("\t %f", u[i][j]);
        }
    }
    z[0] = c[0];
    for (i = 0; i < n; i++)
    {
        z[i] = c[i];
        for (j = 0; j < i; j++)
        {
            z[i] -= l[i][j] * z[j];
        }
    }
    printf("\n\n[z]: \n");
    for (i = 0; i < n; i++)
    {
        printf("%9.3f", z[i]);
    }
    for (i = n - 1; i >= 0; i--)
    {
        x[i] = z[i];
        for (j = i + 1; j < n; j++)
        {
            x[i] -= u[i][j] * x[j];
        }
        x[i] /= u[i][i];
    }
    for (i = 0; i < n; i++)
    {
        printf("\n z[%d]=%f", i, z[i]);
    }

    printf("\n solutio:");
    for (i = 0; i < n; i++)
    {
        printf("\n x[%d]=%f", i + 1, x[i]);
    }
    return 0;
}
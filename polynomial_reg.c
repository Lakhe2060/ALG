#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main()
{
    int i, j, n;
    int op;
    int m;
    float x[10], y[10];
    float s[10], sx[10], sy[10];
    float coef[10];
    float a[10][10];
    printf("\n enter the no. of data points:");
    scanf("%d", &n);
    printf("\n enter the order of the polynomial:");
    scanf("%d", &op);
    if (n < op)
    {
        printf("\n regression is not possible");
        exit(0);
    }
    m = op + 1;

    printf("\n enter the x data:");
    for (i = 0; i < n; i++)

    {
        scanf("%f", &x[i]);
    }
    printf("\n enter the y data:");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &y[i]);
    }
    sx[0] = n;
    for (i = 0; i < n + 1; i++)
    {
        s[i] = 0;
        for (j = 0; j < n; j++)
        {
            s[i] = s[i] + pow(x[j], i + 1);
        }
        sx[i + 1] = s[i];
    }

    for (i = 0; i < m; i++)
    {
        sy[i] = 0;
        for (j = 0; j < n; j++)
        {
            sy[i] = sy[i] + y[j] * (pow(x[j], i));
        }
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            a[i][j] = sx[i + j];
        }
    }
    for (i = 0; i < m - 1; i++)
    {
        for (j = i + 1; j < m; j++)
        {
            float factor = a[j][i] / a[i][i];
            for (int k = i; k < m; k++)
            {
                a[j][k] -= factor * a[i][k];
            }
            sy[j] -= factor * sy[i];
        }
    }
    for (i = m - 1; i >= 0; i--)
    {
        coef[i] = sy[i] / a[i][i];
        for (j = i - 1; j >= 0; j--)
        {
            sy[j] -= a[j][i] * coef[i];
        }
    }
    printf("\n Coefficients of the polynomial:\n");
    for (i = 0; i < m; i++)
    {
        printf("a%d = %f\n", i, coef[i]);
    }

    printf("\n required equation is: y=");
    for (i = 0; i < m; i++)
    {
        printf("%f*x^%d", coef[i], i);
        if (i < op)
        {
            printf("+");
        }
    }

    // for (i = 0; i < n; i++)
    // {
    //     for (j = 0; j <= n; i++)
    //     {
    //     }
    // }
    return 0;
}
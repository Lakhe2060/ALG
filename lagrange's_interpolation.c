#include <stdio.h>
int main()

{
    int i, j, n;
    float x[10], y[10], a, lx[10], value = 0;
    printf("\n enter the no. of data");
    scanf("%d", &n);
    printf("\n enter the value of a:");
    scanf("%f", &a);
    printf("\n enter the data of x");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("\n enter the data y:");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &y[i]);
    }
    for (i = 0; i < n; i++)
    {
        lx[i] = 1;
        for (j = 0; j < n; j++)
        {
            if (i != j)
            {
                lx[i] = lx[i] * ((a - x[j]) / (x[i] - x[j]));
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        value = value + y[i] * lx[i];
    }
    printf("\n the interpolated value is %f", value);
}

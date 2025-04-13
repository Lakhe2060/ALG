#include <stdio.h>
#include <math.h>
int main()
{
    int n, i, j;
    float h, a, b, c;
    float s1, s2;
    float temp, x1, x2, value;
    float x[10], y[10], fd[10];
    printf("\n enter the number of data:");
    scanf("%d", &n);
    printf("\n enter the x data:");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("\n enter the y data:");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &y[i]);
        fd[i] = y[i];
    }
    h = x[1] - x[0];
    for (i = 0; i < n; i++)
    {
        for (j = n - 1; j > 1; --j)
        {
            fd[j] = fd[j] - fd[j - 1];
        }
    }

    a = fd[3] / 2;
    b = fd[2] - fd[3];
    c = fd[1] - (fd[2] / 2) + (fd[3] / 3);
    temp = (b * b) - (4 * a * c);
    temp = sqrt(temp);
    s1 = (-b + temp) / (2 * a);
    s2 = (-b - temp) / (2 * a);
    x1 = x[0] + s1 * h;
    x2 = x[0] + s2 * h;
    value = (fd[2] + fabs((6 * s2 - 6) * fd[3])) / (h * h);
    if (value < 0)
    {
        printf("\n maxima at %f", x2);
    }
    else
    {
        printf("\n minima at %f", x1);
    }
    return 0;
}
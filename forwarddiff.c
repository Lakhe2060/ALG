#include <stdio.h>
int fact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return (n * fact(n - 1));
    }
}
int main()
{
    int factorial;
    int i, j, n;
    float calc;
    float xp, x[10], y[10], fd[10];
    float h, s;
    printf("\n enter the no. of data");
    scanf("%d", &n);
    printf("\n enter the value to be interpolated:");
    scanf("%f", &xp);
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
    s = (xp - x[0]) / h;
    for (i = 0; i < n; i++)
    {
        for (j = n - 1; j > i; --j)
        {
            fd[j] = fd[j] - fd[j - 1];
        }
    }
    // for (i = 0; i < n; i++)
    // {
    //     printf("\n%f", fd[i]);
    // }
    float v = fd[0];
    float p = 1;
    for (i = 1; i < n; i++)
    {

        for (j = 0; j < i; j++)
        {
            p = p * (s - j);
        }
        // printf("\n %f", p);
        factorial = fact(i);
        calc = (fd[i] * p) / factorial;
        v = v + calc;
        p = 1;
        // printf("\n %f", calc);
    }
    printf("\n required interpolated value is %f", v);
    return 0;
}
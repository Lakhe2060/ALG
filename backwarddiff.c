#include <stdio.h>
int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return (n * fact(n - 1));
}

int main()
{
    int i, j, n;
    float x[10], y[10];
    float xp;
    float bd[10];
    int factorial;
    float h, s, v, p = 1, calc;
    printf("\n enter the no. of data:");
    scanf("%d", &n);
    printf("\n enter the value to be interpolated at:");
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
        bd[i] = y[i];
    }
    v = bd[n - 1];
    h = x[1] - x[0];
    s = (xp - x[n - 1]) / h;
    for (i = n - 1; i > 0; --i)
    {
        for (j = 0; j < i; j++)
        {
            bd[j] = bd[j + 1] - bd[j];
        }
    }
    for (i = 1; i < n; i++)

    {
        for (j = 1; j < i; j++)
        {
            p = p * (s + j - 1);
        }
        factorial = fact(i);
        calc = (bd[n - i - 1] * p) / factorial;
        v = v + calc;
        p = 1;
    }
    printf("\n required interpolated value is %f", v);

    return 0;
}

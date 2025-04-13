#include <stdio.h>
#include <math.h>
#define f(x) (x * x) - 3 * x + 2
#define df(x) 2 * x - 3
int main()
{
    float x0, x1, f0, df0, e = 0.0000;
    printf("\n enter the initial guess:");
    scanf("%f", &x0);
    do
    {
        f0 = f(x0);
        df0 = df(x0);
        x1 = x0 - (f0 / df0);
        x0 = x1;
    } while (fabs(f0) > e);
    printf("\n req root is %f", x1);
    return 0;
}
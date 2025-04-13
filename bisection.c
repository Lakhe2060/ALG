#include <stdio.h>
#include <math.h>
#define f(x) (x * x) - 4 * x - 10
int main()
{
    float x0, x1, x2, f0, f1, f2, e = 0.0001058;
    printf("\n enter the first two guesses:");
    scanf("%f %f", &x1, &x2);
    x0 = x1;
    x1 = x2;
    do
    {

        f0 = f(x0);
        f1 = f(x1);
        if ((f1 * f0) < 0)
        {
            x2 = ((x0 + x1) / 2);
            f2 = f(x2);
            if (f2 * f1 < 0)
            {
                x0 = x2;
            }
            if (f2 * f0 < 0)
            {
                x1 = x2;
            }
        }
    } while (fabs(f2) > e);
    printf("\n required root is %f", x2);
    return 0;
}
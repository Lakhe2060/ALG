#include <stdio.h>
#include <math.h>
#define f(x) ((x * x) - (3 * x) + 2)
#define g(x) ((2 * x) - 3)
int main()
{
    float x0, x1, e, x;
    printf("\n enter a initial guess and error:");
    scanf("%f %f", &x0, &e);
    do
    {
        x1 = x0 - (f(x0) / g(x0));
        x = x0;
        x0 = x1;
    } while (fabs((x0 - x) / x) >= e);
    printf("\n the root is %f", x0);
    return 0;
}
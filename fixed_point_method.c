#include <stdio.h>
#include <math.h>
#define g(x) (cos(x) - 3 * x + 1)
#define f(x) ((cos(x) + 1) / 3)
int main()
{
    float x0, x1, e = 0.0001;
    printf("\n enter the initial guess:");
    scanf("%f", &x0);
    do
    {
        x1 = f(x0);
        x0 = x1;
    } while (fabs(g(x1) >= e));
    printf("\n root is: %f", x1);
    return 0;
}
#include <stdio.h>
#include <math.h>
#define f(x, y) ((x * x) + (x * y) - 6)
#define dxf(x, y) (2 * x + y)
#define dyf(x, y) (x)
#define g(x, y) ((x * x) - (y * y) - 3)
#define dxg(x, y) (2 * x)
#define dyg(x, y) (-(2 * y))
int main()
{
    float f, g, x0, y0, x1, y1, f0, f1, g0, D, g1, e = 0.0001;
    printf("\n enter initial guesses:");
    scanf("%f%f", &x1, &y1);
    do
    {
        x0 = x1;
        y0 = y1;
        f0 = dxf(x0, y0);
        f1 = dyf(x0, y0);
        g0 = dxg(x0, y0);
        g1 = dyg(x0, y0);
        D = (f0 * g1) - (f1 * g0);
        f = f(x0, y0);
        g = g(x0, y0);

        x1 = x0 - (((f * g1) - (f1 * g)) / D);
        y1 = y0 - (((g * f0) - (f * g0)) / D);

    } while (fabs(x1 - x0) > e && fabs(y1 - y0) > e);
    printf("\n root is: (%f,%f)", x1, y1);
    return 0;
}
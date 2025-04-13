#include <stdio.h>
#include <math.h>
#define f(x) sqrt(1 - (x * x))
int main()
{
    float a, b, h, xi;
    float sum;
    int i;
    printf("\n enter the lower and upper limits:");
    scanf("%f %f", &a, &b);
    h = (b - a) / 3;
    sum = f(a) + f(b);
    for (i = 1; i < 3; i++)
    {
        xi = a + i * h;
        sum = sum + 3 * f(xi);
    }
    sum = sum * 3 * h / 8;
    printf("\n required answer is:%f", sum);
    return 0;
}
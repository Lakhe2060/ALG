#include <stdio.h>
#include <math.h>
#define f(x) sqrt(1 - (x * x))
int main()
{
    float a, b, h, c;
    printf("\n enter the lower and upper limits:");
    scanf("%f %f", &a, &b);
    h = (b - a) / 2;
    c = a + h;
    float sum = f(a) + 4 * f(c) + f(b);
    sum = (sum * h) / 3;
    printf("\n required answer is %f", sum);
    return 0;
}
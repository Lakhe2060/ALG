#include <stdio.h>
#include <math.h>
#define f(x) sqrt(1 - (x * x))
int main()
{
    float a, b, h, k;
    float sum, xi;
    int i;
    printf("\n enter the lower and upper limits:");
    scanf("%f %f", &a, &b);
    printf("\n enter the value of segments:");
    scanf("%f", &k);
    h = (b - a) / k;
    sum = f(a) + f(b);
    for (i = 1; i < k; i++)
    {
        xi = a + (i * h);
        printf("\n%f", xi);
        if ((i % 2) == 0)
        {
            sum = sum + 2 * f(xi);
        }
        else
        {
            sum = sum + 4 * f(xi);
        }
    }
    sum = (sum * h) / 3;
    printf("\n required answer is %f", sum);
    return 0;
}
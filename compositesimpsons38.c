#include <stdio.h>
#include <math.h>
#define f(x) (x * x * x) + 1
int main()
{
    float a, b, h;
    float sum, xi;
    int i, k;
    printf("\n enter the lower and upper limits:");
    scanf("%f %f", &a, &b);
    printf("\n enter the value of segment:");
    scanf("%d", &k);
    h = (b - a) / k;
    sum = f(a) + f(b);
    for (i = 1; i < k; i++)
    {
        xi = a + h * i;
        if (i % k != 0)
        {

            sum = sum + 3 * f(xi);
        }
        else
        {
            sum = sum + 2 * f(xi);
        }
    }
    sum = sum * h * 3 / 8;
    printf("\n required answer is %f", sum);
    return 0;
}
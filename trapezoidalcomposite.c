#include <stdio.h>
#include <math.h>
#define f(x) exp(x)
int main()
{
    float a, b;
    float k, h, sum;
    float m;
    int i;
    printf("\n enter the lower and upper limits:");
    scanf("%f %f", &a, &b);
    printf("\n enter the no. of segments:");
    scanf("%f", &k);
    h = ((b - a)) / k;

    sum = f(a) + f(b);
    for (i = 1; i < k; i++)
    {
        m = a + (h * i);
        sum = sum + 2 * f(m);
    }
    sum = (sum * h) / 2;
    printf("\n required integrated value is %f", sum);

    return 0;
}
#include <stdio.h>
#define f(x) x *x
int main()
{
    float x, n, h, f1;
    printf("\n enter the value of x");
    scanf("%f", &x);
    printf("\n enter the value of h");
    scanf("%f", &h);
    n = x - h;
    f1 = (f(x) - f(n)) / h;
    printf("\n required answer is %f", f1);
    return 0;
}
#include <stdio.h>
#define f(x) x *x *x + 2
int main()
{
    float a, b;
    float f1, f2;
    printf("\n enter the values of lower and upper limits:");
    scanf("%f %f", &a, &b);
    float h = b - a;
    f1 = f(a);
    f2 = f(b);
    float f3 = ((f2 + f1) / 2) * h;
    printf("\n the required answer is %0.2f", f3);
    return 0;
}
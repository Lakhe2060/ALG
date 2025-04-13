#include <stdio.h>
#define f(x) x *x
int main()
{
    float x, h, f1;
    printf("\n enter the value of x: ");
    scanf("%f", &x);
    printf("\n enter the value of h: ");
    scanf("%f", &h);
    float n2 = x - h;
    float n1 = x + h;
    f1 = (f(n1) - f(n2)) / (2 * h);
    printf("\n required answer is %f", f1);
    return 0;
}
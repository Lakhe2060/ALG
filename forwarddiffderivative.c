#include <stdio.h>
#define f(x) x *x
int main()
{
    float x;
    float f1;
    float h;
    printf("\n enter the valued of x:");
    scanf("%f", &x);
    printf("\n enter the value of h:");
    scanf("%f", &h);
    float n = x + h;
    f1 = (f(n) - f(x)) / h;
    printf("\n required answer is %f", f1);
    return 0;
}
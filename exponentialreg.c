#include <stdio.h>
#include <math.h>
int main()
{
    int n, i;
    float a, b;
    float lgy;
    float x[10], y[10], sx = 0, slgy = 0, sxlgy = 0, sx2 = 0;
    printf("\n enter the no. of data:");
    scanf("%d", &n);
    printf("\n enter the x data:");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("\n enter the y data:");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &y[i]);
    }
    for (i = 0; i < n; i++)
    {
        sx = sx + x[i];
        lgy = log(y[i]);
        slgy = slgy + lgy;
        sxlgy = sxlgy + (x[i] * lgy);
        sx2 = sx2 + (x[i] * x[i]);
    }
    b = ((n * sxlgy) - (sx * slgy)) / ((n * sx2) - (sx * sx));
    a = (slgy / n) - (b * (sx / n));
    a = exp(a);
    printf("\n required answer is:/n y=%f*e^%f", a, b);
    return 0;
}
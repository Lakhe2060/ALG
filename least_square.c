#include <stdio.h>
int main()
{
    int i, n;
    float x[10], y[10];
    float a, b;
    float sx = 0, sy = 0, sxy = 0, sx2 = 0;
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
        sy = sy + y[i];
        sxy = sxy + (x[i] * y[i]);
        sx2 = sx2 + (x[i] * x[i]);
    }
    b = ((n * sxy) - (sx * sy)) / ((n * sx2) - (sx * sx));
    a = (sy / n) - ((b * sx) / n);
    printf("\n a=%f,b=%f", a, b);
    printf("\n y = %fx", a);
    if (b > 0)
        printf("+");
    printf("%f", b);
    return 0;
}
#include <stdio.h>
int main()
{
    float h;
    int i, n;
    float sum;
    float x[20], y[20];
    printf("\n enter the number of data:");
    scanf("%d", &n);
    printf("\n enter the x data:");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &x[i]);
    }
    printf("\n enter the functionat data:");
    for (i = 0; i < n; i++)
    {
        scanf("%f", &y[i]);
    }
    h = x[1] - x[0];
    sum = y[0] + y[n - 1];
    for (i = 1; i < n - 1; i++)
    {

        if (i % n != 0)
        {

            sum = sum + 3 * y[i];
        }
        else
        {
            sum = sum + 2 * y[i];
        }
    }
    sum = sum * h * 3 / 8;
    printf("\n required answer is %f", sum);
    return 0;
}
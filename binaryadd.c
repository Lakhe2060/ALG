#include <stdio.h>
int main()
{
    int a[10], b[10], s[11];
    int i, j, k, tmp1, tmp2, tmp3, d, C = 0, m, n;
    int l;
    printf("\n Enter the no. of bits of 1st and 2nd binary numbers:");
    scanf("%d%d", &m, &n);
    if (m > n)
    {
        tmp2 = m - n;
        tmp1 = 1;
        tmp3 = m;
        for (i = 1; i <= tmp2; i++)
        {
            b[i] = 0;
        }
        k = tmp1;
        l = tmp2++;
    }
    else if (m < n)
    {
        tmp2 = 1;
        tmp1 = n - m;
        tmp3 = n;
        for (i = 1; i <= tmp1; i++)
        {
            a[i] = 0;
        }
        k = tmp1++;
        l = tmp2;
    }
    else
    {
        tmp1 = 1;
        tmp2 = 1;
        tmp3 = m;
        k = 1;
        l = 1;
    }
    printf("\n Enter 1st binary number:");
    for (i = k; i <= tmp3; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("\n Enter 2nd binary number:");
    for (i = l; i <= tmp3; i++)
    {
        scanf("%d", &b[i]);
    }
    printf("\n 1st binary number is:");
    for (i = 1; i <= tmp3; i++)
    {
        printf("%d", a[i]);
    }
    printf("\n 2nd binary number is:");
    for (i = 1; i <= tmp3; i++)
    {
        printf("%d", b[i]);
    }
    j = tmp3;
    for (i = tmp3; i > 0; i--)
    {
        d = a[i] + b[i] + C;
        d = d / 2;
        s[j] = (a[i] + b[i] + C) - (2 * d);
        C = d;
        j--;
    }
    s[j] = C;

    printf("\n the sum is:\n");
    for (i = 0; i <= tmp3; i++)
    {
        printf("%d", s[i]);
    }
}
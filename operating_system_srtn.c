#include <stdio.h>
#include <conio.h>
#define N 10

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int i, j, n;
    int p[N], r[N], b[N], c[N], t[N], w[N];
    printf("\n Enter the number of processes:");
    scanf("%d", &n);
    printf("\n Enter the release time and burst time :");
    for (i - 0; i < n; i++)
    {
        scanf("%d%d", &r[i], &b[i]);
        p[i] = i + 1;
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (r[j] > r[j + 1])
            {
                swap(&p[j], &p[j + 1]);
                swap(&r[j], &r[j + 1]);
                swap(&b[j], &b[j + 1]);
            }
        }
    }
    
}
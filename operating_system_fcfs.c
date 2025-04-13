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
    float At = 0, Aw = 0;
    int r[N], b[N], c[N], t[N], w[N], p[N];
    printf("\n enter the num of processes:");
    scanf("%d", &n);
    printf("\n enter the release time and burst time:");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &r[i], &b[i]);
        p[i] = i + 1;
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (r[j] > r[j + 1])
            {
                swap(&r[j], &r[j + 1]);
                swap(&b[j], &b[j + 1]);
                swap(&p[j], &p[j + 1]);
            }
        }
    }

    c[0] = b[0];
    int d = 0;

    for (i = 1; i < n; i++)
    {
        if (r[i] > c[i - 1])
        {
            d = r[i];
            // c[i] = b[i] + r[i];
        }
        d += b[i];
        c[i] = d;
    }
    for (i = 0; i < n; i++)
    {
        t[i] = c[i] - r[i];
        w[i] = t[i] - b[i];
        At += t[i];
        Aw += w[i];
    }
    At = At / n;
    Aw = Aw / n;
    printf("\n\t process\trelease_time\tburst_time\tcompletion_time\t turn_around_time\twaiting_time\n");
    for (i = 0; i < n; i++)
    {
        printf("\t  p%d\t\t%d\t\t%d\t\t\t%d\t\t%d\t\t\t%d\n", p[i], r[i], b[i], c[i], t[i], w[i]);
    }
    printf("\n avg. turn around time is %0.2f\n avg. wating time is %0.2f", At, Aw);
    return 0;
}

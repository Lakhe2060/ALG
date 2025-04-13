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
    int i, j, n, r[N], b[N];
    float At = 0, Aw = 0;
    int p[N];
    printf("\n enter the number of processes:");
    scanf("%d", &n);
    printf("\n enter the release time and burst time:");
    for (i = 0; i < n; i++)
    {
        scanf("%d %d", &r[i], &b[i]);
        p[i] = i + 1;
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (r[j] > r[j + 1])
            {
                swap(&r[j], &r[j + 1]);
                swap(&b[j], &b[j + 1]);
                swap(&p[j], &p[j + 1]);
            }
            if (r[j] == r[j + 1])
            {
                if (b[j] > b[j + 1])
                {
                    swap(&r[j], &r[j + 1]);
                    swap(&b[j], &b[j + 1]);
                    swap(&p[j], &p[j + 1]);
                }
            }
        }
    }
    int currentTime = 0;
    int remP = n;
    printf("\n\t process\trelease_time\tburst_time\tcompletion_time\t turn_around_time\twaiting_time\n");

    while (remP > 0)
    {
        int index = -1;
        int burst = N;

        for (i = 0; i < n; i++)
        {
            if (r[i] <= currentTime && b[i] < burst)
            {
                burst = b[i];
                index = i;
            }
        }

        if (index == -1)
        {
            currentTime++;
            continue;
        }

        printf("\t  P%d\t\t%d\t\t%d\t\t\t%d\t\t%d\t\t\t%d\n",
               p[index],
               r[index],
               b[index],
               currentTime + b[index],
               currentTime + b[index] - r[index],
               currentTime - r[index]);
        At += currentTime + b[index] - r[index];
        Aw += currentTime - r[index];
        currentTime += b[index];
        b[index] = N;
        remP--;
    }
    printf("\n avg.TAT is %0.2f\n avg.WT is %0.2f", At, Aw);
}

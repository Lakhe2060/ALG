#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

struct P
{
    int AT, BT, WT, FT, TAT, pos;
};

int quant;

int main()
{
    int n, i;

    printf("Enter the no. of processes: ");
    scanf("%d", &n);
    struct P p[n];

    printf("Enter the quantum: ");
    scanf("%d", &quant);

    printf("Enter the process numbers: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &(p[i].pos));

    printf("Enter the Arrival time of processes: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &(p[i].AT));

    printf("Enter the Burst time of processes: \n");
    for (i = 0; i < n; i++)
        scanf("%d", &(p[i].BT));

    int c = n;
    float time = 0, mini = INT_MAX, b[n], a[n];

    for (i = 0; i < n; i++)
    {
        b[i] = p[i].BT;
        a[i] = p[i].AT;
    }

    int tot_wt = 0, tot_tat = 0;
    bool flag = false;

    while (c != 0)
    {
        mini = INT_MAX;
        flag = false;

        for (i = 0; i < n; i++)
        {
            float p = time + 0.1;
            if (a[i] <= p && mini > a[i] && b[i] > 0)
            {
                mini = a[i];
                flag = true;
            }
        }

        if (!flag)
        {
            time++;
            continue;
        }

        int index = -1;
        for (i = 0; i < n; i++)
        {
            float p = time + 0.1;
            if (a[i] <= p && mini == a[i] && b[i] > 0)
            {
                index = i;
                break;
            }
        }

        if (b[index] <= quant)
        {
            time += b[index];
            b[index] = 0;
        }
        else
        {
            time += quant;
            b[index] -= quant;
        }

        if (b[index] > 0)
        {
            a[index] = time + 0.1;
        }

        if (b[index] == 0)
        {
            c--;
            p[index].FT = time;
            p[index].WT = p[index].FT - p[index].AT - p[index].BT;
            tot_wt += p[index].WT;
            p[index].TAT = p[index].BT + p[index].WT;
            tot_tat += p[index].TAT;
        }
    }

    printf("Process number Arrival time Burst time Final time Wait Time TurnAround Time\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t\t", p[i].pos);
        printf("%d\t\t", p[i].AT);
        printf("%d\t\t", p[i].BT);
        printf("%d\t\t", p[i].FT);
        printf("%d\t\t", p[i].WT);
        printf("%d\n", p[i].TAT);
    }

    double avg_wt = (double)tot_wt / n;
    double avg_tat = (double)tot_tat / n;

    printf("The average wait time is: %0.2f\n", avg_wt);
    printf("The average TurnAround time is: %0.2f\n", avg_tat);

    return 0;
}

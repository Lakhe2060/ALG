#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void calculatedifference(int request[], int head, int diff[][2], int n)
{
    for (int i = 0; i < n; i++)
    {
        diff[i][0] = abs(head - request[i]);
    }
}

int findMIN(int diff[][2], int n)
{
    int index = -1;
    int minimum = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (!diff[i][1] && minimum > diff[i][0])
        {
            minimum = diff[i][0];
            index = i;
        }
    }
    return index;
}

void shortestSeekTimeFirst(int request[], int head, int n)
{
    if (n == 0)
    {
        return;
    }

    int diff[n][2];
    for (int i = 0; i < n; i++)
    {
        diff[i][0] = 0;
        diff[i][1] = 0;
    }

    int seekcount = 0;

    int seeksequence[n + 1];
    for (int i = 0; i <= n; i++)
    {
        seeksequence[i] = 0;
    }

    for (int i = 0; i < n; i++)
    {
        seeksequence[i] = head;
        calculatedifference(request, head, diff, n);
        int index = findMIN(diff, n);
        diff[index][1] = 1;

        seekcount += diff[index][0];

        head = request[index];
    }
    seeksequence[n] = head;

    printf("Total number of seek operations = %d\n", seekcount);
    printf("Seek sequence is:\n");

    for (int i = 0; i <= n; i++)
    {
        printf("%d\n", seeksequence[i]);
    }
}

int main()
{
    int n, head;
    printf("Enter the number of disk requests: ");
    scanf("%d", &n);
    int proc[n];
    printf("Enter the disk requests: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &proc[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);

    shortestSeekTimeFirst(proc, head, n);

    return 0;
}

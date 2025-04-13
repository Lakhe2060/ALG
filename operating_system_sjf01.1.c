#include <stdio.h>
#include <limits.h>

#define N 10

typedef struct
{
    int release_time;
    int burst_time;
    int process_id;
} Process;

void swap(Process *a, Process *b)
{
    Process temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n, i;
    printf("\nEnter the number of processes: ");
    scanf("%d", &n);

    Process processes[N];
    printf("\nEnter the release time and burst time for each process:\n");
    for (i = 0; i < n; i++)
    {
        printf("Process P%d: ", i + 1);
        scanf("%d %d", &processes[i].release_time, &processes[i].burst_time);
        processes[i].process_id = i + 1;
    }

    for (i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (processes[j].release_time > processes[j + 1].release_time ||
                (processes[j].release_time == processes[j + 1].release_time &&
                 processes[j].burst_time > processes[j + 1].burst_time))
            {
                swap(&processes[j], &processes[j + 1]);
            }
        }
    }

    int currentTime = 0;
    int remainingProcesses = n;

    printf("\n\t process\trelease_time\tburst_time\tcompletion_time\t turn_around_time\twaiting_time\n");

    while (remainingProcesses > 0)
    {
        int shortestJobIndex = -1;
        int shortestJobBurst = INT_MAX;

        for (i = 0; i < n; i++)
        {
            if (processes[i].release_time <= currentTime && processes[i].burst_time < shortestJobBurst)
            {
                shortestJobBurst = processes[i].burst_time;
                shortestJobIndex = i;
            }
        }

        if (shortestJobIndex == -1)
        {
            currentTime++;
            continue;
        }

        Process *currentProcess = &processes[shortestJobIndex];

        printf("\t  P%d\t\t%d\t\t%d\t\t\t%d\t\t%d\t\t\t%d\n",
               currentProcess->process_id,
               currentProcess->release_time,
               currentProcess->burst_time,
               currentTime + currentProcess->burst_time,
               currentTime + currentProcess->burst_time - currentProcess->release_time,
               currentTime - currentProcess->release_time);

        currentTime += currentProcess->burst_time;
        currentProcess->burst_time = INT_MAX;
        -remainingProcesses--;
    }

    return 0;
}

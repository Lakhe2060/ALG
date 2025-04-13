#include <stdio.h>

#define MAX_PROCESSES 10
#define MAX_RESOURCES 10

int main()
{
    int p, r;
    int AL[MAX_PROCESSES][MAX_RESOURCES], AV[MAX_RESOURCES], M[MAX_PROCESSES][MAX_RESOURCES], N[MAX_PROCESSES][MAX_RESOURCES];
    int processes[MAX_PROCESSES];

    printf("\nEnter the number of processes and resources: ");
    scanf("%d%d", &p, &r);
    for (int i = 0; i < p; i++)
        processes[i] = i + 1;

    printf("\nEnter the Allocated resources:\n");
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &AL[i][j]);

    printf("\nEnter the maximum resources required:\n");
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            scanf("%d", &M[i][j]);

    printf("\nEnter the available resources:\n");
    for (int i = 0; i < r; i++)
        scanf("%d", &AV[i]);

    // Calculating the resources needed
    for (int i = 0; i < p; i++)
        for (int j = 0; j < r; j++)
            N[i][j] = M[i][j] - AL[i][j];

    int work[MAX_RESOURCES];
    int finish[MAX_PROCESSES] = {0};
    int safeSeq[MAX_PROCESSES];
    int count = 0;

    for (int i = 0; i < r; i++)
        work[i] = AV[i];

    while (count < p)
    {
        int found = 0;
        for (int pIndex = 0; pIndex < p; pIndex++)
        {
            if (finish[pIndex] == 0)
            {
                int canExecute = 1;
                for (int j = 0; j < r; j++)
                {
                    if (N[pIndex][j] > work[j])
                    {
                        canExecute = 0;
                        break;
                    }
                }

                if (canExecute)
                {
                    for (int j = 0; j < r; j++)
                        work[j] += AL[pIndex][j];

                    safeSeq[count++] = pIndex;
                    finish[pIndex] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0)
            break;
    }

    if (count < p)
    {
        printf("System is not in a safe state!\n");
        return 0;
    }

    printf("System is in a safe state.\nSafe Sequence is: ");
    for (int i = 0; i < p; i++)
    {
        printf("P%d", processes[safeSeq[i]]);
        if (i == p - 1)
        {
            printf("\n");
        }
        else
        {
            printf("->");
        }
    }

    return 1;
}

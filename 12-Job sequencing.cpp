#include <stdio.h>
#include <stdlib.h>
typedef struct {
    int id;      
    int deadline; 
    int profit;   
} Job;
int compare(const void *a, const void *b) {
    Job *job1 = (Job *)a;
    Job *job2 = (Job *)b;
    return job2->profit - job1->profit; 
}
int job_sequencing(Job jobs[], int n, int *step_count) {
    int max_deadline = 0;
    for (int i = 0; i < n; i++) {
        (*step_count)++; 
        if (jobs[i].deadline > max_deadline) {
            max_deadline = jobs[i].deadline;
        }
    }
    int timeline[max_deadline];
    for (int i = 0; i < max_deadline; i++) {
        timeline[i] = -1; 
    }

    int total_profit = 0;
    for (int i = 0; i < n; i++) {
        (*step_count)++; 
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            (*step_count)++; 
            if (timeline[j] == -1) {
                timeline[j] = i; 
                total_profit += jobs[i].profit;
                break;
            }
        }
    }
    return total_profit;
}

main() {
    Job jobs[] = {
        {1, 4, 70}, 
        {2, 1, 50},
        {3, 1, 60},
        {4, 2, 100},
        {5, 3, 20}
    };
    int n = sizeof(jobs) / sizeof(jobs[0]);
    int steps = 0;
    qsort(jobs, n, sizeof(Job), compare);
    int max_profit = job_sequencing(jobs, n, &steps);
    printf("Maximum profit: %d\n", max_profit);
    printf("Total number of steps: %d\n", steps);
}


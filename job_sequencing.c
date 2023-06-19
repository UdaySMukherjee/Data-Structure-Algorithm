#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int deadline;
    int profit;
} job;

int max(int a, int b) {
    return a > b ? a : b;
}

int cmpfunc(const void *a, const void *b) {
    return ((job*)b)->profit - ((job*)a)->profit;
}

int job_sequencing(job jobs[], int n) {
    qsort(jobs, n, sizeof(job), cmpfunc);
    int i, j;
    int max_profit = 0;
    int slots[n];
    for (i = 0; i < n; i++) {
        slots[i] = -1;
    }
    for (i = 0; i < n; i++) {
        for (j = jobs[i].deadline - 1; j >= 0; j--) {
            if (j < n && slots[j] == -1) {
                slots[j] = jobs[i].id;
                max_profit += jobs[i].profit;
                break;
            }
        }
    }
    return max_profit;
}

int main() {
    int n = 5; // Number of jobs
    job jobs[] = {{1, 2, 100}, {2, 1, 19}, {3, 2, 27}, {4, 1, 25}, {5, 3, 15}};
    int max_profit = job_sequencing(jobs, n);
    printf("Maximum profit = %d", max_profit);
    return 0;
}

#include <stdio.h>

#define MAX_PROCESS 5
int i,j;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
};

void swap(struct Process *xp, struct Process *yp) {
    struct Process temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sortProcesses(struct Process processes[], int n) {
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (processes[j].burstTime > processes[j+1].burstTime) {
                swap(&processes[j], &processes[j+1]);
            }
        }
    }
}

void calculateWaitingTime(struct Process processes[], int n, int waitingTime[]) {
    waitingTime[0] = 0;
    for (i = 1; i < n; i++) {
        waitingTime[i] = processes[i-1].burstTime + waitingTime[i-1];
    }
}

void calculateTurnaroundTime(struct Process processes[], int n, int waitingTime[], int turnaroundTime[]) {
    for (i = 0; i < n; i++) {
        turnaroundTime[i] = processes[i].burstTime + waitingTime[i];
    }
}

void calculateAverageTime(struct Process processes[], int n) {
    int waitingTime[MAX_PROCESS], turnaroundTime[MAX_PROCESS];
    int totalWaitingTime = 0, totalTurnaroundTime = 0;

    calculateWaitingTime(processes, n, waitingTime);
    calculateTurnaroundTime(processes, n, waitingTime, turnaroundTime);

 

    int endTime = 0;
    for (i = 0; i < n; i++) {
        
        // Print Gantt chart
        printf(" ");
        for (j = 0; j < processes[i].burstTime; j++) {
            printf("--");
        }
        printf("\n");
        printf("|");
        for (j = 0; j < processes[i].burstTime - 1; j++) {
            printf(" ");
        }
        printf("P%d", processes[i].pid);
        for (j = 0; j < processes[i].burstTime - 1; j++) {
            printf(" ");
        }
        printf("|");

        endTime += processes[i].burstTime;
    }
    printf("\n");

    printf("\nAverage waiting time: %.2f\n", (float)totalWaitingTime/n);
    printf("Average turnaround time: %.2f\n", (float)totalTurnaroundTime/n);
}

int main() {
    struct Process processes[MAX_PROCESS] = {
        {1, 1, 3},
        {2, 2, 5},
        {3, 4, 2},
        {4, 0, 4},
        {5, 2, 2}
    };

    int n = sizeof(processes) / sizeof(processes[0]);

    sortProcesses(processes, n);
    calculateAverageTime(processes, n);

    return 0;
}


#include <stdio.h>

void findAverageTime(int processes[], int n, int bt[], int tq) {
    int wt[n], tat[n], rem_bt[n];
    int total_wt = 0, total_tat = 0;

    // Copy the burst time to remaining burst time array
    for (int i = 0; i < n; i++) {
        rem_bt[i] = bt[i];
        wt[i] = 0; // Initializing waiting time to 0
    }

    int time = 0;  // Track total time
    while (1) {
        int done = 1; // To check if all processes are completed

        for (int i = 0; i < n; i++) {
            // If process has remaining burst time
            if (rem_bt[i] > 0) {
                done = 0; // There is a pending process

                // Process the current process for the time quantum
                if (rem_bt[i] > tq) {
                    time += tq;
                    rem_bt[i] -= tq;
                } else {
                    time += rem_bt[i];
                    wt[i] = time - bt[i]; // Waiting time = total time - burst time
                    rem_bt[i] = 0; // Process is complete
                }
            }
        }

        // If all processes are done, exit the loop
        if (done == 1)
            break;
    }

    // Calculate turnaround time
    for (int i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i]; // Turnaround time = burst time + waiting time
    }

    // Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Display results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", processes[i], bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time: %.2f\n", (float)total_wt / n);
    printf("Average Turnaround Time: %.2f\n", (float)total_tat / n);
}

int main() {
    int n = 4;
    int processes[] = {1, 2, 3, 4};  // Process IDs
    int bt[] = {6, 2, 8, 3};  // Burst Times
    int tq = 4;  // Time Quantum

    // Call function to calculate average waiting time and turnaround time
    findAverageTime(processes, n, bt, tq);

    return 0;
}


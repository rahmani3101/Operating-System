#include <stdio.h>

#define MAX 10

// Structure to represent each process
struct Process {
    char name[3];       // Process name (now a string)
    int burstTime;
    int remainingTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};

// Function to calculate the average waiting time and turnaround time
void calculateAverageTimes(struct Process proc[], int n) {
    float totalWaitingTime = 0, totalTurnaroundTime = 0;
    for (int i = 0; i < n; i++) {
        totalWaitingTime += proc[i].waitingTime;
        totalTurnaroundTime += proc[i].turnaroundTime;
    }
    printf("\nAverage Waiting Time: %.2f\n", totalWaitingTime / n);
    printf("Average Turnaround Time: %.2f\n", totalTurnaroundTime / n);
}

// Round Robin CPU Scheduling
void roundRobin(struct Process proc[], int n, int timeQuantum) {
    int currentTime = 0, completed = 0;
    int queue[MAX], front = 0, rear = 0;
    
    // Enqueue all processes initially
    for (int i = 0; i < n; i++) {
        proc[i].remainingTime = proc[i].burstTime;
        queue[rear++] = i;
    }
    
    // Process the queue
    while (completed < n) {
        int i = queue[front++];
        if (front == MAX) front = 0;
        
        // Process the current task
        if (proc[i].remainingTime <= timeQuantum) {
            // The process finishes in this cycle
            currentTime += proc[i].remainingTime;
            proc[i].remainingTime = 0;
            proc[i].completionTime = currentTime;
            proc[i].turnaroundTime = proc[i].completionTime;
            proc[i].waitingTime = proc[i].turnaroundTime - proc[i].burstTime;
            completed++;
        } else {
            // Process gets time quantum to execute
            currentTime += timeQuantum;
            proc[i].remainingTime -= timeQuantum;
            queue[rear++] = i;  // Re-add process to queue if it still needs time
            if (rear == MAX) rear = 0;
        }
    }
    
    // Calculate and print average waiting time and average turnaround time
    calculateAverageTimes(proc, n);
}

int main() {
    // Declare processes with string names (using char arrays)
    struct Process proc[] = {
        {"P1", 6, 0, 0, 0, 0},
        {"P2", 4, 0, 0, 0, 0},
        {"P3", 8, 0, 0, 0, 0},
        {"P4", 3, 0, 0, 0, 0}
    };
    
    int n = sizeof(proc) / sizeof(proc[0]);  // Number of processes
    int timeQuantum = 3;  // Time Quantum
    
    printf("Round Robin CPU Scheduling\n");
    printf("----------------------------\n");
    
    // Perform Round Robin Scheduling
    roundRobin(proc, n, timeQuantum);
    
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct process {
    int pid, AT, BT, WT, TAT;
};

struct process a[10];

int queue[100];
int front = -1, rear = -1;

/* Function Prototypes */
void inputArrivalTime(int n, int *arrivalTime);
void inputBurstTime(int n, int *burstTime, int *p);
void swap(int *x, int *y);
void sortingFCFS(int *p, int n, int *arrivalTime, int *burstTime);
void sortingSJF(int n, int *at, int *bt, int *p);
float calculateAvgTATime(int *TATime, int n);
float calculateAvgWaitingTime(int *WaitingTime, int n);

void FCFS(int n, int *TATime, int *arrivalTime,
          int *burstTime, int *waitingTime, int *p);

void SJF(int n, int *TATime, int *arrivalTime,
         int *burstTime, int *waitingTime, int *p);

void SRTN(int n);
void RR(int n);

void insert(int n);
int delete();

int main() {
    int choice;

    while (1) {

        printf("\nProcess Scheduling Algorithms\n");
        printf("1. First Come First Serve\n");
        printf("2. Shortest Job First (Non-Preemptive)\n");
        printf("3. Shortest Remaining Time Next\n");
        printf("4. Round Robin\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 5) {
            printf("Program Terminated.\n");
            break;
        }

        int n;

        printf("Enter number of processes: ");
        scanf("%d", &n);

        if (n <= 0 || n > 10) {
            printf("Please enter a value between 1 and 10.\n");
            continue;
        }

        int *arrivalTime = (int *)malloc(n * sizeof(int));
        int *burstTime = (int *)malloc(n * sizeof(int));
        int *waitingTime = (int *)malloc(n * sizeof(int));
        int *TATime = (int *)malloc(n * sizeof(int));
        int *Process = (int *)malloc(n * sizeof(int));

        if (!arrivalTime || !burstTime || !waitingTime ||
            !TATime || !Process) {
            printf("Memory Allocation Failed!\n");
            return 1;
        }

        switch (choice) {

        case 1:
            printf("\n===== FCFS =====\n");
            inputArrivalTime(n, arrivalTime);
            inputBurstTime(n, burstTime, Process);
            FCFS(n, TATime, arrivalTime,
                 burstTime, waitingTime, Process);
            break;

        case 2:
            printf("\n===== SJF =====\n");
            inputArrivalTime(n, arrivalTime);
            inputBurstTime(n, burstTime, Process);
            SJF(n, TATime, arrivalTime,
                burstTime, waitingTime, Process);
            break;

        case 3:
            printf("\n===== SRTN =====\n");
            SRTN(n);
            break;

        case 4:
            printf("\n===== ROUND ROBIN =====\n");
            RR(n);
            break;

        default:
            printf("Invalid Choice!\n");
        }

        free(arrivalTime);
        free(burstTime);
        free(waitingTime);
        free(TATime);
        free(Process);
    }

    return 0;
}

/*================ Utility Functions ================*/

void inputArrivalTime(int n, int *arrivalTime) {

    printf("Enter Arrival Times:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arrivalTime[i]);
}

void inputBurstTime(int n, int *burstTime, int *p) {

    printf("Enter Burst Times:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &burstTime[i]);
        p[i] = i + 1;
    }
}

void swap(int *x, int *y) {

    int temp = *x;
    *x = *y;
    *y = temp;
}

void sortingFCFS(int *p, int n,
                 int *arrivalTime,
                 int *burstTime) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (arrivalTime[i] > arrivalTime[j]) {

                swap(&p[i], &p[j]);
                swap(&arrivalTime[i], &arrivalTime[j]);
                swap(&burstTime[i], &burstTime[j]);
            }
        }
    }
}

void sortingSJF(int n, int *at, int *bt, int *p) {

    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (at[i] > at[j] ||
               (at[i] == at[j] && bt[i] > bt[j])) {

                swap(&p[i], &p[j]);
                swap(&at[i], &at[j]);
                swap(&bt[i], &bt[j]);
            }
        }
    }
}

float calculateAvgTATime(int *TATime, int n) {

    float sum = 0;

    for (int i = 0; i < n; i++)
        sum += TATime[i];

    return sum / n;
}

float calculateAvgWaitingTime(int *WaitingTime, int n) {

    float sum = 0;

    for (int i = 0; i < n; i++)
        sum += WaitingTime[i];

    return sum / n;
}
/*================ FCFS ================*/

void FCFS(int n, int *TATime, int *arrivalTime,
          int *burstTime, int *waitingTime, int *p)
{
    int *completionTime = (int *)malloc(n * sizeof(int));

    sortingFCFS(p, n, arrivalTime, burstTime);

    completionTime[0] = arrivalTime[0] + burstTime[0];

    for (int i = 1; i < n; i++) {

        if (completionTime[i - 1] < arrivalTime[i])
            completionTime[i] = arrivalTime[i] + burstTime[i];
        else
            completionTime[i] = completionTime[i - 1] + burstTime[i];
    }

    printf("\nProcess\tArrival\tBurst\tCompletion\tTAT\tWaiting\n");

    for (int i = 0; i < n; i++) {

        TATime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = TATime[i] - burstTime[i];

        printf("P[%d]\t%d\t%d\t%d\t\t%d\t%d\n",
               p[i],
               arrivalTime[i],
               burstTime[i],
               completionTime[i],
               TATime[i],
               waitingTime[i]);
    }

    printf("\nAverage Waiting Time = %.2f",
           calculateAvgWaitingTime(waitingTime, n));

    printf("\nAverage Turnaround Time = %.2f\n",
           calculateAvgTATime(TATime, n));

    free(completionTime);
}


/*================ SJF (Non-Preemptive) ================*/

void SJF(int n, int *TATime, int *arrivalTime,
         int *burstTime, int *waitingTime, int *p)
{
    int *completionTime = (int *)malloc(n * sizeof(int));

    /* Correct function call */
    sortingSJF(n, arrivalTime, burstTime, p);

    completionTime[0] = arrivalTime[0] + burstTime[0];

    for (int i = 1; i < n; i++) {

        int pos = i;
        int min = burstTime[i];

        for (int j = i;
             j < n && arrivalTime[j] <= completionTime[i - 1];
             j++) {

            if (burstTime[j] < min) {
                min = burstTime[j];
                pos = j;
            }
        }

        swap(&p[i], &p[pos]);
        swap(&arrivalTime[i], &arrivalTime[pos]);
        swap(&burstTime[i], &burstTime[pos]);

        if (completionTime[i - 1] < arrivalTime[i])
            completionTime[i] = arrivalTime[i] + burstTime[i];
        else
            completionTime[i] = completionTime[i - 1] + burstTime[i];
    }

    printf("\nProcess\tArrival\tBurst\tCompletion\tTAT\tWaiting\n");

    for (int i = 0; i < n; i++) {

        TATime[i] = completionTime[i] - arrivalTime[i];
        waitingTime[i] = TATime[i] - burstTime[i];

        printf("P[%d]\t%d\t%d\t%d\t\t%d\t%d\n",
               p[i],
               arrivalTime[i],
               burstTime[i],
               completionTime[i],
               TATime[i],
               waitingTime[i]);
    }

    printf("\nAverage Waiting Time = %.2f",
           calculateAvgWaitingTime(waitingTime, n));

    printf("\nAverage Turnaround Time = %.2f\n",
           calculateAvgTATime(TATime, n));

    free(completionTime);
}
/*================ SRTN (Preemptive SJF) ================*/

void SRTN(int n)
{
    int arrival[10], burst[10], remaining[10], completion[10];
    bool finished[10] = {false};

    int time = 0;
    int completed = 0;

    float totalWT = 0;
    float totalTAT = 0;

    printf("Enter Arrival Times:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arrival[i]);

    printf("Enter Burst Times:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &burst[i]);
        remaining[i] = burst[i];
    }

    printf("\nProcess\tArrival\tBurst\tCompletion\tTAT\tWaiting\n");

    while (completed != n) {

        int shortest = -1;
        int minimum = 1000000;

        for (int i = 0; i < n; i++) {

            if (!finished[i] &&
                arrival[i] <= time &&
                remaining[i] > 0 &&
                remaining[i] < minimum) {

                minimum = remaining[i];
                shortest = i;
            }
        }

        if (shortest == -1) {
            time++;
            continue;
        }

        remaining[shortest]--;
        time++;

        if (remaining[shortest] == 0) {

            completion[shortest] = time;
            finished[shortest] = true;
            completed++;

            int tat = completion[shortest] - arrival[shortest];
            int wt = tat - burst[shortest];

            totalTAT += tat;
            totalWT += wt;

            printf("P[%d]\t%d\t%d\t%d\t\t%d\t%d\n",
                   shortest + 1,
                   arrival[shortest],
                   burst[shortest],
                   completion[shortest],
                   tat,
                   wt);
        }
    }

    printf("\nAverage Waiting Time = %.2f",
           totalWT / n);

    printf("\nAverage Turnaround Time = %.2f\n",
           totalTAT / n);
}


/*================ Queue Functions ================*/

void insert(int x)
{
    if (front == -1)
        front = 0;

    queue[++rear] = x;
}

int delete()
{
    return queue[front++];
}


/*================ Round Robin ================*/

void RR(int n)
{
    int temp[10];
    int exist[10] = {0};

    int TIME = 0;
    int TQ;

    float totalWT = 0;
    float totalTAT = 0;

    front = rear = -1;

    printf("Enter Arrival Times:\n");
    for (int i = 0; i < n; i++) {

        scanf("%d", &a[i].AT);
        a[i].pid = i + 1;
    }

    printf("Enter Burst Times:\n");
    for (int i = 0; i < n; i++) {

        scanf("%d", &a[i].BT);
        temp[i] = a[i].BT;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &TQ);

    insert(0);
    exist[0] = 1;

    while (front <= rear) {

        int p = delete();

        if (a[p].BT > TQ) {

            a[p].BT -= TQ;
            TIME += TQ;

        } else {

            TIME += a[p].BT;
            a[p].BT = 0;
        }

        for (int i = 0; i < n; i++) {

            if (!exist[i] && a[i].AT <= TIME) {

                insert(i);
                exist[i] = 1;
            }
        }

        if (a[p].BT == 0) {

            a[p].TAT = TIME - a[p].AT;
            a[p].WT = a[p].TAT - temp[p];

            totalWT += a[p].WT;
            totalTAT += a[p].TAT;

        } else {

            insert(p);
        }
    }

    printf("\nProcess\tArrival\tBurst\tTAT\tWaiting\n");

    for (int i = 0; i < n; i++) {

        printf("P[%d]\t%d\t%d\t%d\t%d\n",
               a[i].pid,
               a[i].AT,
               temp[i],
               a[i].TAT,
               a[i].WT);
    }

    printf("\nAverage Waiting Time = %.2f",
           totalWT / n);

    printf("\nAverage Turnaround Time = %.2f\n",
           totalTAT / n);
}

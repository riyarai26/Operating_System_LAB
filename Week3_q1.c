// FCFS: FIRST COME FIRST SERVE

#include <stdio.h>

typedef struct Process
{
    int pid, bt, at, wt, tat;
} process;

int main()
{
    int n, i, j;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    process p[n];

    printf("Enter Burst Times: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i].bt);
        p[i].pid = i + 1;
    }

    printf("Enter Arrival Times: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i].at);
    }

    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (p[i].at > p[j].at || (p[i].at == p[j].at && p[i].pid > p[j].pid))
            {
                process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int time = 0;
    printf("\nGantt Chart:\n");
    for (i = 0; i < n; i++)
    {
        if (time < p[i].at)
        {
            time = p[i].at;
        }
        printf("| P%d (%d-%d) ", p[i].pid, time, time + p[i].bt);
        p[i].wt = time - p[i].at;
        time += p[i].bt;
        p[i].tat = p[i].wt + p[i].bt;
    }
    printf("|\n");

    for (i = 0; i < n; i++)
    {
        avgWT += p[i].wt;
        avgTAT += p[i].tat;
    }

    printf("Average Waiting Time: %.2f\n", avgWT / n);
    printf("Average TurnAround Time: %.2f\n", avgTAT / n);
}

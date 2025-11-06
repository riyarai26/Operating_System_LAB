// SJF NON-PREEMPTIVE

#include <stdio.h>

struct process
{
    int pid, bt, at, wt, tat;
};

int main()
{
    int n, completed = 0, time = 0;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];
    int finished[n];

    printf("Enter Burst Times: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i].bt);
        p[i].pid = i + 1;
        finished[i] = 0;
    }

    printf("Enter Arrival Times: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i].at);

    printf("\nGantt Chart:\n");
    while (completed < n)
    {
        int idx = -1, min = 9999;
        for (int i = 0; i < n; i++)
            if (!finished[i] && p[i].at <= time && p[i].bt < min)
            {
                min = p[i].bt;
                idx = i;
            }

        if (idx == -1)
        {
            time++;
            continue;
        }

        printf("| P%d (%d-%d) ", p[idx].pid, time, time + p[idx].bt);
        p[idx].wt = time - p[idx].at;
        time += p[idx].bt;
        p[idx].tat = p[idx].wt + p[idx].bt;
        finished[idx] = 1;
        completed++;
    }
    printf("|\n");

    for (int i = 0; i < n; i++)
    {
        avgWT += p[i].wt;
        avgTAT += p[i].tat;
    }

    printf("Average Waiting Time: %.2f\n", avgWT / n);
    printf("Average TurnAround Time: %.2f\n", avgTAT / n);
}

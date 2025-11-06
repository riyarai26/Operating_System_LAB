// Priority Scheduling (Non-Preemptive)

#include <stdio.h>

typedef struct Process
{
    int pid, bt, at, pr, ct, wt, tat;
} process;

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    process p[n];

    printf("Enter burst times: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i].bt);

    printf("Enter arrival times: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i].at);

    printf("Enter priorities (lower number means higher priority): ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i].pr);
        p[i].pid = i + 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[i].at > p[j].at)
            {
                process t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }

    int time = 0, completed = 0, min, idx;
    printf("\nGantt Chart:\n");
    printf("0");

    while (completed < n)
    {
        min = 9999;
        idx = -1;
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= time && p[i].pr < min && p[i].ct == 0)
            {
                min = p[i].pr;
                idx = i;
            }
        }
        if (idx == -1)
        {
            time++;
            continue;
        }
        time += p[idx].bt;
        p[idx].ct = time;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;
        completed++;

        printf(" -> P%d(%d)", p[idx].pid, time);
    }

    float avgWT = 0, avgTAT = 0;
    for (int i = 0; i < n; i++)
    {
        avgWT += p[i].wt;
        avgTAT += p[i].tat;
    }

    printf("\nAverage Waiting Time = %.2f", avgWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);
}

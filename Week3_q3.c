// SJF PREEMPTIVE

#include <stdio.h>

struct process
{
    int pid, bt, at, wt, tat, rt;
};

int main()
{
    int n, i, time = 0, completed = 0;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct process p[n];

    printf("Enter Burst Times: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].pid = i + 1;
    }

    printf("Enter Arrival Times: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i].at);
    }

    printf("\nGantt Chart:\n");

    int prev = -1;
    while (completed < n)
    {
        int idx = -1, min = 9999;
        for (i = 0; i < n; i++)
        {
            if (p[i].at <= time && p[i].rt > 0 && p[i].rt < min)
            {
                min = p[i].rt;
                idx = i;
            }
        }

        if (idx == -1)
        {
            time++;
            continue;
        }

        if (prev != idx)
        {
            printf("| P%d (%d-", p[idx].pid, time);
        }
            
        p[idx].rt--;
        time++;

        if (p[idx].rt == 0)
        {
            printf("%d) ", time);
            completed++;
            p[idx].tat = time - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
        }
        prev = idx;
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

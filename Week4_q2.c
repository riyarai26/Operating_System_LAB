// Round Robin Scheduling

#include <stdio.h>

typedef struct Process
{
    int pid, bt, at, ct, wt, tat, rt;
}process;

int main()
{
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    process p[n];

    printf("Enter burst times: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i].bt);

    printf("Enter arrival times: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i].at);
        p[i].pid = i + 1;
        p[i].rt = p[i].bt;
        p[i].ct = 0;
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int time = 0, completed = 0;
    printf("\nGantt Chart:\n");
    printf("%d", time);

    while (completed < n)
    {
        int executed = 0;
        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= time && p[i].rt > 0)
            {
                if (p[i].rt > tq)
                {
                    time += tq;
                    p[i].rt -= tq;
                }
                else
                {
                    time += p[i].rt;
                    p[i].ct = time;
                    p[i].rt = 0;
                    completed++;
                }
                printf(" -> P%d(%d)", p[i].pid, time);
                executed = 1;
            }
        }
        if (!executed)
        {
            time++;
        }
    }

    float avgWT = 0, avgTAT = 0;
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
        avgWT += p[i].wt;
        avgTAT += p[i].tat;
    }

    printf("\nAverage Waiting Time = %.2f", avgWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);
}

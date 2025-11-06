// Banker's Algorithm (Deadlock Avoidance)

#include <stdio.h>
int main() {
    int p, r;
    printf("Enter number of processes: ");
    scanf("%d", &p);
    printf("Enter number of resources: ");
    scanf("%d", &r);

    int max[p][r], alloc[p][r], need[p][r], avail[r];
    int total[r], finished[p], safeSeq[p];
    
    printf("\nEnter Maximum Requirement Matrix:\n");
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            scanf("%d", &max[i][j]);
        }
    } 
    printf("\nEnter Allocation Matrix:\n");
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    printf("\nEnter Total Resources of each type:\n");
    for(int j=0;j<r;j++)
    {
        scanf("%d", &total[j]);
    }

    for(int j=0;j<r;j++) 
    {
        int sum = 0;
        for(int i=0;i<p;i++)
        {
            sum += alloc[i][j];
        }
        avail[j] = total[j] - sum;
    }

    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    for(int i=0;i<p;i++)
    {
        finished[i] = 0;
    }

    int count = 0;
    while(count < p) 
    {
        int found = 0;
        
        for(int i=0;i<p;i++) 
        {
            if(!finished[i]) 
            {
                int j;
                for(j=0;j<r;j++) 
                {
                    if(need[i][j] > avail[j])
                        break;
                }
                if(j == r) 
                {
                    for(int k=0;k<r;k++)
                    {
                        avail[k] += alloc[i][k];
                    }

                    safeSeq[count++] = i;
                    finished[i] = 1;
                    found = 1;
                }
            }
        }

        if(!found) {
            printf("\nRequest cannot be fulfilled (System is in Deadlock state)\n");
            return 0;
        }
    }

    printf("\nRequest can be fulfilled\nSafe Sequence: ");
    for(int i=0;i<p;i++)
    {
        printf("P%d ", safeSeq[i]);
    }
    printf("\n");

    return 0;
}

#include <stdio.h>
int main()
{
    int nb, np;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &nb);
    int blockSize[nb], blockAllocated[nb];
    printf("Enter the size of each memory block:\n");
    for (int i = 0; i < nb; i++)
    {
        scanf("%d", &blockSize[i]);
        blockAllocated[i] = 0;
    }
    printf("\nEnter the number of processes: ");
    scanf("%d", &np);
    int processSize[np], allocation[np];
    printf("Enter the size of each process:\n");
    for (int i = 0; i < np; i++)
    {
        scanf("%d", &processSize[i]);
        allocation[i] = -1;
    }
    for (int i = 0; i < np; i++)
    {
        int bestIdx = -1;
        for (int j = 0; j < nb; j++)
        {
            if (blockSize[j] >= processSize[i])
            {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1)
        {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < np; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
    return 0;
}

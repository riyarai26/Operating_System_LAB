#include <stdio.h> int main() {
int nb, np;

printf("Enter number of memory blocks: ");
scanf("%d", &nb);

int blockSize[nb], processSize[100], allocation[100];

printf("Enter size of each memory block:\n");
for (int i = 0; i < nb; i++)
{
    scanf("%d", &blockSize[i]);
}

printf("\nEnter number of processes: ");
scanf("%d", &np);

printf("Enter size of each process:\n");
for (int i = 0; i < np; i++)
{
    scanf("%d", &processSize[i]);
    allocation[i] = -1;
}
for (int i = 0; i < np; i++)
{
    for (int j = 0; j < nb; j++)
    {
        if (blockSize[j] >= processSize[i])
        {
            allocation[i] = j;
            blockSize[j] -= processSize[i];
            break;
        }
    }
}
printf("\nProcess No.\tProcess Size\tBlock Allocated\n");
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

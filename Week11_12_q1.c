#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, head, total_seek = 0;
    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    int req[n];
    printf("Enter the track numbers: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }
    printf("Enter initial head position: ");
    scanf("%d", &head);
    for (int i = 0; i < n; i++)
    {
        total_seek += abs(head - req[i]);
        head = req[i];
    }
    printf("\nTotal Seek Movement (FCFS): %d\n", total_seek);
    return 0;
}

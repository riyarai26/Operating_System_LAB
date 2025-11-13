#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{
    int n, head, disk_size, direction;
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
    printf("Enter disk size: ");
    scanf("%d", &disk_size);
    printf("Enter direction (1 for high, 0 for low): ");
    scanf("%d", &direction);
    sort(req, n);
    int total_seek = 0;
    int pos = 0;
    for (int i = 0; i < n; i++)
    {
        if (req[i] > head)
        {
            pos = i;
            break;
        }
    }
    if (direction == 1)
    {
        for (int i = pos; i < n; i++)
        {
            total_seek += abs(head - req[i]);
            head = req[i];
        }
        total_seek += abs((disk_size - 1) - head);
        total_seek += (disk_size - 1);
        head = 0;

        for (int i = 0; i < pos; i++)
        {
            total_seek += abs(head - req[i]);
            head = req[i];
        }
    }
    else
    {
        for (int i = pos - 1; i >= 0; i--)
        {
            total_seek += abs(head - req[i]);
            head = req[i];
        }
        total_seek += abs(head - 0);
        total_seek += (disk_size - 1);
        head = disk_size - 1;
        for (int i = n - 1; i >= pos; i--)
        {
            total_seek += abs(head - req[i]);
            head = req[i];
        }
    }
    printf("\nTotal Seek Movement (C-SCAN): %d\n", total_seek);
    return 0;
}

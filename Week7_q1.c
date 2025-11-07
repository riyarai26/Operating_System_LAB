#include <stdio.h>
int main()
{
    int n, sz;
    printf("Enter number of frames available: ");
    scanf("%d", &sz);
    printf("Enter number of page requests: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the page reference string:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int mem[sz];
    for (int i = 0; i < sz; i++)
    {
        mem[i] = -1;
    }
    int last = 0;
    int hit = 0, miss = 0;
    for (int j = 0; j < n; j++)
    {
        int page = arr[j];
        int flag = 0;
        for (int i = 0; i < sz; i++)
        {
            if (mem[i] == page)
            {
                hit++;
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            miss++;
            mem[last] = page;
            last = (last + 1) % sz;
        }
        printf("After accessing %d: ", page);
        for (int i = 0; i < sz; i++)
        {
            if (mem[i] == -1)
                printf("- ");
            else
                printf("%d ", mem[i]);
        }
        printf("\n");
    }
    printf("\nTotal Hits: %d\n", hit);
    printf("Total Misses (Page Faults): %d\n", miss);
    return 0;
}

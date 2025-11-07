#include <stdio.h>
int main()
{
    int n, frames;
    printf("Enter number of frames available: ");
    scanf("%d", &frames);
    printf("Enter number of page requests: ");
    scanf("%d", &n);
    int pages[n];
    printf("Enter the page reference string:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &pages[i]);
    int mem[frames];
    int recent[frames];
    int hit = 0, miss = 0;
    for (int i = 0; i < frames; i++)
    {
        mem[i] = -1;
        recent[i] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        int page = pages[i];
        int found = 0;
        for (int j = 0; j < frames; j++)
        {
            if (mem[j] == page)
            {
                hit++;
                found = 1;
                recent[j] = i;
                break;
            }
        }
        if (!found)
        {
            miss++;
            int empty = -1;
            for (int j = 0; j < frames; j++)
            {
                if (mem[j] == -1)
                {
                    empty = j;
                    break;
                }
            }
            if (empty != -1)
            {
                mem[empty] = page;
                recent[empty] = i;
            }
            else
            {
                int lruIndex = 0;
                for (int j = 1; j < frames; j++)
                {
                    if (recent[j] < recent[lruIndex])
                        lruIndex = j;
                }
                mem[lruIndex] = page;
                recent[lruIndex] = i;
            }
        }
        printf("After accessing %d: ", page);
        for (int j = 0; j < frames; j++)
        {
            if (mem[j] == -1)
                printf("- ");
            else
                printf("%d ", mem[j]);
        }
        printf("\n");
    }
    printf("\nTotal Page Hits: %d\n", hit);
    printf("Total Page Faults (Misses): %d\n", miss);
    return 0;
}

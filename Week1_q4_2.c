// ZOMBIE PROCESS
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int pid = fork();
    if (pid == 0)
    {
        printf("Child Completed Execution.\n");
        exit(0);
    }
    else
    {
        printf("Parent Sleeping... Child becomes Zombie for a moment.\n");
        sleep(10);
    }
    return 0;
}

// ORPHAN PROCESS

#include <stdio.h>
#include <unistd.h>
int main()
{
    int pid = fork();
    if (pid == 0)
    {
        sleep(5);
        printf("Child (Orphan) New Parent PID: %d\n", getppid());
    }
    else
    {
        printf("Parent process exiting...\n");
    }
    return 0;
}

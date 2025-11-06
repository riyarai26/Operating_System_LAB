// Parent Waits Until Child Completes (wait() & exit())

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
    int pid = fork();

    if (pid == 0)
    {
        printf("Child: My PID = %d\n", getpid());
        printf("Child: Exiting...\n");
        exit(0);
    }
    else
    {
        wait(NULL);
        printf("Parent: My PID = %d, Child Completed\n", getpid());
    }

    return 0;
}

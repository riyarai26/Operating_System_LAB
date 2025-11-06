// Print Parent and Child Process IDs
#include <stdio.h>
#include <unistd.h>

int main() 
{
    int pid;
    pid = fork();

    if(pid == 0) 
    {
        printf("Child Process ID: %d\n", getpid());
        printf("Parent Process ID of Child: %d\n", getppid());
    } 
    else 
    {
        printf("Parent Process ID: %d\n", getpid());
        printf("Child Process ID: %d\n", pid);
    }
    return 0;
}

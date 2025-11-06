#include <stdio.h>
#include <unistd.h>
int main()
{
    int pid = fork();
    if (pid == 0)
    {
        printf("Child Process Running ls command:\n");
        execlp("ls", "ls", NULL); 
        printf("execlp failed\n");
    }
    else
    {
        printf("Parent Process\n");
    }
    return 0;
}

// Using Pipe

#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
    int fd[2];
    char msg[] = "Hello from Child";
    char buffer[50];
    pipe(fd);
    if (fork() == 0)
    {
        close(fd[0]);
        write(fd[1], msg, strlen(msg) + 1);
        close(fd[1]);
    }
    else
    {
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("Parent received: %s\n", buffer);
        close(fd[0]);
    }
    return 0;
}

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    int f1, f2;
    char mydata[100], frienddata[100];
    pid_t pid;

    printf("Enter your details: ");
    fgets(mydata, 100, stdin);

    printf("Enter your friend's details: ");
    fgets(frienddata, 100, stdin);

    f1 = open("me.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    write(f1, mydata, strlen(mydata));
    close(f1);

    f2 = open("friend.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
    write(f2, frienddata, strlen(frienddata));
    close(f2);

    pid = fork();

    if (pid == 0)
    {
        printf("\nMatching Lines (if any):\n");
        execlp("grep", "grep", "-Fx", "-f", "me.txt", "friend.txt", NULL);
        printf("grep failed\n");
    }
    else
    {
        wait(NULL);
        printf("\nParent Finished.\n");
    }

    return 0;
}

// Using Message Passing

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <unistd.h>

struct msg_buffer
{
    long msg_type;
    char msg[100];
} message;

int main()
{
    key_t key = ftok("msgfile", 65);
    int msgid = msgget(key, 0666 | IPC_CREAT);

    if (fork() == 0)
    {
        message.msg_type = 1;
        strcpy(message.msg, "Hello from Child");
        msgsnd(msgid, &message, sizeof(message), 0);
    }
    else
    {
        msgrcv(msgid, &message, sizeof(message), 1, 0);
        printf("Parent received : %s\n", message.msg);
        msgctl(msgid, IPC_RMID, NULL);
    }
    return 0;
}

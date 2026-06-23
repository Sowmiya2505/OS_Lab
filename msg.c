#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct message
{
    long type;
    char text[100];
};

int main()
{
    int msgid;
    struct message msg;

    msgid = msgget(1234, 0666 | IPC_CREAT);

    msg.type = 1;

    strcpy(msg.text, "Hello Queue");

    msgsnd(msgid, &msg, sizeof(msg.text), 0);

    msgrcv(msgid, &msg, sizeof(msg.text), 1, 0);

    printf("%s\n", msg.text);

    return 0;
}

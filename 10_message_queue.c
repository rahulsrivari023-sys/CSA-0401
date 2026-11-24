#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
struct message { long type; char text[100]; };
int main(void) {
    int q=msgget(IPC_PRIVATE,IPC_CREAT|0600);if(q<0){perror("msgget");return 1;}
    struct message m={.type=1};strcpy(m.text,"Hello through System V message queue");
    if(msgsnd(q,&m,sizeof m.text,0)<0){perror("msgsnd");msgctl(q,IPC_RMID,NULL);return 1;}
    memset(&m,0,sizeof m);if(msgrcv(q,&m,sizeof m.text,1,0)<0){perror("msgrcv");msgctl(q,IPC_RMID,NULL);return 1;}
    printf("Received: %s\n",m.text);msgctl(q,IPC_RMID,NULL);return 0;
}

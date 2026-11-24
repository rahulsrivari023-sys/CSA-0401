#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main(void) {
    int id=shmget(IPC_PRIVATE,1024,IPC_CREAT|0600); if(id<0){perror("shmget");return 1;}
    char *data=(char*)shmat(id,NULL,0); if(data==(void*)-1){perror("shmat");return 1;}
    pid_t p=fork();
    if(p==0){snprintf(data,1024,"Message written by child process %ld",(long)getpid());shmdt(data);_exit(0);}
    if(p<0){perror("fork");return 1;}
    wait(NULL);printf("Parent read: %s\n",data);shmdt(data);shmctl(id,IPC_RMID,NULL);return 0;
}

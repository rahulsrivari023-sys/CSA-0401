#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void) {
    pid_t pid = fork();
    if (pid < 0) { perror("fork"); return 1; }
    if (pid == 0)
        printf("Child: PID=%ld, PPID=%ld\n", (long)getpid(), (long)getppid());
    else {
        printf("Parent: PID=%ld, Child PID=%ld\n", (long)getpid(), (long)pid);
        wait(NULL);
    }
    return 0;
}

#include <stdio.h>
#include <pthread.h>
void *task(void *arg) { printf("Thread %ld is running\n",(long)arg); return NULL; }
int main(void) {
    pthread_t t[3];
    for(long i=0;i<3;i++)if(pthread_create(&t[i],NULL,task,(void*)i)!=0){perror("pthread_create");return 1;}
    for(int i=0;i<3;i++)pthread_join(t[i],NULL);
    return 0;
}

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
sem_t mutex,wrt;int readers=0,data=0;
void *reader(void *arg){sem_wait(&mutex);readers++;if(readers==1)sem_wait(&wrt);sem_post(&mutex);printf("Reader reads %d\n",data);sem_wait(&mutex);readers--;if(readers==0)sem_post(&wrt);sem_post(&mutex);return NULL;}
void *writer(void *arg){sem_wait(&wrt);data++;printf("Writer updates data to %d\n",data);sem_post(&wrt);return NULL;}
int main(void){pthread_t r[3],w[2];sem_init(&mutex,0,1);sem_init(&wrt,0,1);for(int i=0;i<3;i++)pthread_create(&r[i],NULL,reader,NULL);for(int i=0;i<2;i++)pthread_create(&w[i],NULL,writer,NULL);for(int i=0;i<3;i++)pthread_join(r[i],NULL);for(int i=0;i<2;i++)pthread_join(w[i],NULL);sem_destroy(&mutex);sem_destroy(&wrt);return 0;}

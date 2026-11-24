#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define SIZE 5
int buffer[SIZE],in=0,out=0;
sem_t empty,full;pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
void *producer(void *x){for(int i=1;i<=10;i++){sem_wait(&empty);pthread_mutex_lock(&mutex);buffer[in]=i;printf("Produced %d\n",i);in=(in+1)%SIZE;pthread_mutex_unlock(&mutex);sem_post(&full);}return NULL;}
void *consumer(void *x){for(int i=1;i<=10;i++){sem_wait(&full);pthread_mutex_lock(&mutex);int v=buffer[out];printf("Consumed %d\n",v);out=(out+1)%SIZE;pthread_mutex_unlock(&mutex);sem_post(&empty);}return NULL;}
int main(void){pthread_t p,c;sem_init(&empty,0,SIZE);sem_init(&full,0,0);pthread_create(&p,NULL,producer,NULL);pthread_create(&c,NULL,consumer,NULL);pthread_join(p,NULL);pthread_join(c,NULL);sem_destroy(&empty);sem_destroy(&full);return 0;}

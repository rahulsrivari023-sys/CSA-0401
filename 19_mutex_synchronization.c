#include <stdio.h>
#include <pthread.h>
#define THREADS 4
long counter=0;pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
void *increment(void *arg){for(int i=0;i<100000;i++){pthread_mutex_lock(&lock);counter++;pthread_mutex_unlock(&lock);}return NULL;}
int main(void){pthread_t t[THREADS];for(int i=0;i<THREADS;i++)pthread_create(&t[i],NULL,increment,NULL);for(int i=0;i<THREADS;i++)pthread_join(t[i],NULL);printf("Final counter = %ld\n",counter);pthread_mutex_destroy(&lock);return 0;}

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#define N 5
sem_t forks[N];
void *dine(void *x){int i=(int)(long)x,l=i,r=(i+1)%N;for(int k=0;k<1;k++){if(i%2){sem_wait(&forks[r]);sem_wait(&forks[l]);}else{sem_wait(&forks[l]);sem_wait(&forks[r]);}printf("Philosopher %d eats\n",i);sem_post(&forks[l]);sem_post(&forks[r]);}return NULL;}
int main(void){pthread_t t[N];for(int i=0;i<N;i++)sem_init(&forks[i],0,1);for(long i=0;i<N;i++)pthread_create(&t[i],NULL,dine,(void*)i);for(int i=0;i<N;i++)pthread_join(t[i],NULL);for(int i=0;i<N;i++)sem_destroy(&forks[i]);return 0;}

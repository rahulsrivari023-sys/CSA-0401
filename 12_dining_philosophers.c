#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define N 5
sem_t forks[N];
void *philosopher(void *arg) {
    int id=(int)(long)arg,left=id,right=(id+1)%N;
    for(int k=0;k<2;k++){
        printf("Philosopher %d is thinking\n",id);
        if(id%2==0){sem_wait(&forks[left]);sem_wait(&forks[right]);}
        else {sem_wait(&forks[right]);sem_wait(&forks[left]);}
        printf("Philosopher %d is eating\n",id);
        sem_post(&forks[left]);sem_post(&forks[right]);
    } return NULL;
}
int main(void) {
    pthread_t t[N];for(int i=0;i<N;i++)sem_init(&forks[i],0,1);
    for(long i=0;i<N;i++)pthread_create(&t[i],NULL,philosopher,(void*)i);
    for(int i=0;i<N;i++)pthread_join(t[i],NULL);
    for(int i=0;i<N;i++)sem_destroy(&forks[i]);return 0;
}

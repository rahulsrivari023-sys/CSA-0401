#include <stdio.h>
#include <pthread.h>
void *worker(void *x){printf("Worker thread executing\n");pthread_exit((void*)42);}
int main(void){pthread_t t1,t2;void *result;pthread_create(&t1,NULL,worker,NULL);pthread_create(&t2,NULL,worker,NULL);printf("pthread_equal: %s\n",pthread_equal(t1,t2)?"equal":"not equal");pthread_join(t1,&result);pthread_join(t2,NULL);printf("Thread 1 returned %ld\n",(long)result);return 0;}

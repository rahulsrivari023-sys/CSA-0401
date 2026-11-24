#include <stdio.h>
#include <stdlib.h>
int main(void){int n,req[100],head,total=0;printf("Number of requests: ");scanf("%d",&n);if(n<1||n>100)return 1;printf("Request queue: ");for(int i=0;i<n;i++)scanf("%d",&req[i]);printf("Initial head: ");scanf("%d",&head);printf("Seek sequence: %d",head);for(int i=0;i<n;i++){total+=abs(head-req[i]);head=req[i];printf(" -> %d",head);}printf("\nTotal head movement = %d\n",total);return 0;}

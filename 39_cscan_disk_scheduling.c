#include <stdio.h>
#include <stdlib.h>
int cmp2(const void*a,const void*b){return *(int*)a-*(int*)b;}
int main(void){int n,r[100],head,size,total=0;printf("Requests and disk size: ");scanf("%d%d",&n,&size);if(n<1||n>100||size<2)return 1;printf("Request queue: ");for(int i=0;i<n;i++)scanf("%d",&r[i]);printf("Initial head: ");scanf("%d",&head);qsort(r,n,sizeof(int),cmp2);printf("Seek sequence: %d",head);for(int i=0;i<n;i++)if(r[i]>=head){total+=abs(head-r[i]);head=r[i];printf(" -> %d",head);}total+=abs(head-(size-1));head=size-1;printf(" -> %d -> 0",head);total+=size-1;head=0;for(int i=0;i<n;i++)if(r[i]<head+1){total+=abs(head-r[i]);head=r[i];printf(" -> %d",head);}printf("\nTotal head movement = %d\n",total);return 0;}

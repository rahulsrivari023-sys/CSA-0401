#include <stdio.h>
int main(void) {
    int nb,np,b[50],p[50],choice,alloc[50];
    printf("Number of blocks and processes: ");scanf("%d%d",&nb,&np);if(nb<1||nb>50||np<1||np>50)return 1;
    for(int i=0;i<nb;i++){printf("Block %d size: ",i+1);scanf("%d",&b[i]);}
    for(int i=0;i<np;i++){printf("Process %d size: ",i+1);scanf("%d",&p[i]);alloc[i]=-1;}
    printf("1.First Fit 2.Best Fit 3.Worst Fit: ");scanf("%d",&choice);
    for(int i=0;i<np;i++){int k=-1;
        for(int j=0;j<nb;j++)if(b[j]>=p[i]&&(k==-1||(choice==2&&b[j]<b[k])||(choice==3&&b[j]>b[k]))) {k=j;if(choice==1)break;}
        if(k!=-1){alloc[i]=k;b[k]-=p[i];}
    }
    printf("Process\tSize\tBlock\n");for(int i=0;i<np;i++)printf("P%d\t%d\t%s%d\n",i+1,p[i],alloc[i]<0?"Not allocated (":"",alloc[i]<0?0:alloc[i]+1);
    return 0;
}

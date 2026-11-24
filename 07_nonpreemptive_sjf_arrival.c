#include <stdio.h>
int main(void) {
    int n, at[50], bt[50], done[50]={0}, ct[50], time=0, completed=0;
    printf("Number of processes: ");scanf("%d",&n);if(n<1||n>50)return 1;
    for(int i=0;i<n;i++){printf("P%d arrival and burst: ",i+1);scanf("%d%d",&at[i],&bt[i]);}
    while(completed<n){int k=-1;
        for(int i=0;i<n;i++)if(!done[i]&&at[i]<=time&&(k==-1||bt[i]<bt[k]))k=i;
        if(k==-1){time++;continue;} time+=bt[k];ct[k]=time;done[k]=1;completed++;
    }
    double sw=0,st=0;printf("Process\tAT\tBT\tWT\tTAT\n");
    for(int i=0;i<n;i++){int tat=ct[i]-at[i],wt=tat-bt[i];sw+=wt;st+=tat;printf("P%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],wt,tat);}
    printf("Average WT=%.2f\nAverage TAT=%.2f\n",sw/n,st/n);return 0;
}

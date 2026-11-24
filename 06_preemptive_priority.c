#include <stdio.h>
int main(void) {
    int n, at[50], bt[50], rem[50], pr[50], ct[50]={0}, time=0, done=0;
    printf("Number of processes: ");scanf("%d",&n);if(n<1||n>50)return 1;
    for(int i=0;i<n;i++){printf("P%d arrival burst priority (smaller = higher): ",i+1);scanf("%d%d%d",&at[i],&bt[i],&pr[i]);rem[i]=bt[i];}
    while(done<n){int k=-1;
        for(int i=0;i<n;i++)if(rem[i]>0&&at[i]<=time&&(k==-1||pr[i]<pr[k]))k=i;
        if(k==-1){time++;continue;}
        rem[k]--;time++;
        if(rem[k]==0){ct[k]=time;done++;}
    }
    double sw=0,st=0;printf("Process\tAT\tBT\tPriority\tWT\tTAT\n");
    for(int i=0;i<n;i++){int tat=ct[i]-at[i],wt=tat-bt[i];sw+=wt;st+=tat;printf("P%d\t%d\t%d\t%d\t\t%d\t%d\n",i+1,at[i],bt[i],pr[i],wt,tat);}
    printf("Average WT=%.2f\nAverage TAT=%.2f\n",sw/n,st/n);return 0;
}

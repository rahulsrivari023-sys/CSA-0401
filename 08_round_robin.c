#include <stdio.h>
int main(void) {
    int n,at[50],bt[50],rem[50],ct[50],q,time=0,done=0;
    printf("Number of processes: ");scanf("%d",&n);if(n<1||n>50)return 1;
    for(int i=0;i<n;i++){printf("P%d arrival and burst: ",i+1);scanf("%d%d",&at[i],&bt[i]);rem[i]=bt[i];}
    printf("Time quantum: ");scanf("%d",&q);if(q<=0)return 1;
    while(done<n){int progressed=0;
        for(int i=0;i<n;i++)if(rem[i]>0&&at[i]<=time){
            progressed=1;int run=rem[i]<q?rem[i]:q;rem[i]-=run;time+=run;
            if(rem[i]==0){ct[i]=time;done++;}
        }
        if(!progressed)time++;
    }
    double sw=0,st=0;printf("Process\tAT\tBT\tWT\tTAT\n");
    for(int i=0;i<n;i++){int tat=ct[i]-at[i],wt=tat-bt[i];sw+=wt;st+=tat;printf("P%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],wt,tat);}
    printf("Average WT=%.2f\nAverage TAT=%.2f\n",sw/n,st/n);return 0;
}

#include <stdio.h>
int main(void) {
    int n, bt[100], p[100], wt[100], tat[100]; float aw=0, aa=0;
    printf("Number of processes: "); scanf("%d",&n); if(n<1||n>100)return 1;
    for(int i=0;i<n;i++){p[i]=i+1; printf("Burst time P%d: ",p[i]); scanf("%d",&bt[i]);}
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) if(bt[j]<bt[i]) {
        int t=bt[i];bt[i]=bt[j];bt[j]=t; t=p[i];p[i]=p[j];p[j]=t;
    }
    wt[0]=0; for(int i=1;i<n;i++) wt[i]=wt[i-1]+bt[i-1];
    printf("Process\tBT\tWT\tTAT\n");
    for(int i=0;i<n;i++){tat[i]=wt[i]+bt[i];aw+=wt[i];aa+=tat[i];printf("P%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);}
    printf("Average WT=%.2f\nAverage TAT=%.2f\n",aw/n,aa/n); return 0;
}

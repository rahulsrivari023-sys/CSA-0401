#include <stdio.h>
int main(void) {
    int n, bt[100], wt[100], tat[100]; float aw=0, at=0;
    printf("Number of processes: "); scanf("%d",&n);
    if(n<1 || n>100) return 1;
    for(int i=0;i<n;i++){ printf("Burst time P%d: ",i+1); scanf("%d",&bt[i]); }
    wt[0]=0;
    for(int i=1;i<n;i++) wt[i]=wt[i-1]+bt[i-1];
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(int i=0;i<n;i++){ tat[i]=wt[i]+bt[i]; aw+=wt[i]; at+=tat[i]; printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]); }
    printf("Average WT=%.2f\nAverage TAT=%.2f\n",aw/n,at/n);
    return 0;
}

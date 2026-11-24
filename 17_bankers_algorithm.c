#include <stdio.h>
int main(void) {
    int n,m,alloc[10][10],max[10][10],need[10][10],avail[10],work[10],finish[10]={0},seq[10],count=0;
    printf("Processes and resource types: ");scanf("%d%d",&n,&m);if(n>10||m>10||n<1||m<1)return 1;
    printf("Allocation matrix:\n");for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",&alloc[i][j]);
    printf("Maximum matrix:\n");for(int i=0;i<n;i++)for(int j=0;j<m;j++){scanf("%d",&max[i][j]);need[i][j]=max[i][j]-alloc[i][j];}
    printf("Available resources: ");for(int j=0;j<m;j++){scanf("%d",&avail[j]);work[j]=avail[j];}
    while(count<n){int progress=0;for(int i=0;i<n;i++)if(!finish[i]){int ok=1;for(int j=0;j<m;j++)if(need[i][j]>work[j])ok=0;
        if(ok){for(int j=0;j<m;j++)work[j]+=alloc[i][j];seq[count++]=i;finish[i]=1;progress=1;}}
        if(!progress)break;
    }
    if(count==n){printf("Safe sequence: ");for(int i=0;i<n;i++)printf("P%d%s",seq[i],i==n-1?"\n":" -> ");}else puts("System is not in a safe state");
    return 0;
}

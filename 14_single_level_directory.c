#include <stdio.h>
#include <string.h>
int main(void) {
    char files[50][50],name[50];int n=0,ch,found;
    do{
        printf("\n1.Create 2.List 3.Delete 4.Exit\nChoice: ");scanf("%d",&ch);
        if(ch==1){printf("File name: ");scanf("%49s",name);found=0;for(int i=0;i<n;i++)if(!strcmp(files[i],name))found=1;
            if(found)puts("File already exists");else if(n==50)puts("Directory full");else strcpy(files[n++],name);
        }else if(ch==2){for(int i=0;i<n;i++)puts(files[i]);}
        else if(ch==3){printf("File name: ");scanf("%49s",name);found=0;for(int i=0;i<n;i++)if(!strcmp(files[i],name)){for(int j=i;j<n-1;j++)strcpy(files[j],files[j+1]);n--;found=1;break;}puts(found?"Deleted":"Not found");}
    }while(ch!=4);return 0;
}

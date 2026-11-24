#include <stdio.h>
#include <string.h>
#define U 10
#define F 20
int main(void) {
    char users[U][30],files[U][F][30];int counts[U]={0},nu=0,ch,u;char user[30],file[30];
    do{
        printf("\n1.Create user 2.Create file 3.List user files 4.Exit\nChoice: ");scanf("%d",&ch);
        if(ch==1){printf("Username: ");scanf("%29s",user);for(u=0;u<nu&&strcmp(users[u],user);u++);if(u==nu&&nu<U){strcpy(users[nu++],user);puts("User created");}else puts("User exists or directory full");}
        else if(ch==2){printf("Username and filename: ");scanf("%29s%29s",user,file);for(u=0;u<nu&&strcmp(users[u],user);u++);if(u==nu)puts("User not found");else if(counts[u]<F)strcpy(files[u][counts[u]++],file);else puts("Directory full");}
        else if(ch==3){printf("Username: ");scanf("%29s",user);for(u=0;u<nu&&strcmp(users[u],user);u++);if(u==nu)puts("User not found");else for(int j=0;j<counts[u];j++)puts(files[u][j]);}
    }while(ch!=4);return 0;
}

#include <stdio.h>
#include <unistd.h>
int main(void){int ch;char a[100],b[100];do{printf("\n1.Create 2.Delete 3.Rename 4.Exit\nChoice: ");scanf("%d",&ch);if(ch==1){printf("Filename: ");scanf("%99s",a);FILE*f=fopen(a,"w");if(f){puts("Created");fclose(f);}else perror("create");}else if(ch==2){printf("Filename: ");scanf("%99s",a);if(remove(a)==0)puts("Deleted");else perror("delete");}else if(ch==3){printf("Old and new filenames: ");scanf("%99s%99s",a,b);if(rename(a,b)==0)puts("Renamed");else perror("rename");}}while(ch!=4);return 0;}

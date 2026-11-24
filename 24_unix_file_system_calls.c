#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
int main(void){char name[100],buf[256];printf("Filename: ");scanf("%99s",name);int fd=open(name,O_CREAT|O_RDWR,0644);if(fd<0){perror("open");return 1;}printf("Enter text: ");int c;while((c=getchar())!='\n'&&c!=EOF);if(fgets(buf,sizeof buf,stdin))write(fd,buf,strlen(buf));lseek(fd,0,SEEK_SET);int n=read(fd,buf,sizeof(buf)-1);if(n>=0){buf[n]='\\0';printf("File content: %s",buf);}close(fd);return 0;}

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <dirent.h>
int main(int argc,char *argv[]){const char *path=argc>1?argv[1]:".";int fd=open(path,O_RDONLY);if(fd<0){perror("open");return 1;}int flags=fcntl(fd,F_GETFL);printf("fcntl flags: %d\n",flags);struct stat st;if(stat(path,&st)==0)printf("Size: %lld bytes, mode: %o\n",(long long)st.st_size,st.st_mode&0777);char buf[32];if(lseek(fd,0,SEEK_SET)>=0){ssize_t n=read(fd,buf,sizeof buf);printf("Read %ld bytes from beginning\n",(long)n);}close(fd);DIR *d=opendir(path);if(d){struct dirent *e;puts("Directory entries:");while((e=readdir(d)))puts(e->d_name);closedir(d);}else puts("Path is not an accessible directory");return 0;}

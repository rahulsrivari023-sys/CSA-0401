#include <stdio.h>
#include <dirent.h>
int main(int argc,char *argv[]){const char *path=argc>1?argv[1]:".";DIR*d=opendir(path);if(!d){perror("opendir");return 1;}struct dirent*e;while((e=readdir(d)))if(e->d_name[0]!='.')printf("%s\n",e->d_name);closedir(d);return 0;}

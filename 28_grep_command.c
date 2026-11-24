#include <stdio.h>
#include <string.h>
int main(int argc,char *argv[]){if(argc!=3){fprintf(stderr,"Usage: %s pattern filename\n",argv[0]);return 1;}FILE*f=fopen(argv[2],"r");if(!f){perror("fopen");return 1;}char line[2048];int n=0,found=0;while(fgets(line,sizeof line,f)){n++;if(strstr(line,argv[1])){printf("%d:%s",n,line);found=1;}}fclose(f);return found?0:1;}

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <pwd.h>
#include <grp.h>
int main(int argc,char *argv[]){const char *path=argc>1?argv[1]:"permission_demo.txt";FILE*f=fopen(path,"a");if(!f){perror("fopen");return 1;}fclose(f);struct stat st;if(stat(path,&st)<0){perror("stat");return 1;}printf("File: %s\nOwner UID: %ld (%s)\nGroup GID: %ld (%s)\n",path,(long)st.st_uid,getpwuid(st.st_uid)?getpwuid(st.st_uid)->pw_name:"unknown",(long)st.st_gid,getgrgid(st.st_gid)?getgrgid(st.st_gid)->gr_name:"unknown");printf("Permissions: %c%c%c %c%c%c %c%c%c\n",st.st_mode&S_IRUSR?'r':'-',st.st_mode&S_IWUSR?'w':'-',st.st_mode&S_IXUSR?'x':'-',st.st_mode&S_IRGRP?'r':'-',st.st_mode&S_IWGRP?'w':'-',st.st_mode&S_IXGRP?'x':'-',st.st_mode&S_IROTH?'r':'-',st.st_mode&S_IWOTH?'w':'-',st.st_mode&S_IXOTH?'x':'-');puts("Users: owner, group members, and others");puts("Permission classes: read (r), write (w), execute (x)");return 0;}

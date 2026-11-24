#include <stdio.h>
#include <string.h>
typedef struct { int id; char name[40]; double salary; } Employee;
int main(void) {
    FILE *fp=fopen("employees.dat","rb+");if(!fp)fp=fopen("employees.dat","wb+");if(!fp){perror("file");return 1;}
    int ch,id;Employee e;
    do{
        printf("\n1.Add/Update 2.Read by ID 3.List 4.Exit\nChoice: ");scanf("%d",&ch);
        if(ch==1){printf("ID name salary: ");scanf("%d%39s%lf",&e.id,e.name,&e.salary);fseek(fp,(long)(e.id-1)*sizeof e,SEEK_SET);fwrite(&e,sizeof e,1,fp);fflush(fp);}
        else if(ch==2){printf("ID: ");scanf("%d",&id);fseek(fp,(long)(id-1)*sizeof e,SEEK_SET);if(fread(&e,sizeof e,1,fp))printf("%d %s %.2f\n",e.id,e.name,e.salary);else puts("Record not found");}
        else if(ch==3){rewind(fp);while(fread(&e,sizeof e,1,fp))printf("%d %s %.2f\n",e.id,e.name,e.salary);}
    }while(ch!=4);fclose(fp);return 0;
}

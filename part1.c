#include <stdio.h>
#include <string.h>
void create_account(char *filename,long long int b[]);
void create_password(char *filename,char a[][101]);
void course_management(char *filename,char a[][101]);
int main(){
    printf("欢迎使用学生成绩管理系统.\n");
    printf("本系统使用数字化菜单，请输入对应服务的数字，按回车以确定。\n");
    beginning:;
    printf("----------学生管理系统----------\n");
    printf("1.学生账号注册     2.课程管理\n");
    printf("3.忘记or修改密码   4.账号查询     \n");
    printf("5.查看使用说明     6.退出系统\n");
    int index=0;
    long long int stu_idnum[100]={0},stu_phonenum[100]={0};
    char password[100][101];
    scanf("%d",&index);
    switch(index)
    {
        case 1:
        printf("------注册账号------\n");
        printf("请输入您的电话号码：");
        char temp1[]="stu_phonenum.txt";
        create_account(temp1,stu_phonenum);
        printf("\n");
        printf("请输入您的学号：");
        char temp2[]="stu_idnum.txt";
        create_account(temp2,stu_idnum);
        printf("\n");
        printf("请输入您的密码（为了确保密码的安全性，密码至少8位）：");
        char temp3[]="password.txt";
        create_password(temp3,password);
        printf("账号创建成功，请牢记您的账号与密码。");
        break;
        case 6:
        return 0;
        break;
        case2:
          printf("------课程管理------");
    }
    printf("请问是否还需要进行其他操作？");
    printf("需要请输1，不需要请输入2");
    int j = 0;
    scanf("%d",&j);
    if (j==1){
        goto beginning;
    }
    printf("感谢您的使用，再见！");
    return 0;
}

void course_management(char *filename,char a[][101]){
    int i=0;
    FILE *file;
    file = fopen (filename,"r");
    while(fscanf(file,"%100s",a[i])!=EOF)
    {i++;}
    fclose(file);
}
void create_password(char *filename,char a[][101]){
    int cnt=0,i=0;
    int change=0;
    char pass[101];
    FILE *file,*tempfile;
    char *tempfilename="temp.txt";
    file = fopen (filename,"r");
    while(fscanf(file,"%100s",pass)!=EOF)
    {strcpy(a[cnt++],pass);}
    for(i=0;i<100;i++){
        if(strlen(a[i])==1){
            change=i;
            break;
        }
    }
    char new[101];
    scanf("%100s",new);
    strcpy(a[change],new);
    tempfile=fopen(tempfilename,"w");
    for(i=0;i<100;i++)
    {fprintf(tempfile,"%s\n",a[i]);}
    fclose(tempfile);
    fclose(file);
    remove(filename);
    rename(tempfilename,filename);
}
void create_account(char *filename,long long int b[]){
    long long int number;
    int cnt=0,i=0;
    FILE *file,*tempfile;
    char *tempfilename="temp.txt";
    int change=0;
    file = fopen (filename,"r");
    while (fscanf(file,"%lld",&number)!=EOF)
    {b[cnt++] = number;}
    fclose(file);
    for(i=0;i<100;i++){
        if(b[i]==0){
            change=i;
            break;
        }
    }    
    long long int new=0;
    scanf("%lld",&new);
    b[change]=new;
    tempfile=fopen(tempfilename,"w");
    for(i=0;i<100;i++)
    {fprintf(tempfile,"%lld\n",b[i]);}
    fclose(file);
    fclose(tempfile);
    remove(filename);
    rename(tempfilename,filename);
}

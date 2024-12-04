#include <stdio.h>
#include <string.h>
void create_account(char *filename,long long int b[]){
    long long int number;
    int cnt=0,i=0;
    FILE *file,*tempfile;
    char *tempfilename="temp.txt";
    int changeline=0;
    file = fopen (filename,"r");
    while (fscanf(file,"%lld",&number)!=EOF)
    {b[cnt++] = number;}
    fclose(file);
    for(i=0;i<10;i++){
        if(b[i]==0){
            changeline=i+1;
            break;
        }
    }    
    long long int new=0;
    scanf("%lld",&new);
    file=fopen(filename, "r");
    tempfile = fopen(tempfilename, "w");
    int currentline=1;
    while (fscanf(file, "%lld", &number) != EOF){
        if(currentline==changeline)
        {fprintf(tempfile,"%lld\n",new);}
        else {fprintf(tempfile,"%lld\n",number);}
        currentline++;
    }
    fclose(file);
    fclose(tempfile);
    remove(filename);
    rename(tempfilename,filename);
}
int main(){
    printf("欢迎使用学生成绩管理系统.\n");
    printf("本系统使用数字化菜单，请输入对应服务的数字，按回车以确定。\n");
    printf("----------学生管理系统----------\n");
    printf("1.学生账号注册     2.系统用户登录\n");
    printf("3.忘记or修改密码   4.账号查询     \n");
    printf("5.查看使用说明     6.退出系统\n");
    int index=0;
    long long int stu_idnum[100]={0},stu_phonenum[100]={0};
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
        printf("请输入您的密码：");
        break;
        case 6:
        return 0;
        break;
    }
    return 0;
}
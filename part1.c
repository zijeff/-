#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void create_account(char *filename,long long int b[]);
void create_password(char *filename,char a[][101]);
int course_management(char *filename,int j1);
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
          printf("请输入您的电话号码：\n");
          char temp1[]="stu_phonenum.txt";
          create_account(temp1,stu_phonenum);
          printf("\n");
          printf("请输入您的学号：\n");
          char temp2[]="stu_idnum.txt";
          create_account(temp2,stu_idnum);
          printf("\n");
          printf("请输入您的密码（为了确保密码的安全性，密码至少8位）：\n");
          char temp3[]="password.txt";
          create_password(temp3,password);
          printf("账号创建成功，请牢记您的账号与密码。\n");
          break;
          case 6:
          return 0;
          break;
        case 2:
          printf("------课程管理------\n");
          printf("修改请输入1,查询请输入2,删除请输入3,增加请输入4\n");
          int j1 = 0;
          scanf("%d",&j1);
          course_management("course.txt",j1);
    }
    printf("请问是否还需要进行其他操作？\n");
    printf("需要请输1，不需要请输入2\n");
    int j = 0;
    scanf("%d",&j);
    if (j==1){
        goto beginning;
    }
    printf("感谢您的使用，再见！");
    return 0;
}

int course_management(char *filename,int j1){
    FILE *fp, *fp_temp; // 声明两个文件指针，一个用于原文件，一个用于临时文件
    char buffer[1024]; // 用于存储文件内容的缓冲区
    char *temp_filename = "temp.txt"; // 临时文件的名称
    fp = fopen("example.txt", "r+");
    // 创建一个临时文件
    fp_temp = fopen(temp_filename, "w");
    // 读取原文件内容，并写入临时文件
    char course_name[101],content[1024];
    switch(j1)
    {
        case 1:
            printf("请输入您要修改的课程：\n");
            fgets(course_name,sizeof(course_name),stdin);
            printf("请输入要修改的课程信息：依次输入课程名、简介、学院、学分、学时、选必修，并以空格隔开\n");
            printf("如果不记得，可以输入1以回到查询菜单\n");
            fgets(content,sizeof(course_name),stdin);
            if (strcmp(content,"1")==0){
                return 0;
            }
            while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            if (strstr(buffer, course_name) != NULL) {
            // 找到包含特定第一句的行，进行修改
            fprintf(fp_temp, "%s\n", content);
            }
            else {
            // 未找到特定第一句，将原始行写入临时文件
            fputs(buffer, fp_temp);
            }
        case 2:
            printf("请输入您要查询的课程：\n");
            fgets(course_name,sizeof(course_name),stdin);
            while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            buffer[strcspn(buffer, "\n")] = 0;
            if (strstr(buffer, course_name) != NULL) {
            printf("%s", buffer);
            }
        case 3:
            printf("请输入您要删除的课程：\n");
            fgets(course_name,sizeof(course_name),stdin);
            while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            buffer[strcspn(buffer, "\n")] = 0;
        if (strstr(buffer, course_name) == NULL) {
            fputs(buffer, fp_temp);
            fputs("\n", fp_temp); // 添加换行符
            }
        }
        case 4:
            printf("请输入您要增加的课程：\n");
            fgets(course_name, sizeof(course_name), stdin);
            course_name[strcspn(course_name, "\n")] = 0; 
            printf("请输入要增加的课程信息：依次输入课程名、简介、学院、学分、学时、选必修，并以空格隔开：\n");
            fgets(content, sizeof(content), stdin);
            content[strcspn(content, "\n")] = 0; // 去除换行符
    // 完成对原文件的读取和临时文件的写入
            while (fgets(buffer, sizeof(buffer), fp) != NULL) {
                buffer[strcspn(buffer, "\n")] = 0; // 去除换行符
                fputs(buffer, fp_temp); // 将原始行写入临时文件
                fputs("\n", fp_temp); // 添加换行符
            }
            }}
    // 关闭原文件和临时文件
    fclose(fp);
    fclose(fp_temp);
    // 删除原文件，并将临时文件重命名为原文件名
    remove("course.txt");
    rename(temp_filename, "course.txt");
}}

void create_password(char *filename,char a[][101])
{
    int cnt=0,i=0;
    int change=0;
    char pass[101];
    FILE *file,*tempfile;
    char *tempfilename="temp.txt";
    file = fopen (filename,"r");
    while(fscanf(file,"%100s",pass)!=EOF);
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

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;
#define STACK_INIT_SIZE 10
#define STACKINCREMENT 10
struct SqStackYH
{
    int *base;
    int *top;// 栈顶指针
    int stacksize;
};//一般报警信息小时的结构体
void InitStackYH(SqStackYH &S)
{
    S.base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
}//一般报警信息小时栈的建立函数
void PushHourY(SqStackYH &S,int e)
{
    S.top++;
    *S.top=e;
}//一般报警信息小时入栈的函数
void PopHourY(SqStackYH &S,int &e)
{
    S.base++;
    e=*S.base;
}//一般报警信息小时出栈的函数
struct SqStackYM
{
    int *base;
    int *top;//栈顶指针
    int stacksize;
};//一般报警信息分钟的结构体
void InitStackYM(SqStackYM &S1)
{
    S1.base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
    S1.top=S1.base;
    S1.stacksize=STACK_INIT_SIZE;
}//一般报警信息分钟栈的建立函数
void PushMinY(SqStackYM &S1,int e)
{
    S1.top++;
    *S1.top=e;
}//一般报警信息分钟入栈的函数
void PopMinY(SqStackYM &S1,int &e)
{
    S1.base++;
    e=*S1.base;
}//一般报警信息分钟出栈的函数
void Get_YH(SqStackYH &S,int &e)
{
    e=*(S.base+1);
}//获得一般报警信息小时的函数
void Get_YM(SqStackYM &S1,int &e)
{
    e=*(S1.base+1);
}//获得一般报警信息分钟的函数
struct SqStackJH
{
    int *base;
    int *top;// 栈顶指针
    int stacksize;
};//紧急报警信息小时的结构体
void InitStackJH(SqStackJH &H)
{
    H.base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
    H.top=H.base;
    H.stacksize=STACK_INIT_SIZE;
}//紧急报警信息小时栈的建立函数
void PushHourJ(SqStackJH &H,int e)
{
    H.top++;
    *H.top=e;
}//紧急报警信息小时入队的函数
void PopHourJ(SqStackJH &H,int &e)
{
    H.base++;
    e=*H.base;
}//紧急报警信息小时出队的函数
struct SqStackJM
{
    int *base;
    int *top;
    int stacksize;
};//紧急报警信息分钟的结构体
void InitStackJM(SqStackJM &H1)
{
    H1.base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
    H1.top=H1.base;
    H1.stacksize=STACK_INIT_SIZE;
}//紧急报警信息分钟栈的建立函数
void PushMinJ(SqStackJM &H1,int e)
{
    H1.top++;
    *H1.top=e;
}//紧急报警信息分钟入栈的函数
void PopMinJ(SqStackJM &H1,int &e)
{
    H1.base++;
    e=*H1.base;
}//紧急报警信息分钟出栈的函数
struct SqQueueY
{
    int *base;
    int front;//头指针
    int rear;//尾指针
};//一般报警信息结构体
void InitQueueY(SqQueueY &Q)
{
    Q.base=(int *)malloc(100*sizeof(int));
    Q.front=0;
    Q.rear=0;
}//一般队列的建立函数
void EnQueueY(SqQueueY &Q,int x)
{
    Q.base[Q.rear]=x;
    Q.rear=(Q.rear+1);
}//一般队列的如对函数
void DeQueueY(SqQueueY &Q,int &x)
{
    x=Q.base[Q.front];
    Q.front=(Q.front+1);
}//一般队列的出对函数
struct SqQueueJ
{
    int *base;
    int front;
    int rear;
};//紧急报警信息结构体
void InitQueueJ(SqQueueJ &G)
{
    G.base=(int *)malloc(100*sizeof(int));
    G.front=0;
    G.rear=0;
}//紧急队列的建立函数
void EnQueueJ(SqQueueJ &G,int x)
{
    G.base[G.rear]=x;
    G.rear=(G.rear+1);
}//紧急队列的入队函数
void DeQueueJ(SqQueueJ &G,int &x)
{
    x=G.base[G.front];
    G.front=(G.front+1);
}//紧急队列的出对函数
void Baojing(FILE *p1)//对报警信息处理的函数
{
    SqStackYH S;
    InitStackYH(S);
    SqStackYM S1;
    InitStackYM(S1);
    SqStackJH H;
    InitStackJH(H);
    SqStackJM H1;
    InitStackJM(H1);
    SqQueueY Q;
    InitQueueY(Q);
    SqQueueJ G;
    InitQueueJ(G);
    FILE *p;
    p=fopen("E:\\报警记录.txt","w");//用于最后记录备查的文件
    int N=10,i,j=0,f=0,k=0;
    int hour,min;
    int L,M,Y;
    int x=0,y=0;
    int a[100],b[100],c[100];
    while(N!=0)
    {
    fscanf(p1,"%d %d %d",&N,&hour,&min);
    if(N==3)//对非紧急报警信息的处理
    {
        a[k]=N;
        b[k]=hour;
        c[k]=min;
        k++;
    }
    else if(N==2)//对一般报警信息的处理
    {
        if(Q.front==Q.rear)
        {
            EnQueueY(Q,N);
            x++;
            PushHourY(S,hour);
            PushMinY(S1,min);
        }
        else
        {
            EnQueueY(Q,N);
            x++;
            PushHourY(S,hour);
            PushMinY(S1,min);
            while(Q.front!=Q.rear)
            {
            Get_YH(S,L);
            Get_YM(S1,M);
            if((hour-L==1&&min>M)||(hour-L>=2))//判断等待时间是否超1小时操作
            {
                if(hour-L>=2&&min>N)
                {
                    printf("等待时长超2小时：发出警告warning\n");
                }
                DeQueueY(Q,Y);
                PopHourY(S,L);
                PopMinY(S1,M);
                EnQueueJ(G,Y);
                PushHourJ(H,L);
                PushMinJ(H1,M);
                y++;
            }
            else
            {
                break;
            }
            }
        }
        if(((10-x)/10)==0&&((10-x)%10)==1)
        {
            printf("剩余空间等于0.1:发出警告warning\n");
        }
    }
    else if(N==1)//对紧急报警信息的处理
    {
        EnQueueJ(G,N);
        PushHourJ(H,hour);
        PushMinJ(H1,min);
        y++;
        if(((10-y)/10)==0&&((10-y)%10)==1)
        {
            printf("剩余空间等于0.1:发出警告warning\n");
        }
    }
    }
    if(k!=0)//非紧急报警信息输出操作
    {
        fprintf(p,"非紧急报警信息:\n");
        printf("非紧急报警信息:\n");
    }
    for(i=0;i<k;i++)
    {
        fprintf(p,"等级:%d 时间:%d:%d  ",a[i],b[i],c[i]);
        printf("等级:%d 时间:%d:%d  ",a[i],b[i],c[i]);
        j++;
        if(j%8==0)
        {
            fprintf(p,"\n");
            printf("\n");
        }
    }
    fprintf(p,"\n");
    printf("\n");
    int P,T;
    if(G.front!=G.rear)//紧急报警信息输出操作
    {
        fprintf(p,"紧急报警信息:\n");
        printf("紧急报警信息:\n");
        while(G.front!=G.rear)
        {
            DeQueueJ(G,P);
            PopHourJ(H,L);
            PopMinJ(H1,M);
            if(P==1)
            {
                fprintf(p,"等级:%d 时间:%d:%d  ",P,L,M);
                printf("等级:%d 时间:%d:%d  ",P,L,M);
                T=P;
            }
            if((T==1&&P==2))
            {
                fprintf(p,"\n");
                printf("\n");
            }
            if(P==2)
            {
                fprintf(p,"一般报警信息超过一小时升级为紧急:");
                printf("一般报警信息超过一小时升级为紧急:");
                fprintf(p,"原报警信息:等级:%d 时间:%d:%d  ",P,L,M);
                printf("原报警信息:等级:%d 时间:%d:%d  ",P,L,M);
                T=P;
                P=1;
                fprintf(p,"升级后报警信息:等级:%d 时间:%d:%d\n",P,L,M);
                printf("升级后报警信息:等级:%d 时间:%d:%d\n",P,L,M);
            }
        }
    }
    fprintf(p,"\n");
    printf("\n");
    if(Q.front!=Q.rear)//一般报警信息输出的操作
    {
        fprintf(p,"一般报警信息:\n");
        printf("一般报警信息:\n");
        while(Q.front!=Q.rear)
        {
            DeQueueY(Q,P);
            PopHourY(S,L);
            PopMinY(S1,M);
            fprintf(p,"等级:%d 时间:%d:%d  ",P,L,M);
            printf("等级:%d 时间:%d:%d  ",P,L,M);
            f++;
            if(f%8==0)
            {
                fprintf(p,"\n");
                printf("\n");
            }
        }
    }
}
int main()
{
    printf("\t------欢迎使用报警系统------\n");
    printf("\t---------报警请按1----------\n");
    printf("\t---------退出请按0----------\n");
    int h;
    scanf("%d",&h);
    if(h==1)
    {
         printf("\t------非紧急情况请按3------\n");
         printf("\t------一般情况请按2--------\n");
         printf("\t------紧急情况请按1--------\n");
    }
    printf("\t-------请输入内容---------\n");
    FILE *p1;
    p1=fopen("E:\\报警.txt","r");
    Baojing(p1);//引用文件函数
    return 0;
}

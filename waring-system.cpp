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
    int *top;// ջ��ָ��
    int stacksize;
};//һ�㱨����ϢСʱ�Ľṹ��
void InitStackYH(SqStackYH &S)
{
    S.base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
    S.top=S.base;
    S.stacksize=STACK_INIT_SIZE;
}//һ�㱨����ϢСʱջ�Ľ�������
void PushHourY(SqStackYH &S,int e)
{
    S.top++;
    *S.top=e;
}//һ�㱨����ϢСʱ��ջ�ĺ���
void PopHourY(SqStackYH &S,int &e)
{
    S.base++;
    e=*S.base;
}//һ�㱨����ϢСʱ��ջ�ĺ���
struct SqStackYM
{
    int *base;
    int *top;//ջ��ָ��
    int stacksize;
};//һ�㱨����Ϣ���ӵĽṹ��
void InitStackYM(SqStackYM &S1)
{
    S1.base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
    S1.top=S1.base;
    S1.stacksize=STACK_INIT_SIZE;
}//һ�㱨����Ϣ����ջ�Ľ�������
void PushMinY(SqStackYM &S1,int e)
{
    S1.top++;
    *S1.top=e;
}//һ�㱨����Ϣ������ջ�ĺ���
void PopMinY(SqStackYM &S1,int &e)
{
    S1.base++;
    e=*S1.base;
}//һ�㱨����Ϣ���ӳ�ջ�ĺ���
void Get_YH(SqStackYH &S,int &e)
{
    e=*(S.base+1);
}//���һ�㱨����ϢСʱ�ĺ���
void Get_YM(SqStackYM &S1,int &e)
{
    e=*(S1.base+1);
}//���һ�㱨����Ϣ���ӵĺ���
struct SqStackJH
{
    int *base;
    int *top;// ջ��ָ��
    int stacksize;
};//����������ϢСʱ�Ľṹ��
void InitStackJH(SqStackJH &H)
{
    H.base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
    H.top=H.base;
    H.stacksize=STACK_INIT_SIZE;
}//����������ϢСʱջ�Ľ�������
void PushHourJ(SqStackJH &H,int e)
{
    H.top++;
    *H.top=e;
}//����������ϢСʱ��ӵĺ���
void PopHourJ(SqStackJH &H,int &e)
{
    H.base++;
    e=*H.base;
}//����������ϢСʱ���ӵĺ���
struct SqStackJM
{
    int *base;
    int *top;
    int stacksize;
};//����������Ϣ���ӵĽṹ��
void InitStackJM(SqStackJM &H1)
{
    H1.base=(int *)malloc(STACK_INIT_SIZE*sizeof(int));
    H1.top=H1.base;
    H1.stacksize=STACK_INIT_SIZE;
}//����������Ϣ����ջ�Ľ�������
void PushMinJ(SqStackJM &H1,int e)
{
    H1.top++;
    *H1.top=e;
}//����������Ϣ������ջ�ĺ���
void PopMinJ(SqStackJM &H1,int &e)
{
    H1.base++;
    e=*H1.base;
}//����������Ϣ���ӳ�ջ�ĺ���
struct SqQueueY
{
    int *base;
    int front;//ͷָ��
    int rear;//βָ��
};//һ�㱨����Ϣ�ṹ��
void InitQueueY(SqQueueY &Q)
{
    Q.base=(int *)malloc(100*sizeof(int));
    Q.front=0;
    Q.rear=0;
}//һ����еĽ�������
void EnQueueY(SqQueueY &Q,int x)
{
    Q.base[Q.rear]=x;
    Q.rear=(Q.rear+1);
}//һ����е���Ժ���
void DeQueueY(SqQueueY &Q,int &x)
{
    x=Q.base[Q.front];
    Q.front=(Q.front+1);
}//һ����еĳ��Ժ���
struct SqQueueJ
{
    int *base;
    int front;
    int rear;
};//����������Ϣ�ṹ��
void InitQueueJ(SqQueueJ &G)
{
    G.base=(int *)malloc(100*sizeof(int));
    G.front=0;
    G.rear=0;
}//�������еĽ�������
void EnQueueJ(SqQueueJ &G,int x)
{
    G.base[G.rear]=x;
    G.rear=(G.rear+1);
}//�������е���Ӻ���
void DeQueueJ(SqQueueJ &G,int &x)
{
    x=G.base[G.front];
    G.front=(G.front+1);
}//�������еĳ��Ժ���
void Baojing(FILE *p1)//�Ա�����Ϣ����ĺ���
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
    p=fopen("E:\\������¼.txt","w");//��������¼������ļ�
    int N=10,i,j=0,f=0,k=0;
    int hour,min;
    int L,M,Y;
    int x=0,y=0;
    int a[100],b[100],c[100];
    while(N!=0)
    {
    fscanf(p1,"%d %d %d",&N,&hour,&min);
    if(N==3)//�Էǽ���������Ϣ�Ĵ���
    {
        a[k]=N;
        b[k]=hour;
        c[k]=min;
        k++;
    }
    else if(N==2)//��һ�㱨����Ϣ�Ĵ���
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
            if((hour-L==1&&min>M)||(hour-L>=2))//�жϵȴ�ʱ���Ƿ�1Сʱ����
            {
                if(hour-L>=2&&min>N)
                {
                    printf("�ȴ�ʱ����2Сʱ����������warning\n");
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
            printf("ʣ��ռ����0.1:��������warning\n");
        }
    }
    else if(N==1)//�Խ���������Ϣ�Ĵ���
    {
        EnQueueJ(G,N);
        PushHourJ(H,hour);
        PushMinJ(H1,min);
        y++;
        if(((10-y)/10)==0&&((10-y)%10)==1)
        {
            printf("ʣ��ռ����0.1:��������warning\n");
        }
    }
    }
    if(k!=0)//�ǽ���������Ϣ�������
    {
        fprintf(p,"�ǽ���������Ϣ:\n");
        printf("�ǽ���������Ϣ:\n");
    }
    for(i=0;i<k;i++)
    {
        fprintf(p,"�ȼ�:%d ʱ��:%d:%d  ",a[i],b[i],c[i]);
        printf("�ȼ�:%d ʱ��:%d:%d  ",a[i],b[i],c[i]);
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
    if(G.front!=G.rear)//����������Ϣ�������
    {
        fprintf(p,"����������Ϣ:\n");
        printf("����������Ϣ:\n");
        while(G.front!=G.rear)
        {
            DeQueueJ(G,P);
            PopHourJ(H,L);
            PopMinJ(H1,M);
            if(P==1)
            {
                fprintf(p,"�ȼ�:%d ʱ��:%d:%d  ",P,L,M);
                printf("�ȼ�:%d ʱ��:%d:%d  ",P,L,M);
                T=P;
            }
            if((T==1&&P==2))
            {
                fprintf(p,"\n");
                printf("\n");
            }
            if(P==2)
            {
                fprintf(p,"һ�㱨����Ϣ����һСʱ����Ϊ����:");
                printf("һ�㱨����Ϣ����һСʱ����Ϊ����:");
                fprintf(p,"ԭ������Ϣ:�ȼ�:%d ʱ��:%d:%d  ",P,L,M);
                printf("ԭ������Ϣ:�ȼ�:%d ʱ��:%d:%d  ",P,L,M);
                T=P;
                P=1;
                fprintf(p,"�����󱨾���Ϣ:�ȼ�:%d ʱ��:%d:%d\n",P,L,M);
                printf("�����󱨾���Ϣ:�ȼ�:%d ʱ��:%d:%d\n",P,L,M);
            }
        }
    }
    fprintf(p,"\n");
    printf("\n");
    if(Q.front!=Q.rear)//һ�㱨����Ϣ����Ĳ���
    {
        fprintf(p,"һ�㱨����Ϣ:\n");
        printf("һ�㱨����Ϣ:\n");
        while(Q.front!=Q.rear)
        {
            DeQueueY(Q,P);
            PopHourY(S,L);
            PopMinY(S1,M);
            fprintf(p,"�ȼ�:%d ʱ��:%d:%d  ",P,L,M);
            printf("�ȼ�:%d ʱ��:%d:%d  ",P,L,M);
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
    printf("\t------��ӭʹ�ñ���ϵͳ------\n");
    printf("\t---------�����밴1----------\n");
    printf("\t---------�˳��밴0----------\n");
    int h;
    scanf("%d",&h);
    if(h==1)
    {
         printf("\t------�ǽ�������밴3------\n");
         printf("\t------һ������밴2--------\n");
         printf("\t------��������밴1--------\n");
    }
    printf("\t-------����������---------\n");
    FILE *p1;
    p1=fopen("E:\\����.txt","r");
    Baojing(p1);//�����ļ�����
    return 0;
}

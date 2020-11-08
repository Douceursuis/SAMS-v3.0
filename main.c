#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_LEN 10
#define N 30
#define SUBJECT 6

int Ascending(int a,int b)
{
    return a>b;
}
int Descending(int a,int b)
{
    return a<b;
}
void swapNum(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
void swapStr(char a[], char b[])
{
    char temp[20];
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

void PrintMenu()
{
    printf("1.Input record\n");
    printf("2.List record\n");
    printf("3.Calculate total and average score of every course\n");
    printf("4.Calculate total and average score of every student\n");
    printf("5.Sort in descending order by total score of every student\n");
    printf("6.Sort in ascending order by total score of every student\n");
    printf("7.Sort in ascending order by StudentID\n");
    printf("8.Sort in dictionary order by name:\n");
    printf("9.Search by StudentID\n");
    printf("10.Search by name:\n");
    printf("11.Statistic analysis for every course\n");
    printf("0.Exit\n");
    printf("Please enter your choice:\n");
}

void ReadData(int ID[],char name[][MAX_LEN],int sub_score[][SUBJECT],int n,int sub)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        printf("Please enter the ID and name of student like ab:\n");     //a,b之间有两个空格
        scanf("%d%s",&ID[i],name[i]);
        for(j=0; j<sub; j++)
        {
            printf("Please enter the score of course %d:\n",j+1);
            scanf("%d",&sub_score[i][j]);
        }
    }
}
void PrintData(int ID[],char name[][MAX_LEN],int sub_score[][SUBJECT],int n,int sub)
{
    int i,j,sum[n];
    float aver[n];
    for(i=0; i<n; i++)
    {
        sum[i]=0;
        aver[i]=0;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<sub; j++)
        {
            sum[i]+=sub_score[i][j];
        }
        aver[i]=1.0*sum[i]/sub;
    }
    for(i=0; i<n; i++)
    {
        printf("StudentID: %ld name: %s\n",ID[i],name[i]);
        for(j=0; j<sub; j++)
        {
            printf("course: %d score: %d\n",j+1,sub_score[i][j]);
        }
        printf("The total scores is %d The rank is %d The average is %.2f",sum[i],i+1,aver[i]);
        printf("\n");

    }
}

void iPrintData(int ID[],char name[][MAX_LEN],int sub_score[][SUBJECT],int n,int sub)
{
    int i,j,sum[n];
    float aver[n];
    for(i=0; i<n; i++)
    {
        sum[i]=0;
        aver[i]=0;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<sub; j++)
        {
            sum[i]+=sub_score[i][j];
        }
        aver[i]=1.0*sum[i]/sub;
    }
    for(i=0; i<n; i++)
    {
        printf("StudentID: %ld name: %s\n",ID[i],name[i]);
        for(j=0; j<sub; j++)
        {
            printf("course: %d score: %d\n",j+1,sub_score[i][j]);
        }
        printf("The total scores is %d The rank is %d The average is %.2f",sum[i],n-i,aver[i]);
        printf("\n");

    }
}
void iiPrintData(int ID[],char name[][MAX_LEN],int sub_score[][SUBJECT],int n,int sub)
{
    int i,j,sum[n];
    float aver[n];
    for(i=0; i<n; i++)
    {
        sum[i]=0;
        aver[i]=0;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<sub; j++)
        {
            sum[i]+=sub_score[i][j];
        }
        aver[i]=1.0*sum[i]/sub;
    }
    for(i=0; i<n; i++)
    {
        printf("StudentID: %ld name: %s\n",ID[i],name[i]);
        for(j=0; j<sub; j++)
        {
            printf("course: %d score: %d\n",j+1,sub_score[i][j]);
        }
        printf("The total scores is %d The average is %.2f",sum[i],aver[i]);
        printf("\n");

    }
}
void sum_aver_course(int sub_score[][SUBJECT],int n,int sub,int sum[SUBJECT],float aver[SUBJECT])
{
    int i,j;
    for(j=0; j<sub; j++)
    {
        sum[j]=0;
    }
    for(j=0; j<sub; j++)
    {
        for(i=0; i<n; i++)
        {
            sum[j] +=sub_score[i][j];
        }
        aver[j]=1.0*sum[j]/n;
    }
}
void sum_aver_stu(int sub_score[][SUBJECT],int n,int sub,int sum[N],float aver[N] )
{
    int i,j;
    for(i=0; i<n; i++)
    {
        sum[i]=0;
    }
    for(i=0; i<n; i++)
    {
        for(j=0; j<sub; j++)
        {
            sum[i] +=sub_score[i][j];
        }
        aver[i]=1.0*sum[i]/sub;
    }

}
void SortScore(int copyID[], char copyname[][MAX_LEN], int copysub_score[][SUBJECT], int ID[], char name[][MAX_LEN], int sub_score[][SUBJECT], int n,  int sub, int (*compare)(int a, int b))
{
    int sumscore[N];
    int flag;
    for(int i = 0; i < n; i++)
    {
        sumscore[i] = 0;
        copyID[i] = ID[i];
        strcpy(copyname[i], name[i]);
        for(int j = 0; j < sub; j++)
        {
            copysub_score[i][j] = sub_score[i][j];
            sumscore[i] += sub_score[i][j];
        }
    }
    for(int i = 0; i < n - 1; i++)
    {
        flag=0;
        for(int j = 0; j < n - 1; j++)
        {
            if((*compare)(sumscore[j],sumscore[j+1]))
            {
                swapNum(&copyID[j], &copyID[j+1]);
                swapStr(copyname[j], copyname[j+1]);
                for(int k = 0; k < sub; k++)
                {
                    swapNum(&copysub_score[j][k], &copysub_score[j+1][k]);
                }
                swapNum(&sumscore[j], &sumscore[j+1]);
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
    }
}

void SortID(int copyID[], char copyname[][MAX_LEN], int copysub_score[][SUBJECT], int ID[], char name[][MAX_LEN], int sub_score[][SUBJECT], int n,  int sub)
{
    int flag;
    for(int i = 0; i < n; i++)
    {
        copyID[i] = ID[i];
        strcpy(copyname[i], name[i]);
        for(int j = 0; j < sub; j++)
        {
            copysub_score[i][j] = sub_score[i][j];
        }
    }
    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - 1; j++)
        {
            if(copyID[j]>copyID[j+1])
            {
                swapNum(&copyID[j], &copyID[j+1]);
                swapStr(copyname[j], copyname[j+1]);
                for(int k = 0; k < sub; k++)
                {
                    swapNum(&copysub_score[j][k], &copysub_score[j+1][k]);
                }
            }
        }
    }
}

void SortName(int copyID[], char copyname[][MAX_LEN], int copysub_score[][SUBJECT], int ID[], char name[][MAX_LEN], int sub_score[][SUBJECT], int n,  int sub)
{

    for(int i = 0; i < n; i++)
    {
        copyID[i] = ID[i];
        strcpy(copyname[i], name[i]);
        for(int j = 0; j < sub; j++)
        {
            copysub_score[i][j] = sub_score[i][j];
        }
    }
    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            if(strcmp(copyname[j],name[j+1])>0)
            {
                swapNum(&copyID[j],&copyID[j+1]);
                swapStr(copyname[j],copyname[j+1]);
                for(int k=0; k<sub; k++)
                {
                    swapNum(&copysub_score[j][k],&copysub_score[j+1][k]);
                }
            }
        }
    }
}

void search_ID(int ID[], int sub_score[][SUBJECT],char name[][MAX_LEN], int sub,long x,int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        if(x==ID[i])
        {
            printf("name: %s ID: %ld rank: %d\n",name[i],ID[i],i+1);

            for(j=0; j<sub; j++)
            {
                printf("course: %d score: %d\n",j+1,sub_score[i][j]);
            }

        }

    }
}

void search_name(int ID[], int sub_score[][SUBJECT],char name[][MAX_LEN],int sub,char y[MAX_LEN],int n)
{
    int i,j;
    for(i=0; i<n; i++)
    {
        if(strcmp(y, name[i]) == 0)
  //if(y==Copyname[i])
        {
            printf("name: %s ID: %ld rank: %d\n",name[i],ID[i],i+1);

            for(j=0; j<sub; j++)
            {
                printf("course: %d score: %d\n",j+1,sub_score[i][j]);
            }
        }
    }
}
void Range(int sub_score[][SUBJECT],int n,int sub)
{
    int i,j,a;
    int sum[5]= {0};
    double percent[5];
    for(int j=0; j<sub; j++)
    {
        for(int i=0; i<n; i++)
        {
            if(sub_score[i][j]<101&&sub_score[i][j]>=90)
            {
                sum[0]+=1;
            }
            if(sub_score[i][j]<90&&sub_score[i][j]>=80)
            {
                sum[1]+=1;
            }
            if(sub_score[i][j]<80&&sub_score[i][j]>=70)
            {
                sum[2]+=1;
            }
            if(sub_score[i][j]<70&&sub_score[i][j]>=60)
            {
                sum[3]+=1;
            }
            if(sub_score[i][j]<60&&sub_score[i][j]>=0)
            {
                sum[4]+=1;
            }
        }
        for(a=0; a<5; a++)
        {
            percent[a]=(double)sum[a]/n*100;
        }
        printf("course %d  90-100  number: %d   percent: %.2f%%\n",j+1,sum[0],percent[0]);
        printf("course %d  80-89  number: %d   percent: %.2f%%\n",j+1,sum[1],percent[1]);
        printf("course %d  70-79  number: %d   percent: %.2f%%\n",j+1,sum[2],percent[2]);
        printf("course %d  60-69  number: %d   percent: %.2f%%\n",j+1,sum[3],percent[3]);
        printf("course %d  0-59  number: %d   percent: %.2f%%\n",j+1,sum[4],percent[4]);
        for(a=0; a<5; a++)
        {
            sum[a]=0;
        }

    }

}




int main()
{
    char name[N][MAX_LEN],Copyname[N][MAX_LEN];
    int ID[N],CopyID[N];
    int sub_score[N][SUBJECT],rank[N],sum[SUBJECT],i,j,n,sub,choice,temp;
    float averStu[N],averSub[SUBJECT];
    int Copysub_score[N][SUBJECT];
    long x;
    char y[MAX_LEN];
    do
    {
        printf("How many students?(1-30)\n");
        scanf("%d",&n);

    }
    while(n>30||n<1);

    do
    {
        printf("How many courses?(1-6)\n");
        scanf("%d",&sub);
    }
    while(sub>6||sub<1);

    //设置循环以便多次输入
    for(j=1; j<100000; j++)
    {
        PrintMenu();
        scanf("%d",&choice);

        //当第一次没有输入1的时候提示重新输入
        while(j==1&&choice!=1)
        {
            printf("Errors,please input 1 first \n");
            scanf("%d",&choice);
            if(choice==1)
                break;
        }

        //利用switch语句进行功能选择
        switch(choice)
        {
        case 1:
            ReadData(ID,name,sub_score,n,sub);

            break;
        case 2:
            PrintData(ID,name,sub_score,n,sub);
            break;
        case 3:
            sum_aver_course(sub_score,n,sub,sum,averSub);
            for(i=0; i<sub; i++)
            {
                printf("The total score of course %d is %d  \nThe average score of course %d is %.2f\n",i+1,sum[i],i+1,averSub[i]);
            }
            break;
        case 4:
            sum_aver_stu(sub_score,n,sub,sum,averStu);
            for( i=0; i<n; i++)
            {
                printf("The total score of student %d is %d\nThe average score of student %d is %.2f\n",i+1,sum[i],i+1,averStu[i]);
            }
            break;
        case 5:
            SortScore(CopyID,Copyname,Copysub_score,ID,name,sub_score,n,sub,Descending);
            PrintData(CopyID,Copyname,Copysub_score,n,sub);
            break;
        case 6:
            SortScore(CopyID,Copyname,Copysub_score,ID,name,sub_score,n,sub,Ascending);
            iPrintData(CopyID,Copyname,Copysub_score,n,sub);
            break;
        case 7:
            SortID(CopyID,Copyname,Copysub_score,ID,name,sub_score,n,sub);
            PrintData(CopyID,Copyname,Copysub_score,n,sub);
            break;
        case 8:
            SortName(CopyID,Copyname,Copysub_score,ID,name,sub_score,n,sub);
            iiPrintData(CopyID,Copyname,Copysub_score,n,sub);
            break;
        case 9:
            SortScore(CopyID,Copyname,Copysub_score,ID,name,sub_score,n,sub,Descending);

            printf("Please input the studentID of a student:\n");
            scanf("%d",&x);
            search_ID(CopyID,Copysub_score,Copyname,sub,x,n);

            break;
        case 10:
            SortScore(CopyID,Copyname,Copysub_score,ID,name,sub_score,n,sub,Descending);

            printf("Please input the name of a student:\n");
            scanf("%s",y);
            //getchar();
            search_name(CopyID,Copysub_score,Copyname,sub,y,n);

            break;
        case 11:
            Range(sub_score,n,sub);
            break;
        case 0:
            exit(0);
            break;

        //当用户没有输入0-10时，提醒重新输入
        default:
            printf("Please enter the right choice!\n");
            break;
        }

    }
    return 0;
}



#include<stdio.h>
#include<iostream>
#include<iomanip>
#define MAX 1000
struct Task
{
    int cost;
    int start;
    int end;
    int wait;
};
void sort(Task t[],int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(t[i].cost>t[j].cost)
            {
                Task temp=t[i];
                t[i]=t[j];
                t[j]=temp;
            }
        }
    }
}
int main()
{
    int n;
    printf("Please input the num of task:");
    std::cin>>n;

    Task task[MAX];
    for(int i=1;i<=n;i++)
    {
        printf("Please input the %d-th task's cost:",i);
        std::cin>>task[i].cost;
    }
    printf("Origin:\n");
    std::string str[5]={"id","cost","start","end","wait"};
    std::cout<<std::setw(8)<<str[0]<<'|'<<std::setw(8)<<str[1]<<'|'<<std::setw(8)<<str[2]<<'|'<<std::setw(8)<<str[3]<<'|'<<std::setw(8)<<str[4]<<'|'<<'\n';
    
    int s=1,e=0,w=0,now=1;
    double aver_w=0;
    for(int i=1;i<=n;i++)
    {
        aver_w+=w;
        e=s+task[i].cost;
        printf("%8d |%8d |%8d |%8d |%8d |\n",i,task[i].cost,s,e,w);
        s=e;
        w+=task[i].cost;
    }
    printf("\n the average waiting time is: %.2f\n",aver_w/n);

    
    sort(task,n);
    printf("after:\n");
    std::cout<<std::setw(8)<<str[0]<<'|'<<std::setw(8)<<str[1]<<'|'<<std::setw(8)<<str[2]<<'|'<<std::setw(8)<<str[3]<<'|'<<std::setw(8)<<str[4]<<'|'<<'\n';
    s=1,e=0,w=0,now=1,aver_w=0;
    for(int i=1;i<=n;i++)
    {
        aver_w+=w;
        e=s+task[i].cost;
        printf("%8d |%8d |%8d |%8d |%8d |\n",i,task[i].cost,s,e,w);
        s=e;
        w+=task[i].cost;
    }
    printf("\n the average waiting time is: %.2f\n",aver_w/n);
}
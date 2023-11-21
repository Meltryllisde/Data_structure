#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
struct max_well
{
    int i;
    int val;
};
max_well max,maxx;
max_well score[512];
void init()
{
    srand((unsigned)time(NULL));
    for(int i=0;i<512;i++)
    {
        score[i].val=(rand()%1000);
        score[i].i=i;
    }
    max.val=0;
    maxx.val=0;
    max.i=0;
    maxx.i=0;
}
bool cmp(max_well a,max_well b)
{
    return a.val>b.val;
}
void search0()
{
    max_well scoree[512];
    memcpy(scoree,score,sizeof(scoree));
    std::sort(scoree,scoree+512,cmp);
    max=scoree[0],maxx=scoree[1];
    std::cout<<"Origin:\n";
    std::cout<<"FMAXID"<<max.i<<':'<<max.val<<std::endl;
    std::cout<<"SMAXID"<<maxx.i<<':'<<maxx.val<<std::endl;
}
void search1()
{
    max.val=0,maxx.val=0,max.i=0,maxx.i=0;
    for(int i=0;i<512;i++)
    {
        if(max.val<score[i].val)
        {
            maxx=max;
            max=score[i];
        }
        else if(maxx.val<score[i].val)maxx=score[i];
    }
    std::cout<<"\nSearch1:\n";
    std::cout<<"FMAXID"<<max.i<<':'<<max.val<<std::endl;
    std::cout<<"SMAXID"<<maxx.i<<':'<<maxx.val<<std::endl;
}
void search2()
{
    max.val=0,maxx.val=0,max.i=0,maxx.i=0;
    int ptr=0;
    max_well temp[2000];
    memcpy(temp+512,score,sizeof(score));
    for(int i=1022;i>=2;i-=2)
        temp[i/2]=temp[i].val>temp[i+1].val?temp[i]:temp[i+1];
    max=temp[1];
    for(int i=1;i<512;)
    {
        if(temp[i].val==temp[i*2].val)
        {
            if(maxx.val<temp[i*2+1].val)maxx=temp[i*2+1];
            i*=2;
        }
        else
        {
            if(maxx.val<temp[i*2].val)maxx=temp[i*2];
            i=i*2+1;
        }
    }
    std::cout<<"\nSearch2:\n";
    std::cout<<"FMAXID"<<max.i<<':'<<max.val<<std::endl;
    std::cout<<"SMAXID"<<maxx.i<<':'<<maxx.val<<std::endl;
}
void heap(max_well a[],int p,int l)
{
    max_well temp=a[p];
    int c=2*p;
    while (c<=l)
    {
        if(c+1<=l&&a[c].val<a[c+1].val)c++;
        if(temp.val>=a[c].val)break;

        a[p]=a[c];
        p=c;
        c=c*2;
    }
    a[p]=temp;
}
void search3()
{
    max.val=0,maxx.val=0,max.i=0,maxx.i=0;
    max_well temp[513];
    memcpy(temp+1,score,sizeof(score));
    int ptr=512/2;
    for(int i=ptr;i>=1;i--)
    {
        heap(temp,i,512);
    }
    max=temp[1];
    maxx=temp[2].val>temp[3].val?temp[2]:temp[3];
    std::cout<<"\nSearch3:\n";
    std::cout<<"FMAXID"<<max.i<<':'<<max.val<<std::endl;
    std::cout<<"SMAXID"<<maxx.i<<':'<<maxx.val<<std::endl;
}
int main()
{
    init();
    
    search0();
    search1();
    search2();
    search3();
}
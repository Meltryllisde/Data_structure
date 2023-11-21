#include<stdio.h>
#include<iostream>
#include <cmath>
using namespace std;
int n=0,c=0;
int check(int x,int y)
{
    if(x>=y||x==0)return 1;
    else return 0;
}

int dist[101][101][2]={0};
int pre[101][101][2][3]={0};

void dfs(int x,int y,int z,int dis,int prex,int prey)
{
    if(check(x,y)==0)return;
    if(dist[x][y][z]!=0&&dist[x][y][z]<=dis)return;

    pre[x][y][z][0]=prex;
    pre[x][y][z][1]=prey;
    pre[x][y][z][2]=z^1;

    dist[x][y][z]=dis;

    int hx,hy,tx,ty;
    if(z==0)hx=x,hy=y,tx=n-x,ty=n-y;
    else tx=x,ty=y,hx=n-x,hy=n-y;

    for(int dx=min(c,hx);dx>=0;dx--)
    {
        for(int dy=min(c-dx,hy);dy>=0;dy--)
        {
            if(dx+dy==0)continue;
            if(check(dx,dy)&&check(hx-dx,hy-dy)&&check(tx+dx,ty+dy))
            {
                int nextx,nexty;
                if(z==0) nextx=hx-dx,nexty=hy-dy;
                else nextx=tx+dx,nexty=ty+dy;
                dfs(nextx,nexty,z^1,dis+1,x,y);
            }
        }
    }
}
int main()
{
    printf("Please input the n:");
    scanf("%d",&n);
    printf("\n");
    printf("Please input the c:");
    scanf("%d",&c);
    dfs(n,n,0,1,n,n);
    if(dist[0][0][1])
    {
        system("cls");
        printf("Successed!\n");
        int nowx=0,nowy=0,nowz=1;
        while(nowx!=n||nowy!=n||nowz!=0)
        {
            printf("(%d,%d,%d)\n",nowx,nowy,nowz);
            int tx=pre[nowx][nowy][nowz][0];
            int ty=pre[nowx][nowy][nowz][1];
            int tz=pre[nowx][nowy][nowz][2];
            nowx = tx, nowy = ty, nowz = tz;
        }
        printf("(%d,%d,%d)\n",3,3,0);
        printf("n=%d ,c=%d",n,c);
    }
    else 
    {
        printf("Failed!\n");
    }
}
#include<bits/stdc++.h>
using namespace std;
int x[500][500];
int main()
{
    int n;
    while (1)
    {
        cout<<"Please input the m:";
        cin>>n;
        if(n%2!=0)
            break;
        else
            cout<<"m%2==0!!!\n";
    }
    
    for (int i=1;i<=n;i++)
    {
        for (int k=1;k<=n;k++)
        {
            x[i][k]=0;
        } 
    }
    int r,c;
    r=1;
    c=(n/2)+1;
    for (int i=1;i<=n*n;i++)
    {
    if (x[r][c]!=0)
    {
        r+=2;
        c-=1;
        if(r>=n+1)
            r=r%n;
        if(c==0)
            c=n;
    }                
    x[r][c]=i;
    r-=1;
    c+=1;
    if(r==0)
        r=n;
    if(c==n+1)
        c=1;
    }
    for (int i=1;i<=n;i++)
    {
        for (int k=1;k<=n;k++)
        {
            printf("%5d ",x[i][k]);
        } 
        printf("\n");
    }
    system("pause");
}
#include<bits/stdc++.h>
using namespace std;
#define max(a,b) ((a)>(b))?(a):(b)
#define min(a,b) ((a)<(b))?(a):(b)
int n,m,tot,num;
int a[10001];
int vis[20][20][20][20];
int dfs(int x,int y,int x1,int y1)
{
    if(vis[x][y][x1][y1])
    {
        if(num==vis[x][y][x1][y1])return 2;
        return vis[x][y][x1][y1];
    }
    vis[x][y][x1][y1]=num;
    int tx=x,ty=y,tx1=x1,ty1=y1;
    bool di=0;
    if(x>0)
    {
        if(x==1)di=1;
        --x;
        if(x==0)x=a[x];
		else
        if(y==0)y=a[x];
        else if(x1==0)x1=a[x];
        else if(y1==0) y1=a[x];
    }
    if(y>0)
    {
        if(y==1)di=1;
        --y;
		if(x==0)x=a[y];
		else
        if(y==0)y=a[y];
        else if(x1==0)x1=a[y];
        else if(y1==0) y1=a[y];
    }
    if(x1>0)
    {
        if(x1==1)di=1;
        --x1;
        if(x==0)x=a[x1];
		else
        if(y==0)y=a[x1];
        else if(x1==0)x1=a[x1];
        else if(y1==0) y1=a[x1];
    }
    if(y1>0)
    {
        if(y1==1)di=1;
        --y1;
        if(x==0)x=a[y1];
		else
        if(y==0)y=a[y1];
        else if(x1==0)x1=a[y1];
        else if(y1==0)y1=a[y1];
    }
    if(!di)return 1;
    vis[tx][ty][tx1][ty1]=dfs(x,y,x1,y1);
    if(vis[tx][ty][tx1][ty1]==2)tot++;
    return vis[tx][ty][tx1][ty1];

}
int main()
{
	freopen("bob.in","r",stdin);
	freopen("bob.out","w",stdout);
    cin>>n;
    for(int i=1; i<n; i++)cin>>a[i];
    num=2;
    for(int i=n; i>=0; i--)
    {
        for(int j=n; j>=0; j--)
        {
            for(int k=n; k>=0; k--)
            {
                for(int l=n; l>=0; l--)
                {
                    if(!vis[i][j][k][l])
                    {
                        ++num;
                        dfs(i,j,k,l);
                    }
                }
            }
        }
    }
    cout<<tot<<endl;
    return 0;
}

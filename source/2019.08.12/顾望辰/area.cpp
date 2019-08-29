#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
int maxs,dxy[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
bool vis[7000][7000];
struct matrix
{
	bool a[7000][7000];
	int siz;
}A;
void calc(matrix& x)
{
	int t=x.siz;
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=t;j++)
		{
			x.a[t+i][j]=x.a[i][t+j]=x.a[i][j];
			x.a[t+i][t+j]=!x.a[i][j];
		}
	}
	x.siz<<=1;
	return ;
}
int bfs(int sx,int sy)
{
	int ans=1;
	bool nd=A.a[sx][sy];
	queue<pair<int,int> > q;
	q.push(make_pair(sx,sy));
	vis[sx][sy]=true;
	pair<int,int> now,nw;
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			nw.first=now.first+dxy[i][0];
			nw.second=now.second+dxy[i][1];
			if(A.a[nw.first][nw.second]==nd&&!vis[nw.first][nw.second])
			{
				vis[nw.first][nw.second]=true;
				q.push(nw);
				ans++;
				if(ans>maxs) return -1;
			}
		}
	}
	return ans;
}
int main()
{
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	int X,Y,tx;
	scanf("%d%d",&X,&Y);
	tx=max(X,Y);
	while(tx!=(tx&(-tx))) tx+=tx&(-tx);
	tx<<=1;
	A.a[1][1]=A.a[1][2]=A.a[2][1]=true;
	A.a[2][2]=false;
	A.siz=2;
	while(A.siz<tx) calc(A);
	maxs=A.siz<<1;
	int ans=bfs(X,Y);
	if(ans==-1) printf("infinity\n");
	else printf("%d\n",ans);
	return 0;
}

#include<bits/stdc++.h>
const int MAXN=300005;
using namespace std;
int read();
struct Edge{
	int xx,yy,zz;
} ee[MAXN];
struct edge{
	int to_,value_,next_;
} e[MAXN*2];
int head[MAXN];
int tot;
void Add(int x,int y,int z);
int _min(int a,int b);
int _max(int a,int b);
bool cmp(Edge a,Edge b);
int Find_(int x);
void dfs(int x);
int lca(int x,int y);
int bing[MAXN];
int depth[MAXN],father[20][MAXN],mfer[20][MAXN];
int main()
{
	freopen("graph.in","r",stdin);
	freopen("graph.out","w",stdout);
	int N=read(),M=read(),Q=read();
	for  (int i=1;i<=M;i++)
		{
			int x=read(),y=read(),z=read();
			ee[i].xx=x,ee[i].yy=y,ee[i].zz=z;
		}//M
		
		
	sort(ee+1,ee+M+1,cmp);//M*log M
	for  (int i=1;i<=N;i++)
		bing[i]=i;
	int cnt=0;	
	for  (int i=1;i<=M;i++)
		{
			if  (cnt==N-1)	break;
			int X=ee[i].xx,Y=ee[i].yy,Z=ee[i].zz;
			int XX=Find_(X),YY=Find_(Y);
			if  (XX!=YY)
				{
					bing[XX]=YY;
					bing[XX]=Find_(XX);
					Add(X,Y,Z),Add(Y,X,Z);
					cnt++;	
				}
		}
	for  (int i=1;i<=N;i++)
		bing[i]=Find_(i);
	for  (int i=1;i<=N;i++)
		if  (depth[i]==0)
			{
				depth[i]=1;
				father[0][i]=i;
				dfs(i);
			}
	int NN=log2(N);
	for  (int i=1;i<=NN;i++)
		for  (int j=1;j<=N;j++)
			{
				father[i][j]=father[i-1][father[i-1][j]];
				mfer[i][j]=_max(mfer[i-1][j],mfer[i-1][father[i-1][j]]);
			}
	for  (int i=1;i<=Q;i++)
		{
			int xx=read(),yy=read();
			if  (bing[xx]!=bing[yy])
				{
					printf("-1\n");
					continue;
				}
			int Ans=lca(xx,yy);
			printf("%d\n",Ans);
		}
	return 0;
}



int lca(int x,int y)
{
	int ans=0;
	if  (depth[x]<depth[y])
		swap(x,y);
	int z=depth[x]-depth[y];
	if  (z>0)
		{
			int zz=log2(z);
			for  (int i=zz;i>=0;i--)
				if  (z&(1<<i))
					{
						ans=_max(ans,mfer[i][x]);
						x=father[i][x];
					}
		}
	
	if  (x==y)	return ans;
	z=depth[x];
	int zz=log2(z);
	for  (int i=zz;i>=0;i--)
		if  (father[i][x]!=father[i][y])
			{
				ans=_max(ans,mfer[i][x]);
				ans=_max(ans,mfer[i][y]);
				x=father[i][x];
				y=father[i][y];
			}
	ans=_max(ans,_max(mfer[0][x],mfer[0][y]));
	return ans;
}
void dfs(int x)
{
	for  (int i=head[x];i;i=e[i].next_)
		{
			int y=e[i].to_,z=e[i].value_;
			if  (depth[y]==0)
				{
					depth[y]=x+1;
					father[0][y]=x;
					mfer[0][y]=z;
					dfs(y);
				}
		}
}
int Find_(int x)
{
	if  (bing[x]!=x)
		bing[x]=Find_(bing[x]);
	return bing[x];
}
int read()
{
	int a=0; char c=getchar();
	for (;!isdigit(c);c=getchar());
	for (;isdigit(c);a=a*10+c-48,c=getchar());
	return a;
}
void Add(int x,int y,int z)
{
	e[++tot].to_=y;
	e[tot].value_=z;
	e[tot].next_=head[x];
	head[x]=tot;
}
int _min(int a,int b)
{
	return a<b?a:b;
}
int _max(int a,int b)
{
	return a>b?a:b;
}
bool cmp(Edge a,Edge b)
{
	return a.zz<b.zz;
}

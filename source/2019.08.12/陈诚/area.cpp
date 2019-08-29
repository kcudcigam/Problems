#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1,0,0};
template <typename T> inline void rd(T &x)
{
	x=0; int f=1; char ch=0;
	for(;!isdigit(ch);ch=getchar()) if(ch=='-') f=-f;
	for(; isdigit(ch);ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	x*=f;
}
template <typename T> inline void wrote(T x)
{
	if(x<0) {putchar('-'); wrote(-x); return;}
	if(x<10) {putchar(x+48); return;}
	wrote(x/10);
	putchar(x%10+48);
}
int xx,yy,cnt;
bool a[505][505],vis[505][505];
void Build(int x,int y)
{
	if(xx*2<=x && yy*2<=y) return;
	for(int i=x/2+1; i<=x; ++i)
		for(int j=1; j<=x/2; ++j)
			a[i][j]=a[i-x/2][j];
	for(int i=1; i<=x/2; ++i)
		for(int j=x/2+1; j<=x; ++j)
			a[i][j]=a[i][j-x/2];
	for(int i=x/2+1; i<=x; ++i)
		for(int j=x/2+1; j<=x; ++j)
			a[i][j]=!a[i-x/2][j-x/2];
	Build(x*2,y*2);
}
void dfs(int x,int y)
{
	if(x==1 || y==1)
	{
		puts("infinity");
		exit(0);
	}
	vis[x][y]=1;
	++cnt;
	for(int i=0; i<4; ++i)
	{
		if(a[x+dx[i]][y+dy[i]]==a[x][y]
		&& x+dx[i]>0 && x+dx[i]<500 && y+dy[i]>0 && y+dy[i]<500
		&& !vis[x+dx[i]][y+dy[i]])
		dfs(x+dx[i],y+dy[i]);
	}
}
int main()
{
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	rd(xx); rd(yy);
	++xx; ++yy;
	if(xx==1 || yy==1)
	{
		puts("infinity");
		return 0;
	}
	a[1][1]=a[1][2]=a[1][3]=0;
	a[2][2]=1;
	Build(4,4);
	dfs(xx,yy);
	wrote(cnt);
	return 0;
}


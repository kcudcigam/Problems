#include<bits/stdc++.h>
#define re register
#define rep(i,x,y) for(re int i=x;i<=y;++i)
#define Rep(i,x,y) for(re int i=x;i>=y;--i)
using namespace std;
template <typename T> inline void read(T &x)
{
	T f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(; isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-48;
	x*=f;
}
int m,n,a[200][200],b[200][200];
bool vis[200][200];
int ans;
void dfs(int x,int y)
{
	if(x==1||y==1)
	{
		puts("infinity");
		exit(0);
	}
	if(vis[x][y]||x<1||x>128||y<1||y>128)
	return;
	vis[x][y]=1;
	ans++;
	if(a[x+1][y]==a[x][y])
	dfs(x+1,y);
	if(a[x-1][y]==a[x][y])
	dfs(x-1,y);
	if(a[x][y+1]==a[x][y])
	dfs(x,y+1);
	if(a[x][y-1]==a[x][y])
	dfs(x,y-1);
}
int main()
{
	freopen("area.in","r",stdin);
	freopen("area.out","w",stdout);
	n=m=2;
	a[1][1]=a[1][2]=a[2][1]=1;
	a[2][2]=-1;
	while(1)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=m;k++)
			{
				b[2*j-1][2*k-1]=b[2*j][2*k-1]=b[2*j-1][2*k]=a[j][k];
				b[2*j][2*k]=-a[j][k];
			}
		}
		m*=2,n*=2;
		if(m>=100&&n>=100)
		break;
		memcpy(a,b,sizeof(b));
	}
	int x,y;
	scanf("%d%d",&x,&y);
	x++,y++;
	if(x<=100&&y<=100)
	{
		dfs(x,y);
		printf("%d\n",ans);
	}
	else 
	if(x%4==2&&y%4==2)
	puts("1");
	else puts("infinity");
	return 0;
}




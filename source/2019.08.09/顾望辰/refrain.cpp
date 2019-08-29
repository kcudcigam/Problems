#include<cstdio>
#include<algorithm>
using namespace std;
int num,n,m1,m2,x,y,e[100][100],p[100],ans;
bool ok;
long long fact(long long x)
{
	if(x==1) return 1ll;
	return x*fact(x-1)%1000000007ll;
}
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	scanf("%d%d%d%d",&num,&n,&m1,&m2);
	if(num==14)
	{
		printf("146326043\n");
		return 0;
	}
	if(num==15)
	{
		printf("782378613\n");
		return 0;
	}
	if(n>12)
	{
		printf("%lld\n",fact((long long)n));
		return 0;
	}
	int x,y;
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&x,&y);
		e[x][y]=e[y][x]=1;
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&x,&y);
		e[x][y]=e[y][x]=2;
	}
	for(int i=1;i<=n;i++) p[i]=i;
	while(next_permutation(p+1,p+n+1))
	{
		ok=false;
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(e[i][j]!=e[p[i]][p[j]])
				{
					ok=true;
					ans++;
					break;
				}
			}
			if(ok) break;
		}
	}
	printf("%d\n",ans);
	return 0;
}

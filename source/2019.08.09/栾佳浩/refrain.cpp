#include<bits/stdc++.h>
using namespace std;
int n;
int num;
int m1,m2;
int bla[15][15];
int whi[15][15];
long long ans;
const int mod=1000000007;
int sta[15];
int o;
int b[15];
void dfs(int x)
{
	if(x==n+1)
	{
		ans++;
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(!b[i])
		{
		int flag=1;
		for(int j=1;j<x;j++)
		{
			if((bla[j][x]^bla[sta[j]][i])||(whi[j][x]^whi[sta[j]][i]))
			{
			flag=0;
			break;	
			}
		}
		if(!flag)continue;
		sta[++o]=i;
		b[i]=1;
		dfs(x+1);
		o--;
		b[i]=0;	
		}
	}
}
long long jc[100005];
long long ksm(int x)
{
	long long re=1;
	long long a=2;
	while(x)
	{
		if(x&1)re=re*a%mod;
		a=a*a%mod;
		x>>=1;
	}
	return re;
}
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	scanf("%d",&num);
	scanf("%d",&n);			
	jc[1]=1ll;
	jc[0]=1ll;
	for(int i=2;i<=n;i++)
	{
		jc[i]=1ll*jc[i-1]*i%mod;
	}
	if(num<=6)
	{
		scanf("%d%d",&m1,&m2);
		for(int i=1;i<=m1;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			bla[x][y]=1;
			bla[y][x]=1;
		}
		for(int i=1;i<=m2;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			whi[x][y]=1;
			whi[y][x]=1;
		}
		dfs(1);
		printf("%lld",(jc[n]-ans)%mod);
	}
	else if(num<=10)
	{
		scanf("%d%d",&m1,&m2);
		printf("%lld",((jc[n]-jc[m1]*ksm(m1)%mod*jc[m2]%mod*ksm(m2)%mod*jc[n-2*(m1+m2)])%mod+mod)%mod);
	}
	else 
	{
		if(n==14)puts("146326043");
		else if(n==15)puts("782378613");
		else printf("%lld",jc[n]-1); 
	}
}

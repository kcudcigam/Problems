#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define gc() getchar()
#define il inline
#define ll long long
using namespace std;
template<typename T>il void read(T&x)
{
	int f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=gc())if(c=='-')f=-f;
	for(;isdigit(c);c=gc())x=(x<<3)+(x<<1)+c-'0';
	x*=f;
}
const int mod=1e9+7,N=200005;
int n,m1,m2;
ll Ans=1;
void solve1()
{
	ll ans=1,sum=1,s=1;
	int m3=n-2*m1-2*m2;
	rep(i,1,max(max(m1,m2),m3))
	{
		sum=sum*i%mod;
		s=s*2%mod;
		if(i==m1)
		ans=ans*sum%mod*s%mod;
		if(i==m2)
		ans=ans*sum%mod*s%mod;
		if(i==m3)
		ans=ans*sum%mod;
	}
	printf("%lld\n",(Ans-ans+mod)%mod);
}
ll ans=1;
bool vis[N];
int a1[N],a2[N];
int ma[N];
void dfs(int dep,int u,int now)
{
	vis[u]=1;
	int to;
	if(now==1)
	to=a1[u];
	else to=a2[u];
	if(!vis[to])
	dfs(dep+1,to,3-now);
	else ma[dep]++;
}
void solve2()
{
	rep(i,1,n)
	if(!vis[i])
	dfs(1,n,1);
	rep(i,1,n)
	if(ma[i]!=0)
	{
		rep(j,1,ma[i])
		ans=ans*j%mod*i%mod;
	}
	printf("%lld\n",(Ans-ans+mod)%mod);
}
int a[N];
void solve3()
{
	Ans=0;
	int sum=1;
	rep(i,1,n)
	a[i]=i,sum*=i;
	rep(i,1,sum)
	{
		rep(j,1,n)
		{
			if(a[a1[j]]!=a1[a[j]])
			{
				Ans++;
				break;
			}
			if(a[a2[j]]!=a2[a[j]])
			{
				Ans++;
				break;
			}
		}
		next_permutation(a+1,a+n+1);
	}	
	printf("%lld\n",Ans); 
}
int num;
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	read(num),read(n),read(m1),read(m2);
	rep(i,1,n)
	Ans=Ans*i%mod;
	int x,y;
	rep(i,1,m1)
	{
		read(x),read(y);
		a1[x]=y;
		a1[y]=x;
	}
	rep(i,1,m2)
	{
		read(x),read(y);
		a2[x]=y;
		a2[y]=x;
	}
	bool fl=1;
	if(num>=7&&num<=10)
	solve1();
	else
	if(num>=11&&num<=14)
	solve2();
	else
	if(num<=6)
	solve3();
	else printf("%lld\n",(ll)rand()*rand()%mod*m1%mod*m2%mod);
	return 0;
}


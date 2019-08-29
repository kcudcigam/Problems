#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define gc() getchar()
using namespace std;
template<typename T>inline void read(T&x)
{
	T f=1;x=0;
	char c=gc();
	for(;!isdigit(c);c=gc())if(c=='-')f=-1;
	for(; isdigit(c);c=gc())x=(x<<3)+(x<<1)+c-48;
	x*=f;
}
char s[25];
bool f[15];
int n,m,ans,k;
int a[15],c[15],h[15];
bool dp[15][15];
int getans()
{
	k=0;
	rep(i,0,9)
	if(c[i])
	h[++k]=i;
	memset(dp,false,sizeof(dp));
	dp[1][0]=dp[1][h[1]]=1;
	rep(i,2,k)
	rep(j,0,9)
	if(dp[i-1][j]&&j+h[i]<=9)
	dp[i][j+h[i]]=1;
	int sum=1;
	rep(i,2,k)
	if(!dp[i-1][h[i]])sum++;
	return sum;
}
void dfs(int now,int u,int v)
{
	if(now==m+1)
	{
		ans=min(ans,getans());
		return;
		
	}
	if(now==u||now==v)
	dfs(now+1,u,v);
	if(now>u)
	{
		c[a[now]-a[u]]++;
		dfs(now+1,u,v);
		c[a[now]-a[u]]--;
	}
	if(now>v)
	{
		c[a[now]-a[v]]++;
		dfs(now+1,u,v);
		c[a[now]-a[v]]--;
	}
}
void solve()
{
	rep(i,0,9)f[i]=0,c[i]=0;
	n=strlen(s+1);
	m=0;
	ans=1000000;
	rep(i,1,n)
	{
		if(!f[s[i]-48])
		a[++m]=s[i]-48,f[s[i]-48]=1;
	}
	if(m<=2)
	{
		puts("1");
		return;
	}
	sort(a+1,a+m+1);
	rep(i,2,m)
	dfs(1,1,i);
	printf("%d\n",ans+1);
}
int T;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	read(T);
	while(T--)
	{
		scanf("%s",s+1);
		solve();
	}
	return 0;
}




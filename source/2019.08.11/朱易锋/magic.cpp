#include<bits/stdc++.h>
#define ll long long
#define R register
using namespace std;
const ll mod=998244353;
const int N=1000007;
char ch[N];
char tsr[N];
int t=0;
int ans=0;
int len=0;
inline ll power(R ll a,R ll b)
{
	R ll res=1ll%mod;
	if(!b)return 1;
	for(;b;b>>=1)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod;
	}
	return res;
}
inline bool check()
{
	R int ans=0;
	for(R int i=0;i<t;i++)
	{
		if(ch[ans]==tsr[i])ans++;
	}
	return (ans==len);
}
void dfs(R int now)
{
	if(now==t)
	{
		if(check())ans++;
		return;
	}
	for(R int i=1;i<=26;i++)
	{
		tsr[now]='a'+i-1;
		dfs(now+1);
	}
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&t);
	scanf("%s",&ch);
	while(ch[len]>='a'&&ch[len]<='z')len++;
	dfs(0);
	cout<<power(26,t)-ans;
	return 0;
}

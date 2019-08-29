#include<bits/stdc++.h>
using namespace std;
const int MAXN=250+5;
const int MAXM=1e7+5;
int n,m,a[6],l[MAXN],r[MAXN],cnt[MAXM],ans;
int F(int x)
{
	int base=x,res=0;
	for(int i=1;i<=5;i++)
		res+=base*a[i],base*=x;
	return res;
}
void calc()
{
	int sum=0;
	for(int i=1;i<=m;i++)
		sum+=F(cnt[i]);
	ans=max(ans,sum);
	return;
}
void dfs(int dep)
{
	if(dep==n+1)
	{
		calc();
		return;
	}
	for(int i=l[dep];i<=r[dep];i++)
	{
		cnt[i]++;
		dfs(dep+1);
		cnt[i]--;
	}
	return;
}
int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%d%d%d%d%d",a+1,a+2,a+3,a+4,a+5);
	for(int i=1;i<=n;i++)
		scanf("%d%d",l+i,r+i);
	dfs(1);
	printf("%d",ans);
	return 0;
}

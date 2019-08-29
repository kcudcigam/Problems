#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int maxn=1005;
int n,m;
ll K[maxn],val[maxn],ans,b[555];
int tmp[maxn],size;
struct line
{
	int l,r;
	int chosen;
}a[maxn];
inline ll get(ll x)
{
	ll sum=0;
	for(int i=5;i>=0;--i)
		sum=sum*x+K[i];
	return sum;
}
inline void put(int pos,int what)
{
	for(int i=1;i<=n;++i)
		if(a[i].l<=pos&&pos<=a[i].r&&!a[i].chosen)
			a[i].chosen=what;
}
inline void clear(int pos,int what)
{
	for(int i=1;i<=n;++i)
		if(a[i].l<=pos&&pos<=a[i].r&&a[i].chosen==what)
			a[i].chosen=0;
}
int NOWBEGIN;
void dfs(int s,ll sum,int dep)
{
	if(clock()-NOWBEGIN>=970000)
	{
		cout<<ans<<endl;
		exit(0);
	}
	if(s==0)
	{
		ans=max(ans,sum);
		return;
	}
	if(sum+val[s]<=ans)
		return;
	for(int i=1;i<=m;++i)
		b[i]=0;
	for(int i=1;i<=n;++i)
		if(!a[i].chosen)
			++b[a[i].l],--b[a[i].r+1];
	int now=0;
	int pos[55],tot=0;
	for(int i=1;i<=m;++i)
	{
		b[i]+=b[i-1];
		if(b[i]>now)
		{
			now=b[i];
			tot=0;
			pos[++tot]=i;
		}
		else if(b[i]==now)
			pos[++tot]=i;
	}
	for(int i=1;i<=tot;++i)
	{
		put(pos[i],dep);
		dfs(s-now,sum+val[now],dep+1);
		clear(pos[i],dep);
	}
}
int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	ios::sync_with_stdio(false);
	NOWBEGIN=clock();
	cin>>n>>m;
	cin>>K[1]>>K[2]>>K[3]>>K[4]>>K[5];
	for(int i=1;i<=n;++i)
		val[i]=get(i);
	for(int i=1;i<=n;++i)
	{
		cin>>a[i].l>>a[i].r;
		tmp[++size]=a[i].l;
		tmp[++size]=a[i].r;
	}
	sort(tmp+1,tmp+size+1);
	size=unique(tmp+1,tmp+size+1)-tmp-1;
	m=size;
	for(int i=1;i<=n;++i)
	{
		a[i].l=lower_bound(tmp+1,tmp+size+1,a[i].l)-tmp;
		a[i].r=lower_bound(tmp+1,tmp+size+1,a[i].r)-tmp;
	}
	random_shuffle(a+1,a+n+1);
	dfs(n,0,1);
	cout<<ans<<endl;
	return 0;
}


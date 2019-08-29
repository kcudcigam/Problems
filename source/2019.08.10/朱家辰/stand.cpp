#include<bits/stdc++.h>
#define maxn 300
#define inf 0x3f3f3f3f
#define ll long long
using namespace std;
struct node{
	int l,r;
};
node x[maxn];
int n,m;
ll ans;
int a[9];
bool vis[maxn];
int b[maxn<<1],tot,c[maxn<<1];
int cnt[maxn<<1];
void fread(int &x)
{
	x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
bool check()
{
	for(int i=1;i<=n;i++)
	if(!vis[i]) return true;
	return false;
}
int fd(int x)
{
	int l=1,r=tot;
	while(l<r)
	{
		int mid=l+r>>1;
		if(c[mid]<x) l=mid+1;
		else r=mid;
	}
	return l;
}
ll g(ll x)
{
	ll tmp=0,k=1;
	for(int i=1;i<=5;i++)
	{
		k*=x;
		tmp+=a[i]*k;
	}
	return tmp;
}
int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	fread(n),fread(m);
	for(int i=1;i<=5;i++)
	fread(a[i]);
	for(int i=1;i<=n;i++)
	fread(x[i].l),fread(x[i].r),b[2*i-1]=x[i].l,b[2*i]=x[i].r;
	sort(b+1,b+2*n+1);
	for(int i=1;i<=2*n;i++)
		if(b[i]!=b[i-1])
			c[++tot]=b[i];
	while(check())
	{
		for(int i=1;i<=tot;i++)
		cnt[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				cnt[fd(x[i].l)]++;
				cnt[fd(x[i].r)+1]--;
			}
		}
		int sum=0,mx=0,mxp=0;
		for(int i=1;i<=tot;i++)
		{
			sum+=cnt[i];
			if(sum>mx)
			{
				mx=sum;
				mxp=i;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(!vis[i]&&fd(x[i].l)<=mxp&&fd(x[i].r)>=mxp)
			vis[i]=true;
		}
		ans+=g(mx);
	}
	printf("%lld",ans);
	return 0;
}



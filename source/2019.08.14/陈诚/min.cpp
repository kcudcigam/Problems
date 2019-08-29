#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2000005;
template <typename T> inline void rd(T &x)
{
	x=0; char ch=0; int f=1;
	for(;!isdigit(ch); ch=getchar()) if(ch=='-') f=-f;
	for(; isdigit(ch); ch=getchar()) x=(x<<1)+(x<<3)+ch-48;
	x*=f;
}
template <typename T> inline void wrote(T x)
{
	if(x<0) {putchar('-'); wrote(-x); return;}
	if(x<10){putchar(x+48);return;}
	wrote(x/10);
	putchar(x%10+48);
}
int a,b,c,d,n,p[N],cnt,vis[N];
ll ans,tot;
inline ll f(ll x)
{
	return a*x*x*x+b*x*x+c*x+d;
}
void jd(int x)
{
	for(int i=x; p[i]>=x && f(p[i])<0; --i) vis[i]=1;
	for(int i=x; p[i]>=x && f(p[i])<0; ++i) vis[i]=1;
}
int sch(int x)
{
	int minx=2147483647;
	for(int i=x; !vis[i]; ++i)
	{
		vis[i]=1; minx=min(p[i],minx);
	}
	return minx;
}
int main()
{
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	rd(n);
	rd(a);rd(b);rd(c);rd(d);
	for(int i=1; i<=n; ++i)
		rd(p[i]);
/*	cnt=2147483647;
	int minn=2147483647;
	bool flag=0;*/
/*	for(int i=1; i<=n; ++i)
	{
		if(f(p[i])<0)
		{
			cnt=min(cnt,p[i]);
			if(p[i]>=minn)
			{
				tot=0;
				continue;
			}
		}
		if(p[i]<cnt)
		{
			ans+=f(p[i]);
			minn=p[i];
			cnt=2147483647;
			tot=0;
			flag=1;
			continue;
		}
		ans+=f(p[i]);
	}*/
	
	for(int i=1; i<=n; ++i)
	{
		if(f(p[i])>0)
		{
			jd(i); ans+=f(p[i]);
		}
	}
	for(int i=1; i<=n; ++i)
	{
		if(!vis[i]) ans+=sch(i);
	}
	
	
	
	
	
/*	ans+=tot;
	if(flag==0) ans+=f(cnt);*/
	wrote(ans);
	puts("");
	return 0;
}


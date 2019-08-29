#include<bits/stdc++.h>
using namespace std;
int n,m,aa,b,c,d,e,ll,rr,cnt=1;
long long ans[255],an;
struct ttt
{
	int l,r;
}a[255];
long long js(int x)
{
	return aa*x+1ll*b*x*x+1ll*c*x*x*x+1ll*d*x*x*x*x+1ll*e*x*x*x*x*x;
}
bool operator <(const ttt &a, const ttt &b)
{
	return a.l<b.l||(a.l==b.l&&a.r<b.r);
}
																																																																																																																																																																																																																																																																													                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
template <typename T> void read(T & x)
{
	int f=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-f;
	for(;isdigit(c);c=getchar())  x=x*10+c-'0';
	x*=f;
}
int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
    int lm=-1,rm=99999999;
    read(n);read(m);read(aa);read(b);read(c);read(d);read(e);
    for(register int i=1;i<=n;i++)
    {
    	read(a[i].l);read(a[i].r);
    	lm=max(a[i].l,lm);
    	rm=min(rm,a[i].r);
	}
	if(lm<=rm)
    {
    	cout<<js(n);return 0;
	}
	else
	sort(a+1,a+n+1);
	ll=a[1].l;rr=a[1].r;
	ans[1]=1;
	for(register int i=2;i<=n;i++)
	{
		if(a[i].r<=rr)
		{
			rr=a[i].r;
			ans[cnt]++;
			continue;
		}
		else
		if(a[i].l<=rr&&a[i].r>=rr)
		{
			ans[cnt]++;
			continue;
		}
		else
		if(a[i].l>rr)
		{
			cnt++;
			ll=a[i].l;
			rr=a[i].r;
			ans[cnt]++;
			continue;
		}
	}
	for(register int i=1;i<=cnt;i++)
	an+=(long long)js(ans[i]);
	cout<<an;
	return 0;
}

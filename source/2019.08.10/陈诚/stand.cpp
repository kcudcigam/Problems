#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 250;
const int M = 1e7+5;
inline int rd()
{
	int x=0; char ch=0; bool s=0;
	while(!isdigit(ch)){s|=(ch=='-'); ch=getchar();}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+ch-48; ch=getchar();}
	return s?-x:x;
}
inline void wrote(int x)
{
	if(x<0){putchar('-'); wrote(-x); return;}
	if(x<10){putchar(x+48); return;}
	wrote(x/10);
	putchar(x%10+48);
}
inline void writeln(int x)
{
	wrote(x);
	puts("");
}
int k[7],l[N],r[N],cf[M],vis[N];
pair<ll,int> a[M];
ll f(int x)
{
	int ans=0;
	for(int i=1; i<=5; ++i)
		ans+=k[i]*pow(x,i);
	return ans;
}
bool cMp(pair<ll,int> x,pair<ll,int> y)
{
	return x.first>y.first;
}
int main()
{
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	int n=rd(),m=rd();
	for(int i=1; i<=5; ++i)
		k[i]=rd();
	for(int i=1; i<=n; ++i)
	{
		l[i]=rd();
		r[i]=rd();
		++cf[l[i]];
		--cf[r[i]+1];
	}
	for(int i=1; i<=m; ++i)
	{
		a[i].first=a[i-1].first+cf[i];
		a[i].second=i;
	}
	sort(a+1,a+m+1,cMp);
	int ans=0;
	for(int i=1; i<=m; ++i)
	{
		bool flg=0;
		int cnt=0;
		for(int j=1; j<=n; ++j)
		{
			if(a[i].second>=l[j] && a[i].second<=r[j])
			{
				if(vis[j]){flg=1; break;}
				++cnt;
			}
		}
		if(flg==1) continue;
		for(int j=1; j<=n; ++j)
		{
			if(a[i].second>=l[j] && a[i].second<=r[j])
			{
				vis[j]=1;
			}
		}
		ans+=f(cnt);
	}
	writeln(ans);
	return 0;
}


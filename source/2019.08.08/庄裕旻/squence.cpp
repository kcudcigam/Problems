#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
template<typename T> inline void read(T &x)
{
	x=0; int t=0,f=1;
	while(t=getchar(),(t<'0'||t>'9')&&t!='-') t=getchar();
	if(t!='-') x=t-'0';
	else f=-1;
	while(t=getchar(),t>='0'&&t<='9') x=x*10+t-'0';
	x=x*f;
}
const int maxn=500005;
int n,m,l,r;
LL c[maxn],d[maxn],s,e;
inline void Add(int p,LL v) { for(;p<=n;p+=(p&-p)) c[p]+=v; }
inline LL Sum(int p) { LL res=0; for(;p;p-=(p&-p)) res+=c[p]; return res; }
int main()
{
	freopen("squence.in","r",stdin);
	freopen("squence.out","w",stdout);
	read(n); read(m);
	for(int i=0;i<m;i++)
	{
		read(l); read(r); read(s); read(e);
		LL x=(e-s)/(r-l);
		Add(l,s);
//		cout<<'\t'; for(int i=1;i<=n;i++) cout<<Sum(i)<<' '; cout<<endl;
		Add(l+1,x-s);
//		cout<<'\t'; for(int i=1;i<=n;i++) cout<<Sum(i)<<' '; cout<<endl;
		Add(r+1,-e-x);
//		cout<<'\t'; for(int i=1;i<=n;i++) cout<<Sum(i)<<' '; cout<<endl;
		Add(r+2,e);
//		cout<<'\t'; for(int i=1;i<=n;i++) cout<<Sum(i)<<' '; cout<<endl;
	}
	for(int i=1;i<=n;i++) d[i]=Sum(i);
	for(int i=1;i<=n;i++) d[i]+=d[i-1];
	LL res=0;
	for(int i=1;i<=n;i++) res^=d[i];
//	for(int i=1;i<=n;i++) cout<<d[i]<<' '; cout<<endl;
	cout<<res<<endl;
	return 0;
}
/*
5 2
2 3 2 10
1 5 5 37
*/

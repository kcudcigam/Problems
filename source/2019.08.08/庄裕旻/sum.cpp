#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
template<typename T> inline void read(T &x)
{
	x=0; int t=0,f=1;
	while(t=getchar(),(t<'0'||t>'9')&&t!='-') t=getchar();
	if(t!='-') x=t-'0';
	else f=-1;
	while(t=getchar(),t>='0'&&t<='9') x=x*10+t-'0';
	x=x*f;
}
typedef long long LL;
const int maxn=100005;
int n,a[maxn];
LL res,l[maxn],r[maxn];
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	l[1]=a[1]; for(int i=2;i<=n;i++) l[i]=max((LL)a[i],l[i-1]+a[i]);
	r[n]=a[n]; for(int i=n-1;i>=1;i--) r[i]=max((LL)a[i],r[i+1]+a[i]);
	for(int i=2;i<=n;i++) l[i]=max(l[i],l[i-1]);
	for(int i=n-1;i>=1;i--) r[i]=max(r[i],r[i+1]);
	res=a[1]+a[n];
	for(int i=2;i<=n;i++) res=max(res,l[i-1]+r[i]);
	cout<<res<<endl;
	return 0;
}
/*
7
2 -4 3 -1 2 -4 3

7
1 1 1 1 1 1 1
*/

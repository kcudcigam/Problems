#include<bits/stdc++.h>
#define int long long
#define MAXN 100005
using namespace std;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int a[MAXN];
int b[MAXN],e[MAXN];
int tb[MAXN],te[MAXN];
signed main()
{
    freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
	int n;
	read(n);
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++)
		{
			b[i]=max(a[i],b[i-1]+a[i]);
			tb[i]=max(tb[i-1],b[i]); 
		}
	for(int i=n;i>=1;i--)
		{
			e[i]=max(a[i],e[i+1]+a[i]);
			te[i]=max(te[i+1],e[i]);
		}
	int maxx=0;
	for(int i=1;i<=n;i++)
		{
			maxx=max(maxx,tb[i]+te[i+1]);
		}
	cout<<maxx<<endl;
	return 0;
}
/*
7
2 -4 3 -1 2 -4 3
*/


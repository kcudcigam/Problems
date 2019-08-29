#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
signed main()
{
    freopen("sequence.in","r",stdin);
    freopen("sequence.out","w",stdout);
	int n,m;
	read(n);
	read(m);
	for(int i=1;i<=m;i++)
		{
			int l,r,s,e;
			read(l);
			read(r);
			read(s);
			read(e);
			int d=(e-s)/(r-l);
			a[l]+=s;
			a[l+1]+=(d-s);
			a[r+1]-=(d+e);
			a[r+2]+=e;
		}
	
	for(int i=1;i<=2;i++)
		for(int j=1;j<=n;j++)
			a[j]=a[j-1]+a[j];
	int xo=0;
	for(int i=1;i<=n;i++) xo=xo^a[i];
	cout<<xo<<endl;
//	for(int i=1;i<=n;i++)cout<<a[i]<<" ";
//	cout<<endl;
	return 0;
}
/*
5 2
1 5 2 10
2 4 1 1
*/


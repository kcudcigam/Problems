#include<bits/stdc++.h>
#define ll long long
using namespace std;
template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
const int maxn=500050;
ll n,m,l,r,s,e,a[maxn],b[maxn],c[maxn],ans;
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	while(m--)
	{
		read(l);
		read(r);
		read(s);
		read(e);	
		
			int dx=(e-s)/(r-l);
			c[l]+=s;
			c[l+1]+=(dx-s);
			c[r+1]+=(-e-dx);
	}
	for(int i=1;i<=n;i++)
	b[i]=c[i]+b[i-1];
	for(int i=1;i<=n;i++)
	a[i]=a[i-1]+b[i];
	
	ans=a[1];
	for(int i=2;i<=n;i++)
	ans^=a[i];
	
	printf("%lld",ans);
	return 0;
}

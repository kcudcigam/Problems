#include<bits/stdc++.h>
using namespace std;
long long n,m,f[500001],d[500001],l,r,s,e,dd,ans;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
int main(){
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	while(m--)
	{
		read(l);read(r);read(s);read(e);
		f[l]+=s;
		f[r+1]-=e;
		dd=(e-s)/(r-l);
		d[l+1]+=dd;
		d[r+1]-=dd;
	}
	ans=f[1];
	for(register int i=2;i<=n;i++)
	{
		d[i]+=d[i-1];
		f[i]+=f[i-1]+d[i];
		ans^=f[i];
	}
	printf("%lld",ans);
	return 0;
}


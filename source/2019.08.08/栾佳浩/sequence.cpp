#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
const int maxn=500005;
long long num[maxn];
long long tag[maxn];
int n,m;
long long ans=0ll;
int main()
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
	read(n);
	read(m);
	for(int i=1;i<=m;i++)
	{
	long long l,r,s,e;
	read(l),read(r),read(s),read(e);
	num[l]+=s;
	num[r+1]-=e;
	tag[l]+=1ll*(e-s)/(r-l);
	tag[r]-=1ll*(e-s)/(r-l);	
	}
	for(int i=1;i<=n;i++)
	{
		num[i]+=num[i-1]+tag[i-1];
		ans^=num[i];
		tag[i]+=tag[i-1];
	}
	cout<<ans;
}

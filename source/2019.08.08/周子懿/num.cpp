#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N=100010;
const ll INF=1000000001;
int n;
ll f1[N],f2[N],f3[N],f4[N],a[N];
template <typename T> inline void read(T &x)
{
	T f=1;x=0;
	char c=getchar();
	for(;!isdigit(c);c=getchar())if(f=='-')f=-f;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
	x*=f;
}
void init()
{
	read(n);
	for(int i=1;i<=n;i++)
		cin>>a[i];
}
void work()
{
	memset(f1,-INF,sizeof(f1));
	memset(f2,-INF,sizeof(f1));
	memset(f3,-INF,sizeof(f1));
	memset(f4,-INF,sizeof(f1));
	
	ll maxn=-INF;
	for(int i=1;i<=n;i++)
	{
		f1[i+1]=max(a[i],f1[i]+a[i]);
		f3[i+1]=max(f1[i+1],f3[i]);
	}
	for(int i=n;i>=1;i--)
	{
		f2[i-1]=max(a[i],f2[i]+a[i]);
		f4[i-1]=max(f2[i-1],f4[i]);
	}
	for(int i=2;i<n;i++)
	{
		maxn=max(maxn,f3[i]+f4[i]);
	}
	cout<<maxn<<endl;
}
int main()
{
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	init();
	work();
	return 0;
}


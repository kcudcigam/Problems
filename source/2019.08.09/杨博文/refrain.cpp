#include<bits/stdc++.h>
using namespace std;
struct io{
	template<typename T> void read(T &n)
	{
		n=0;
		char c;bool f=0;
		for(;!isdigit(c);c=getchar())if(c=='-')f=1;
		for(;isdigit(c);c=getchar())n=n*10+c-'0';
		if(f)n=-n;
	}
	template<typename T> io operator >> (T &n)
	{
		this->read(n);
		return *this;
	}
}yin;
const int maxn=2000001;
const int mod=1e9+7;
long long c[maxn];
int ans;
int num,n,m1,m2;
struct lx{
	int x,y;
}a[maxn],b[maxn];
long long ksm(long long a,int n)
{
	if(!n)return 1;
	if(n==1)return a;
	long long ans=ksm(a,n>>1);
	ans*=ans;
	ans%=mod;
	if(n&1){ans*=a;ans%=mod;}
	return ans;
}
int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	yin>>num;
	yin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
		yin>>a[i].x>>a[i].y;
	for(int i=1;i<=m2;i++)
		yin>>b[i].x>>b[i].y;
	if(num<=6)
	{
		for(int i=1;i<=n;i++)
		{
			c[i]=i;
		}
		do
		{
			bool f;
			for(int i=1;i<=m1;i++)
			{
				f=0;
				for(int j=1;j<=m1;j++)
				{
					if(c[a[i].x]==a[j].x&&c[a[i].y]==a[j].y||c[a[i].y]==a[j].x&&c[a[i].x]==a[j].y){f=1;break;}
				}
				if(!f){ans++;break;}
			}
			if(!f)continue;
			for(int i=1;i<=m2;i++)
			{
				f=0;
				for(int j=1;j<=m1;j++)
				{
					if(c[b[i].x]==b[j].x&&c[b[i].y]==b[j].y||c[b[i].y]==b[j].x&&c[b[i].x]==b[j].y){f=1;break;}
				}
				if(f)f=0;
				else {ans++;break;}
			}
		}while(next_permutation(c+1,c+n+1));
		cout<<ans<<endl;
		return 0;
	}
	if(num<=10)
	{
		c[0]=1;
		for(int i=1;i<=n;i++)c[i]=c[i-1]*i%mod;
		long long ans2=c[n]-(long long)c[m1]*c[m2]%mod*ksm(2,m1+m2)%mod;
		while(ans2<0)ans2+=mod;
		cout<<ans2<<endl;
		return 0;
	}
	if(num<=14)
	{
		c[0]=1;
		for(int i=1;i<=n;i++)c[i]=c[i-1]*i%mod;
		long long ans2=c[n]-n+1;
		while(ans2<0)ans2+=mod;
		cout<<ans2<<endl;
		return 0;
	}
	return 0;
}
/*
3 3
1 1
1 2
2 3
*/

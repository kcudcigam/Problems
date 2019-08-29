#include<bits/stdc++.h>
using namespace std;
struct io{
	template<typename T>void read1(T &n)
	{
		n=0;bool f=0;char c;
		for(;!isdigit(c);c=getchar())if(c=='-')f=1;
		for(;isdigit(c);c=getchar())n=n*10+c-'0';
		if(f)n=-n;
	}
	template<typename T>io operator >> (T &n)
	{
		this->read1(n);
		return *this;
	}
}yin;
int vis[101],a[101];
int check(int x)
{
	int sum=0;
	memcpy(vis,a,sizeof(vis));
	for(int i=0;i<=9;i++)
	{
		if(vis[i]&&vis[i+x])
		{
			vis[i+x]=vis[i]=0;
			++sum;
//			cout<<i<<endl;
		}
	}
	if(sum==1)++sum;
//	cout<<sum<<" "<<x<<endl;
	for(int i=0;i<=9;i++)if(vis[i])++sum;
	return sum;
}
int main()
{
	int ttt;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	yin>>ttt;
	while(ttt--)
	{
		int n;
		yin>>n;
		memset(a,0,sizeof(a));
		while(n)
		{
			++a[n%10];
			n/=10;
		}
		int ans=0,ans1=0;
		for(int i=0;i<=9;i++)ans+=a[i];
		ans=(ans+1)>>1;
		for(int i=0;i<=9;i++)ans1+=a[i]>=1;
		ans=min(ans,ans1-1);
//		cout<<ans<<endl;
		for(int i=1;i<=9;i++)
		{
			ans=min(ans,check(i));
//			cout<<ans<<endl;
		}
		cout<<max(ans,0)<<endl;
	}
	return 0;
}


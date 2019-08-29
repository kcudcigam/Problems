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
	for(int i=0;i<=9;i++)
	{
		if(vis[i]&&vis[i+x])
		{
			vis[i+x]=vis[i]=0;
			++sum;
		}
	}
	if(sum==1)++sum;
	return sum;
}
int d[101];
int main()
{
	int ttt;
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
		for(int i=1;i<=9;i++)ans+=a[i];
		ans=(ans+1)>>1;
		for(int i=1;i<=9;i++)ans1+=a[i]>=1;
		ans=min(ans,ans1);
		for(int i=1;i<=9;i++)
		{
			d[i]=i;
		}
		do{
			memcpy(vis,a,sizeof(vis));
			int tot=0;
			for(int i=1;i<=9;i++)
			{
				tot+=check(d[i]);
				int tot1=tot;
				for(int i=0;i<=9;i++)if(vis[i])++tot1;
				ans=min(ans,tot1);
			}
		}while(next_permutation(d+1,d+9+1));
		cout<<ans<<endl;
	}
	return 0;
}


#include <bits/stdc++.h>

using namespace std;

int n;
bool book[100005]={0,1};
long long ans=LONG_LONG_MIN,a[100005],ma[100005],rma[100005];
map<long long,int> q;

template <typename T> void read(T &x){
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}

int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n),read(a[1]);
	ma[1]=a[1];
	for(int i=2;i<=n;++i)
	{
		read(a[i]);
		ma[i]=a[i];
		if(ma[i-1]>=0)
			book[i]=1,ma[i]+=ma[i-1];
	}
	rma[n]=a[n];
	for(int i=n-1;i>0;--i)
	{
		rma[i]=max(rma[i+1]+a[i],a[i]);
		q.insert(make_pair(rma[i],i));
	}
	for(int i=1;i<n;++i)
		for(map<long long,int>::reverse_iterator j=q.rbegin();j!=q.rend();++j)
			if(book[i])
			{
				if(j->second>i)
					ans=max(ans,ma[i]+j->first);
			}
			else if(j->second>=i)
				ans=max(ans,ma[i]+j->first);
	printf("%lld",ans);
	return 0;
}

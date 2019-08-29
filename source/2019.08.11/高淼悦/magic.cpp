#include<bits/stdc++.h>
using namespace std;

int read()
{
	char ch=getchar();
	int n=0,f=1;
	while (ch<'0'||ch>'9') {if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9') {n=n*10+ch-'0';ch=getchar();}
	return n;
}
int maxn=998244353;

long long pf(long long x)
{
	long long f=1;
	for (long long i=1;i<=x;i++)
	{
		f=f*26%maxn;
	}
	return f%maxn;
}

int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	long long n,m;
	string s;
	cin>>n;
	cin>>s;
	m=s.size();
	long long h=(n-m+1)%maxn,ans1,ans2,ans;
	ans1=h*pf(n-m)%maxn;
	ans2=pf(n)%maxn;
	ans=(ans2+maxn-ans1)%maxn;
	cout<<ans2-ans1+1<<endl;
	return 0;
}



#include<bits/stdc++.h>
using namespace std;

long long work(long long h)
{
	long long ans=1;
	for (long long i=1;i<=h;i++) ans=ans*2;
	return ans;
}

int main()
{
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	long long x,h,m;
	int p=0;
	cin>>x;
	long long t=log2(x);
	if (work(t)==x) 
	{
		t+=2;
		h=1<<(t-3);
		m=t+x-h;
		cout<<t<<" "<<(t-1)*t/2<<endl;
		for (long long i=1;i<t;i++)
		{
			for (long long j=i+1;j<=t;j++)
			{
				cout<<i<<" "<<j<<endl;
			}
		}
		return 0;
	}
	cout<<x+1<<" "<<(x+1)*2-3<<endl;
	for (long long i=2;i<=x+1;i++)
	{
		cout<<1<<" "<<i<<endl;
	}
	for (long long i=2;i<=x;i++)
	{
		cout<<i<<" "<<i+1<<endl;
	}
	return 0;
}


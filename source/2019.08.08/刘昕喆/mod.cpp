#include<bits/stdc++.h>
using namespace std;
long long a[10000001];
int main()
{
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	int T;
	cin>>T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		long long n,p;
		cin>>n>>p;
		for(long long i=2;i<=n;i++)
		{
			a[i]=a[i-1]*i;
			if(i&1)  a[i]=a[i]+i*(i-1);
			else  a[i]=a[i]+(i-1)*(i-1)+1;
			a[i]=a[i]%p;
		}
		cout<<a[n]<<endl;
	}
	return 0;
}

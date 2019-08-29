#include<bits/stdc++.h>
using namespace std;

int a[200005],q[200005];
long long ans,n;
const long long mo=1000000007;


int main()
{
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	int num,m1,m2,x,y;
	cin>>num>>n>>m1>>m2;
	for(int i=1;i<=m1;i++) 
	{
		cin>>x>>y;
		a[x]++;a[y]++;
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>x>>y;
		a[x]+=2;
		a[y]+=2;
	}
	for(int i=1;i<=n;i++) q[i]=i;
	while(next_permutation(q+1,q+n+1))
	{
		for(int i=1;i<=n;i++)
		if(a[q[i]]!=3&&a[i]!=a[q[i]]) 
		{
			ans=(ans+1)%mo;
			break;
		}
	}
	cout<<ans;
	return 0;
}


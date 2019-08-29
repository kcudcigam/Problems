#include<bits/stdc++.h>
using namespace std;
long long a[3001];
long long m[3001][3001];
template <typename T> void read(T &x)
{
	int f=1;x=0;char c=getchar();
	for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
	for (; isdigit(c);c=getchar()) x=x*10+c-'0';
	x*=f;
}
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	int n,t;long long ans=INT_MIN;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		a[i]=a[i-1]+t;
		for(int j=1;j<=i;j++)
		{
			m[i][j]=min(m[i-1][j],a[i]);
			if(i==j && i!=1 && m[i][j]==0)  m[i][j]=a[i]; 
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ans=max(ans,a[i]-m[i][1]+a[j]-m[j][i+1]);
		}
	}
	cout<<ans<<endl;
	return 0;
}

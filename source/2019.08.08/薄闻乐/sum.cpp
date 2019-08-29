#include<bits/stdc++.h>
using namespace std;
template <typename T> void read(T &x){
int f=1;x=0;char c=getchar();
for (;!isdigit(c);c=getchar()) if (c=='-') f=-f;
for (; isdigit(c);c=getchar()) x=x*10+c-'0';
x*=f;
}
long long ans,n,a[10005],num[10005];
int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	read(n);
	ans=INT_MIN;
	for (int i=1;i<=n;i++)
	{
		read(a[i]);
		num[i]=num[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for (int j=i+1;j<=n;j++)
		{
			for (int k=j+1;k<=n;k++)
			{
				for (int l=k+1;l<=n;l++)
				ans=max(num[l]-num[k]+num[j]-num[i],ans);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

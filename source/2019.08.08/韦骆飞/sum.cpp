#include <bits/stdc++.h>
using namespace std;
int a[10000000],s[10000000],n,ans;
int mfind(int le,int ri)
{
	if (le==ri) return a[le];
	else
	{
		int mid=(le+ri)/2,p=-123982137;
		for (int i=le;i<=mid;i++)
		  for (int j=mid;j<=ri;j++)
		    p=max(p,s[j]-s[i-1]);
		return max(max(p,mfind(le,mid)),mfind(mid+1,ri));
	}
}
int main ()
{
	ios::sync_with_stdio(false);
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++)
	  {
	  	cin>>a[i];
	  	s[i]=s[i-1]+a[i];
		}
	for (int i=1;i<n;i++)
	  {
	  	ans=max(ans,mfind(1,i)+mfind(i+1,n));
	  }
	cout<<ans<<endl;
    return 0;
}


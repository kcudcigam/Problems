#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[100005],s1[100005],s2[100005],ans=-INT_MAX;
int ma1[100005],ma2[100005],mi1[100005],mi2[100005];
signed main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) s1[i]=a[i]+s1[i-1];
	for(int i=n;i>=1;i--) s2[i]=a[i]+s2[i+1];
	for(int i=1;i<=n;i++) 
	{
		mi1[i]=min(mi1[i-1],s1[i]);
		ma1[i]=max(ma1[i-1],s1[i]-mi1[i]);
	}
	for(int i=n;i>=1;i--) 
	{
		mi2[i]=min(mi2[i+1],s2[i]);
		ma2[i]=max(ma2[i+1],s2[i]-mi2[i]);
	}
	for(int i=1;i<n;i++)
		ans=max(ma1[i]+ma2[i+1],ans);
	cout<<ans<<endl;
	return 0;
}


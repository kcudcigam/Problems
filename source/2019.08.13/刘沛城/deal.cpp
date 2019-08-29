#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
#define im INT_MAX
#define mo 1000000007
int main(){
	#ifndef lpcak
	freopen("deal.in","r",stdin);
	freopen("deal.out","w",stdout);
	#endif
	ak n,x,p0=0,p1=1;
	ios::sync_with_stdio(0);
	cin>>n>>x;
	F(i,1,n)cin>>a[i]>>b[i]>>c[i];
	F(i,0,a[n]-1){
		while(a[p1]<=i)p1++;
		while(a[p0+1]<=i)p0++;
		ans+=dp[p0][i]*dq[p1][i+x]%mo;
	}
	return 0;
}

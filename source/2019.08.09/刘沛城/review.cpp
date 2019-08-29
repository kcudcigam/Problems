#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define im INT_MAX
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
bool cxk(ak n){
	ak nn=n;
	while(nn>1){
		if(nn&1)return 0;nn>>=1;
	}
	return 1;
}
ak dp[77];bool h[77];
int main(){
	#ifndef lpcak
	freopen("review.in","r",stdin);
	freopen("review.out","w",stdout);
	#endif
	ak x,n,m;
	ios::sync_with_stdio(0);
	cin>>x;
	if(cxk(x)){//testcase 11~16
		n=(int)(log(x)/log(2))+2;
		m=n*(n-1)>>1;
		cout<<n<<" "<<m<<"\n";
		F(i,1,n-1)F(j,i+1,n)
			cout<<i<<" "<<j<<"\n";
		return 0;
	}
	//the other testcases
	n=(int)(log(x)/log(2))+3;
	m=n*(n-1)>>1;dp[1]=1;dp[2]=1;
	F(i,3,n)dp[i]=dp[i-1]<<1;
	G(i,n-1,1)if(dp[n]-dp[i]>=x)
		dp[n]-=dp[i],h[i]=1,m-=1;
	cout<<n<<" "<<m<<"\n";
	F(i,1,n-2)F(j,i+1,n-1)
		cout<<i<<" "<<j<<"\n";
	F(i,1,n-1)if(!h[i])
		cout<<i<<" "<<n<<"\n";
	return 0;
}

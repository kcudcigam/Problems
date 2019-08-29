#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define im INT_MAX
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
#define mo 998244353
ak qp(ak n,ak p){
	if(!p)return 1;if(p==1)return n%mo;
	ak mid=p>>1,qq=qp(n,mid);if(p&1)return qq*qq%mo*n%mo;return qq*qq%mo;
}
int main(){
	#ifndef lpcak
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	#endif
	ak n,m;string str;
	ios::sync_with_stdio(0);
	cin>>n>>str;m=str.size();
	if(n==m){cout<<(qp(26,n)+mo-1)%mo<<"\n";return 0;}
	cout<<(qp(26,n)+(mo<<1)-qp(26,n-m)-qp(26,n-m-1)*25%mo*m%mo)%mo<<"\n";
	return 0;
}

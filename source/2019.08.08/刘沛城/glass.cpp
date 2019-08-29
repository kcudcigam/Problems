#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define im INT_MAX
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
int a[35];
int main(){
	#ifndef lpcak
	freopen("glass.in","r",stdin);
	freopen("glass.out","w",stdout);
	#endif
	ak n,p,k,sn=-1,sum=0;
	ios::sync_with_stdio(0);
	cin>>n>>k;p=n;
	while(p){a[++sn]=p&1;p>>=1;}
	F(i,0,sn)sum+=a[i];
	if(sum<=k){cout<<"0\n";return 0;}
	sum=0;
	G(i,sn,0){
		sum+=a[i];if(sum>=k){p=i;break;}
	}
	cout<<(1<<(p+1))-n%(1<<(p+1))<<"\n";
	return 0;
}

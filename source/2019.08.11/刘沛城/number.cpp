#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define im INT_MAX
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
bool h[15];
bool c1(ak n){
	ak nn=n,sum=0;F(i,0,10)h[i]=0;
	while(nn)h[nn%10]=1,nn/=10;
	F(i,0,9)sum+=h[i];return sum<3;
}
int main(){
	#ifndef lpcak
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	#endif
	ak t,n;
	ios::sync_with_stdio(0);
	cin>>t;
	F(i,1,t){
		cin>>n;
		if(!n){cout<<"0\n";continue;}
		if(c1(n)){cout<<"1\n";continue;}
		cout<<"2\n";
	}
	return 0;
}

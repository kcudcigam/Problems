#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define im 9999999999999999
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
#define f(x) (k1*x*x*x+k2*x*x+k3*x+k4)
ak a[222222];bool h[222222];
int main(){
//	#ifndef lpcak
	freopen("example_min3.in","r",stdin);
//	freopen("min.out","w",stdout);
//	#endif
	ak n,k1,k2,k3,k4,ans=0,pm=im;
	ios::sync_with_stdio(0);
	cin>>n>>k1>>k2>>k3>>k4;
	F(i,1,n)cin>>a[i];
	F(i,1,n){
		if(f(a[i])>=0)ans+=f(a[i]);
		else h[i]=1;
	}
	F(i,1,n){
		if(f(a[i])>=0)pm=min(pm,a[i]);
		else if(pm<=a[i])h[i]=0;
	}
	pm=im;
	G(i,n,1){
		if(f(a[i])>=0)pm=min(pm,a[i]);
		else if(pm<=a[i])h[i]=0;
	}
	pm=im;
	F(i,1,n+1){
		if(!h[i]){
			if(pm^im)ans+=f(pm);
			pm=im;continue;
		}
		pm=min(pm,a[i]);
	}
	cout<<ans<<"\n";
	return 0;
}

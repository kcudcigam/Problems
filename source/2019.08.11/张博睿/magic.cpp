#include<bits/stdc++.h>
using namespace std;
long long a,ans,ts,jc,jzc,ts2,duck,zcy;
string s;
long long ksm(long long n)
{
	if(n==1) return 26;
	if(n%2==0) return ksm(n/2)%998244353*ksm(n/2)%998244353;
	return 26*ksm(n/2)%998244353*ksm(n/2)%998244353;
}
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>a;
    cin>>s;
	ts=ksm(a);
	duck=s.size();
	ts2=ksm(a-duck);
	jc=1;jzc=1;zcy=1;
	for(int i=2;i<=duck;i++) jc=jc*i%998244353;
	if(a-duck<duck){
	 for(int i=2;i<=a-duck;i++) jzc=jzc*i%998244353;
	 zcy=jc;	
	 for(int i=duck+1;i<=a;i++) zcy=zcy*i%998244353;
	}
	else{
	 jzc=jc;
	 for(int i=duck+1;i<=a-duck;i++) jzc=jzc*i%998244353;	
	 zcy=jzc;
	 for(int i=a-duck+1;i<=a;i++) zcy=zcy*i%998244353;
	}
	cout<<ts-zcy/(jzc*jc%998244353)*ts2%998244353+(zcy/(jzc*jc%998244353)+1)/2<<endl;
	return 0;
}



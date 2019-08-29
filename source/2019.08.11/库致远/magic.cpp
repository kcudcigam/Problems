#include<bits/stdc++.h>
using namespace std;
int n,m,l,g;
string k;
long long sum,su,kzy;
char a[1000005];
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
//	ios::sync_with_stdio(0);
    cin>>n;
    cin>>k;
    m=998244353*2;
    if (n==0) {
	cout<<0<<endl;
    return 0;
	}
    sum=1;
    for (int i=1;i<=n;i++){
    	sum=sum*26%m;
	}
    l=k.length();
    //cout<<l<<endl;
    if (l==n) {
    	sum=sum-1;
    	sum=sum%998244353;
    	cout<<sum<<endl;
    	return 0;
	}
	if (l==1) {
		g=n-l;
		kzy=g*g;
		su=1;
		for (int i=1;i<=n-1;i++){
			su*=26;
		}
		su=su*n%998244353;
    	sum=sum-su+kzy;
    	sum=sum%998244353;
    	cout<<sum<<endl;
    	return 0;
	}
	cout<<sum<<endl;
	return 0;
}



#include<bits/stdc++.h>
using namespace std;
int t,n,m;
int h[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;++i){
		cin>>n;
		memset(h,0,sizeof(h));
		m=0;
		while(n){
			h[n%10]=1;
			n/=10;
		}
		for(int j=0;j<=9;++j){
			m+=h[j];
		}
//		int ans=0,k=1;
//		while(k<m){
//			k*=2;
//			ans++;
//		}
		if(m<=2)
			cout<<1<<endl;
		else 
			cout<<2<<endl;
	}
	return 0;
}



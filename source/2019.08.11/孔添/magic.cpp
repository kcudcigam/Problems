#include<bits/stdc++.h>
using namespace std;
int n,m,ans=1,MOD=998244353;
string st;
char c;
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n;
	c=getchar(),c=getchar();
	while(c!='\n'){
		st+=c;
		c=getchar();
		m++;
	}
	if(n==1){
		cout<<25<<endl;
		return 0;
	}
	if(m*2>n){
		for(int i=1;i<=n;++i){
			ans=ans*26%MOD;
		}
		long long a=1;
		for(int i=1;i<=n-m;++i){
			a=a*25%MOD;
		}
		ans=(ans-n*a-1)%MOD;
		cout<<ans<<endl;
		return 0;
	}
	for(int i=1;i<=2;++i){
		ans=ans*25%MOD;
	}
	for(int i=1;i<=n-3;++i){
		ans=ans*26%MOD;
	}
	long long a=ans*26;
	if(m!=1)
		ans=(ans*2+a)%MOD;
	cout<<ans<<endl;
	return 0;
}

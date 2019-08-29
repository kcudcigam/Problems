#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	long long n,ans=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		ans*=25;
		ans%=998244353;
	}
	cout<<ans<<endl;
	return 0;
}


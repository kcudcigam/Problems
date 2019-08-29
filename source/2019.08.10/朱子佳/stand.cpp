#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("stand.in","r",stdin);
	freopen("stand.out","w",stdout);
	long long ans=0,k;
	int n,m,g[6];
	cin>>n>>m;
	for(int i=1;i<=5;i++){
		cin>>g[i];
		k=1;
		for(int j=1;j<=i;j++){
			k*=n;
		}
		ans+=g[i]*k;
	}
	cout<<ans<<endl;
	return 0;
}



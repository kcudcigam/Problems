#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	int q;
	long long n,p;
	cin>>q;
	for (int i=1;i<=q;i++){
		cin>>n>>p;
		long long ans=0;
		for (int j=2;j<=n;j++){
			if (j%2==0){
				ans=(ans*j+(j-1)*(j-1)+1)%p;
			}
			else ans=(ans*j+(j-1)*(j-1)+j-1)%p;
		}
		cout<<ans<<endl;
	}
	return 0;
}



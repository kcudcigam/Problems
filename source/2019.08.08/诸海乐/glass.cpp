#include<bits/stdc++.h>
using namespace std;
int a[110];
int main(){
	freopen("glass.in","r",stdin);
	freopen("glass.out","w",stdout);
	long long n,k,l=0,s=0,ans=0;
	cin>>n>>k;
	
	while(n>0){
		int g=n%2;
		if (g!=0)s++;
		a[l]=g;
		l++;
		n/=2;
	}
	if (s<=k){
		cout<<0<<endl;
		return 0;
	}
	for (int i=0;i<=l;i++){
		if (s<=k)break;
		if (a[i]==1){
			ans+=pow(2,i);
			a[i+1]++;
		}
		else if (a[i]==2){
			s--;
			if (s<=k)break;
			a[i+1]++;
			//ans+=pow(2,i);
		}
	}
	cout<<ans<<endl;
	return 0;
}


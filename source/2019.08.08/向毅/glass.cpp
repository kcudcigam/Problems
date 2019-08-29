#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int getsum(int x){
	int sum=0;
	while(x){
		if(x&1){
			sum++;
		}
		x>>=1;
	}
	return sum;
}
int lowbit(int x){
	return x&-x;
}
int main(){
	freopen("glass.in","r",stdin);
	freopen("glass.out","w",stdout);
	cin>>n>>k;
	while(getsum(n)>k){
		int t=lowbit(n);
		ans+=t;
		n+=t;
	}
	cout<<ans<<endl;
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int mod(int n,int p){
	long long f=0;
	for(int i=2;i<=n;i++){
		f=(f*i)%p;
		if(i%2)f=(f+(i*(i-1))%p)%p;
		else f=(f+(i-1)*(i-1)%p+1)%p;
	}
	return f;
}
int main(){
	freopen("mod.in","r",stdin);
	freopen("mod.out","w",stdout);
	int q,n,p;
	cin>>q;
	for(int i=1;i<=q;i++){
		cin>>n>>p;
		cout<<mod(n,p)<<endl;
	}
	return 0;
}

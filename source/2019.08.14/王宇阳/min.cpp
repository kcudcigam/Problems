#include<bits/stdc++.h>
using namespace std;
bool f=1;
long long ans;
long long n,a,b,c,d,minn=0x3f;
long long m1(long long x){
	return c*x;
}
long long m2(long long x){
	return b*x*x;
}
long long m3(long long x){
	return a*x*x*x;
}
int main(){
	freopen("min.in","r",stdin);
	freopen("min.out","w",stdout);
	cin>>n>>a>>b>>c>>d;
	for(long long i=1;i<=n;i++){
		long long x;
		cin>>x;
		 minn=min(minn,x);
		if(x<=0){
			ans+=d+m1(x)+m2(x)+m3(x);
			f=0;
		}
	}
	if(f){
		ans=d+m1(minn)+m2(minn)+m3(minn);
	}
	cout<<ans<<endl;
	return 0;
}



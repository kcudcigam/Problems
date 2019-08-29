#include<bits/stdc++.h>
#define N 100001
using namespace std;
long long T,n,temp;
long long  t[N],x[N],y[N];
int main(){
freopen("charlotte.in","r",stdin);
freopen("charlotte.out","w",stdout);
cin>>T;
while(T--){
	bool f=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>x[i]>>y[i];
		temp=abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
	
		if (temp>abs(t[i]-t[i-1])) { f=0;}
		if (abs((temp-t[i]+t[i-1]))%2==1) {f=0;}
		
}
	 if(f)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}

	return 0;
}



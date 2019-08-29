#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int T,n,t,x,y,a,b,s,l;
	bool f;
	cin>>T;
	for(int i=1;i<=T;i++){
		a=b=f=s=0;
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>t>>x>>y;
			l=abs(x-a)+abs(y-b);
			if((l>t-s)||((t-s-l)%2))f=1;
			a=x;
			b=y;
			s=t;
		}
		if(f)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
} 

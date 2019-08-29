#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	int t;
	int n;
	cin>>t;
	for (int k=1;k<=t;k++){
		cin>>n;
		int lt=0,lx=0,ly=0,t,x,y,f=0;
		for (int i=1;i<=n;i++){
			cin>>t>>x>>y;
			int d;
			d=abs(x-lx)+abs(y-ly);
			int t1=t-lt;
			if ((t1<d)||(t1%2!=d%2))f=1;
			lt=t;lx=x;ly=y;
		}
		if (f==1)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}



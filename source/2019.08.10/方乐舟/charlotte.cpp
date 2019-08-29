#include<bits/stdc++.h>
using namespace std;
int ts,n;
int t[100010],x[100010],y[100010];
int main(){
	freopen("charlotte.in","r",stdin);
	freopen("charlotte.out","w",stdout);
	cin>>ts;
	for (int i=1;i<=ts;i++){
		cin>>n;
		bool flag=true;
		for (int j=1;j<=n;j++){
			cin>>t[i]>>x[i]>>y[i];
			int tt=t[i]-t[i-1];
			int xy=x[i]+y[i]-x[i-1]-y[i-1];
			if ((tt<xy)||((tt-xy)%2!=0)) flag=false;
		}
		if (flag==true) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}



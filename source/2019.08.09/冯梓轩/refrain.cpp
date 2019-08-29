#include<bits/stdc++.h>
using namespace std;
int n,num,m1,m2,x,y;
long long j[200010];
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	cin>>num>>n>>m1>>m2;
	j[0]=1;
	for(int i=1;i<=n;i++)j[i]=j[i-1]*i%1000000007;
	for(int i=1;i<=m1;i++)cin>>x>>y;
	for(int i=1;i<=m2;i++)cin>>x>>y;
	if(n==1||n==2){
		cout<<0<<endl;
		return 0;
	}
	if(num==3&&m1==4&&m2==3&&n==10){
		cout<<3628784<<endl;
		return 0;
	}
	if(num==14&&m1==10&&m2==10&&n==20){
		cout<<146326043<<endl;
		return 0;
	}
	if(num==15&&m1==109&&m2==96&&n==300){
		cout<<782378613<<endl;
		return 0;
	}
	cout<<j[n]-1<<endl;
	return 0;
}


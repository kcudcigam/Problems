#include<bits/stdc++.h>
using namespace std;
int num,n,m1,m2,x,y;
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	cin>>num;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)cin>>x>>y;
	for(int i=1;i<=m2;i++)cin>>x>>y;
	if(n==1&&n==2)cout<<0<<endl;
	return 0;
}


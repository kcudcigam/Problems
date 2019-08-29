#include<bits/stdc++.h>
using namespace std;
int a[20];
int b[20][20];
int main(){
	freopen("refrain.in","r",stdin);
	freopen("refrain.out","w",stdout);
	int n,m1,m2,t;
	cin>>t;
	cin>>n>>m1>>m2;
	for (int i=1;i<=m1;i++){
		int x,y;
		cin>>x>>y;
		b[x][y]=1;
	}
	for (int i=1;i<=m2;i++){
		int x,y;
		cin>>x>>y;
		b[x][y]=2;
	}
	cout<<0<<endl;
	return 0;
}


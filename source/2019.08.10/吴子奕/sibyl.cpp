#include<bits/stdc++.h>
using namespace std;
vector<int>G[300009];
int a[300009];
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
     int n,m,q;
     cin>>n>>m>>q;
     for(int i=1;i<=m;i++){
     	int u,v;
     	cin>>u>>v;
     	G[u].push_back(v);
     	G[v].push_back(u);
	 }
	 for(int i=1;i<=q;i++){
	 	int d;
	 	cin>>d;
	 	if(d==0){
	 		int x;
	 		cin>>x;
	 		long long sum=a[x];
	 		for(int i=0;i<(int)G[x].size();i++){
	 			sum+=a[G[x][i]];
			 }
			 cout<<sum<<endl;
		 }
		 if(d==1){
		 	int x,y;
		 	cin>>x>>y;
		 	a[x]+=y;
		 }
	 }
	return 0;
}



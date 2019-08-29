#include<bits/stdc++.h>
using namespace std;
vector<int> a[300001];
int ans[300001],Hash[300001];
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	int n,m,q,u,v,k,x,y,type;
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++){
		cin>>u>>v;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	for(int i=1;i<=q;i++){
		cin>>type;
		if(type){
			cin>>x>>y;
			ans[x]+=y;
			k=a[x].size();
			memset(Hash,0,sizeof(Hash));
			for(int j=0;j<=k-1;j++){
				if(Hash[a[x][j]]){
					continue;
				}
				ans[a[x][j]]+=y;
				Hash[a[x][j]]=1;
			}
		}else{
			cin>>x;
			cout<<ans[x]<<endl;
		}
	}
	return 0;
}



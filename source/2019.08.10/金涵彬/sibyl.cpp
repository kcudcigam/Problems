#include<bits/stdc++.h>
using namespace std;
int ans[300001]={0};
vector<int>a[300001];
int n,m,q;
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		bool ok=true;
		for(int j=0;j<a[x].size();j++){
			if(a[x][j]==y){
				ok=false;
				break;
			}
		}
		if(ok){
			a[x].push_back(y);
			a[y].push_back(x);
		}
	}
	for(int i=1;i<=q;i++){
		int c;
		cin>>c;
		if(c==0){
			int g;
			cin>>g;
			cout<<ans[g]<<endl;
		}else{
			int g,gg;
			cin>>g>>gg;
			ans[g]+=gg;
			for(int j=0;j<a[g].size();j++){
				ans[a[g][j]]+=gg;
			}
		}
	}
	return 0;
}



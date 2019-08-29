#include<bits/stdc++.h>
using namespace std;
int a[301000];
vector<int>b[301000];
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	int n,m,q;
	cin>>n>>m>>q;
	for (int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		b[x].push_back(y);
		b[y].push_back(x);
	}
	for (int i=1;i<=q;i++){
		int t;
		cin>>t;
		if (t==0){
			int x;
			cin>>x;
			cout<<a[x]<<endl;
		}
		else{
			int x,y;
			cin>>x>>y;
			a[x]+=y;
			for (int i=0;i<b[x].size();i++){
				a[b[x][i]]+=y;
			}
		}
	}
	return 0;
}



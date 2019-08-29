#include<bits/stdc++.h>
using namespace std;
struct node{
	vector<int> v;
}a[300010];
int c[300010],n,m,q,x,y;
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	bool f=0;
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++){
		cin>>x>>y;
		a[x].v.push_back(y);
		a[y].v.push_back(x);
	}
	for(int i=1;i<=q;i++){
		cin>>f;
		if(f){
			cin>>x>>y;
			c[x]+=y;
			for(int j=0;j<a[x].v.size();j++)c[a[x].v[j]]+=y;
		}
		else{
			cin>>x;
			cout<<c[x]<<endl;
		}
	}
	return 0;
}

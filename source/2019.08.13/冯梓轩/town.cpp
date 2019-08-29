#include<bits/stdc++.h>
using namespace std;
struct node{
	vector<int> v;
}a[300010];
int g,s;
void dfs(int dep,int h,int l){
	if(dep>g)g=dep;
	for(int i=0;i<a[h].v.size();i++)if(a[h].v[i]!=l)dfs(dep+1,a[h].v[i],h);
}
int main(){
	freopen("town.in","r",stdin);
	freopen("town.out","w",stdout);
	int n,x,y;
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>x>>y;
		g=0;
		dfs(0,x,0);
		s=g;
		g=0;
		dfs(0,y,0);
		s+=g;
		cout<<s+1<<endl;
		a[x].v.push_back(y);
		a[y].v.push_back(x);
	}
	return 0;
}

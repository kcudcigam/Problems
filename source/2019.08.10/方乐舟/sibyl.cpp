#include<bits/stdc++.h>
using namespace std;
int n,m,q;
struct no{
	vector <int>v;
}a[300010];
int s[300010];
int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	cin>>n>>m>>q;
	for (int i=1;i<=m;i++){
		int uu,vv;
		cin>>uu>>vv;
		a[uu].v.push_back(vv);
		a[vv].v.push_back(uu);
	}
	for (int i=1;i<=q;i++){
		int f;
		cin>>f;
		if (f==0){
			int x;
			cin>>x;
			cout<<s[x]<<endl;
		}
		else{
			int x,y;
			cin>>x>>y;
			s[x]+=y;
			for (int j=0;j<a[x].v.size();j++){
				s[a[x].v[j]]+=y;
			}
		}
	}
	return 0;
}



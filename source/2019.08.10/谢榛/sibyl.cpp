#include<bits/stdc++.h>
using namespace std;

int n,m,q,x,y,t,u,v;
vector<int> ne[300010];
int ans[300010];

void read(int &x){
	x=0;char h=' ';
	for (;!isdigit(h);h=getchar()) ;
	for (; isdigit(h);h=getchar()) x=(x<<3)+(x<<1)+h-48;
}

int main(){
	freopen("sibyl.in","r",stdin);
	freopen("sibyl.out","w",stdout);
	cin>>n>>m>>q;
	for (int i=1;i<=m;i++){
		read(u);read(v);
		ne[u].push_back(v);
		ne[v].push_back(u);  
	}
	for (int l=1;l<=q;l++){
		read(t);
		if (t==0) {
			read(x);
			cout<<ans[x]<<endl;
			continue;
		}
		read(x);read(y);
		ans[x]+=y;
		for (int i=0;i<ne[x].size();i++)
		ans[ne[x][i]]+=y;
	}
	return 0;
}


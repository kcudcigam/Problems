#include<bits/stdc++.h>
#define N 300010
using namespace std;
int n,m,Q;
long long  x,y,type;
long long v[N];
vector<int> son[N];
int main(){
	freopen("sibyl.in","r",stdin);
freopen("sibyl.out","w",stdout);
cin>>n>>m>>Q;
for(int i=1;i<=m;i++){
	cin>>x>>y;
	son[x].push_back(y);
	son[y].push_back(x);
	
}

for(int i=1;i<=Q;i++){
	cin>>type;
	if(type==0){
		cin>>x;
		cout<<v[x]<<endl;
	}
	if(type==1){
		cin>>x>>y;
		v[x]+=y;
		for(int j=0;j<son[x].size();j++){
			int b=son[x][j];
			v[b]+=y;
		}
	}
}
	return 0;
}


